#include <iostream>
#include "Song.h"
#include "DoublyCircularLinkedList.h"
#include "MusicPlayer.h"

using namespace std;

int main()
{
    DoublyCircularLinkedList list;

    list.addFront("Title 1", "Singer 1");
    list.addBack("Title 2", "Singer 2");
    list.addIndex(1, "Title 3", "Singer 3");
    list.addBack("Title 4", "Singer 4");
    list.addBack("Title 5", "Singer 5");

    list.removeIndex(1);
    list.removeBack();

    // Print the list
    list.printList(); cout << endl << endl;
    list.printListReverse(); cout << endl << endl;

    MusicPlayer playlist1("Playlist 1");

    playlist1.print(true);
    playlist1.play();
    playlist1.next();
    playlist1.prev();
    playlist1.removeSong();

    playlist1.add("How Deep Is Your Love", "Bee Gees");
    playlist1.add("Isn't She Lovely", "Stevie Wonder");
    playlist1.add("Let's Stay Together", "Al Green");
    playlist1.add("My Cherie Amour", "Stevie Wonder");

    cout << endl << endl; cout << "Current List : ";
    cout << "Size(" << playlist1.getPlayerList().getSize() << "), ";
    cout << "Cursor(" << playlist1.getCursor() << "), " << endl;
    playlist1.print(true);

    cout << endl << endl;
    playlist1.print(false);

    cout << endl << endl;
    playlist1.removeSong();
    playlist1.play();
    playlist1.next();
    playlist1.next();
    playlist1.next();

    cout << endl << endl; cout << "Current List : ";
    cout << "Size(" << playlist1.getPlayerList().getSize() << "), ";
    cout << "Cursor(" << playlist1.getCursor() << "), " << endl;
    playlist1.print(true);
    return 0;
}
