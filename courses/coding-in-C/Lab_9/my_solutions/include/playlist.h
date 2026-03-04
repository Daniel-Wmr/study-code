#ifndef PLAYLIST_H
#define PLAYLIST_H

#define MAX_SONGS 20

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song {
    char* pName;
    char* pArtist;
    struct Song* pNext;
} Song;

typedef struct Playlist {
    Song* head;
    int songs_counter;
} Playlist;

Playlist* init_playlist();
void add_song(const char* name, const char* artist, Playlist* p);
void print_playlist(Playlist* p);
void delete_firstSong(Playlist* p);
void delete_playlist(Playlist* p);

Song* find_song_by_title(Playlist *playlist, const char *title);

#endif // PLAYLIST_H