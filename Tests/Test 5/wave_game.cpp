#include <iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int x; // x coordainate
    int y; // y coordainate
    int dist; // distance from the start
    Node(int x, int y, int distance){ //constructor
        this->x=x;
        this->y=y;
        this->dist=distance;
    }
};
int arr[500][500],n,m;
int startX,startY,Distance; // the start coordinates and the distance
bool used[500][500]; // boolean matrix where we will save if we used curtain vertex 
long long int sum; // the sum of all vertices at the given distance from start
queue<Node> q;
void read(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    cin>>startX>>startY>>Distance;
}
bool isValid(int x, int y, int dist){
     if(x>-1 && y>-1 && x<n && y<m && dist<=Distance && arr[x][y]!=-1 && used[x][y]==false) return true;
     else return false;
}
void solve(){

    q.push(Node(startX-1,startY-1,1)); // we start from (1,1) and it is at disatance 1 from itself

    while(!q.empty()){
        Node current=q.front();
        q.pop();
        
        if(isValid(current.x,current.y,current.dist)){ // check if the coordinates are valid, it is not a wall and we haven't used it yet
            used[current.x][current.y]=true; //use the vertex
            if(current.dist==Distance){ // if it is at the right distance add it to the queue
                sum+=arr[current.x][current.y]; 
            }
            else{
            // push the neighboring vertices into the queue
            q.push(Node(current.x +1,current.y,current.dist+1));
            
            q.push(Node(current.x -1,current.y,current.dist+1));
            
            q.push(Node(current.x,current.y +1,current.dist+1));
            
            q.push(Node(current.x,current.y -1 ,current.dist+1));
            }
        }
    }
}

int main() {
    read();
    solve();
    cout<<sum<<endl;
    return 0;
}