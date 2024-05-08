#include<bits/stdc++.h>
using namespace std;

class Cargo{

    public:
    string  type;
    string destination;
    int weight;
    int priority;

    Cargo(string type,string destination, int weight, int priority){

        this->type= type;
        this->destination=destination;
        this->weight = weight;
        this->priority=priority;
    }
     
};

class Flight{

    public:
    string destination;
    int capacity;
    vector<string>cargos;

    Flight(string destination ,int capacity){

        this->destination=destination;
        this->capacity=capacity;
        this->cargos={};
    }

};

void assign(vector<Cargo> cargos, vector<Flight> flights, vector<Flight> nearest_flights)
{

    for(auto it:cargos){

        bool t=false;

        if(it.type=="Perishable"){

            for (auto i : nearest_flights)
            {
                if (i.destination == it.destination)
                {
                    if (i.capacity >= it.weight)
                    {
                        i.capacity -= it.weight;
                        cout << "Cargo info : " << it.type << " " << it.destination << " " << it.weight << endl;
                        cout << "Status : "
                             << "Shipped in "<< i.destination<<" flight..." << endl;

                        i.cargos.push_back(it.type);
                        t=true;
                    }
                    else
                    {
                        cout << "Cargo info : " << it.type << " " << it.destination << " " << it.weight << endl;
                        cout << "Status : "
                             << "Not shipped due to uavailability  of space in flight... " << endl;

                        t = true;
                    }
                }
            }
        }
        else if(it.type=="Fragile"){

            for(auto  i:flights){
                if(it.destination == i.destination){
                    if (i.capacity >= it.weight)
                    {
                        i.capacity -= it.weight;
                        cout << "Cargo info : " << it.type << " " << it.destination << " " << it.weight << endl;
                        cout << "Status : "
                             << "Shipped in " << i.destination << " flight..." << endl;
                        i.cargos.push_back(it.type);
                        t = true;
                    }
                    else
                    {
                        cout << "Cargo info : " << it.type << " " << it.destination << " " << it.weight << endl;
                        cout << "Status : "
                             << "Not shipped due to uavailability  of space in flight... " << endl;
                        t = true;
                    }
                }
            }

            for (auto i : nearest_flights)
            {
                if (i.destination == it.destination)
                {
                    if (i.capacity >= it.weight)
                    {
                        i.capacity -= it.weight;
                        cout << "Cargo info : " << it.type << " " << it.destination << " " << it.weight << endl;
                        cout << "Status : "
                             << "Shipped in " << i.destination << " flight..." << endl;

                        i.cargos.push_back(it.type);
                        t = true;
                    }
                    else
                    {
                        cout << "Cargo info : " << it.type << " " << it.destination << " " << it.weight << endl;
                        cout << "Status : "
                             << "Not shipped due to uavailability  of space in flight... " << endl;
                        t = true;
                    }
                }
            }
        }

        if(t==false){
            cout << "Cargo info : " << it.type << " " << it.destination << " " << it.weight << endl;
            cout << "Status : "
                 << "Not shipped due to uavailability  destination of flight... " << endl;
        }
    }
}

int main(){

    vector<Flight>flights{
        Flight("NewYork" , 200),
        Flight("Japan" , 450),
        Flight("USA" , 750)
    };

    vector<Flight>nearest_flights{
        Flight("UAE", 320),
        Flight("Nepal" ,450)
    };

    int n;cout<<"Enter no of cargos you  want shift : ";cin>>n;
    cout << "Enter TYPE , DESTINATION , WEIGHT , PRIORITY  for each cargo" << endl;
    vector<Cargo>cargos;
    while(n--){

        int w,p;string type,dest;
        cin>>type>>dest>>w>>p;
        Cargo obj(type, dest, w , p );
        cargos.push_back(obj);

    }

    sort(cargos.begin(), cargos.end(), [](const Cargo &a, const Cargo &b)
         { return a.priority > b.priority; });
    
    cout<<endl;

    assign(cargos ,flights ,nearest_flights);


    cout<<endl;
    cout<<"Thank you for using Expert System ... "<<endl;
    return 0;
}