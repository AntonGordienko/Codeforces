#include<iostream>
#include<queue>
#include<unordered_set>
#include<cmath>

using namespace std;

int main(int argc, char* argv[]) {
  unsigned long long n, x;
  // int answer = -1;
  cin >> n >> x;

  unsigned long long max_val = pow(10, n);
  unsigned long long min_val = max_val / 10;

  queue<pair<unsigned long long, int>> q;
  unordered_set<unsigned long long> used;
  q.push(make_pair(x, 0));
 // int temp_move = -1;
  while (!q.empty()) {
    auto [x, moves] = q.front();
    // if (temp_move < moves) {
    //   temp_move = moves;
    //   cout << x << ' ' << moves << ' ' << q.size() << endl;
    // }
    q.pop();
    if (x >= min_val && x < max_val) {
      cout << moves << endl;
      return 0;
    }
    
    int mask = 0;
    unsigned long long nx = x;
    while(nx > 0) {
      mask |= (1 << nx % 10);
      nx /= 10;
    }

    for (int i = 2; i < 10; i++) {
      if (mask & (1 << i) && used.find(x * i) == used.end()) {
        q.push(make_pair(x * i, moves + 1));
        used.insert(x * i);
      }
    }
  }
  cout << -1 << endl;
  return 0;
}
