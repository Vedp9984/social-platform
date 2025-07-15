#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "platform.h"
#include "post.h"
#include "comment.h"
#include "reply.h"
Platform *platform;
int flag = 0;
Platform *createPlatform()
{
    if (platform == NULL)
    {
        platform = (Platform *)malloc(sizeof(Platform));
        if (platform != NULL)
        {
            platform->posts = NULL;
            platform->lastViewedPost = NULL;
        }
    }
    return platform;
}


bool addPost(char *username, char *caption)
{

    Post *newPost = createPost(username, caption);
    if (newPost == NULL)
    {

        return false;
    }

    if (platform->posts == NULL)
    {
        platform->posts = newPost;
        platform->lastViewedPost = newPost;
        return true;
    }

    Post *p = platform->posts;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = newPost;
    // Set the lastViewedPost to the newly added post
    if (flag == 0)
        platform->lastViewedPost = newPost;
    return true;
}


int commentSize(Comment *head)
{
    int size = 0;
    Comment *current = head;

    while (current != NULL)
    {
        size++;
        current = current->next;
    }

    return size;
}

int postSize(Post *head)
{
    int size = 0;
    Post *current = head;

    // Traverse the linked list and count the nodes
    while (current != NULL)
    {
        size++;
        current = current->next;
    }

    return size;
}
bool deletePost(int n) {
    if (platform->posts == NULL) {
        return false;
    }
 
    //     if (n == 1) {
    //     Post* temp = platform->posts;
    //     platform->posts = platform->posts->next;
    //     free(temp);
    //     return true;
    // }
    if(n>postSize(platform->posts) || n<=0)
        return false;
    Post* current = platform->posts;
    int x=postSize(current);

    for (int i = 1; i < x - n; i++) {
        current = current->next;
    }

    if (current == NULL || current->next == NULL) {
        return false;
    }
    if (current->next == platform->lastViewedPost) {
        platform->lastViewedPost = current;
    }

    Post* temp = current->next;
    current->next = temp->next;
    free(temp);
    return true;
}

Post *viewPost(int n)
{
    Post *current = platform->posts;

    if (current == NULL)
    {
        return NULL;
    }
    if(n>postSize(current) || n<=0)
        return NULL;
    int x=postSize(current);
    for (int i = 0; i <x- n; i++)
    {
        // printf("%d\n",postSize(current));
        current = current->next;
    }
    platform->lastViewedPost = current;
    flag = 1;
    return current;
}

Post *nextPost()
{
    if (platform->lastViewedPost == NULL)
    {
        return NULL;
    }

    if (platform->lastViewedPost == platform->posts || platform->posts->next == NULL)
    {
        return platform->lastViewedPost;
    }
    Post *current = platform->posts;
    Post *nextPost = NULL;

    while (current->next != platform->lastViewedPost)
    {
        if (current->next != NULL)
        {
            current = current->next;
        }
        else
        {

            return NULL;
        }
    }

    nextPost = current;

    // Update lastViewedPost to the post before it
    platform->lastViewedPost = nextPost;

    return nextPost;
}

Post *currPost()
{
    if (platform->lastViewedPost == NULL || platform->posts == NULL)
    {
        return NULL;
    }
    return platform->lastViewedPost;
}

Post *previousPost()
{
    if (platform->posts == NULL)
    {
        return NULL;
    }
    if (platform->lastViewedPost->next == NULL)
    {
        return platform->lastViewedPost;
    }

    Post *current = platform->posts;
    while (current != platform->lastViewedPost)
    {
        current = current->next;
    }

    platform->lastViewedPost = current->next;

    return current->next;
}

bool addComment(char *username, char *content)
{
    if (platform->lastViewedPost == NULL)
    {
        return false;
    }

    Comment *newComment = createComment(username, content);
    if (newComment == NULL)
    {
        return false;
    }

    Comment *ptr = platform->lastViewedPost->comment;

    if (ptr == NULL)
    {
        platform->lastViewedPost->comment = newComment;
        return true;
    }

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = newComment;
    newComment->next = NULL;
    return true;
}

bool deleteComment(int n)
{
    if (platform->lastViewedPost == NULL || platform->lastViewedPost->comment == NULL)
    {

        return false;
    }
    Comment *current = platform->lastViewedPost->comment;
    int x=commentSize(current);
    if(n>x || n<=0)
        return false;

    for (int i = 1; i < x- n; i++)
    {
        current = current->next;
    }
    if(current->next == NULL && n==1)
    {
        free(current);
    }
    if (current->next == NULL)
    {
        return false;
    }
    Comment *temp = current->next;
    current->next = temp->next;
    free(temp);
    return true;
}

Comment *viewComments()
{

    if (platform->lastViewedPost == NULL)
    {
        return NULL;
    }
    return platform->lastViewedPost->comment;
}
bool addReply(char *username, char *content, int n)
{
}
bool deleteReply(int n, int m)
{
}
