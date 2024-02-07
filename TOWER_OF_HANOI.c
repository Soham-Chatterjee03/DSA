#include<stdio.h>
void move(int n,char SOURCE,char DESTINATION,char SPARE);
int main(){
    int n;
    printf("Ente the number of Rings: ");
    scanf("%d",&n);
    move(n,'A','B','C');

    return 0;

}
void move(int n,char SOURCE,char DESTINATION,char SPARE){
    if(n==1){
        printf("\n move %c to %c ", SOURCE,DESTINATION);
    }
    else{
        move(n-1,SOURCE,DESTINATION,SPARE);
        move(1,SOURCE,SPARE,DESTINATION);
        move(n-1,DESTINATION,SPARE,SOURCE);
    }
}