//Curiously Recurring Template Pattern
//컴파일 타임에 베이스 클래스의 구현부에서 자식 클래스의 this 포인터를 사용가능하게 함
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class SomeBase{
public:
    void foo(){
        for(auto& item: static_cast<T*>(this)->items){
            cout<<item;
        }
    }
};

class Foo: public SomeBase<Foo>{
public:
    vector<int> items;
    Foo(){
        for(int i = 0; i<10; i++){
            items.emplace_back(i);
        }
    }
};
//------------------------------
//CRTP와 비슷한 기능: virtual
class SomeBase1{
public:
    virtual void foo() = 0;
    virtual ~SomeBase1(){ };
};

class Foo1: public SomeBase1{
public:
    vector<int> items;
    Foo1(){
        for(int i = 0; i<10; i++){
            items.emplace_back(i);
        }
    }
    virtual void foo() override{
        for(auto& item: items){
            cout<<item;
        }
    }
};

int main(){
    Foo *f = new Foo();
    SomeBase<Foo> *b = dynamic_cast<SomeBase<Foo>*>(f);
    b->foo();
    //------------------------
    Foo1 *f1 = new Foo1();
    SomeBase1 *b1 = dynamic_cast<SomeBase1*>(f1);
    b1->foo();

    return 0;
}