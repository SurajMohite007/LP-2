#include<bits/stdc++.h>
using namespace std;

void recDfs(vector<int>adj[] ,int node, vector<int>&vis){
    vis[node]=1;

    for(auto  it:adj[node]){
        if(vis[it]==0){
            recDfs(adj ,it ,vis);
        }
    }

}

int Dfs(vector<vector<int>> graph, int n)
{
    vector<int> vis(n, 0);
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            cnt++;
            stack<int> st;
            st.push(i);
            vis[i] = 1;

            while (!st.empty())
            {
                int node = st.top();
                st.pop();

                for (int j = 0; j < n; j++)
                {
                    if (graph[node][j] == 1 && !vis[j])
                    {
                        st.push(j);
                        vis[j] = 1;
                    }
                }
            }
        }
    }

    return cnt;
}

int Bfs(vector<vector<int>> graph, int n)
{
    vector<int> vis(n, 0);
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            cnt++;
            queue<int> st;
            st.push(i);
            vis[i] = 1;

            while (!st.empty())
            {
                int node = st.front();
                st.pop();

                for (int j = 0; j < n; j++)
                {
                    if (graph[node][j] == 1 && !vis[j])
                    {
                        st.push(j);
                        vis[j] = 1;
                    }
                }
            }
        }
    }

    return cnt;
}

int noOfPrevience(vector<vector<int>>graph , int n){

    vector<int>adj[n];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(graph[i][j]==1 && i!=j){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    int cnt=0;

    vector<int>vis(n ,0);
    for(int i=0;i<n;i++){
        if(vis[i]==0){
            cnt++;
            recDfs(adj , i, vis);
        }
    }

    return cnt;
}
int main(){

    int n;
    cout<<"Enter no. of nodes : ";
    cin>>n;

    vector<vector<int>>graph(n ,vector<int>(n ,0));
    cout<<"Provide matrix  reprensetation of graph : "<<endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>graph[i][j];
        }
    }

    int ans1 = noOfPrevience(graph ,n);
    int ans2 = Dfs(graph ,n);
    int ans3 = Bfs(graph, n);

    cout<<"No of proviences are : "<<ans1<<endl;
    cout << "No of proviences are : " << ans2 << endl;
    cout << "No of proviences are : " << ans3 << endl;
    return 0;
}