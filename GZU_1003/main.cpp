
#include <stdio.h>


int ip[1000][4];
int yan[4];
int wang[1000][4];
int temp[1000][4];

int main(){
//freopen("data.in","r",stdin);
int t;
int w=1;
while(scanf("%d",&t)!=EOF){
  while(t--){
     int n,m;
     scanf("%d%d",&n,&m);
     for(int i=0;i<n;i++){
        scanf("%d.%d.%d.%d",&ip[i][0],&ip[i][1],&ip[i][2],&ip[i][3]);
       }
    printf("Case #%d:\n",w++);
    for(int i=0;i<m;i++){
       scanf("%d.%d.%d.%d",&yan[0],&yan[1],&yan[2],&yan[3]);
       int len=0;
       for(int j=0;j<n;j++){
           wang[j][0]=yan[0]&ip[j][0];
           wang[j][1]=yan[1]&ip[j][1];
           wang[j][2]=yan[2]&ip[j][2];
           wang[j][3]=yan[3]&ip[j][3];
          }
        for(int z=0;z<n;z++){
            int flag=0;
            for(int x=0;x<len;x++){
                //flag=0;
                if((wang[z][0]==temp[x][0])&&(wang[z][1]==temp[x][1])&&(wang[z][2]==temp[x][2])&&(wang[z][3]==temp[x][3])){
                       flag=1;
                       break;
                   }
            }
            if(!flag){
                temp[len][0]=wang[z][0];
                temp[len][1]=wang[z][1];
                temp[len][2]=wang[z][2];
                temp[len][3]=wang[z][3];
                len++;
              }
        }
        printf("%d\n",len);
    }
  }
}
return 0;
}
