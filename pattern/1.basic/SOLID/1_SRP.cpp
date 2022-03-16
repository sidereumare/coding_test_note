//SRP: Single Responsibility Principle
//단일 책임 원칙, 클래스를 변경해야 하는 이유는 하나 뿐이어야 함
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Jornal{
public:
    string title;
    vector<string> entries;

    explicit Jornal(const string& title): title{title} {}
    void add(const string& entry){
        entries.emplace_back(entry);
    }
};

class PersistenceManager{
    static void save(const Jornal& j, const string& filename){
        ofstream ofs(filename);

        for(auto& s: j.entries){
            ofs<<s<<endl;
        }
    }
};
//위의 클래스 함수인 save가 jornal에 들어가면 srp원칙을 어긴것이 됨
int main(){
    return 0;
}