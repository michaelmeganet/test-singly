
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    struct node *next;
    int vertex;
}node;



node *G[10000];   
//heads of linked list
int visited[10000];
int n;
int a = 0;
int readCount;
int i;
int xx;
int ii,vi,vj,no_of_edges;


void DFS(int);
 
int main()
{
    FILE *testFile;
    testFile = fopen("test2.txt", "r");
    
    //printf("Enter number of vertices:");
    //scanf("%d",&n);
    while(fscanf(testFile, "%d" , &xx) != EOF){ // scan total testing rounds
        for(readCount = 0 ; readCount < xx ; readCount++)
        {
            fscanf(testFile, "%d" , &n);        // scan each total vertices
            printf("this is n : %d\n", n);

            for(ii=0;ii<n;ii++)
            {   
                G[ii] = NULL;
                fscanf(testFile, "%d" , &no_of_edges);  //scan each no of edges
                printf("this is the no of edges : %d\n", no_of_edges);
                for(ii=0;ii<no_of_edges;ii++)
                {
                    fscanf(testFile, "%d%d" ,&vi,&vj);  // scan edges
                    printf("this is the vi and vj : %d %d\n", vi,vj);
                    insert(vi,vj);
                }
                
            }
            for(i=0;i<n;i++)
            {
                visited[i]=0;
            }
            DFS(0);
            

             //i have to reset the whole G back to NULL every time i finish a cycle , or else its gonna follow up
            for(i=0;i<n;i++)
            {
                ListDelete(G,i);
            }
            
        }


    }

    //initialised visited to 0

   
    }
/*{
    node *p;
    
    printf("%d\n",i);
    p=G[i];
    visited[i]=1;
    while(p!=NULL)
    {
       i=p->vertex;
       printf("this is i : %d\n", i);
       printf("this is visited : %d\n", visited[i] );
       if(!visited[i]){
            DFS(i);

       }else{
            printf("NOT \n");
            a = 1;
            return 0;
       }
        p=p->next;
    }
}*/
    void DFS(int i)
{
    node *p;
   
    printf("\n%d",i);
    printf("\n");
    p=G[i];
    visited[i]=1;
    while(p!=NULL)
    {
       i=p->vertex;
       
       if(!visited[i])
            DFS(i);
        p=p->next;
    }
}
 
 
int insert(int vi,int vj)
{
    node *p,*q;
    
    //acquire memory for the new node
    q=(node *)malloc(sizeof(node));
    q->vertex=vj;
    q->next=NULL;
 
    //insert the node in the linked list number vi
    if(G[vi]==NULL)
        G[vi]=q;
    else
    {
        //go to end of the linked list
        p=G[vi];
       
        while(p->next!=NULL)
            p=p->next;
        p->next=q;
    }
}

int ListDelete(node *listP, int value)
{
  node *currP, *prevP;

  /* For 1st node, indicate there is no previous. */
  prevP = NULL;

  /*
   * Visit each node, maintaining a pointer to
   * the previous node we just visited.
   */
  for (currP = listP ;currP != NULL;prevP = currP, currP = currP->next) {

    if (currP->vertex == value) {  /* Found it. */
      if (prevP == NULL) {
        /* Fix beginning pointer. */
        listP = currP->next;
      } else {
        /*
         * Fix previous node's next to
         * skip over the removed node.
         */
        prevP->next = currP->next;
      }

      /* Deallocate the node. */
      free(currP);

      /* Done searching. */
      return;
    }
  }
}
/*int delete(int num,struct node *final)
{

    node *tmp,*pre;
    tmp = final;
    while(tmp!=NULL)
    {
        if(tmp->vertex == num)
        {
            if(tmp==final)
            {
                final = tmp->next;
                free(tmp);
                return 1;
            }else{
                pre->next = tmp->next;
                free(tmp);
                return 1;
            }
        }else{
            pre = tmp;
            tmp = tmp->next;
        }
    }
    return 0;
}*/
