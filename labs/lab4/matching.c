/****************************************************/
/* matching.c                                       */ 
/* Andreea Muresan                                  */
/* SID: 1498868                                     */
/* Description: This program takes in a graph G(V,E)*/
/* matrix and the number of vertices it has and     */
/* outputs a maximal matching of its edges.         */
/****************************************************/

#include <stdio.h>
#include <stdlib.h>

// vert : INT of vertices in matrix
// a : ARRAY of matrix, SIZE(vert x vert)
// edges : ARRAY of all edges in a SIZE(vert x 2)
// edge_count : INT of edges total
// flag : ARRAY that tracks which vertices are used for edges, SIZE(vert)
// ans : ARRAY of the answers, SIZE(vert/2 x 2) - can't be more than vert/2 maximal edges

int main(void) {

	int vert;
	printf("Enter the number of verticies: ");
        scanf("%d", &vert);

	int edges[vert][2]; 
	int a[vert][vert];
	int* flag;
	flag = (int*) calloc(vert + 1, sizeof(int)); // make array of zeros to track vertices with edges

	printf("Enter the matrix: \n");

	// READ INPUT
	for (int i = 0; i < vert; i++) {
		for (int j = 0; j < vert; j++){
			scanf("%d", &a[i][j]);
		}
	}
	// FIND 1s IN MATRIX
	int col = 1;
	int row = 0;
	for (int i = 0; i < vert; i++) {
		for (int j = col; j < vert; j++) {
			if (a[i][j] == 1) {
				edges[row][0] = i + 1;
				edges[row][1] = j + 1;
				row++;
				break;
			}
		}
		col++;
	}
	// FIND DISTINCT VERTICIES
	int edge_count = 0;
	int ans[vert/2][2];
	int insert = 0; // keep track of where to insert answer into ans array
	for (int i = 0; i < row; i++) {
		int first = edges[i][0];
		int second = edges[i][1];
		if (flag[first] == 0 && flag[second] == 0) {
			flag[first] = 1;
			flag[second] = 1;
			ans[insert][0] = first;
			ans[insert][1] = second;
			insert++;
			edge_count++;	
	
		}
	}
	// PRINT EDGES
	printf("%d\n", edge_count);
	for (int i = 0; i < edge_count; i++) {  
		printf("%d %d\n", ans[i][0], ans[i][1]);
	}
	return 0;
}







