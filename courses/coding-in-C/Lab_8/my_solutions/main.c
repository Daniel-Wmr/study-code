#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/playlist.h"

int main(){

    Playlist* playlist = init_playlist();

    add_song("Song1", "Artist1", playlist);
    add_song("Song2", "Artist2", playlist);
    add_song("Song3", "Artist3", playlist);

    print_playlist(playlist);

    delete_firstSong(playlist);
    print_playlist(playlist);

    delete_playlist(playlist);
    printf("Success!\n");

    return 0;
}