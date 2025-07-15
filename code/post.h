
#ifndef POST_H
#define POST_H
typedef struct Post {
    char* username;
    char* caption;
    struct Post*next;
    struct Comment*comment;
} Post;

Post* createPost(char* username, char* caption);
#endif

