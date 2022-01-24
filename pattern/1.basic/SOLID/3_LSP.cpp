//LSP: Liskov Substitution Principle(리스코프 치환 원칙)
//어떤 자식 객체에 접근할 때 그 부모 객체의 인터페이스로 
//접근하더라도 아무런 문제가 없어야 한다는 것
#include <iostream>

using namespace std;

class Rectangle{
protected:
    int width, height;
public:
    Rectangle(const int width, const int height)
    :width{width}, height{height}{}

    int get_width()const {return width;}
    virtual void set_width(const int width){ this->width = width;}
    int get_height()const {return height;}
    virtual void set_height(const int height){ this->height = height;}
    int area() const {return width*height;}
};

class Square : public Rectangle{
public:
    Square(int size):Rectangle(size, size){}
    void set_width(const int width) override{
        this->width = height = width;
    }
    void set_height(const int height)override{
        this->height = width = height;
    }
};

//서브 클래스를 부모 클래스로 이용할 때 문제가 발생함
void process(Rectangle& r){
    int w = r.get_width();
    r.set_height(10);
    cout<<"expected area = "<< (w*10)<<", got "<<r.area()<<endl;
}

int main(){
    Square s{5};
    process(s);
    return 0;
}