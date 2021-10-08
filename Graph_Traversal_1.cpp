/*
    PRIYANSHU IS A PEACEFULL SOUL
*/
#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ll long long
#define ss second
using namespace std;

bool vis[20];
vi adj[20];
void dfs(int node)
{
    vis[node] = 1;
    cout << node << " ";

    vi::iterator it;
    for (it = adj[node].begin(); it != adj[node].end(); it++)
    {
        if (!vis[*it])
        {
            dfs(*it);
        }
    }
}

int main()
{
    for (int i = 0; i < 20; i++)
    {
        vis[i] = 0;
    }
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int p;
    cin >> p;
    queue<int> q;
    q.push(p);
    vis[p] = true;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";

        vi::iterator it;
        for (it = adj[node].begin(); it != adj[node].end(); it++)
        {
            if (!vis[*it])
            {
                vis[*it] = 1;
                q.push(*it);
            }
        }
    }
    cout<<endl;
    for (int i = 0; i < 20; i++)
    {
        vis[i] = 0;
    }
    dfs(p);

    return 0;
}