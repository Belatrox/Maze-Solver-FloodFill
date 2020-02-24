#include <stdio.h>

void printMaze(int maze[12][12]){
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) {
            printf("%d ",maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int maze[12][12] = { 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0,
                         0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0,
                         0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0,
                         0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1,
                         1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1,
                         0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1,
                         0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1,
                         0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1,
                         0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1,
                         0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1,
                         0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1,
                         0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, -6, };
    //right = i    ,j + 1
    //left  = i    ,j - 1
    //up    = i - 1,j
    //down  = i + 1,j
    int indexOfi = 0;
    int indexOfj = 0;
    int finished = 0;
    int tileNumber = 0;
    while(finished == 0){
        if(maze[indexOfi + 1][indexOfj] == -6 || maze[indexOfi][indexOfj + 1] == -6
           || maze[indexOfi - 1][indexOfj] == -6 || maze[indexOfi][indexOfj - 1] == -6){
            finished = 1;
            printMaze(maze);
            continue;
        }
        //right is empty
        if(maze[indexOfi][indexOfj + 1] == 0 && indexOfj + 1 < 12){
            tileNumber++;
            maze[indexOfi][indexOfj + 1] = tileNumber;
            indexOfj = indexOfj + 1;
            printMaze(maze);
            continue;
        }else
            //down is empty
        if(maze[indexOfi + 1][indexOfj] == 0 && indexOfi + 1 < 12){
            tileNumber++;
            maze[indexOfi + 1][indexOfj] = tileNumber;
            indexOfi = indexOfi + 1;
            printMaze(maze);
            continue;
        }else
            //up is empty
        if(maze[indexOfi - 1][indexOfj] == 0 && indexOfi - 1 >= 0){
            tileNumber++;
            maze[indexOfi - 1][indexOfj] = tileNumber;
            indexOfi = indexOfi - 1;
            printMaze(maze);
            continue;
        }else
            //left is empty
        if(maze[indexOfi][indexOfj - 1] == 0 && indexOfj - 1 >= 0){
            tileNumber++;
            indexOfj = indexOfj - 1;
            printMaze(maze);
            continue;
        }
        //if its dead end go back until a 0 (an open road) is found :
        //left
        if(maze[indexOfi][indexOfj - 1] != 1 && indexOfj - 1 >= 0){
            tileNumber--;
            maze[indexOfi][indexOfj] = 1;
            indexOfj = indexOfj - 1;
            printMaze(maze);
            continue;
        }else
            //up
            if(maze[indexOfi - 1][indexOfj] != 1 && indexOfi - 1 >= 0){
                tileNumber--;
                maze[indexOfi][indexOfj] = 1;
                indexOfi = indexOfi - 1;
                printMaze(maze);
                continue;
        }else
            //down
            if(maze[indexOfi + 1][indexOfj] != 1 && indexOfi + 1 < 12){
                tileNumber--;
                maze[indexOfi][indexOfj] = 1;
                indexOfi = indexOfi + 1;
                printMaze(maze);
                continue;
        }else
            //right
            if(maze[indexOfi][indexOfj + 1] != 1 && indexOfj + 1 < 12){
                tileNumber--;
                maze[indexOfi][indexOfj] = 1;
                indexOfj = indexOfj + 1;
                printMaze(maze);
                continue;
        }
    }
}