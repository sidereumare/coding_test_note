#include <ctime>
#include <iostream>
using namespace std;

int main(){
    time_t timer = time(NULL);
    struct tm* t = localtime(&timer);
    string mon = t->tm_mon<9?("0"+to_string(t->tm_mon+1)):to_string(t->tm_mon);
    string day = t->tm_mday<10?("0"+to_string(t->tm_mday)):to_string(t->tm_mday);
    cout<<t->tm_year+1900<<'-'<<mon<<'-'<<day;
    return 0;
}