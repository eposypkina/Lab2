#include "unique_ptr.h"


struct Foo {
    Foo() { std::cout << "Foo::Foo\n"; }
    ~Foo() { std::cout << "Foo::~Foo\n"; }
};
 

int main()
{
    //Использование get
    unique_ptr<int> p1( new int(10) );
    int *p=p1.get();
    std::cout<<*p<<std::endl;

    //Использование reset
    int *p3=new int(6);
    unique_ptr<int> p4(p3);
    p4.reset();
    std::cout<<p4.get()<<std::endl;
    std::cout<<*p3<<std::endl;

    //Создание  unique_ptr типа Foo
    unique_ptr<Foo> p5(new Foo);  

    return 0;
}