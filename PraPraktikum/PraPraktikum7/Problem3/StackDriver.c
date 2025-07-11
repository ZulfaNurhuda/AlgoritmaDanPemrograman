#include "Stack.h"

/* Untuk keperluan menampilkan isi Stack */
#include <stdio.h>

/**
 * @brief Mencetak isi Stack s ke layar
 *
 * Cetak string "Stack: " diikuti dengan isi Stack s. Jika Stack s kosong,
 * maka hanya dicetak "EMPTY". Jika Stack s tidak kosong, maka dicetak
 * semua elemen Stack stack dipisahkan dengan spasi.
 *
 * @param stack Stack yang akan dicetak
 */
static void printStack(Stack stack)
{
    printf("Stack: ");
    if (isEmpty(stack))
    {
        printf("EMPTY\n");
    }
    else
    {
        for (int i = 0; i <= IDX_TOP(stack); i++)
        {
            printf("%d ", stack.buffer[i]);
        }
        printf("\n");
    }
}

int main(void)
{
    Stack s;
    ElType val;

    // Inisialisasi stack
    createStack(&s);
    if (isEmpty(s))
    {
        // Stack harus kosong setelah inisialisasi
        printf("Stack is empty\n");
    }

    // Menambahkan beberapa elemen ke stack
    push(&s, 5);
    push(&s, 3);
    push(&s, 8);
    push(&s, 3);

    // Cetak isi stack
    printStack(s);

    // Tampilkan elemen paling atas
    printf("Top element: %d\n", TOP(s));

    // Tampilkan jumlah elemen saat ini
    printf("Length: %d\n", length(s));

    // Menghapus elemen teratas dari stack (pop)
    pop(&s, &val);
    printf("Popped: %d\n", val);

    // Cetak kembali isi stack setelah pop
    printStack(s);

    // Cek apakah stack sudah penuh
    if (isFull(s))
    {
        printf("Stack is full\n");
    }
    else
    {
        printf("Stack is not full\n");
    }

    // Isi stack hingga penuh
    while (!isFull(s))
    {
        push(&s, 1);
    }
    printf("Filled the stack.\n");

    // Cek panjang dan status penuh setelah pengisian
    printf("Length after filling: %d\n", length(s));
    printf("Is full: %s\n", isFull(s) ? "true" : "false");

    return 0;
}