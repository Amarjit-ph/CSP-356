#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > graph;
vector<int> moves;//(101, 100);
vector<bool> visit;//(101, false);
queue<int> fifo;

void bfs()
{
    while(!fifo.empty())
    {
        int a = fifo.front();
        fifo.pop();
        for(int i = 0; i < graph[a].size(); i++)
        {
            int b = graph[a][i];
            if(!visit[b])
            {
                visit[b] = true;
                moves[b] = min(moves[b], moves[a] + 1);
                fifo.push(b);
            }
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        //we could have initialized the vectors globally since we already know the size, but since we are running multiple test cases, we want them to be cleaned each time
        graph = vector<vector<int> > (101);
        moves = vector<int> (101, 100);
        visit = vector<bool> (101, false);
        //initialize graph assuming no ladders or snakes
        for(int i = 1; i <= 100; i++)
        {
            for(int j = 1; j <= 6 && i + j <= 100; j++)
            {
                graph[i].push_back(i+j);
            }
        }

        int l;
        scanf("%d", &l);
        int u, v;
        //make modifications for ladders
        for(int i = 0; i < l; i++)
        {
            scanf("%d %d", &u, &v);
            int j = u - 6;
            if(j < 1) //as j can be less than 1 for initial values
                j = 1;

            for(; j < u; j++)
            {
                for(int k = 0; k < graph[j].size(); k++)
                {
                    if(graph[j][k] == u)
                    {
                        graph[j][k] = v;
                        break;
                    }
                }
            }
        }

        int s;
        scanf("%d", &s);
        //make modifications for snakes
        for(int i = 0; i < s; i++)
        {
            scanf("%d %d", &u, &v);
            int j = u - 6;
            if(j < 1) //as j can be less than 1 for initial values
                j = 1;

            for(; j < u; j++)
            {
                for(int k = 0; k < graph[j].size(); k++)
                {
                    if(graph[j][k] == u)
                    {
                        graph[j][k] = v;
                        break;
                    }
                }
            }
        }

        //now graph is set, use bfs to find shortest path
        fifo.push(1); //since we use 1 indexing and game always start from 1
        visit[1] = true;
        moves[1] = 0;
        bfs();

        if(moves[100] > 17)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n", moves[100]);
        }
    }
    return 0;
}
