#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include<filesystem>
void list_files()
{
    char path[100], command[200];
    strcpy(command, "find ");
    printf("\nPlease enter the whole path of the directory to list its files:\n\n");
    fgets(path, sizeof(path), stdin);
    strtok(path, "\n");  // Remove the trailing newline character
    strcat(command, path);
    strcat(command," -maxdepth 1 -type f " );
    system(command);
}
void list_directories()
{
    char path[100], command[200];
    strcpy(command, "find ");
    printf("\nPlease enter the whole path of the directory to list its directories:\n\n");
    fgets(path, sizeof(path), stdin);
    strtok(path, "\n");  // Remove the trailing newline character
    strcat(command, path);
    strcat(command," -maxdepth 1 -type d" );
    system(command);
}

void list_files_and_directories()
{
    char path[100], command[200];
    strcpy(command, "ls ");
    printf("\nPlease enter the whole path of the directory to list its files and directories:\n\n");
    fgets(path, sizeof(path), stdin);
    strtok(path, "\n");  // Remove the trailing newline character
    strcat(command, path);
    system(command);
}

void change_permissions()
{
    char path[100], num[100], command[200];
    strcpy(command, "sudo chmod ");
    printf("\nPlease enter the number (r/w/x),(O/G/N):\n\n");
    fgets(num, sizeof(num), stdin);
    strtok(num, "\n");  
    strcat(command, num);

    printf("\nEnter the whole path of the file:\n\n");
    fgets(path, sizeof(path), stdin);
    strtok(path, "\n");  
    strcat(command, " ");
    strcat(command, path);
}

void make_directory()
{
    char path[100], command[200];
    strcpy(command, "mkdir ");
    printf("\nPlease enter the whole path of the directory you want to create:\n\n");
    fgets(path, sizeof(path), stdin);
    strtok(path, "\n"); 
    strcat(command, path);
    system(command);
}

void remove_directory()
{
    char path[100], command[200];
    strcpy(command, "rmdir ");
    printf("\nPlease enter the whole path of the directory you want to remove:\n\n");
    fgets(path, sizeof(path), stdin);
    strtok(path, "\n"); 
    strcat(command, path);
    system(command);
}

void make_file()
{
    char path[100], command[200];
    strcpy(command, "touch ");
    printf("\nPlease enter the whole path of the file you want to create:\n\n");
    fgets(path, sizeof(path), stdin);
    strtok(path, "\n");  
    strcat(command, path);
    system(command);
}

void remove_file()
{
    char path[100], command[200];
    strcpy(command, "rm ");
    printf("\nPlease enter the whole path of the file you want to remove:\n\n");
    fgets(path, sizeof(path), stdin);
    strtok(path, "\n");  
    strcat(command, path);
    system(command);
}

void create_symbolic_link_file()
{
    char path[100], dest[100], command[200];
    strcpy(command, "ln -s ");
    printf("\nPlease enter the whole path of the file you want to link:\n\n");
    fgets(path, sizeof(path), stdin);
    strtok(path, "\n");  
    strcat(command, path);
    printf("\nEnter the whole destination of the file:\n\n");
    fgets(dest, sizeof(dest), stdin);
    strtok(dest, "\n");  
    strcat(command, " ");
    strcat(command, dest);
    system(command);
}

int main(int argc, char *argv[])
{
    printf("\nWelcome to our file manager. Please choose what you want (from 1 to 8):\n\n");
    int choice;
    char t;

    while (choice != 10)
    {
        printf("\n   [1] List files and directories.\n");
        printf("   [2] List files.\n");
        printf("   [3] List directories.\n");
        printf("   [4] Change permissions of files.\n");
        printf("   [5] Make directories.\n");
        printf("   [6] Make files.\n");
        printf("   [7] Delete directories.\n");
        printf("   [8] Delete files.\n");
        printf("   [9] Create symbolic link files.\n");
        printf("   [10] Exit.\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        t = getchar(); // Consume newline character
        switch (choice)
        {
        
        case 1:
            list_files_and_directories();
            break;

        case 2:
            list_files();
            break;

        case 3:
            list_directories();
            break;
        case 4: 
            change_permissions();
            break;
        case 5:
            make_directory();
            break;
        case 6:
            make_file();
            break;

        case 7:
            remove_directory();
            break;

        case 8:
            remove_file();
            break;

        case 9:
            create_symbolic_link_file();
            break;

        case 10:
            exit(0);

        default:
            printf("\nPlease make sure your choice is valid and try again.\n\n");
        }
    }

    return 0;
}
