#include "../include/playlist.h"
#include <string.h>

Playlist* init_playlist(){
    Playlist* p = malloc(sizeof(Playlist));
    if(!p) {
        printf("Playlist Allocation failed!\n");
        return NULL;
    }
    p->head = NULL;
    p->songs_counter = 0;
    return p;
}

void add_song(const char* name, const char* artist, Playlist* p){
    if(p->songs_counter >= MAX_SONGS){
        printf("Maximum amount of songs already reached!\n");
        return;
    }

    Song* new_song = malloc(sizeof(Song));
    if(!new_song) {
        printf("Song allocation failed!\n");
        return;
    }

    new_song->pName = strdup(name);
    new_song->pArtist = strdup(artist);
    new_song->pNext = NULL;

    if(p->head == NULL){
        p->head = new_song;
    } else {
        Song* current = p->head;
        while(current->pNext != NULL){
            current = current->pNext;
        }
        current->pNext = new_song;
    }

    p->songs_counter++;
}

void print_playlist(Playlist* p){
    if(p->head == NULL){
        printf("This Playlist contains no songs...\n");
        return;
    }
    
    Song* current = p->head;
    while(current != NULL){
        printf("Title: %s, Artist: %s\n", current->pName, current->pArtist);
        current = current->pNext;
    }

}

void delete_firstSong(Playlist* p){
    if(p->head == NULL){
        printf("Playlist already empty...\n");
        return;
    }

    Song* firstSong = p->head;
    p->head = firstSong->pNext;

    free(firstSong->pName);
    free(firstSong->pArtist);
    free(firstSong);

    p->songs_counter--;
}

void delete_playlist(Playlist* p){
    while(p->head != NULL){
        delete_firstSong(p);
    }

    free(p);
}

Song* find_song_by_title(Playlist *playlist, const char *title){
    Song* current = playlist->head;

    while(current->pNext != NULL){

        if(strcmp(current->pName, title) == 0){
            return current;
        }
        
    }
    
    printf("No Song with the title \"%s\" has been found", title);
    return NULL;
}