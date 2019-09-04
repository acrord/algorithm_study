#include <stdio.h>
using namespace std;
int main(){
    int k;

    while(1){
        scanf("%d", &k);
        if(k==0) break;
        int list[50];
        for(int i = 0; i<k ; i++){
            scanf("%d", &list[i]);
        }
        for(int a = 0 ; a<k; a++){
            for(int b = a+1 ; b<k; b++){
                if(a>=b) continue;
                for(int c = b+1 ; c<k; c++){
                    if(b>=c || a>=c) continue;
                    for(int d = c+1 ; d<k; d++){
                        if(c>=d || b>=d || a>=d) continue;
                        for(int e = d+1 ; e<k; e++){
                            if(d>=e || c>=e || b>=e || a>=e) continue;
                            for(int f = e+1 ; f<k; f++){
                                if(e>=f || d>=f || c>=f || b>=f || a>=f) continue;
                                printf("%d %d %d %d %d %d\n",list[a],list[b],list[c],list[d],list[e],list[f]);
                            }
                        }
                    }
                }
            }
        }
        printf("\n");
            
    }
}