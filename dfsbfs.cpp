#include<iostream>
#include<bits/stdc++.h>
#define ll long long
#define mod 1e9 + 7
using namespace std;

int cities;
vector<vector<int>>adjLis;
map<string,int>node;
map<int,string>city;

void bfs(int start,vector<int>&visi,int level){
     queue<pair<int,int>>q;
     q.push({level,start});
     visi[start]=1;

     while(!q.empty()){
        int cur=q.front().second;
        int lev=q.front().first;
        q.pop();
        cout<<"city"<<city[cur]<<" connected at level "<<lev<<endl;

         for(auto it :adjLis[cur]){
            if(visi[it]==0){
                q.push({lev+1,it});
                visi[it]=1;
            }
         }
     }
}

void dfs(int cur,vector<int>&visi,int level){
    visi[cur]=1;
    cout<<"city"<<city[cur]<<"connceted at level "<<level<<endl;

    for(auto it:adjLis[cur]){
        if(visi[it]==0){
            dfs(it,visi,level+1);
        }
    }
}

int noOfProviencesBFS(){
    vector<int>visi(cities,0);
    int ans=0;

    for(int i=0;i<cities;i++){
        if(visi[i]==0){
            ans++;
            cout<<" The Cities connected to"<<city[i]<<" are as follows\n";
            bfs(i,visi,0);
        }
    }
    return ans;
}
int noOfProviencesDFS(){
    vector<int>visi(cities,0);
    int ans=0;

    for(int i=0;i<cities;i++){
        if(visi[i]==0){
            ans++; 
            cout<<" The Cities connected to "<<city[i]<<" are as follows\n";
            dfs(i,visi,0);
        }
    }
    return ans;
}

int main()
{   
    
    cout<<"No of citites ";cin>>cities;
    cout<<"Name of cities\n";

    for(int i=0;i<cities;i++){
        string temp;
        cin>>temp;
        node.insert(pair<string,int>(temp,i));
        city.insert(pair<int,string>(i,temp));
    }

    int conn;
    cout<<"Enter the no of Connection between the cities";
    cin>>conn;
    
    adjLis.resize(cities);
    for(int i=0;i<conn;i++){
        string a,b;
        cout<<"City a";cin>>a;
        cout<<"City b";cin>>b;
        adjLis[node[a]].push_back(node[b]);
        adjLis[node[b]].push_back(node[a]);
    }
    // created adjLisrix;
    
    //To Find out the Proviences or the Connected groups among all
    
    // int ans1=noOfProviencesBFS();
    // cout<<"Total areas connceted are "<<ans1<<endl;
    
    int ans2=noOfProviencesBFS();
    cout<<"Total areas are"<<ans2<<endl;


    return 0;
}


/*
 cities 6 a b c d e f 
 coonection 4
 a b
 b c
 a c
 e d
  output 
  3 proviences abc ed f 
  the levels are as per the traverseal 

*/