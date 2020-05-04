#pragma once

#include <iostream>
#include <vector>
#include<memory>
using namespace std;
//15*15的棋盘,以拓扑3代为例

#define row_num 6
#define col_num 6
#define black 1
#define white 2

class status
{
    public:
    bool black_or_white;//true is black
    int generation=0;
    int x=0,y=0;//下一步的坐标，仅针对第一步预判

    int fx=-1000;//评估函数

    vector<vector<int>> chessboard;

    int max=-10000,min=10000;//alpha-belta减枝法

    status();
    ~status();
    
};

using status_ptr=std::shared_ptr<status>;

/*极大极小法*/
int Minimax(status_ptr p, status_ptr head);

/*alpha_belta法*/
int alpha_belta(status_ptr p, status_ptr head);

int get_fx(status_ptr p);

int weight(int x1, int x2);



