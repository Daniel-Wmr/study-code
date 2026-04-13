#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "../include/playlist.h"

/* === Unit-tests === */

// example unit test
void test_init_playlist(void)
{
    Playlist* p = init_playlist();

    assert(p != NULL);
    assert(p->head == NULL);
    assert(p->songs_counter == 0);

    delete_playlist(p);
}

void test_add_song(){
    Playlist* p = init_playlist();
    int old_count = p->songs_counter;
    add_song("Test_Song", "Test_Artist", p);

    Song* last = p->head;
    while (last->pNext != NULL)
        last = last->pNext;

    assert(p->songs_counter <= MAX_SONGS);
    assert(p->songs_counter >= 0);
    assert(p->songs_counter == (old_count + 1));
    assert(last != NULL);
    assert(strcmp(last->pName, "Test_Song") == 0);
    assert(strcmp(last->pArtist, "Test_Artist") == 0);
    assert(last->pNext == NULL);
    delete_playlist(p);
}

void test_delete_firstSong() {
    Playlist* p = init_playlist();

    add_song("Song1", "Artist1", p);
    add_song("Song2", "Artist2", p);
    add_song("Song3", "Artist3", p);

    int old_count = p->songs_counter;

    // Der neue erste Song nach dem Löschen
    Song* expected_new_head = p->head->pNext;

    delete_firstSong(p);

    // 1) Counter korrekt?
    assert(p->songs_counter == old_count - 1);

    // 2) Head zeigt auf das alte zweite Element?
    assert(p->head == expected_new_head);

    // 3) Head ist nicht NULL (weil vorher 3 Songs)
    assert(p->head != NULL);

    // 4) Head-Daten sind korrekt?
    assert(strcmp(p->head->pName, "Song2") == 0);
    assert(strcmp(p->head->pArtist, "Artist2") == 0);

    // 5) Liste ist weiterhin konsistent
    assert(p->head->pNext != NULL);
    assert(strcmp(p->head->pNext->pName, "Song3") == 0);

    delete_playlist(p);
}

void test_delete_firstSong_empty(){
    Playlist* p = init_playlist();
    delete_firstSong(p);

    assert(p->head == NULL);
    assert(p->songs_counter == 0);
    assert(p->songs_counter >= 0);

    delete_playlist(p);
}

void test_delete_playlist() {
    Playlist* p = init_playlist();

    add_song("Song1", "Artist1", p);
    add_song("Song2", "Artist2", p);
    add_song("Song3", "Artist3", p);

    assert(p->songs_counter == 3);
    assert(p->head != NULL);

    delete_playlist(p);
}

void test_max_songs_limit() {
    Playlist* p = init_playlist();

    for (int i = 0; i < MAX_SONGS; i++) {
        add_song("Song", "Artist", p);
    }
    assert(p->songs_counter == MAX_SONGS);

    add_song("Overflow", "Overflow", p);
    assert(p->songs_counter == MAX_SONGS);

    // Liste hat wirklich nur MAX_SONGS Elemente
    int count_nodes = 0;
    Song* current = p->head;
    while (current != NULL) {
        count_nodes++;
        current = current->pNext;
    }
    assert(count_nodes == MAX_SONGS);

    // Letzter Song ist korrekt
    Song* last = p->head;
    while (last->pNext != NULL)
        last = last->pNext;

    assert(strcmp(last->pName, "Song") == 0);
    assert(strcmp(last->pArtist, "Artist") == 0);

    delete_playlist(p);
}


/* === Test-Runner === */
int main(void)
{
    test_init_playlist();
    test_add_song();
    test_delete_firstSong();
    test_delete_firstSong_empty(); // what happens if we delete first song from empty playlist
    test_delete_playlist();
    test_max_songs_limit(); // verify if the limit will be not be surpassed

    printf("Alle Playlist-Tests erfolgreich bestanden.\n");
    return 0;
}