#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Tag{
public:
    string name;
    string text;
    vector<Tag> children;
    vector<pair<string, string> attributes;

    friend ostream& operator<<(ostream& os, const Tag& tag){
        os<<"<"<<name<<">"<<'\n';
        if(text.length()!=0){
            os<<text<<'\n';
        }
        for(auto e: children){
            os<<e;
        }
        os<<"</"<<name<<">"<<'\n';
        return oss.str();
    }
};

int main(){

    return 0;
}