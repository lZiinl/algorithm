#include <iostream>
 
using namespace std;
 
int prime_cnt(long long _n, long long _a)
{
    // n!에 있는 소수 a의 개수 찾기
    long long cnt = 0;
    for(long long i = _a ; i <= _n; i *= _a)
    {
        cnt += _n / i;
    }
 
    return cnt;
}
 
 
int main()
{
    long long n, a;
    cin >> n >> a;
 
    cout << prime_cnt(n, a);
 
    return 0;
}