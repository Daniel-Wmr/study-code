#ifndef PLAYLIST_H
#define PLAYLIST_H

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
} Playlist;

Playlist* init_playlist();
void add_song(const char* name, const char* artist, Playlist* p);
void print_playlist(Playlist* p);
void delete_firstSong(Playlist* p);
void delete_playlist(Playlist* p);

#endif // PLAYLIST_H