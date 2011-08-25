#include <iostream>
using namespace std;
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>

int main()
{
    std::vector<std::string> input;

    std::string tmp;
    while (std::cin >> tmp)
    {
        input.push_back(tmp);
    }

    std::ofstream out("out.txt", std::ios::out);
    for (std::vector<std::string>::const_iterator iter = input.begin();
         iter != input.end();
         ++iter)
    {
        std::cout << *iter << "\n";
        
        out << (*iter).size() << "|" << *iter;
    }
    out.close();

    std::vector<std::string> output;
    std::ifstream in("out.txt", std::ios::in);
    if (in.is_open())
    {
        std::string tmp;
        if (!in.eof())
        {
            getline(in, tmp);
            size_t pos;
            int length = 0;
            std::string str;
            //std::stringstream ss;
            
            while (!tmp.empty())
            {
                pos = tmp.find('|');
                if (pos != std::string::npos)
                {
                    //std::cout << pos << "(" ;
                    length = atoi(tmp.substr(0, pos).c_str());
                    str = tmp.substr(pos+1, length);     
                    tmp = tmp.substr(pos+str.size() + 1);

                    //std::cout << length << "(" << str << "(" << tmp <<
                    //std::endl;
                    
                    output.push_back(str);
                }
                //ss.str().clear();
            }
        }

        in.close();
    }

    for (std::vector<std::string>::const_iterator iter = output.begin();
         iter != output.end();
         ++iter)
    {
        std::cout << *iter << "\n";
    }

    return 0;
}
