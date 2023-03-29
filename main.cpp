#include <iostream>
#include <memory>
#include <string>
template<class T>
class Iterator{
public:
    T * def_it = nullptr;
    void adr(T * arr) {
        def_it = arr;
    }

};
template<class T>
class vector : public Iterator<T>{
private:
    size_t cap = 1;
    size_t sz = 0;
public:
    T * arr;
public:
    vector(){
        cap=1;
        sz = 0;
        arr = new T[1];
        Iterator<T>::adr(arr);
        //Iterator<T> def_it = arr;
    }
    vector(size_t n): cap(n), sz(n),arr(new T[n]){
        Iterator<T>::adr(arr);
    }
    void resize(size_t new_size){
        if(new_size<sz){
            sz = new_size;
            return;
        }
        if(new_size==sz){
            return;
        }
            reserve(new_size);
        sz = new_size;
    }
    T& at(size_t index){
        return arr[index];
    }
    T* data(){
        return arr;
    }
    int size(){
        return sz;
    }
    int capacity(){
        return cap;
    }
    Iterator<T> begin(){
        return Iterator<T>::def_it;
    }
    T& front(){
        return arr[0];
    }
    T& back(){
        return arr[sz-1];
    }
    void reserve(size_t arg){
        if(arg == cap){
            return;
        }
        if(arg<cap){
            cap = arg;
        }
        int8_t * temp = new int8_t [sizeof(T)*arg];
        T * temp2 = reinterpret_cast<T*>(temp);
        //delete[] temp;
        std::uninitialized_move(arr,arr+size(),temp2);
        arr = temp2;
        //delete[] temp2;
        cap = arg;
    };
    void push_back(const T& arg){
        if(sz==cap){
            reserve(cap*2);
            std::cout<<"\nreserved, cap = "<<cap<<"\n";
        }
        arr[sz]= arg;
        sz++;
    }


};
class tmp{
public:
    char t='0';
    int i=0;
    std::string e = "0";
};
int main() {
vector<tmp> a;
    std::cout<<a.size()<<" "<<a.capacity()<<"\n";
//a.push_back('a');
    std::cout<<a.size()<<" "<<a.capacity()<<"\n";
//a.push_back('b');
    std::cout<<a.size()<<" "<<a.capacity()<<"\n";
//a.push_back('c');
std::cout<<a.size()<<" "<<a.capacity()<<"\n";
//std::cout<<a.at(1);
a.resize(10);
std::cout<<a.size()<<" "<<a.capacity()<<"\n";
std::cout<<a.at(1).t;
//std::cout<<a.at(11);







}
