#include<stdio.h>
#include<vector>
using namespace std;
int rotation[5]={2, 1, 4, 2, 4};
int symmetric[5]={1, 1, 2, 2, 1};
int n,m;
int mat[500][500];
int switchCase(int i, int j, int k){
    int max = 0, temp = 0;
    switch(i){
        case 0: //긴거
        switch(k){
            case 0:
            for(int a = 0;a<n;a++){
                for(int b = 0; b<m-3; b++){
                    temp = 0;
                    temp += (mat[a][b]+mat[a][b+1]+mat[a][b+2]+mat[a][b+3]);
                    if(max<temp) max = temp;
                }
            }
            break;
            case 1:
            for(int a = 0;a<m;a++){
                for(int b = 0; b<n-3; b++){
                    temp = 0;
                    temp += (mat[b][a]+mat[b+1][a]+mat[b+2][a]+mat[b+3][a]);
                    if(max<temp) max = temp;
                }
            }
            break;
        }
        break;
        case 1: // 네모
        switch(k){
            case 0:
            for(int a = 0;a<n-1;a++){
                for(int b = 0; b<m-1; b++){
                    temp = 0;
                    temp += (mat[a][b]+mat[a][b+1]+mat[a+1][b]+mat[a+1][b+1]);
                    if(max<temp) max = temp;
                }
            }
            break;
        }
        break;
        case 2: // 기역
        switch(j){
            case 0:
            switch(k){
                case 0:
                for(int a = 0;a<n-1;a++){
                    for(int b = 0; b<m-2; b++){
                        temp = 0;
                        temp += (mat[a][b]+mat[a][b+1]+mat[a][b+2]+mat[a+1][b+2]);
                        if(max<temp) max = temp;
                    }
                }
                break;
                case 1:
                for(int a = 0;a<n-2;a++){
                    for(int b = 0; b<m-1; b++){
                        temp = 0;
                        temp += (mat[a+2][b]+mat[a+2][b+1]+mat[a+1][b+1]+mat[a][b+1]);
                        if(max<temp) max = temp;
                    }
                }
                break;
                case 2:
                for(int a = 0;a<n-1;a++){
                    for(int b = 0; b<m-2; b++){
                        temp = 0;
                        temp += (mat[a][b]+mat[a+1][b]+mat[a+1][b+1]+mat[a+1][b+2]);
                        if(max<temp) max = temp;
                    }
                }
                break;
                case 3:
                for(int a = 0;a<n-2;a++){
                    for(int b = 0; b<m-1; b++){
                        temp = 0;
                        temp += (mat[a][b]+mat[a+1][b]+mat[a+2][b]+mat[a][b+1]);
                        if(max<temp) max = temp;
                    }
                }
                break;
            }
            break;
            case 1:
            switch(k){
                case 0:
                for(int a = 0;a<n-1;a++){
                    for(int b = 0; b<m-2; b++){
                        temp = 0;
                        temp += (mat[a][b]+mat[a][b+1]+mat[a][b+2]+mat[a+1][b]);
                        if(max<temp) max = temp;
                    }
                }
                break;
                case 1:
                for(int a = 0;a<n-2;a++){
                    for(int b = 0; b<m-1; b++){
                        temp = 0;
                        temp += (mat[a][b]+mat[a+1][b]+mat[a+2][b]+mat[a+2][b+1]);
                        if(max<temp) max = temp;
                    }
                }
                break;
                case 2:
                for(int a = 0;a<n-1;a++){
                    for(int b = 0; b<m-2; b++){
                        temp = 0;
                        temp += (mat[a][b+2]+mat[a+1][b]+mat[a+1][b+1]+mat[a+1][b+2]);
                        if(max<temp) max = temp;
                    }
                }
                break;
                case 3://
                for(int a = 0;a<n-2;a++){
                    for(int b = 0; b<m-1; b++){
                        temp = 0;
                        temp += (mat[a][b]+mat[a][b+1]+mat[a+1][b+1]+mat[a+2][b+1]);
                        if(max<temp) max = temp;
                    }
                }
                break;
            }
            break;
        }
        break;
        case 3://ㄹ
        switch(j){
            case 0:
            switch(k){
                case 0:
                for(int a = 0;a<n-1;a++){
                    for(int b = 0; b<m-2; b++){
                        temp = 0;
                        temp += (mat[a][b]+mat[a][b+1]+mat[a+1][b+1]+mat[a+1][b+2]);
                        if(max<temp) max = temp;
                    }
                }
                break;
                case 1:
                for(int a = 0;a<n-2;a++){
                    for(int b = 0; b<m-1; b++){
                        temp = 0;
                        temp += (mat[a][b]+mat[a+1][b]+mat[a+1][b+1]+mat[a+2][b+1]);
                        if(max<temp) max = temp;
                    }
                }
                break;
            }
            break;
            case 1:
            switch(k){
                case 0:
                for(int a = 0;a<n-1;a++){
                    for(int b = 0; b<m-2; b++){
                        temp = 0;
                        temp += (mat[a+1][b]+mat[a+1][b+1]+mat[a][b+1]+mat[a][b+2]);
                        if(max<temp) max = temp;
                    }
                }
                break;
                case 1:
                for(int a = 0;a<n-2;a++){
                    for(int b = 0; b<m-1; b++){
                        temp = 0;
                        temp += (mat[a][b+1]+mat[a+1][b+1]+mat[a+1][b]+mat[a+2][b]);
                        if(max<temp) max = temp;
                    }
                }
                break;
            }
            break;
        }
        break;
        case 4://ㅗ
        switch(k){
            case 0:
            for(int a = 0;a<n-1;a++){
                for(int b = 0; b<m-2; b++){
                    temp = 0;
                    temp += (mat[a][b+1]+mat[a+1][b]+mat[a+1][b+1]+mat[a+1][b+2]);
                    if(max<temp) max = temp;
                }
            }
            break;
            case 1:
            for(int a = 0;a<n-1;a++){
                for(int b = 0; b<m-2; b++){
                    temp = 0;
                    temp += (mat[a+1][b+1]+mat[a][b]+mat[a][b+1]+mat[a][b+2]);
                    if(max<temp) max = temp;
                }
            }
            break;
            case 2:
            for(int a = 0;a<n-2;a++){
                for(int b = 0; b<m-1; b++){
                    temp = 0;
                    temp += (mat[a][b]+mat[a+1][b]+mat[a+2][b]+mat[a+1][b+1]);
                    if(max<temp) max = temp;
                }
            }
            break;
            case 3:
            for(int a = 0;a<n-2;a++){
                for(int b = 0; b<m-1; b++){
                    temp = 0;
                    temp += (mat[a][b+1]+mat[a+1][b+1]+mat[a+2][b+1]+mat[a+1][b]);
                    if(max<temp) max = temp;
                }
            }
            break;
        }
        break;
    }
    return max;
}



int main(){
    int max=0, temp;
    scanf("%d %d", &n, &m);
    for(int i=0;i<n; i++){
        for(int j = 0 ; j<m;j++){
            scanf("%d", &mat[i][j]);
        }
    }
    for(int i = 0; i<5; i++){
        for(int j=0; j<symmetric[i];j++){
            for(int k = 0; k<rotation[i]; k++){
                temp = 0;
                temp = switchCase(i,j,k);
                if(max<temp) max = temp;
            }
        }
    }
    printf("%d\n", max);
}