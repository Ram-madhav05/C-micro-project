#include <stdio.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

// Function declarations
void addStudent();
void viewStudents();
void searchStudent();
void countStudents();

int main() {
    int choice;

    do {
        printf("\n===== Student Record System =====\n");
        printf("1. Add Student\n");
        printf("2. View All Students\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Count Total Students\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline

        if (choice == 1) addStudent();
        else if (choice == 2) viewStudents();
        else if (choice == 3) searchStudent();
        else if (choice == 4) countStudents();
        else if (choice == 5) printf("Exiting...\n");
        else printf("Invalid choice! Try again.\n");

    } while (choice != 5);

    return 0;
}

void addStudent() {
    struct Student s;
    FILE *fp = fopen("students.txt", "ab");

    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Roll Number: ");
    scanf("%d", &s.roll);
    getchar();
    printf("Enter Name: ");
    fgets(s.name, sizeof(s.name), stdin);

    // remove newline
    int i = 0;
    while (s.name[i] != '\0') {
        if (s.name[i] == '\n') {
            s.name[i] = '\0';
            break;
        }
        i++;
    }

    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);
    printf("Student added successfully!\n");
}

void viewStudents() {
    struct Student s;
    FILE *fp = fopen("students.txt", "rb");

    if (fp == NULL) {
        printf("No records found.\n");
        return;
    }

    printf("\n--- Student Records ---\n");
    while (fread(&s, sizeof(s), 1, fp)) {
        printf("Roll: %d | Name: %s | Marks: %.2f\n", s.roll, s.name, s.marks);
    }

    fclose(fp);
}

void searchStudent() {
    int roll, found = 0;
    struct Student s;
    FILE *fp = fopen("students.txt", "rb");

    if (fp == NULL) {
        printf("No records found.\n");
        return;
    }

    printf("Enter Roll Number to search: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.roll == roll) {
            printf("Student Found:\nRoll: %d | Name: %s | Marks: %.2f\n", s.roll, s.name, s.marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with Roll No. %d not found.\n", roll);
    }

    fclose(fp);
}

void countStudents() {
    int count = 0;
    struct Student s;
    FILE *fp = fopen("students.txt", "rb");

    if (fp == NULL) {
        printf("No records found.\n");
        return;
    }

    while (fread(&s, sizeof(s), 1, fp)) {
        count++;
    }

    fclose(fp);
    printf("Total number of students: %d\n", count);
}
