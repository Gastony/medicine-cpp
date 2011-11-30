/* Top coder problem
http://community.topcoder.com/stat?c=problem_statement&pm=2356
Problem Statement for TeamBuilder


Problem Statement
    	You are arranging a weird game for a team building exercise. In this game there are certain locations that people can stand at, and from each location there are paths that lead to other locations, but there are not necessarily paths that lead directly back. You have everything set up, but you need to know two important numbers. There might be some locations from which every other location can be reached. There might also be locations that can be reached from every other location. You need to know how many of each of these there are.

Create a class TeamBuilder with a method specialLocations that takes a String[] paths that describes the way the locations have been connected, and returns a int[] with exactly two elements, the first one is the number of locations that can reach all other locations, and the second one is the number of locations that are reachable by all other locations. Each element of paths will be a String containing as many characters as there are elements in paths. The i-th element of paths (beginning with the 0-th element) will contain a '1' (all quotes are for clarity only) in position j if there is a path that leads directly from i to j, and a '0' if there is not a path that leads directly from i to j.
 
Definition
    	
Class:	TeamBuilder
Method:	specialLocations
Parameters:	String[]
Returns:	int[]
Method signature:	int[] specialLocations(String[] paths)
(be sure your method is public)
    
 
Constraints
-	paths will contain between 2 and 50 elements, inclusive.
-	Each element of paths will contain N characters, where N is the number of elements of paths.
-	Each element of paths will contain only the characters '0' and '1'.
-	The i-th element of paths will contain a zero in the i-th position.
*/

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class TeamBuilder
{
public:
  vector<int> specialLocations(const vector<string> & paths)
  {
    int rows = paths.size();
    vector<vector<int> > visited(rows);
    for (int i = 0; i < rows; ++i)
      {
	visited[i].resize(rows);
	fill(visited[i].begin(), visited[i].end(), 0);
      }

    for (int i = 0; i < rows; ++i)
      {
	dfs(paths, i, rows, visited[i]);
      }

    vector<int> result(2);
    processResults(visited, result);

    return result;
  }

private:
  void dfs(const vector<string> & paths, const int i, const int size, vector<int> & visited)
  {
    if (!visited[i])
      {
	visited[i] = 1;

	for (int j = 0; j < size; ++j)
	  {
	    if ('1' == paths[i][j])
	      {
		dfs(paths, j, size, visited);
	      }
	  }
      }
  }

  void processResults(const vector<vector<int> > & visited, vector<int> & result)
  {
    int reacher = 0, reachable = 0;
    int size = visited.size();

    //printVisited(visited);

    for (int i = 0; i < size; ++i)
      {
	int rowsum = 0, colsum = 0;
	for (int j = 0; j < size; ++j)
	  {
	    rowsum += visited[i][j];
	    colsum += visited[j][i];
	  }

	if (rowsum == size) ++reacher;
	if (colsum == size) ++reachable;
      }

    result[0] = reacher;
    result[1] = reachable;
  }

  void  printVisited(const vector<vector<int> > & visited)
  {
    int size = visited.size();
    for (int i = 0; i < size; ++i)
      {
	for (int j = 0; j < size; ++j)
	  {
	    cout << visited[i][j] << " ";
	  }
	cout << endl;
      }
  }
};

void Test(const vector<string> & paths)
{
  TeamBuilder tb;
  vector<int> out = tb.specialLocations(paths);
  cout << "Output: " <<  out[0] << "|" << out[1] << endl;
}

int main()
{
  vector<string> test;
  test.push_back("010");
  test.push_back("000");
  test.push_back("110");
  Test(test);

  test.clear();
  test.push_back("0010");
  test.push_back("1000");
  test.push_back("1100");
  test.push_back("1000");
  Test(test);

  test.clear();
  test.push_back("01000");
  test.push_back("00100");
  test.push_back("00010");
  test.push_back("00001");
  test.push_back("10000");
  Test(test);

  test.clear();
  test.push_back("0110000");
  test.push_back("1000100");
  test.push_back("0000001");
  test.push_back("0010000");
  test.push_back("0110000");
  test.push_back("1000010");
  test.push_back("0001000");
  Test(test);

  return 0;
}
