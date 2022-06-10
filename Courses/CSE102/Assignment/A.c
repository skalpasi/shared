#include<stdio.h>
#include <stdlib.h>
#include<string.h>

char g[8][8];
int vis[8][8][70];
int visG[8][8];

int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};

int knightok(int x, int y, int m) {
    return x >= 0 && y >= 0 && x < 8 && y < 8 && !vis[x][y][m] && g[x][y] == '.';
}

void rec1(int x, int y, int m) {
    if(m == 0) {
        visG[x][y] = 1;
        return;
    }

    vis[x][y][m] = 1;
    visG[x][y] = 1;

    // x++, y++
    for(int i = 0; i < 8; i++) {
        if(x + i < 8 && y + i < 8) {
            if(g[x + i][y + i] != '.') break;
            if(!vis[x + i][y + i][m - 1]) rec1(x + i, y + i, m - 1);
        }
    }   
    
    // x++, y--
    for(int i = 0; i < 8; i++) {
        if(x + i < 8 && y - i >= 0) {
            if(g[x + i][y - i] != '.') break;
            if(!vis[x + i][y - i][m - 1]) rec1(x + i, y - i, m - 1);
        }
    }  

    // x--, y++
    for(int i = 0; i < 8; i++) {
        if(x - i >= 0 && y + i < 8) {
            if(g[x - i][y + i] != '.') break;
            if(!vis[x - i][y + i][m - 1]) rec1(x - i, y + i, m - 1);
        }
    }  

    // x--, y--
    for(int i = 0; i < 8; i++) {
        if(x - i >= 0 && y - i >= 0) {
            if(g[x - i][y - i] != '.') break;
            if(!vis[x - i][y - i][m - 1]) rec1(x - i, y - i, m - 1);
        }
    }  
} 

void rec2(int x, int y, int m) {
    if(m == 0) {
        visG[x][y] = 1;
        return;
    }

    vis[x][y][m] = 1;
    visG[x][y] = 1;

    for(int i = 0; i < 8; i++) {
        if(knightok(x + dx[i], y + dy[i], m - 1)) {
            rec2(x + dx[i], y + dy[i], m - 1);
        }
    }
}

void rec3(int x, int y, int m) {
    if(m == 0) {
        visG[x][y] = 1;
        return;
    }

    vis[x][y][m] = 1;
    visG[x][y] = 1;

    // x++
    for(int i = 0; i < 8; i++) {
        if(x + i < 8) {
            if(g[x + i][y] != '.') break;
            if(!vis[x + i][y][m - 1]) rec3(x + i, y, m - 1);
        }
    }  

    // x--
    for(int i = 0; i < 8; i++) {
        if(x - i >= 0) {
            if(g[x - i][y] != '.') break;
            if(!vis[x - i][y][m - 1]) rec3(x - i, y, m - 1);
        }
    }  

    // y++ 
    for(int i = 0; i < 8; i++) {
        if(y + i < 8) {
            if(g[x][y + i] != '.') break;
            if(!vis[x][y + i][m - 1]) rec3(x, y + i, m - 1);
        }
    } 

    // y-- 
    for(int i = 0; i < 8; i++) {
        if(y - i >= 0) {
            if(g[x][y - i] != '.') break;
            if(!vis[x][y - i][m - 1]) rec3(x, y - i, m - 1);
        }
    } 
} 

int main() {
    for(int i = 0; i < 8; i++) {
        scanf("%s", g[i]);
    }

    int xb, yb, xk, yk, xr, yr, m;
    scanf("%d %d", &xb, &yb);
    scanf("%d %d", &xk, &yk);
    scanf("%d %d", &xr, &yr);
    scanf("%d", &m);
    
    int bishop = 0, knight = 0, rook = 0;

    memset(vis, 0, 64 * 70 * sizeof(int));
    memset(visG, 0, 64 * sizeof(int));
    if(g[xb - 1][yb - 1] == '.') rec1(xb - 1, yb - 1, m);

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(visG[i][j]) bishop++;
        }   
    }

    memset(vis, 0, 64 * 70 * sizeof(int));
    memset(visG, 0, 64 * sizeof(int));
    if(g[xk - 1][yk - 1] == '.') rec2(xk - 1, yk - 1, m);

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(visG[i][j]) knight++;
        }
    }

    memset(vis, 0, 64 * 70 * sizeof(int));
    memset(visG, 0, 64 * sizeof(int));
    if(g[xr - 1][yr - 1] == '.') rec3(xr - 1, yr - 1, m);

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(visG[i][j]) rook++;
        }
    }

    printf("%d %d %d", bishop, knight, rook);
    return 0;
}