#include <stdio.h>
#include "MegaNimons.h"

int main() {
    LabTrack lab;
    createLabTrack(&lab);

    MegaNimons m1 = {1, "Minion1", 100.0, "fly", TRUE};
    MegaNimons m2 = {2, "Minion2", 50.0, "laser", FALSE};

    insertFirst(&lab, m1);
    insertLast(&lab, m2);
    printLabTrack(lab);

    printf("\n");

    printf("Index of Minion1: %d\n", indexOf(lab, 1));

    printf("\n");

    MegaNimons m = getElmt(lab, 0);
    printf("Retrieved Minion in index 0: %s\n", m.name);

    printf("\n");

    MegaNimons m3 = {3, "Minion3", 75.0, "fire", TRUE};
    setElmt(&lab, 0, m3);
    printLabTrack(lab);

    printf("\n");

    printf("Index 0 is valid index: %s\n", isIdxValid(0) ? "Yes" : "No");
    printf("Index 0 is effective index: %s\n", isIdxEff(lab, 0) ? "Yes" : "No");

    printf("\n");

    printf("Is empty: %s\n", isEmpty(lab) ? "Yes" : "No");
    printf("Is full: %s\n", isFull(lab) ? "Yes" : "No");

    printf("\n");

    printf("Length: %d\n", length(lab));
    printf("Max capacity: %d\n", maxCapacity());

    printf("\n");

    ejectUnstable(&lab);
    printLabTrack(lab);

    printf("\n");

    MegaNimons m4 = {4, "Minion4", 90.0, "water", TRUE};
    MegaNimons m5 = {5, "Minion5", 60.0, "earth", FALSE};
    insertFirst(&lab, m5);
    insertAt(&lab, m4, 1);
    filterByPower(lab, 70.0);

    printf("\n");

    printLabTrack(lab);

    printf("\n");

    MegaNimons deleted;
    deleteFirst(&lab, &deleted);
    printf("Deleted first: %s\n", deleted.name);
    printLabTrack(lab);

    printf("\n");

    deleteLast(&lab, &deleted);
    printf("Deleted last: %s\n", deleted.name);
    printLabTrack(lab);

    printf("\n");

    deleteAt(&lab, 0, &deleted);
    printf("Deleted at index 0: %s\n", deleted.name);
    printLabTrack(lab);

    return 0;
}

