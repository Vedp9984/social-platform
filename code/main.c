
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "platform.h"
extern Platform *platform;
// platform at the top of the so be ready for-->>>>
int main()
{
     int x = 1;
     while (x == 1)
     {
          char s[105];
          scanf("%s", s);

          if (strcmp(s, "add_post") == 0)
          {
               char username[100];
               char caption[200];
               scanf("%s", username);
               scanf("%[^\n]c", caption);
               getchar();
               addPost(username, caption);
          }
          else if (strcmp(s, "create_platform") == 0)
          {

               platform = createPlatform();
          }
          else if (strcmp(s, "delete_post") == 0)
          {
               int n;
               scanf("%d", &n);
               deletePost(n);
          }
          else if (strcmp(s, "current_post") == 0)
          {

               Post *p = currPost();
               if (p != NULL)
               {
                    printf("%s:%s", p->username, p->caption);
               }
               else
               {
                    printf("p is null\n");
               }
          }
          else if (strcmp(s, "view_post") == 0)
          {
               int n;
               scanf("%d", &n);
               Post *p = viewPost(n);
               if(p==NULL)
                    printf("Error\n");
               else
               printf("%s :%s\n", p->username, p->caption);
          }
          else if (strcmp(s, "next_post") == 0)
          {

               Post *p = nextPost();
                if (p != NULL)
                {
                    printf("%s %s\n", p->username, p->caption);
                }
                 else
               {
                    printf("next_post is null\n");
               }
          }
          else if (strcmp(s, "previous_post") == 0)
          {

               Post *p = previousPost();
               if (p != NULL)
               {
                    printf("%s %s\n", p->username, p->caption);
               }
               else
               {
                    printf("p is NULL");
               }
          }
          else if (strcmp(s, "add_comment") == 0)
          {
               char username[100];
               char content[200];
               scanf("%s ", username);
               scanf("%[^\n]c", content);
               getchar();
               addComment(username, content);
          }
          else if (strcmp(s, "delete_comment") == 0)
          {
               int n;
               scanf("%d", &n);
               deleteComment(n);
          }
          else if (strcmp(s, "view_comments") == 0)
          {
               Comment *p = viewComments();
               while (p != NULL)
               {
                    printf("%s:%s\n", p->username, p->content);
                    p = p->next;
               }
          }
          else if (strcmp(s, "add_reply") == 0)
          {
               char username[100];
               char content[200];
               scanf("%s", username);
               scanf("%s", content);
               int n;
               scanf("%d", &n);
          }
          else if (strcmp(s, "delete_reply") == 0)
          {
               int n, m;
               scanf("%d %d", &n, &m);
          }
        else if (strcmp(s, "exit") == 0)
       {
              x = 0;
      }
}
}

