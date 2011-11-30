/* Top coder problem
   http://community.topcoder.com/stat?c=problem_statement&pm=6517
    Problem Statement for ParallelProgramming
Problem Statement
    	

You are programming the process scheduler for an operating system that controls many processors. The parallelism achieved by this new system is total, meaning that any number of processes can run at the same time without disturbing each other. Of course, certain processes may need some other processes to end before they start.

You will be given the execution time of each process as a int[], where the ith element is the number of milliseconds the ith process takes to complete execution. The information about precedences will be given as a String[] prec, where the jth character of the ith element is 'Y' if process j needs process i to be finished before executing itself and 'N' otherwise. Return the minimum number of milliseconds needed for all processes to be finished. If it's impossible for all the processes to finish, return -1.
 
Definition
    	
Class:	ParallelProgramming
Method:	minTime
Parameters:	int[], String[]
Returns:	int
Method signature:	int minTime(int[] time, String[] prec)
(be sure your method is public)
    
 
Constraints
-	time will contain between 1 and 50 elements, inclusive.
-	time and prec will contain the same number of elements.
-	Each element of time will be between 1 and 1000, inclusive.
-	Each element of prec will contain exactly N characters, where N is the number of elements in prec.
-	Each element of prec will contain only 'N' and 'Y'.
-	The ith character of the ith element of prec will be 'N'.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

class ParallelProgramming
{
public:
	int minTime(vector<int> & time, vector<string> & prec)
        {
            int size = prec.size();

            vector<int> indegree(size);
            fill(indegree.begin(), indegree.end(), 0);
            populateIndegree(prec, indegree);
            queue<int> zdeg;
            getZeroIndegreeNodes(indegree, zdeg);
            
            vector<int> sorted;
            while (!zdeg.empty())
            {
                int v = zdeg.front();
                zdeg.pop();
                sorted.push_back(v);

                for (int i = 0; i < size; ++i)
                {
                    if (prec[v][i] == 'Y')
                    {
                        --indegree[i];
                        if (0 == indegree[i])
                        {
                            zdeg.push(i);
                        }
                    }
                }
            }

            if (sorted.size() != size)
            {
                return -1;
            }

            vector<int> start(size);
            fill(start.begin(), start.end(), 0);
            for (int i = 0; i < size; ++i)
            {
                for (int j = 0; j < size; ++j)
                {
                    if ('Y' == prec[sorted[i]][j])
                    {
                        if (start[sorted[i]] + time[sorted[i]] > start[j])
                        {
                            start[j] = start[sorted[i]] + time[sorted[i]];
                        }
                    }
                }
            }

            vector<int> end(size);
            for (int i = 0; i < size; ++i)
            {
                end[i] = start[i] + time[i];
            }
            
            return *max_element(end.begin(), end.end());
        }
private:
    void populateIndegree(vector<string> & prec, vector<int> & indegree)
        {
            int size = prec.size();
            for (int i = 0; i < size; ++i)
            {
                for (int j = 0; j < size; ++j)
                {
                    if (prec[i][j] == 'Y') ++indegree[j];
                }
            }
        }

    void getZeroIndegreeNodes(vector<int> & indegree, queue<int> & zdeg)
        {
            int size = indegree.size();
            for (int i = 0; i < size; ++i)
            {
                if (0 == indegree[i])
                {
                    zdeg.push(i);
                }
            }
        }
};

void Test(vector<int> & time, vector<string> & prec)
{
    ParallelProgramming pp;
    cout << "Output: " << pp.minTime(time, prec) << endl;
}

int main()
{
    vector<string> test;
    test.push_back("NNN");
    test.push_back("NNN");
    test.push_back("NNN");
    vector<int> times;
    times.push_back(150);
    times.push_back(200);
    times.push_back(250);
    Test(times, test);

    test.clear(); times.clear();
    test.push_back("NNN");
    test.push_back("YNN");
    test.push_back("NNN");
    times.push_back(150);
    times.push_back(200);
    times.push_back(250);
    Test(times, test);

    test.clear(); times.clear();
    test.push_back("NYN");
    test.push_back("NNY");
    test.push_back("NNN");
    times.push_back(150);
    times.push_back(200);
    times.push_back(250);
    Test(times, test);

    test.clear(); times.clear();
    test.push_back("NYN");
    test.push_back("NNY");
    test.push_back("YNN");
    times.push_back(150);
    times.push_back(200);
    times.push_back(250);
    Test(times, test);

    test.clear(); times.clear();
    test.push_back("NNNNNN");
    test.push_back("NNYYYY");
    test.push_back("YNNNNN");
    test.push_back("NNYNYN");
    test.push_back("NNNNNN");
    test.push_back("NNNNNN");
    times.push_back(345);
    times.push_back(335);
    times.push_back(325);
    times.push_back(350);
    times.push_back(321);
    times.push_back(620);
    Test(times, test);
    
    return 0;
}
