//새로운 타입을 만들지 않고도 새로운 속성을 합성가능하게 만드는 패턴
#include <iostream>

using namespace std;
class base{
public:
    virtual string str() const {return "base";}
};

template <typename T>
class Color: public T{
public:
    //base가 아닐경우 체크
    static_assert(is_base_of<base, T>::value,
        "template argument must be a base");

    template<typename...Args>
    Color(string c, Args ...args): color{c},
    T(forward<Args>(args)...) {}
    string color;
    
    string str() const override{
        return T::str()+color;
    }
};

int main(){
    Color<Color<base>> mixin{"red", "blue"};
    cout<<mixin.str();
    return 0;
}
