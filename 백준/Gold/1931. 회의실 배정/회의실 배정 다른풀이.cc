#include <iostream>
#include <queue>
#include <utility>


using namespace std;

int n;

struct Sub{
    int start;
    int end;
};

struct cmp{
    bool operator()(Sub a, Sub b){
        if(a.end == b.end){ // 종료시간이 같을 경우 시작시간이 작은것부터
            return a.start > b.start;
        }
        return a.end > b.end; // 종료시간이 빠른것부터
    }
};

priority_queue<Sub, vector<Sub>, cmp> pq;


int main(){
    int tmp1,tmp2;
    cin >> n;
    Sub sub;
    for(int i=0;i<n;i++){
        cin >> tmp1 >> tmp2;
        sub.start = tmp1;
        sub.end = tmp2;
        pq.push(sub);
    }

    int end = 0;
    int tot = 0;

    while(pq.size() > 0){
        sub = pq.top();
        if(end <= sub.start){ // 현재 꺼낸 회의가 현재 가장 최근에 종료된 회의 이후일때
            tot++;
            end = sub.end;
        }
        pq.pop();
        
    }
    cout << tot;
}
