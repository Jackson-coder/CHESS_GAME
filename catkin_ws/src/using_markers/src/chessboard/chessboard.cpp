#include <chessboard.h>
#include <string.h>

/*机器是黒棋*/
status::status()
{
    chessboard.clear();
    for (int i = 0; i < row_num; i++)
    {
        vector<int> row_chessboard;
        row_chessboard.clear();
        for (int j = 0; j < col_num; j++)
        {
            row_chessboard.push_back(0);
        }
        chessboard.push_back(row_chessboard);
    }
}
status::~status()
{
}

int tt = 0;
//递归结果输出新棋盘的棋局P->chessboard
int Minimax(status_ptr p, status_ptr head)
{
    int add_chess = p->black_or_white == true ? black : white;

    if (head->generation != -1)
    {
        for (int i = 0; i < row_num; i++)
        {
            for (int j = 0; j < col_num; j++)
            {
                p->chessboard[i][j] = head->chessboard[i][j];
            }
        }
    }
    else
    {
        for (int i = 0; i < row_num; i++)
        {
            for (int j = 0; j < col_num; j++)
            {
                cout << p->chessboard[i][j] << ' ';
            }
            cout << endl;
        }
    }

    p->generation = head->generation + 1;

    if (p->generation == 3)
    {
        /*计算p->hx*/
        p->fx = get_fx(p);
        return p->fx;
    }

    int fx;
    for (int i = 0; i < row_num; i++)
        for (int j = 0; j < col_num; j++)
        {
            if (p->chessboard[i][j] == 0)
            {
                p->chessboard[i][j] = add_chess;

                status_ptr pn{new (status)};
                pn->black_or_white = p->black_or_white == true ? false : true;

                int fx = Minimax(pn, p);

                if (p->fx == -1000)
                {
                    p->fx = fx;
                    p->x = i;
                    p->y = j;
                }

                else if (p->generation % 2 == 0) //黑 取大
                {
                    if (p->fx < fx)
                    {
                        p->fx = fx;
                        if (p->generation == 0)
                        {
                            p->x = i;
                            p->y = j;
                        }
                    }
                }
                else //白 取小
                {
                    if (p->fx > fx)
                        p->fx = fx;
                }

                if (p->generation == 0)
                    cout << p->x << ' ' << p->y << ' ' << p->fx << endl;

                p->chessboard[i][j] = 0;
            }
        }

    return p->fx;
}

int alpha_belta(status_ptr p, status_ptr head)
{
    int add_chess = p->black_or_white == true ? black : white;

    if (head->generation != -1)
    {
        for (int i = 0; i < row_num; i++)
        {
            for (int j = 0; j < col_num; j++)
            {
                p->chessboard[i][j] = head->chessboard[i][j];
            }
        }
    }
    else
    {
        for (int i = 0; i < row_num; i++)
        {
            for (int j = 0; j < col_num; j++)
            {
                cout << p->chessboard[i][j] << ' ';
            }
            cout << endl;
        }
    }

    p->generation = head->generation + 1;

    if (p->generation == 3)
    {
        /*计算p->hx*/
        p->fx = get_fx(p);
        return p->fx;
    }

    int fx;
    for (int i = 0; i < row_num; i++)
        for (int j = 0; j < col_num; j++)
        {
            if (p->chessboard[i][j] == 0)
            {
                p->chessboard[i][j] = add_chess;

                status_ptr pn{new (status)};
                pn->black_or_white = p->black_or_white == true ? false : true;

                int fx = alpha_belta(pn, p);

                if (p->fx == -1000)
                {
                    cout << "fx:" << fx << endl;
                    p->fx = fx;
                    p->x = i;
                    p->y = j;
                }
                else if (p->generation % 2 == 0) //黑 取大
                {
                    if (p->fx > head->fx && head->fx != -1000)
                        return head->fx;
                    if (p->fx < fx)
                    {
                        p->fx = fx;
                        if (p->generation == 0)
                        {
                            p->x = i;
                            p->y = j;
                        }
                    }
                }
                else if (p->generation % 2 != 0) //白 取小
                {
                    if (p->fx < head->fx && head->fx != -1000)
                        return head->fx;
                    if (p->fx > fx)
                        p->fx = fx;
                }

                if (p->generation == 0)
                    cout << p->x << ' ' << p->y << ' ' << p->fx << endl;

                p->chessboard[i][j] = 0;
            }
        }

    return p->fx;
}

int get_fx(status_ptr p)
{
    int max = 0, min = 0, count = 0;

    for (int i = 0; i < row_num; i++)
    {
        for (int j = 0; j < col_num - 4; j++)
        {
            int count_max = 0, count_min = 0, x1 = 0, x2 = 0;
            for (int z = 0; z < 5; z++)
            {
                if (p->chessboard[i][j + z] == 0 || p->chessboard[i][j + z] == white)
                    count_min++;
                if (p->chessboard[i][j + z] == 0 || p->chessboard[i][j + z] == black)
                    count_max++;
                if (p->chessboard[i][j + z] == white)
                    {x1++;x2--;}
                if (p->chessboard[i][j + z] == black)
                    {x2++;x1--;}
                // if (p->chessboard[i][j + z] == white)
                //     count++;
                // if (p->chessboard[i][j + z] == black)
                //     count++;
            }
            if (count_max == 5)
                max++;
            if (count_min == 5)
                min++;

            count += weight(x2 , x1);
        }
    }
    // cout << max << ' ' << min << endl;

    for (int i = 0; i < col_num; i++)
    {
        for (int j = 0; j < row_num - 4; j++)
        {
            int count_max = 0, count_min = 0, x1 = 0, x2 = 0;
            for (int z = 0; z < 5; z++)
            {
                if (p->chessboard[j + z][i] == 0 || p->chessboard[j + z][i] == white)
                    count_min++;
                if (p->chessboard[j + z][i] == 0 || p->chessboard[j + z][i] == black)
                    count_max++;
                if (p->chessboard[j + z][i] == white)
                    {x1++;x2--;}
                if (p->chessboard[j + z][i] == black)
                    {x2++;x1--;}
            }
            if (count_max == 5)
                max++;
            if (count_min == 5)
                min++;
            count += weight(x2 , x1);
        }
    }

    for (int i = 0; i < col_num - 4; i++)
    {

        for (int j = 0; j < row_num - 4; j++)
        {
            int count_max = 0, count_min = 0, x1 = 0, x2 = 0;
            for (int z = 0; z < 5; z++)
            {
                if (p->chessboard[i + z][j + z] == 0 || p->chessboard[i + z][j + z] == white)
                    count_min++;
                if (p->chessboard[i + z][j + z] == 0 || p->chessboard[i + z][j + z] == black)
                    count_max++;
                if (p->chessboard[i + z][j + z] == white)
                    {x1++;x2--;}
                if (p->chessboard[i + z][j + z] == black)
                    {x2++;x1--;}
            }
            if (count_max == 5)
                max++;
            if (count_min == 5)
                min++;
            count += weight(x2 , x1);
        }
    }

    for (int i = 4; i < row_num; i++)
    {
        for (int j = 0; j < col_num - 4; j++)
        {
            int count_max = 0, count_min = 0, x1 = 0, x2 = 0;
            for (int z = 0; z < 5; z++)
            {
                if (p->chessboard[i - z][j + z] == 0 || p->chessboard[i - z][j + z] == white)
                    count_min++;
                if (p->chessboard[i - z][j + z] == 0 || p->chessboard[i - z][j + z] == black)
                    count_max++;
                if (p->chessboard[i - z][j + z] == white)
                    {x1++;x2--;}
                if (p->chessboard[i - z][j + z] == black)
                    {x2++;x1--;}
            }
            if (count_max == 5)
                max++;
            if (count_min == 5)
                min++;
            count += weight(x2 , x1);
        }
    }
    return max - min + count;
}

int weight(int x1, int x2)
{
    int count=0;
    switch (x1)
    {
    case 1:
        count += 3 * x1;
        break;
    case 2:
        count += 3 * x1;
        break;
    case 3:
        count += 11 * x1;
        break;
    case 4:
        count += 37 * x1;
        break;
    case 5:
        count += 100 * x1;
    default:
        break;
    }

    switch (x2)
    {
    case 1:
        count -= 3 * x2;
        break;
    case 2:
        count -= 3 * x2;
        break;
    case 3:
        count -= 13 * x2;
        break;
    case 4:
        count -= 50 * x2;
        break;
    default:
        break;
    }
    return count;
}