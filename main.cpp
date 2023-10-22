#include <iostream>


using namespace std;

template <class T>
class dynamicArray{
private:
    int size;
    T * head;
    float grow = 1.5;
public:
    int length;

    dynamicArray(){
        head = new T[5];
        size = 5;
        length = 0;
    }
    ~dynamicArray(){
        delete [] head;
    }

    bool checkSize(){
        return size*0.8 < length;
    }

    void add(T value){
        if(checkSize()) growSize();
        head[length]= value;
        length++;
    }

    void growSize(){
        size= size*grow;
        auto *newHead = new T[size];

        for(int i = 0; i<length;i++){
            newHead[i] = head[i];
        }
        delete [] head;
        head = newHead;
    }


    void clear(){
        delete [] head;
        length = 0;
        size = 5;
    }

    int index(int index){
       if(length<= index){
           cout<<"Index out of range!";
           return -1;
       }
        return head[index];
    }

    void change(int index, T newValue){
        if(length<= index){
            cout<<"Index out of range!";
            return;
        }
        head[index] = newValue;

    }


    void toString(){
        cout<<"Size: "<< size<< ". Length: "<<length<<endl;
        for(int i = 0; i<length; i++){
            cout<<"Value: "<< head[i]<<endl;
        }
    }
    int getSize(){
        return this->size;
    }

    void sort(bool (*cmp)(T,T)){
        for(int i = 0; i<length;i++){
            for(int j = 0; j<length-i-1; j++){
                if(cmp(head[j],head[j+1])){
                    int temp = head[j];
                    head[j] =  head[j+1];
                    head[j+1] = temp;
                }
            }
        }
    }
};

template <class T>
T getRandom(){
    srand(time(0));
    return rand() % 1000;
}

template <class T>
bool compare(T first, T second){
    return first > second;
}


int main() {
    auto * first = new dynamicArray<int>();
    for(int i = 0; i< 17; i++){
        first->add(i*2);
    }
first->change(1, 54);
    first->toString();
    first->sort(compare);
    first->toString();
    return 0;
}
