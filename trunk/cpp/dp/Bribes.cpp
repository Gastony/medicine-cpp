/* Top coder problem
   http://community.topcoder.com/stat?c=problem_statement&pm=11037

   Problem Statement for Bribes
Problem Statement
    	The Government in Bulgaria is elected every four years. When an election is held, most people don't vote. They then complain about the new government for the entire time they're in charge, but when the next elections are held four years later, they again don't vote.



Elleonora plans to use this low voter turnout to her advantage. She has found the key to the prime minister's chair: bribes. To ensure that she will win the election, she has decided to bribe all people, who show up on the day of elections, into voting for her. Due to the so called "shurobadjanashtina" (a Bulgarian term meaning that each person is related in some way to all other people), she doesn't even need to pay every voter. For example, if a young couple shows up to vote, bribing just one of them might be sufficient since the other will voluntarily vote for the same candidate.



All voters are lined up in front of the voting place. They are numbered 0 to N-1 from left to right. Each voter has two integer attributes - influence and resistance. They are given in int[]s influence and resistance, the i-th elements of which are the influence and resistance, respectively, of the i-th voter. Influence is a measure of how much a person can affect the decisions of the people surrounding him. Resistance is a measure of a person's will to vote for different candidate. If a person's resistance ever falls to zero or less, he will vote for Elleonora. If Elly bribes the i-th person in line, that person's resistance will be reduced by influence[i]. Since that person affects the people around him, the resistances of the person directly to his left and the person directly to his right (the (i-1)-th and (i+1)-th person, respectively) will each be reduced by influence[i]/2. All division in this problem is integer division, meaning that any fractional parts are discarded. The resistances of the (i-2)-th and (i+2)-th people will be reduced by influence[i]/4, and so on. More formally, when the i-th person is bribed, the resistance of the j-th person is reduced by influence[i]/2^(abs(i-j)), where abs(i-j) is the absolute value of i-j. If, after a number of bribes, everybody's resistance is less than or equal to zero, she has won all the votes, and therefore the election.



Return the minimum number of people she must bribe to win the election. She can't bribe the same person more than once. To win the election, every single person must vote for her. If this is impossible, return -1 instead.
 
Definition
    	
Class:	Bribes
Method:	minBribes
Parameters:	int[], int[]
Returns:	int
Method signature:	int minBribes(int[] influence, int[] resistance)
(be sure your method is public)
    
 
*Constraints
*-	influence and resistance will each contain between 1 and 50 elements, inclusive.
*-	influence and resistance will contain the same number of elements.
*-	Each element of influence and resistance will be between 1 and
*500, inclusive.
*/
    
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;

/*two solutions presented
 * one using dynamic programming - produces optimal solution
 * one using greedy algorithm - may not produce optimal solution always
 */
class Bribes
{
public:
  int minBribes(vector<int> & influence, vector<int> & resistance)
  {
    int size = influence.size();
    
    vector<vector<int> > resists(size);
    for (int i = 0; i < size; ++i)
      {
	resists[i].resize(size);
	for (int j = 0; j < size; ++j)
	  {
	    resists[i][j] = influence[i]/static_cast<int>(pow(static_cast<double>(2),abs(i-j)));
	  }
      }
    
    vector<int> runningTotal(size);
    for (int i = 0; i < size; ++i)
      {
	int sum = 0;
	for (int j = 0; j < size; ++j)
	  {
	    sum += resists[j][i];
	  }
	runningTotal[i] = sum;
      }

    if (!isSolution(resistance, runningTotal))
      {
	return -1;
      }

    vector<int> Min(size);
    fill(Min.begin(), Min.end(), 0);


    return 0;
  }

  //Greedy may not give the optimal solution
  int minBribesGreedy(const vector<int> & influence, const vector<int> & resistance)
  {
    int size = influence.size();
    
    vector<vector<int> > resists(size);
    for (int i = 0; i < size; ++i)
      {
	resists[i].resize(size);
	for (int j = 0; j < size; ++j)
	  {
	    resists[i][j] = influence[i]/static_cast<int>(pow(static_cast<double>(2),abs(i-j)));
	  }
      }
    
    vector<int> runningTotal(size);
    for (int i = 0; i < size; ++i)
      {
	int sum = 0;
	for (int j = 0; j < size; ++j)
	  {
	    sum += resists[j][i];
	  }
	runningTotal[i] = sum;
      }

    if (!isSolution(resistance, runningTotal))
      {
	return -1;
      }
    
    int min = size;
    for (int i = 0; i < size; ++i)
      {
	removeFromTotal(i, resists, runningTotal);
	if (isSolution(resistance, runningTotal))
	  {
	    --min;
	  }
	else
	  {
	    addToTotal(i, resists, runningTotal);
	  }
      }
    
    return min;
  }
private:
  bool isSolution(const vector<int> & res, const vector<int> & curr)
  {
    unsigned int size = res.size(), i = 0;
    for (; i < size; ++i)
      {
	if (res[i]-curr[i] > 0) break;
      }

    if (i != size) return false;
    else return true;
  }

  void removeFromTotal(int i, const vector<vector<int> > & resists, vector<int> & total)
  {
    int size = total.size();
    for (int j = 0; j < size; ++j)
      {
	total[j] -= resists[i][j];
      }
  }

  void addToTotal(int i, const vector<vector<int> > & resists, vector<int> & total)
  {
    int size = total.size();
    for (int j = 0; j < size; ++j)
      {
	total[j] += resists[i][j];
      }
  }
};

void Test(vector<int> & influence, vector<int> & resistance)
{
    Bribes b;
    cout << "Output Greedy: " << b.minBribesGreedy(influence, resistance) << endl;
    cout << "Output Dynamic Programming: " << b.minBribes(influence, resistance) << endl;
}

int main()
{
    int i1[] = {10, 3, 5, 3, 1};
    int r1[] = {11, 2, 7, 3, 1};
    vector<int> vi(i1, i1+sizeof(i1)/sizeof(int));
    vector<int> vr(r1, r1+sizeof(r1)/sizeof(int));
    Test(vi, vr);
    
    vi.clear(); vr.clear();
    int i2[] = { 15, 15, 15 };
    int r2[] = { 13, 42, 13 };
    vi = vector<int>(i2, i2+sizeof(i2)/sizeof(int));
    vr = vector<int>(r2, r2+sizeof(r2)/sizeof(int));
    Test(vi, vr);

    vi.clear(); vr.clear();
    int i3[] = { 10, 16, 4, 7, 1, 1, 13 };
    int r3[] = { 10, 16, 4, 7, 1, 1, 13 };
    vi = vector<int>(i3, i3+sizeof(i3)/sizeof(int));
    vr = vector<int>(r3, r3+sizeof(r3)/sizeof(int));
    Test(vi, vr);

    vi.clear(); vr.clear();
    int i4[] = { 479, 340, 398, 40, 477, 181, 422, 377, 60, 486, 15, 500, 307, 1, 2, 65, 411, 374, 446, 401 };
    int r4[] = { 402, 87, 20, 76, 468, 493, 252, 98, 216, 58, 89, 500, 89, 26, 8, 125, 269, 116, 426, 81 };
    vi = vector<int>(i4, i4+sizeof(i4)/sizeof(int));
    vr = vector<int>(r4, r4+sizeof(r4)/sizeof(int));
    Test(vi, vr);

    vi.clear(); vr.clear();
    int i5[] = { 21, 196, 401, 157, 9, 497, 371, 84, 395, 495, 401, 190, 465, 359, 47, 441, 245, 487, 118, 405 };
    int r5[] = { 127, 313, 376, 94, 66, 37, 237, 142, 315, 495, 257, 153, 437, 339, 483, 356, 16, 132, 231, 342 };
    vi = vector<int>(i5, i5+sizeof(i5)/sizeof(int));
    vr = vector<int>(r5, r5+sizeof(r5)/sizeof(int));
    Test(vi, vr);

    return 0;
}
