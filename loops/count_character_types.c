
/*
 * Function countCharacterTypes() prompts the user to input a string of characters.
 * It performs the following tasks:
 * 1. Counts the number of lowercase letters.
 * 2. Counts the number of uppercase letters.
 * 3. Counts the number of digits.
 *
 * Output:
 * 1. The number of lowercase letters is printed.
 * 2. The number of uppercase letters is printed.
 * 3. The number of digits is printed.
*/



int count_characterc_types()
{
    int ch, lower = 0, upper = 0, num = 0;
    printf("Zadajte retazec: ");

    while ((ch = getchar()) != '\n') {
        if (ch >= 'a' && ch <= 'z') {
            lower += 1;
        }
        else if (ch >= 'A' && ch <= 'Z') {
            upper += 1;
        }
        else if (ch >= '0' && ch <= '9') {
            num += 1;
        }
    }


    printf("Male: %d\n", lower);
    printf("Velke: %d\n", upper);
    printf("Cisla: %d\n", num);
}

int main(){
    count_characterc_types();
}
