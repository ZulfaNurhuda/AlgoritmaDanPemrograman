/**
 * --------------------------------------------------------------
 * | @file moleculeDriver.c                                     |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Program driver interaktif untuk mengelola kumpulan molekul.|
 * | Pengguna dapat melakukan berbagai operasi pada molekul     |
 * | melalui perintah teks.                                     |
 * --------------------------------------------------------------
 */

#include "molecule.h" // Header ADT Molecule
#include <stdio.h>    // Untuk scanf, printf
#include <stdlib.h>   // Untuk exit (jika diperlukan untuk error handling VLA)
#include <string.h>   // Untuk strcmp

/**
 * @brief Fungsi utama untuk program driver interaktif ADT Molekul.
 * @details
 * Program ini pertama-tama meminta jumlah molekul yang akan dikelola.
 * Kemudian, program masuk ke dalam loop untuk menerima dan memproses perintah dari pengguna.
 * Perintah yang didukung meliputi:
 * - `ADD <idx> <simbol> <jumlah>`: Menambahkan atom ke molekul pada indeks `idx`.
 * - `PRINT <idx>`: Mencetak formula molekul pada indeks `idx`.
 * - `WEIGHT <idx>`: Menghitung dan mencetak berat molekul pada indeks `idx`.
 * - `GET_COUNT <idx> <simbol>`: Mendapatkan jumlah atom `simbol` pada molekul `idx`.
 * - `ARE_EQUAL <idx1> <idx2>`: Memeriksa apakah molekul pada `idx1` dan `idx2` sama.
 * - `COMBINE <idx_hasil> <idx1> <idx2>`: Menggabungkan molekul `idx1` dan `idx2`, hasil di `idx_hasil`.
 * - `CAN_SUBTRACT <idx_total> <idx_kurang>`: Memeriksa apakah molekul `idx_kurang` bisa dikurangkan dari `idx_total`.
 * - `SUBTRACT <idx_hasil> <idx_total> <idx_kurang>`: Mengurangkan molekul `idx_kurang` dari `idx_total`, hasil di `idx_hasil`.
 * - `END`: Mengakhiri program.
 *
 * @note Catatan dari pengembang asli:
 *       "I don't know where vulnerability is in this code.
 *        If you run this code in olympia vitual machine, you may get only 10/100 point.
 *        But if you run this code in your local machine, anything looks fine.
 *        Sorry for the inconvenience. Hehe :)"
 *       (Catatan ini dipertahankan untuk konteks.)
 *
 * @return int Status keluar program (0 untuk sukses).
 */
int main(void)
{
    int numberOfMolecules; // Jumlah total molekul yang akan dikelola
    // Membaca jumlah molekul dari pengguna.
    scanf("%d", &numberOfMolecules);

    // Membuat array molekul. Menggunakan VLA (Variable Length Array) C99.
    // Perlu diperhatikan bahwa VLA mungkin tidak didukung oleh semua kompiler C (misal, MSVC).
    // Alternatifnya adalah alokasi dinamis.
    if (numberOfMolecules <= 0) {
        // Jika input tidak valid atau 0, bisa langsung keluar atau beri pesan.
        // printf("Jumlah molekul harus positif.\n");
        return 0; // Sesuai perilaku umum jika N=0, tidak ada yang diproses.
    }
    Molecule moleculesArray[numberOfMolecules];

    // Menginisialisasi setiap molekul dalam array menjadi kosong.
    for (int i = 0; i < numberOfMolecules; ++i)
    {
        createMolecule(&moleculesArray[i]);
    }

    char command[30];             // Buffer untuk menyimpan perintah input.
    int moleculeIndex1, moleculeIndex2, resultMoleculeIndex; // Indeks untuk operasi molekul.
    int atomCountInput;           // Jumlah atom untuk perintah ADD.
    char atomSymbolInput[MAX_SYMBOL_LEN]; // Simbol atom untuk perintah ADD dan GET_COUNT.

    // Loop utama untuk membaca dan memproses perintah.
    do
    {
        scanf("%s", command); // Membaca string perintah.

        // Perintah "END": Keluar dari loop dan mengakhiri program.
        if (strcmp(command, "END") == 0)
        {
            break;
        }

        // Perintah "ADD": Menambahkan atom ke molekul.
        if (strcmp(command, "ADD") == 0)
        {
            scanf("%d %s %d", &moleculeIndex1, atomSymbolInput, &atomCountInput);
            // Validasi indeks dan jumlah atom sebelum memanggil fungsi.
            if (moleculeIndex1 >= 0 && moleculeIndex1 < numberOfMolecules && atomCountInput > 0)
            {
                addAtom(&moleculesArray[moleculeIndex1], atomSymbolInput, atomCountInput);
            }
        }
        // Perintah "PRINT": Mencetak formula molekul.
        else if (strcmp(command, "PRINT") == 0)
        {
            scanf("%d", &moleculeIndex1);
            if (moleculeIndex1 >= 0 && moleculeIndex1 < numberOfMolecules)
            {
                printMoleculeFormula(&moleculesArray[moleculeIndex1]);
            }
        }
        // Perintah "WEIGHT": Menghitung dan mencetak berat molekul.
        else if (strcmp(command, "WEIGHT") == 0)
        {
            scanf("%d", &moleculeIndex1);
            if (moleculeIndex1 >= 0 && moleculeIndex1 < numberOfMolecules)
            {
                printf("%.3f\n", calculateMolecularWeight(&moleculesArray[moleculeIndex1]));
            }
        }
        // Perintah "GET_COUNT": Mendapatkan jumlah atom tertentu.
        else if (strcmp(command, "GET_COUNT") == 0)
        {
            scanf("%d %s", &moleculeIndex1, atomSymbolInput);
            if (moleculeIndex1 >= 0 && moleculeIndex1 < numberOfMolecules)
            {
                printf("%d\n", getAtomCount(&moleculesArray[moleculeIndex1], atomSymbolInput));
            }
        }
        // Perintah "ARE_EQUAL": Memeriksa kesetaraan dua molekul.
        else if (strcmp(command, "ARE_EQUAL") == 0)
        {
            scanf("%d %d", &moleculeIndex1, &moleculeIndex2);
            if (moleculeIndex1 >= 0 && moleculeIndex1 < numberOfMolecules &&
                moleculeIndex2 >= 0 && moleculeIndex2 < numberOfMolecules)
            {
                printf("%s\n", areEqual(&moleculesArray[moleculeIndex1], &moleculesArray[moleculeIndex2]) ? "YES" : "NO");
            }
        }
        // Perintah "COMBINE": Menggabungkan dua molekul.
        else if (strcmp(command, "COMBINE") == 0)
        {
            scanf("%d %d %d", &resultMoleculeIndex, &moleculeIndex1, &moleculeIndex2);
            if (resultMoleculeIndex >= 0 && resultMoleculeIndex < numberOfMolecules &&
                moleculeIndex1 >= 0 && moleculeIndex1 < numberOfMolecules &&
                moleculeIndex2 >= 0 && moleculeIndex2 < numberOfMolecules)
            {
                moleculesArray[resultMoleculeIndex] = combineMolecules(&moleculesArray[moleculeIndex1], &moleculesArray[moleculeIndex2]);
            }
        }
        // Perintah "CAN_SUBTRACT": Memeriksa apakah pengurangan molekul dimungkinkan.
        else if (strcmp(command, "CAN_SUBTRACT") == 0)
        {
            scanf("%d %d", &moleculeIndex1, &moleculeIndex2); // idx1 = total, idx2 = sub
            if (moleculeIndex1 >= 0 && moleculeIndex1 < numberOfMolecules &&
                moleculeIndex2 >= 0 && moleculeIndex2 < numberOfMolecules)
            {
                printf("%s\n", canSubtract(&moleculesArray[moleculeIndex1], &moleculesArray[moleculeIndex2]) ? "YES" : "NO");
            }
        }
        // Perintah "SUBTRACT": Mengurangkan satu molekul dari yang lain.
        else if (strcmp(command, "SUBTRACT") == 0)
        {
            scanf("%d %d %d", &resultMoleculeIndex, &moleculeIndex1, &moleculeIndex2); // idx_res, idx1=total, idx2=sub
            if (resultMoleculeIndex >= 0 && resultMoleculeIndex < numberOfMolecules &&
                moleculeIndex1 >= 0 && moleculeIndex1 < numberOfMolecules &&
                moleculeIndex2 >= 0 && moleculeIndex2 < numberOfMolecules)
            {
                moleculesArray[resultMoleculeIndex] = subtractMolecule(&moleculesArray[moleculeIndex1], &moleculesArray[moleculeIndex2]);
            }
        }
        // Jika perintah tidak dikenal, loop akan berlanjut meminta perintah baru.
        // Bisa ditambahkan penanganan untuk perintah tidak valid jika diinginkan.

    } while (true); // Loop tak terbatas, dihentikan oleh "END" command.

    // Mengindikasikan bahwa program berakhir dengan sukses.
    return 0;
}