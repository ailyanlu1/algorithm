#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const int INF = 999999999;


int count_D(int left, int right, string message){
    int num = 0;
    for(int i=left; i<=right; i++){
        if(message[i]=='D')num++;
    }
    return num;
}


class InboxCleanup {
    public:
        int fewestClicks(string messages, int low, int high) {
            int clicks = INF;
            int N = messages.size();
            for(int n_per_page = low; n_per_page<=high; n_per_page++){
                int cur = 0;
                int t_clicks = 0;
                //int next_page = 0;
                for(int cur=0; cur<N; cur+=n_per_page){
                    int n_D = 0;
                    int cur_page = 0;
                    if(cur+n_per_page<N){
                        n_D = count_D(cur, cur+n_per_page-1, messages);
                        cur_page = n_per_page;
                    }else{
                        n_D = count_D(cur, N-1, messages);
                        cur_page = N-cur;
                    }
                    if(n_D!=0){
                        if(n_D*2>cur_page){
                            t_clicks+=1+cur_page-n_D;
                            t_clicks+=1;
                        }else{
                            t_clicks+=n_D;
                            t_clicks += 1;
                        }
                    }
                    t_clicks+=1;    //next page
                }
                t_clicks-=1;
                clicks = min(clicks, t_clicks);
                cout<<"for "<<n_per_page<<" clicks = "<<clicks<<endl;
            }
            return clicks;
        }
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, string p0, int p1, int p2, bool hasAnswer, int p3) {
    cout << "Test " << testNum << ": [" << "\"" << p0 << "\"" << "," << p1 << "," << p2;
    cout << "]" << endl;
    InboxCleanup *obj;
    int answer;
    obj = new InboxCleanup();
    clock_t startTime = clock();
    answer = obj->fewestClicks(p0, p1, p2);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer) {
        cout << "Desired answer:" << endl;
        cout << "\t" << p3 << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << answer << endl;
    if (hasAnswer) {
        res = answer == p3;
    }
    if (!res) {
        cout << "DOESN'T MATCH!!!!" << endl;
    } else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
        cout << "FAIL the timeout" << endl;
        res = false;
    } else if (hasAnswer) {
        cout << "Match :-)" << endl;
    } else {
        cout << "OK, but is it right?" << endl;
    }
    cout << "" << endl;
    return res;
}
int main() {
    bool all_right;
    all_right = true;

    string p0;
    int p1;
    int p2;
    int p3;

    {
        // ----- test 0 -----
        p0 = "..........";
        p1 = 5;
        p2 = 10;
        p3 = 0;
        all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    {
        // ----- test 1 -----
        p0 = ".D.D.DD.D.";
        p1 = 5;
        p2 = 5;
        p3 = 8;
        all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        p0 = "...D..DDDDDD...D.DD..";
        p1 = 3;
        p2 = 10;
        p3 = 12;
        all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        p0 = "D.D..D..DD.DDDD.D.DDD.DDDD..";
        p1 = 3;
        p2 = 11;
        p3 = 17;
        all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    {
        // ----- test 4 -----
        p0 = "DDD.........................";
        p1 = 1;
        p2 = 3;
        p3 = 11;
        all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    if (all_right) {
        cout << "You're a stud (at least on the example cases)!" << endl;
    } else {
        cout << "Some of the test cases had errors." << endl;
    }
    return 0;
}
// END KAWIGIEDIT TESTING
