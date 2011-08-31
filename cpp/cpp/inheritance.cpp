#include <iostream>
using namespace std;

class Base
{
public:
    Base () { } //calling f() in constructor didnt call derived class f()
    void p() { f(); }
    int l;
protected:
    virtual void g() { cout << "protected virtual base\n"; }
    void k(int l) {}
    //virtual int n();
private:
    virtual void f() { cout << "private virtual base\n"; g(); } //private virtual
};

class Derived: public Base
{
public:
    using Base::k;
    void k(std::string s) {k(s.size());} // haha k from Base is hidden
                                         // without above line
protected:
    virtual void g() { cout << "protected virtual derived\n"; }
    
private:
    void f() { cout << "private virtual derived\n"; g(); }
};

class Leaf: private Base //public and protected become private
{
public:
    using Base::l;
    void j() { this->l = 2; } //to make l accessible in TestLeaf
};

class PLeaf: protected Base // public and protected become protected
{
};

class TestLeaf: public Leaf
{
public:
     void j() { this->l = 2; }
};

int main()
{
    Base b;
    b.p();

    Derived d;
    d.p();
    d.k("hello");

    return 0;
}
