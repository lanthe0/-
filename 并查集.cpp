#include <iostream>
#include <vector>

//并查集类
//功能：支持基本的合并以及溯祖操作，支持查询连通块大小以及块的个数，支持下标溯祖
//函数列表： init   初始化大小为n的并查集（实际创建n+1大小，兼容0索引以及1索引）
//         same   查询俩个元素是否位于同一集合
//         find   溯祖
//         size   返回该元素所在集合的元素个数
//         count  返回集合个数
//         merge  合并俩个集合
//         []     溯祖
//                                  ——————code by lanthe0 2025.1.24
class UnionFindSet
{
    private: std::vector<int> parent,_size;int Ufs_Size;
    public:
        UnionFindSet() {};
        UnionFindSet(int n) {init(n);};

        void init(int n){
            parent.resize(n+1);_size.resize(n+1,1);Ufs_Size=n;
            for(int i=0;i<=n;i++) parent[i]=i;
        }

        int find(int x) {return parent[x]==x?parent[x]:find(parent[x]);}

        bool same(int x,int y) {return find(x)==find(y);}

        int size(int x) {return _size[find(x)];}
        int count() {return Ufs_Size;}
        
        bool merge(int x,int y){
            x=find(x),y=find(y);
            if(x==y) return false;
            _size[x]+=_size[y];
            parent[y]=x;Ufs_Size--;
            return true;
        }

        int operator[](int x){
            return find(x);
        }        
};

int main()
{
    UnionFindSet ufs(10);
    int x,y;
    while(scanf("%d %d",&x,&y)==2&&x!=-1)
    {
        ufs.merge(x,y);
    }

    while(scanf("%d %d",&x,&y)==2&&x!=-1)
    {
        if(ufs.same(x,y)) std::cout<<"Yes"<<std::endl;
        else std::cout<<"No"<<std::endl;
    }
    while(scanf("%d",&x)==1&&x!=-1) std::cout<<ufs.size(x)<<" ";
    std::cout<<std::endl<<ufs.count();
    return 0;
}