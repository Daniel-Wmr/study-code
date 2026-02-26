#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song{
    char* pName;
    char* pArtist;
    struct Song* pNext;
} Song;

typedef struct Playlist{
    Song* head;
} Playlist;

Playlist* init_playlist(){
    Playlist* p = malloc(sizeof(Playlist));
    if(!p) {
        printf("Playlist Allocation failed!\n");
        return NULL;
    }
    p->head = NULL;
    return p;
}

void add_song(const char* name, const char* artist, Playlist* p){
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
        return;
    }

    Song* current = p->head;
    while(current->pNext != NULL){
        current = current->pNext;
    }

    current->pNext = new_song;
}


int main(){
    return 0;
}