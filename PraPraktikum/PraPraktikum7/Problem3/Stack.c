/**
 * --------------------------------------------------------------
 * | @file Stack.c                                              |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Implementasi ADT Stack statis.                             |
 * --------------------------------------------------------------
 */

#include "Stack.h"

void createStack(Stack *stack)
{
    // Inisialisasi stack kosong dengan top = IDX_UNDEF
    IDX_TOP(*stack) = IDX_UNDEF;
}

bool isEmpty(Stack stack)
{
    // Stack kosong jika top belum didefinisikan
    return (IDX_TOP(stack) == IDX_UNDEF);
}

bool isFull(Stack stack)
{
    // Stack penuh jika top berada di indeks terakhir array
    return (IDX_TOP(stack) == (CAPACITY - 1));
}

int length(Stack stack)
{
    // Panjang stack = indeks top + 1 (karena top dimulai dari 0)
    return (IDX_TOP(stack) + 1);
}

void push(Stack *stack, ElType newElement)
{
    // Tambahkan elemen ke atas stack jika belum penuh
    if (!isFull(*stack))
    {
        IDX_TOP(*stack)++;        // Geser top ke atas
        TOP(*stack) = newElement; // Simpan elemen di atas stack
    }
}

void pop(Stack *stack, ElType *poppedElement)
{
    // Ambil elemen dari atas stack jika tidak kosong
    if (!isEmpty(*stack))
    {
        *poppedElement = TOP(*stack); // Ambil elemen teratas
        IDX_TOP(*stack)--;            // Geser top ke bawah
    }
}