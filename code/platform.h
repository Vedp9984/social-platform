#ifndef PLATFORM_H
#define PLATFORM_H
#include<stdbool.h>
#include "post.h"
#include "comment.h"
#include "reply.h"

typedef struct Platform {    
    Post* posts;
    Post* lastViewedPost;
} Platform;
Platform *createPlatform();
bool addPost(char* username, char* caption);

int commentSize(Comment*head);
int postSize(Post*head);
bool deletePost(int n);
Post* nextPost();
Post* viewPost(int n);
Comment* viewComments();
Post* currPost();
Post* previousPost();
Post* currPost();
bool addComment(char* username, char* content);
bool deleteComment(int n);
Comment* viewComments();
bool addReply(char* username,char* content,int n);
bool deleteReply(int n ,int m);



#endif
