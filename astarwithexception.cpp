#include<iostream>
#include<bits/stdc++.h>
#define ll long long
#define mod 1e9 + 7
using namespace std;

int evalu(vector<vector<int>>&start,vector<vector<int>>&end,int level){
    int heu=0;
    for(int i=0;i<start.size();i++){
        for(int j=0;j<start[0].size();j++){
            if(start[i][j]!=-1 && start[i][j]!=end[i][j])heu++;
        }
    }
    return heu+level;  // evalution funtion is h(n) + f(n);
}
bool check(vector<vector<int>>&start,vector<vector<int>>&end){
     vector<int>temp={-1,1,2,3,4,5,6,7,8};
     vector<vector<vector<int>>>all;
     //for all the possible  matrix of 3 by 3 ;

     do{
        vector<vector<int>>tempx(3,vector<int>(3));
        for(int i=0;i<9;i++){
            tempx[i/3][i%3]=temp[i];
        }
        all.push_back(tempx);
     }while(next_permutation(temp.begin(),temp.end()));

     map<vector<vector<int>>,int>mp;
     //map for the matrix to node;for visited purpose 
     for(int i=0;i<all.size();i++)mp[all[i]]=i;

     vector<int>visi(all.size(),0); // visited ARRAY....

     priority_queue<pair<int,pair<int,vector<vector<int>>>>,vector<pair<int,pair<int,vector<vector<int>>>>>,greater<pair<int,pair<int,vector<vector<int>>>>>>pq;
    pq.push({evalu(start,end,0),{0,start}});
    visi[mp[start]]=1;

    while(!pq.empty()){
        int eval=pq.top().first;
        int level=pq.top().second.first;
        vector<vector<int>>state=pq.top().second.second;
        pq.pop();

        
        if(state==end){
            return true;
        }
       vector<int>rows={-1,0,1,0};
       vector<int>cols={0,1,0,-1};
        for(int i=0;i<state.size();i++){
            for(int j=0;j<state[0].size();j++){
                if(state[i][j]==-1){
                    //if blank space then move up,down,right,left;
                    for(  int k=0;k<4;k++){
                        int nx=i+rows[k];
                        int ny=j+cols[k];

                        if(nx<state.size() && nx>=0 && ny<state.size() && ny>=0){
                            vector<vector<int>>tempstate=state;
                            swap(tempstate[i][j],tempstate[nx][ny]);//shifted the tile...
                            int tempeval=evalu(tempstate,end,level+1);
                            if(visi[mp[tempstate]]==1)continue;
                            pq.push({tempeval,{level+1,tempstate}});
                            visi[mp[tempstate]]=1;
                        }
                    } 
                }
            }
        }
    }
      return false;


};

void Print(vector<vector<int>>&start,vector<vector<int>>&end){
    priority_queue<pair<int,pair<int,vector<vector<int>>>>,vector<pair<int,pair<int,vector<vector<int>>>>>,greater<pair<int,pair<int,vector<vector<int>>>>>>pq;
    pq.push({evalu(start,end,0),{0,start}});
    int steps=1;
    while(!pq.empty()){
        int eval=pq.top().first;
        int level=pq.top().second.first;
        vector<vector<int>>state=pq.top().second.second;
        pq.pop();

        cout<<"Selected State at step "<<steps++<<"\n";
        for(auto it:state){
            for(auto x:it){cout<<x<<" ";}cout<<endl;
        }
        cout<<"Level : "<<level<<"\n Heuristic value H(n) : "<<eval-level<<"\nEvalution function F(n): "<<eval<<endl;
        
        if(state==end){
            cout<<"Final State Reached H(n)==0 at level"<<level<<" in "<<steps-1<<" Slides/Shifts"<<endl;
            break;
        }
       vector<int>rows={-1,0,1,0};
       vector<int>cols={0,1,0,-1};
       cout<<"possible moves ::::"<<endl;
       int move=1;
        for(int i=0;i<state.size();i++){
            for(int j=0;j<state[0].size();j++){
                if(state[i][j]==-1){
                    //if blank space then move up,down,right,left;
                    for(  int k=0;k<4;k++){
                        int nx=i+rows[k];
                        int ny=j+cols[k];

                        if(nx<state.size() && nx>=0 && ny<state.size() && ny>=0){
                            vector<vector<int>>tempstate=state;
                            swap(tempstate[i][j],tempstate[nx][ny]);//shifted the tile...
                            int tempeval=evalu(tempstate,end,level+1);
                            pq.push({tempeval,{level+1,tempstate}});
                            cout<<" move no "<<move++<<endl;
                            for(auto it:tempstate){
                                 for(auto x:it){cout<<x<<" ";}cout<<endl;
                            }
                            cout<<"Level : "<<level+1<<"\n Heuristic value H(n) : "<<tempeval-level-1<<"\nEvalution function F(n): "<<tempeval<<endl;

                        }
                    } 
                }
            }
        }
        cout<<"end of possible moves---\n";
    }
}

int main()
{ 
    vector<vector<int>>start(3,vector<int>(3)),end(3,vector<int>(3));
    cout<<"initial state"<<endl;
    for (auto& it : start){
        for (auto& i : it) cin>>i;
    }
    cout<<"final state"<<endl;
    for (auto& it : end){
        for (auto& i : it) cin>>i;
    }
    cout<<endl;
    // priority queue of {eval,{level,grid}};
    if(check(start,end)){
        Print(start,end);
    }else{
        cout<<" Not Possible"<<endl;
    }   
    return 0;
}