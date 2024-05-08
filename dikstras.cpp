#include<iostream>
#include<bits/stdc++.h>
#define ll long long
#define mod 1e9 + 7
using namespace std;

int main()
{   int cities;
    cout<<"No of citites ";cin>>cities;
    cout<<"Name of cities\n";
    map<string,int>node;
    map<int,string>city;
    for(int i=0;i<cities;i++){
        string temp;
        cin>>temp;
        node.insert(pair<string,int>(temp,i));
        city.insert(pair<int,string>(i,temp));
    }
    int nosflight;
    cout<<"No of Flights :";cin>>nosflight;
    vector<vector<pair<int,int>>>adjLis(cities);//adjacency list ( form -{to,price});
    for(int i=0;i<nosflight;i++){
        string from,to;
        int price;
        cout<<"from:";cin>>from;
        cout<<"to:";cin>>to;
        cout<<"price";cin>>price;
        int u=node[from];
        int v=node[to];
        adjLis[u].push_back({v,price});
    }
    
    // Dijkstras algo 
    string start,end;
    cout<<"Enter The Start stop:";cin>>start;
    cout<<"Enter The Distination stop:";cin>>end;
    int src=node[start];
    int desti=node[end];
    vector<int>price(cities,1e9);
    vector<int>parent(cities);
    for(int i=0;i<cities;i++)parent[i]=i;
    set<pair<int,int>>pq;
    pq.insert({0,src});
    price[src]=0;
    while(!pq.empty()){
        auto it=*(pq.begin());
        int curprice=it.first;
        int cur=it.second;
        pq.erase(it);
        for(auto it:adjLis[cur]){
             int v=it.first;
             int pri=it.second;
             if(pri+curprice<price[v]){
                
                if(price[v]!=1e9){
                    pq.erase({price[v],v});// if already taken with large value delete it so not in path.
                }

                price[v]=curprice+pri;
                pq.insert({price[v],v});
                parent[v]=cur;
             }
        }
    }
    
    if(price[desti]==1e9){
        cout<<"------------\nNo flights"<<endl;
    }else{
       vector<int>path;
       int node=desti;
       while(parent[node]!=node){
            path.push_back(node);
            node=parent[node];
       }
       path.push_back(src);
       for(int i=path.size()-1;i>=0;i--){
          cout<<city[path[i]]<<"->-to->-";
       }cout<<endl;
        cout<<"Cheapest Price needed"<<price[desti]<<endl;
    }

    return 0;
}
//cities 4 akola,pune,nagpur,mumbai
//flights 5 
// akola pune 100
//pune nagpur 100
// nagpur akola 100
//pune mumbai 600
//nagpur mumbai 300


// Name of cities
// akola
// pune
// nagpur
// mumbai
// No of Flights :5
// from:akola
// to:pune
// price100
// from:pune    
// to:nagpur
// price100
// from:nagpur
// to:akola
// price100
// from:pune
// to:mumbai
// price600
// from:nagpur
// to:mumbai
// price300
// Enter The Start stop:akola
// Enter The Distination stop:mumbai
// The Path is As Follows-----
// akola
// pune
// nagpur
// mumbai
// Cheapest Price needed500