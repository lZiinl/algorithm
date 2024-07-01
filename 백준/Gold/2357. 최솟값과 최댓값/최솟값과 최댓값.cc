#include <iostream>
#include <vector>
#include <algorithm>
#include<cstring>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>
#include <deque>
#include <string>

typedef long long ll;

using namespace std;
int n, m;
vector<int> li;
vector<int> mintree, maxtree;


void init(int node, int start, int end){
	if(start == end){
		mintree[node] = li[start];
		maxtree[node] = li[start];
		return;
	}

	int mid = (start+end)/2;
	init(node*2, start, mid);
	init(node*2+1, mid+1, end);

	mintree[node] = min(mintree[node*2], mintree[node*2+1]);
	maxtree[node] = max(maxtree[node*2], maxtree[node*2+1]);
}

pair<int, int> find(int node, int a, int b, int left, int right){
    if(left > b || right < a) return make_pair(INT32_MAX, 0);
    if(a <= left && right <= b){
        return make_pair(mintree[node], maxtree[node]);
    }
    pair<int, int> l, r;
	
    l = find(node * 2, a, b, left, (left + right) / 2);
    r = find(node * 2 + 1, a, b, (left + right) / 2 + 1, right);
    return make_pair(min(l.first, r.first), max(l.second, r.second));
}

int main(int argc, char** argv)
{	

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> n >> m;
	int h = (int)ceil(log2(n));
	
	li.resize(n+1);
	mintree.resize((1<<(h+1)) + 10 );
	maxtree.resize((1<<(h+1)) + 10 );

	for(int i=1; i<=n; i++)
		cin >> li[i];

	init(1,1,n);
	

	for(int iii=0; iii<m; iii++){
		int a, b;
		cin >> a >> b;
		pair<int, int> ans = find(1, a, b, 1, n);
		cout << ans.first << " " << ans.second << "\n";
	}
	
	return 0;
}