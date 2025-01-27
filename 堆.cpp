#include <iostream>
#include <vector>

template <typename T>
class SmallHeap{
    private:std::vector<T> heap;long long HeapSize;
    public:
        SmallHeap() {};
        SmallHeap(long long n) {build(n);};
        SmallHeap(std::vector<T> &aim) {build(aim,aim.begin(),aim.end());} 
        SmallHeap(std::vector<T> &aim,typename std::vector<T>::iterator begin,typename std::vector<T>::iterator end)
        {build(aim,begin,end);} 

        void init(){
            HeapSize=0;
        }

        void build(long long n){
            heap.resize(n+10);
            init();
        }

        void build(std::vector<T> &aim,typename std::vector<T>::iterator begin,typename std::vector<T>::iterator end){
            build(aim.size());
            for(auto p=begin;p!=end;++p) push(*p);
        }

        void up(long long u){
            if(u/2&&heap[u/2]>heap[u])
                std::swap(heap[u/2],heap[u]),up(u/2);
        }
        void down(long long u){
            T t=u;
            if(u*2<=HeapSize&&heap[t]>heap[2*u]) t=2*u;
            if(u*2+1<=HeapSize&&heap[t]>heap[2*u+1]) t=2*u+1;
            if(t!=u)
            {
                std::swap(heap[u],heap[t]);
                down(t);
            }
        }

        void push(T u){
            heap[++HeapSize]=u;
            up(HeapSize);
        }

        T pop(){
            if(HeapSize==0) throw std::out_of_range("ERROR:Heap is empty");
            T tmp=heap[1];
            std::swap(heap[1],heap[HeapSize]);
            --HeapSize;down(1);
            return tmp;
        }

        T top(){
            if(HeapSize==0) throw std::out_of_range("ERROR:Heap is empty");
            return heap[1];
        }

        long long size(){
            return HeapSize;
        }

        void test(){
            for(int i=0;i<=HeapSize;i++)
            std::cout<<heap[i]<<" ";
            puts("");
        }
};

int main()
{
    int n,m;
    std::cin>>n>>m;
    std::vector<int> arr(n);
    for(int i=0;i<n;i++) std::cin>>arr[i];
    SmallHeap<int> hp(arr);
    //std::cout<<hp.size()<<std::endl;
    //hp.test();
    for(int i=1;i<=m;i++)
    std::cout<<hp.top()<<" ",hp.pop();//<<hp.pop()<<std::endl;
    return 0;
}

