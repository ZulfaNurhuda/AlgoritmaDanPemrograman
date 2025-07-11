/**
 * --------------------------------------------------------------
 * | @file ListLinier.c                                         |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Implementasi ADT List Linier yang sesuai dengan header     |
 * | ListLinier.h                                               |
 * --------------------------------------------------------------
 */

#include "ListLinier.h"

bool isEmpty(List list)
{
    // Mengecek apakah list kosong dengan memeriksa apakah FIRST bernilai NIL
    return (FIRST(list) == NIL);
}

void createEmpty(List *list)
{
    // Menginisialisasi list kosong dengan mengatur pointer ke elemen pertama menjadi NIL
    FIRST(*list) = NIL;
}

Address allocate(InfoType value)
{
    // Mengalokasikan memori untuk node baru
    Address newNode = (Address)malloc(sizeof(NodeList));

    // Jika alokasi berhasil
    if (newNode != NIL)
    {
        INFO(newNode) = value; // Isi info dengan nilai yang diberikan
        NEXT(newNode) = NIL;   // Node baru belum menunjuk ke node lain
    }

    return newNode; // Kembalikan pointer node baru (atau NIL jika gagal)
}

void deallocate(Address *node)
{
    // Menghapus node dari memori dan set pointer-nya ke NIL
    free(*node);
    *node = NIL;
}

Address search(List list, InfoType query)
{
    Address currentNode = FIRST(list); // Mulai dari head list
    bool found = false;

    // Selama belum ditemukan dan node belum habis
    while (currentNode != NIL && !found)
    {
        // Jika data sesuai
        if (INFO(currentNode) == query)
        {
            found = true;
        }
        else
        {
            currentNode = NEXT(currentNode); // Lanjut ke node berikutnya
        }
    }

    // Jika tidak ditemukan, kembalikan NIL
    if (!found)
    {
        currentNode = NIL;
    }

    return currentNode;
}

void insertValueFirst(List *list, InfoType newValue)
{
    // Alokasi node baru dengan nilai yang diberikan
    Address newNode = allocate(newValue);

    // Jika alokasi berhasil, insert ke depan
    if (newNode != NIL)
    {
        insertFirst(list, newNode);
    }
}

void insertValueLast(List *list, InfoType newValue)
{
    // Alokasi node baru dengan nilai yang diberikan
    Address newNode = allocate(newValue);

    // Jika alokasi berhasil, insert ke belakang
    if (newNode != NIL)
    {
        insertLast(list, newNode);
    }
}

void deleteValueFirst(List *list, InfoType *deletedValue)
{
    Address deletedNode;

    // Hapus elemen pertama dan simpan pointer-nya
    deleteFirst(list, &deletedNode);

    *deletedValue = INFO(deletedNode); // Ambil nilai dari node
    deallocate(&deletedNode);          // Dealokasi node
}

void deleteValueLast(List *list, InfoType *deletedValue)
{
    Address deletedNode;

    // Hapus elemen terakhir dan simpan pointer-nya
    deleteLast(list, &deletedNode);

    *deletedValue = INFO(deletedNode); // Ambil nilai dari node
    deallocate(&deletedNode);          // Dealokasi node
}

void insertFirst(List *list, Address node)
{
    // Hubungkan node baru ke node pertama sebelumnya
    NEXT(node) = FIRST(*list);

    // Jadikan node baru sebagai elemen pertama
    FIRST(*list) = node;
}

void insertAfter(Address node, Address prevNode)
{
    // Hubungkan node baru ke node setelah prevNode
    NEXT(node) = NEXT(prevNode);

    // Hubungkan prevNode ke node baru
    NEXT(prevNode) = node;
}

void insertLast(List *list, Address newNode)
{
    // Jika list kosong, langsung insert di depan
    if (isEmpty(*list))
    {
        insertFirst(list, newNode);
    }
    else
    {
        // Cari node terakhir
        Address lastNode = FIRST(*list);
        while (NEXT(lastNode) != NIL)
        {
            lastNode = NEXT(lastNode);
        }

        // Sisipkan setelah node terakhir
        insertAfter(newNode, lastNode);
    }
}

void deleteFirst(List *list, Address *deletedNode)
{
    *deletedNode = FIRST(*list);       // Simpan pointer node pertama
    FIRST(*list) = NEXT(FIRST(*list)); // Perbarui pointer ke node berikutnya
    NEXT(*deletedNode) = NIL;          // Putuskan hubungan dengan list
}

void deleteNode(List *list, InfoType valueToDelete)
{
    if (!isEmpty(*list))
    {
        Address current = FIRST(*list); // Node saat ini
        Address prev = NIL;             // Node sebelumnya
        bool found = false;

        // Cari node dengan nilai yang cocok
        while (current != NIL && !found)
        {
            if (INFO(current) == valueToDelete)
            {
                found = true;
            }
            else
            {
                prev = current;
                current = NEXT(current);
            }
        }

        if (found)
        {
            if (prev == NIL)
            {
                deleteFirst(list, &current); // Node yang dihapus adalah yang pertama
            }
            else
            {
                Address deletedNode;
                deleteAfter(list, &deletedNode, prev); // Node di tengah/akhir
            }
            deallocate(&current); // Dealokasi node
        }
    }
}

void deleteLast(List *list, Address *deletedNode)
{
    Address lastNode = FIRST(*list); // Node terakhir
    Address prev = NIL;              // Node sebelum terakhir

    // Cari node terakhir
    while (NEXT(lastNode) != NIL)
    {
        prev = lastNode;
        lastNode = NEXT(lastNode);
    }

    *deletedNode = lastNode;

    // Jika hanya satu elemen
    if (prev == NIL)
    {
        FIRST(*list) = NIL;
    }
    else
    {
        NEXT(prev) = NIL; // Putuskan hubungan ke node terakhir
    }
}

void deleteAfter(List *list, Address *deletedNode, Address prevNode)
{
    *deletedNode = NEXT(prevNode); // Ambil node setelah prevNode

    if (*deletedNode != NIL)
    {
        NEXT(prevNode) = NEXT(*deletedNode); // Hubungkan prevNode ke node setelah deletedNode
        NEXT(*deletedNode) = NIL;            // Putuskan hubungan
    }
    else
    {
        NEXT(prevNode) = NIL; // prevNode menjadi node terakhir
    }
}

void printInfo(List list)
{
    printf("[");
    if (!isEmpty(list))
    {
        Address currentNode = FIRST(list);

        // Cetak satu per satu elemen list
        while (currentNode != NIL)
        {
            printf("%d", INFO(currentNode));
            currentNode = NEXT(currentNode);
            if (currentNode != NIL)
            {
                printf(",");
            }
        }
    }
    printf("]\n");
}

int numberOfElements(List list)
{
    int count = 0;
    Address currentNode = FIRST(list);

    // Hitung jumlah node
    while (currentNode != NIL)
    {
        count++;
        currentNode = NEXT(currentNode);
    }

    return count;
}

void inversList(List *list)
{
    Address current = FIRST(*list); // Node saat ini
    Address prev = NIL;             // Node sebelumnya
    Address nextNode = NIL;         // Node setelahnya

    // Balik arah setiap node
    while (current != NIL)
    {
        nextNode = NEXT(current);
        NEXT(current) = prev;
        prev = current;
        current = nextNode;
    }

    FIRST(*list) = prev; // Update head list
}

void concat(List *list1, List *list2, List *list3)
{
    createEmpty(list3);

    // Jika list1 kosong, list3 adalah list2
    if (isEmpty(*list1))
    {
        FIRST(*list3) = FIRST(*list2);
    }
    else
    {
        FIRST(*list3) = FIRST(*list1);

        // Temukan akhir list1
        Address lastL1 = FIRST(*list1);
        while (NEXT(lastL1) != NIL)
        {
            lastL1 = NEXT(lastL1);
        }

        // Sambungkan ke awal list2
        NEXT(lastL1) = FIRST(*list2);
    }

    // Kosongkan list1 dan list2
    createEmpty(list1);
    createEmpty(list2);
}

InfoType max(List list)
{
    Address p = FIRST(list);
    InfoType maxVal = INFO(p);

    // Cari nilai maksimum
    while (p != NIL)
    {
        if (INFO(p) > maxVal)
        {
            maxVal = INFO(p);
        }
        p = NEXT(p);
    }

    return maxVal;
}

Address addressMax(List list)
{
    Address p = FIRST(list);
    InfoType maxVal = INFO(p);
    Address maxAddr = p;

    // Cari alamat dengan nilai maksimum
    while (p != NIL)
    {
        if (INFO(p) > maxVal)
        {
            maxVal = INFO(p);
            maxAddr = p;
        }
        p = NEXT(p);
    }

    return maxAddr;
}

InfoType min(List list)
{
    Address p = FIRST(list);
    InfoType minVal = INFO(p);

    // Cari nilai minimum
    while (p != NIL)
    {
        if (INFO(p) < minVal)
        {
            minVal = INFO(p);
        }
        p = NEXT(p);
    }

    return minVal;
}

Address addressMin(List list)
{
    Address p = FIRST(list);
    InfoType minVal = INFO(p);
    Address minAddr = p;

    // Cari alamat dengan nilai minimum
    while (p != NIL)
    {
        if (INFO(p) < minVal)
        {
            minVal = INFO(p);
            minAddr = p;
        }
        p = NEXT(p);
    }

    return minAddr;
}

float average(List list)
{
    float total = 0.0;
    int count = 0;
    Address p = FIRST(list);

    // Jumlahkan seluruh nilai dalam list
    while (p != NIL)
    {
        total += INFO(p);
        count++;
        p = NEXT(p);
    }

    // Hitung rata-rata
    return total / count;
}