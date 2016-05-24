
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
void showG();
void nodes_visited();
void isSG(int);
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
            // all this to prevent obmitted unvisited vertice(s)
            //check the youtube video
            // Depth-first Search (DFS) on Graphs Part 1 - Algorithm
            //https://youtu.be/fI6X6IBkzcw
            //Depth-first Search (DFS) on Graphs Part 2 - Implementation
            //https://youtu.be/uT1p5Eiw9CE
            // you have to restart the DFS if in the Set G still have uvisited vertice(s)
            // or some time  the vertices is few seperated island
            for(i=0;i<n;i++)
            {
                if (visited[i]==0)
                  DFS(i);
                
            }
            //// end of the above prevent obmitted unvisited vertice(s)
			
			nodes_visited();
            isSG(no_of_edges);

            
        }
			//showG();
		             //i have to reset the whole G back to NULL every time i finish a cycle , or else its gonna follow up
            for(i=0;i<n;i++)
            {
                ListDelete(G,i);
            }
    }
    
    

    //initialised visited to 0

   
   
 }
/*
for each vertex u in V[G]
        do color[u] ← WHITE
                π[u] ← NIL
     time ← 0
     for each vertex u in V[G]
        do if color[u] ← WHITE
                then DFS-Visit(u)   
*/

    void isSG(int no_of_edges){
    	int i;
    	int j;;
    	i = 0;
    	j = 0;
    	for(i=0;i<n;i++)
            {
                if (visited[i]==1){
                  j++;
                }
                
            }
        if( j < no_of_edges) {
        	printf("NO\n"); 
        	printf("\n" ); 
        }else{
        	printf("YES\n"); 
        	printf("\n" ); 
        }

    }

    void nodes_visited(){
    	int i;
    	int j;
    	i = 0;
    	j = 0;
    	for(i=0;i<n;i++)
            {
                if (visited[i]==1){
                  j++;
                }
                
            }
         printf("number of nodes visited :  %d\n", j); 

    }


    void showG()
    {
    	node *p;
    	while(p!=NULL)
    	{
    		i=p->vertex;
    		printf("\n%d",i);
    		//printf("\n");
    		p=p->next;
    	}



    }

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
