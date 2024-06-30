#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>
#include <deque>
#include <string>

typedef long long ll;

using namespace std;
deque<int> dq;

int main(int argc, char** argv)
{	

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int tn;
	cin >> tn;

	while(tn--){
		string func;
		int n;
		string l;
		dq.clear();
		bool reverse = false;
		
		cin >> func;
		cin >> n;
		cin >> l;

	
		
		int idx = 0;
		while(idx < l.length()){
			if(l[idx] == ',' || l[idx] == '[' || l[idx] == ']'){
				idx++;
				continue;
			}
			int num = 0;
			while(l[idx] >= '0' && l[idx] <= '9'){
				num = 10*num;
				num += l[idx] - '0';
				idx++;
			}
			dq.push_back(num);
		}

		int err = 0;
		for(char c : func){
			if(c=='R'){
				reverse = !reverse;
			}
			else{
				if(dq.empty()){
					cout << "error\n";
					err = 1;
					break;
				}
				if(!reverse){
					dq.pop_front();
				}
				else{
					dq.pop_back();
				}
			}
		}

		if(err==1) continue;

		cout << '[';
		while (!dq.empty()) { 
			if (!reverse) {
				cout << dq.front();
				dq.pop_front();
			}
			else {
				cout << dq.back();
				dq.pop_back();
			}
			if (!dq.empty()) {
				cout << ",";
			}
		}
		cout << "]\n";

	}
	
}