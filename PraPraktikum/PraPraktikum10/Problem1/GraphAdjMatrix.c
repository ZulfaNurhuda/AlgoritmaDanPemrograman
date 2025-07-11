/**
 * --------------------------------------------------------------
 * | @file GraphAdjMatrix.c                                     |
 * --------------------------------------------------------------
 * | @details                                                   |
 * | Implementasi ADT Graph dengan representasi Adjacency       |
 * | Matrix sesuai header graphAdjMatrix.h                      |
 * --------------------------------------------------------------
 */

#include "GraphAdjMatrix.h"

void initializeGraph(Graph *graph, int numberOfVertices)
{
    if (numberOfVertices > 0 && numberOfVertices <= MAX_VERTICES)
    {
        // Set jumlah simpul (vertex) dari graph
        graph->numberOfVertices = numberOfVertices;

        // Inisialisasi seluruh elemen adjacency matrix menjadi 0 (tidak ada edge)
        for (int i = 0; i < numberOfVertices; i++)
        {
            for (int j = 0; j < numberOfVertices; j++)
            {
                graph->adjacencyMatrix[i][j] = 0;
            }
        }
    }
    else
    {
        // Jika jumlah vertex tidak valid, set jadi 0
        graph->numberOfVertices = 0;
    }
}

bool isValidVertex(Graph graph, int vertex)
{
    // Memastikan vertex dalam range 0 hingga numberOfVertices-1
    bool valid = false;
    if (vertex >= 0 && vertex < graph.numberOfVertices)
    {
        valid = true;
    }
    return valid;
}

void addEdge(Graph *graph, int sourceVertex, int destinationVertex)
{
    // Tambahkan edge jika kedua vertex valid
    if (isValidVertex(*graph, sourceVertex) && isValidVertex(*graph, destinationVertex))
    {
        // Set hubungan source -> destination
        graph->adjacencyMatrix[sourceVertex][destinationVertex] = 1;

        // Karena ini graf tak berarah, juga set destination -> source
        graph->adjacencyMatrix[destinationVertex][sourceVertex] = 1;
    }
}

void removeEdge(Graph *graph, int sourceVertex, int destinationVertex)
{
    // Hapus edge jika kedua vertex valid
    if (isValidVertex(*graph, sourceVertex) && isValidVertex(*graph, destinationVertex))
    {
        // Hapus hubungan source -> destination
        graph->adjacencyMatrix[sourceVertex][destinationVertex] = 0;

        // Karena graf tak berarah, juga hapus destination -> source
        graph->adjacencyMatrix[destinationVertex][sourceVertex] = 0;
    }
}

bool isAdjacent(Graph *graph, int sourceVertex, int destinationVertex)
{
    bool adjacent = false;

    // Cek apakah source dan destination valid
    if (isValidVertex(*graph, sourceVertex) && isValidVertex(*graph, destinationVertex))
    {
        // Jika ada nilai 1 pada posisi [i][j], maka bertetangga
        if (graph->adjacencyMatrix[sourceVertex][destinationVertex] == 1)
        {
            adjacent = true;
        }
    }

    return adjacent;
}