#include<iostream>
#include"Vertex.h"
#include"Graph.h"
#include<string>
using namespace std;
int main() {
    Graph g;
    string name1, name2;
    int d;
    int option;
    bool check;
    g.loadFromFileC("dsawyc.txt");
    g.loadFromFileE("dsawye.txt");
    cout << "                                              Welcome To Wassalny\n";
    do {
        cout << "------------------------------------------------------------------------------------------------------------\n";
        cout << "What operation do you want to perform? " << " Select Option number. Enter 0 to exit." << endl;
        cout << "1. Add City" << endl;
        cout << "2. Delete City" << endl;
        cout << "3. Add Road" << endl;
        cout << "4. Delete Road" << endl;
        cout << "5. Find the shortest path between 2 Cities" << endl;
        cout << "6. Traverse the graph (BFS)" << endl;
        cout << "7. Traverse the graph (DFS)" << endl;
        cout << "8. Print Graph" << endl;
        cout << "0. Exit Program" << endl;
        cin >> option;
        Vertex v;
        switch (option)
        {
        case 0: {
            break;
        }
        case 1: {
            cout << "Add City Operation" << endl;
            cout << "Enter City Name :";
            cin >> name1;
            name1[0] = toupper(name1[0]);
            v.SetName(name1);
            g.AddCity(v);
            break;
        }
        case 2: {
            cout << "Delete City Operation" << endl;
            cout << "Enter Name of City to Delete :";
            cin >> name1;
            name1[0] = toupper(name1[0]);
            g.DeleteCity(name1);

            break;
        }
        case 3: {
            cout << "Add Road Operation" << endl;
            cout << "Enter Name of Source City:";
            cin >> name1;
            name1[0] = toupper(name1[0]);
            cout << "Enter Name of Destination City:";
            cin >> name2;
            name2[0] = toupper(name2[0]);
            cout << "Enter Distance of Road:";
            cin >> d;
            if (d <= 0) {
                cout << "Invalid Distance!!!" << endl;
            }
            else
                g.AddEdge(name1, name2, d);
            break;
        }
        case 4: {
            cout << "Delete Road Operation" << endl;
            cout << "Enter Name of Source City:";
            cin >> name1;
            name1[0] = toupper(name1[0]);
            cout << "Enter Name of Destination City:";
            cin >> name2;
            name2[0] = toupper(name2[0]);
            g.DeleteRoad(name1, name2);
            

            break;
        }
        case 5: {
            cout << "Find the shortest path between 2 Cities Operation" << endl;
            cout << "Enter Name of Source City:";
            cin >> name1;
            name1[0] = toupper(name1[0]);
            cout << "Enter Name of Destination City:";
            cin >> name2;
            name2[0] = toupper(name2[0]);
            g.dijkstra(name1, name2);
            break;
        }
        case 6: {
            cout << "Traverse the graph (BFS) Operation" << endl;
            cout << "Enter the name of start City:";
            cin >> name1;
            name1[0] = toupper(name1[0]);
            g.BFS(name1);
            break;
        }
        case 7: {
            cout << "Traverse the graph (DFS) Operation" << endl;
            cout << "Enter the name of start City:";
            cin >> name1;
            name1[0] = toupper(name1[0]);
            g.DFS(name1);
            break;
        }
        case 8: {
            cout << "Print Graph Operation" << endl;
            g.printGraph();
            break;
        }
        default:
            break;
        }
    } while (option != 0);
    g.saveToFileC("dsawyc.txt");
    g.saveToFileE("dsawye.txt");
    return 0;
}