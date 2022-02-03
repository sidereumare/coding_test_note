#include <iostream>
#include <string>
using namespace std;

class Person{
    //주소
    string street_address, post_code, city;

    //직업
    string company_name, position;
    int annual_income = 0;

    Person() {}
};

class PersonBuilderBase{
protected:
    Person& person;
    explicit PersonBuilderBase(Person& person)
    :person{ person } {   }

public:
    operator Person(){
        return move(person);
    }

    PersonAddressBuilder lives() const;
    PersonJobBuilder works() const;
};
class PersonAddressBuilder : public PersonBuilderBase{
    typedef PersonAddressBuilder self;
public:
    explicit PersonAddressBuilder(Person& person)
    : PersonBuilderBase{person} {  }

    self& at(string street_address){
        person.street_address = street_address;
        return *this;
    }
    self& with_postcode(string post_code){
        person.post_code = post_code;
        return *this;
    }
    self& in(string city){
        person.city = city;
        return *this;
    }
};
class PersonBuilder: public PersonBuilderBase{
    Person p; //생성 중인 객체
public:
    PersonBuilder() : PersonBuilderBase{p} {}
};