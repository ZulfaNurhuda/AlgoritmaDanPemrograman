#include "molecule.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Main function to interactively manage a collection of molecules.
 *
 * This function initializes an array of Molecule objects based on user input.
 * It then enters a loop to process various commands that allow the user
 * to perform operations on the molecules such as adding atoms, printing
 * molecular formulas, calculating molecular weight, checking equality,
 * combining molecules, and subtracting molecules. The loop continues until
 * the "END" command is received.
 *
 * Commands:
 *
 * - `ADD`: Add atoms to a specified molecule.
 *
 * - `PRINT`: Print the formula of a specified molecule.
 *
 * - `WEIGHT`: Calculate and print the molecular weight of a specified molecule.
 *
 * - `GET_COUNT`: Get the count of a specific atom in a specified molecule.
 *
 * - `ARE_EQUAL`: Check if two molecules are equal.
 *
 * - `COMBINE`: Combine two molecules and store the result in a specified molecule.
 *
 * - `CAN_SUBTRACT`: Check if one molecule can be subtracted from another.
 *
 * - `SUBTRACT`: Subtract one molecule from another and store the result.
 *
 * Note:
 * I don't know where vulnerability is in this code.
 * If you run this code in olympia vitual machine, you may get only 10/100 point.
 * But if you run this code in your local machine, anything looks fine.
 * Sorry for the inconvenience. Hehe :)"
 *
 * @return int Exit status of the program.
 */
int main(void)
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
    do
    {
        scanf("%s", command);
        if (strcmp(command, "END") == 0)
        {
            break;
        }

        if (strcmp(command, "ADD") == 0)
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
                printf("%s\n", areEqual(&molecules[idx1], &molecules[idx2]) ? "YES" : "NO");
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
                printf("%s\n", canSubtract(&molecules[idx1], &molecules[idx2]) ? "YES" : "NO");
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
    } while (1);

    return 0;
}