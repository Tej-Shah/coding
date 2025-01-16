#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASK_LENGTH 100
#define FILENAME "agenda.txt"

// Function to display menu
void displayMenu() {
    printf("\nAgenda Menu:\n");
    printf("1. Add task\n");
    printf("2. View tasks\n");
    printf("3. Delete task\n");
    printf("4. Exit\n");
}

// Function to add a task to the agenda
void addTask() {
    FILE *file = fopen(FILENAME, "a");  // Open file in append mode
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    
    char task[MAX_TASK_LENGTH];
    printf("Enter task description: ");
    getchar();  // Clear newline character left in the buffer
    fgets(task, MAX_TASK_LENGTH, stdin);
    
    // Remove trailing newline character if it exists
    task[strcspn(task, "\n")] = 0;
    
    fprintf(file, "%s\n", task);
    printf("Task added successfully!\n");
    
    fclose(file);
}

// Function to view all tasks
void viewTasks() {
    FILE *file = fopen(FILENAME, "r");  // Open file in read mode
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }
    
    char task[MAX_TASK_LENGTH];
    printf("\nYour tasks:\n");
    int taskCount = 1;
    while (fgets(task, MAX_TASK_LENGTH, file) != NULL) {
        printf("%d. %s", taskCount, task);
        taskCount++;
    }
    
    fclose(file);
}

// Function to delete a task (by task number)
void deleteTask() {
    FILE *file = fopen(FILENAME, "r");  // Open file in read mode
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    // Read all tasks into a temporary array
    char tasks[100][MAX_TASK_LENGTH];
    int taskCount = 0;
    while (fgets(tasks[taskCount], MAX_TASK_LENGTH, file) != NULL) {
        taskCount++;
    }
    
    fclose(file);

    // Display tasks and ask for a task number to delete
    if (taskCount == 0) {
        printf("No tasks to delete.\n");
        return;
    }

    printf("\nSelect a task number to delete (1 to %d): ", taskCount);
    int taskNumber;
    scanf("%d", &taskNumber);

    // Ensure the number is valid
    if (taskNumber < 1 || taskNumber > taskCount) {
        printf("Invalid task number.\n");
        return;
    }

    // Rewrite the tasks to the file excluding the deleted task
    file = fopen(FILENAME, "w");  // Open file in write mode (clears the file)
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < taskCount; i++) {
        if (i != taskNumber - 1) {  // Skip the task to delete
            fprintf(file, "%s", tasks[i]);
        }
    }

    printf("Task deleted successfully!\n");
    fclose(file);
}

int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                deleteTask();
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
