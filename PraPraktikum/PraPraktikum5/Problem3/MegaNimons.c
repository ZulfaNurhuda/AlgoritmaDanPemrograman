/**
 * --------------------------------------------------------------
 * | @file MegaNimons.c                                         |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Implementasi ADT LabTrack untuk manajemen data MegaNimons. |
 * --------------------------------------------------------------
 */

#include "MegaNimons.h"

void createLabTrack(LabTrack *labTrack)
{
    // Inisialisasi jumlah elemen efektif menjadi 0
    setLength(labTrack, 0);
}

int length(LabTrack labTrack)
{
    // Mengembalikan jumlah elemen saat ini
    return labTrack.nEff;
}

int maxCapacity()
{
    // Mengembalikan kapasitas maksimum dari LabTrack
    return CAPACITY;
}

IdxType firstIndex(LabTrack labTrack)
{
    // Jika tidak kosong, indeks pertama adalah 0
    int firstIdx;
    if (!isEmpty(labTrack))
    {
        firstIdx = 0;
    }
    else
    {
        // Jika kosong, kembalikan indeks tak terdefinisi
        firstIdx = IDX_UNDEF;
    }

    return firstIdx;
}

IdxType lastIndex(LabTrack labTrack)
{
    // Indeks terakhir = panjang - 1
    return length(labTrack) - 1;
}

MegaNimons getElement(LabTrack labTrack, IdxType idx)
{
    // Mengambil elemen pada indeks ke-idx
    return labTrack.contents[idx];
}

void setElement(LabTrack *labTrack, IdxType idx, MegaNimons element)
{
    // Menetapkan elemen pada indeks tertentu jika valid
    if (isIndexValid(idx))
    {
        labTrack->contents[idx] = element;
    }
}

void setLength(LabTrack *labTrack, int nEff)
{
    // Menetapkan jumlah elemen efektif jika dalam batas valid
    if (isIndexValid(nEff))
    {
        labTrack->nEff = nEff;
    }
}

bool isIndexValid(IdxType idx)
{
    // Indeks valid jika dalam rentang kapasitas array
    return (idx >= 0 && idx < maxCapacity());
}

bool isIndexEff(LabTrack labTrack, IdxType idx)
{
    // Indeks efektif jika dalam rentang indeks yang digunakan
    return (idx >= firstIndex(labTrack) && idx < length(labTrack));
}

bool isEmpty(LabTrack labTrack)
{
    // LabTrack kosong jika panjang = 0
    return (length(labTrack) == 0);
}

bool isFull(LabTrack labTrack)
{
    // LabTrack penuh jika panjang = kapasitas maksimum
    return (length(labTrack) == maxCapacity());
}

void insertAt(LabTrack *labTrack, MegaNimons newElement, IdxType idx)
{
    if (!isFull(*labTrack) && isIndexValid(idx))
    {
        // Geser semua elemen dari kanan ke kiri mulai dari akhir ke idx
        for (IdxType i = length(*labTrack); i > idx; i--)
        {
            setElement(labTrack, i, getElement(*labTrack, i - 1));
        }

        // Tempatkan elemen baru pada posisi yang diminta
        setElement(labTrack, idx, newElement);
        setLength(labTrack, length(*labTrack) + 1);
    }
}

void insertFirst(LabTrack *labTrack, MegaNimons newElement)
{
    // Sisipkan di awal (indeks pertama)
    insertAt(labTrack, newElement, firstIndex(*labTrack));
}

void insertLast(LabTrack *labTrack, MegaNimons newElement)
{
    // Sisipkan di akhir (indeks setelah elemen terakhir)
    insertAt(labTrack, newElement, length(*labTrack));
}

void deleteAt(LabTrack *labTrack, IdxType idx, MegaNimons *deletedElement)
{
    if (isIndexEff(*labTrack, idx) && !isEmpty(*labTrack))
    {
        // Salin elemen yang akan dihapus ke variabel output
        (*deletedElement) = getElement(*labTrack, idx);

        // Geser elemen setelah idx ke kiri
        for (IdxType i = idx; i < lastIndex(*labTrack); i++)
        {
            setElement(labTrack, i, getElement(*labTrack, i + 1));
        }

        // Kurangi panjang array
        setLength(labTrack, length(*labTrack) - 1);
    }
}

void deleteFirst(LabTrack *labTrack, MegaNimons *deletedElement)
{
    // Hapus elemen pertama
    deleteAt(labTrack, firstIndex(*labTrack), deletedElement);
}

void deleteLast(LabTrack *labTrack, MegaNimons *deletedElement)
{
    if (!isEmpty(*labTrack))
    {
        // Hapus elemen terakhir
        deleteAt(labTrack, lastIndex(*labTrack), deletedElement);
    }
}

IdxType indexOf(LabTrack labTrack, int id)
{
    // Mencari indeks dari MegaNimons dengan ID tertentu
    IdxType foundIndex = IDX_UNDEF;
    for (IdxType i = firstIndex(labTrack); i < length(labTrack) && foundIndex == IDX_UNDEF; i++)
    {
        if (getElement(labTrack, i).id == id)
        {
            foundIndex = i;
        }
    }
    return foundIndex;
}

/* ********** Utilitas dan Output ********** */

void printLabTrack(LabTrack labTrack)
{
    if (isEmpty(labTrack))
    {
        // Jika kosong, tampilkan pesan
        printf("LabTrack is empty.\n");
    }
    else
    {
        // Cetak setiap MegaNimons
        for (IdxType i = firstIndex(labTrack); i < length(labTrack); i++)
        {
            MegaNimons currentNimon = getElement(labTrack, i);

            // Ubah status stabil menjadi string "Yes" atau "No"
            char *isStable;
            if (currentNimon.isStable)
            {
                isStable = "Yes";
            }
            else
            {
                isStable = "No";
            }

            // Tampilkan informasi lengkap
            printf("[%d] ID=%d NAME=%s POWER=%.1f MUT=%s STABLE=%s\n", i, currentNimon.id, currentNimon.name, currentNimon.powerLevel, currentNimon.mutationType, isStable);
        }
    }
}

void ejectUnstable(LabTrack *labTrack)
{
    // Buat lab sementara hanya untuk MegaNimons yang stabil
    LabTrack stableTrack;
    createLabTrack(&stableTrack);

    for (IdxType i = firstIndex(*labTrack); i < length(*labTrack); i++)
    {
        MegaNimons currentNimon = getElement(*labTrack, i);
        if (currentNimon.isStable)
        {
            insertLast(&stableTrack, currentNimon);
        }
        else
        {
            // Tampilkan siapa yang dikeluarkan
            printf("EJECTED: %s\n", currentNimon.name);
        }
    }

    // Salin isi lab stabil ke lab asli
    (*labTrack) = stableTrack;
}

void filterByPower(LabTrack labTrack, float minPower)
{
    IdxType idx = 0;
    for (IdxType i = firstIndex(labTrack); i < length(labTrack); i++)
    {
        MegaNimons currentNimon = getElement(labTrack, i);
        if (currentNimon.powerLevel >= minPower)
        {
            // Konversi stabil ke string
            char *isStable;
            if (currentNimon.isStable)
            {
                isStable = "Yes";
            }
            else
            {
                isStable = "No";
            }

            // Tampilkan yang memenuhi syarat kekuatan
            printf("[%d] ID=%d NAME=%s POWER=%.1f MUT=%s STABLE=%s\n", idx, currentNimon.id, currentNimon.name, currentNimon.powerLevel, currentNimon.mutationType, isStable);
            idx++;
        }
    }
}