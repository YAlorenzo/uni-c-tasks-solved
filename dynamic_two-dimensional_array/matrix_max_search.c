#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

/*
 * Function create() dynamically allocates memory for a 2D array.
 *
 * Parameters:
 *   - riadky: number of rows in the matrix.
 *   - stlpce: number of columns in the matrix.
 *
 * Returns:
 *   - A pointer to the allocated 2D array.
 *
 * This function allocates memory for the matrix with the specified number of rows and columns.
 */
int **create(int riadky, int stlpce)
{
    int **p, i;
    p = (int **) malloc(riadky * sizeof(int *));
    for(i = 0; i < riadky; i++){
        p[i] = (int *) malloc(stlpce * sizeof(int));
    }
    return p;
}

/*
 * Function AlokujNapln() reads matrix dimensions and values from a file
 * and allocates memory for the matrix.
 *
 * Parameters:
 *   - riadky: pointer to store the number of rows.
 *   - stlpce: pointer to store the number of columns.
 *
 * Returns:
 *   - A pointer to the dynamically allocated and populated matrix.
 *   - NULL if file reading fails.
 *
 * This function reads the matrix dimensions and the matrix values from a file,
 * dynamically allocates memory, and fills the matrix with data.
 */
int **AlokujNapln(int *riadky, int *stlpce){
    int rows = 0;
    int columns = 0;
    FILE *fr = fopen("vstup_matica9.txt", "r");

    if(fr == NULL){
        return NULL;
    }

    fscanf(fr, "%d %d", riadky, stlpce);

    int **pole = create(*riadky, *stlpce);
    if (pole == NULL) {
        fclose(fr);
        return NULL;
    }

    for (int i = 0; i < *riadky; i++){
        for (int j = 0; j < *stlpce; j++){
            fscanf(fr, "%d", &pole[i][j]);
        }
    }

    fclose(fr);
    return pole;
}

/*
 * Function Uvolni() frees the allocated memory for the 2D array.
 *
 * Parameters:
 *   - pole: pointer to the 2D array.
 *   - riadky: number of rows in the matrix.
 *
 * This function releases the dynamically allocated memory for the matrix.
 */
void Uvolni(int **pole, int riadky){
    for (int i = 0; i < riadky; i++){
        free(pole[i]); // frees memory for each row
    }

    free(pole); // frees memory for the array of pointers
}

/*
 * Function Vypis() prints the contents of the 2D array to the console.
 *
 * Parameters:
 *   - pole: pointer to the 2D array.
 *   - riadky: number of rows in the matrix.
 *   - stlpce: number of columns in the matrix.
 *
 * This function prints the entire matrix in a readable format.
 */
void Vypis(int **pole, int riadky, int stlpce){
    for (int i = 0; i < riadky; i++){
        for (int j = 0; j < stlpce; j++){
            printf("%5d", pole[i][j]);
        }
        printf("\n");
    }
}

/*
 * Function NajdiMax() finds the maximum value in the matrix and its position.
 *
 * Parameters:
 *   - pole: pointer to the 2D array.
 *   - riadky: number of rows in the matrix.
 *   - stlpce: number of columns in the matrix.
 *   - max_riadok: pointer to store the row of the maximum value.
 *   - max_stlpec: pointer to store the column of the maximum value.
 *
 * Returns:
 *   - The maximum value in the matrix.
 *
 * This function iterates through the matrix to find the maximum value and its position.
 */
int NajdiMax(int **pole, int riadky, int stlpce, int *max_riadok, int *max_stlpec){
    *max_riadok = 0;
    *max_stlpec = 0;
    int max = INT_MIN;
    for(int i = 0; i < riadky; i++){
        for (int j = 0; j < stlpce; j++){
            if (pole[i][j] > max){
                max = pole[i][j];
                *max_riadok = i;
                *max_stlpec = j;
            }
        }
    }
    return max;
}

/*
 * Main function where the program starts.
 *
 * The program performs the following tasks:
 * 1. Reads a matrix from a file.
 * 2. Prints the matrix.
 * 3. Finds the maximum value in the matrix and its position.
 * 4. Prints the maximum value and its position.
 * 5. Frees allocated memory.
 *
 * Returns:
 *   - 0 if the program runs successfully.
 *   - 1 if there is an error in reading the matrix.
 */
int main (){
    int **pole;
    int riadky, stlpce, max, max_riadok, max_stlpec;

    pole = AlokujNapln(&riadky, &stlpce);
    if (pole == NULL) {
        printf("Pole sa nepodarilo naplnit");
        return 1;
    }

    Vypis(pole, riadky, stlpce);
    max = NajdiMax(pole, riadky, stlpce, &max_riadok, &max_stlpec);
    printf("Maximum pola [%d] sa naslo na suradnici [%d, %d]", max, max_riadok, max_stlpec);

    Uvolni(pole, riadky);

    return 0;
}
