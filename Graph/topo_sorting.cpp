#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int maxn = 1001;
int n, m;
vector<int> adj[maxn];
bool visited[maxn];
stack<int> topo;

void inp()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    memset(visited, false, sizeof(visited));
}

void dfs(int u)
{
    visited[u] = true;
    for(int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if(!visited[v])
        {
            dfs(v);
        }
    }
    topo.push(u);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt","w", stdout);
    inp();
    for(int i = 1; i <=n; i++)
    {
        if(!visited[i])
        {
            dfs(i);
        }
    }
    for(int i = 0; i < n; i++)
    {
        cout << topo.top() << " ";
        topo.pop();
    }
    
    return 0;
}