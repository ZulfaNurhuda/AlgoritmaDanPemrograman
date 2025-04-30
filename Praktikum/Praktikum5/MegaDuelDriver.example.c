#include "MegaDuel.h"

int main() {
    LabTrack L;
    createLabTrack(&L);

    MegaNimons m1 = {1, "Kevzilla", 800.0, "Mutant", TRUE};
    MegaNimons m2 = {2, "Bobzilla", 850.0, "Mutant", FALSE};
    MegaNimons m3 = {3, "Melatron", 780.0, "Mutant", TRUE};
    MegaNimons m4 = {4, "Gigantor", 820.0, "Mutant", TRUE};
    MegaNimons m5 = {5, "Titanus", 790.0, "Mutant", FALSE};
    MegaNimons m6 = {6, "Colossus", 810.0, "Mutant", TRUE};
    MegaNimons m7 = {7, "Behemoth", 795.0, "Mutant", TRUE};
    MegaNimons m8 = {8, "Leviathan", 770.0, "Mutant", FALSE};
    MegaNimons m9 = {9, "Juggernaut", 830.0, "Mutant", TRUE};
    MegaNimons m10 = {10, "Goliath", 765.0, "Mutant", FALSE};

    insertLast(&L, m1);
    insertLast(&L, m2);
    insertLast(&L, m3);
    insertLast(&L, m4);
    insertLast(&L, m5);
    insertLast(&L, m6);
    insertLast(&L, m7);
    insertLast(&L, m8);
    insertLast(&L, m9);
    insertLast(&L, m10);

    runMegaDuel(&L);

    return 0;
}