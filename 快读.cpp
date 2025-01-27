#include <iostream>

int read(){
    char ch=getchar();int f=1,k=0;
    while(ch<48||ch>57) {if(ch=='-') f=-1;ch=getchar();}
    while(ch>=48&&ch<=57) {k=k*10+(ch-48);ch=getchar();}
    return f*k;
}

int main()
{
    int x=read();
    std::cout<<x;
    return 0;
}