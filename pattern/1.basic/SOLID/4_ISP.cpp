//ISP: Interface Segregation Principle(인터페이스 분리 원칙)
//한 덩어리의 복잡한 인터페이스를 목적에 따라 구분하여 인터페이스의 모든 구현을 강제하지 않고
//실제 필요한 인터페이스만 구현 할 수 있도록 하는 것
#include <iostream>
#include <vector>
using namespace std;
class Document{
public:
    vector<string> contents;
};
class IMachine{
public:
    virtual void print(vector<Document*> docs) = 0;
    virtual void fax(vector<Document*> docs) = 0;
    virtual void scan(vector<Document*> docs) = 0;
};
//아래 클래스는 fax와 scan이 구현되지 않아 오류
class MyFavouritePrinter: IMachine
{
public:
    void print(vector<Document*> docs) override;
};
//위의 세가지 동작은 서로 분리가능한 별개의 동작이므로 
//이런 경우 인터페이스를 분리하여야 함