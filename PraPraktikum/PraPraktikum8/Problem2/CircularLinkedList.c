/**
 * --------------------------------------------------------------
 * | @file CircularLinkedList.c                                 |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Implementasi ADT Circular Linked List sesuai file header   |
 * | CircularLinkedList.h                                       |
 * --------------------------------------------------------------
 */

#include "CircularLinkedList.h"

Address createNode(InfoType value)
{
    Address newNode = (Address)malloc(sizeof(Node)); // Alokasi node baru
    if (newNode != NULL)
    {
        newNode->data = value; // Set nilai data
        newNode->next = NULL;  // Pointer awal NULL
    }
    return newNode; // Kembalikan alamat node baru
}

bool isEmpty(Address last)
{
    return (last == NULL); // List kosong jika tidak ada node terakhir
}

bool insertAtBeginning(Address *last, InfoType newValue)
{
    bool success = false;
    Address newNode = createNode(newValue); // Buat node baru
    if (newNode != NULL)
    {
        if (isEmpty(*last))
        {
            *last = newNode;
            (*last)->next = *last; // Circular: node menunjuk ke dirinya sendiri
        }
        else
        {
            newNode->next = (*last)->next; // newNode menunjuk ke elemen pertama lama
            (*last)->next = newNode;       // last->next menunjuk ke newNode (sebagai elemen baru pertama)
        }
        success = true;
    }
    return success;
}

bool insertAtEnd(Address *last, InfoType newValue)
{
    bool success = false;
    Address newNode = createNode(newValue);
    if (newNode != NULL)
    {
        if (isEmpty(*last))
        {
            *last = newNode;
            (*last)->next = *last;
        }
        else
        {
            newNode->next = (*last)->next; // newNode menunjuk ke head
            (*last)->next = newNode;       // last menunjuk ke newNode
            *last = newNode;               // last diperbarui ke node baru
        }
        success = true;
    }
    return success;
}

void deleteFromBeginning(Address *last)
{
    if (!isEmpty(*last))
    {
        Address firstNode = (*last)->next; // Ambil elemen pertama
        if (firstNode == *last)
        {
            *last = NULL; // Hanya 1 elemen
        }
        else
        {
            (*last)->next = firstNode->next; // last->next lompat ke node kedua
        }
        free(firstNode); // Bebaskan memori node
    }
}

void deleteFromEnd(Address *last)
{
    if (!isEmpty(*last))
    {
        Address current = (*last)->next; // Mulai dari head
        Address nodeToDelete = *last;    // Simpan node yang akan dihapus

        if (current == *last)
        {
            *last = NULL; // 1 elemen
        }
        else
        {
            // Cari node sebelum last
            while (current->next != *last)
            {
                current = current->next;
            }
            current->next = (*last)->next; // Node sebelumnya menunjuk ke head
            *last = current;               // Perbarui last
        }
        free(nodeToDelete);
    }
}

void displayList(Address last)
{
    if (isEmpty(last))
    {
        printf("KOSONG\n");
    }
    else
    {
        Address current = last->next; // Mulai dari head
        do
        {
            printf("%d", current->data);
            current = current->next;
            if (current != last->next)
            {
                printf(" -> "); // Cetak panah kecuali elemen terakhir
            }
        } while (current != last->next); // Berhenti saat kembali ke head
        printf("\n");
    }
}

void deleteAllNodes(Address *last)
{
    while (!isEmpty(*last))
    {
        deleteFromBeginning(last); // Hapus satu-satu dari depan
    }
}

Address searchNode(Address last, InfoType queryValue)
{
    Address result = NULL;
    if (!isEmpty(last))
    {
        Address current = last->next; // Mulai dari head
        do
        {
            if (current->data == queryValue)
            {
                result = current;
                break;
            }
            current = current->next;
        } while (current != last->next);
    }
    return result;
}

bool insertAfter(Address *last, InfoType queryValue, InfoType newValue)
{
    bool success = false;
    if (!isEmpty(*last))
    {
        Address precNode = searchNode(*last, queryValue); // Cari node acuan
        if (precNode != NULL)
        {
            Address newNode = createNode(newValue);
            if (newNode != NULL)
            {
                newNode->next = precNode->next;
                precNode->next = newNode;
                if (precNode == *last)
                {
                    *last = newNode; // Perbarui last jika disisipkan setelah last
                }
                success = true;
            }
        }
    }
    return success;
}

void deleteNodeWithValue(Address *last, InfoType valueToDelete)
{
    if (!isEmpty(*last))
    {
        Address current = (*last)->next; // Mulai dari head
        Address prev = *last;            // Mulai dari last
        bool found = false;

        do
        {
            if (current->data == valueToDelete)
            {
                found = true;
                break;
            }
            prev = current;
            current = current->next;
        } while (current != (*last)->next);

        if (found)
        {
            if (current == prev)
            {
                *last = NULL; // Hanya 1 elemen
            }
            else if (current == (*last)->next)
            {
                // Hapus head
                prev->next = current->next;
            }
            else if (current == *last)
            {
                // Hapus tail
                prev->next = current->next;
                *last = prev;
            }
            else
            {
                // Hapus node tengah
                prev->next = current->next;
            }
            free(current);
        }
    }
}