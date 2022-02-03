#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

class HtmlElement{
public:
    string name;
    string text;
    vector<HtmlElement> elements;

    HtmlElement(){}
    HtmlElement(const string& name, const string& text)
    :name(name), text(text){}

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
};

class HtmlBuilder{
public:
    HtmlElement root;

    HtmlBuilder(string root_name){root.name = root_name;}

    //simple builder
    void add_child(string child_name, string child_text){
        HtmlElement e{child_name, child_text};
        root.elements.emplace_back(e);
    }
    //fluent builder
    //빌더 자신이 참조로 리턴
    HtmlBuilder* add_child_f(string child_name, string child_text){
        HtmlElement e{child_name, child_text};
        root.elements.emplace_back(e);
        return this;
    }

    string str() {return root.str();}
};
int main(){
    //빌더 사용x
    string words[] = {"hello", "world"};
    HtmlElement list{"ul", ""};
    for(auto w: words){
        list.elements.emplace_back(HtmlElement{"li", w});
    }
    cout<<list.str()<<endl;

    //빌더 사용
    HtmlBuilder builder{"ul"};
    builder.add_child("li", "hello");
    builder.add_child("li", "world");
    cout<<builder.str()<<endl;
    //fluent interface 사용
    HtmlBuilder builderf{"ul"};
    builderf.add_child_f("li", "hello")->add_child_f("li", "world");
    cout<<builder.str()<<endl;

    
    return 0;
}