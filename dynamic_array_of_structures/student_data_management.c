#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Function loadStudents() reads student data from a file and stores it in an array of structures.
 * It performs the following tasks:
 * 1. Reads the number of students from the file.
 * 2. Dynamically allocates memory for an array of structures to store student data.
 * 3. Reads the name, year, and GPA of each student.
 *
 * Output:
 * 1. A pointer to an array of STUDENT structures containing student data.
 *
 * Example:
 * Input:
 * 5
 * Ivan Novak 3 3.5
 * Anna Kralova 2 4.0
 * Marek Horvath 3 4.5
 * Peter Mlynar 1 3.7
 * Jana Kucerova 2 4.3
 * Output:
 * Array of student structures with the corresponding data.
 */
STUDENT *loadStudents(char *file, int *count){
    char line[100];
    FILE *fr = fopen(file, "r");
    fscanf(fr, "%d", count); // Read the number of students
    if (*count < 1) return NULL;

    STUDENT *students = (STUDENT *)malloc(*count * sizeof(STUDENT)); // Dynamically allocate memory for the student array

    if (students == NULL) {
        printf("Error: failed to allocate memory.\n");
        fclose(fr);
        return NULL;
    }

    // Read student data
    for (int i = 0; i < *count; i++) {
        fgets(students[i].name, sizeof(students[i].name), fr); // Read the name
        students[i].name[strlen(students[i].name)-1] = '\0'; // Remove the newline character
        fscanf(fr, "%d\n", &students[i].year); // Read the year
        fscanf(fr, "%f\n", &students[i].gpa); // Read the GPA
    }

    fclose(fr);
    return students;
}

/*
 * Function printStudents() prints the student data from an array of structures.
 * It performs the following tasks:
 * 1. Iterates over the array of students.
 * 2. Prints the name, year, and GPA of each student.
 *
 * Output:
 * 1. A list of students in the format:
 *    "Name; Year; GPA;"
 *
 * Example:
 * Input:
 * Ivan Novak; 3; 3.5;
 * Anna Kralova; 2; 4.0;
 * Marek Horvath; 3; 4.5;
 * Output:
 * Ivan Novak; 3; 3.5;
 * Anna Kralova; 2; 4.0;
 * Marek Horvath; 3; 4.5;
 */
void printStudents(STUDENT *students, int count){
    for (int i = 0; i < count; i++){ // Iterate through all students
        printf("%s; %d; %.1f;\n", students[i].name, students[i].year, students[i].gpa); // Print student details
    }
}

/*
 * Function findTopStudent() finds the student with the highest GPA in a given year.
 * It performs the following tasks:
 * 1. Iterates over the array of students.
 * 2. For each student in the specified year, compares their GPA to find the highest.
 *
 * Output:
 * 1. A pointer to the STUDENT structure with the highest GPA in the specified year.
 *    If no student is found in the given year, it returns NULL.
 *
 * Example:
 * Input: 3 (year)
 * Students data:
 * Ivan Novak; 3; 3.5;
 * Marek Horvath; 3; 4.5;
 * Output:
 * The student with the highest GPA in year 3: Marek Horvath
 */
STUDENT *findTopStudent(STUDENT *students, int count, int year){
    float maxGpa = 0;
    STUDENT *topStudent = NULL;

    for (int i = 0; i < count; i++){ // Iterate through all students
        if(year == students[i].year){ // Check if the student is in the specified year
            if(students[i].gpa > maxGpa){ // Check if the GPA is higher than the current maximum
                maxGpa = students[i].gpa;
                topStudent = &students[i];
            }
        }
    }

    return topStudent; // Return the student with the highest GPA
}

/*
 * Main function that loads student data, prints it, and finds the best student in a given year.
 * It performs the following tasks:
 * 1. Calls loadStudents() to load student data from a file.
 * 2. Calls printStudents() to print the student data.
 * 3. Calls findTopStudent() to find the best student in year 3.
 * 4. Prints the name of the best student.
 *
 * Output:
 * 1. Prints all student data.
 * 2. Prints the best student for a given year.
 *
 * Example:
 * Input:
 * File data:
 * 5
 * Ivan Novak 3 3.5
 * Anna Kralova 2 4.0
 * Marek Horvath 3 4.5
 * Peter Mlynar 1 3.7
 * Jana Kucerova 2 4.3
 * Output:
 * Ivan Novak; 3; 3.5;
 * Anna Kralova; 2; 4.0;
 * Marek Horvath; 3; 4.5;
 * Peter Mlynar; 1; 3.7;
 * Jana Kucerova; 2; 4.3;
 * The best student in year 3 is Marek Horvath.
 */
int main(){
    STUDENT *students, *topStudent;
    int count;
    students = loadStudents("students.txt", &count);

    if (students == NULL) {
        printf("Failed to load student data.\n");
        return -1;
    }

    printStudents(students, count); // Print all students' data

    topStudent = findTopStudent(students, count, 3); // Find the top student in year 3

    if (topStudent == NULL) {
        printf("No student found in the given year.\n");
        return -2;
    }

    // Print the name of the best student
    printf("The best student in year 3 is %s", topStudent->name);

    return 0;
}
