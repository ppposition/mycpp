/*
使用c++实现A*算法
假设有一个网格地图，其中包含可行走的路径和障碍物
目标是找到从起点到目标点的最短路径
*/
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<unordered_set>
using namespace std;

//定义地图大小
const int ROWS=5;
const int COLS=5;

//定义节点
struct Node{
    int x, y; //定义坐标
    int g, h; //g表示从起点到当前节点的实际代价，h表示从当前节点到目标节点的估计代价
    Node* parent; //指向父节点的指针
    Node(int x,int y):x(x),y(y),g(0),h(0),parent(nullptr){}
    //计算f值
    int getF() const{
        return g+h;
    }
};

// 比较两个节点的f值
struct CompareNode{
    bool operator()(const Node* a, const Node* b) const{
        return a->getF() > b->getF();
    }
};

//A*算法
vector<Node*> AStar(int grid[ROWS][COLS], Node* start, Node* goal){
    //用f值排序的优先队列，
    priority_queue<Node*, vector<Node*>, CompareNode> openSet;
    unordered_set<Node*> openSetSearch;
    //二维数组跟踪已访问的节点
    bool closedSet[ROWS][COLS]={false};
    
    //起点g值为0，计算起点到目标的h值
    start->h = abs(start->x - goal->x) + abs(start->y-goal->y);
    
    //起点加到开放集中
    openSet.push(start);
    openSetSearch.emplace(start);
    while(!openSet.empty()){
        Node* current = openSet.top();
        openSet.pop();
        openSetSearch.erase(current);
        //当前节点是目标节点，返回路径
        if(current->x == goal->x && current->y == goal->y){
            vector<Node*> path;
            while(current){
                path.push_back(current);
                current=current->parent;
            }
            return path;
        }
        
        //当前节点标记为已访问
        closedSet[current->x][current->y]=true;

        //定义四个可能移动的方向：上下左右
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        
        for(int i=0;i<4;i++){
            int newX = current->x + dx[i];
            int newY = current->y + dy[i];
            //检查新坐标是否在地图范围内
            if(newX>=0 && newY>=0 && newX<ROWS && newY<COLS){
                if(grid[newX][newY]==0||closedSet[newX][newY])
                    continue;
                int newG = current->g + 1;

                Node* neighbor = nullptr;

                //检验是否已经在openSet中，
                for(Node* node:openSetSearch){
                    if(node->x==newX && node->y==newY){
                        neighbor = node;
                        break;
                    }
                }

                //若新节点不在openset中或者新的g小于原来的g，更新节点
                if(!neighbor||newG<neighbor->g){
                    if(!neighbor)
                        neighbor = new Node(newX,newY);
                    neighbor->g = newG;
                    neighbor->h = abs(newX - goal->x) + abs(newY - goal->y);
                    neighbor->parent = current;
                    openSet.push(neighbor);
                    openSetSearch.emplace(neighbor);
                } 
            }
        }
    }
    return vector<Node*>();
}
int main(){
    int grid[ROWS][COLS] = {
        {1, 1, 1, 0, 1},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 0, 1},
        {0, 0, 1, 1, 1},
        {1, 1, 1, 1, 1}
    };
    Node* start=new Node(0, 0);
    Node* goal=new Node(4, 4);
    vector<Node*> path = AStar(grid, start, goal);
    if(path.empty()){
        cout<<"path doesn't exist"<<endl;
    }
    else{
        for(int i=path.size()-1;i>=0;i--){
            cout<<"("<<path[i]->x<<","<<path[i]->y<<")"<<endl;
        }
    }
    return 0;
}
