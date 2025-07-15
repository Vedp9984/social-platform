#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reply.h"

Reply *createReply(char *username, char *content)
{
  Reply *newReply = (Reply *)malloc(sizeof(Reply));

  newReply->username = (char *)malloc(sizeof(char)*200);

  strcpy(newReply->username, username);

  newReply->content = (char *)malloc(sizeof(char)*200);

  strcpy(newReply->content, content);

  newReply->next=NULL;
  
  return newReply;
}
