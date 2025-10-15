

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define URL_SIZE 100

typedef struct Node {
    char url[URL_SIZE];
    struct Node* prev;
    struct Node* next;
} Node;

Node* current = NULL;

Node* createNode(char* url) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->url, url);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void visitPage(char* url) {
    Node* newPage = createNode(url);
    if (current != NULL) {
        Node* temp = current->next;
        while (temp != NULL) {
            Node* toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
        current->next = newPage;
        newPage->prev = current;
    }
    current = newPage;
    printf("Visited: %s\n", current->url);
}

void goBack() {
    if (current == NULL || current->prev == NULL) {
        printf("No previous page.\n");
        return;
    }
    current = current->prev;
    printf("Went back to: %s\n", current->url);
}

void goForward() {
    if (current == NULL || current->next == NULL) {
        printf("No forward page.\n");
        return;
    }
    current = current->next;
    printf("Went forward to: %s\n", current->url);
}

void showCurrentPage() {
    if (current == NULL) {
        printf("No page visited yet.\n");
    } else {
        printf("Current page: %s\n", current->url);
    }
}

int main() {
    int choice;
    char url[URL_SIZE];

    while (1) {
        printf("\n=== Browser Menu ===\n");
        printf("1. Visit Page\n");
        printf("2. Back\n");
        printf("3. Forward\n");
        printf("4. Show Current Page\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter URL: ");
                scanf("%s", url);
                visitPage(url);
                break;
            case 2:
                goBack();
                break;
            case 3:
                goForward();
                break;
            case 4:
                showCurrentPage();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
//https://share.google/AwqrrgW3LJKDJai72
//https://share.google/A0bhZqxQxwaZV0tUq

	


	
