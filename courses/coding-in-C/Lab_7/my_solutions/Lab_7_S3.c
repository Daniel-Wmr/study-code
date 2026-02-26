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
        printf("Playlist Allocation failed!");
        return NULL;
    }
    p->head = NULL;
    return p;
}

int main(){
    return 0;
}