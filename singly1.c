
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    struct node *next;
    int vertex;
}node;
 
node *G[20];   
//heads of linked list
int visited[20];
int n;
int a = 0;
 
int main()
{
    int i;

    int ii,vi,vj,no_of_edges;
    printf("Enter number of vertices:");
   
    scanf("%d",&n);
 
    //initialise G[] with a null
   
    for(ii=0;ii<n;ii++)
    {
        G[ii]=NULL;
        //read edges and insert them in G[]
       
        printf("Enter number of edges:");
           scanf("%d",&no_of_edges);
 
           for(ii=0;ii<no_of_edges;ii++)
        {
            printf("Enter an edge(u,v):");
            scanf("%d%d",&vi,&vj);
            insert(vi,vj);
        }
    }

    //initialised visited to 0
   
    for(i=0;i<n;i++)
        visited[i]=0;
 
    DFS(0);
    if (a != 1){
        printf("YES\n");
    }
}
int DFS(int i)
{
    node *p;
    
    //printf("\n%d",i);
    p=G[i];
    visited[i]=1;
    while(p!=NULL)
    {
       i=p->vertex;
       
       if(!visited[i]){
            DFS(i);

       }else{
            printf("NOT \n");
            a = 1;
            return 0;
       }
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