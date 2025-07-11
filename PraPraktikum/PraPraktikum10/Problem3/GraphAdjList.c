/*
 * Nama File: GraphAdjList.c
 * Deskripsi: Implementasi ADT Graph dengan representasi Adjacency List sesuai header GraphAdjList.h
 */
#include "GraphAdjList.h"

AddressNode createNode(int vertex)
{
    // Alokasi memori untuk node baru
    AddressNode newNode = (AddressNode)malloc(sizeof(Node));
    if (newNode != NULL)
    {
        newNode->vertex = vertex; // Set simpul tujuan
        newNode->next = NULL;     // Inisialisasi pointer berikutnya ke NULL
    }
    return newNode; // Kembalikan pointer ke node baru
}

Graph *createGraph(int numberOfVertices)
{
    // Alokasi memori untuk struktur graph
    Graph *newGraph = (Graph *)malloc(sizeof(Graph));

    if (newGraph != NULL)
    {
        newGraph->numberOfVertices = numberOfVertices;

        // Alokasi memori untuk array adjacency list
        newGraph->adjList = (AddressNode *)malloc(numberOfVertices * sizeof(AddressNode));

        if (newGraph->adjList == NULL)
        {
            // Gagal alokasi array adjacency list → bebaskan graph
            free(newGraph);
            newGraph = NULL;
        }
        else
        {
            // Inisialisasi setiap list ke NULL (kosong)
            for (int i = 0; i < numberOfVertices; i++)
            {
                newGraph->adjList[i] = NULL;
            }
        }
    }

    return newGraph; // Kembalikan pointer ke graph yang sudah dibuat
}

void addEdge(Graph *graph, int source, int destination)
{
    bool isValid = true;

    // Validasi input: pastikan pointer graph tidak NULL
    if (graph == NULL)
    {
        isValid = false;
    }
    // Pastikan indeks simpul berada dalam rentang yang valid
    else if (source >= graph->numberOfVertices || destination >= graph->numberOfVertices || source < 0 || destination < 0)
    {
        isValid = false;
    }

    if (isValid)
    {
        // Buat node baru untuk simpul tujuan (destination)
        AddressNode newNodeDest = createNode(destination);

        if (newNodeDest != NULL)
        {
            // Tambahkan ke akhir daftar adjacency list source
            if (graph->adjList[source] == NULL)
            {
                graph->adjList[source] = newNodeDest;
            }
            else
            {
                AddressNode temp = graph->adjList[source];
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = newNodeDest;
            }

            // Buat node baru untuk arah sebaliknya (karena graf tak berarah)
            AddressNode newNodeSrc = createNode(source);

            if (newNodeSrc != NULL)
            {
                // Tambahkan ke akhir daftar adjacency list destination
                if (graph->adjList[destination] == NULL)
                {
                    graph->adjList[destination] = newNodeSrc;
                }
                else
                {
                    AddressNode temp = graph->adjList[destination];
                    while (temp->next != NULL)
                    {
                        temp = temp->next;
                    }
                    temp->next = newNodeSrc;
                }
            }
            else
            {
                // Jika alokasi newNodeSrc gagal, batalkan newNodeDest
                printf("Penambahan edge gagal.\n");

                // Hapus newNodeDest dari adjacency list source
                if (graph->adjList[source] == newNodeDest)
                {
                    graph->adjList[source] = NULL;
                }
                else
                {
                    AddressNode temp = graph->adjList[source];
                    while (temp->next != newNodeDest)
                    {
                        temp = temp->next;
                    }
                    temp->next = NULL;
                }

                free(newNodeDest); // Dealokasi node tujuan
            }
        }
        else
        {
            // Gagal alokasi newNodeDest
            printf("Penambahan edge gagal.\n");
        }
    }
    else
    {
        // Input invalid
        printf("Penambahan edge gagal.\n");
    }
}

void freeGraph(Graph *graph)
{
    if (graph != NULL)
    {
        // Iterasi semua simpul
        for (int i = 0; i < graph->numberOfVertices; i++)
        {
            AddressNode current = graph->adjList[i];
            // Bebaskan seluruh node pada adjacency list simpul ke-i
            while (current != NULL)
            {
                AddressNode temp = current;
                current = current->next;
                free(temp);
            }
        }

        // Bebaskan array adjacency list
        free(graph->adjList);
        // Bebaskan struktur graph
        free(graph);
    }
}