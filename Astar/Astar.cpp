#include <iostream>
#include <stdio.h>   
#include <vector>   
#include <algorithm>
//#include <Astar/Astar.h>  
using namespace std;

class Node{  
public:  
    int x;  
    int y;  
    int f;//g+h  
    int g;//起点到当前点的消耗   
    int h;//重点到当前点的理论消耗   
    Node* parent;  
    Node(int x,int y){  
        this->x = x;  
        this->y = y;  
        this->f = 0;  
        this->g = 0;  
        this->h = 0;  
        this->parent = NULL;  
    }  
    Node(int x,int y,Node* parent){  
        this->x = x;  
        this->y = y;  
        this->f = 0;  
        this->g = 0;  
        this->h = 0;  
        this->parent = parent;  
    }  
};  
//0表示可通过1表示障碍物   
int map[101][101] = {  
        {0,0,0,1,0,1,0,0,0},  
        {0,0,0,1,0,1,0,0,0},  
        {0,0,0,0,0,1,0,0,0},  
        {0,0,0,1,0,1,0,1,0},  
        {0,0,0,1,0,1,0,1,0},  
        {0,0,0,1,0,0,0,1,0},  
        {0,0,0,1,0,0,0,1,0}  
    };  
vector<Node*> openList;  
vector<Node*> closeList;    
int row;//地图总行数   
int col;//地图总列数   
Node* startPos;//开始点   
Node* endPos;//结束点   
int weightW;//平移权重   
int weightWH;//斜移权重   
  
int countH(Node* sNode,Node* eNode){  
    int w = abs(sNode->x - eNode->x);  
    int h = abs(sNode->y - eNode->y);  
    int cost = min(w,h)*weightWH + abs(w-h)*weightW;  
    return cost;  
}  
void countFGH(Node* sNode,Node* eNode,int cost){  
    int h = countH(sNode,eNode);  
    int g = sNode->parent->g + cost;  
    int f = h + g;  
    sNode->f = f;  
    sNode->h = h;  
    sNode->g = g;  
}  
//检测列表是否包含指定节点  
 int isContains(vector<Node*>* v,int x,int y){  
    for(int i=0;i<v->size();i++){  
        if(v->at(i)->x==x&&v->at(i)->y==y){  
            return i;  
        }  
    }  
    return -1;  
 }  
void initMap(){   
    row = 7;  
    col = 9;  
    weightW = 10;  
    weightWH = 15;  
    startPos = new Node(5,1);  
    endPos = new Node(3,8);  
}  
  
void printMap(){  
    for(int i=0;i<row;i++){  
        for(int j=0;j<col;j++){  
            printf("%d ",map[i][j]);  
        }  
        printf("\n");  
    }  
}  
bool compare(Node* n1,Node* n2){  
    return n1->f <= n2->f;  
}  
void checkMove(int x,int y,Node* parent,Node* end,int cost){  
    if(map[x][y]==1){  
        return;  
    }  
    if(isContains(&closeList,x,y)!=-1){  
        return;  
    }  
    int index = -1;  
    if((index = isContains(&openList,x,y))!=-1){  
        //是否存在更小的G值  
        Node* sNode = openList[index];  
        if(parent->g+cost < sNode->g){  
            sNode->g = parent->g+cost;  
            sNode->f = sNode->g + sNode->h;  
        }  
    }else{  
        Node* n = new Node(x,y,parent);  
        countFGH(n,end,cost);  
        openList.push_back(n);  
    }  
}  
void printPath(Node* node){  
    if(node->parent != NULL){  
        printPath(node->parent);  
    }  
    //将走过的点标记为2   
    //map[node->x][node->y] = 2;  
    printf("->%d,%d",node->x,node->y);  
}  
void releaseNode(Node* n){  
    if(n->parent != NULL){  
        releaseNode(n->parent);  
    }  
    delete n;  
}  
//-1错误0没找到1找到   
int startSearch(Node* start,Node* end){  
    if(start->x<0||start->y<0||start->x>=row||start->y>=col  
     ||end->x<0||end->y<0||end->x>=row||end->y>=col){  
        return -1;  
    }  
    if(map[start->x][start->y]==1||map[end->x][end->y]==1){  
        return -1;  
    }  
      
    start->h = countH(start,end);  
    start->f = start->h + start->g;  
    //查找算法  
    openList.push_back(start);  
    Node* root = NULL;  
    int find = 0;  
    while(openList.size()>0){  
        root = openList[0];  
        if(root->x==end->x&&root->y==end->y){  
            find = 1;  
            break;  
        }     
        //上下左右   
        if(root->x > 0){  
            checkMove(root->x-1,root->y,root,end,weightW);  
        }  
        if(root->y > 0){  
            checkMove(root->x,root->y-1,root,end,weightW);  
        }  
        if(root->x < row-1){  
            checkMove(root->x+1,root->y,root,end,weightW);  
        }  
        if(root->y < col-1){  
            checkMove(root->x,root->y+1,root,end,weightW);  
        }  
        if(root->x < row-1&&root->y>0){  
            checkMove(root->x+1,root->y-1,root,end,weightW);  
        }  
        if(root->y < col-1&&root->x>0){  
            checkMove(root->x-1,root->y+1,root,end,weightW);  
        }  
        if(root->x>0&&root->y>0){  
            checkMove(root->x-1,root->y-1,root,end,weightW);  
        }  
        if(root->y<col-1&&root->x<row-1){  
            checkMove(root->x+1,root->y+1,root,end,weightW);  
        }  
        closeList.push_back(root);  
        openList.erase(openList.begin());  
        sort(openList.begin(),openList.end(),compare);  
    }  
    if(find){  
        printPath(root);  
        printf("\n");  
        //printMap();  
    }  
    releaseNode(root);  
    openList.clear();  
    closeList.clear();  
    return find;  
}  
  
  
int main(int argc, char *argv[]){  
    initMap();    
    printMap();  
    int t = startSearch(startPos,endPos);  
    if(t==1){  
        printf("find!");  
    }else if(t==0){  
        printf("no find.");  
    }else{  
        printf("error!");  
    }  
    return 0;  
}  