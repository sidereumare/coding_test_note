#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
using namespace std;

class HtmlElement{
public:
    string name;
    string text;
    vector<HtmlElement> elements;

    static HtmlElement* build(const string& root_name){
        return new HtmlElement{root_name, ""};
    }
    //fluent builder
    //빌더 자신이 참조로 리턴
    HtmlElement* add_child_f(string child_name, string child_text){
        HtmlElement e{child_name, child_text};
        elements.emplace_back(e);
        return this;
    }

    string str(int indent = 0) const{
        ostringstream oss;
        oss<<setw(indent*4+name.length()-1)<<"<"<<name<<">"<<'\n';
        if(text.length()!=0){
            oss<<setw((indent+1)*4+text.length()-1)<<text<<'\n';
        }
        for(auto e: elements){
            oss<<e.str(indent+1);
        }
        oss<<setw(indent*4+name.length())<<"</"<<name<<">"<<'\n';
        return oss.str();
    }
    //생성자를 숨김
protected:
    HtmlElement(){}
    HtmlElement(const string& name, const string& text)
    :name(name), text(text){}
};

int main(){
    //build 메서드 사용을 강제
    auto e = HtmlElement::build("ul")
    ->add_child_f("li", "hello")
    ->add_child_f("li", "world");
    cout<<e->str()<<endl;
    return 0;
}