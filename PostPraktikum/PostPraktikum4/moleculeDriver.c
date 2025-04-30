#include "molecule.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);

    Molecule molecules[n];
    for (int i = 0; i < n; ++i)
    {
        createMolecule(&molecules[i]);
    }

    char command[30];
    int idx1, idx2, idx_res, count;
    char symbol[MAX_SYMBOL_LEN];

    // TODO: Lengkapi main function
    bool isEnd = false;

    do
    {
        scanf("%s", command);
        if (strcmp(command, "END") == 0)
        {
            isEnd = true;
        }
        else if (strcmp(command, "ADD") == 0)
        {
            scanf("%d %s %d", &idx1, symbol, &count);
            if (idx1 >= 0 && idx1 < n && count > 0)
            {
                addAtom(&molecules[idx1], symbol, count);
            }
        }
        else if (strcmp(command, "PRINT") == 0)
        {
            scanf("%d", &idx1);
            if (idx1 >= 0 && idx1 < n)
            {
                printMoleculeFormula(&molecules[idx1]);
            }
        }
        else if (strcmp(command, "WEIGHT") == 0)
        {
            scanf("%d", &idx1);
            if (idx1 >= 0 && idx1 < n)
            {
                printf("%.3f\n", calculateMolecularWeight(&molecules[idx1]));
            }
        }
        else if (strcmp(command, "GET_COUNT") == 0)
        {
            scanf("%d %s", &idx1, symbol);
            if (idx1 >= 0 && idx1 < n)
            {
                printf("%d\n", getAtomCount(&molecules[idx1], symbol));
            }
        }
        else if (strcmp(command, "ARE_EQUAL") == 0)
        {
            scanf("%d %d", &idx1, &idx2);
            if (idx1 >= 0 && idx1 < n && idx2 >= 0 && idx2 < n)
            {
                printf("%s\n", areEqual(&molecules[idx1], &molecules[idx2]) ? "Ya" : "Tidak");
            }
        }
        else if (strcmp(command, "COMBINE") == 0)
        {
            scanf("%d %d %d", &idx_res, &idx1, &idx2);
            if (idx_res >= 0 && idx_res < n && idx1 >= 0 && idx1 < n && idx2 >= 0 && idx2 < n)
            {
                molecules[idx_res] = combineMolecules(&molecules[idx1], &molecules[idx2]);
            }
        }
        else if (strcmp(command, "CAN_SUBTRACT") == 0)
        {
            scanf("%d %d", &idx1, &idx2);
            if (idx1 >= 0 && idx1 < n && idx2 >= 0 && idx2 < n)
            {
                printf("%s\n", canSubtract(&molecules[idx1], &molecules[idx2]) ? "Ya" : "Tidak");
            }
        }
        else if (strcmp(command, "SUBTRACT") == 0)
        {
            scanf("%d %d %d", &idx_res, &idx1, &idx2);
            if (idx_res >= 0 && idx_res < n && idx1 >= 0 && idx1 < n && idx2 >= 0 && idx2 < n)
            {
                molecules[idx_res] = subtractMolecule(&molecules[idx1], &molecules[idx2]);
            }
        }
    } while (!isEnd);

    return 0;
}