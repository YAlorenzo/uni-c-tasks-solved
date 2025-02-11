#include <stdio.h>
#include <string.h>



/*
 * Function read_words_from_file() reads words from a file and stores them in a 2D array.
 *
 * It performs the following tasks:
 * 1. Reads words from the provided file, ignoring spaces and newlines.
 * 2. Copies each word into the words array, ensuring a maximum word length of 49 characters.
 * 3. Ensures the total number of words does not exceed 50.
 * 4. Returns the number of words successfully read.
 *
 * Example:
 * Input (file content): "hello world example file"
 * Output: ["hello", "world", "example", "file"]
 */



int read_words_from_file(char words[50][50], FILE *fr) {
    int i = 0; // Index for words array
    char word[50]; // Temporary storage for a word

    while (fscanf(fr, "%49s", word) == 1) { // Read words, ignoring spaces and newlines
        strncpy(words[i], word, 50); // Copy word into array
        words[i][49] = '\0'; // Ensure null termination
        i++;
        if (i >= 50) { // Limit number of words to 50
            printf("Array is full, skipping remaining words.\n");
            break;
        }
    }
    return i; // Return number of words read
}

/*
 * Function merge_files() merges words from two files into a third file.
 *
 * It performs the following tasks:
 * 1. Reads words from two input files.
 * 2. Alternates words from each file and writes them to an output file.
 * 3. Words from the first file are prefixed with '+', and from the second file with '-'.
 *
 * Output:
 * A file containing merged words from both input files in an alternating pattern.
 */

int merge_files() {
    FILE *fprvy = fopen("prvy.txt", "r");
    FILE *fdruhy = fopen("druhy.txt", "r");
    FILE *ftreti = fopen("treti.txt", "w");
    char words_prvy[50][50] = {0}; // Array for words from prvy.txt
    char words_druhy[50][50] = {0}; // Array for words from druhy.txt

    if (fprvy == NULL || fdruhy == NULL || ftreti == NULL) {
        printf("Error opening file(s)!\n");
        return 1;
    }

    // Read words from files
    int count_prvy = read_words_from_file(words_prvy, fprvy);
    int count_druhy = read_words_from_file(words_druhy, fdruhy);

    int i = 0, j = 0;

    // Alternate words and write to treti.txt
    while (i < count_prvy || j < count_druhy) {
        if (i < count_prvy) {
            fprintf(ftreti, "+%s ", words_prvy[i]);
            i++;
        }
        if (j < count_druhy) {
            fprintf(ftreti, "-%s ", words_druhy[j]);
            j++;
        }
    }

    // Close files
    fclose(fprvy);
    fclose(fdruhy);
    fclose(ftreti);

    printf("Words successfully merged into treti.txt.\n");
    return 0;
}

int main() {
    return merge_files();
}
