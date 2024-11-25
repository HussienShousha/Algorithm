#include <bits/stdc++.h>
using namespace std;

struct Job{
    int id;
    int deadline;
    int profit;
};
//true -> No swap
//->false  swap
bool cmp(Job &a, Job&b)
{
    return a.profit > b.profit;
}
void JobScheduling(Job *job, int n, int& profit, int& cnt)
{  //O(n^2) number of jobs
    sort(job,job+n,cmp);
    int daysMapToJob[n];
    for (int i = 0; i < n; ++i) {
        daysMapToJob[i] = -1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = job[i].deadline; j >= 0 ; --j) {
            if(daysMapToJob[j] == -1)
            {
                daysMapToJob[j] = job[i].id;
                profit += job[i].profit;
                cnt++;
                break;
            }
        }
    }
}

int main() {
    int n;
    cin>>n;
    Job job[n];
    int id;
    int deadline;
    int profit = 0;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cin>>id>>deadline>>profit;
        job[i].id = id;
        job[i].deadline = deadline;
        job[i].profit = profit;
    }
    JobScheduling(job,n,profit,cnt);
    cout<<profit<<" "<<cnt<<endl;
    return 0;
}
