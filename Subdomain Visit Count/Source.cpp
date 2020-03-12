#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
vector<string> subdomainVisits(vector<string>& cpdomains);
int main() {
	vector <string> Ss = {"9001 discuss.leetcode.com", "1 test.com"};
	for (auto x : subdomainVisits(Ss)) { cout << x << endl; }
	return 0;
}
vector<string> subdomainVisits(vector<string>& cpdomains) {
	vector<string> res;
	unordered_map<string, int> SS;
	for (string ptr : cpdomains) {
		int spaceI = ptr.find(' ');
		int cntr = stoi(ptr.substr(0, spaceI));
		string rem = ptr.substr(spaceI+1);
		for (int i = 0; i < rem.size(); i++) {
			if (rem[i] == '.') {
				SS[rem.substr(i + 1)] += cntr;
			}
		}
		SS[rem] += cntr;
	}
	for (auto ptr : SS) {
		string tmp;
		tmp += to_string(ptr.second);
		tmp += ' ';
		tmp += ptr.first;
		res.push_back(tmp);
	}
	return res;
}