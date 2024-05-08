#include<bits/stdc++.h>
using namespace std;

int evalFn (vector<vector<int>>&state, vector<vector<int>>&grid, int level){
    int count = 0;
    
    for (int i = 0; i<3; i++){
        for (int j = 0; j<3; j++){
            if(state[i][j] != grid[i][j]) count++;
        }
    }
    return count+level;
}

int main(){
    vector<vector<int>>initialState(3,vector<int>(3));
    vector<vector<int>>goalState(3,vector<int>(3));
    cout<<"Please enter initialState state-> "<<endl;
    for (auto& it : initialState){
        for (auto& i : it) cin>>i;
    }
    cout<<"Please enter goalState state"<<endl;
    for (auto& it : goalState){
        for (auto& i : it) cin>>i;
    }
    // {evalfn,{level,currstate}};
    priority_queue <pair<int,pair<int,vector<vector<int>>>>, vector<pair<int,pair<int,vector<vector<int>>>>>, greater<pair<int,pair<int,vector<vector<int>>>>> > pq;
    pq.push({evalFn(initialState,goalState,0),{0,initialState}});

    while (!pq.empty()){
        cout<<"Chosen path: "<<endl;
        int val = pq.top().first;
        int level = pq.top().second.first;
        vector<vector<int>>state = pq.top().second.second;
        pq.pop();
        for (auto it :state){
            for (auto i : it) cout<<i<<" ";
            cout<<endl;
        }
        cout<<"Value of EvalFn is -> "<<val<<endl;
        cout<<"The coressponding Heuristic Value is:"<<val-level<<endl;
        cout<<"Lvl : "<<level<<endl;
        cout<<endl;
        if(state == goalState){
            cout<<"The Goal State is reached!!"<<endl;
            break;
        }
        int perrow[4] = {-1,0,1,0};
        int percol[4] = {0,1,0,-1};
        cout<<"All the Possibilities are: "<<endl;
        for (int i = 0; i<3; i++){
            for (int j = 0; j<3; j++){
                if(state[i][j]==-1){
                    for (int a = 0; a<4; a++){
                        int rowi = i+perrow[a];
                        int colj = j+percol[a];

                        if(rowi>=0 && rowi<3 && colj>=0 && colj<3){
                            vector<vector<int>>temp = state;
                            swap(temp[i][j],temp[rowi][colj]);
                            pq.push({evalFn(temp,goalState,level+1),{level+1,temp}});
                            for (auto it : temp){
                                for (auto i : it) cout<<i<<" ";
                                cout<<endl;
                            }
                            cout<<"Evaluation function value: "<<evalFn(temp,goalState,level+1)<<endl;
                            cout<<"Heuritistic value :"<<evalFn(temp,goalState,level+1)-level-1<<endl;
                            cout<<"Lvl : "<<level+1<<endl;
                            cout<<endl;
                        }
                    }
                }
            }
        }
    }
   
}