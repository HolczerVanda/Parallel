#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Topic
{
    char* title;
    char* description;
    char* data;
    int numPosts;
} Topic;

Topic* createTopic(char* title, char* description)
{
    Topic* newTopic = (Topic*) malloc(sizeof(Topic));
    newTopic->title = (char*) malloc(sizeof(char) * (strlen(title) + 1));
    strcpy(newTopic->title, title);
    newTopic->description = (char*) malloc(sizeof(char) * (strlen(description) + 1));
    strcpy(newTopic->description, description);
    newTopic->data = "";
    newTopic->numPosts = 0;
    return newTopic;
}

void deleteTopic(Topic* topic)
{
    free(topic->title);
    free(topic->description);
    free(topic);
}

void addPost(Topic* topic)
{
    topic->numPosts++;
}

void printTopic(Topic* topic)
{
    printf("Title: %s\n", topic->title);
    printf("Description: %s\n", topic->description);
    printf("Data: %s\n", topic->data);
    printf("Number of posts: %d\n", topic->numPosts);
}

void publish(Topic* topic, char* data)
{
    topic->data = (char*) malloc(sizeof(char) * (strlen(data) + 1));
    strcpy(topic->data, data);
}


int main() {
    Topic* topic1 = createTopic("Topic I.", "First topic.");
    Topic* topic2 = createTopic("Topic II.", "Second topic.");

    addPost(topic1);
    addPost(topic1);
    addPost(topic2);

    printTopic(topic1);
    printTopic(topic2);

    publish(topic1, "Hello, world!");
    printTopic(topic1);
    
    deleteTopic(topic1);
    deleteTopic(topic2);

    return 0;
}
