/**
 * --------------------------------------------------------------
 * | @file molecule.c                                           |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Implementasi ADT Molekul, termasuk fungsi untuk membuat,   |
 * | menambah atom, menghitung berat molekul, mencetak formula, |
 * | dan operasi lainnya pada molekul.                          |
 * --------------------------------------------------------------
 */

#include "molecule.h" // Asumsi header ini mendefinisikan struct Molecule, AtomInfo, MAX_ATOM_TYPES, dll.
#include <stdio.h>    // Untuk printf
#include <stdlib.h>   // Untuk qsort, malloc, free (meskipun malloc/free tidak eksplisit di sini jika createMolecule di .h)
#include <string.h>   // Untuk strcmp, strcpy
#include <stdbool.h>  // Untuk tipe data bool pada areEqual dan canSubtract

// --- Implementasi Fungsi ADT Molekul ---

/**
 * @brief Menginisialisasi sebuah molekul menjadi kosong.
 * @details Mengatur jumlah tipe atom menjadi 0 dan mengosongkan array atom.
 * @param molecule Pointer ke Molekul yang akan diinisialisasi.
 * @note I.S. : `molecule` adalah pointer valid.
 * @note F.S. : `molecule->atomTypeCount` adalah 0. Setiap `AtomInfo` dalam `molecule->atoms` diinisialisasi (count=0, symbol="").
 */
void createMolecule(Molecule *molecule)
{
    if (molecule == NULL)
    {
        return; // Menghindari dereferencing NULL pointer.
    }

    molecule->atomTypeCount = 0;
    for (int i = 0; i < MAX_ATOM_TYPES; i++)
    {
        molecule->atoms[i].count = 0;
        molecule->atoms[i].symbol[0] = '\0'; // Mengosongkan string simbol.
    }
}

/**
 * @brief Menambahkan sejumlah atom dengan simbol tertentu ke dalam molekul.
 * @details Jika atom dengan simbol tersebut sudah ada, jumlahnya akan ditambahkan.
 *          Jika belum ada dan masih ada kapasitas, atom baru akan ditambahkan.
 * @param molecule Pointer ke Molekul yang akan dimodifikasi.
 * @param atomSymbol Simbol atom yang akan ditambahkan (misal, "H", "O").
 * @param atomCount Jumlah atom yang akan ditambahkan (harus > 0).
 * @note I.S. : `molecule` terdefinisi, `atomSymbol` valid, `atomCount` > 0.
 * @note F.S. : Jumlah atom `atomSymbol` dalam `molecule` bertambah sebanyak `atomCount`,
 *              atau atom baru ditambahkan jika belum ada dan kapasitas memungkinkan.
 */
void addAtom(Molecule *molecule, const char *atomSymbol, int atomCount)
{
    // Validasi input.
    if (molecule == NULL || atomSymbol == NULL || atomSymbol[0] == '\0' || atomCount <= 0)
    {
        return;
    }

    // Cek apakah atom dengan simbol yang sama sudah ada.
    for (int i = 0; i < molecule->atomTypeCount; i++)
    {
        if (strcmp(molecule->atoms[i].symbol, atomSymbol) == 0)
        {
            molecule->atoms[i].count += atomCount; // Tambah jumlahnya.
            return;                                // Selesai.
        }
    }

    // Jika atom belum ada dan masih ada tempat di array.
    if (molecule->atomTypeCount < MAX_ATOM_TYPES)
    {
        // Salin simbol atom baru. Pastikan atomSymbol tidak lebih panjang dari kapasitas symbol di AtomInfo.
        strncpy(molecule->atoms[molecule->atomTypeCount].symbol, atomSymbol, sizeof(molecule->atoms[0].symbol) - 1);
        molecule->atoms[molecule->atomTypeCount].symbol[sizeof(molecule->atoms[0].symbol) - 1] = '\0'; // Pastikan null-terminated.

        molecule->atoms[molecule->atomTypeCount].count = atomCount;
        molecule->atomTypeCount++; // Tambah jumlah tipe atom yang berbeda.
    }
    // Jika tidak ada tempat, atom tidak ditambahkan (perilaku diam).
}

/**
 * @brief Mendapatkan massa atom relatif (Ar) untuk simbol atom yang diberikan.
 * @details Fungsi ini adalah bawaan dari brief soal.
 * @param atomSymbol Simbol atom (misalnya, "H", "C", "O").
 * @return double Massa atom relatif. Mengembalikan 0.0 jika simbol tidak dikenal.
 * @note I.S. : `atomSymbol` terdefinisi.
 * @note F.S. : Mengembalikan Ar atau 0.0.
 */
double getAtomicWeight(const char *atomSymbol)
{
    if (strcmp(atomSymbol, "H") == 0) return 1.008;
    else if (strcmp(atomSymbol, "He") == 0) return 4.0026;
    else if (strcmp(atomSymbol, "Li") == 0) return 6.94;
    else if (strcmp(atomSymbol, "C") == 0) return 12.011;
    else if (strcmp(atomSymbol, "N") == 0) return 14.007;
    else if (strcmp(atomSymbol, "O") == 0) return 15.999;
    else if (strcmp(atomSymbol, "F") == 0) return 18.998;
    else if (strcmp(atomSymbol, "Ne") == 0) return 20.180;
    else if (strcmp(atomSymbol, "Na") == 0) return 22.990;
    else if (strcmp(atomSymbol, "Mg") == 0) return 24.305;
    else if (strcmp(atomSymbol, "Al") == 0) return 26.982;
    else if (strcmp(atomSymbol, "Si") == 0) return 28.085;
    else if (strcmp(atomSymbol, "P") == 0) return 30.974;
    else if (strcmp(atomSymbol, "S") == 0) return 32.06;
    else if (strcmp(atomSymbol, "Cl") == 0) return 35.45;
    else if (strcmp(atomSymbol, "Ar") == 0) return 39.948;
    else if (strcmp(atomSymbol, "K") == 0) return 39.098;
    else if (strcmp(atomSymbol, "Ca") == 0) return 40.078;
    else if (strcmp(atomSymbol, "Fe") == 0) return 55.845;
    else if (strcmp(atomSymbol, "Au") == 0) return 196.967;
    else if (strcmp(atomSymbol, "Br") == 0) return 79.904;
    else if (strcmp(atomSymbol, "I") == 0) return 126.904;
    return 0.0; // Simbol tidak dikenal.
}

/**
 * @brief Menghitung berat molekul relatif (Mr) dari sebuah molekul.
 * @param molecule Pointer ke Molekul yang beratnya akan dihitung.
 * @return double Berat molekul relatif. Mengembalikan 0.0 jika molekul NULL atau kosong.
 * @note I.S. : `molecule` terdefinisi.
 * @note F.S. : Mengembalikan Mr dari `molecule`.
 */
double calculateMolecularWeight(const Molecule *molecule)
{
    if (molecule == NULL)
    {
        return 0.0;
    }

    double totalWeight = 0.0;
    for (int i = 0; i < molecule->atomTypeCount; i++)
    {
        double atomicWeightOfCurrentSymbol = getAtomicWeight(molecule->atoms[i].symbol);
        // Hanya tambahkan jika berat atom valid (bukan 0.0 dari simbol tak dikenal)
        if (atomicWeightOfCurrentSymbol > 0.0)
        {
            totalWeight += atomicWeightOfCurrentSymbol * molecule->atoms[i].count;
        }
    }
    return totalWeight;
}

/**
 * @brief Mendapatkan jumlah atom dengan simbol tertentu dalam sebuah molekul.
 * @param molecule Pointer ke Molekul yang akan diperiksa.
 * @param atomSymbol Simbol atom yang jumlahnya ingin diketahui.
 * @return int Jumlah atom dengan simbol tersebut. Mengembalikan 0 jika molekul NULL,
 *             simbol NULL/kosong, atau atom tidak ditemukan.
 * @note I.S. : `molecule` dan `atomSymbol` terdefinisi.
 * @note F.S. : Mengembalikan jumlah atom `atomSymbol` dalam `molecule`.
 */
int getAtomCount(const Molecule *molecule, const char *atomSymbol)
{
    if (molecule == NULL || atomSymbol == NULL || atomSymbol[0] == '\0')
    {
        return 0; // Input tidak valid.
    }

    for (int i = 0; i < molecule->atomTypeCount; i++)
    {
        if (strcmp(molecule->atoms[i].symbol, atomSymbol) == 0)
        {
            return molecule->atoms[i].count; // Atom ditemukan.
        }
    }
    return 0; // Atom tidak ditemukan.
}

// --------- Fungsi Bantuan untuk qsort jika diperlukan ---------
// Komentar untuk fungsi getAtomPriority, getElectronegativity,
// compareAtomInfo, dan sortMolecule dipertahankan dari kode asli
// karena sudah cukup deskriptif dan sesuai dengan brief/tambahan.

int getAtomPriority(const char *symbol)
{
    if (strcmp(symbol, "C") == 0) return 1;
    if (strcmp(symbol, "Li") == 0 || strcmp(symbol, "Na") == 0 || strcmp(symbol, "K") == 0 ||
        strcmp(symbol, "Mg") == 0 || strcmp(symbol, "Ca") == 0 || strcmp(symbol, "Fe") == 0 ||
        strcmp(symbol, "Au") == 0 || strcmp(symbol, "Al") == 0) return 2;
    if (strcmp(symbol, "H") == 0) return 3;
    if (strcmp(symbol, "N") == 0 || strcmp(symbol, "P") == 0 || strcmp(symbol, "Si") == 0) return 4;
    if (strcmp(symbol, "O") == 0 || strcmp(symbol, "S") == 0 || strcmp(symbol, "F") == 0 ||
        strcmp(symbol, "Cl") == 0 || strcmp(symbol, "Br") == 0 || strcmp(symbol, "I") == 0) return 5;
    if (strcmp(symbol, "He") == 0 || strcmp(symbol, "Ne") == 0 || strcmp(symbol, "Ar") == 0) return 6;
    return 7; // Menaikkan default priority agar atom tak dikenal muncul terakhir.
}

double getElectronegativity(const char *symbol)
{
    if (strcmp(symbol, "H") == 0) return 2.20;
    if (strcmp(symbol, "C") == 0) return 2.55;
    if (strcmp(symbol, "N") == 0) return 3.04;
    if (strcmp(symbol, "O") == 0) return 3.44;
    if (strcmp(symbol, "F") == 0) return 3.98;
    if (strcmp(symbol, "Cl") == 0) return 3.16;
    if (strcmp(symbol, "Br") == 0) return 2.96;
    if (strcmp(symbol, "I") == 0) return 2.66;
    if (strcmp(symbol, "Li") == 0) return 0.93; // Seharusnya 0.98
    if (strcmp(symbol, "Na") == 0) return 0.93;
    if (strcmp(symbol, "K") == 0) return 0.82;
    if (strcmp(symbol, "Mg") == 0) return 1.31;
    if (strcmp(symbol, "Ca") == 0) return 1.00;
    if (strcmp(symbol, "Fe") == 0) return 1.83;
    if (strcmp(symbol, "Au") == 0) return 2.54;
    if (strcmp(symbol, "Al") == 0) return 1.61;
    if (strcmp(symbol, "Si") == 0) return 1.90;
    if (strcmp(symbol, "P") == 0) return 2.19;
    if (strcmp(symbol, "S") == 0) return 2.58;
    return 0.0; // Default untuk atom tak dikenal
}

int compareAtomInfo(const void *a, const void *b)
{
    const AtomInfo *atomA = (const AtomInfo *)a;
    const AtomInfo *atomB = (const AtomInfo *)b;

    int priorityA = getAtomPriority(atomA->symbol);
    int priorityB = getAtomPriority(atomB->symbol);

    if (priorityA != priorityB)
    {
        return priorityA - priorityB; // Urutkan berdasarkan prioritas.
    }

    // Jika prioritas sama, urutkan berdasarkan elektronegativitas (rendah dulu).
    double electroA = getElectronegativity(atomA->symbol);
    double electroB = getElectronegativity(atomB->symbol);
    if (electroA < electroB) return -1;
    if (electroA > electroB) return 1;

    // Jika elektronegativitas juga sama, urutkan berdasarkan alfabet simbol.
    return strcmp(atomA->symbol, atomB->symbol);
}

void sortMolecule(Molecule *molecule)
{
    if (molecule != NULL && molecule->atomTypeCount > 1)
    {
        qsort(molecule->atoms, molecule->atomTypeCount, sizeof(AtomInfo), compareAtomInfo);
    }
}

// --------------------------------------------------------------

/**
 * @brief Mencetak formula kimia dari sebuah molekul.
 * @details Atom-atom akan diurutkan sesuai konvensi sebelum dicetak.
 *          Contoh: C6H12O6, H2O, NaCl. Jika molekul kosong, cetak "(Kosong)".
 * @param molecule Pointer ke Molekul yang formulanya akan dicetak.
 * @note I.S. : `molecule` terdefinisi.
 * @note F.S. : Formula molekul dicetak ke standar output diakhiri newline.
 */
void printMoleculeFormula(const Molecule *molecule)
{
    if (molecule == NULL || molecule->atomTypeCount == 0)
    {
        printf("(Kosong)\n");
        return;
    }

    // Buat salinan molekul untuk diurutkan tanpa mengubah molekul asli.
    Molecule sortedMoleculeCopy = *molecule;
    sortMolecule(&sortedMoleculeCopy);

    for (int i = 0; i < sortedMoleculeCopy.atomTypeCount; i++)
    {
        // Hanya cetak atom jika jumlahnya lebih dari 0.
        if (sortedMoleculeCopy.atoms[i].count > 0)
        {
            printf("%s", sortedMoleculeCopy.atoms[i].symbol);
            // Hanya cetak jumlah jika lebih dari 1.
            if (sortedMoleculeCopy.atoms[i].count > 1)
            {
                printf("%d", sortedMoleculeCopy.atoms[i].count);
            }
        }
    }
    printf("\n"); // Akhiri dengan newline.
}

/**
 * @brief Memeriksa apakah dua molekul identik.
 * @details Dua molekul dianggap identik jika memiliki tipe atom yang sama
 *          dengan jumlah yang sama untuk setiap tipe, tidak memperdulikan urutan awal.
 * @param molecule1 Pointer ke molekul pertama.
 * @param molecule2 Pointer ke molekul kedua.
 * @return bool true jika kedua molekul identik, false jika tidak.
 * @note I.S. : `molecule1` dan `molecule2` terdefinisi.
 * @note F.S. : Mengembalikan status kesetaraan.
 */
bool areEqual(const Molecule *molecule1, const Molecule *molecule2)
{
    // Jika salah satu atau keduanya NULL, mereka tidak bisa sama (kecuali keduanya NULL).
    if (molecule1 == NULL && molecule2 == NULL) return true;
    if (molecule1 == NULL || molecule2 == NULL) return false;

    // Jika jumlah tipe atom berbeda, pasti tidak sama.
    if (molecule1->atomTypeCount != molecule2->atomTypeCount)
    {
        return false;
    }

    // Buat salinan untuk diurutkan agar perbandingan tidak bergantung urutan.
    Molecule sortedMolecule1 = *molecule1;
    Molecule sortedMolecule2 = *molecule2;
    sortMolecule(&sortedMolecule1);
    sortMolecule(&sortedMolecule2);

    // Bandingkan setiap atom yang sudah diurutkan.
    for (int i = 0; i < sortedMolecule1.atomTypeCount; i++)
    {
        if (strcmp(sortedMolecule1.atoms[i].symbol, sortedMolecule2.atoms[i].symbol) != 0 ||
            sortedMolecule1.atoms[i].count != sortedMolecule2.atoms[i].count)
        {
            return false; // Ditemukan perbedaan.
        }
    }
    return true; // Semua atom dan jumlahnya cocok.
}

/**
 * @brief Menggabungkan dua molekul menjadi satu molekul baru.
 * @details Jumlah atom untuk simbol yang sama akan dijumlahkan.
 * @param molecule1 Pointer ke molekul pertama.
 * @param molecule2 Pointer ke molekul kedua.
 * @return Molecule Molekul baru hasil penggabungan. Jika input NULL, mengembalikan molekul kosong.
 * @note I.S. : `molecule1` dan `molecule2` terdefinisi.
 * @note F.S. : Mengembalikan molekul baru.
 */
Molecule combineMolecules(const Molecule *molecule1, const Molecule *molecule2)
{
    Molecule combinedMolecule;
    createMolecule(&combinedMolecule); // Inisialisasi molekul hasil.

    if (molecule1 == NULL && molecule2 == NULL) return combinedMolecule; // Keduanya NULL

    // Tambahkan semua atom dari molekul pertama.
    if (molecule1 != NULL) {
        for (int i = 0; i < molecule1->atomTypeCount; i++)
        {
            addAtom(&combinedMolecule, molecule1->atoms[i].symbol, molecule1->atoms[i].count);
        }
    }

    // Tambahkan semua atom dari molekul kedua.
    // Fungsi addAtom akan menangani jika simbol sudah ada (menjumlahkan count).
    if (molecule2 != NULL) {
        for (int i = 0; i < molecule2->atomTypeCount; i++)
        {
            addAtom(&combinedMolecule, molecule2->atoms[i].symbol, molecule2->atoms[i].count);
        }
    }

    sortMolecule(&combinedMolecule); // Urutkan hasil akhir untuk konsistensi
    return combinedMolecule;
}

/**
 * @brief Memeriksa apakah molekul `moleculeToSubtract` dapat dikurangkan dari `totalMolecule`.
 * @details Dapat dikurangkan jika `totalMolecule` memiliki jumlah atom yang cukup
 *          untuk setiap tipe atom yang ada di `moleculeToSubtract`.
 * @param totalMolecule Pointer ke molekul total.
 * @param moleculeToSubtract Pointer ke molekul yang akan dikurangkan.
 * @return bool true jika pengurangan dimungkinkan, false jika tidak.
 * @note I.S. : `totalMolecule` dan `moleculeToSubtract` terdefinisi.
 * @note F.S. : Mengembalikan status apakah pengurangan bisa dilakukan.
 */
bool canSubtract(const Molecule *totalMolecule, const Molecule *moleculeToSubtract)
{
    if (totalMolecule == NULL || moleculeToSubtract == NULL)
    {
        // Pengurangan tidak mungkin jika salah satu molekul tidak ada.
        // Jika moleculeToSubtract kosong, maka selalu bisa dikurangkan.
        return (moleculeToSubtract == NULL || moleculeToSubtract->atomTypeCount == 0);
    }

    // Periksa setiap tipe atom dalam molekul yang akan dikurangkan.
    for (int i = 0; i < moleculeToSubtract->atomTypeCount; i++)
    {
        const char *atomSymbolToSubtract = moleculeToSubtract->atoms[i].symbol;
        int countNeeded = moleculeToSubtract->atoms[i].count;
        int countAvailable = getAtomCount(totalMolecule, atomSymbolToSubtract);

        if (countAvailable < countNeeded)
        {
            return false; // Tidak cukup atom tersedia untuk dikurangkan.
        }
    }
    return true; // Semua atom yang dibutuhkan tersedia.
}

/**
 * @brief Mengurangkan satu molekul (`moleculeToSubtract`) dari molekul lain (`initialMolecule`).
 * @details Hanya atom yang ada di `initialMolecule` yang akan dikurangi.
 *          Jika `moleculeToSubtract` mengandung atom yang tidak ada di `initialMolecule`,
 *          atau jika jumlahnya lebih banyak, operasi pengurangan untuk atom tersebut
 *          tidak akan menghasilkan jumlah negatif (minimal 0).
 *          Fungsi ini mengembalikan molekul baru hasil pengurangan.
 * @param initialMolecule Pointer ke molekul awal.
 * @param moleculeToSubtract Pointer ke molekul yang akan dikurangkan.
 * @return Molecule Molekul baru hasil pengurangan. Mengembalikan molekul kosong jika
 *                  input tidak valid atau pengurangan tidak memungkinkan (`canSubtract` false).
 * @note I.S. : `initialMolecule` dan `moleculeToSubtract` terdefinisi.
 * @note F.S. : Mengembalikan molekul hasil.
 */
Molecule subtractMolecule(const Molecule *initialMolecule, const Molecule *moleculeToSubtract)
{
    Molecule resultingMolecule;
    createMolecule(&resultingMolecule); // Inisialisasi hasil.

    // Jika input tidak valid atau pengurangan tidak bisa dilakukan, kembalikan molekul kosong.
    if (initialMolecule == NULL || !canSubtract(initialMolecule, moleculeToSubtract))
    {
        // Jika moleculeToSubtract NULL, canSubtract akan true, jadi kita copy initialMolecule.
        if (initialMolecule != NULL && moleculeToSubtract == NULL) {
            for (int i = 0; i < initialMolecule->atomTypeCount; i++) {
                addAtom(&resultingMolecule, initialMolecule->atoms[i].symbol, initialMolecule->atoms[i].count);
            }
            sortMolecule(&resultingMolecule);
            return resultingMolecule;
        }
        return resultingMolecule; // Kembalikan kosong jika canSubtract false atau initialMolecule NULL
    }

    // Salin semua atom dari initialMolecule ke resultingMolecule.
    for (int i = 0; i < initialMolecule->atomTypeCount; i++)
    {
        addAtom(&resultingMolecule, initialMolecule->atoms[i].symbol, initialMolecule->atoms[i].count);
    }

    // Kurangkan atom berdasarkan moleculeToSubtract.
    if (moleculeToSubtract != NULL) { // Pastikan moleculeToSubtract tidak NULL
        for (int i = 0; i < moleculeToSubtract->atomTypeCount; i++)
        {
            const char *currentAtomSymbol = moleculeToSubtract->atoms[i].symbol;
            int countToSubtract = moleculeToSubtract->atoms[i].count;

            // Cari atom yang sama di resultingMolecule dan kurangi jumlahnya.
            for (int j = 0; j < resultingMolecule.atomTypeCount; j++)
            {
                if (strcmp(resultingMolecule.atoms[j].symbol, currentAtomSymbol) == 0)
                {
                    resultingMolecule.atoms[j].count -= countToSubtract;
                    // Jika count menjadi <= 0, idealnya atom ini dihapus dari list,
                    // tapi ADT saat ini tidak memiliki fungsi removeAtom.
                    // Untuk sementara, atom dengan count <= 0 tidak akan dicetak oleh printMoleculeFormula.
                    // Jika count menjadi negatif, itu masalah. Asumsi canSubtract mencegah ini.
                    if (resultingMolecule.atoms[j].count < 0) resultingMolecule.atoms[j].count = 0; // Pastikan tidak negatif
                    break;
                }
            }
        }
    }

    // Membersihkan atom dengan count 0 dari resultingMolecule (opsional, tapi baik)
    Molecule finalResult;
    createMolecule(&finalResult);
    for(int i=0; i < resultingMolecule.atomTypeCount; i++){
        if(resultingMolecule.atoms[i].count > 0){
            addAtom(&finalResult, resultingMolecule.atoms[i].symbol, resultingMolecule.atoms[i].count);
        }
    }
    sortMolecule(&finalResult);
    return finalResult;
}