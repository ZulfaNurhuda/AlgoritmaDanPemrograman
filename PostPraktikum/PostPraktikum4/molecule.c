#include "molecule.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Implementasi Fungsi ADT Molekul ---

void createMolecule(Molecule *m)
{
    // TODO: Implementasikan fungsi ini
    m->numAtomTypes = 0;
    for (int i = 0; i < MAX_ATOM_TYPES; i++)
    {
        m->atoms[i].count = 0;
        strcpy(m->atoms[i].symbol, "");
    }
}

void addAtom(Molecule *m, const char *symbol, int count)
{
    // TODO: Implementasikan fungsi ini
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
    int i = 0;
    int count = 0;

    while (i < m->numAtomTypes && strcmp(m->atoms[i].symbol, symbol) == 0)
    {
        i++;
    }

    if (strcmp(m->atoms[i].symbol, symbol) == 0)
    {
        count = m->atoms[i].count;
    }

    return count;
}

// --------- Fungsi Bantuan untuk qsort jika diperlukan ---------
int compareAtomInfo(const void *a, const void *b)
{
    AtomInfo *atomA = (AtomInfo *)a;
    AtomInfo *atomB = (AtomInfo *)b;
    return strcmp(atomA->symbol, atomB->symbol);
}

void sortMolecule(Molecule *m)
{
    if (m->numAtomTypes > 1)
    {
        qsort(m->atoms, m->numAtomTypes, sizeof(AtomInfo), compareAtomInfo);
    }
}

bool areEqual(const Molecule *m1, const Molecule *m2)
{
    // Sort molekul sebelum membandingkan
    Molecule m1_sorted = *m1;
    Molecule m2_sorted = *m2;
    sortMolecule(&m1_sorted);
    sortMolecule(&m2_sorted);

    int i = 0;
    bool isEqual = true;

    while (i < m1_sorted.numAtomTypes && isEqual)
    {
        if (strcmp(m1_sorted.atoms[i].symbol, m2_sorted.atoms[i].symbol) != 0 ||
            m1_sorted.atoms[i].count != m2_sorted.atoms[i].count)
        {
            isEqual = false;
        }
        i++;
    }

    return isEqual;
}

Molecule combineMolecules(const Molecule *m1, const Molecule *m2)
{
    Molecule result;
    createMolecule(&result);

    // TODO: Implementasikan logika penggabungan
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

    int i = 0;
    bool able = true;

    while (i < m_sub->numAtomTypes && able)
    {
        const char *symbol = m_sub->atoms[i].symbol;
        if (getAtomCount(m_total, symbol) < getAtomCount(m_sub, symbol))
        {
            able = false;
        }
        i++;
    }

    return able;
}

Molecule subtractMolecule(const Molecule *m_total, const Molecule *m_sub)
{
    Molecule result;
    createMolecule(&result);

    // TODO: Implementasikan logika pengurangan
    if (canSubtract(m_total, m_sub))
    {
        for (int i = 0; i < m_total->numAtomTypes; i++)
        {
            for (int j = 0; j < m_sub->numAtomTypes; j++)
            {
                const char *symbol1 = m_total->atoms[i].symbol;
                const char *symbol2 = m_sub->atoms[j].symbol;

                if (strcmp(symbol1, symbol2) == 0)
                {
                    int countTotal = getAtomCount(m_total, symbol1);
                    int countSub = getAtomCount(m_sub, symbol1);

                    if (countTotal > countSub)
                    {
                        addAtom(&result, symbol1, countTotal - countSub);
                    }
                }
            }
        }
    }

    return result;
}

void printMoleculeFormula(const Molecule *m)
{
    // TODO: Implementasikan fungsi ini
    // 1. Jika m->numAtomTypes == 0, cetak "(Kosong)".
    // 2. Urutkan atom berdasarkan simbol untuk output (gunakan fungsi sorting
    // yang sudah diberikan)
    // 3. Cetak formula molekul
    // Contoh output: C6H12O6, H2O, NaCl

    if (m->numAtomTypes == 0)
    {
        printf("(Kosong)\n");
    }
    else
    {
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
}