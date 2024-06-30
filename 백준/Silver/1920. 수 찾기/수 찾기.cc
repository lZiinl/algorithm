#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <unordered_set>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	unordered_set<long> set;

	int n, m;

	cin >> n;
	for(int i=0; i<n; i++)
	{
		long temp;
		cin >> temp;

		set.insert(temp);
	}

	cin >> m;
	for(int j=0; j<m; j++)
	{
		long temp;
		cin >> temp;
		
		if (set.find(temp) == set.end())
		{
			cout << 0 << "\n";
		}
		else
		{
			cout << 1 << "\n";
		}
	}
	return 0;
}