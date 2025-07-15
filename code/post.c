#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "post.h"

Post *createPost(char *username, char *caption)
{


    Post *newPost = (Post *)malloc(sizeof(Post));

    newPost->username = (char *)malloc(sizeof(char)*200);

    strcpy(newPost->username, username);

    newPost->caption = (char *)malloc(sizeof(char)*200);
    strcpy(newPost->caption, caption);
     newPost->next=NULL;
    
    return newPost;
}
