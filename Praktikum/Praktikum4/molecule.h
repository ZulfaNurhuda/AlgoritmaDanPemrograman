/**
 * --------------------------------------------------------------
 * | @file molecule.h                                           |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Header file untuk Abstract Data Type (ADT) Molekul.        |
 * | Mendefinisikan struktur data untuk AtomInfo dan Molecule,  |
 * | serta prototipe fungsi untuk memanipulasi molekul.         |
 * --------------------------------------------------------------
 */

#ifndef MOLECULE_H
#define MOLECULE_H

#include <stdbool.h> // Untuk tipe data bool

/* ***************************************************** */
/* ********************** KONSTANTA ******************** */
/* ***************************************************** */

#define MAX_ATOM_TYPES 20    // Jumlah maksimum tipe atom yang berbeda dalam satu molekul.
#define MAX_SYMBOL_LEN 4     // Panjang maksimum string simbol atom (misal "Fe" + null, "Cl" + null).
                             // Sebaiknya (3 + 1) untuk simbol seperti "Au", "Cl". Jika ada simbol 3 huruf, perlu 4.

/* ***************************************************** */
/* ********************** TIPE DATA ******************** */
/* ***************************************************** */

/**
 * @struct AtomInfo
 * @brief Menyimpan informasi satu jenis atom dalam molekul.
 * @details Terdiri dari simbol kimia atom dan jumlah atom tersebut dalam molekul.
 */
typedef struct AtomInfo // Memberi nama pada struct untuk kejelasan
{
    char symbol[MAX_SYMBOL_LEN]; /**< Simbol atom (contoh: "H", "O", "Fe"). Null-terminated. */
    int count;                   /**< Jumlah atom jenis ini dalam molekul. */
} AtomInfo;

/**
 * @struct Molecule
 * @brief Merepresentasikan sebuah molekul sebagai kumpulan dari berbagai jenis atom.
 * @details Terdiri dari array `AtomInfo` dan jumlah tipe atom yang berbeda saat ini.
 */
typedef struct Molecule // Memberi nama pada struct untuk kejelasan
{
    AtomInfo atoms[MAX_ATOM_TYPES]; /**< Array untuk menyimpan informasi setiap tipe atom. */
    int atomTypeCount;             /**< Jumlah tipe atom yang berbeda saat ini dalam molekul. */
} Molecule;

/* ***************************************************** */
/* ******************** KONSTRUKTOR ******************** */
/* ***************************************************** */

/**
 * @brief Menginisialisasi sebuah molekul menjadi kosong.
 * @details Mengatur `atomTypeCount` menjadi 0 dan membersihkan array `atoms`.
 * @param molecule Pointer ke `Molecule` yang akan diinisialisasi.
 * @note I.S. : `molecule` adalah pointer valid.
 * @note F.S. : `molecule` terinisialisasi sebagai molekul kosong.
 */
void createMolecule(Molecule *molecule);

/* ***************************************************** */
/* ***************** OPERASI MOLEKUL ******************* */
/* ***************************************************** */

/**
 * @brief Menambahkan sejumlah atom dengan simbol tertentu ke dalam molekul.
 * @details Jika atom dengan simbol tersebut sudah ada, jumlahnya akan ditambahkan.
 *          Jika belum ada dan masih ada kapasitas (`atomTypeCount < MAX_ATOM_TYPES`),
 *          atom baru akan ditambahkan. Jika kapasitas penuh, atom baru diabaikan.
 * @param molecule Pointer ke `Molecule` yang akan ditambahkan atom.
 * @param atomSymbol Simbol atom yang akan ditambahkan (string, contoh: "H").
 * @param atomCount Jumlah atom yang akan ditambahkan (harus positif).
 * @note I.S. : `molecule` terdefinisi, `atomSymbol` valid, `atomCount` > 0.
 * @note F.S. : Komposisi atom dalam `molecule` diperbarui.
 */
void addAtom(Molecule *molecule, const char *atomSymbol, int atomCount);

/**
 * @brief Mendapatkan perkiraan massa atom relatif (Ar) untuk simbol atom yang diberikan.
 * @details Ini adalah fungsi helper yang disediakan (JANGAN UBAH implementasinya).
 * @param atomSymbol Simbol atom (string).
 * @return double Massa atom relatif, atau 0.0 jika simbol tidak diketahui.
 * @note I.S. : `atomSymbol` terdefinisi.
 * @note F.S. : Mengembalikan Ar atau 0.0.
 */
double getAtomicWeight(const char *atomSymbol);

/**
 * @brief Menghitung perkiraan berat molekul total (Mr) dari sebuah molekul.
 * @details Menggunakan `getAtomicWeight` untuk mendapatkan Ar setiap jenis atom.
 * @param molecule Pointer ke `Molecule` (const, tidak dimodifikasi) yang akan dihitung beratnya.
 * @return double Berat molekul total. Mengembalikan 0.0 jika molekul NULL atau kosong.
 * @note I.S. : `molecule` terdefinisi.
 * @note F.S. : Mengembalikan Mr dari `molecule`.
 */
double calculateMolecularWeight(const Molecule *molecule);

/**
 * @brief Mendapatkan jumlah atom dengan simbol tertentu dalam sebuah molekul.
 * @param molecule Pointer ke `Molecule` (const) yang akan dicari.
 * @param atomSymbol Simbol atom (string) yang jumlahnya ingin diketahui.
 * @return int Jumlah atom dengan simbol tersebut. Mengembalikan 0 jika
 *             molekul NULL, `atomSymbol` tidak valid, atau atom tidak ditemukan.
 * @note I.S. : `molecule` dan `atomSymbol` terdefinisi.
 * @note F.S. : Mengembalikan jumlah atom.
 */
int getAtomCount(const Molecule *molecule, const char *atomSymbol);

/**
 * @brief Membandingkan dua molekul untuk kesetaraan komposisi atom.
 * @details Dua molekul dianggap sama jika memiliki jenis atom yang sama
 *          dengan jumlah yang sama untuk setiap jenis atom, tidak memperdulikan
 *          urutan atom dalam array internal. Memerlukan pengurutan internal.
 * @param molecule1 Pointer ke `Molecule` pertama (const).
 * @param molecule2 Pointer ke `Molecule` kedua (const).
 * @return bool `true` jika kedua molekul memiliki komposisi yang sama, `false` jika tidak.
 * @note I.S. : `molecule1` dan `molecule2` terdefinisi.
 * @note F.S. : Mengembalikan status kesetaraan.
 */
bool areEqual(const Molecule *molecule1, const Molecule *molecule2);

/**
 * @brief Mencetak formula kimia molekul ke standar output.
 * @details Format: Simbol diikuti jumlah jika jumlah > 1. Atom-atom diurutkan
 *          berdasarkan konvensi kimia sebelum dicetak.
 *          Contoh: C6H12O6, H2O, NaCl. Jika molekul kosong, cetak "(Kosong)".
 * @param molecule Pointer ke `Molecule` (const) yang akan dicetak formulanya.
 * @note I.S. : `molecule` terdefinisi.
 * @note F.S. : Formula molekul dicetak ke layar, diakhiri newline.
 */
void printMoleculeFormula(const Molecule *molecule);

/**
 * @brief Menggabungkan dua molekul menjadi satu molekul baru.
 * @details Membuat molekul baru yang berisi semua atom dari `molecule1` dan `molecule2`.
 *          Jumlah atom dengan simbol yang sama akan dijumlahkan.
 *          Jika hasil penggabungan melebihi `MAX_ATOM_TYPES`, atom tambahan
 *          dari `molecule2` yang tidak muat akan diabaikan (sesuai perilaku `addAtom`).
 * @param molecule1 Pointer ke `Molecule` pertama (const).
 * @param molecule2 Pointer ke `Molecule` kedua (const).
 * @return Molecule Molekul baru hasil penggabungan. Mengembalikan molekul kosong jika kedua input NULL.
 * @note I.S. : `molecule1` dan `molecule2` terdefinisi.
 * @note F.S. : Mengembalikan molekul baru hasil penggabungan.
 */
Molecule combineMolecules(const Molecule *molecule1, const Molecule *molecule2);

/**
 * @brief Memeriksa apakah molekul `moleculeToSubtract` dapat dikurangkan dari `totalMolecule`.
 * @details Pengecekan berhasil jika untuk setiap jenis atom dalam `moleculeToSubtract`,
 *          jumlah atom tersebut dalam `totalMolecule` lebih besar atau sama.
 * @param totalMolecule Pointer ke `Molecule` total (const).
 * @param moleculeToSubtract Pointer ke `Molecule` yang akan dikurangkan (const).
 * @return bool `true` jika `moleculeToSubtract` dapat dikurangkan dari `totalMolecule`, `false` jika tidak.
 * @note I.S. : `totalMolecule` dan `moleculeToSubtract` terdefinisi.
 * @note F.S. : Mengembalikan status apakah pengurangan bisa dilakukan.
 */
bool canSubtract(const Molecule *totalMolecule, const Molecule *moleculeToSubtract);

/**
 * @brief Mengurangkan molekul `moleculeToSubtract` dari `initialMolecule` dan mengembalikan hasilnya.
 * @details Fungsi ini pertama-tama akan memanggil `canSubtract`.
 *          Jika `canSubtract` mengembalikan `false`, fungsi ini akan mengembalikan
 *          molekul kosong. Jika `true`, molekul baru dibuat sebagai salinan `initialMolecule`,
 *          kemudian jumlah atom dari `moleculeToSubtract` dikurangkan.
 *          Atom dengan jumlah 0 atau kurang setelah pengurangan akan dihilangkan dari hasil.
 * @param initialMolecule Pointer ke `Molecule` total (const).
 * @param moleculeToSubtract Pointer ke `Molecule` yang akan dikurangkan (const).
 * @return Molecule Molekul baru hasil pengurangan, atau molekul kosong jika
 *                  pengurangan tidak memungkinkan atau input tidak valid.
 * @note I.S. : `initialMolecule` dan `moleculeToSubtract` terdefinisi.
 * @note F.S. : Mengembalikan molekul hasil pengurangan.
 */
Molecule subtractMolecule(const Molecule *initialMolecule, const Molecule *moleculeToSubtract);

/* Fungsi-fungsi helper untuk sorting (biasanya tidak dipanggil langsung oleh pengguna ADT) */
/* Komentar untuk fungsi ini dipertahankan dari implementasi .c karena sudah detail */
int getAtomPriority(const char *symbol);
double getElectronegativity(const char *symbol);
int compareAtomInfo(const void *a, const void *b);
void sortMolecule(Molecule *molecule);

#endif // MOLECULE_H