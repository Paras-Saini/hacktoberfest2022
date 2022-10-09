#include <bits/stdc++.h>
using namespace std;
class vectorr
{
    private:
        int capacity;
        int lastIndex;
        int *ptr;
    public:
        void createArray(int cap)
        {
            capacity = cap;
            lastIndex = -1;
            ptr = (int *)malloc(sizeof(int) * cap);
        }

        void doubleArray()
        {
            int *t, i;
            this->capacity *= 2;
            t = (int *)malloc(sizeof(int) * this->capacity);
            for (i = 0; i <= this->lastIndex; i++)
                t[i] = this->ptr[i];
            free(this->ptr);
            this->ptr = t;
        }

        void insert(int index, int data)
        {
            if (index < 0 || index > this->lastIndex + 1)
                printf("Invalid Index\n");
            else if (this->capacity - 1 == this->lastIndex)
            {
                this->doubleArray();
                this->ptr[index] = data;
                this->lastIndex += 1;
            }
            else
            {
                for (int i = this->lastIndex; index <= i; i--)
                {
                    this->ptr[i + 1] = this->ptr[i];
                }
                this->ptr[index] = data;
                this->lastIndex += 1;
            }
        }

        void printArray()
        {
            for (int i = 0; i <= this->lastIndex; i++)
                printf("%d ", this->ptr[i]);
            printf("\n");
        }

        void append(int data){
            if(this->capacity-1==this->lastIndex){
                this->doubleArray();
                this->ptr[this->lastIndex]=data;
            }
            else{
                this->lastIndex+=1;
                this->ptr[this->lastIndex];
            }
        }

        int getItem(int index){
            if(index>=0&&index<=this->lastIndex)
                return this->ptr[index];
            return -1;
        }

        int count(){
            return this->lastIndex+1;
        }

        void removeItem(int index){
            if(index<0||index>this->lastIndex+1)
                printf("Invalid Index\n");
            else if(this->lastIndex==-1)
                printf("Array is Empty\n");
            else{
                for(int i=index;i<=this->lastIndex;i++){
                    this->ptr[i]=this->ptr[i+1];
                }
                this->lastIndex-=1;
            }
        }

        int searchItem(int item){
            for(int i=0;i<=this->lastIndex;i++){
                if(this->ptr[i]==item)
                    return i;
                return -1;
            }   
        }

        void release(){
            free(this->ptr);
            free(this);
        }
};

int main()
{
    vectorr v;
    v.createArray(5);
    v.insert(0, 110);
    v.insert(1, 120);
    v.insert(2, 140);
    v.insert(3, 170);
    v.insert(4, 190);
    v.insert(5, 100);
    v.printArray();
    return 0;
}