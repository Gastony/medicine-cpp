#include <iostream>
#include <limits>
#include <fstream>
#include <string>

void InputwithCin()
{
    int i = 0;
    while (!(std::cin >> i) || i == -1)
    {
        std::cout << "bad\n"; //"\n" does not flush output buffer
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cout << "i=" << i << std::endl; //std::endl flushes output
                                         //buffer after putting
                                         //newline
    //std::flush flushes the output buffer
}

class X
{
public:
    X(std::string x) : x(x) {}
    friend std::ostream& operator<< (std::ostream& os, const X & x);
    friend std::istream& operator>> (std::istream& is, X & x);
    std::string get() const { return x; }
private:
    std::string x;
};

std::ostream& operator<< (std::ostream& os, const X & x)
{
    os << x.x;
    return os;
}

std::istream& operator>> (std::istream& is, X & x)
{
    return is >> x.x; 
}

int main()
{
    //InputwithCin();

    X x("swargam");
    std::cout << x << "\n" << std::flush; //play on std::endl

    
    //std::cin >> x;
    //std::cout << x << "\n" << std::flush;

    std::ifstream inf("test.dat", std::ios::in);
    if (inf.is_open())
    {
        std::ofstream opf("ot.dat", std::ios::out);
        
        std::string line;
        while (inf.good())
        {
            getline(inf, line);
            size_t pos = std::string::npos;
            if (!line.empty())
            {
                std::cout << line  << std::endl;
                pos = line.find(',');
                line.replace(pos, 1, " ");
                if (opf.good())
                {
                    opf << line << "\n";
                }
            }
        }
        
        inf.close();
    }
        
    return 0;
}
