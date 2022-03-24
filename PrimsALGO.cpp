int getMinVertex(bool * visited, int * weight , int n)
{
    int min =-1;

    for(int i =0; i<n; i++)
    {
        if(!visited[i] && ( min ==-1    || weight[i]<weight[min] ))
        {
            min =i;
        }
    }


    return min;
}

void prims(int ** edges, int n ){
    bool *visited = new bool[n];
    int *parent = new int[n];
    int *weight = new int[n];
    
    
    for(int i =0; i<n; i++)
    {
        weight[i]= INT_MAX;
        visited[i]= false;
    }
    parent[0] = -1;
    weight[0]= 0;
    
    
    for(int i =0; i<n-1; i++)
    {
        int minvertex = getMinVertex(visited, weight,n);
        visited[minvertex] = true;
        
        
        for(int j =0; j<n; j++)
        {
            if(!visited[j] and edges[minvertex][j]!=0   and weight[j]>edges[minvertex][j])
            {
                weight[j]= edges[minvertex][j];
                
                parent[j]=minvertex;
            
            }
        }
    }
    
    
    for (int i = 1; i < n; i++)
	{
		if (parent[i] < i)
		{
			cout << parent[i] << " " << i <<" "<< weight[i]<<endl;
		}
		else
		{
			cout << i << " " << parent[i] << " " << weight[i] << endl;
		}
	}

}

int main()
{
	int n, e;
	cin >> n >> e;
	int** edges = new int* [n];
	for (int i = 0; i < n; i++)
	{
		edges[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			edges[i][j] = 0;
		}
	}
	for (int i = 0; i < e; i++)
	{
		int f, s, weight;
		cin >> f >> s >> weight;
		edges[f][s] = weight;
		edges[s][f] = weight;
	}
	prims(edges, n);
	for (int i = 0; i < n; i++)
	{
		delete[]edges[i];
	}
	delete[]edges;
}