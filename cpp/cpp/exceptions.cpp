#include <iostream>
#include <exception>

class MyException : public std::exception
{
public:
    int x;
    MyException() { x= 2;}
    
    virtual const char * what() const throw()
        {
            return "myex";
        }
private:
    //int x;
    //MyException(MyException const & me) {} // exception classes should
    //have this public
    MyException& operator = (MyException const & me) {}
};

class B
{
public:
    ~B() { MyException me; std::cout << "B\n";  throw me; }
};

class A
{
public:
    A() { b = B(); }
    ~A() { MyException me; std::cout << "A\n"; throw me; }
private:
    B b;
};

int main()
{
    /*try
    {
        MyException me;
        throw me;
    }
    catch(MyException & myex)
    {
        std::cout << myex.what() << std::endl;
        }*/

    /*try
    {
        A a; //core dump expected
    }
    catch(std::exception & e)
    {
        std::cout << e.what() << std::endl;
        }*/

    MyException me;
    MyException mee = me; //here copy constructor is called actually

    
    //mee = me; //compile erroe but not above

    std::cout << mee.x << "|" << me.x << std::endl;
    
    return 0;
}
