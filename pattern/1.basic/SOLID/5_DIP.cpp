//DIP:Dependency Inversion Principle(의존성 역전 원칙)
//상위 모듈이 하위 모둘에 종속성을 가져서는 안된다, 양쪽 모두 추상화에 의존해야 한다.
//추상화가 세부 사항에 의존해서는 안 된다. 세부 상항이 추상화에 의존해야 한다.

#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>
#include <boost/bind.hpp>

using namespace std;

class ILogger{
public:
    virtual void Log(const string& s) = 0;
    virtual ~ILogger() {}
};

struct ConsoleLogger : ILogger
{
 void Log(const string& s) override
 {
  cout << "LOG: " << s.c_str() << endl;
 }
};

struct Car
{
 shared_ptr<ILogger> mLogger;
 
 Car(shared_ptr<ILogger> logger) : mLogger(logger)
 {
  mLogger->Log("making a car");
 }
};
 
int main()
{
 auto injector = di::make_injector(
  di::bind<ILogger>().to<ConsoleLogger>()
 );
  
 auto car = injector.create<Car>();
}