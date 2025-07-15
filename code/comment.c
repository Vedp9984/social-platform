#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "comment.h"

Comment *createComment(char *username, char *content)
{
    Comment *newComment = (Comment *)malloc(sizeof(Comment));

    newComment->username = (char *)malloc(strlen(username) + 1);
    
    strcpy(newComment->username, username);

    newComment->content = (char *)malloc(sizeof(char)*200);
    
    strcpy(newComment->content, content);

    
     newComment->next=NULL;
    return newComment;
}
