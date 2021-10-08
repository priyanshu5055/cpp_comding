/*
    PRIYANSHU IS A PEACEFULL SOUL
*/
#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii> 
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ll long long
#define ss second
using namespace std;

int findMinVertex(int dist[],bool visited[],int n)
{
    int minVertex = -1;
    for(int i=1;i<=n;i++)
    {
        if(!visited[i]  && (minVertex == -1 || dist[i] < dist[minVertex] ))
        {
            minVertex = i;
        }
    }
    return minVertex;
}

void shortest_path(int numOfNode,int *arr,int s)
{
    int g[numOfNode+1][numOfNode+1];
    for(int i=0;i<numOfNode;i++)
    {
        for(int j=0;j<numOfNode;j++)
        {
            g[i+1][j+1] = *((arr+i*numOfNode) + j);
        }
    }
    int dist[numOfNode+1];
    bool visited[numOfNode+1];
    list <int> *path = new list<int>[numOfNode+1];
    
    for(int i=1;i<=numOfNode;i++)
    {
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    dist[s] = 0;
    path[s].push_back(s);
    for(int i=1;i<=numOfNode;i++)
    {
        int minVertex = findMinVertex(dist,visited,numOfNode);
        visited[minVertex] = true;
        for(int j=1;j<=numOfNode;j++)
        {
            if(g[minVertex][j] > 0 && !visited[j])
            {
                int distance = dist[minVertex] + g[minVertex][j];
                if(distance < dist[j])
                {
                    path[j].clear();
                    list <int>l = path[minVertex];
                    while(!l.empty())
                    {
                        int temp = l.front();
                        path[j].push_back(temp);
                        l.pop_front();
                    }
                    path[j].push_back(j);
                    dist[j] = distance;
                }
            }
        }
    }
    for(int i=1;i<=numOfNode;i++)
    {
        cout << i << "\t" << dist[i] << "\t" << s;
        path[i].pop_front();
        while(!path[i].empty())
        {
            cout << "->";
            cout << path[i].front();
            path[i].pop_front();
        }
        cout << endl;
    }    
    
}

int main() 
{
    int numOfNode,source;
    cin >> numOfNode;
    
    int g[numOfNode][numOfNode];
    
    for(int i=0;i<numOfNode;i++)
    {
        for(int j=0;j<numOfNode;j++)
        {
            cin >> g[i][j];
            if(i == j && g[i][j] != 0)
            {
                cout << "Weight of the edge " << i+1 << " <-> " << j+1 << " must be 0";
                exit(0);
            }
            if(i != j && g[i][j] == 0)
            {
                cout << "Weight of the edge " << i+1 << " <-> " << j+1 << " can not be 0";
                exit(0);
            }
            if(g[i][j] < -1)
            {
                cout << "Weight of the edge " << i+1 << " <-> " << j+1 << " can not be negative";
                exit(0);
            }
        }
    }
    cin >> source;
    shortest_path(numOfNode,(int *)g,source);
    return 0;
}
