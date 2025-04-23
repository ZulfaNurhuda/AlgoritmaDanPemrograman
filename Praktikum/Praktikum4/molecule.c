#include "molecule.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Implementasi Fungsi ADT Molekul ---

void createMolecule(Molecule *m)
{
    // TODO: Implementasikan fungsi ini
    if (m == NULL)
    {
        return;
    }

    m->numAtomTypes = 0;
    for (int i = 0; i < MAX_ATOM_TYPES; i++)
    {
        m->atoms[i].count = 0;
        m->atoms[i].symbol[0] = '\0';
    }
}

void addAtom(Molecule *m, const char *symbol, int count)
{
    // TODO: Implementasikan fungsi ini
    if (m == NULL || symbol == NULL || symbol[0] == '\0' || count <= 0)
    {
        return;
    }

    for (int i = 0; i < m->numAtomTypes; i++)
    {
        if (strcmp(m->atoms[i].symbol, symbol) == 0)
        {
            m->atoms[i].count += count;
            return;
        }
    }

    if (m->numAtomTypes < MAX_ATOM_TYPES)
    {
        strcpy(m->atoms[m->numAtomTypes].symbol, symbol);
        m->atoms[m->numAtomTypes].count = count;
        m->numAtomTypes++;
    }
}

/**
 * @brief Mendapatkan massa atom relatif (Ar) untuk simbol atom yang diberikan.
 *
 * `=====( FUNGSI BAWAAN YANG SUDAH ADA DI BRIEF )=====`
 *
 * Fungsi ini menerima simbol atom sebagai parameter dan mengembalikan
 * massa atom relatif berdasarkan simbol tersebut. Jika simbol tidak dikenal,
 * fungsi ini akan mengembalikan 0.0.
 *
 * @param symbol Simbol atom (misalnya, "H", "C", "O").
 * @return double Massa atom relatif untuk simbol yang diberikan. Mengembalikan
 * 0.0 jika simbol tidak dikenal.
 */
double getAtomicWeight(const char *symbol)
{
    if (strcmp(symbol, "H") == 0)
        return 1.008;
    else if (strcmp(symbol, "He") == 0)
        return 4.0026;
    else if (strcmp(symbol, "Li") == 0)
        return 6.94;
    else if (strcmp(symbol, "C") == 0)
        return 12.011;
    else if (strcmp(symbol, "N") == 0)
        return 14.007;
    else if (strcmp(symbol, "O") == 0)
        return 15.999;
    else if (strcmp(symbol, "F") == 0)
        return 18.998;
    else if (strcmp(symbol, "Ne") == 0)
        return 20.180;
    else if (strcmp(symbol, "Na") == 0)
        return 22.990;
    else if (strcmp(symbol, "Mg") == 0)
        return 24.305;
    else if (strcmp(symbol, "Al") == 0)
        return 26.982;
    else if (strcmp(symbol, "Si") == 0)
        return 28.085;
    else if (strcmp(symbol, "P") == 0)
        return 30.974;
    else if (strcmp(symbol, "S") == 0)
        return 32.06;
    else if (strcmp(symbol, "Cl") == 0)
        return 35.45;
    else if (strcmp(symbol, "Ar") == 0)
        return 39.948;
    else if (strcmp(symbol, "K") == 0)
        return 39.098;
    else if (strcmp(symbol, "Ca") == 0)
        return 40.078;
    else if (strcmp(symbol, "Fe") == 0)
        return 55.845;
    else if (strcmp(symbol, "Au") == 0)
        return 196.967;
    else if (strcmp(symbol, "Br") == 0)
        return 79.904;
    else if (strcmp(symbol, "I") == 0)
        return 126.904;
    return 0.0;
}

double calculateMolecularWeight(const Molecule *m)
{
    // TODO: Implementasikan fungsi ini
    if (m == NULL)
    {
        return 0.0;
    }

    double total = 0.0;
    for (int i = 0; i < m->numAtomTypes; i++)
    {
        double weight = getAtomicWeight(m->atoms[i].symbol);
        if (weight > 0.0)
        {
            total += weight * m->atoms[i].count;
        }
    }
    return total;
}

int getAtomCount(const Molecule *m, const char *symbol)
{
    // TODO: Implementasikan fungsi ini
    if (m == NULL || symbol == NULL || symbol[0] == '\0')
    {
        return 0;
    }

    for (int i = 0; i < m->numAtomTypes; i++)
    {
        if (strcmp(m->atoms[i].symbol, symbol) == 0)
        {
            return m->atoms[i].count;
        }
    }
    return 0;
}

// --------- Fungsi Bantuan untuk qsort jika diperlukan ---------

/**
 * @brief Mendapatkan prioritas atom berdasarkan konvensi kimia.
 *
 * `=====( FUNGSI TAMBAHAN YANG BELUM ADA DI BRIEF )=====`
 *
 * Prioritas menentukan urutan atom dalam formula molekul:
 * - 1: Karbon (C) untuk senyawa organik.
 * - 2: Logam (kation) seperti Li, Na, K, dll.
 * - 3: Hidrogen (H) untuk senyawa kovalen/organik.
 * - 4: Atom kovalen lain seperti N, P, Si.
 * - 5: Anion seperti O, S, F, Cl, Br, I.
 * - 6: Gas mulia seperti He, Ne, Ar.
 *
 * @param symbol Simbol atom (misalnya "H", "C", "O").
 * @return int Prioritas atom.
 */
int getAtomPriority(const char *symbol)
{
    if (strcmp(symbol, "C") == 0)
        return 1; // Karbon untuk senyawa organik
    if (strcmp(symbol, "Li") == 0 || strcmp(symbol, "Na") == 0 || strcmp(symbol, "K") == 0 ||
        strcmp(symbol, "Mg") == 0 || strcmp(symbol, "Ca") == 0 || strcmp(symbol, "Fe") == 0 ||
        strcmp(symbol, "Au") == 0 || strcmp(symbol, "Al") == 0)
        return 2; // Logam (kation)
    if (strcmp(symbol, "H") == 0)
        return 3; // Hidrogen
    if (strcmp(symbol, "N") == 0 || strcmp(symbol, "P") == 0 || strcmp(symbol, "Si") == 0)
        return 4; // Atom kovalen lain
    if (strcmp(symbol, "O") == 0 || strcmp(symbol, "S") == 0 || strcmp(symbol, "F") == 0 ||
        strcmp(symbol, "Cl") == 0 || strcmp(symbol, "Br") == 0 || strcmp(symbol, "I") == 0)
        return 5; // Anion
    if (strcmp(symbol, "He") == 0 || strcmp(symbol, "Ne") == 0 || strcmp(symbol, "Ar") == 0)
        return 6; // Gas mulia
    return 6;     // Default untuk atom tak dikenal
}

/**
 * @brief Mendapatkan nilai elektronegativitas untuk simbol atom yang diberikan.
 *
 * `=====( FUNGSI TAMBAHAN YANG BELUM ADA DI BRIEF )=====`
 *
 * Fungsi ini menerima simbol atom sebagai parameter dan mengembalikan
 * nilai elektronegativitas yang sesuai. Jika simbol tidak dikenali,
 * fungsi akan mengembalikan 0.0.
 *
 * @param symbol Simbol atom (misalnya "H", "C", "O").
 * @return double Nilai elektronegativitas atom. Mengembalikan 0.0 jika simbol tidak dikenali.
 */
double getElectronegativity(const char *symbol)
{
    if (strcmp(symbol, "H") == 0)
        return 2.20;
    if (strcmp(symbol, "C") == 0)
        return 2.55;
    if (strcmp(symbol, "N") == 0)
        return 3.04;
    if (strcmp(symbol, "O") == 0)
        return 3.44;
    if (strcmp(symbol, "F") == 0)
        return 3.98;
    if (strcmp(symbol, "Cl") == 0)
        return 3.16;
    if (strcmp(symbol, "Br") == 0)
        return 2.96;
    if (strcmp(symbol, "I") == 0)
        return 2.66;
    if (strcmp(symbol, "Li") == 0)
        return 0.93;
    if (strcmp(symbol, "Na") == 0)
        return 0.93;
    if (strcmp(symbol, "K") == 0)
        return 0.82;
    if (strcmp(symbol, "Mg") == 0)
        return 1.31;
    if (strcmp(symbol, "Ca") == 0)
        return 1.00;
    if (strcmp(symbol, "Fe") == 0)
        return 1.83;
    if (strcmp(symbol, "Au") == 0)
        return 2.54;
    if (strcmp(symbol, "Al") == 0)
        return 1.61;
    if (strcmp(symbol, "Si") == 0)
        return 1.90;
    if (strcmp(symbol, "P") == 0)
        return 2.19;
    if (strcmp(symbol, "S") == 0)
        return 2.58;
    return 0.0;
}

/**
 * @brief Membandingkan dua atom untuk pengurutan berdasarkan konvensi kimia.
 *
 * `=====( FUNGSI BAWAAN YANG SUDAH ADA DI BRIEF )=====`
 *
 * Fungsi ini digunakan oleh qsort untuk mengurutkan atom dalam molekul.
 * Pengurutan dilakukan berdasarkan:
 * 1. Prioritas atom (dari getAtomPriority).
 * 2. Elektronegativitas (dari getElectronegativity, lebih rendah didahulukan).
 * 3. Urutan alfabetis (jika prioritas dan elektronegativitas sama).
 *
 * Fungsi bawaan telah dimodifikasi mengikuti beberapa aturan supaya
 * sesuai dengan kasus penamaan molekul yang umum.
 *
 * Fungsi asli sebelum modifikasi adalah:
 *
 * ```
 * int compareAtomInfo(const void *a, const void *b) {
 *     const AtomInfo *atomA = (const AtomInfo *)a;
 *     const AtomInfo *atomB = (const AtomInfo *)b;
 *     return strcmp(atomA->symbol, atomB->symbol);
 * }
 * ```
 *
 * @param a Pointer ke AtomInfo pertama.
 * @param b Pointer ke AtomInfo kedua.
 * @return int Nilai negatif jika a < b, positif jika a > b, 0 jika sama.
 */
int compareAtomInfo(const void *a, const void *b)
{
    const AtomInfo *atomA = (const AtomInfo *)a;
    const AtomInfo *atomB = (const AtomInfo *)b;

    int priorityA = getAtomPriority(atomA->symbol);
    int priorityB = getAtomPriority(atomB->symbol);
    double electroA = getElectronegativity(atomA->symbol);
    double electroB = getElectronegativity(atomB->symbol);

    if (priorityA != priorityB)
    {
        return priorityA - priorityB;
    }

    if (electroA != electroB)
    {
        return (electroA < electroB) ? -1 : 1;
    }

    return strcmp(atomA->symbol, atomB->symbol);
}

/**
 * @brief Mengurutkan atom dalam molekul berdasarkan prioritas dan elektronegativitas.
 *
 * Fungsi ini mengurutkan array atom dalam Molecule m menggunakan fungsi qsort.
 * Atom diurutkan berdasarkan prioritas, dan jika prioritas sama, akan diurutkan
 * berdasarkan elektronegativitas. Jika elektronegativitas juga sama,
 * pengurutan dilakukan berdasarkan urutan alfabet simbol atom.
 *
 * Fungsi asli ini sudah ada di brief dan tidak ada perubahan yang dilakukan.
 *
 * @param m Pointer ke Molecule yang atom-atomnya akan diurutkan.
 */
void sortMolecule(Molecule *m)
{
    if (m->numAtomTypes > 1)
    {
        qsort(m->atoms, m->numAtomTypes, sizeof(AtomInfo), compareAtomInfo);
    }
}

// --------------------------------------------------------------

void printMoleculeFormula(const Molecule *m)
{
    // TODO: Implementasikan fungsi ini
    // 1. Jika m->numAtomTypes == 0, cetak "(Kosong)".
    // 2. Urutkan atom berdasarkan simbol untuk output (gunakan fungsi sorting
    // yang sudah diberikan)
    // 3. Cetak formula molekul
    // Contoh output: C6H12O6, H2O, NaCl

    if (m == NULL || m->numAtomTypes == 0)
    {
        printf("(Kosong)\n");
        return;
    }

    Molecule temp = *m;
    sortMolecule(&temp);

    for (int i = 0; i < temp.numAtomTypes; i++)
    {
        if (temp.atoms[i].count > 0)
        {
            printf("%s", temp.atoms[i].symbol);
            if (temp.atoms[i].count > 1)
            {
                printf("%d", temp.atoms[i].count);
            }
        }
    }
    printf("\n");
}

bool areEqual(const Molecule *m1, const Molecule *m2)
{
    // TODO: Implementasikan fungsi ini
    if (m1 == NULL || m2 == NULL)
    {
        return false;
    }

    if (m1->numAtomTypes != m2->numAtomTypes)
    {
        return false;
    }

    // Sort atoms first
    Molecule m1_sorted = *m1;
    Molecule m2_sorted = *m2;
    sortMolecule(&m1_sorted);
    sortMolecule(&m2_sorted);

    for (int i = 0; i < m1_sorted.numAtomTypes; i++)
    {
        if (strcmp(m1_sorted.atoms[i].symbol, m2_sorted.atoms[i].symbol) != 0 ||
            m1_sorted.atoms[i].count != m2_sorted.atoms[i].count)
        {
            return false;
        }
    }
    return true;
}

Molecule combineMolecules(const Molecule *m1, const Molecule *m2)
{
    Molecule result;
    createMolecule(&result);

    // TODO: Implementasikan logika penggabungan
    if (m1 == NULL || m2 == NULL)
    {
        return result;
    }

    for (int i = 0; i < m1->numAtomTypes; i++)
    {
        addAtom(&result, m1->atoms[i].symbol, m1->atoms[i].count);
    }

    for (int i = 0; i < m2->numAtomTypes; i++)
    {
        addAtom(&result, m2->atoms[i].symbol, m2->atoms[i].count);
    }

    return result;
}

bool canSubtract(const Molecule *m_total, const Molecule *m_sub)
{
    // TODO: Implementasikan logika pengecekan
    if (m_total == NULL || m_sub == NULL)
    {
        return false;
    }

    for (int i = 0; i < m_sub->numAtomTypes; i++)
    {
        const char *symbol = m_sub->atoms[i].symbol;
        if (getAtomCount(m_total, symbol) < getAtomCount(m_sub, symbol))
        {
            return false;
        }
    }
    return true;
}

Molecule subtractMolecule(const Molecule *m_total, const Molecule *m_sub)
{
    Molecule result;
    createMolecule(&result);

    // TODO: Implementasikan logika pengurangan

    if (m_total == NULL || m_sub == NULL || !canSubtract(m_total, m_sub))
    {
        return result;
    }

    for (int i = 0; i < m_total->numAtomTypes; i++)
    {
        const char *symbol = m_total->atoms[i].symbol;
        int countTotal = getAtomCount(m_total, symbol);
        int countSub = getAtomCount(m_sub, symbol);
        if (countTotal > countSub)
        {
            addAtom(&result, symbol, countTotal - countSub);
        }
    }

    return result;
}