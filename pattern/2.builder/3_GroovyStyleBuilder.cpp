#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>

using namespace std;

class Tag{
public:
    string name;
    string text;
    vector<Tag> children;
    vector<pair<string, string> > attributes;
    
    string str(int indent = 0) const{
        ostringstream oss;
        oss<<setw(indent*4+name.length()-1)<<"<"<<name<<">"<<'\n';
        if(text.length()!=0){
            oss<<setw((indent+1)*4+text.length()-1)<<text<<'\n';
        }
        for(auto e: children){
            oss<<e.str(indent+1);
        }
        oss<<setw(indent*4+name.length())<<"</"<<name<<">"<<'\n';
        return oss.str();
    }

    friend ostream& operator<<(ostream& os, const Tag& tag){
        os<<tag.str();
        return os;
    }
protected:
    Tag(const string& name, const string& text)
    : name{name}, text{text} {}

    Tag(const string& name, const vector<Tag>& children)
    : name{name}, children{children} {}
};
class P : public Tag{
public:
    explicit P(const string& text)
    : Tag{"p", text} {}

    P(initializer_list<Tag> children)
    : Tag("p", children) {}
};
class IMG: public Tag{
public:
    explicit IMG(const string& text)
    : Tag{"img", text} {}

    IMG(initializer_list<Tag> children)
    : Tag("img", children) {}
};
int main(){
    cout<<P{ IMG{"http://dfjsiljfdsilajsda"}, P{"dfjldjil"} }<<endl;
    return 0;
}