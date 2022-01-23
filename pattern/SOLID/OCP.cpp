//확장에는 열러있고, 변경에는 닫혀 있어야 함
#include <iostream>

using namespace std;

class base{
public:
    virtual void sell(){};
};

class clark1: public base{
    void sell() override{
        cout<<"점원 1"<<endl;
    }
};

int main(){
    base* b = new clark1();
    b->sell();
    return 0;
}
//위 예제는 인터페이스를 사용하여 다른 점원이 추가 되었을때
//클래스를 추가함으로 써 기존의 클래스는 수정하지 않아도 됨