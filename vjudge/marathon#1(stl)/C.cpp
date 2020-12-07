#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define X first
#define Y second
#define A begin
#define B end
#define S1 100000
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

void pv(){ printf("\n"); }

template<typename T, typename... Args>
void pv(T a, Args... args) {
	#ifndef DDEBUG
	return;
	#endif
	std::cout << a << " "; pv(args...);
}

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	#ifndef DDEBUG
	return;
	#endif
	cout << *it << " = " << a << endl;
	err(++it, args...);
}

template<typename T>
void parr(T arr) {
	#ifndef DDEBUG
	return;
	#endif
	for(auto i:arr) cout << i << " ";
	printf("\n");
}

int main(){
	int i, ix, t, n, m, g, a[S1];
	scanf("%d", &t);
	while(t--){
		queue<pair<int,int> > q;
		multiset<int, greater<int>> s;
		scanf("%d %d", &n, &m);
		rep(i, 0, n) scanf("%d", &g), q.push({i,g}), s.insert(g);
		int ans=0;
		bool gg=0;
		while(!gg) {
			if(q.front().Y == *s.A()) {
				auto it = s.find(*s.A());
				s.erase(it);
				if(q.front().X == m) gg=1;
				ans++;
			}
			q.push(q.front());
			q.pop();
		}
		// parr(s);
		printf("%d\n", ans);
	}
}