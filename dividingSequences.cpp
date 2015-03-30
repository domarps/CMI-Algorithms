/*
  Created by S Pramod <-> domarps
  http://www.iarcs.org.in/inoi/contests/apr2005/Advanced-1.php
  (IARCS OPC Archive, K Narayan Kumar, CMI)
*/
#include <iostream>
using namespace std;

int main(){

	int n;
	cin >> n;
	int array[n];

	for(int i = 0;i < n; i++){cin >> array[i];}

	int Best[n];
	int maxlength = 1;
	int bestEnd = 0;

	Best[0] = 1;


	for(int i = 1;i < n; i ++)
	{
		Best[i] = 1;
		for(int j = i-1; j >=0; j--)
		{
		  //The Meat of the Problem i.e. Dynamic Programming 
			if(Best[j] + 1 > Best[i] && array[i] % array[j] == 0)
			{
				Best[i] = Best[j] + 1;
			}
			//Learnt why this DP approach is better than Memoization or Recursive approach
		}
		if(Best[i] > maxlength)
		{
			bestEnd = i;
			maxlength = Best[i];
		}
	}
	cout << maxlength;
	return 0;
}
