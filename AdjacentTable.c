#include <stdio.h>
#include <stdlib.h>

typedef char VertexType;
typedef int EdgeType;
#define MAXVEX 100
#define INFINITY 65535

typedef struct
{
	VertexType vexs[MAXVEX];      // 顶点表
	EdgeType arc[MAXVEX][MAXVEX]; // 邻接矩阵, 可看作边表
	int numVertexes, numEdges;    // 图中当前的顶点数和边数
}MGraph;

void CreateMGraph(MGraph *G)
{
	int i, j, k, w;
	printf("输入当前的顶点数和边数:\n");
	scanf("%d,%d", &G->numVertexes, &G->numEdges);

	for (i = 0; i < G->numVertexes; ++i)
	{
		scanf(&G->vexs[i]);
	}

	for (i = 0; i < G->numVertexes; ++i)
	{
		for (j = 0; j < G->numVertexes; ++j)
		{
			G->arc[i][j] = INFINITY; // 邻接矩阵初始化
		}
	}

	for (k = 0; k < G->numEdges; ++k)
	{
		printf("输入边(vi, vj)上的下标 i , 下标 j 和权 w:\n");
		scanf("%d,%d,%d", &i, &j, &w);
		G->arc[i][j] = w;
		G->arc[j][i] = G->arc[i][j]; // 因为是无向图, 矩阵对称
	}
}

int main()
{
	MGraph *G = new MGraph;

	CreateMGraph(G);

	delete G;

	return 0;
}
