// https://leetcode.com/problems/brick-wall/description/
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define inf (long long int)1e18
#define log(args...)    { std::string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); std::stringstream _ss(_s); std::istream_iterator<std::string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b) for(int z=(a);z<=(b);z++) std::cout<<(arr[z])<<" ";std::cout<<std::endl;
#define vec std::vector
#define vll std::vector<long long int>
#define vi std::vector<int>
#define vb std::vector<bool>
#define pii std::pair<int, int>
#define pllll std::pair<long long int, long long int>
#define loop(i, a, b) for(int i=a;i<=b;i++)
#define rloop(i, a, b) for(int i=a;i>=b;i--)
#define iter_all(el, cont) for(auto &el:cont)

void err(std::istream_iterator<std::string> it) {}
template<typename T, typename... Args>
void err(std::istream_iterator<std::string> it, T a, Args... args) {
	std::cout << *it << " = " << a << std::endl;
	err(++it, args...);
}

void file_i_o() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        // if I want to cross minimum bricks then most of the edges should lie on the line.
        // This means for each integral co-ord, I need to find the number of brick-edges lying on the line.
        // Therefore the problem boils down to finding the maximum number of common integral co-ord.
        // Since, the bricks are placed side-by-side, we need to take the prefix-sum of each row of the 2D array.
        // Then compute the common-edges

        int n = wall.size();
        int max_width = std::accumulate(wall[0].begin(), wall[0].end(), 0);

        std::unordered_map<int, int> count_coord;

        int max_coord = 0;

        for(int i=0;i<n;i++){
            int cs = 0;
            for(int j=0;j<wall[i].size();j++){
                cs += wall[i][j];
                count_coord[cs]++;
                max_coord = std::max(max_coord, cs);
            }
        }

        int ans = n;
        for(auto &el:count_coord){
            if(max_coord == el.first) continue;
            ans = std::min(ans, n-el.second);
        }

        return ans;
    }
};

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}