# test-singly-grapgh
Depth-first Search (DFS) on Graphs

result.txt is the output of ./cleandone.c

Strong-Connected.c is a C++ codes, look for it at the below link
http://www.geeksforgeeks.org/connectivity-in-a-directed-graph/

find a "Run on IDE" green button on the above page

or manually  copy paste the codes completely from this Strong-Connected.c
into http://code.geeksforgeeks.org/index.php

then you can run this web ide as C++ code

it will run ans test the 5 input in the test.txt is Strongly connected ot not

in analysis_result.txt you can find the singly test and Strong Connected test result

but take a look in Depth-first Search (DFS) on Graphs Part 1 - Algorithm

https://youtu.be/fI6X6IBkzcw

and 

Depth-first Search (DFS) on Graphs Part 2 - Implementation

https://youtu.be/uT1p5Eiw9CE

to ensure you are not mis understabd the meaning of DFS

-------------------------------------------------------------------
check this out http://www.cs.yale.edu/homes/aspnes/pinewiki/DepthFirstSearch.html

you will find the running time, clock will be a consideration of test forward , back and cross edges

look into this pdf file

=====================================================================================

http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.43.6948&rep=rep1&type=pdf


from page 2 

"If the same vertex is encountered along two dierent simple paths from the initial vertex, we
may conclude that the graph is not singly connected. Similarly, if we do not nd such a
case for any initial vertex, then the graph is singly connected. The question thus reduces
to determining whether or not there are any forward or cross arcs in any of the DFS trees."

mean if first do a DFS searh, filter out the visited node and reduce the number of time to search any forward and cross arcs.

so we can do a DFS first.

then take the remain list to do the  checking of forward arcs, back arcs and cross arcs

after filtered this, the remian will be call singly connected graph

you also can find the same concept on time related to forward, back and cross edges

in page 3 Algorithm for Determining Single Connectivity

and in page 4 

	If G has a chord, then G is not singly connected.
		Otherwise, compute the strongly connected components (SCC's) of G.
			Contract the SCC's and throw away loop arcs; let G be the resulting graph.
	If G has a multiple arc, then G is not strongly connected.
		Otherwise
			For every v 2 V (G
			) do
			Compute a depth rst search tree T rooted at v.
			If T has a forward or cross arc, G is not singly connected.
		If no T had a forward or cross arc, G is singly connected.

===============================================================================

the above all can be found on http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.43.6948&rep=rep1&type=pdf


final  --> al_DFS.c

using this algorithm DFS for final codes

compile it under linux

using Number of nodes must be = Number of Edges to detetmine singly

