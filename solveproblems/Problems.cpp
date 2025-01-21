#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<utility>
#include<cstring>
#include<cmath>
#include<string>
#include<map>
using namespace std;
//ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//b : baekjoon, c : codeup

int arr[] = { 1,2,3,4,5 };
vector<int> segment;
int create(int idx, int left, int right) {
	if (left == right) {
		segment[idx] = arr[left];
		return segment[idx];
	}
	int mid = (left + right) / 2;
	segment[idx] = create(idx * 2 + 1, left, mid) + create(idx * 2 + 2, mid + 1, right);
	return segment[idx];
}
void update(int idx, int left, int right, int position, int diff)
{
	if (left > position || position > right)
	{
		return;
	}
	segment[idx] -= diff;
	if (left == right)
	{
		return;
	}
	int mid = (left + right) / 2;
	update(idx * 2 + 1, left, mid,position,diff);
	update(idx * 2 + 2, mid + 1, right, position, diff);

}
int query(int idx, int left, int right, int low, int high) // idx는 현재 세그먼트 트리의 현재 위치, data배열의 탐색 오른쪽 ,왼쪽, low high 구간 쿼리 
{
	//1 쿼리에 포함범위 안되는경우
	if (low > right || high < left)return 0;
	//2. 쿼리에 완전 포함 되는 경우 
	if (low <= left && right <= high)return segment[idx];

	//3. 쿼리에 부분 포함 되는 경우
	int mid = (left + right) / 2;
	return query(idx * 2 + 1, left, mid, low, high) + query(idx * 2 + 2, mid + 1, right, low, high);
}
int main() {
	segment.resize(sizeof(arr) / sizeof(int) * 4);
	create(0, 0, 4);
	for (int i = 0; i < sizeof(arr) / sizeof(int) * 4; i++)
	{
		cout << segment[i] <<" ";
	}
	cout << "\n";
	int idx, diff;
	cin >> idx >> diff;
	update(0, 0, 4, idx, diff);
	for (int i = 0; i < sizeof(arr) / sizeof(int) * 4; i++)
	{
		cout << segment[i] << " ";
	}
	int l, r;
	cin >> l >> r;
	cout << query(0, 0, 4, l, r);
}

////11438번 문제 b
//#define MAX 100001
//int n;
//vector<int> tree[MAX];
//int parents[MAX][20];
//int depth[MAX];
//int visited[MAX];
//int query;
//void dfs(int curr) {
//	visited[curr] = 1;
//	for (auto next : tree[curr]) {
//		if (!visited[next]) {
//			depth[next] = depth[curr] + 1;
//			parents[next][0] = curr;
//			dfs(next);
//		}
//	}
//}
//void parentSetting() {
//	for (int i = 1; i < 20; i++) {
//		for (int node = 1; node <= n; node++)
//			parents[node][i] = parents[parents[node][i - 1]][i - 1];
//	}
//}
//int lca(int node1, int node2) {
//	
//	if (depth[node1] > depth[node2])
//		swap(node1, node2);
//
//	for (int i = 19; i >= 0; i--) {
//		if (depth[parents[node2][i]] > depth[node1]) {
//			node2 = parents[node2][i];
//		}
//	}
//
//	if (node1 == node2)
//		return node1;
//	if (node1 != node2) {
//		for (int i = 19; i >= 0; i--) {
//			if (parents[node1][i] != parents[node2][i]) {
//				node1 = parents[node1][i];
//				node2 = parents[node2][i];
//			}
//		}
//	}
//	return parents[node1][0];
//}
//int main() {
//	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//	cin >> n;
//	for (int i = 0; i < n - 1; i++) {
//		int node1, node2;
//		cin >> node1 >> node2;
//		tree[node1].push_back(node2);
//		tree[node2].push_back(node1);
//	}
//	dfs(1);
//	parentSetting();
//	cin >> query;
//	for (int i = 0; i < query; i++) {
//		int x, y;
//		cin >> x >> y;
//		cout << lca(x, y) << "\n";
//	}
//}

////20040번 문제 b
//int table[50000001];
//int totalNode, progress, answer;
//int MyParent(int node) {
//	if (node == table[node])
//		return node;
//	return table[node] = MyParent(table[node]);
//}
//void Myunion(int node1, int node2) {
//	node1 = MyParent(node1);
//	node2 = MyParent(node2);
//	if (node1 > node2)
//		table[node1] = node2;
//	else
//		table[node2] = node1;
//}
//int main() {
//	cin >> totalNode >> progress;
//	for (int i = 1; i <= totalNode; i++)
//		table[i] = i;
//	for (int i = 0; i < progress; i++) {
//		int input1, input2;
//		cin >> input1 >> input2;
//		if (MyParent(input1) != MyParent(input2))
//			Myunion(input1, input2);
//		else {
//			answer = i + 1;
//			break;
//		}
//	}
//	cout << answer;
//}

////14003번 문제 b
//int main() {
//	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//	vector<int> list, temp, idxs, answer;
//	int N;
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		int num;
//		cin >> num;
//		list.push_back(num);
//	}
//	idxs.resize(N,0);
//	for (int i = 0; i < N; i++) {
//		int save = lower_bound(temp.begin(), temp.end(), list[i]) - temp.begin();
//		if (temp.size() == 0 || temp.back() < list[i])
//			temp.push_back(list[i]);
//		else
//			temp[save] = list[i];
//		idxs[i] = save;
//	}
//	int index = temp.size() - 1;
//	printf("\n");
//	for (int i = N-1; i >= 0; i--) {
//		if (index == idxs[i]) {
//			answer.push_back(list[i]);
//			index--;
//		}
//	}
//	cout << temp.size() << "\n";
//	reverse(answer.begin(), answer.end());
//	for (int i = 0; i < answer.size(); i++) {
//		cout << answer[i] << " ";
//	}
//}

////11438번 문제 old b
//#define MAX 100001
//int n, m;
//int parent[MAX][21];
//int depth[MAX];
//vector<int> vec[MAX];
//int visited[MAX];
//void dfs(int node) {
//	visited[node] = 1;
//	for (auto next : vec[node]) {
//		if (!visited[	next]) {
//			parent[next][0] = node;
//			depth[next] = depth[node] + 1;
//			dfs(next);
//		}
//	}
//}
//int lca(int node1, int node2) {
//	if (depth[node1] > depth[node2]) {
//		int temp = node1;
//		node1 = node2;
//		node2 = temp;
//	}
//	int i = 20;
//	while (depth[node1] != depth[node2] && i>=0) {
//		if (depth[node2] - depth[node1] & 1 << i) 
//			node2 = parent[node2][(1 << i)-1];
//		i--;
//	}
//	if (node1 == node2)
//		return node1;
//	i = 0;
//	while (node1 != node2 && i >= 0) {
//		if (parent[node1][i - 1] != 0 && parent[node2][i - 1] != 0 && node1!=node2) {
//			node1 = parent[node1][i- 1];
//			node2 = parent[node2][i- 1];
//			//cout << "node1 " << node1 << "   node2 " << node2 << endl;
//		}
//
//		i++;
//	}
//	return node1;
//}
//int main() {
//	cin >> n;
//	for (int i = 0; i < n - 1; i++) {
//		int n1, n2;
//		cin >> n1 >> n2;
//		vec[n1].push_back(n2);
//		vec[n2].push_back(n1);
//	}
//	dfs(1);
//	int idx = 20;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= 20; j++)
//			parent[i][j] = parent[parent[i][j - 1]][j - 1];
//	}
//	int m;
//	cin >> m;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 0; j <= 20; j++)
//			cout << parent[i][j] << " ";
//		cout << endl;
//	}
//	for (int i = 0; i < m; i++) {
//		int n1, n2;
//		cin >> n1 >> n2;
//		cout << lca(n1, n2) << "\n";
//	}
//}

////3584번 문제 b
//int N;
//vector<int> list[10001];
//int parent[10001];
//int depth[10001];
//void dfs(int curr) {
//	for(auto next: list[curr]) {
//		parent[next] = curr;
//		depth[next] = depth[curr] + 1;
//		dfs(next);
//	}
//}
//int LCA(int node1, int node2) {
//	if (depth[node1] > depth[node2]) {
//		int temp = node1;
//		node1 = node2;
//		node2 = temp;
//	}
//	while (depth[node1] != depth[node2]) {
//		node2 = parent[node2];
//	}
//	if (node1 == node2)
//		return node1;
//	while (node1 != node2) {
//		node1 = parent[node1];
//		node2 = parent[node2];
//	}
//	return node1;
//}
//void init() {
//	for (int i = 0; i < 10001; i++) {
//		list[i].clear();
//		parent[i] = i;
//	}
//}
//int main() {
//	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//	int T;
//	cin >> T;
//	for (int i = 0; i < T; i++) {
//		init();
//		cin >> N;
//		for (int j = 0; j < N - 1; j++) {
//			int num1, num2;
//			cin >> num1 >> num2;
//			list[num1].push_back(num2);
//			parent[num2] = num1;
//		}
//		for (int i = 1; i <= N; i++) {
//			if (parent[i] == i) {
//				depth[i] = 0;
//				dfs(i);
//				break;
//			}
//		}
//		int com_1, com_2;
//		cin >> com_1 >> com_2;
//		cout << LCA(com_1, com_2) << "\n";
//	}
//}

////9663번 문제 b
//int list[16];
//int N, total = 0;
//bool check(int level) {
//	for (int i = 0; i < level; i++)
//		if (list[i] == list[level] || abs(list[level] - list[i]) == level - i)
//			return false;
//	return true;
//}
//void f(int num)
//{
//	if (num == N)
//		total++;
//	else {
//		for (int i = 0; i < N; i++) {
//			list[num] = i;
//			if (check(num))
//				f(num + 1);
//		}
//	}
//}
//int main() {
//	cin >> N;
//	f(0);
//	cout << total;
//}

////14002번 문제 b
//int main() {
//	int N;
//	int list[1000], len[1000], answer[1000];
//	cin >> N;
//	for (int i = 0; i < N; i++)
//		cin >> list[i];
//	for (int i = 0; i < N; i++) {
//		len[i] = 1;
//		for (int j = 0; j < i; j++) {
//			if (list[i] > list[j])
//				len[i] = max(len[i], len[j] + 1);
//		}
//	}
//	int maxlen = 0, maxidx;
//	for (int i = 0; i < N; i++)
//		if (len[i] > maxlen) {
//			maxlen = len[i];
//			maxidx = i;
//		}
//	answer[0] = list[maxidx];
//	int temp = maxlen - 1;
//	for (int i = maxidx - 1, j = 0; i >= 0; i--) {
//		if (len[i] == temp && list[i] < answer[j]) {
//			answer[++j] = list[i];
//			temp--;
//		}
//	}
//	cout << maxlen << endl;
//	for (int i = maxlen - 1; i >= 0; i--)
//		cout << answer[i] << " ";
//}

////14889번 문제 b
//int N;
//int list[21][21], visit[21];
//int MIN = 999999999;
//void f2() {
//	int score_1 = 0;
//	int score_2 = 0;
//	int save;
//	for (int i = 1; i <= N; i++) {
//		for (int j = i + 1; j <= N; j++) {
//			if (visit[i] && visit[j]) {
//				score_1 += list[i][j];
//				score_1 += list[j][i];
//			}
//			else if (!visit[i] && !visit[j]) {
//				score_2 += list[i][j];
//				score_2 += list[j][i];
//			}
//
//		}
//	}
//	save = abs(score_1 - score_2);
//	if (save < MIN) {
//		MIN = save;
//	}
//}
//void f1(int cnt, int idx) {
//	if (cnt == N / 2) {
//		f2();
//		return;
//	}
//	for (int i = idx; i <= N; i++) {
//		visit[i] = 1;
//		f1(cnt + 1, i + 1);
//		visit[i] = 0;
//	}
//}
//int main() {
//	cin >> N;
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= N; j++) {
//			cin >> list[i][j];
//		}
//	}
//	f1(0, 1);
//	cout << MIN;
//}

////3036번 문제 b
//int f(int num1, int num2) {
//	if (num2 == 0)
//		return num1;
//	else
//		return f(num2, num1 % num2);
//}
//int main() {
//	int n;
//	int radius[101];
//	cin >> n;
//	for (int i = 0; i < n; i++)
//		cin >> radius[i];
//	for (int i = 1; i < n; i++) {
//		int gcd = f(radius[0], radius[i]);
//		if (gcd == 1)
//			cout << radius[0] << "/" << radius[i] << endl;
//		else
//			cout << radius[0] / gcd << "/" << radius[i] / gcd << endl;
//	}
//}

////18258번 문제 b
//int main(void) {
//	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//	int N;
//	queue<int> Q;
//	string input_comment;
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		cin >> input_comment;
//		if (input_comment == "push") {
//			int num;
//			cin >> num;
//			Q.push(num);
//		}
//		else if (input_comment == "pop") {
//			if (Q.empty()) {
//				cout << -1 << '\n';
//			}
//			else {
//				cout << Q.front() << '\n';
//				Q.pop();
//			}
//		}
//		else if (input_comment == "size") {
//			cout << Q.size() << '\n';
//		}
//		else if (input_comment == "empty") {
//			cout << (int)Q.empty() << '\n';
//		}
//		else if (input_comment == "front") {
//			if (Q.empty()) {
//				cout << -1 << '\n';
//			}
//			else {
//				cout << Q.front() << '\n';
//			}
//		}
//		else if (input_comment == "back") {
//			if (Q.empty()) {
//				cout << -1 << '\n';
//			}
//			else {
//				cout << Q.back() << '\n';
//			}
//		}
//	}
//}

////2630번 문제 b
//int list[129][129];
//int answer1 = 0, answer2 = 0;
//void f(int x, int y, int size) {
//	int temp = 0;
//	for (int i = x; i < x + size; i++) {
//		for (int j = y; j < y + size; j++) {
//			if (list[i][j]) {
//				temp++;
//			}
//		}
//	}
//	if (temp == 0)
//		answer1++;
//	else if (temp == size * size)
//		answer2++;
//	else {
//		f(x, y, size / 2);
//		f(x, y + size / 2, size / 2);
//		f(x + size / 2, y, size / 2);
//		f(x + size / 2, y + size / 2, size / 2);
//	}
//	return;
//}
//
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cin >> list[i][j];
//		}
//	}
//	f(0, 0, n);
//	cout << answer1 << endl << answer2;
//}

////1717번 문제 b
//int parents[1000001];
//int n, m;
//void initParent(){
//	for (int i = 1; i <= n; i++)
//		parents[i] = i;
//}
//int getParent(int node) {
//	if (parents[node] == node)
//		return node;
//	return parents[node] = getParent(parents[node]);
//}
//void m_union(int node1, int node2) {
//	node1 = getParent(node1);
//	node2 = getParent(node2);
//	if (node1 > node2)
//		parents[node1] = node2;
//	else
//		parents[node2] = node1;
//}
//int main() {
//	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//	cin >> n >> m;
//	initParent();
//	for (int i = 0; i < m; i++) {
//		int find, a, b;
//		cin >> find >> a >> b;
//		if (find == 0) {
//			m_union(a, b);
//		}
//		if (find == 1) {
//			if (getParent(a) == getParent(b))
//				cout << "YES" << "\n";
//			else
//				cout << "NO" << "\n";
//		}
//	}
//}

////11650번 문제 b
//bool compare(pair<int, int> p1, pair<int, int> p2) {
//	if (p1.first == p2.first)
//		return p1.second < p2.second;
//	else
//		return p1.first < p2.first;
//}
//int main() {
//	int num;
//	cin >> num;
//	vector<pair<int, int>> v;
//	for (int i = 0; i < num; i++) {
//		int input1, input2;
//		cin >> input1 >> input2;
//		v.push_back(make_pair(input1, input2));
//	}
//	sort(v.begin(), v.end(), compare);
//	for (int i = 0; i < num; i++)
//		cout << v[i].first << " " << v[i].second << "\n";
//}

////2309번 문제 b
//int all[10];
//int dwarf[8], check = 0;
//void f(int search = 0, int sum = 0, int select = 0) {
//	if (search > 9 || sum > 100 || select > 7)
//		return;
//	if (search == 9 && sum == 100 && select == 7 && check == 0) {
//		for (int i = 0; i < 7; i++) {
//			cout << dwarf[i] << endl;
//		}
//		check++;
//		return;
//	}
//	dwarf[select] = all[search];
//	f(search + 1, sum + all[search], select + 1);
//	f(search + 1, sum, select);
//}
//int main() {
//	for (int i = 0; i < 9; i++)
//		cin >> all[i];
//	sort(all, all + 9);
//	f();
//}

////2170번 문제 b
//vector<pair<int, int>> list;
//int main() {
//	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//	int num;
//	cin >> num;
//	for (int i = 0; i < num; i++) {
//		int input1, input2;
//		cin >> input1 >> input2;
//		list.push_back(make_pair(input1, input2));
//	}
//	sort(list.begin(), list.end());
//	int answer = 0;
//	int start = list[0].first, end = list[0].second;
//	for (int i = 1; i < num; i++) {
//		int save_start = list[i].first, save_end = list[i].second;
//		if (end >= save_start) {
//			if (end < save_end)
//				end = save_end;
//		}
//		else {
//			answer += end - start;
//			start = save_start, end = save_end;
//		}
//	}
//	answer += end - start;
//	cout << answer << "\n";
//}

////1939번 문제 b
//vector<pair<int, int>> bridge[10001];
//bool f(int mid, int num, int input1, int input2) {
//	queue<int> q;
//	vector<int> visited(num + 1);
//	visited[input1] = 1;
//	q.push(input1);
//	while (!q.empty()) {
//		int pos = q.front();
//		q.pop();
//		if (pos == input2)
//			return true;
//		for (int i = 0; i < bridge[pos].size(); i++) {
//			int w = bridge[pos][i].first;
//			int next_pos = bridge[pos][i].second;
//			if (!visited[next_pos] && w >= mid) {
//				visited[next_pos] = 1;
//				q.push(next_pos);
//			}
//		}
//	}
//	return false;
//}
//int main(void) {
//	int inform, bridges;
//	int start, end, max_weight = 0, mid, weight;
//	cin >> inform >> bridges;
//	while (bridges--) {
//		cin >> start >> end >> weight;
//		bridge[start].push_back({ weight,end });
//		bridge[end].push_back({ weight,start });
//		max_weight = max(weight, max_weight);
//	}
//	int input1, input2;
//	cin >> input1 >> input2;
//	start = 0;
//	end = max_weight;
//	while (start <= end) {
//		mid = (start + end) / 2;
//		if (f(mid, inform, input1, input2))
//			start = mid + 1;
//		else
//			end = mid - 1;
//	}
//	cout << end;
//}

////1920번 문제 b
//int num, cases, list[1000000];
//int temp;
//void f(int x) {
//	int left = 0, mid = 0, right = num - 1;
//	while (left <= right) {
//		mid = (left + right) / 2;
//		if (list[mid] == x) {
//			cout << 1 << "\n";
//			return;
//		}
//		else if (list[mid] > x)
//			right = mid - 1;
//		else
//			left = mid + 1;
//	}
//	cout << 0 << "\n";
//	return;
//}
//int main() {
//	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//	cin >> num;
//	for (int i = 0; i < num; i++) {
//		cin >> list[i];
//	}
//	sort(list, list + num);
//	cin >> cases;
//	int input;
//	for (int i = 0; i < cases; i++) {
//		cin >> input;
//		f(input);
//	}
//}

////1874번 문제 b
//int main() {
//	stack<int> s;
//	vector<char> result;
//	int count = 1, num;
//	cin >> num;
//	for (int i = 0; i < num; i++) {
//		int input;
//		cin >> input;
//		while (count <= input) {
//			s.push(count);
//			count += 1;
//			result.push_back('+');
//		}
//		if (s.top() == input) {
//			s.pop();
//			result.push_back('-');
//		}
//		else {
//			cout << "NO";
//			return 0;
//		}
//	}
//	for (int i = 0; i < result.size(); i++)
//		cout << result[i] << "\n";
//}

////1753번 문제 b
//#define INF 1000000
//int d[20001];
//vector<pair<int, int> > edge[300001];
//void f(int start_node) {
//	d[start_node] = 0;
//	priority_queue<pair<int, int> > pq;
//	pq.push(make_pair(0, start_node));
//	while (!pq.empty()) {
//		int current = pq.top().second;
//		int start_to_current_distance = -pq.top().first;
//		pq.pop();
//		if (d[current] < start_to_current_distance) {
//			continue;
//		}
//		for (int i = 0; i < edge[current].size(); ++i) {
//			int next = edge[current][i].second;
//			int start_to_next_distance = start_to_current_distance + edge[current][i].first;
//			if (d[next] > start_to_next_distance) {
//				d[next] = start_to_next_distance;
//				pq.push(make_pair(-start_to_next_distance, next));
//			}
//		}
//	}
//}
//int main() {
//	int v, e;
//	cin >> v >> e;
//	int start_node;
//	cin >> start_node;
//	for (int i = 1; i < v + 1; ++i) {
//		d[i] = INF;
//	}
//	for (int i = 0; i < e; ++i) {
//		int start, end, cost;
//		cin >> start >> end >> cost;
//		edge[start].push_back(make_pair(cost, end));
//	}
//	f(start_node);
//	for (int i = 1; i < v + 1; ++i) {
//		if (d[i] == INF) {
//			cout << "INF" << "\n";
//		}
//		else {
//			cout << d[i] << "\n";
//		}
//	}
//}

////1012번 문제 b
//int dy[4] = { 1,-1,0,0 };
//int dx[4] = { 0,0,1,-1 };
//int M, N, K;
//int arr[50][50] = { 0 };
//int visited[50][50] = { 0 };
//void dfs(int y, int x) {
//	for (int i = 0; i < 4; i++) {
//		int ny = y + dy[i];
//		int nx = x + dx[i];
//		if (ny < 0 || ny >= N || nx < 0 || nx >= M)
//			continue;
//		if (arr[ny][nx] && !visited[ny][nx]) {
//			visited[ny][nx]++;
//			dfs(ny, nx);
//		}
//	}
//}
//
//int main() {
//	int T, x, y;
//	scanf("%d", &T);
//	for (int testCase = 0; testCase < T; testCase++) {
//		scanf("%d %d %d", &M, &N, &K);
//		memset(arr, 0, sizeof(arr));
//		memset(visited, 0, sizeof(visited));
//		int answer = 0;
//		for (int i = 0; i < K; i++) {
//			scanf("%d %d", &x, &y);
//			arr[y][x] = 1;
//		}
//		for (int i = 0; i < N; i++)
//			for (int j = 0; j < M; j++)
//				if (arr[i][j] && !visited[i][j]) {
//					answer++;
//					visited[i][j]++;
//					dfs(i, j);
//				}
//		printf("%d\n", answer);
//	}
//}

////17619번 문제 b
//typedef struct pos {
//	int x1, x2, idx;
//};
//int logs, cases, answer, x1, x2, y;
//int parent[100001], list[100001];
//vector<pos> v;
//bool cmp(pos a, pos b) {
//	return a.x1 < b.x1;
//}
//int find_parent(int x) {
//	if (x == parent[x])
//		return x;
//	return parent[x] = find_parent(parent[x]);
//}
//void find(int x, int y) {
//	x = find_parent(x);
//	y = find_parent(y);
//	if (x == y)
//		return;
//	if (list[x] < list[y])
//		swap(x, y);
//	parent[y] = x;
//	list[x] += list[y];
//}
//int main() {
//	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//	cin >> logs >> cases;
//	v.push_back({ 0,0,0 });
//	for (int i = 1; i <= logs; i++) {
//		cin >> x1 >> x2 >> y;
//		v.push_back({ x1,x2,i });
//		parent[i] = i;
//		list[i] = 1;
//	}
//	sort(v.begin(), v.end(), cmp);
//	for (int i = 1, j = 2; i <= logs && j <= logs;) {
//		if (v[j].x1 <= v[i].x2) {
//			find(v[i].idx, v[j].idx);
//			j++;
//		}
//		else
//			i++;
//	}
//	for (int i = 0; i < cases; i++) {
//		cin >> x1 >> x2;
//		if (find_parent(x1) == find_parent(x2))
//			cout << "1" << "\n";
//		else 
//			cout << "0" << "\n";
//	}
//}

////3079번 문제 b
//int main() {
//	unsigned long long num1, num2;
//	unsigned long long list[100001];
//	cin >> num1 >> num2;
//	for (int i = 0; i < num1; i++)
//		cin >> list[i];
//	sort(list, list + num1);
//	unsigned long long top = num2 * list[0],  bottom = 1;
//	unsigned long long mid, answer = 0, people;
//	while (top >= bottom) {
//		people = 0;
//		mid = (top + bottom) / 2;
//		for (int i = 0; i < num1; i++)
//			people += mid / list[i];
//		if (people >= num2) {
//			if (answer > mid || answer == 0)
//				answer = mid;
//			top = mid - 1;
//		}
//		else
//			bottom = mid + 1;
//	}
//	cout << answer;
//}

////2981번 문제 b
//int f(int a, int b) {
//	if (a % b == 0) {
//		return b;
//	}
//	return f(b, a % b);
//}
//int main() {
//	int num;
//	cin >> num;
//	vector<int> v;
//	vector<int> result;
//	for (int i = 0; i < num; i++) {
//		int num;
//		cin >> num;
//		v.push_back(num);
//	}
//	int gcd = abs(v[1] - v[0]);
//	for (int i = 2; i < v.size(); i++)
//		gcd = f(gcd, abs(v[i] - v[i - 1]));
//	for (int i = 2; i * i <= gcd; i++) {
//		if (gcd % i == 0) {
//			result.push_back(i);
//			if (gcd / i != i)
//				result.push_back(gcd / i);
//		}
//	}
//	result.push_back(gcd);
//	sort(result.begin(), result.end());
//	for (int i = 0; i < result.size(); i++)
//		cout << result[i] << " ";
//}

////11050번 문제 b
//int f(int num) {
//	int answer = 1;
//	for (int i = num; i > 0; i--)
//		answer *= i;
//	return answer;
//}
//int main() {
//	int input1, input2;
//	cin >> input1 >> input2;
//	cout << f(input1) / (f(input2) * f(input1 - input2));
//}

////2581번 문제 b
//int main() {
//	int input1, input2, sum = 0, min = -1, count = 0;
//	cin >> input1 >> input2;
//	for (int i = input1; i <= input2; i++) {
//		for (int j = 1; j <= i; j++) {
//			if (i % j == 0)
//				count++;
//		}
//		if (count == 2) {
//			if (min == -1)
//				min = i;
//			sum += i;
//		}
//		count = 0;
//	}
//	if (min == -1)
//		cout << -1;
//	else
//		cout << sum << endl << min;
//}

////2252번 문제 b
//queue<int> q,temp;
//vector<int> save[32001], answer;
//int degree[32001];
//int main() {
//	int	N, M;
//	cin >> N >> M;
//	for (int i = 0; i < M; i++) {
//		int input1, input2;
//		cin >> input1 >> input2;
//		save[input1].push_back(input2);
//		degree[input2]++;
//	}
//	for (int i = 1; i <= N; i++) {
//		if (degree[i] == 0)
//			temp.push(i);
//	}
//	int size = temp.size();
//	for (int i = 0; i < size; i++)
//	{
//		int curr = temp.front();
//		temp.pop();
//		q.push(curr);
//		while (!q.empty())
//		{
//			int next_node = q.front();
//			answer.push_back(next_node);
//			q.pop();
//			for (auto next : save[next_node])
//			{
//				degree[next]--;
//				if (degree[next] == 0)
//				{
//					q.push(next);
//
//				}
//			}
//		}
//	}
//	for (auto i : answer)
//		cout << i << " ";
//}

////17611번 문제 b
//int num, answer_x[500001], answer_y[500001];
//vector<pair<int, int>> list;
//int main() {
//	cin >> num;
//	for (int i = 0; i < num; i++) {
//		int input1, input2;
//		cin >> input1 >> input2;
//		input1 += 500000;
//		input2 += 500000;
//		list.push_back({input1, input2});
//	}
//	for (int i = 0; i < num; i++) {
//		int cur_x = list[i].first;
//		int cur_y = list[i].second;
//		int next_x = list[(i + 1) % num].first;
//		int next_y = list[(i + 1) % num].second;
//		if (cur_x == next_x) {
//			int min_y = min(cur_y, next_y);
//			int max_y = max(cur_y, next_y);
//			answer_y[min_y]++;
//			answer_y[max_y]--;
//		}
//		else {
//			int min_x = min(cur_x, next_x);
//			int max_x = max(cur_x, next_x);
//			answer_x[min_x]++;
//			answer_x[max_x]--;
//		}
//	}
//	for (int i = 1; i < 100010; i++) {
//		answer_x[i] += answer_x[i - 1];
//		answer_y[i] += answer_y[i - 1];
//	}
//	int answer = 0;
//	for (int i = 1; i < 100010; i++)
//		answer = max(max(answer_x[i], answer_y[i]), answer);
//	cout << answer;
//}

////1939번 문제 b
//vector<pair<int, int>> node[100001];
//queue<pair<int, int>> q;
//int visit[1000001];
//int total_island, total_bridge;
//int check()
//int main() {
//	cin >> total_island >> total_bridge;
//	int max_weight = 0, answer = 0;
//	for (int i = 0; i < total_bridge; i++) {
//		int input1, input2, weight;
//		cin >> input1 >> input2 >> weight;
//		if (max_weight < weight)
//			max_weight = weight;
//		int che = 0;
//		for (auto data : node[input1])
//		{
//			int no = data.first;
//			int w = data.second;
//			if (no == input2)
//			{
//				if(w<weight)
//					node
//			}
//		}
//		node[input1].push_back({ input2, weight });
//	}
//	int first_factory, second_factory;
//	cin >> first_factory >> second_factory;
//	int left = 0;
//	int right = max_weight;
//	while (left <= right) {
//		int mid = (left + right) / 2, passed = 1;
//		q.push({ first_factory, mid });
//		while (!q.empty()) {
//			int cur_node = q.front().first;
//			if (cur_node == second_factory) {
//				passed = 0;
//				break;
//			}
//			q.pop();
//			for (int i = 0; i < node[cur_node].size(); i++) {
//				int next_node = node[cur_node][i].first;
//				int next_save = node[cur_node][i].second;
//				if (visit[next_node] == 0) {
//					visit[next_node] = 1;
//					if (next_save >= mid) {
//						q.push({ next_node, next_save });
//					}
//				}
//			}
//		}
//		if (passed == 0) {
//			cout << mid << endl;
//			answer = mid;
//			left = mid + 1;
//		}
//		else
//			right = mid - 1;
//	}
//	cout << answer;
//}

////17070번 문제 b
//int dp[17][17][3];
//int list[17][17];
//int main() {
//	int num;
//	cin >> num;
//	for (int i = 0; i < num; i++) {
//		for (int j = 0; j < num; j++)
//			cin >> list[i][j];
//	}
//	dp[0][1][0] = 1;
//	for (int i = 0; i < num; i++) {
//		for (int j = 1; j < num; j++) {
//			if (list[i][j] == 1)
//				continue;
//			dp[i][j][0] += dp[i][j - 1][0] + dp[i][j - 1][2];
//			if (i - 1 < 0)
//				continue;
//			dp[i][j][1] += dp[i - 1][j][1] + dp[i - 1][j][2];
//			if (list[i - 1][j] || list[i][j - 1])
//				continue;
//			dp[i][j][2] += dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
//		}
//	}
//	int answer = 0;
//	for (int i = 0; i < 3; i++)
//		answer += dp[num - 1][num - 1][i];
//	cout << answer;
//}

////1021번 문제 b
//int main() {
//	deque<int> list;
//	int size, pop_count;
//	cin >> size >> pop_count;
//	for (int i = 1; i <= size; i++) {
//		list.push_back(i);
//	}
//	int left = 0, right = 0, answer = 0;
//	while (pop_count--) {
//		int input;
//		cin >> input;
//		for (int i = 0; i < list.size(); i++) {
//			if (list[i] == input) {
//				left = i;
//				right = list.size() - i;
//				break;
//			}
//		}
//		if (left <= right) {
//			while (true) {
//				if (list.front() == input)
//					break;
//				list.push_back(list.front());
//				list.pop_front();
//				answer++;
//			}
//			list.pop_front();
//		}
//		else {
//			answer++;
//			while (true) {
//				if (list.back() == input)
//					break;
//				list.push_front(list.back());
//				list.pop_back();
//				answer++;
//			}
//			list.pop_back();
//		}
//	}
//	cout << answer;
//}

////1167번 문제 b
//int visit[100001], answer = 0, save = 0;
//vector<pair<int, int>> list[100001];
//void f(int node, int distance) {
//	visit[node] = 1;
//	if (answer < distance) {
//		answer = distance;
//		save = node;
//	}
//	for (auto& i : list[node]) {
//		if (visit[i.first] == 0)
//			f(i.first, distance + i.second);
//	}
//}
//int main() {
//	int num;
//	cin >> num;
//	for (int i = 0; i < num; i++) {
//		int input;
//		cin >> input;
//		while (true) {
//			int next_node, distance;
//			cin >> next_node;
//			if (next_node == -1)
//				break;
//			cin >> distance;
//			list[input].emplace_back(next_node, distance);
//		}
//	}
//	f(1, 0);
//	memset(visit, 0, sizeof(visit));
//	f(save, 0);
//	cout << answer;
//}

////3020번 문제 b
//int main() {
//	vector<int> bottom, top;
//	int stone, height, answer = 0;
//	cin >> stone >> height;
//	int min = stone;
//	for (int i = 0; i < stone / 2; i++) {
//		int input1, input2;
//		cin >> input1 >> input2;
//		bottom.push_back(input1);
//		top.push_back(height - input2);
//	}
//	sort(bottom.begin(), bottom.end());
//	sort(top.begin(), top.end());
//	for (int i = 0; i < height; i++) {
//		int temp = lower_bound(bottom.begin(), bottom.end(), i) - bottom.begin();
//		int count = stone / 2 - temp;
//		temp = lower_bound(top.begin(), top.end(), i) - top.begin();
//		count += temp;
//		if (count < min) {
//			min = count;
//			answer = 1;
//		}
//		else if (count == min)
//			answer++;
//	}
//	cout << min << " " << answer;
//}

////1300번 문제 b
//int main() {
//	long long int size, input, answer = 0;
//	cin >> size >> input;
//	long long int start = 1, end = size * size;
//	while (start <= end) {
//		long long mid = (start + end) / 2;
//		long long int compare = 0;
//		for (int i = 1; i <= size; i++) {
//			compare += min(size, (long long int)mid / i);
//			if (i > mid)
//				break;
//		}
//		if (compare < input)
//			start = mid + 1;
//		else {
//			answer = mid;
//			end = mid - 1;
//		}
//	}
//	cout << answer;
//}

////2156번 문제 b
//int list[10001] = { 0 }, dp[10001] = { 0 };
//int main() {
//	int num;
//	cin >> num;
//	for (int i = 0; i < num; i++)
//		cin >> list[i];
//	dp[0] = list[0];
//	dp[1] = list[0] + list[1];
//	dp[2] = max(dp[1], max(dp[0] + list[2], list[1] + list[2]));
//	for (int i = 3; i < num; i++) {
//		dp[i] = max(dp[i - 1], max(dp[i - 3] + list[i - 1] + list[i], dp[i - 2] + list[i]));
//	}
//	cout << dp[num - 1];
//}

////2981번 문제 b
//int f(int num1, int num2) {
//	if (num2 == 0)
//		return num1;
//	return f(num2, num1 % num2);
//}
//int main() {
//	int num, list[101] = { 0 }, save[101] = { 0 };
//	cin >> num;
//	for (int i = 0; i < num; i++) {
//		cin >> list[i];
//	}
//	sort(list, list + num);
//	for (int i = 0; i < num - 1; i++) {
//		save[i] = list[i + 1] - list[i];
//	}
//	sort(save, save + num - 1);
//	for (int i = 0; i < num - 2; i++) {
//		save[i] = f(save[i], save[i + 1]);
//	}
//	for (int i = 2; i <= save[num - 3]; i++) {
//		if (save[num - 3] % i == 0)
//			cout << i << " ";
//	}
//}

////1966번 문제 b
//int main() {
//	int count = 0, testcase;
//	cin >> testcase;
//	int num1, num2, important;
//	for (int i = 0; i < testcase; ++i) {
//		count = 0;
//		cin >> num1 >> num2;
//		queue<pair<int, int>> q;
//		priority_queue<int> pq;
//		for (int j = 0; j < num1; ++j) {
//			cin >> important;
//			q.push({ j, important });
//			pq.push(important);
//		}
//		while (!q.empty()) {
//			int index = q.front().first;
//			int value = q.front().second;
//			q.pop();
//			if (pq.top() == value) {
//				pq.pop();
//				++count;
//				if (index == num2) {
//					cout << count << endl;
//					break;
//				}
//			}
//			else
//				q.push({ index,value });
//		}
//	}
//}

////1874번 문제 b
//int main(void) {
//	vector<char> answer;
//	stack<int> input;
//	int num;
//	int temp = 1;
//	cin >> num;
//	for (int i = 0; i < num; i++) {
//		int input_num;
//		cin >> input_num;
//		while (temp <= input_num) {
//			input.push(temp);
//			temp++;
//			answer.push_back('+');
//		}
//		if (input.top() == input_num) {
//			input.pop();
//			answer.push_back('-');
//		}
//		else {
//			cout << "NO";
//			return 0;
//		}
//	}
//	for (int i = 0; i < answer.size(); i++)
//		cout << answer[i] << endl;
//}

////28216번 문제 b
//int list[1000001][2];
//vector<pair<int, int>> v;
//int com(pair<int,int> p1,pair<int,int> p2)
//{
//	return p1.first < p2.first;
//}
//int main() {
//	int num, answer = 0;
//	cin >> num;
//	v.resize(num);
//	for (int i = 0; i < num; i++) {
//		cin >> v[i].first >> v[i].second;
//		if (v[i].first > v[i].second) {
//			int temp = v[i].first;
//			v[i].first = v[i].second;
//			v[i].second = temp;
//		}
//	}
//	sort(v.begin(), v.end(), com);
//	int x1 = 0, x2 = 0;
//	for (int i = 0; i < num; i++) {
//		if (x1 == 0 && x2 == 0 && i == 0) {
//			x1 = v[i].first;
//			x2 = v[i].second;
//		}
//		if (x1 <= v[i].first && v[i].first <= x2)
//			x2 = v[i].second;
//		else {
//			answer += x2 - x1;
//			x1 = v[i].first;
//			x2 = v[i].second;
//		}
//	}
//	answer += x2 - x1;
//	cout << answer;
//}

////25378번 문제 b
//int dp[2501], list[2501];
//int main() {
//	int num;
//	cin >> num;
//	for (int i = 1; i <= num; i++)
//		cin >> list[i];
//	for (int i = 1; i <= num; i++) {
//		int remain = list[i];
//		dp[i] = max(dp[i], dp[i - 1]);
//		for (int j = i + 1; j <= num; j++) {
//			remain = list[j] - remain;
//			if (remain < 0)
//				break;
//			if (remain == 0) {
//				dp[j] = max(dp[j], dp[i - 1] + 1);
//				break;
//			}
//		}
//	}
//	cout << num - dp[num];
//}

////1949번 문제 b
//vector<int> list[10001];
//int visited[10001], dp[10001][2], citizen[10001];
//int num, answer = -1;
//void f(int num) {
//	dp[num][0] = citizen[num];
//	dp[num][1] = 0;
//	for (int next : list[num]) {
//		if (visited[num] == next)
//			continue;
//		visited[next] = num;
//		f(next);
//		dp[num][0] += dp[next][1];
//		dp[num][1] += max(dp[next][0], dp[next][1]);
//		answer = max(dp[num][0], dp[num][1]);
//	}
//}
//int main() {
//	cin >> num;
//	for (int i = 1; i <= num; i++)
//		cin >> citizen[i];
//	for (int i = 0; i < num - 1; i++) {
//		int input1, input2;
//		cin >> input1 >> input2;
//		list[input1].push_back(input2);
//		list[input2].push_back(input1);
//	}
//	f(1);
//	cout << answer;
//}

////2533번 문제 b
//vector <int> list[1000000];
//int visited[1000001];
//int num, answer = 0;
//int f(int num) {
//	visited[num] = 1;
//	int save[2] = { 0, 0 };
//	for (int i = 0; i < list[num].size(); i++) {
//		int next_num = list[num][i];
//		if (visited[next_num] == 0)
//			save[f(next_num)]++;
//	}
//	if (save[0] != 0) {	
//		answer++;
//		return 1;
//	}
//	return 0;
//}
//int main() {
//	cin >> num;
//	for (int i = 0; i < num - 1; i++) {
//		int input1, input2;
//		cin >> input1 >> input2;
//		list[input1].push_back(input2);
//		list[input2].push_back(input1);
//	}
//	f(1);
//	cout << answer;
//}

////15681번 문제 b
//vector<int> list[100001];
//int dp[100001];
//int visited[100001];
//void f(int num) {
//	visited[num] = 1;
//	for (auto next : list[num])
//	{
//		if (!visited[next])
//		{
//			f(next);
//			dp[num] += (dp[next] + 1);
//		}
//	}
//}
//int main() {
//	std::ios_base::sync_with_stdio(false);
//	std::cin.tie(NULL);
//	std::cout.tie(NULL);
//	int point, num, cases;
//	cin >> point >> num >> cases;
//	
//	for (int i = 0; i < point - 1; i++) {
//		int input1, input2;
//		cin >> input1 >> input2;
//
//		list[input1].push_back(input2);
//		list[input2].push_back(input1);
//	}
//	
//	f(num);
//	for (int i = 0; i < cases; i++) {
//		int input;
//		cin >> input;
//		cout << dp[input] + 1 << endl;
//	}
//}

////19940번 문제 b
//int main() {
//	int cases;
//	cin >> cases;
//	for (int i = 0; i < cases; i++) {
//		int input, answer[5] = { 0 };
//		cin >> input;
//		answer[0] = input / 60;
//		input -= (answer[0] * 60);
//		if (input > 35) {
//			answer[0]++;
//			input -= 60;
//		}
//		if (input < 0) {
//			answer[2] = abs(input / 10);
//			input += answer[2] * 10;
//			if (input < -5) {
//				answer[2]++;
//				input += 10;
//			}
//		}
//		else {
//			answer[1] = abs(input / 10);
//			input -= answer[1] * 10;
//			if (input > 5) {
//				answer[1]++;
//				input -= 10;
//			}
//		}
//		if (input > 0)
//			answer[3] = input;
//		else
//			answer[4] = -input;
//		cout << answer[0] << " " << answer[1] << " " << answer[2] << " " << answer[3] << " " << answer[4] << endl;
//	}
//}

////28323번 문제 b
//stack<int> answer;
//int list[300001];
//int main() {
//	int num, compare = 0;
//	cin >> num;
//	for (int i = 0; i < num; i++) {
//		cin >> list[i];
//	}
//	answer.push(list[0]);
//	for (int i = 1; i < num; i++) {
//		if (answer.top() % 2 != list[i] % 2)
//			answer.push(list[i]);
//	}
//	cout << answer.size() << endl;
//}

////28215번 문제 b
//int list[100001][2], houses;
//int f(int shelter1, int shelter2, int shelter3) {
//	int MAX = 0;
//	for (int i = 0; i < houses; i++) {
//		if (i == shelter1 || i == shelter2 || i == shelter3)
//			continue;
//		MAX = max(min(min(abs(list[i][0] - list[shelter1][0]) + abs(list[i][1] - list[shelter1][1]),
//					  abs(list[i][0] - list[shelter2][0]) + abs(list[i][1] - list[shelter2][1])),
//					  abs(list[i][0] - list[shelter3][0]) + abs(list[i][1] - list[shelter3][1])), MAX);
//	}
//	return MAX;
//}
//int main() {
//	int sheleter, answer = 0x7fffffff;
//	cin >> houses >> sheleter;
//	for (int i = 0; i < houses; i++)
//		cin >> list[i][0] >> list[i][1];
//	if (sheleter == 1) {
//		for (int i = 0; i < houses; i++) {
//			answer = min(answer, f(i, i, i));
//		}
//	}
//	else if (sheleter == 2) {
//		for (int i = 0; i < houses; i++) {
//			for (int j = 0; j < houses; j++)
//				answer = min(answer, f(i, i, j));
//		}
//	}
//	else if (sheleter == 3) {
//		for (int i = 0; i < houses; i++) {
//			for (int j = 0; j < houses; j++) {
//				for (int k = 0; k < houses; k++)
//					answer = min(answer, f(i, j, k));
//			}
//		}
//	}
//	cout << answer << endl;
//}

////28325번 문제 b
//long long int list[500001];
//int main() {
//	long long int num, answer = 0, sum = 0, start = 0;
//	cin >> num;
//	for (long long int i = 0; i < num; i++) {
//		cin >> list[i];
//		sum += list[i];
//		list[i + num] = list[i];
//	}
//	if (sum == 0) {
//		cout << num / 2;
//		return 0;
//	}
//	for (int i = 0; i < num; i++) {
//		if (list[i] != 0) {
//			start = i;
//			break;
//		}
//	}
//	int total = 0;
//	for (int i = start; i < num + start; i++) {
//		if (list[i] != 0) {
//			answer += list[i];
//			answer += (total + 1) / 2;
//			total = 0;
//		}
//		else {
//			total += 1;
//		}
//
//	}
//	answer += (total + 1) / 2;
//	cout << answer << endl;
//}

////28218번 문제 b
//int num1, num2, moves, cases;
//string input[301];
//int check[301][301];
//int f(int i, int j) {
//	if (0 <= i && i < num1 && 0 <= j && j < num2) {
//		if (input[i][j] == '.' && check[i][j] == 0)
//			return true;
//	}
//	return false;
//}
//int main() {
//	cin >> num1 >> num2 >> moves;
//	for (int i = 0; i < num1; i++)
//		cin >> input[i];
//	for (int i = num1 - 1; i >= 0; i--) {
//		for (int j = num2 - 1; j >= 0; j--) {
//			if (f(i + 1, j)) {
//				check[i][j] = 1;
//				continue;
//			}
//			if (f(i, j + 1)) {
//				check[i][j] = 1;
//				continue;
//			}
//			for (int k = 1; k <= moves; k++) {
//				if (f(i + k, j + k)) {
//					check[i][j] = 1;
//					break;
//				}
//			}
//		}
//	}
//	cin >> cases;
//	for (int i = 0; i < cases; i++) {
//		int pos_x, pos_y;
//		cin >> pos_x >> pos_y;
//		if (check[pos_y - 1][pos_x - 1] == 1)
//			cout << "First" << endl;
//		else
//			cout << "Second" << endl;
//	}
//}

////28324번 문제 b
//int main() {
//	long long int total;
//	vector<long long int> list;
//	cin >> total;
//	list.resize(total);
//	for (int i = 0; i < total; i++)
//		cin >> list[i];
//	long long int answer = 0, temp = 0;
//	for (long long int i = total - 1; i >= 0; i--) {
//		if (list[i] > temp)
//			temp++;
//		else
//			temp = list[i];
//		answer += temp;
//	}
//	cout << answer;
//}

////3079번 문제 b
//vector<int> list;
//int main() {
//	int num1, num2;
//	cin >> num1 >> num2;
//	list.resize(num1);
//	long long int MAX = 0;
//	for (int i = 0; i < num1; ++i) {
//		cin >> list[i];
//		MAX = max((long long int)list[i], MAX);
//	}
//	long long int left = 1, right = MAX * num2;
//	long long int answer = 0;
//	while (left <= right) {
//		long long int mid = (left + right) / 2;
//		long long int sum = 0;
//		for (int i = 0; i < num1; ++i)
//			sum += mid / list[i];
//		if (sum < num2)
//			left = mid + 1;
//		else {
//			answer = mid;
//			right = mid - 1;
//		}
//	}
//	cout << answer;
//}

////1012번 문제 b
//int num1, num2, pos_total;
//int list[51][51];
//int check[51][51];
//int dx[4] = { 0, 0, 1, -1 };
//int dy[4] = { 1, -1, 0, 0 };
//int f(int y, int x) {
//	if (check[y][x])
//		return 0;
//	check[y][x] = 1;
//	for (int i = 0; i < 4; i++) {
//		int next_x = x + dx[i];
//		int next_y = y + dy[i];
//		if (next_x >= 0 && next_y >= 0 && next_x < num2 && next_y < num1 && list[next_y][next_x])
//			f(next_y, next_x);
//	}
//	return 1;
//}
//int main(void) {
//	int cases;
//	cin >> cases;
//	for (int i = 0; i < cases; i++) {
//		cin >> num2 >> num1 >> pos_total;
//		for (int j = 0; j < pos_total; j++) {
//			int x = 0, y = 0;
//			cin >> x >> y;
//			list[y][x] = 1;
//		}
//		int answer = 0;
//		for (int j = 0; j < num1; j++) {
//			for (int k = 0; k < num2; k++) {
//				if (list[j][k] && !check[j][k]) { 
//					if (f(j, k))
//						answer++;
//				}
//			}
//		}
//		cout << answer;
//	}
//}

//----------mixed codeup, baekjoon problems----------
////2953번 문제
//int main() {
//	int MAX = -1, count, input, num;
//	for (int i = 0; i < 5; i++) {
//		count = 0;
//		for (int j = 0; j < 4; j++) {
//			scanf("%d", &input);
//			count += input;
//		}
//		if (MAX < count) {
//			MAX = count;
//			num = i + 1;
//		}
//	}
//	printf("%d %d", num, MAX);
//}
//
////10797번 문제
//int main() {
//	int num, count = 0;
//	scanf("%d", &num);
//	for (int i = 0; i < 5; i++) {
//		int input;
//		scanf("%d", &input);
//		if (num % 10 == input)
//			count++;
//	}
//	printf("%d", count);
//}
//
//15727번 문제
//int main() {
//	int num;1
//	scanf("%d", &num);
//	if (num % 5 == 0)
//		printf("%d", num / 5);
//	else
//		printf("%d", num / 5 + 1);
//}
//
////14681번 문제
//int main() {
//	int num1, num2;
//	scanf("%d %d", &num1, &num2);
//	if (num1 > 0 && num2 > 0)
//		printf("1");
//	else if (num1 < 0 && num2 > 0)
//		printf("2");
//	else if (num1 < 0 && num2 < 0)
//		printf("3");
//	else
//		printf("4");
//}
//
////11966번 문제
//int main() {
//	int num, cnt = 1;
//	scanf("%d", &num);
//	for (int i = 1; i < num + 1; i++) {
//		if (num == cnt) {
//			printf("1");
//			return 0;
//		}
//		cnt = cnt * 2;
//	}
//	printf("0");
//}
//
////11134번 문제
//int main() {
//	int num;
//	scanf("%d", &num);
//	for (int i = 0; i < num; i++) {
//		int num1, num2;
//		scanf("%d %d", &num1, &num2);
//		if (num1 % num2 == 0) {
//			printf("%d\n", num1 / num2);
//		}
//		else
//			printf("%d\n", num1 / num2 + 1);
//	}
//}
//
////11006번 문제
//int main() {
//	int num;
//	scanf("%d", &num);
//	while (num--)
//	{
//		int c1, cnt;
//		scanf("%d %d", &c1, &cnt);
//		int temp=cnt * 2 - c1;
//		printf("%d %d\n", temp, cnt - temp);
//	}
//}
//
//10824번 문제
//int main() {
//	long long a, b, c, d;
//	scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
//	long long temp = b;
//	long long cnt = 0;
//	while (temp > 0)
//	{
//		temp /= 10;
//		cnt++;
//	}
//	long long cc=a*(long long)(pow(10,cnt)) + b;
//	temp = d;
//	cnt = 0;
//	while (temp > 0)
//	{
//		temp /= 10;
//		cnt++;
//	}
//	long long dd = c * (long long)(pow(10, cnt)) + d;
//
//	printf("%lld", cc + dd);
//
//	/*long long num1, num2, num3, num4, n1, n2, count = 0, cnt = 0;
//	scanf("%d %d %d %d", &num1, &num2, &num3, &num4);
//	n1 = num2;
//	n2 = num4;
//	while (n1 != 0)
//	{
//		n1 = n1 / 10;
//		count++;
//	}
//	while (n2 != 0)
//	{
//		n2 = n2 / 10;
//		cnt++;
//	}
//	for (int i = 0; i < count; i++) {
//		num1 = num1 * 10;
//	}
//	for (int i = 0; i < cnt; i++) {
//		num3 = num3 * 10;
//	}
//	printf("%lld", (num1 + num2) + (num3 + num4));*/
//	}
//
//	//5618번 문제
//	int main() {
//		int num;
//		scanf("%d", &num);
//		if (num == 2) {
//			int num1, num2;
//			scanf("%d %d", &num1, &num2);
//			if (num1 > num2) {
//				for (int i = 1; i < num2 + 1; i++) {
//					if (num1 % i == 0 && num2 % i == 0)
//						printf("%d\n", i);
//				}
//			}
//			else {
//				for (int i = 1; i < num1 + 1; i++) {
//					if (num1 % i == 0 && num2 % i == 0)
//						printf("%d\n", i);
//				}
//			}
//		}
//		else {
//			int num1, num2, num3;
//			scanf("%d %d %d", &num1, &num2, &num3);
//			if (num1 < num2 && num1 < num3) {
//				for (int i = 1; i < num1 + 1; i++) {
//					if (num1 % i == 0 && num2 % i == 0 && num3 % i == 0)
//						printf("%d\n", i);
//				}
//			}
//			else if (num2 < num3 && num2 < num1) {
//				for (int i = 1; i < num2 + 1; i++) {
//					if (num1 % i == 0 && num2 % i == 0 && num3 % i == 0)
//						printf("%d\n", i);
//				}
//			}
//			else {
//				for (int i = 1; i < num3 + 1; i++) {
//					if (num1 % i == 0 && num2 % i == 0 && num3 % i == 0)
//						printf("%d\n", i);
//				}
//			}
//		}
//	}
//
//	//3003번 문제
//	int main() {
//		int list[7] = { 1, 1, 2, 2, 2, 8 };
//		for (int i = 0; i < 6; i++) {
//			int num;
//			scanf("%d", &num);
//			printf("%d ", list[i] - num);
//		}
//	}
//
//	//2875번 문제
//	int main() {
//		int num1, num2, num3, max;
//		scanf("%d %d %d", &num1, &num2, &num3);
//		if (num1 / 2 < num2)
//			max = num1 / 2;
//		else
//			max = num2;
//		num3 -= num1 + num2 - 3 * max;
//		if (num3 > 0) {
//			num3--;
//			max -= num3 / 3 + 1;
//		}
//		printf("%d", max);
//	}
//
//	//2845번 문제
//	int main() {
//		int num1, num2;
//		scanf("%d %d", &num1, &num2);
//		for (int i = 0; i < 5; i++) {
//			int num;
//			scanf("%d", &num);
//			printf("%d ", num - num1 * num2);
//		}
//	}
//
//	//2588번 문제
//	int main() {
//		int num1, num2;
//		scanf("%d", &num1);
//		scanf("%d", &num2);
//		printf("%d\n", num1 * (num2 - ((num2 / 10) * 10)));
//		printf("%d\n", num1 * (num2 - (((num2 / 100) * 100) + num2 - (num2 / 10) * 10)) / 10);
//		printf("%d\n", num1 * (num2 / 100));
//		printf("%d\n", num1 * num2);
//	}
//
//	//2476번 문제
//	int main() {
//		int num, MAX = 0;
//		scanf("%d", &num);
//		for (int i = 0; i < num; i++) {
//			int num1, num2, num3, total = 0;
//			scanf("%d %d %d", &num1, &num2, &num3);
//			if (num1 == num2 && num2 == num3) {
//				total += 10000 + num2 * 1000;
//			}
//			else if (num1 == num2 || num2 == num3) {
//				total = 1000 + num2 * 100;
//			}
//			else if (num3 == num1) {
//				total = 1000 + num1 * 100;
//			}
//			else {
//				if (num1 > num2 && num1 > num3)
//					total = num1 * 100;
//				else if (num2 > num3 && num2 > num1)
//					total = num2 * 100;
//				else if (num3 > num2 && num3 > num1)
//					total = num3 * 100;
//			}
//			if (MAX < total)
//				MAX = total;
//		}
//		printf("%d", MAX);
//	}
//
//	//2475번 문제
//	int main() {
//		int num = 0, cnt = 0;
//		for (int i = 0; i < 5; i++) {
//			scanf("%d", &num);
//			cnt += num * num;
//		}
//		printf("%d", cnt % 10);
//	}
//
//	//2420번 문제
//	int main() {
//		long long num1, num2;
//		scanf("%lld %lld", &num1, &num2);
//		if (num1 > num2)
//			printf("%lld", num1 - num2);
//		else
//			printf("%lld", num2 - num1);
//	}
//
//	1712번 문제
//	int main() {
//		int num1, num2, num3, cnt = 1;
//		scanf("%d %d %d", &num1, &num2, &num3);
//		if (num2 >= num3) {
//			printf("-1");
//			return 0;`
//		}
//	
//		printf("%d", num1 / (num3 - num2) + 1);
//	}
//
//
//	//1110번 문제
//	int main() {
//		int num, num1 = 0, num2 = 0, num3 = 0, total = 1;
//		scanf("%d", &num);
//		if (num < 10) {
//			num = num * 10;
//		}
//		num3 = num;
//		while (1) {
//			num1 += (num % 10) + (num - num % 10) / 10;
//			num2 += num % 10 * 10 + num1 % 10;
//			if (num3 == num2) {
//				printf("%d", total);
//				return;
//			}
//			else {
//				num = num2;
//				num1 = 0;
//				num2 = 0;
//			}
//			total++;
//		}
//	}
//
//
//
//
//
//
//
//
//
//
//
//
//	//f(탐색 위ㅣ, 현재까지 구한 해)
//	//하나는 +, 하나는 -
//	//0, 0 /  1, 1    1,-1
//	int n, k, cnt;
//	int f(int idx, int chair) {
//		if (idx == n && chair == k) {
//			cnt++;
//			return;
//		}
//		else if (idx > n || chair > k)
//			return;
//		else {
//			f(idx + 1, chair);
//		}
//	}
//	int list[444] = { 0 };
//	int main() {
//		int num;
//		scanf("%d", &n);
//		scanf("%d", &num);
//		for (int i = 0; i < num; i++) {
//			int input = 0;
//			scanf("%d", &input);
//			list[i] = num;
//		}
//		f(0, 0);
//		printf("%d", cnt);
//	}
//	
//	//int save[1000001] = { 0 };
//	//int main() {
//	//	int input, input1, maxium = -1, answer = 0 ;
//	//	scanf("%d %d", &input, &input1);
//	//	for (int i = 0; i < input; i++) {
//	//		int num;
//	//		scanf("%d", &num);
//	//		save[i] = num;
//	//		if (num > maxium)
//	//			maxium = num;
//	//	}
//	//	int left = 1, right = maxium, find;
//	//	find = input1;
//	//
//	//	while (1) {
//	//		int mid = (left + right) / 2;
//	//		answer = 1;
//	//		for (int i = 0; i < input; i++) {
//	//			answer += save[i] / mid;
//	//		}
//	//		printf("left : %d, right : %d, mid : %d, answer : %d\n", left, right, mid, answer);
//	//		if (answer < input1)
//	//			right = mid - 1;
//	//		else if (answer > input1)
//	//			left = mid + 1;
//	//		else {
//	//			printf("%d", mid - 1);
//	//			break;
//	//		}
//	//	}
//	//}
//	//int list[10001] = { 0 };
//	//int main() {
//	//	int num, total_budget, max_budget = 0, answer = 0, max = 0;
//	//	scanf("%d", &num);
//	//	for (int i = 0; i < num; i++) {
//	//		int input;
//	//		scanf("%d", &input);
//	//		list[i] = input;
//	//		if (max < input)
//	//			max = input;
//	//	}
//	//	scanf("%d", &total_budget);
//	//	int left = 0, right = max;
//	//	while (left <= right) {
//	//		int mid = (left + right) / 2;
//	//		int sum_budget = 0;
//	//		for (int i = 0; i < num; i++) {
//	//			if (list[i] > mid)
//	//				sum_budget += mid;
//	//			else
//	//				sum_budget += list[i];
//	//		}
//	//		printf("left : %d, right : %d, mid : %d, sum_budget : %d\n", left, right, mid, sum_budget);
//	//		if (sum_budget <= total_budget) {
//	//			if (max_budget < sum_budget) {
//	//				max_budget = sum_budget;
//	//				answer = mid;
//	//			}
//	//			left = mid + 1;
//	//		}
//	//		else if (sum_budget > total_budget) {
//	//			right = mid - 1;
//	//		}
//	//	}
//	//	printf("%d", answer);
//	//}
//	//int list[100001] = { 0 };
//	//int main() {
//	//	int scan, people, maxium = 0, minium, answer = 0;
//	//	scanf("%d %d", &scan, &people);
//	//	for (int i = 0; i < scan; i++) {
//	//		int input;
//	//		scanf("%d", &input);
//	//		list[i] = input;
//	//		if (maxium < input)
//	//			maxium = input;
//	//	}
//	//	
//	//	int left = 0, right = maxium * people;
//	//	
//	//	while (left <= right) {
//	//		int mid = (left + right) / 2;
//	//		minium = 0;
//	//		for (int i = 0; i < scan; i++)
//	//			minium += mid / list[i];
//	//		//printf("left : %d, right : %d, mid : %d, minium : %d\n", left, right, mid, minium);
//	//		if (people <= minium) {
//	//			answer = mid;
//	//			right = mid - 1;
//	//		}
//	//		else if (people > minium)
//	//			left = mid + 1;
//	//	}
//	//	printf("%d", answer);
//	//}

////4053번 문제
//#include <stdio.h>
//#include <stdlib.h>
//#pragma warning(disable:4996)
//
//int save[101][101] = { 0 };
//int num1, num2;
//int answer = 0;
//int visit[101] = { 0 };
//void f(int x) {
//    for (int i = 1; i <= num1; ++i) {
//        if (save[x][i] == 0)
//            continue;
//        if (visit[i] == 1)
//            continue;
//        visit[i] = 1;
//        ++answer;
//        f(i);
//    }
//}
//int main() {
//
//    scanf("%d", &num1);
//    scanf("%d", &num2);
//    int a, b;
//    for (int i = 0; i < num2; ++i) {
//        scanf("%d %d", &a, &b);
//        save[a][b] = 1;
//        save[b][a] = 1;
//    }
//    f(1);
//    printf("%d", answer - 1);
//    return 0;
//}

////1451번 문제
//int save[10001] = { 0 }, num;;
//f(){
//	for (int i = num - 1; i >= 0; i--) {
//		for (int j = i; j < num - 1; j++) {
//			if (save[j] > save[j + 1]) {
//				int a = save[j + 1];
//				save[j + 1] = save[j];
//				save[j] = a;
//			}
//		}
//	}
//}
//int main() {
//	scanf("%d", &num);
//	for (int i = 0; i < num; i++) {
//		scanf("%d", &save[i]);
//	}
//	f();
//	for (int i = 0; i < num; i++) {
//		printf("%d\n", save[i]);
//	}
//}

////2610번 문제
//char list[11][11] = { 0 }, save[11][11] = { 0 };
//int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };
//void f(int x, int y) {
//	save[x][y] = 1;
//	for (int i = 0; i < 4; i++) {
//		int cx = x + dx[i], cy = y + dy[i];
//		if (0 <= cx && cx < 10 && 0 <= cy && cy < 10 && save[cx][cy] == 0 && list[cx][cy] == '_') {
//			list[cx][cy] = '*';
//			f(cx, cy);
//		}
//	}
//}
//int main() {
//	int pos_x, pos_y;
//	for (int i = 0; i < 10; i++) {
//		scanf("%s", list[i]);
//	}
//	scanf("%d %d", &pos_y, &pos_x);
//	if (list[pos_x][pos_y] != '*') {
//		list[pos_x][pos_y] = '*';
//		f(pos_x, pos_y);
//	}
//	for (int i = 0; i < 10; i++) {
//		for (int j = 0; j < 10; j++) {
//			printf("%c", list[i][j]);
//		}
//		printf("\n");
//	}
//}

////2605번 문제
//int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };
//int list[26][26] = { 0 }, save[26][26] = { 0 }, answer = 0, cnt;
//void dfs(int x, int y, int color) {
//	save[x][y] = 1;
//	cnt++;
//	for (int i = 0; i < 4; i++) {
//		int cx = x + dx[i];
//		int cy = y + dy[i];
//		if (0 <= cx && cx < 7 && 0 <= cy && cy < 7 && save[cx][cy] == 0 && list[cx][cy] == color)
//			dfs(cx, cy, color);
//	}
//}
//int main() {
//	for (int i = 0; i < 7; i++) {
//		for (int j = 0; j < 7; j++)
//			scanf("%d", &list[i][j]);
//	}
//	for (int i = 0; i < 7; i++) {
//		for (int j = 0; j < 7; j++) {
//			if (save[i][j] == 0) {
//				cnt = 0;
//				dfs(i, j, list[i][j]);
//				if (cnt >= 3)
//					answer++;
//			}
//		}
//	}
//	printf("%d", answer);
//}

//4060번 문제
//int m, n;
//int save[101][101], list[101][101];
//int dy[4] = { 0, 0, 1, -1 }, dx[4] = { 1, -1, 0, 0 };
//void f1(int row, int col) {
//	if (row == -1 || col == -1 || row == m || col == n)
//		return;
//	if (save[row][col] == 1)
//		return;
//	save[row][col] = 1;
//	for (int i = 0; i < 4; i++)
//		f1(row + dy[i], col + dx[i]);
//}
//void f2(int row, int col) {
//	if (row == -1 || col == -1 || row == m || col == n)
//		return;
//	if (list[row][col] == 0)
//		return;
//	list[row][col] = 0;
//	for (int i = 0; i < 4; i++)
//		f2(row + dy[i], col + dx[i]);
//}
//int main() {
//	scanf("%d %d", &m, &n);
//	for (int i = 0; i < m; i++) {
//		for (int j = 0; j < n; j++) {
//			scanf("%d", &save[i][j]);
//			list[i][j] = save[i][j];
//		}
//	}
//	int cnt1 = 0, cnt2 = 0;
//	for (int i = 0; i < m; i++) {
//		for (int j = 0; j < n; j++) {
//			if (save[i][j] == 0) {
//				f1(i, j);
//				cnt1++;
//			}
//			if (list[i][j] == 1) {
//				f2(i, j);
//				cnt2++;
//			}
//		}
//	}
//	printf("%d %d", cnt1, cnt2);
//}

//int main() {
//	for (int i = 0; i < 7; i++) {
//		for (int j = 0; j < 7; j++)
//			scanf("%d", &list[i][j]);
//	}
//	for (int i = 0; i < 7; i++) {
//		for (int j = 0; j < 7; j++) {
//			if (save[i][j] == 0) {
//				temp++;
//				dfs(i, j, list[i][j], 1);
//			}
//		}
//	}
//	printf("%d\n", temp);
//	for (int i = 0; i < 7; i++) {
//		for (int j = 0; j < 7; j++)
//			printf("%d ", save[i][j]);
//		printf("\n");
//	}
//	printf("%d", answer - 1);
//}
//int dx[] = { -1,1,0,0 };
//int dy[] = { 0,0,-1,1 };
//int list[8][8] = { 0 }, overlap[8][8] = { 0 };
//void dfs(int x, int y, int color) {
//	for (int i = 0; i < 4; i++) {
//		int nowx = x + dx[i], nowy = y + dy[i];
//		if (nowx >= 0 && nowy >= 0 && nowx < 7 && nowy < 7 && list[nowx][nowy] == color)
//			overlap[x + dx[i]][y + dy[i]] = color;
//	}
//}
//
//int main() {
//	int num;
//	for (int i = 0; i < 7; i++) {
//		for (int j = 0; j < 7; j++)
//			scanf("%d", &list[i][j]);
//	}
//
//	for (int i = 0; i < 7; i++) {
//		for (int j = 0; j < 7; j++)
//			if (overlap[i][j] == 0)
//				dfs(i, j, list[i][j]);
//	}
//	printf("\n\n\n\n\n");
//	for (int i = 0; i < 7; i++) {
//		for (int j = 0; j < 7; j++) {
//			printf("%d ", overlap[i][j]);
//		}
//		printf("\n");
//	}
//}




////4421번 문제
//int dx[] = { -1,1,0,0 };
//int dy[] = { 0,0,-1,1 };
//int num, list[26][26] = { 0 }, visit[26][26] = { 0 };
///**
//조건 1. 맵의 범위 안에 있어야 한다. 
//조건 2. 데이터가 1이여야 한다.
//조건 3. 이미 탐색된 좌표는 다시 탐색되면 안됨. 
//
//
//*/
//int danji = 0;
//int jib[25 * 25] = { 0 };
//int getScope(int x, int y)
//{
//	return 0 <= x && x < num && 0 <= y && y <= num;
//}
//void dfs(int x, int y)
//{
//	jib[danji]++;
//	visit[x][y] = 1;
//	for (int i = 0; i < 4; i++)
//	{
//		int cx = x + dx[i];
//		int cy = y + dy[i];
//		if (list[cx][cy] == 1 && getScope(cx,cy) && visit[cx][cy]==0)
//		{
//			dfs(cx, cy);
//		}
//	}
//}
//
//
//int main() {
//	scanf("%d", &num);
//	for (int i = 0; i < num; i++) {
//		for (int j = 0; j < num; j++)
//			scanf("%1d", &list[i][j]);
//	}
//	for (int i = 0; i < num; i++) {
//		for (int j = 0; j < num; j++)
//		{
//			if (visit[i][j]==0 && list[i][j] == 1)
//			{
//				danji++;
//				dfs(i, j);
//			}
//		}
//	}
//	printf("%d\n", danji);
//	for (int i = danji; i >= 1; i--)
//	{
//		for (int j = 1; j < i; j++)
//		{
//			if (jib[j] > jib[j + 1])
//			{
//				int t = jib[j];
//				jib[j] = jib[j + 1];
//				jib[j + 1] = t;
//			}
//		}
//	}
//
//
//	for (int i = 1; i <= danji; i++)
//	{
//		printf("%d\n", jib[i]);
//	}
//
//}

////2076번 문제
//int answer;
//int arr[10];
//void f(int idx, int cur_data, int size)
//{
//	if (answer < cur_data)
//	{
//		answer = cur_data;
//	}
//	if (idx >= size)
//		return;
//	f(idx + 1, cur_data + arr[idx], size);
//	if(idx!=size-1)
//	f(idx + 2, cur_data + (arr[idx] * 10 + arr[idx + 1]), size);
//}
//int main()
//{
//	int n;
//	int length=0;
//	scanf("%d", &n);
//	int temp = n;
//	while(temp > 0)
//	{
//
//		temp /= 10;
//		length++;
//	}
//	temp = n;
//	for (int i = length - 1; i >= 0; i--,temp/=10)
//	{
//		arr[i] = temp % 10;
//	}
//	f(0, 0, length);
//	printf("%d", answer);
//}

////3071번 문제
//int table[1000001];
//int main() {
//	int num1, num2, num3, count = 0, max = -1, min = 1000000;
//	scanf("%d %d", &num1, &num2);
//	if (num1 > num2) {
//		num3 = num2;
//		num2 = num1;
//		num1 = num3;
//	}
//	for (int i = 2; i < 1000001; i++) {
//		table[i] = i;
//	}
//	for (int i = 2; i < 1000001; i++) {
//		if(table[i] != 0)
//		for (int j = i + i; j < 1000001; j += i)
//			table[j] = 0;
//	}
//	for (int i = num1; i < num2 + 1; i++) {
//		if (table[i] != 0) {
//			if (max < table[i])
//				max = table[i];
//			if (min > table[i])
//				min = table[i];
//			count++;
//			printf("%d ", table[i]);
//			//printf("%d\n%d", table[i], result + max);
//		}
//	}
//}

//4422번 문제
//int main() {
//	int list[101] = { 0 };
//	int num;
//	int result = 0;
//	scanf("%d", &num);
//	for (int i = 0; i < num; i++) {
//		scanf("%d", &list[i + 1]);
//	}
//	for (int i = 1; i < num + 1; i++) {
//		int x = list[i], savex = x, lead = 0;
//		while (1) {
//			lead++;
//			if (lead > num)
//				break;
//			int s = list[savex];
//			savex = s;
//			if (s == x)
//				break;
//		}
//		printf("%d\n", lead);
//	}
//}
//int main()
//{
//	int n;
//	int arr[101] = { 0 };
//	int temp;
//
//	int answer[101] = { 0 };
//	int ansIdx = 0;
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		int cnt = 0;
//		temp = arr[i];
//		while (i != temp)
//		{
//			if (cnt > n)break;
//			cnt++;
//			// i=1 , temp=3;
//			temp = arr[temp];
//		}
//		if (i == temp)
//		{
//			answer[ansIdx++] = i;
//		}
//	}
//	printf("%d\n", ansIdx);
//	for (int i = 0; i < ansIdx; i++)
//	{
//		printf("%d\n", answer[i]);
//	}
//
//}


////4057번 문제
//int table[4000000];
//int main() {
//	int num1, num2, num3, count = 0, max = -1, min = 4000000;
//	scanf("%d %d", &num1, &num2);
//	if (num1 > num2) {
//		num3 = num2;
//		num2 = num1;
//		num1 = num3;
//	}
//	for (int i = 2; i < 4000000; i++) {
//		table[i] = i;
//	}
//	for (int i = 2; i < 4000000; i++) {
//		if(table[i] != 0)
//		for (int j = i + i; j < 4000000; j += i)
//			table[j] = 0;
//	}
//	for (int i = num1; i < num2 + 1; i++) {
//		if (table[i] != 0) {
//			if (max < table[i])
//				max = table[i];
//			if (min > table[i])
//				min = table[i];
//			count++;
//			//printf("%d\n%d", table[i], result + max);
//		}
//	}
//	printf("%d\n%d", count, min + max);
//}

//2706번 문제 #예전코드
//char list[10] = { 0 };
//int result = 0;
//void f(int index, int sum) {
//	if (index > 9) {
//		printf("나온값:%d\n", sum + 48);
//		if (sum + 48 > result)
//			result = sum + 48;
//		return 0;
//	}
//	printf("index:%d, sum:%d\n", index, sum);
//	int save_1 = sum, save_2 = sum;	
//	save_1 += (int)list[index] - 48;
//	if (index + 1 <= 9)
//		save_2 += ((int)list[index] - 48) * 10 + (int)list[index + 1];
//	f(index + 1, save_1);
//	if (index + 2 <= 9)
//		f(index + 2, save_2);
//}
////void fa(int index, int sum, int numvalue) {
////	printf("index:%d, sum:%d, numvalue:%d\n", index, sum, numvalue);
////	int save = sum;
////	if (numvalue == 1)
////		save += (int)list[index] - 48;
////	else if (numvalue == 2)
////		save += ((int)list[index] - 48) * 10 + ((int)list[index + 1] - 48);
////	if (index >= 9) {
////		printf("최대값:%d\n", sum);
////		if (sum > result)
////			result = sum;
////		return 0;
////	}
////	f(index + 1, save, 1);
////	if (index + 2 <= 9)
////		f(index + 2, save, 2);
////}
//int main() {
//	scanf("%s", list);
//	f(0, 0, 1);
//	printf("%d", result);
//}
//
//char str[10];
//int length;
//int n;
//int max;
//int trace[10];
//int getData(char *ch,int pos,int len)
//{
//	if (len == 1)
//		return ch[pos] - '0';
//	else
//		return (ch[pos] - '0') * 10 + (ch[pos+1] - '0');
//}
//void f(int idx, int sum)
//{
//	if (idx >= length)return;
//	if (max < sum)
//	{
//		printf("%d\n ", sum);
//		max = sum;
//	}
//	f(idx + 1, sum + getData(str, idx, 1));
//	if (idx+1 < length) {
//
//		f(idx + 2, sum + getData(str, idx, 2));
//	}
//}
//int main()
//{
//	
//	char temp;
//	scanf("%s", str);
//	length=strlen(str);
//
//	f(0, 0);  // left = index , right = sum;
//	printf("%d", max);
//}















////4068번 문제 에라토스테라스의 체
//
//
//int table[4000000];
//int main() {
//	int num1, num2;
//	scanf("%d %d", &num1, &num2);
//	for (int i = 2; i < 4000000; i++) {
//		table[i] = i;
//	}
//	for (int i = 2; i < 4000000; i++) {
//		if(table[i] != 0)
//		for (int j = i + i; j < 4000000; j += i)
//			table[j] = 0;
//	}
//	int save = -1;
//	for (int i = num1; i < num2 + 1; i++) {
//		if (table[i] != 0) {
//			if (save + 2 == table[i])
//			printf("%d %d\n", save, table[i]);
//			save = table[i];
//		}
//	}
//}




//int save[10000000] = { 0 };
//int main() {
//	int num;
//	scanf("%d", &num);
//	for (int i = 2; i < 10000000; i++) {
//		save[i] = i;
//	}
//	for (int i = 2; i < 10000000; i++) {
//		if (save[i] == 0)
//			continue;
//		int loop = i;
//		while (1) {
//			if (loop >= 10000000)
//				break;
//			loop += i;
//			save[loop] = 0;
//			
//		}
//	}
//	for (int i = 2; i < 10000000; i++)
//		printf("%d", save[i]);
//}

////1920번 문제
//int save1[100000] = { 0 }, save2[100000] = { 0 };
//
//int static compare(const void* first, const void* second)
//{
//	if (*(int*)first > *(int*)second)
//		return 1;
//	else if (*(int*)first < *(int*)second)
//		return -1;
//	else
//		return 0;
//}
//
//int main() {
//	int num1, num2, save = 0;
//	scanf("%d", &num1);
//	for (int i = 0; i < num1; i++)
//		scanf("%d", &save1[i]);
//	qsort(save1, num1, sizeof(int), compare);
//	scanf("%d", &num2);
//	for (int i = 0; i < num2; i++)
//		scanf("%d", &save2[i]);
//
//	int left = 0, right = num1, mid, answer;
//	for (int i = 0; i < num2; i++) {
//		answer = -1;
//		int key = save2[i];
//		while (left <= right) {
//			mid = (left + right) / 2;
//			if (save1[mid] < key) {
//				left = mid + 1;
//			}
//			else if (save1[mid] > key)
//				right = mid - 1;
//			else if (save1[mid] == key) {
//				answer = 1;
//				break;
//			}
//		}
//		if (answer == -1)
//			printf("0\n");
//		else
//			printf("1\n");
//		left = 0, right = num1;
//	}
//}

////9613번 문제
//int main() {
//	int num;
//	scanf("%d", &num);
//	for (int i = 0; i < num; i++) {
//		int input_value;
//		long long int result = 0;
//		int list[101] = { 0 };
//		scanf("%d", &input_value);
//		for (int j = 0; j < input_value; j++) {
//			int input;
//			scanf("%d", &input);
//			list[j] = input;
//		}
//		for (int x = 0; x < input_value - 1; x++) {
//			for (int y = x + 1; y < input_value; y++) {
//				printf("%d %d\n", list[x], list[y]);
//				int j;
//				for (j = list[x]; j > 0; j--) {
//					if (list[x] % j == 0 && list[y] % j == 0)
//					{
//						break;
//					}
//				}
//				result += j;
//			}
//		}
//		printf("%lld\n", result);
//	}
//}

////4153번 문제
//int main() {
//	int num1 = 0, num2 = 0, num3 = 0;
//	while (1) {
//		scanf("%d %d %d", &num1, &num2, &num3);
//		if (num1 == 0 && num2 == 0 && num3 == 0)
//			return 0;
//		if (num1 >= num2 && num1 >= num3) {
//			if (num1 * num1 == num2 * num2 + num3 * num3)
//				printf("right\n");
//			else
//				printf("wrong\n");
//		}
//		if (num2 >= num1 && num2 >= num3) {
//			if (num2 * num2 == num1 * num1 + num3 * num3)
//				printf("right\n");
//			else
//				printf("wrong\n");
//		}
//		if (num3 >= num2 && num3 >= num1) {
//			if (num3 * num3 == num2 * num2 + num1 * num1)
//				printf("right\n");
//			else
//				printf("wrong\n");
//		}
//	}
//}

////3009번 문제
//int main() {
//	int save1[1000] = { 0 }, save2[1000] = { 0 };
//	for (int i = 0; i < 3; i++) {
//		int num1, num2;
//		scanf("%d %d", &num1, &num2);
//		save1[num1]++;
//		save2[num2]++;
//	}
//	int result1 = 0, result2 = 0;
//	for (int i = 0; i < 1000; i++) {
//		if (save1[i] == 1)
//			result1 = i;
//		if (save2[i] == 1)
//			result2 = i;
//	}
//	printf("%d %d", result1, result2);
//}

////1085번 문제
//int main() {
//	int num1, num2, num3, num4;
//	scanf("%d %d %d %d", &num1, &num2, &num3, &num4);
//	int save1 = 0, save2 = 0;
//	if (num3 - num1 > num1)
//		save1 = num1;
//	else
//		save1 = num3 - num1;
//	if (num4 - num2 > num2)
//		save2 = num2;
//	else
//		save2 = num4 - num2;
//	if (save1 > save2)
//		printf("%d", save2);
//	else
//		printf("%d", save1);
//}

////3071 - codeup문제
//int save[1000001] = { 0 };
//int main() {
//	int first, end;
//	scanf("%d %d", &first, &end);
//	for (int i = 2; i <= end; i++)
//	{
//		save[i] = i;
//	}
//	//에라토스테네스의 체
//	for (int i = 2; i <= end; i++)
//	{
//		// i의 배수를 제거
//		if(save[i]!=0)
//		for (int j = i + i; j <= end; j += i)
//		{
//			save[j] = 0;
//		}
//	}
//	for (int i = first; i <= end; i++)
//	{
//		if (save[i])
//		{
//			printf("%d ", save[i]);
//		}
//	}
//}

////2869번 문제
//int main() {
//	int up, down, height, result = 0, nowheight = 0;
//	scanf("%d %d %d", &up, &down, &height);
//	if ((height - down) % (up - down) != 0)
//		printf("%d", (height - down) / (up - down) + 1);
//	else
//		printf("%d", (height - down) / (up - down));
//
//}

////14490번 문제
//int main() {
//	int num1, num2, min, max = 1;
//	scanf("%d:%d", &num1, &num2);
//	if (num1 > num2)
//		min = num2;
//	else
//		min = num1;
//	for (int i = min; i > 0; i--) {
//		if (num1 % i == 0 && num2 % i == 0) {
//			max = i;
//			break;
//		}
//	}
//	printf("%d:%d", num1 / max, num2 / max);
//}
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ여기까지가 문자열ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
// 
//8595번 문제
//char input[5000001];
//int stacks[5000001];
//int top = -1;
//void push(int data)
//{
//	stacks[++top] = data;
//}
//int pop()
//{
//	return stacks[top--];
//}
//int main()
//{
//	int n;
//	int flag = 0;
//	int cnt = 0;
//	int sum = 0;
//	scanf("%d", &n);
//	scanf("%s", input);
//	for (int i = 0; i < strlen(input); i++)
//	{
//		int a = input[i];
//		if (a == 48 && flag == 0)continue;
//		if (a > 48 && a < 58)
//		{
//			flag = 1;
//		}
//		else {
//			flag = 0;
//		}
//		if (flag == 1)
//		{
//			push(a);
//		}
//		if (flag == 0 || i == n - 1)
//		{
//			int temp = 0;
//			while (top != -1)
//			{
//				temp += pop() *(int)pow(10,top);
//			}
//			sum += temp;
//		}
//
//	}
//	printf("%d", sum);
//}
//int main() {
//	int save[6] = { 0 }, nowpos = 0, result = 0, num;
//	scanf("%d", &num);
//	scanf("%s", input);
//	for (int i = 0; i < num + 1; i++) {
//		if (input[i] >= 48 && input[i] <= 57) {
//			if (nowpos == 0 && input[i] == 48)
//				continue;
//			save[nowpos] = input[i] - 48;
//			nowpos++;
//		}
//		else {
//			for (int i = nowpos - 1, j = 0; i >= 0; i--, j++)
//				result += save[i] * (int)pow(10, j);
//			nowpos = 0;
//			memset(save, 0, 6 * sizeof(int));
//		}
//	}
//	printf("%d", result);
//}
//11586번 문제
//char input[101][101];
//int main() {
//	int num;
//	scanf("%d", &num);
//	for (int i = 0; i < num; i++)
//		scanf("%s", input[i]);
//	int angry;
//	scanf("%d", &angry);
//	if (angry == 1) {
//		for (int i = 0; i < num; i++) {
//			for (int j = 0; j < num; j++) {
//				printf("%c", input[i][j]);
//			}
//			printf("\n");
//		}
//	}
//	else if (angry == 2) {
//		for (int i = 0; i < num; i++) {
//			for (int j = num - 1; j >= 0; j--) {
//				printf("%c", input[i][j]);
//			}
//			printf("\n");
//		}
//	}
//	else if (angry == 3) {
//		for (int i = num - 1; i >= 0; i--) {
//			for (int j = 0; j < num; j++) {
//				printf("%c", input[i][j]);
//			}
//			printf("\n");
//		}
//	}
//}

////10988번 문제
//int main() {
//	char input[100];
//	scanf("%s", input);
//	for (int i = 0, j = strlen(input) - 1; i < j; i++, j--) {
//		if (input[i] != input[j]) {
//			printf("0");
//			return 0;
//		}
//	}
//	printf("1");
//}

////10798번 문제	
//int main() {
//	char input[100];
//	int result = 0;
//	scanf("%s", input);
//	for (int i = 0; input[i] != '\0'; i++) {
//		if (input[i] == 97 || input[i] == 101 || input[i] == 105 || input[i] == 111 || input[i] == 117)
//			result++;
//	}
//	printf("%d", result);
//}

////2743번 문제
//int main() {
//	int num;
//	scanf("%d", &num);
//	for (int i = 0; i < num; i++) {
//		char input[101] = "";
//		scanf("%s", input);
//		int result = 0;
//		for (int i = 0; input[i] != '\0'; i++) {
//			if (input[i] >= 65 && input[i] <= 90)
//				printf("%c", input[i] + 32);
//			else
//				printf("%c", input[i]);
//		}
//		printf("\n");
//	}
//}

////2495번 문제
//int main() {
//	for (int i = 0; i < 3; i++) {
//		int num, MAX = -1, count = 0;
//		scanf("%d", &num);
//		int temp = -1;
//		while (num != 0) {
//			if (num % 10 != temp)
//				count = 1;
//			else {
//				count++;
//			}
//			if (count > MAX)
//				MAX = count;
//			temp = num % 10;
//			num /= 10;
//		}
//		printf("%d\n", MAX);
//	}
//}

////1919번 문제
//char input1[1001], input2[1001];
//int save1[25] = { 0 }, save2[25] = { 0 };
//int main() {
//	int result = 0;
//	scanf("%s", input1);
//	scanf("%s", input2);
//	for (int i = 0; input1[i] != '\0'; i++) {
//		save1[input1[i] - 97]++;
//	}
//	for (int i = 0; input2[i] != '\0'; i++) {
//		save2[input2[i] - 97]++;
//	}
//	for (int i = 0; i < 26; i++) {
//		result += abs(save1[i] - save2[i]);
//	}
//	printf("%d", result);
//}

////1718번 문제
//char password[30001] = "", solve[30001] = "", word[30001] = "";
//int main() {
//	scanf("%[^\n]s", password);
//	scanf("%s", solve);
//	int len = strlen(solve);
//	for (int i = 0; i < 30000; i += len) {
//		strcat(word, solve);
//	}
//	for (int i = 0; password[i] != '\0'; i++) {
//		if (password[i] > 96 && password[i] < 123) {
//			//printf("%d ", password[i] - word[i]);
//			password[i] -= word[i];
//			if (password[i] <= 0)
//				password[i] += 26;
//			password[i] += 96;
//
//			printf("%c", password[i]);
//		}
//		else
//			printf("%c", password[i]);
//	}
//}

////1652번 문제
//int main() {
//	int num;
//	scanf("%d", &num);
//	char arr[101][101] = { 0 };
//	for (int i = 0; i < num; i++) {
//		scanf("%s", arr[i]);
//	}
//	int result1 = 0, result2 = 0, state = 0;
//	for (int j = 0; j < num; j++) {
//		for (int i = 0; i < num; i++) {
//			if (arr[j][i] == '.') {
//				state++;
//			}
//			else {
//				if (state > 1)
//					result1++;
//				state = 0;
//			}
//		}
//		if (state > 1)
//			result1++;
//		state = 0;
//	}
//	for (int j = 0; j < num; j++) {
//		for (int i = 0; i < num; i++) {
//			if (arr[i][j] == '.') {
//				state++;
//			}
//			else {
//				if (state > 1)
//					result2++;
//				state = 0;
//			}
//		}
//		if (state > 1)
//			result2++;
//			state = 0;
//	}
//	printf("%d %d", result1, result2);
//}

////1157번 문제
//char input[1000001] = "";
//int save[27] = { 0 };
//int main() {
//	scanf("%s", input);
//	for (int i = 0; i < 1000000; i++) {
//		for (int j = 0; j < 26; j++) {
//			if (input[i] == j + 65 || input[i] == j + 97)
//				save[j]++;
//		}
//	}
//	int max = 0;
//	for (int i = 0; i < 26; i++) {
//		if (save[max] < save[i])
//			max = i;
//	}
//	for (int i = 0; i < 26; i++) {
//		if (max != i && save[max] == save[i]) {
//			printf("?");
//			return 0;
//		}
//	}
//	printf("%c", max + 65);
//}

////1225번 문제
//char save1[10001] = "", save2[10001] = "";
//int main() {
//	unsigned long long int result = 0;
//	scanf("%s %s", save1, save2);
//	for (int i = 0; save1[i] != '\0'; i++) {
//		for (int j = 0; save2[j] != '\0'; j++) {
//			printf("%d %d\n", save1[i] - 48, save2[j] - 48);
//			result += (save1[i] - 48) * (save2[j] - 48);
//		}
//	}
//	printf("%lld", result);
//}
// 
//int main() {
//	int num1, num2, result = 0;
//	scanf("%d %d", &num1, &num2);
//	int count1 = 0, count2 = 0, save = num1;
//	while (save != 0) {
//		save /= 10;
//		count1++;
//	}
//	save = num2;
//	while (save != 0) {
//		save /= 10;
//		count2++;
//	}
//	int save1 = num1, save2;
//	for (int i = 0; i < count1; i++) {
//		save2 = num2;
//		printf("save1:%d\n", save1 % 10);
//		for (int j = 0; j < count2; j++) {
//			printf("save2:%d\n", save2 % 10);
//			result += (save1 % 10) * (save2 % 10);
//			save2 /= 10;
//		}
//		save1 /= 10;
//	}
//	printf("%d", result);
//}

////11721번 문제
//int main() {
//	char input[101] = "";
//	scanf("%s", input);
//	
//
//	for (int i = 0,cnt=1; input[i] != '\0';cnt++, i++)
//	{
//		printf("%c", input[i]);
//		if (cnt % 10 == 0 )
//			printf("\n");
//	}
//	
//	/*for (int i = 1; i < 100; i++) {
//		printf("%c", input[i - 1]);
//		if (i % 10 == 0 && input[i] != '\0')
//			printf("\n");
//	}*/
//}

////11720번 문제
//char input[101] = "";
//int main() {
//	int num, total = 0;
//	scanf("%d", &num);
//	scanf("%s", input);
//	for (int i = 0; i < num; i++) {
//		total += input[i] - 48;
//	}
//	printf("%d", total);
//}
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ이 위부턴 문자열ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
////10809번 문제
//int main() {
//	int answer[27];
//	for (int i = 0; i < 27; i++) {
//		answer[i] = -1;
//	}
//	char input[101] = "";
//	scanf("%s", input);
//	for (int i = 99; i > -1; i--) {
//		if (input[i] > 96 && input[i] < 123)
//			answer[input[i] - 97] = i;
//	}
//	for (int i = 0; i < 26; i++)
//		printf("%d ", answer[i]);
//}


////8958번 문제
//char list[81];
//int main() {
//	int num, score = 0;
//	scanf("%d", &num);
//	for (int i = 0; i < num; i++) {
//		score = 0;
//		char list[81] = { 'X' };
//		scanf("%s", list);
//		int save = 1;
//		for (int i = 0; i < 81; i++) {
//			if (i == 0 && list[0] == 'O') {
//				score++;
//			} else if (list[i] == 'O' && i != 0) {
//				save++;
//				score += save;
//			}
//			else
//				save = 0;
//		}
//		printf("%d\n", score);
//	}
//}

////1924번 문제
//int main() {
//	int mon, day, save = 0;
//	scanf("%d %d", &mon, &day);
//	for (int i = 1; i < mon; i++) {
//		switch (i) {
//		case 1:
//		case 3:
//		case 5:
//		case 7:
//		case 8:
//		case 12:
//		case 10:
//			save += 31;
//			break;
//		case 2:
//			save += 28;
//			break;
//		default:
//			save += 30;
//			break;
//		}
//	}
//	save += day;
//	switch (save % 7) {
//	case 1:
//		printf("MON");
//		break;
//	case 2:
//		printf("TUE");
//		break;
//	case 3:
//		printf("WED");
//		break;
//	case 4:
//		printf("THU");
//		break;
//	case 5:
//		printf("FRI");
//		break;
//	case 6:
//		printf("SAT");
//		break;
//	case 0:
//		printf("SUN");
//		break;
//	}
//}

//6359번 문제
//int main() {
//	int num;
//	scanf("%d", &num);
//	for (int i = 0; i < num; i++) {
//		int list[101] = { 0 };
//		int input;
//		scanf("%d", &input);
//		for (int j = 1; j < input + 1; j++) {
		//	int save = j;
		//	while(save <= input) {
		//		if (list[save] == 0)
		//			list[save] = 1;
		//		else
		//			list[save] = 0;
		//		save += j;
		//	}
		//}
		//int total = 0;
		//for (int j = 1; j < input + 1; j++) {
		//	if (list[j] == 1)
		//		total++;
		//}
//		printf("%d\n", total);
//	}
//}

////5597번 문제
//int list[30] = { 0 };
//int main() {
//	for (int i = 1; i < 31; i++) {
//		int input;
//		scanf("%d", &input);
//		list[input]++;
//	}
//	for (int i = 1; i < 31; i++) {
//		if (list[i] == 0)
//			printf("%d\n", i);
//	}
//}

////3052번 문제
//int list[43] = { 0 };
//int main() {
//	for (int i = 0; i < 10; i++) {
//		int input;
//		scanf("%d", &input);
//		list[input % 42]++;
//	}
//	int total = 0;
//	for (int i = 0; i < 43; i++) {
//		if (list[i] != 0)
//			total++;
//	}
//	printf("%d", total);
//}

//2979번 문제
//int truck1[101] = { 0 }, truck2[101] = { 0 }, truck3[101] = {0};
//int main() {
//	int perone, pertwo, perthree;
//	scanf("%d %d %d", &perone, &pertwo, &perthree);
//	int input1, input2;
//	scanf("%d %d", &input1, &input2);
//	for (int i = input1; i < input2; i++)
//		truck1[i] = 1;
//	scanf("%d %d", &input1, &input2);
//	for (int i = input1; i < input2; i++)
//		truck2[i] = 1;
//	scanf("%d %d", &input1, &input2);
//	for (int i = input1; i < input2; i++)
//		truck3[i] = 1;
//	int total = 0;
//	for (int i = 0; i < 101; i++) {
//		int save = truck1[i] + truck2[i] + truck3[i];
//		if (save == 1)
//			total += perone;
//		else if (save == 2)
//			total += pertwo * 2;
//		else if (save == 3)
//			total += perthree * 3;
//	}
//	printf("%d", total);
//}

////2908번 문제
//int main() {
//	int num1, num2, a = 0, b = 0;
//	scanf("%d %d", &num1, &num2);
//	int save = num1;
//	a += (save % 10) * 100;
//	save /= 10;
//	a += (save % 10) * 10;
//	save /= 10;
//	a += save % 10;
//	save = num2;
//	b += (save % 10) * 100;
//	save /= 10;
//	b += (save % 10) * 10;
//	save /= 10;
//	b += save % 10;
//	if (a > b)
//		printf("%d", a);
//	else
//		printf("%d", b);
//}

////2846번 문제
//int list[1001] = { 0 };
//int main() {
//	int num;
//	scanf("%d", &num);
//	for (int i = 0; i < num; i++) {
//		scanf("%d", &list[i]);
//	}
//	int low = 0, MAX = -1, sp;
//	for (int i = 0; i < num; i++) {
//		if (i != 0 && list[i - 1] >= list[i]) {
//			if (MAX < list[i - 1] - list[low])
//				MAX = list[i - 1] - list[low];
//			low = i;
//		}
//		sp = i;
//	}
//	if (MAX < list[sp] - list[low])
//		MAX = list[sp] - list[low];
//	printf("%d", MAX);
//}

//2846번 문제 구 코드
//int list[1001] = { 0 };
//int main() {
//	int num, save = -1, max = -1;
//	scanf("%d", &num);
//	for (int i = 0; i < num; i++) {
//		scanf("%d", &list[i]);
//		//printf("%d\n", save);
//		if (save == -1) {
//			int save = i;
//		}
//		else {
//			if (list[i] <= list[i - 1]) {
//				if (max < list[i] - list[save])
//					max = list[i] - list[save];
//				save = -1;
//			}
//		}
//		printf("%d\n", save);
//		
//	}
//	printf("%d", max);
//}

//2798번 문제
//int list[101] = { 0 };
//int main() {
//	int card, num, MAX = -1;
//	scanf("%d %d", &card, &num);
//	for (int i = 0; i < card; i++) {
//		int input;
//		scanf("%d", &input);
//		list[i] = input;
//	}
//	for (int i = 0; i < card; i++) {
//		int total = 0;
//		for (int j = 0; j < card; j++) {
//			total = list[i];
//			if (j != i)
//				total = list[i] + list[j];
//			else
//				continue;
//			for (int m = 0; m < card; m++) {
//				total = list[j] + list[i];
//				if (j != m && i != m)
//					total = list[j] + list[i] + list[m];
//				else
//					continue;
//				if (total > MAX && total <= num)
//					MAX = total;
//			}
//		}
//	}
//	printf("%d", MAX);
//}

////2577번 문제
//int numlist[10] = { 0 };
//int main() {
//	int num1, num2, num3, count, a = 0;
//	scanf("%d", &num1);
//	scanf("%d", &num2);
//	scanf("%d", &num3);
//	int save = num1 * num2 * num3;
//	while (save > 0) {
//		int num;
//		num = save % 10;
//		numlist[num]++;
//		save /= 10;
//	}
//	for (int i = 0; i < 10; i++) {
//		printf("%d\n", numlist[i]);
//	}
//}

////2231번 문제
//int main() {
//	int num;
//	scanf("%d", &num);
//	for (int i = 1; i <= num; i++) {
//		int save = i, total = i;
//		while (save > 0) {
//			total += save % 10;
//			save /= 10;
//		}
//		if (total == num) {
//			printf("%d", i);
//			return 0;
//		}
//	}
//	printf("0");
//}

////2010번 문제
//int arr[500001] = { 0 };
//int main() {
//	int num, MAX = 0, total = 0;
//	scanf("%d", &num);
//	for (int i = 0; i < num; i++)
//		scanf("%d", &arr[i]);
//	for (int i = 0; i < num; i++) {
//		if (arr[MAX] < arr[i])
//			MAX = i;
//	}
//	for (int i = 0; i < num; i++) {
//		if (MAX == i)
//			total += arr[i];
//		else
//			total += arr[i] - 1;
//	}
//	printf("%d", total);
//}

//1789번 문제
//int main() {
//	long long int num, cnt = 0;
//	int count = 0;
//	scanf("%lld", &num);
//	while (cnt <= num) {
//		count++;
//		cnt += count;
//	}
//	if (cnt > num) {
//		count--;
//	}
//	printf("%d", count);
//}


//1789번 문제 구 코드
//int main() {
//	unsigned int num;
//	scanf("%d", &num);
//	int i = 1, cnt = 0;
//	while (1) {
//		cnt += i;
//		if (cnt + (i + 1) <= num)
//			i++;
//		else {
//			printf("%d", i);
//			break;
//		}
//	}
//}

////1773번 문제
//int arr[2000001];
//int main() {
//    int num1, num2;
//    scanf("%d %d", &num1, &num2);
//    int cnt = 0, num, temp;
//    for (int i = 0; i < num1; i++) {
//        scanf("%d", &num);
//        temp = num;
//        if (!arr[num]) {
//            while (1) {
//                if (num > num2)
//                    break;
//                else {
//                    arr[num] = 1;
//                    num += temp;
//                }
//            }
//        }
//    }
//    for (int i = 1; i <= num2; i++)
//        if (arr[i])
//            cnt++;
//    printf("%d", cnt);
//}

//2774번 문제
//int main() {
//	int num, list[11] = { 0 }, cnt = 0;
//	scanf("%d", &num);
//	for (int i = 0; i < num; i++) {
//		char arr[101] = {'0'};
//		cnt = 0;
//		scanf("%s", arr);
//		for (int j = 0; j < 101; j++) {
//			switch (arr[j]) {
//			case 48:
//				list[0] += 1;
//				break;
//			case 49:
//				list[1] += 1;
//				break;
//			case 50:
//				list[2] += 1;
//				break;
//			case 51:
//				list[3] += 1;
//				break;
//			case 52:
//				list[4] += 1;
//				break;
//			case 53:
//				list[5] += 1;
//				break;
//			case 54:
//				list[6] += 1;
//				break;
//			case 55:
//				list[7] += 1;
//				break;
//			case 56:
//				list[8] += 1;
//				break;
//			case 57:
//				list[9] += 1;
//				break;
//			}
//		}
//		for (int j = 0; j < 10; j++) {
//			if (list[j] > 0)
//				cnt++;
//			list[j] = 0;
//		}
//		printf("%d\n", cnt);
//	}
//}

////1568번 문제
//int main() {
//	int num, i = 0, to = 0;
//	scanf("%d", &num);
//    while (1) {
//        i++;
//        if (num == 0)
//            break;
//        if (num < i)
//            i = 1;
//        num -= i;
//        to++;
//    }
//	printf("%d", to);
//}

//중요ㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛㅛ
//int num, MAX = -1;
//int f(int nowindex, int total, int inputnumber) {
//	if (nowindex == -1) {
//		if (MAX < total)
//			MAX = total;
//		return 0;
//	}
//	else if (nowindex < -1)
//		return 0;
//	int value = 1;
//	for (int i = 0; i < nowindex - 1; i++)
//		value *= 10;
//	f(nowindex - 1, total + num / value - (num / (value * 10)) * 10, num / value - (num / (value * 10)) * 10);
//	f(nowindex - 2, total + num / value - (num / (value * 100)) * 100, num / value - (num / (value * 100)) * 100);
//}
//
//int main() {
//	int n, num_length = 0;
//	scanf("%d", &num);
//	n = num;
//	while (n != 0) {
//		n /= 10;
//		num_length++;
//	}
//	//printf("%d", num_length);
//	f(num_length, 0, 0);
//	//printf("%d", MAX);
//	int a = 1;
//	for (int i = 0; i < 5; i++)
//		a *= 10;
//	printf("%d\n", a);
//	printf("%d", 138947912 / a - (138947912 / (a * 10)) * 10);
//}

//int num, count = 0;
//int f(int nowindex, int isthree) {
//	if (nowindex == num) {
//		count++;
//		return 0;
//	}
//	else if (nowindex > num)
//		return 0;
//	f(nowindex + 1, isthree - 1);
//	f(nowindex + 2, isthree - 1);
//	if (isthree < 1)
//		f(nowindex + 3, 2);
//	return 0;
//}
//
//int main() {
//	scanf("%d", &num);
//	f(0, 0);
//	printf("%d", count);
//}	

//problem.c
////2953번 문제
//int main() {
//	int MAX = -1, count, input, num;
//	for (int i = 0; i < 5; i++) {
//		count = 0;
//		for (int j = 0; j < 4; j++) {
//			scanf("%d", &input);
//			count += input;
//		}
//		if (MAX < count) {
//			MAX = count;
//			num = i + 1;
//		}
//	}
//	printf("%d %d", num, MAX);
//}

////10797번 문제
//int main() {
//	int num, count = 0;
//	scanf("%d", &num);
//	for (int i = 0; i < 5; i++) {
//		int input;
//		scanf("%d", &input);
//		if (num % 10 == input)
//			count++;
//	}
//	printf("%d", count);
//}

//15727번 문제
//int main() {
//	int num;1
//	scanf("%d", &num);
//	if (num % 5 == 0)
//		printf("%d", num / 5);
//	else
//		printf("%d", num / 5 + 1);
//}

////14681번 문제
//int main() {
//	int num1, num2;
//	scanf("%d %d", &num1, &num2);
//	if (num1 > 0 && num2 > 0)
//		printf("1");
//	else if (num1 < 0 && num2 > 0)
//		printf("2");
//	else if (num1 < 0 && num2 < 0)
//		printf("3");
//	else
//		printf("4");
//}

////11966번 문제
//int main() {
//	int num, cnt = 1;
//	scanf("%d", &num);
//	for (int i = 1; i < num + 1; i++) {
//		if (num == cnt) {
//			printf("1");
//			return 0;
//		}
//		cnt = cnt * 2;
//	}
//	printf("0");
//}

////11134번 문제
//int main() {
//	int num;
//	scanf("%d", &num);
//	for (int i = 0; i < num; i++) {
//		int num1, num2;
//		scanf("%d %d", &num1, &num2);
//		if (num1 % num2 == 0) {
//			printf("%d\n", num1 / num2);
//		}
//		else
//			printf("%d\n", num1 / num2 + 1);
//	}
//}

////11006번 문제
//int main() {
//	int num;
//	scanf("%d", &num);
//	while (num--)
//	{
//		int c1, cnt;
//		scanf("%d %d", &c1, &cnt);
//		int temp=cnt * 2 - c1;
//		printf("%d %d\n", temp, cnt - temp);
//	}
//}

//10824번 문제
//int main() {
//	long long a, b, c, d;
//	scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
//	long long temp = b;
//	long long cnt = 0;
//	while (temp > 0)
//	{
//		temp /= 10;
//		cnt++;
//	}
//	long long cc=a*(long long)(pow(10,cnt)) + b;
//	temp = d;
//	cnt = 0;
//	while (temp > 0)
//	{
//		temp /= 10;
//		cnt++;
//	}
//	long long dd = c * (long long)(pow(10, cnt)) + d;
//
//	printf("%lld", cc + dd);

	/*long long num1, num2, num3, num4, n1, n2, count = 0, cnt = 0;
	scanf("%d %d %d %d", &num1, &num2, &num3, &num4);
	n1 = num2;
	n2 = num4;
	while (n1 != 0)
	{
		n1 = n1 / 10;
		count++;
	}
	while (n2 != 0)
	{
		n2 = n2 / 10;
		cnt++;
	}
	for (int i = 0; i < count; i++) {
		num1 = num1 * 10;
	}
	for (int i = 0; i < cnt; i++) {
		num3 = num3 * 10;
	}
	printf("%lld", (num1 + num2) + (num3 + num4));*/
	//}

	////5618번 문제
	//int main() {
	//	int num;
	//	scanf("%d", &num);
	//	if (num == 2) {
	//		int num1, num2;
	//		scanf("%d %d", &num1, &num2);
	//		if (num1 > num2) {
	//			for (int i = 1; i < num2 + 1; i++) {
	//				if (num1 % i == 0 && num2 % i == 0)
	//					printf("%d\n", i);
	//			}
	//		}
	//		else {
	//			for (int i = 1; i < num1 + 1; i++) {
	//				if (num1 % i == 0 && num2 % i == 0)
	//					printf("%d\n", i);
	//			}
	//		}
	//	}
	//	else {
	//		int num1, num2, num3;
	//		scanf("%d %d %d", &num1, &num2, &num3);
	//		if (num1 < num2 && num1 < num3) {
	//			for (int i = 1; i < num1 + 1; i++) {
	//				if (num1 % i == 0 && num2 % i == 0 && num3 % i == 0)
	//					printf("%d\n", i);
	//			}
	//		}
	//		else if (num2 < num3 && num2 < num1) {
	//			for (int i = 1; i < num2 + 1; i++) {
	//				if (num1 % i == 0 && num2 % i == 0 && num3 % i == 0)
	//					printf("%d\n", i);
	//			}
	//		}
	//		else {
	//			for (int i = 1; i < num3 + 1; i++) {
	//				if (num1 % i == 0 && num2 % i == 0 && num3 % i == 0)
	//					printf("%d\n", i);
	//			}
	//		}
	//	}
	//}

	////3003번 문제
	//int main() {
	//	int list[7] = { 1, 1, 2, 2, 2, 8 };
	//	for (int i = 0; i < 6; i++) {
	//		int num;
	//		scanf("%d", &num);
	//		printf("%d ", list[i] - num);
	//	}
	//}

	////2875번 문제
	//int main() {
	//	int num1, num2, num3, max;
	//	scanf("%d %d %d", &num1, &num2, &num3);
	//	if (num1 / 2 < num2)
	//		max = num1 / 2;
	//	else
	//		max = num2;
	//	num3 -= num1 + num2 - 3 * max;
	//	if (num3 > 0) {
	//		num3--;
	//		max -= num3 / 3 + 1;
	//	}
	//	printf("%d", max);
	//}

	////2845번 문제
	//int main() {
	//	int num1, num2;
	//	scanf("%d %d", &num1, &num2);
	//	for (int i = 0; i < 5; i++) {
	//		int num;
	//		scanf("%d", &num);
	//		printf("%d ", num - num1 * num2);
	//	}
	//}

	////2588번 문제
	//int main() {
	//	int num1, num2;
	//	scanf("%d", &num1);
	//	scanf("%d", &num2);
	//	printf("%d\n", num1 * (num2 - ((num2 / 10) * 10)));
	//	printf("%d\n", num1 * (num2 - (((num2 / 100) * 100) + num2 - (num2 / 10) * 10)) / 10);
	//	printf("%d\n", num1 * (num2 / 100));
	//	printf("%d\n", num1 * num2);
	//}

	////2476번 문제
	//int main() {
	//	int num, MAX = 0;
	//	scanf("%d", &num);
	//	for (int i = 0; i < num; i++) {
	//		int num1, num2, num3, total = 0;
	//		scanf("%d %d %d", &num1, &num2, &num3);
	//		if (num1 == num2 && num2 == num3) {
	//			total += 10000 + num2 * 1000;
	//		}
	//		else if (num1 == num2 || num2 == num3) {
	//			total = 1000 + num2 * 100;
	//		}
	//		else if (num3 == num1) {
	//			total = 1000 + num1 * 100;
	//		}
	//		else {
	//			if (num1 > num2 && num1 > num3)
	//				total = num1 * 100;
	//			else if (num2 > num3 && num2 > num1)
	//				total = num2 * 100;
	//			else if (num3 > num2 && num3 > num1)
	//				total = num3 * 100;
	//		}
	//		if (MAX < total)
	//			MAX = total;
	//	}
	//	printf("%d", MAX);
	//}

	////2475번 문제
	//int main() {
	//	int num = 0, cnt = 0;
	//	for (int i = 0; i < 5; i++) {
	//		scanf("%d", &num);
	//		cnt += num * num;
	//	}
	//	printf("%d", cnt % 10);
	//}

	////2420번 문제
	//int main() {
	//	long long num1, num2;
	//	scanf("%lld %lld", &num1, &num2);
	//	if (num1 > num2)
	//		printf("%lld", num1 - num2);
	//	else
	//		printf("%lld", num2 - num1);
	//}

	//1712번 문제
	//int main() {
	//	int num1, num2, num3, cnt = 1;
	//	scanf("%d %d %d", &num1, &num2, &num3);
	//	if (num2 >= num3) {
	//		printf("-1");
	//		return 0;`
	//	}
	//
	//	printf("%d", num1 / (num3 - num2) + 1);
	//}


	////1110번 문제
	//int main() {
	//	int num, num1 = 0, num2 = 0, num3 = 0, total = 1;
	//	scanf("%d", &num);
	//	if (num < 10) {
	//		num = num * 10;
	//	}
	//	num3 = num;
	//	while (1) {
	//		num1 += (num % 10) + (num - num % 10) / 10;
	//		num2 += num % 10 * 10 + num1 % 10;
	//		if (num3 == num2) {
	//			printf("%d", total);
	//			return;
	//		}
	//		else {
	//			num = num2;
	//			num1 = 0;
	//			num2 = 0;
	//		}
	//		total++;
	//	}
	//}












	////f(탐색 위ㅣ, 현재까지 구한 해)
	////하나는 +, 하나는 -
	////0, 0 /  1, 1    1,-1
	//int n, k, cnt;
	//int f(int idx, int chair) {
	//	if (idx == n && chair == k) {
	//		cnt++;
	//		return;
	//	}
	//	else if (idx > n || chair > k)
	//		return;
	//	else {
	//		f(idx + 1, chair);
	//	}
	//}
	//int list[444] = { 0 };
	//int main() {
	//	int num;
	//	scanf("%d", &n);
	//	scanf("%d", &num);
	//	for (int i = 0; i < num; i++) {
	//		int input = 0;
	//		scanf("%d", &input);
	//		list[i] = num;
	//	}
	//	f(0, 0);
	//	printf("%d", cnt);
	//}
	//
	////int save[1000001] = { 0 };
	////int main() {
	////	int input, input1, maxium = -1, answer = 0 ;
	////	scanf("%d %d", &input, &input1);
	////	for (int i = 0; i < input; i++) {
	////		int num;
	////		scanf("%d", &num);
	////		save[i] = num;
	////		if (num > maxium)
	////			maxium = num;
	////	}
	////	int left = 1, right = maxium, find;
	////	find = input1;
	////
	////	while (1) {
	////		int mid = (left + right) / 2;
	////		answer = 1;
	////		for (int i = 0; i < input; i++) {
	////			answer += save[i] / mid;
	////		}
	////		printf("left : %d, right : %d, mid : %d, answer : %d\n", left, right, mid, answer);
	////		if (answer < input1)
	////			right = mid - 1;
	////		else if (answer > input1)
	////			left = mid + 1;
	////		else {
	////			printf("%d", mid - 1);
	////			break;
	////		}
	////	}
	////}
	////int list[10001] = { 0 };
	////int main() {
	////	int num, total_budget, max_budget = 0, answer = 0, max = 0;
	////	scanf("%d", &num);
	////	for (int i = 0; i < num; i++) {
	////		int input;
	////		scanf("%d", &input);
	////		list[i] = input;
	////		if (max < input)
	////			max = input;
	////	}
	////	scanf("%d", &total_budget);
	////	int left = 0, right = max;
	////	while (left <= right) {
	////		int mid = (left + right) / 2;
	////		int sum_budget = 0;
	////		for (int i = 0; i < num; i++) {
	////			if (list[i] > mid)
	////				sum_budget += mid;
	////			else
	////				sum_budget += list[i];
	////		}
	////		printf("left : %d, right : %d, mid : %d, sum_budget : %d\n", left, right, mid, sum_budget);
	////		if (sum_budget <= total_budget) {
	////			if (max_budget < sum_budget) {
	////				max_budget = sum_budget;
	////				answer = mid;
	////			}
	////			left = mid + 1;
	////		}
	////		else if (sum_budget > total_budget) {
	////			right = mid - 1;
	////		}
	////	}
	////	printf("%d", answer);
	////}
	////int list[100001] = { 0 };
	////int main() {
	////	int scan, people, maxium = 0, minium, answer = 0;
	////	scanf("%d %d", &scan, &people);
	////	for (int i = 0; i < scan; i++) {
	////		int input;
	////		scanf("%d", &input);
	////		list[i] = input;
	////		if (maxium < input)
	////			maxium = input;
	////	}
	////	
	////	int left = 0, right = maxium * people;
	////	
	////	while (left <= right) {
	////		int mid = (left + right) / 2;
	////		minium = 0;
	////		for (int i = 0; i < scan; i++)
	////			minium += mid / list[i];
	////		//printf("left : %d, right : %d, mid : %d, minium : %d\n", left, right, mid, minium);
	////		if (people <= minium) {
	////			answer = mid;
	////			right = mid - 1;
	////		}
	////		else if (people > minium)
	////			left = mid + 1;
	////	}
	////	printf("%d", answer);
	////}

////4508번 문제
//int main() {
//	vector<int> list[500][2];
//	int people, know;
//	cin >> people;
//	cin >> know;
//	for (int i = 0; i < know; i++) {
//		
//	}
//}

////3270번 문제
//int table[1001];
//int V, E;
//void init() {
//	for (int i = 1; i <= V; i++)
//		table[i] = i;
//}
//int myParent(int node) {
//	if (node == table[node])
//		return node;
//	return table[node] = myParent(table[node]);
//}
//void myunion(int node1, int node2) {
//	node1 = myParent(node1);
//	node2 = myParent(node2);
//	if (node1 > node2)
//		table[node1] = node2;
//	else
//		table[node2] = node1;
//}
//int main() {
//	cin >> V >> E;
//	init();
//	for (int i = 1; i <= E; i++) {
//		int node1, node2;
//		cin >> node1 >> node2;
//		myunion(node1, node2);
//	}
//	for (int i = 1; i <= V; i++) {
//		cout << myParent(i) << " ";
//	}
//}

////4779번 문제
//int list[1000001] = { 0 };
//int dp[1000001] = { 0 };
//int main() {
//	int input;
//	int max = 0;
//	cin >> input;
//	for (int i = 0; i < input; i++) {
//		cin >> list[i];
//		dp[list[i]] = dp[list[i] - 1] + 1;
//		if (max < dp[list[i]])
//			max = dp[list[i]];
//	}
//	cout << input - max << endl;
//}

////4594번 문제
//int com(int a[], int b[])
//{
//	return a[0] > b[0]?a[0]:b[0];
//}
//vector<pair<int, int>> v;
//int main() {
//	
//	int dp[501] = {};
//	int electric_line, answer = 0;
//	cin >> electric_line;
//	for (int i = 0; i < electric_line; i++)
//	{
//		int no1, no2;
//		cin >> no1 >> no2;
//		v.push_back({ no2,no1 });
//	}
//	sort(v.begin(), v.end());
//	int max = 0;
//	for (int i = 0; i < v.size(); i++)
//	{
//		dp[i] = 1;
//		for (int j = 0; j < i; j++)
//		{
//			if (v[i].second>v[j].second && dp[j] + 1 > dp[i])
//			{
//				dp[i] = dp[j] + 1;
//			}
//			if (max < dp[i])
//				max = dp[i];
//		}
//	}
//	cout << electric_line - max << endl;
//}

////3736번 문제
//int list[100001] = { 0 };
//int dp[100001] = { 0 };
//int N;
//vector<int> v[100];
//int main() {
//	cin >> N;
//	for (int i = 0; i < N; i++)
//		cin >> list[i];
//	for (int i = 0; i < N; i++) {
//		if (v.size() == 0||v.back()<list[i])
//		{
//			v.push_back(list[i]);
//		}
//		else {
//			int idx = lower_bound(v.begin(), v.end(), list[i]) - v.begin();
//			v[idx] = list[i];
//		}
//	}
//	cout << v.size() << endl;
//}

////3735번 문제
//int N;
//int arr[100001];
//int dp[100001];
//int answer;
//int main()
//{
//	ios_base::sync_with_stdio(cin.tie(nullptr));
//	cin >> N;
//	for (int i = 1; i <= N; i++)
//	{
//		cin >> arr[i];
//	}
//	for (int i = 1; i <= N; i++)
//	{
//		dp[i] = 1;
//		for (int j = 1; j < i; j++)
//		{
//			if (arr[i] > arr[j] && dp[j] + 1 > dp[i])
//				dp[i] = dp[j] + 1;
//			
//		}
//		if (answer < dp[i])
//			answer = dp[i];
//	}
//	cout << answer;
//}

////4818번 문제
//int n, m, k;
//int table[16][16];
//int dp[16][16];
//int answer;
//int main()
//{
//	ios::sync_with_stdio(cin.tie(nullptr));
//	cin >> n >> m >> k;
//	int cnt = 1;
//	int kx = n, ky = m;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//		{
//			table[i][j] = cnt;
//			if (cnt == k)
//			{
//				kx = i;
//				ky = j;
//			}
//
//			cnt++;
//		}
//	}
//	for (int i = 1; i <= kx; i++)
//	{
//		for (int j = 1; j <= ky; j++)
//		{
//			if (i == 1 || j == 1)
//				dp[i][j] = 1;
//			else
//				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//		}
//	}
//	answer = dp[kx][ky];
//	for (int i = kx; i <= n; i++)
//	{
//		for (int j = ky; j <= m; j++)
//		{
//			if (i == kx || j == ky)
//				dp[i][j] = 1;
//			else
//				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//		}
//	}
//	cout << answer * dp[n][m] << endl;
//
//}

////3212번 문제
//int main() {
//	int degree[201] = { 0 };
//	vector<int> save[201];
//	priority_queue<int> search;
//	vector<int> answer;
//	int v, n;
//	cin >> v >> n;
//	for (int i = 0; i < n; i++) {
//		int input1, input2;
//		cin >> input1 >> input2;
//		save[input1].push_back(input2);
//		degree[input2]++;
//	}
//	for (int i = 1; i <= v; i++)
//	{
//		sort(save[i].begin(), save[i].end());
//	}
//	for (int i = 1; i <= v; i++)
//	{
//		if (degree[i] == 0)
//			search.push(-i);
//	}
//	int cnt = 0;
//	while (!search.empty()) {
//		int current_value = -search.top();
//		cnt++;
//		answer.push_back(current_value);
//		search.pop();
//		
//			for (int j = 0; j < save[current_value].size(); j++) {
//
//				int next_data = save[current_value][j];
//				degree[next_data]--;
//				if (degree[next_data] < 0)
//				{
//					
//					cout << "-1";
//					return 0;
//				}if (!degree[next_data])
//					search.push(-next_data);
//			}
//	}
//	if (cnt == v)
//	{
//		for (int i : answer)
//		{
//			cout << i << endl;
//		}
//	}
//	else {
//		cout << "-1";
//	}
//	
//	
//}


////3074번 문제
//int input;
//int dp[100001] = { 0 };
//int f(int pos = 0) {
//	if (pos <= 2)
//		return pos;
//	else if (pos == 3)
//		return 4;
//	if (dp[pos] != 0) return dp[pos];
//	dp[pos] = (f(pos - 3) + f(pos - 2) + f(pos - 1)) % 1000;
//	return dp[pos] ;
//}
//int main() {
//	cin >> input;
//	cout << f(input);
//}

////4818번 문제(구)
//int main() {
//	int dp[16][16] = { 0 };
//	int circle, height, width, temp;
//	cin >> height >> width >> circle;
//	int circle_height = circle / height - 1, circle_width = circle % height;
//	for (int i = 1; i <= circle_height; i++)
//		dp[i][0] = 1;
//	for (int i = 1; i <= circle_width; i++)
//		dp[0][i] = 1;
//	for (int i = 1; i <= circle_height; i++) {
//		for (int j = 1; j <= circle_width; j++)
//			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//	}
//	temp = dp[circle_height][circle_width];
//	dp[circle_height][circle_width] = 1;
//	for (int i = circle_height; i < height; i++)
//		dp[i][circle_width] = 1;
//	for (int i = circle_width; i < width; i++)
//		dp[circle_height][i] = 1;
//	for (int i = circle_height + 1; i < height; i++) {
//		for (int j = circle_width + 1; j < width; j++)
//			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//	}
//	cout << temp * dp[height - 1][width - 1];
//}

////3802번 문제
//int input;
//int check(int num) {
//	int count = 0, temp = 1;
//	do {
//		if (num % 10 + 1 == temp || num % 10 - 1 == temp)
//			count++;
//		temp = num % 10;
//		num /= 10;
//	} while (num != 0);
//	if (count == input)
//		return 1;
//	else
//		return 0;
//}
//int main() {
//	int answer = 0;
//	cin >> input;
//	for (int i = 1; i <= ; i++) {
//		answer += check(i);
//	}
//	cout << answer;
//}

////3701번 문제
//long long int dp[51][51] = { 0 };
//int main() {
//	int num;
//	cin >> num;
//	dp[1][1] = 1;
//	for (int row = 1; row <= num; row++) {
//		for (int col = 1; col <= num; col++) {
//			if (col == 1 || col == row)
//				dp[row][col] = 1;
//			else
//				dp[row][col] = dp[row - 1][col - 1] + dp[row - 1][col];
//		}
//	}
//	for (int i = 1; i <= num; i++) {
//		for (int j = 1; j <= i; j++) {
//			cout << dp[i][j] << " ";
//		}
//		cout << endl;
//	}
//}

////3710번 문제
//int check(int num) {
//	int count = 0;
//	do {
//		if (num % 10 == 3 || num % 10 == 6 || num % 10 == 9)
//			count++;
//		num /= 10;
//	} while (num != 0);
//	return count;
//}
//int main() {
//	int a, b, answer = 0;
//	cin >> a >> b;
//	for (int i = a; i <= b; i++) {
//		answer += check(i);
//	}
//	cout << answer;
//}

////3701번 문제
//int main() {
//	long long int tree[51] = { 0 }, height;
//	cin >> height;
//	tree[1] = 1, tree[2] = 1;
//	for (int i = 3; i <= height; i++) {
//		if (i % 2 == 0)
//			tree[i] = tree[i - 1] * 2 - 1;
//		else
//			tree[i] = tree[i - 1] * 2 + 1;
//	}
//	cout << tree[height];
//}

////3725번 문제
//int main() {
//	long long int tree[62] = { 0 }, height;
//	cin >> height;
//	tree[1] = 1, tree[2] = 1;
//	for (int i = 3; i <= height; i++) {
//		if (i % 2 == 0)
//			tree[i] = tree[i - 1] * 2 - 1;
//		else
//			tree[i] = tree[i - 1] * 2 + 1;
//	}
//	cout << tree[height];
//}

////3705번 문제
//int dp[100001] = { 0 }, list[100001] = { 0 };
//int main() {
//	int count, max = -101;
//	cin >> count;
//	for (int i = 0; i < count; i++)
//		cin >> list[i];
//	for (int i = 0; i < count; i++) {
//		if (i == 0)
//			dp[0] = list[0];
//		else {
//			dp[i] = dp[i - 1] + list[i] > list[i] ? dp[i - 1] + list[i] : list[i];
//			
//		}
//		if (max < dp[i])
//			max = dp[i];
//	}
//	cout << max;
//}

//
////3711번 문제
//int k;
//int check(int num) {
//	int count = 0;
//	do {
//		if (num % 10 == k)
//			count++;
//		num /= 10;
//	} while (num != 0);
//	return count;
//}
//int main() {
//	int a, b, answer = 0;
//	cin >> a >> b >> k;
//	for (int i = a; i <= b; i++) {
//		answer += check(i);
//	}
//	cout << answer;
//}

////3703번 문제
//
//int main() {
//	int n, m;
//	int data[100][100] = {};
//	int dp[100][100] = {};
//	scanf("%d %d", &n, &m);
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < m; j++)
//			scanf("%d", &data[i][j]);
//	dp[0][0] = data[0][0];
//
//	for (int i = 1; i < n; i++)
//		dp[i][0] = dp[i - 1][0] + data[i][0];
//	for (int j = 1; j < m; j++)
//		dp[0][j] = dp[0][j - 1] + data[0][j];
//
//	for (int i = 1; i < n; i++)
//	{
//		for (int j = 1; j < m; j++)
//		{
//			if(dp[i-1][j] > dp[i][j-1])
//			dp[i][j] = dp[i - 1][j] + data[i][j];
//			else
//				dp[i][j] = dp[i][j-1] + data[i][j];
//		}
//	}
//	printf("%d", dp[n - 1][m - 1]);
//}

////2601번 문제
//int main() {
//	int list[41] = { 0 };
//	int list_len;
//	list[1] = 1;
//	list[2] = 1;
//	cin >> list_len;
//	for (int i = 3; i <= list_len; i++)
//		list[i] = list[i - 1] + list[i - 2];
//	cout << list[list_len];
//}

////4697번 문제
//int list_len, list[101][101] = { 0 }, check[101][101] = { 0 }, answer = 0, MAX = 0;
//int nx[4] = { 1, -1, 0, 0 }, ny[4] = {0, 0, 1, -1};
//void DFS(int x, int y, int height) {
//	check[x][y] = 1;
//	for (int i = 0; i < 4; i++) {
//		int cx = x + nx[i];
//		int cy = y + ny[i];
//		if (0 <= cx && cx < list_len && 0 <= cy && cy < list_len && list[cx][cy] > height && check[cx][cy] == 0)
//			DFS(cx, cy, height);
//	}
//}
//int main() {
//	cin >> list_len;
//	for (int i = 0; i < list_len; i++) {
//		for (int j = 0; j < list_len; j++)
//			cin >> list[i][j];
//	}
//	for (int k = 0; k < 101; k++) {
//		memset(check, 0, sizeof(check));
//		answer = 0;
//		for (int i = 0; i < list_len; i++) {
//			for (int j = 0; j < list_len; j++) {
//				if (check[i][j] == 0 && list[i][j] > k) {
//					DFS(i, j, k);
//					answer++;
//				}
//			}
//		}
//		if (MAX < answer)
//			MAX = answer;
//	}
//	cout << MAX;
//}

//int len, check[11] = { 0 };
//vector<int> list[12];
//void DFS(int index = 0) {
//	check[index] = 1;
//	printf("%c ", index + 65);
//	for (int i = 0; i < list[index].size(); i++) {
//		if (check[list[index][i]] == 0) {
//			DFS(list[index][i]);
//		}
//	}
//}
//queue<int> q;
//void BFS() {
//	q.push(0);
//	check[0] = 1;
//	while (!q.empty()) {
//		int current_value = q.front();
//		q.pop();
//		printf("%c ", current_value + 65);
//		for (int i = 0; i < list[current_value].size(); i++) {
//			int temp = list[current_value][i];
//			if (check[temp] == 0) {
//				check[temp] = 1;
//				q.push(temp);
//			}
//		}
//	}
//}
//int main() {
//	cin >> len;
//	for (int i = 0; i < len; i++) {
//		char save1, save2;
//		cin >> save1;
//		cin >> save2;
//		save1 -= 65;
//		save2 -= 65;
//		list[save1].push_back(save2);
//		list[save2].push_back(save1);
//	}
//	cout << "DFS:" << endl;
//	DFS();
//	memset(check, 0, 11 * sizeof(int));
//	cout << endl << "BFS:" << endl;
//	BFS();
//	memset(check, 0, 11 * sizeof(int));
//	return 0;
//}

////2748번 문제
//int m, n, list[21] = { 0 }, answer = 0;
//void f(int index = 0, int sum = 0) {
//	if (index == n) {
//		if (sum == m) {
//			answer++;
//			return;
//		}
//		else
//			return;
//	}
//	f(index + 1, sum + list[index]);
//	f(index + 1, sum - list[index]);
//}
//int main() {
//	cin >> m;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> list[i];
//	}
//	f();
//	cout << answer;
//}

////3008번 문제
//int all[10];
//int dwarf[8];
//void f(int search = 0, int sum = 0, int select = 0) {
//	if (search > 9 || sum > 100 || select > 7)
//		return;
//	if (search == 9 && sum == 100 && select == 7) {
//		for (int i = 0; i < 7; i++) {
//			cout << dwarf[i] << endl;
//		}
//		return;
//	}
//	dwarf[select] = all[search];
//	f(search + 1, sum + all[search], select + 1);
//	f(search + 1, sum, select);
//}
//int main() {
//	for (int i = 0; i < 9; i++)
//		cin >> all[i];
//	//sort(all, all + 9);
//	f();
//}
//int stature[10] = { 0 };
//int answer[8] = { 0 };
//int f(int index, int level, int total) {
//	if (index > 8 || level > 7 || total > 100)
//		return 0;
//	if (level == 7 && total == 100) {
//		for (int i = 0; i < 7; i++) {
//			cout << answer[i] << endl;
//		}
//		return 0;
//	}
//	f(index + 1, level, total);
//	answer[level] = stature[index];
//	f(index + 1, level + 1, total + stature[index]);
//}
//int main() {
//	for (int i = 0; i < 9; i++)
//		cin >> stature[i];
//	sort(stature, stature + 9);
//	f(0, 0, 0);
//}

////4033번 문제
//int total_coloring, save[21], total, answer = 0;
//int trace[21];
//void f(int status = 0, int value = 0,int flag = 0) {
//	if (status > total)
//		return;
//	if (value == total_coloring && total == status) {
//		answer++;
//		return;
//	}
//	if (flag == 1) {
//		f(status + 1, value, 0);
//	}
//	else {
//		f(status + save[value], value + 1, 1);
//		f(status + 1, value, 0);
//	}
//}
//int main() {
//	cin >> total;
//	cin >> total_coloring;
//	for (int i = 0; i < total_coloring; i++)
//		cin >> save[i];
//	f();
//	cout << answer << endl;
//}

////3530번 문제
//int list[10][10];
//int zero[81][2];
//int zero_idx, flag = 0;
//int promissing(int state) {
//	int col = zero[state][0];
//	int row = zero[state][1];
//	for (int i = 0; i < 9; i++) {
//		if (list[col][i] == list[col][row] && i != row)
//			return 0;
//		if (list[i][row] == list[col][row] && i != col)
//			return 0;
//	}
//	for (int i = (col / 3) * 3; i < (col / 3) * 3 + 3; i++) {
//		for (int j = (row / 3) * 3; j < (row / 3) * 3 + 3; j++) {
//			if (i == col && j == row)
//				continue;
//			if (list[i][j] == list[col][row])
//				return 0;
//		}
//	}
//	return 1;
//}
//void f(int state) {
//	if (state == zero_idx) {
//		flag = 1;
//		for (int i = 0; i < 9; i++) {
//			for (int j = 0; j < 9; j++)
//				cout << list[i][j] << " ";
//			cout << endl;
//		}
//		return;
//	}
//	for (int i = 1; i <= 9; i++) {
//		int cur_x = zero[state][0];
//		int cur_y = zero[state][1];
//		list[cur_x][cur_y] = i;
//
//		if (promissing(state))
//		{
//			f(state + 1);
//		}
//		list[cur_x][cur_y] = 0;
//
//	}
//}
//int main() {
//	
//	for (int i = 0; i < 9; i++) {
//		for (int j = 0; j < 9; j++) {
//			cin >> list[i][j];
//			if (list[i][j] == 0)
//			{
//				zero[zero_idx][0] = i;
//				zero[zero_idx++][1] = j;
//			}
//		}
//	}
//	f(0);
//	if (flag == 0)
//		cout << "Not Possible" << endl;
//}

////3520번 문제
//int check[14];
//int n, answer = 0;
//int promissing(int row)
//{
//	//같은 열에 다른 퀸이 있는가?
//	for (int i = 1; i < row; i++)
//	{
//		if (check[i] == check[row])return 0;
//	}
//
//	// 대각선&역대각선에 다른 퀸이 있는가?
//	for (int i = 1; i < row; i++) {
//		if (abs(check[row] - check[i]) == row - i)
//			return 0;
//	}
//	return 1;
//}
//void backTracking(int row)
//{
//	if (row == n + 1)
//	{
//		answer++;
//		if (answer < 4) {
//			for (int i = 1; i <= n; i++)
//			{
//				printf("%d ", check[i]);
//			}
//			cout << endl;
//		}
//		return;
//	}
//	for (int col = 1; col <= n; col++)
//	{
//		check[row] = col;
//		if (promissing(row))
//		{
//			backTracking(row + 1);
//		}
//		check[row] = 0;
//	}
//}
//int main()
//{
//	scanf("%d", &n);
//	backTracking(1);
//	printf("%d", answer);
//}

////2653번 문제
//int save[21] = { 0 }, answer = 0, total;
//void f(int list[], int index, int flag) {
//	if (index == total) {
//		++answer;
//		return;
//	}
//	if (flag == 0)
//		f(list, index + 1, 1);
//	f(list, index + 1, 0);
//}
//int main() {
//	cin >> total;
//	f(save, 0, 0);
//	cout << answer;
//}

////3501번 문제
//int house[1001][4] = { 0 }, total_house, answer = 999999;
//void f(int pos, int money, int color) {
//	if (total_house > pos) {
//		if (color == 0) {
//			f(pos + 1, money + house[pos][1], 1);
//			f(pos + 1, money + house[pos][2], 2);
//		}
//		else if (color == 1) {
//			f(pos + 1, money + house[pos][0], 0);
//			f(pos + 1, money + house[pos][2], 2);
//		}
//		else if (color == 2) {
//			f(pos + 1, money + house[pos][0], 0);
//			f(pos + 1, money + house[pos][1], 1);
//		}
//		else {
//			f(pos + 1, money + house[pos][0], 0);
//			f(pos + 1, money + house[pos][1], 1);
//			f(pos + 1, money + house[pos][2], 2);
//		}
//	}
//	else
//		if (answer > money) {
//			answer = money;
//			
//		}
//}
//int main() {
//	cin >> total_house;
//	for (int i = 0; i < total_house; i++) {
//		cin >> house[i][0] >> house[i][1] >> house[i][2];
//	}
//	f(0, 0, -1); //R:0 G:1 B:2
//	cout << answer << endl;
//}

////4472번 문제
//
//int weight[31] = { 0 }, marble[8] = { 0 };
//int total_weight, total_marble;
//int table[280001];
//void f(int idx, int curWeight)
//{
//	if (curWeight >= 0)
//	{
//		table[curWeight] = 1;
//	}
//	if (idx < total_weight) {
//		f(idx + 1, curWeight - weight[idx]);
//		f(idx + 1, curWeight);
//		f(idx + 1, curWeight + weight[idx]);
//	}
//}
//
//int main() {
//	
//	cin >> total_weight;
//	for (int i = 0; i < total_weight; i++)
//		cin >> weight[i];
//	cin >> total_marble;
//	for (int i = 0; i < total_marble; i++)
//		cin >> marble[i];
//	f(0, 0); // 아무것도 없는 상태 
//
//	for (int i = 0; i < total_marble; i++)
//	{
//		if (table[marble[i]])
//			printf("Y ");
//		else
//			printf("N ");
//	}
//}

//////4713번 문제
//int n;
//pair<int, int> f[100001];
//int main() {
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++) {
//		int a, b, c, d;
//		cin >> a >> b >> c >> d;
//		f[i].first = a * 100 + b, f[i].second = c * 100 + d;
//	}
//	sort(f, f + n);
//	int date = 301, flag = 0, temp = 0, ans = 0, i = -1;
//	while (date <= 1130 && i < n) {
//		flag = 0, i++;
//		for (int j = i; j < n; j++) {
//			if (f[j].first > date)
//				break;
//			if (temp < f[j].second)
//				temp = f[j].second, flag = 1, i = j;
//		}
//		if (flag)
//			date = temp, ans++;
//		else {
//			cout << 0 << endl;
//			return 0;
//		}
//	}
//	cout << ans << endl;
//}
//int born[100001] = { 0 }, die[100001] = { 0 };
//int main() {
//	int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	int total_flower, start = 91, end = 334, answer = 0;
//	cin >> total_flower;
//	for (int i = 0; i < total_flower; i++) {
//		int save1, save2, save3, save4, total1 = 0, total2 = 0;
//		cin >> save1 >> save2 >> save3 >> save4;
//		for (int j = 0; j < save1 - 1; j++)
//			total1 += month[j] - 1;
//		total1 += save2;
//		for (int j = 0; j < save3 - 1; j++)
//			total2 += month[j] - 1;
//		total2 += save4;
//		born[i] = total1;
//		die[i] = total2;
//	}
//	//*or (int i = 0; i < total_flower; i++) {
//		cout << born[i] << "  " << die[i] << endl;
//	//}
//	for (int i = total_flower; i > 0; i--) {
//		for (int j = 0; j < i; j++) {
//			if (born[j] > born[j + 1]) {
//				int temp = born[j];
//				born[j] = born[j + 1];
//				born[j + 1] = temp;
//				temp = die[j];
//				die[j] = die[j + 1];
//				die[j + 1] = temp;
//			}
//		}
//	}
//	/*for (int i = 0; i < total_flower; i++) {
//		cout << born[i] << "  " << die[i] << endl;
//	}*/
//	int standard = 91, count = 0;
//	for (int i = 0; i < total_flower;) {
//		int max = 0;
//		while (standard <= born[i]) {
//			if (max < die[i])
//				max = die[i];
//			i++;
//		}
//		if (max == 0) {
//			cout << 0 << endl;
//			return 0;
//		}
//		standard = max;
//		answer++;
//	}
//	cout << answer << endl;
//	//int standard = 91;
//	//int compar[100001] = { 0 };
//	//while (1) {
//	//	memset(compar, 0, sizeof(compar));
//	//	for (int i = 0; i < total_flower; i++) {
//	//		if (born[i] < standard)
//	//			compar[i] = die[i];
//	//	}
//	//	int max = 0;
//	//	for (int i = 0; i < total_flower; i++) {
//	//		if (max < compar[i])
//	//			max = compar[i];
//	//	}
//	//	//cout << max << endl;
//	//	standard = max;
//	//	answer++;
//	//	if (max >= 333)
//	//		break;
//	//	/*for (int i = 0; i < total_flower; i++) {
//	//		if (start >= born[i])
//	//			if (die[i] > max)
//	//				max = die[i];
//	//	}
//	//	start = max;
//	//	answer++;
//	//	if (max >= end) {
//	//		cout << answer << endl;
//	//		return 0;
//	//	}*/
//	//}
//	//cout << answer << endl;
//}

////2001번 문제
//int main() {
//	int price[5];
//	int pasta, juice;
//	for (int i = 0; i < 5; i++)
//		cin >> price[i];
//	pasta = price[0];
//	if (pasta > price[1])
//		pasta = price[1];
//	if (pasta > price[2])
//		pasta = price[2];
//	juice = price[3];
//	if (juice > price[4])
//		juice = price[4];
//	printf("%.1lf", (pasta + juice) * 1.1);
//}

////3301번 문제
//int main() {
//	int money, answer = 0;
//	cin >> money;
//	answer += money / 50000;
//	answer += money % 50000 / 10000;
//	answer += money % 10000 / 5000;
//	answer += money % 5000 / 1000;
//	answer += money % 1000 / 500;
//	answer += money % 500 / 100;
//	answer += money % 100 / 50;
//	answer += money % 50 / 10;
//	printf("%d", answer);
//}

////3120번 문제:그리디
//void swap(int* a, int* b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//int main() {
//	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//	int num1, num2, count = 0;
//	cin >> num1 >> num2;
//	if (num1 > num2)
//		swap(num1, num2);
//	while (num1 != num2)
//	{
//		if (num2 - num1 >= 8)
//			num1 += 10;
//		else if (num2 - num1 >= 3)
//			num1 += 5;
//		else
//			num1++;
//		count++;
//		if (num1 > num2)
//			swap(num1, num2);
//	}
//	cout << count << endl;
//}

////4502번 문제
//int main() {
//	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//	int student, list[101] = { 0 }, save[101] = { 0 };
//	cin >> student;
//	for (int i = 0; i < student; i++)
//		cin >> list[i];
//	for (int i = 0; i < student; i++) {
//		if (save[i - list[i]] == 0)
//			save[i - list[i]] = i + 1;
//		else {
//			int temp = save[i - list[i]];
//			save[i - list[i]] = i + 1;
//			save[i] = temp;
//		}
//		
//	}
//	for (int i = 0; i < student; i++) {
//		cout << save[i] << endl;
//	}
//}

////19939번 문제
//int main() {
//	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//	int ball, basket;
//	cin >> ball >> basket;
//	int sum = 0;
//	for (int i = 1; i <= basket; i++)
//		sum += i;
//	if (sum <= ball) {
//		if ((ball - sum) % basket == 0)
//			cout << basket - 1 << endl;
//		else
//			cout << basket << endl;
//	}
//	else
//		cout << "-1" << endl;
//}

//int main() {
//	int num1, num2;tfh
//	cin >> num1 >> num2;
//	vector<char> list(num1);
//	for (int i = 0; i < num1; i++)
//		cin >> list[i];
//	int count = 0;
//	for (int i = 0; i < num1; i++) {
//		if (list[i] == 'P') {
//			for (int j = i - num2; j <= i + num2; j++) {
//				if (j < 0 || j > num1 - 1)
//					continue;
//				if (list[j] == 'H') {
//					count++;
//					list[j] = 'N';
//					break;
//				}
//			}
//		}
//	}
//	cout << count << '\n';
//}

//int main() {
//    int width, height, num, sum = 0;
//    cin >> width >> height >> num;
//    int num1, num2, list[101] = { 0 };
//    for (int i = 0; i <= num; i++) {
//        cin >> num1 >> num2;
//        switch (num1) {
//            case 1:
//                list[i] = num2;
//                break;
//            case 2:
//                list[i] = 2 * width + height - num2;
//                break;
//            case 3:
//                list[i] = 2 * (width + height) - num2;
//                break;
//            case 4:
//                list[i] = width + num2;
//                break;
//        }
//    }
//    for (int i = 0; i < num; i++) {
//        int temp = abs(list[i] - list[num]);
//        sum += (temp < (width + height)) ? temp : 2 * (width + height) - temp;
//    }
//    cout << sum;
//}

//4685번 문제
////4714번 문제
//int main() {
//	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//	vector<int> save[501];
//	queue<int> search;
//	int visit[501] = { 0 }, calculate[501][2] = { 0 }, student, line, answer = 0;
//	cin >> student;
//	cin >> line;
//	for (int i = 0; i < line; i++) {
//		int num1, num2;
//		cin >> num1 >> num2;
//		save[num1].push_back(num2);
//	}
//	for (int i = 1; i <= student; i++) {
//		memset(visit, 0, sizeof(visit));
//		search.push(i);
//		visit[i] = 1; 
//		while (!search.empty()) {
//			int current_value = search.front();
//			search.pop();
//			for (int j = 0; j < save[current_value].size(); j++) {
//				int next_data = save[current_value][j];
//				if (visit[next_data] == 0) {
//					visit[next_data] = 1;
//					calculate[i][0]++;
//					calculate[next_data][1]++;
//					search.push(next_data);
//				}
//			}
//		}
//	}
//	for (int i = 1; i <= student; i++) {
//		if (calculate[i][0] + calculate[i][1] + 1 == student)
//			answer++;
//	}
//	cout << answer;
//}

//4023번 문제
//int save[20][20] = { 0 }, visit[20][20] = { 0 };
//typedef struct save_val {
//	int col, row, direction;
//} VALUE;
//int main() {
//	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//	int dx[4] = { 1, 1, 0, -1 }, dy[4] = { 0, -1, -1, -1 };
//	for (int i = 0; i < 10; i++) {
//		for (int j = 0; j < 19; j++)
//			cin >> save[i][j];
//	}
//	queue<VALUE> search;
//	for (int i = 0; i < 19; i++) {
//		for (int j = 0; j < 19; j++) {
//			if (save[i][j] == 1) {
//				visit[i][j] = 1;
//				search.push({ i, j, 0 });
//			}
//		}
//	}
//	for (int i = 0; i < 4; i++) {
//		int search_inform[2] = { dy[i], dx[i] };
//
//	}
//	int cnt = 1;
//	while (!search.empty()) {
//		VALUE cur_inform = search.front();
//		search.pop();
//		VALUE next_inform = { cur_inform.col, cur_inform.row, cur_inform.direction};
//		if (0 <= next_inform.col && next_inform.col < 19 &&
//			0 <= next_inform.row && next_inform.row < 19 &&
//			save[next_inform.col][next_inform.row] == 1) {
//			visit[next_inform.col][next_inform.row] = 1;
//			cnt++;
//			search.push({ next_inform.col, next_inform.row, next_inform.direction});
//		}
//	}
//	printf("%d", cnt);
//}

//int visit[101][101][101], save[101][101][101];
//typedef struct position {
//	int height, col, row;
//} POS;
//int main() {
//	int search_range[6][3] = { {0, 0, 1}, {0, 0, -1}, {0, 1, 0}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0} };
//	int width, length, height, overlap = 1;
//	queue<POS> search;
//	cin >> width >> length >> height;
//	for (int i = 0; i < height; i++) {
//		for (int j = 0; j < length; j++) {
//			for (int n = 0; n < width; n++) {
//				cin >> save[i][j][n];
//				if (save[i][j][n] == -1)
//					visit[i][j][n] = -1;
//				else if (save[i][j][n] == 1) {
//					visit[i][j][n] = 1;
//					search.push({ i, j, n });
//				}
//				else
//					overlap = 0;
//			}
//		}
//	}
//	if (overlap == 1) {
//		cout << "0";
//		return 0;
//	}
//	while (!search.empty()) {
//		POS cur_pos = search.front();
//		search.pop();
//		for (int i = 0; i < 6; i++) {
//			POS next_pos = { cur_pos.height + search_range[i][2], cur_pos.col + search_range[i][1], cur_pos.row + search_range[i][0] };
//			if (0 <= next_pos.height && next_pos.height < height &&
//			0 <= next_pos.col && next_pos.col < length &&
//			0 <= next_pos.row && next_pos.row < width &&
//			save[next_pos.height][next_pos.col][next_pos.row] == 0 &&
//			visit[next_pos.height][next_pos.col][next_pos.row] == 0) {
//				visit[next_pos.height][next_pos.col][next_pos.row] = visit[cur_pos.height][cur_pos.col][cur_pos.row] + 1;
//				search.push(next_pos);
//			}
//		}
//	}
//	int max = 0;
//	for (int i = 0; i < height; i++) {
//		for (int j = 0; j < length; j++) {
//			for (int n = 0; n < width; n++) {
//				if (max < visit[i][j][n])
//					max = visit[i][j][n];
//				if (visit[i][j][n] == 0) {
//					cout << "-1";
//					return 0;
//				}
//			}
//		}
//	}
//	cout << max - 1;
//}
////4773번 문제
//typedef struct position {
//	int z, x, y;
//} pos;
//int visit[101][101][101] = { 0 };
//int main() {
//	int search_range[6][3] = { {0, 0, 1}, {0, 0, -1}, {0, 1, 0}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0} };
//	queue<pos> search;
//	int width, length, height;
//	cin >> width >> length >> height;
//	for (int i = 0; i < height; i++) {
//		for (int j = 0; j < length; j++) {
//			for (int n = 0; n < width; n++) {
//				cin >> visit[height][width][length];
//			}
//		}
//	}
//	for (int i = 0; i < height; i++) {
//		for (int j = 0; j < length; j++) {
//			for (int n = 0; n < width; n++) {
//
//			}
//
//			while (!search.empty()) {
//				int current_pos[3] = { search.front().z, search.front().x, search.front().y };
//				search.pop();
//				for (int i = 0; i < 6; i++) {
//					int next_pos[3] = { search_range[i][0] + current_pos[0], search_range[i][1] + current_pos[1], search_range[i][2] + current_pos[2] };
//					if (visit[next_pos[0]][next_pos[1]][next_pos[2]] == 0) {
//						visit[next_pos[0]][next_pos[1]][next_pos[2]] = 1;
//						search.push({ next_pos[0], next_pos[1], next_pos[2] });
//					}
//				}
//			}
//		}
//	}
//}

////4024번 문제
//int width, height, answer, visit[101][101] = { 0 };
//char save[101][101] = { 0 };
//void DFS(int x, int y) {
//	visit[x][y] = 1;
//	int dx[8] = { 0, -1, -1, -1, 0, 1, 1, 1 }, dy[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
//	for (int i = 0; i < 8; i++) {
//		int next_pos[2] = { dx[i] + x, dy[i] + y };
//		if (0 <= next_pos[0] && next_pos[0] < height && 0 <= next_pos[1] && next_pos[1] < width && visit[next_pos[0]][next_pos[1]] == 0 && save[next_pos[0]][next_pos[1]] == 'L') {
//			DFS(next_pos[0], next_pos[1]);
//		}
//	}
//}
//int main() {
//	cin >> width >> height;
//	for (int i = 0; i < height; i++) {
//		for (int j = 0; j < width; j++) {
//			cin >> save[i][j];
//		}
//	}
//	for (int i = 0; i < height; i++) {
//		for (int j = 0; j < width; j++) {
//			if (visit[i][j] == 0 && save[i][j] == 'L') {
//				DFS(i, j);
//				answer++;
//			}
//		}
//	}
//	cout << answer << endl;
//}

////2608번 문제
//int num;
//char str[7];
//void f(int idx) {
//	if (idx == num)
//	{
//		printf("%s\n", str);
//		return;
//	}
//	str[idx] = 'O';
//	f(idx + 1);
//	str[idx] = 'X';
//	f(idx + 1);
//}
//int main() {
//	cin >> num;
//	f(0);
//	printf("%s 그다음 %s", __DATE__, __TIME__);
//}

//4572번 문제
//int main() {
//	int save[101] = { 0 }, visit[101][101] = { 0 };
//	int dx[4] = { 0, 0, 1, -1 }, dy[4] = { 1, -1, 0, 0 };
//	int width, length, total, answer = 0, temp = 0;
//	queue <pair<int, int>> search;
//	cin >> length >> width >> total;
//	for (int i = 0; i < total; i++) {
//		int num1, num2, num3, num4;
//		cin >> num1 >> num2 >> num3 >> num4;
//		for (int j = num2; j < num4; j++) {
//			for (int n = num1; n < num3; n++) {
//				visit[j][n] = 9;
//			}
//		}
//	}
//	for (int i = 0; i < length; i++) {
//		for (int j = 0; j < width; j++) {
//			if (visit[i][j] == 0) {
//				search.push({ i,j });
//				visit[i][j] = 1;
//				int cnt = 1;
//				while (!search.empty()) {
//					int cur_position[2] = { search.front().first, search.front().second };
//					search.pop();
//					for (int i = 0; i < 4; i++) {
//						int next_position[2] = { cur_position[0] + dx[i], cur_position[1] + dy[i] };
//						if (next_position[0] >= 0 && next_position[0] < length &&
//							next_position[1] >= 0 && next_position[1] < width &&
//							visit[next_position[0]][next_position[1]] == 0) {
//							visit[next_position[0]][next_position[1]] = 1;
//							search.push({ next_position[0], next_position[1] });
//							cnt++;
//						}
//					}
//				}
//				save[temp] = cnt;
//				temp++;
//				answer++;
//			}
//		}
//	}
//	cout << answer << endl;
//	sort(save, save + temp);
//	for (int i = 0; i < temp; i++)
//		cout << save[i] << " ";
//}

////3120번 문제
//int visit[41] = { 0 };
//int main() {
//	int answer = 0;
//	int plus[3] = { 1, 5, 10 }, minus[3] = { -1, -5, -10 };
//	queue<int> search;
//	int pos_1, pos_2;
//	cin >> pos_1 >> pos_2;
//	search.push(pos_1);
//	visit[pos_1] = 1;
//	while (!search.empty()) {
//		int cur_pos = search.front();
//		search.pop();
//		if (cur_pos == pos_2) {
//			cout << visit[cur_pos] - 1;
//			break;
//		}
//		for (int i = 0; i < 3; i++) {
//			if (visit[cur_pos + plus[i]] == 0 && cur_pos + plus[i] <= 40) {
//				search.push(cur_pos + plus[i]);
//				visit[cur_pos + plus[i]] = visit[cur_pos] + 1;
//			}
//		}
//		for (int i = 0; i < 3; i++) {
//			if (visit[cur_pos + minus[i]] == 0 && cur_pos + minus[i] >= 0) {
//				search.push(cur_pos + minus[i]);
//				visit[cur_pos + minus[i]] = visit[cur_pos] + 1;
//			}
//		}
//	}
//}

////1697번 문제
//int visit[1000001];
//int main() {
//	int answer = 0;
//	queue<int> search;
//	int pos_1, pos_2;
//	cin >> pos_1 >> pos_2;
//	search.push(pos_1);
//	visit[pos_1] = 1;
//	while (!search.empty()) {
//		int cur_pos = search.front();
//		search.pop();
//		if (cur_pos == pos_2) {
//			cout << visit[cur_pos] - 1;
//			break;
//		}
//		if (visit[cur_pos - 1] == 0 && cur_pos - 1 >= 0) {
//			search.push(cur_pos - 1);
//			visit[cur_pos - 1] = visit[cur_pos] + 1;
//		}
//		if (visit[cur_pos + 1] == 0 && cur_pos + 1 <= 100000) {
//			search.push(cur_pos + 1);
//			visit[cur_pos + 1] = visit[cur_pos] + 1;
//		}
//		if (visit[cur_pos * 2] == 0 && cur_pos * 2 <= 100000) {
//			search.push(cur_pos * 2);
//			visit[cur_pos * 2] = visit[cur_pos] + 1;
//		}
//	}
//}

////2178번 문제
//int main() {
//	int save[101][101] = { 0 }, answer[101][101] = { 0 };
//	int visit[101][101] = { 0 };
//	int dx[] = {-1,1,0,0};
//	int dy[] = { 0,0,-1,1 };
//	int width, height;
//	cin >> width;
//	cin >> height;
//	int pos_x = width - 1;
//	int pos_y = height - 1;
//	for (int i = 0; i < width; i++) {
//		for (int j = 0; j < height; j++) {
//			scanf("%1d", &save[i][j]);
//		}
//	}
//	queue<pair<int, int>> search;
//	search.push({0, 0});
//	visit[0][0] = 1;
//	answer[0][0] = 1;
//	while (!search.empty()) {
//		int cur_y = search.front().first;
//		int cur_x = search.front().second;
//		search.pop();
//		for (int i = 0; i < 4; i++) {
//			int ny = cur_y + dy[i];
//			int nx = cur_x + dx[i];
//			if (visit[ny][nx] == 0 && save[ny][nx] == 1) {
//				visit[ny][nx] = 1;
//				answer[ny][nx] = answer[cur_y][cur_x] + 1;
//				search.push({ ny,nx });
//			}
//		}
//	}
//	cout << answer[pos_x][pos_y];
//
//}

////4454문제 re
//int main() {
//	int max_people, relation, people1, people2, answer = 0, degree[101] = { 0 };
//	queue<int> list;
//	vector<int> save[101];
//	cin >> max_people;
//	cin >> people1 >> people2;
//	cin >> relation;
//	for (int i = 1; i <= relation; i++) {
//		int num1, num2;
//		cin >> num1 >> num2;
//		save[num1].push_back(num2);
//		save[num2].push_back(num1);
//	}
//	int visit[101] = { 0 };
//	visit[people1] = 1;
//	degree[people1] = 0;
//	list.push(people1);
//	while (!list.empty()) {
//		int current_value = list.front();
//		list.pop();
//		for (int i = 0; i < save[current_value].size(); i++) {
//			int next_data = save[current_value][i];
//			if (visit[next_data] == 0) {
//				degree[next_data] = degree[current_value] + 1;
//				list.push(next_data);
//				visit[next_data] = 1;
//				answer++;
//			}
//		}
//	}
//	if (degree[people2] == 0)
//		cout << -1;
//	else
//		cout << degree[people2];
//}

////1260번 문제
//int num1, num2, start_number;
//int visit[1001] = { 0 };
//vector<int> list[1001];
//void DFS(int cur_node) {
//	cout << cur_node << " ";
//	visit[cur_node] = 1;
//	for (int i = 0; i < list[cur_node].size(); i++) {
//		int next_node = list[cur_node][i];
//		if (visit[next_node] == 0)
//			DFS(next_node);
//	}
//}
//void BFS(int cur_node) {
//	queue<int> save;
//	save.push(cur_node);
//	visit[cur_node] = 1;
//	while (!save.empty()) {
//		int cur = save.front();
//		save.pop();
//		cout << cur << " ";
//		for (int i = 0; i < list[cur].size(); i++) {
//			int next_node = list[cur][i];
//			if (visit[next_node] == 0) {
//				save.push(next_node);
//				visit[next_node] = 1;
//			}
//		}
//	}
//}
//int main() {
//	cin >> num1 >> num2 >> start_number;
//	for (int i = 0; i < num2; i++) {
//		int node1, node2;
//		cin >> node1 >> node2;
//		list[node1].push_back(node2);
//		list[node2].push_back(node1);
//	}
//	for (int i = 1; i <= num1; i++) {
//		sort(list[i].begin(), list[i].end());
//	}
//	DFS(start_number);
//	cout << endl;
//	memset(visit, 0, sizeof(visit));
//	BFS(start_number);
//}

////2178번 문제
//int main() {
//	int save[101][101] = { 0 }, visit[101][101] = { 0 };
//	int list_x, list_y, answer = 1;
//	cin >> list_y >> list_x;
//	for (int i = 0; i < list_x; i++) {
//		for (int j = 0; j < list_y; j++) {
//			scanf("%1d", &save[i][j]);
//		}
//	}
//	int dx[] = {-1,1,0,0};
//	int dy[] = { 0,0,-1,1 };
//	queue<pair<int, int>> search;
//	search.push({ 0, 0 });
//	visit[0][0] = 1;
//	while (!search.empty()) {
//		int cy = search.front().first;
//		int cx = search.front().second;
//		search.pop();
//		for (int i = 0; i < 4; i++) {
//			int nx = cx + dx[i];
//			int ny = cy + dy[i];
//			if (visit[ny][nx] == 0 && 0 <= nx && nx < list_x && 0 <= ny && ny < list_y && save[ny][nx] == 1) {
//				visit[ny][nx] = 1;
//
//				answer++;
//				search.push({ ny, nx });
//			}
//		}
//	}
//	cout << answer << endl;
//}

////1512번 문제(BFS)
//int visit[101][101] = { 0 }, answer[101][101] = { 0 };
//int dx[] = {-1,1,0,0};
//int dy[] = { 0,0,-1,1 };
//int main() {
//	int list_size, pos_x, pos_y, save = 1;
//	cin >> list_size;
//	cin >> pos_y >> pos_x;
//	pos_y--; pos_x--;
//	queue<pair<int, int>> search;
//	search.push({ pos_y,pos_x });
//	answer[pos_y][pos_x] = 1;
//	visit[pos_y][pos_x] = 1;
//	while (!search.empty()) {
//		int cur_y=search.front().first;
//		int cur_x = search.front().second;
//		search.pop();
//		for (int i = 0; i < 4; i++)
//		{
//			int ny = cur_y + dy[i];
//			int nx = cur_x + dx[i];
//			if (visit[ny][nx] == 0 && 0 <= nx && nx < list_size && 0 <= ny && ny < list_size)
//			{
//				visit[ny][nx] = 1;
//				answer[ny][nx] = answer[cur_y][cur_x] + 1;
//				search.push({ ny,nx });
//			}
//		}
//	}
//	for (int i = 0; i < list_size; i++) {
//		for (int j = 0; j < list_size; j++) {
//			cout << answer[i][j] << " ";
//		}
//		cout << endl;
//	}
//}

//1512번 문제(반복문)
//int save[101][101] = { 0 };
//int main(void)
//{
//    int num, x, y;
//    cin >> num;
//    cin >> x >> y;
//    save[x][y] = 1;
//    int value = save[x][y];
//    for (int i = x - 1; i >= 1; i--)
//        save[i][y] = ++value;
//    value = save[x][y];
//    for (int i = x + 1; i <= num; i++)
//        save[i][y] = ++value;
//    for (int i = 1; i <= num; i++) {
//        value = save[i][y];
//        for (int j = y - 1; j >= 1; j--)
//            save[i][j] = ++value;
//        value = save[i][y];
//        for (int j = y + 1; j <= num; j++)
//            save[i][j] = ++value;
//    }
//    for (int i = 1; i <= num; i++) {
//        for (int j = 1; j <= num; j++)
//            cout << save[i][j] << " ";
//        cout << endl;
//    }
//}

////4454번 문제
//int num1 = 0, num2 = 0, x, y, a, b, list[101][2] = { 0 };
//int root_x, root_y, cnt[101] = { 0 };
//int visited[101] = { 0 };
//void bfs() {
//	int save[101] = { 0 };
//	int start = 0, end = 0;
//	save[end++] = x;
//	while (start != end) {
//		int val = save[start++];
//		visited[val] = 1;
//		for (int i = 0; i < num2; i++) {
//			if (list[i][0] == val && !visited[list[i][1]]) {
//				save[end++] = list[i][1];
//				cnt[list[i][1]] = cnt[val] + 1;
//			}
//			if (list[i][1] == val && !visited[list[i][0]]) {
//				save[end++] = list[i][0];
//				cnt[list[i][0]] = cnt[val] + 1;
//			}
//		}
//	}
//}
//int main() {
//	cin >> num1;
//	cin >> x >> y;
//	cin >> num2;
//	for (int i = 0; i < num2; i++)
//		cin >> list[i][0] >> list[i][1];
//	bfs();
//	if (cnt[y] == 0)
//		cout << -1 << endl;
//	else
//		cout << cnt[y] << endl;
//	return 0;
//}

//vector<int> v[101];
//int visit[101];
//int computer_cnt;
//int relation;
//int answer;
//void bfs(int virus)
//{
//	queue<int> q;
//	q.push(virus);
//	visit[virus] = 1;
//	while (!q.empty())
//	{
//		int cur_computer=q.front();
//		q.pop();
//		for (int i = 0; i < v[cur_computer].size(); i++)
//		{
//			int next_computer = v[cur_computer][i];
//			if (!visit[next_computer])
//			{
//				q.push(next_computer);
//				visit[next_computer] = 1;
//				answer++;
//			}
//		}
//	}
//}
//int main()
//{
//	cin >> computer_cnt;
//	cin >> relation;
//	for (int i = 0; i < relation; i++)
//	{
//		int com1, com2;
//		cin >> com1 >> com2;
//		v[com1].push_back(com2);
//		v[com2].push_back(com1);
//	}
//	bfs(1);
//	printf("%d", answer);
//}



//int num1, num2, answer = 1;
//vector<int> save[101];
//int visit[101];
//void f(int x) {
//   
//    for (int i = 0; i < save[x].size(); ++i) {
//        int next_computer = save[x][i];
//        if (visit[next_computer] == 1)
//            continue;
//        visit[next_computer] = 1;
//        ++answer;
//        f(next_computer);
//    }
//}
//int main() {
//    cin >> num1;
//    cin >> num2;
//    int a, b;
//    for (int i = 0; i < num2; ++i) {
//        cin >> a >> b;
//        save[a].push_back(b);
//        save[b].push_back(a);
//    }
//    visit[1] = 1;
//    f(1);
//    printf("%d", answer - 1);
//    return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//#pragma warning(disable:4996)
//
//int save[101][101] = { 0 };
//int num1, num2;
//int answer = 0;
//int visit[101] = { 0 };
//void f(int x) {
//    for (int i = 1; i <= num1; ++i) {
//        if (save[x][i] == 0)
//            continue;
//        if (visit[i] == 1)
//            continue;
//        visit[i] = 1;
//        ++answer;
//        f(i);
//    }
//}
//int main() {
//
//    scanf("%d", &num1);
//    scanf("%d", &num2);
//    int a, b;
//    for (int i = 0; i < num2; ++i) {
//        scanf("%d %d", &a, &b);
//        save[a][b] = 1;
//        save[b][a] = 1;
//    }
//    f(1);
//    printf("%d", answer - 1);
//    return 0;
//}
////3016번 문제
//typedef struct student {
//	char name[11];
//	int subject1, subject2, subject3;
//} STUDENT;
//int com1(const STUDENT& a, const STUDENT& b) {x
//	return a.subject1 > b.subject1;
//}
//int main() {
//	STUDENT save[101] = { 0 };
//	int num, save1 = 1, save2 = 1;
//	cin >> num;
//	for (int i = 0; i < num; i++) {
//		cin >> save[i].name >> save[i].subject1 >> save[i].subject2 >> save[i].subject3;
//	}
//	sort(save, save + num, com1);
//	for (int i = 1; i < num; i++) {
//		if (save[0].subject2 < save[i].subject2)
//			save1++;
//		if (save[0].subject3 < save[i].subject3)
//			save2++;
//	}
//	cout << save[0].name << " " << save1 << " " << save2;
//}

////1452번 문제
//int main() {
//	int num, save[100001] = { 0 };
//	cin >> num;
//	for (int i = 0; i < num; i++) {
//		cin >> save[i];
//	}
//	sort(save, save + num);
//	for (int i = 0; i < num; i++) {
//		cout << save[i] << endl;
//	}
//}
//// c++ 라이브러리 stl 이라는 걸 공부
//typedef struct point {
//	int x;
//	int y;
//}point;
//int com(const point &a,const point &b)
//{
//	return a.y < b.y;
//}
//int main()
//{
//	point p[5] = { {1,4}, {5,3},{6,2},{7,1},{2,5} };
//
//	sort(p, p + 5);
//	
//	for (int i = 0; i < 5; i++)
//	{	
//		cout << p[i].x << " " << p[i].y << endl;
//	}
//
//	return 0;
//}

////1806번 문제
//int list[100001];
//int main(void) {
//    int num, limit;
//    cin >> num >> limit;
//    for (int i = 1; i <= num; i++)
//        cin >> list[i];
//    int start = 0, end = 0;
//    int sum = 0, answer = 100000000;
//    while (start <= num)
//    {
//        while (sum < limit && end < num)
//        {
//            sum += list[++end];
//        }
//        
//        if (sum>=limit && answer > end - start)
//                answer = end - start;
//        sum -= list[++start];
//     }
//    if (answer == 100000000)
//        cout << 0;
//    else
//        cout << answer;
//}

////2470번 문제
//int list[100001];
//int main() {
//	int num;
//	cin >> num;
//	for (int i = 0; i < num; i++)
//		cin >> list[i];
//	sort(list, list + num);
//	int answer = 2000000000, answer_1 = list[0], answer_2 = list[num-1];
//	int pos_1 = 0, pos_2 = num - 1;
//	while (pos_1 < pos_2) {
//		if (answer > abs(list[pos_1] + list[pos_2])) {
//			answer = abs(list[pos_1] + list[pos_2]);
//			answer_1 = list[pos_1];
//			answer_2 = list[pos_2];
//		}
//		if (abs(list[pos_1] + list[pos_2 - 1]) > abs(list[pos_1 + 1] + list[pos_2]))
//			pos_1++;
//		else
//			pos_2--;
//	}
//	cout << answer_1 << " " << answer_2;
//}

////25401번 문제
//int arr[501];
//int n;
//int cnt;
//int minimum = 500;
//int main()
//{
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//		cin >> arr[i];
//	for (int i = 1; i <= n - 1; i++)
//	{
//		for (int j = i + 1; j <= n; j++)
//		{
//			int dis = j - i;
//			cnt = 0;
//			int gap= (arr[j] - arr[i]) / dis;
//			if ((arr[j] - arr[i]) % dis != 0)continue;
//			for (int k = 1; k <= n; k++)
//			{
//				if (i == k || k==j)continue;
//				if (arr[i] + (k - i) * gap != arr[k])
//					cnt++;
//
//
//			}
//			if (minimum > cnt)
//				minimum = cnt;
//		}
//	}
//	cout << minimum;
//}

////25400번 문제
//int list[250001];
//int main() {
//	int num, is_contain = 0;
//	cin >> num;
//	for (int i = 0; i < num; i++) {
//		cin >> list[i];
//		if (list[i] == 1)
//			is_contain = 1;
//	}
//	if (!is_contain) {
//		cout << num;
//		return 0;
//	}
//	int temp = 1, answer = 0;
//	for (int i = 0; i < num; i++) {
//		if (temp != list[i])
//			answer++;
//		if (temp == list[i])
//			temp++;
//	}
//	cout << answer;
//}

////25401번 문제
//int main() {
//	int num, list[501] = { 0 };
//	cin >> num;
//	for (int i = 0; i < num; i++)
//		cin >> list[i];
//	int temp = INF;
//	/*for (int i = 0; i < num - 1; i++) {
//		if (temp < list[i] - list[i + 1])
//			temp = list[i] - list[i + 1];
//	}*/
//	for (int i = 0; i < num - 1; i++) {
//		if (temp > list[i] - list[i + 1])
//			temp = list[i] - list[i + 1];
//	}
//	cout << temp;
//}

////21756번 문제
//int main() {
//	int num, temp = 2;
//	cin >> num;
//	if (num == 1) {
//		cout << num;
//		return 0;
//	}
//	while (true) {
//		if (num <= temp) {
//			if (num == temp)
//				cout << temp;
//			else
//				cout << temp / 2;
//			return 0;
//		}
//		temp *= 2;
//	}
//}

//int main() {
//	int a[144];
//	int n = 144;
//	for (int i = 0; i < n; i++) {
//		if (i % 5 == 1 || i % 5 == 2) a[i] = 1;
//		else if (i % 5 == 4) a[i] = 2;
//		else a[i] = 3;
//	}
//	for (int i = 0; i < n; i++) {
//		cout << a[i] << " ";
//	}
//	cout << endl << endl;
//	int b = a[0], m = 1;
//	for (int i = 1; i < n; i++) {
//		cout << i << " " << b << " " << m << endl;
//		if (m == 0) {
//			b = a[i];
//			m = 1;
//		}
//		else {
//			if (b % 2 == 0) {
//				b += a[i];
//				m--;
//			}
//			else {
//				b -= a[i];
//			}
//		}
//	}
//	cout << b;
//}
//int t;
//int node_cnt;
//vector<int> vec[10001];
//int parent[10001];
//int dep[10001];
//void dfs(int cur, int p, int level)
//{
//	parent[cur] = p;
//	dep[cur] = level;
//	for (auto next : vec[cur])
//	{
//		if (!dep[next])
//		{
//			dfs(next, cur, level + 1);
//		}
//	}
//}
//int query(int a, int b)
//{
//	if (dep[a] < dep[b])
//	{
//		int temp = a;
//		a = b;
//		b = temp;
//	}
//	while (dep[a] != dep[b])
//	{
//		a = dep[parent[a]];
//	}
//	while (a != b)
//	{
//		a = dep[parent[a]];
//		b = dep[parent[b]];
//	}
//	return a;
//}
//void init()
//{
//	for (int i = 1; i <= node_cnt; i++)
//	{
//		parent[i] = 0;
//		dep[i] = 0;
//		vec[i].clear();
//	}
//}
//int main()
//{
//	cin >> t;
//	while (t--)
//	{
//		init();
//		
//		cin >> node_cnt;
//		for (int i = 0; i < node_cnt - 1; i++)
//		{
//			int node1, node2;
//			cin >> node1 >> node2;
//			vec[node1].push_back(node2);
//			vec[node2].push_back(node1);
//		}
//		dfs(1, 0, 1);
//		int s, e;
//		cin >> s >> e;
//		cout << query(s, e) << endl;
//
//	}
//}
//30089번 문제
//int main() {
//	char answer[41];
//	int num;
//	cin >> num;
//	for (int i = 0; i < num; i++) {
//		cin >> answer;
//		//cout << answer;
//		for (int j = 1; j <= strlen(answer); j++) {
//			//cout << j << " " << j + strlen(answer) - 1 << " " << strlen(answer) - j;
//			//cout << answer[j] << " " << answer[strlen(answer) - j] << endl;
//			/*if (answer[j] == answer[strlen(answer) - j])
//				answer[j + strlen(answer) - 1] = ' ';
//			else
//				answer[j + strlen(answer) - 1] = answer[strlen(answer) - j];*/
//			//cout << endl;
//		}
//		cout << answer;
//		cout << endl;
//	}
//}

////1012번 문제
//int list[51][51];
//int check[51][51];
//int total_case, num1, num2, locate;
//int dx[4] = { 0, 0, 1, -1 }, dy[4] = { 1, -1, 0, 0 };
//int f(int y, int x) {
//    if (check[y][x] == 1)
//        return 0;
//    check[y][x] = true;
//    for (int i = 0; i < 4; i++) {
//        int nx = x + dx[i];
//        int ny = y + dy[i];
//        if (nx >= 0 && ny >= 0 && nx < num2 && ny < num1 && list[ny][nx])
//            f(ny, nx);
//    }
//    return 1;
//}
//int main(void) {
//    cin >> total_case;
//    for (int i = 0; i < total_case; i++) {
//        cin >> num2 >> num1 >> locate;
//        for (int j = 0; j < locate; j++) {
//            int x = 0, y = 0;
//            cin >> x >> y;
//            list[y][x] = 1;
//        }
//        int answer = 0;
//        for (int j = 0; j < num1; j++) {
//            for (int k = 0; k < num2; k++) {
//                if (list[j][k] == 1 && !check[j][k]) {
//                    if (f(j, k) == 1)
//                        answer++;
//                }
//            }
//        }
//        cout << answer << endl;
//    }
//}

////1644번 문제
//int check[INF + 1];
//int main() {
//	vector<int> list;
//	int num, sum = 0;
//	cin >> num;
//	list.push_back(0); 	
//	for (int i = 2; i < sqrt(INF); i++) {
//		for (int j = 2 * i; j <= INF; j += i)
//			check[j] = 1; 
//	}
//	for (int i = 2; i <= INF; i++) {
//		if (check[i] == 0) {
//			sum += i;
//			list.push_back(sum);
//		}
//	}
//	int answer = 0, left = 0, right = 0;
//	while (left <= right && right < list.size()) {
//		if (list[right] - list[left] > num)
//			left++;
//		else if (list[right] - list[left] < num)
//			right++;
//		else {
//			answer++;
//			right++;
//		}
//	}
//	cout << answer;
//}

////10025번 문제
//int bucket[1000001];
//int main() {
//    int num1, num2, answer = 0;
//    cin >> num1 >> num2;
//    int save1, save2, save3 = 0;
//    for (int i = 0; i < num1; i++) {
//        cin >> save1 >> save2;
//        bucket[save2] = save1;
//    }
//    num2 = 2 * num2 + 1;
//    for (int i = 0; i < 1000001; i++) {
//        if (i >= num2)
//            save3 -= bucket[i - num2];
//        save3 += bucket[i];
//        answer = max(answer, save3);
//    }
//    cout << answer;
//}

////2018번 문제
//int main() {
//    int num, answer = 0;
//    cin >> num;
//    vector<bool> list(num + 1, 0);
//    for (int i = num; i >= 1; i--) {
//        int sum = 0;
//        for (int j = i; j >= 1; j--) {
//            sum += j;
//            if (sum == num) {
//                list[i] = 1;
//                break;
//            }
//            else if (sum > num)
//                break;
//        }
//    }
//    for (int i = 1; i <= num; i++) {
//        if (list[i] == 1)
//            answer++;
//    }
//    cout << answer;
//}

////2003번 문제
//int main() {
//	int list[10001] = { 0 };
//	int num1, num2, temp = 0;
//	int start = 0, end = 0, answer = 0;
//	cin >> num1 >> num2;
//	for (int i = 0; i < num1; i++)
//		cin >> list[i];
//	while (end <= num1) {
//		if (answer < num2) {
//			answer += list[end];
//			end++;
//		}
//		if (answer >= num2) {
//			if (answer == num2)
//				temp++;
//			answer -= list[start];
//			start++;
//		}
//	}
//	cout << temp;
//}

////3273번 문제
//int list[100001];
//int main() {
//	int num, answer = 0, need;
//	cin >> num;
//	for (int i = 0; i < num; i++)
//		cin >> list[i];
//	cin >> need;
//	sort(list, list + num);
//	int pos_1 = 0, pos_2 = num-1;
//	while (pos_1<pos_2) {
//		if (list[pos_1] + list[pos_2] > need)
//		{
//			pos_2--;
//		}
//		else if (list[pos_1] + list[pos_2] < need)
//		{
//			pos_1++;
//		}
//		else {
//			answer++;
//			if (list[pos_1 + 1] + list[pos_2] == need)
//				pos_1++;
//			else if (list[pos_1] + list[pos_2] - 1 == need)
//				pos_2--;
//			else {
//				pos_1++;
//				pos_2--;
//			}
//		}
//	}
//	cout << answer;
//
//}

////3079번 문제
//long long int list[100001];
//int main() {
//	long long int num, people;
//	cin >> num >> people;
//	long long int right = 0;
//	for (long long int i = 0; i < num; i++) {
//		cin >> list[i];
//		if (list[i] * people > right)
//			right = list[i] * people;
//	}
//	long long int left = 1;
//	long long int min = right;
//	while (right >= left) {
//		long long int mid = (left + right) / 2;
//		long long int total = 0;
//		for (long long int i = 0; i < num; i++) {
//			total += (long long int)(mid / list[i]);
//		}
//		if (total >= people) {
//			min = mid;
//			right = mid - 1;
//		}
//		else
//			left = mid + 1;
//	}
//	cout << min;
//}

////2206번
//int arr[1001][1001];
//int visited[1001][10001][2]; // 행, 열, 상태
//int answer=-1;
//int dx[] = { -1,1,0,0 };
//int dy[] = { 0,0,-1,1 };
//typedef struct node {
//	int row; // 행
//	int col; // 열 
//	int flag; // 벽 유무
//}Node;
//queue<Node> q;
//int n, m;
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//		{
//			scanf("%1d", &arr[i][j]);
//		}
//	}
//	visited[1][1][0] = visited[1][1][1] = 1;
//	q.push({ 1,1,0 });
//	while (!q.empty())
//	{
//		int crow = q.front().row;
//		int ccol = q.front().col;
//		int wall = q.front().flag;
//		if (crow == n && ccol == m) {
//			answer = visited[crow][ccol][wall];
//			break;
//		}
//		q.pop();
//		for (int i = 0; i < 4; i++)
//		{
//			int nrow = crow + dx[i];
//			int ncol = ccol + dy[i];
//			if (1 <= nrow && nrow <= n && 1 <= ncol && ncol <= m)
//			{
//				if (arr[nrow][ncol] == 0 && visited[nrow][ncol][wall] == 0)
//				{
//					visited[nrow][ncol][wall] = visited[crow][ccol][wall] + 1;
//					q.push({ nrow,ncol,wall });
//				}
//				if (arr[nrow][ncol] == 1 && wall == 0 && visited[nrow][ncol][wall] == 0)
//				{
//					visited[nrow][ncol][wall + 1] = visited[crow][ccol][wall] + 1;
//					q.push({ nrow,ncol,wall + 1 });
//				}
//			}
//		}
//	}
//	cout << answer;
//}

////2667번 문제
//int num, temp = 0;
//string list[26];
//int visit[26][26];
//int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };
//vector<int> result;
//queue<pair<int, int>> q;
//void f(int x, int y) {
//    q.push({ x,y });
//    visit[x][y] = true;
//    temp++;
//    while (!q.empty()) {
//        int a = q.front().first;
//        int b = q.front().second;
//        q.pop();
//        for (int i = 0; i < 4; i++) {
//            int nx = a + dx[i];
//            int ny = b + dy[i];
//            if (0 <= nx && 0 <= ny && nx < num && ny < num && visit[nx][ny] == 0 && list[nx][ny] == '1') {
//                q.push({ nx,ny });
//                visit[nx][ny] = true;
//                temp++;
//            }
//        }
//    }
//}
//
//int main() {
//    cin >> num;
//    for (int i = 0; i < num; i++)
//        cin >> list[i];
//    for (int i = 0; i < num; i++) {
//        for (int j = 0; j < num; j++) {
//            if (list[i][j] == '1' && visit[i][j] == 0) {
//                temp = 0;
//                f(i, j);
//                result.push_back(temp);
//            }
//        }
//    }
//    sort(result.begin(), result.end());
//    cout << result.size() << endl;
//    for (int i = 0; i < result.size(); i++)
//        cout << result[i] << endl;
//}

////7576번 문제
//struct tomato {
//    int y, x;
//};
//int dx[4] = { 0, 0, -1, 1 };
//int dy[4] = { -1, 1, 0, 0 };
//int box[1001][1001], num1, num2;
//queue<tomato> q;
//bool check(int ny, int nx) {
//    return (0 <= ny && ny < num2 && 0 <= nx && nx < num1);
//}
//void f() {
//    while (!q.empty()) {
//        int y = q.front().y;
//        int x = q.front().x;
//        q.pop();
//        for (int i = 0; i < 4; i++) {
//            int ny = y + dy[i];
//            int nx = x + dx[i];
//            if (check(ny, nx) == 1 && box[ny][nx] == 0) {
//                box[ny][nx] = box[y][x] + 1;
//                q.push({ ny, nx });
//            }
//        }
//    }
//}
//int main() {
//    cin >> num1 >> num2;
//    for (int i = 0; i < num2; i++) {
//        for (int j = 0; j < num1; j++) {
//            cin >> box[i][j];
//            if (box[i][j] == 1)
//                q.push({ i, j });
//        }
//    }
//    f();
//    int max = 0;
//    for (int i = 0; i < num2; i++) {
//        for (int j = 0; j < num1; j++) {
//            if (box[i][j] == 0) {
//                cout << -1 << "\n";
//                return 0;
//            }
//            if (max < box[i][j])
//                max = box[i][j];
//        }
//    }
//    cout << max - 1 << "\n";
//}

////2110번 문제
//int list[200001];
//int main() {
//	int num, router;
//	int answer = 0;
//	cin >> num >> router;
//	for (int i = 0; i < num; i++) {
//		cin >> list[i];
//		
//	}
//	sort(list, list + num);
//	int left = 1;
//	int right = list[num - 1] - list[0];
//	while (left <= right) {
//		
//		int prev = list[0];
//		int installed = 1;
//		int mid = (left + right) / 2;
//		for (int i = 1; i < num; i++)
//		{
//			if (list[i]-prev >= mid)
//			{
//				prev = list[i];
//				installed++;
//			}
//		}
//		if (installed >= router)
//		{
//			answer = mid;
//			left = mid + 1;
//		}
//		else {
//			right = mid - 1;
//		}
//
//	}
//	cout << answer;
//}

////2805번 문제
//int tree[1000001];
//int main() {
//	int num, need;
//	cin >> num >> need;
//	int right = 0;
//	for (int i = 0; i < num; i++) {
//		cin >> tree[i];
//		if (tree[i] > right)
//			right = tree[i];
//	}
//	int left = 0;
//	int max = 0;
//	while (left <= right) {
//		long long int total = 0;
//		int mid = (left + right) / 2;
//		for (int i = 0; i < num; i++) {
//			if (tree[i]-mid >0)
//				total += tree[i] - mid;
//		}
//		if (total >= need) {
//			max = mid;
//			left = mid + 1;
//		}
//		else
//			right = mid - 1;
//	}
//	cout << max;
//}

////10816번 문제
//int f_lower(int* arr, int target, int size) {
//    int mid, start, end;
//    start = 0, end = size - 1;
//    while (end > start) {
//        mid = (start + end) / 2;
//        if (arr[mid] >= target)
//            end = mid;
//        else start = mid + 1;
//    }
//    return end;
//}
//int f_upper(int* arr, int target, int size) {
//    int mid, start, end;
//    start = 0, end = size - 1;
//    while (end > start) {
//        mid = (start + end) / 2;
//        if (arr[mid] > target)
//            end = mid;
//        else start = mid + 1;
//    }
//    return end;
//}
//int input[500001];
//int list[500001];
//int result[500001];
//int main(void)
//{
//    int num1, num2, temp, target;
//    cin >> num1;
//    for (int i = 0; i < num1; i++)
//        cin >> input[i];
//    sort(input, input + num1);
//    cin >> num2;
//    for (int i = 0; i < num2; i++) {
//        cin >> list[i];
//        result[i] = 0;
//    }
//    int lower, upper;
//    for (int i = 0; i < num2; i++) {
//        lower = f_lower(input, list[i], num1);
//        upper = f_upper(input, list[i], num1);
//        if (upper == num1 - 1 && input[num1 - 1] == list[i])
//            upper++;
//        result[i] = upper - lower;
//    }
//    for (int i = 0; i < num2; i++)
//        cout << result[i] << " ";
//}

////2805번 문제
//long long int list[1000001];
//int main() {
//	long long int num, need, max = -1;
//	cin >> num >> need;
//	for (int i = 0; i < num; i++) {
//		cin >> list[i];
//		if (list[i] > max)
//			max = list[i];
//	}
//	long long int left = 0;
//	long long int right = max;
//	long long int ans = 0;
//	while (left <= right) {
//		int save = 0;
//		long long int mid = (left + right) / 2;
//		for (int i = 0; i < num; i++)
//		{
//			if(list[i]>=mid)
//				save += list[i] - mid;
//		}
//			
//		if (save >= need) {
//			left = mid + 1;
//			ans = mid;
//		}
//		else
//			right = mid - 1;
//	}
//	cout << ans;
//}

////11053번 문제
//int n;
//int datas[10001];
//int dp[10001];
//int ans;
//int main()
//{
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//		cin >> datas[i];
//	for (int i = 1; i <= n; i++)
//	{
//		dp[i] = 1;
//		for (int j = 1; j < i; j++)
//		{
//			if (datas[j] < datas[i] && dp[i] < dp[j] + 1)
//			{
//				dp[i] = dp[j] + 1;
//			}
//		}
//		if (dp[i] > ans)
//			ans = dp[i];
//	}
//		cout << ans;
//}

////10844번 문제
//long long int dp[100][10];
//int main()
//{
//	int n;
//	cin >> n;
//	for (int i = 1; i < 10; i++)
//	{
//		dp[1][i] = 1;
//	}
//	for (int i = 2; i <= n; i++)
//	{
//		for (int j = 0; j < 10; j++)
//		{
//			if (j == 0)
//				dp[i][j] = dp[i - 1][j+1];
//			else if (j == 9)
//			{
//				dp[i][j] = dp[i - 1][j - 1];
//			}
//			else {
//				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1])%1000000000;
//			}
//		}
//	}
//	long long int sum = 0;
//	for (int i = 0; i < 10; i++)
//	{
//		sum += dp[n][i] ;
//	}
//	cout << sum;
//}

//int num;
//string s;
//int res;
//int fal(int left, int right,int cnt)
//{
//	if (cnt > 2)return 2;
//	if (left < right)
//	{
//		if (s[left] == s[right])
//		{
//			return fal(left + 1, right - 1,cnt);
//		}
//		else {
//			return min(fal(left + 1, right,cnt+1), fal(left, right - 1,cnt+1));
//		}
//
//	}
//	return cnt;
//}
//int main()
//{
//	cin >> num;
//	while (num--)
//	{
//		cin >> s;
//		cout << fal(0, s.length() - 1,0) << endl;;
//	}
//}



//17609번 문제
//int main() {
//	int num;
//	cin >> num;
//	for (int i = 0; i < num; i++) {
//		string input;
//		cin >> input;
//		int check = 1;
//		for (int j = 0; j < input.length(); j++) {
//			if (input[i] != input[input.length() - 1 - i]) {
//				check = 0;
//				break;
//			}
//		}
//		if (check == 1)
//			cout << 0 << endl;
//		else
//			cout << 2 << endl;
//	}
//
//}

////14916번 문제
//int main() {
//    int num;
//    cin >> num;
//    int dp[100001] = { 0 };
//    dp[0] = -1; dp[1] = -1; dp[2] = 1; dp[3] = -1;
//    dp[4] =  2; dp[5] =  1; dp[6] = 3; dp[7] =  2; dp[8] = 4;
//    for (int i = 9; i <= num; i++) {
//        dp[i] = dp[i - 5] + 1; 
//    }
//    cout << dp[num];
//}

////9655번 문제
//int main() {
//	int num, dp[1001] = { 0 };
//	cin >> num;
//	dp[0] = 0;
//	dp[1] = 1;
//	dp[2] = 2;
//	for (int i = 3; i <= num; i++)
//		dp[i] = min(dp[i - 1] + 1, dp[i - 3] + 1);
//	if (dp[num] % 2 == 1)
//		cout << "SK";
//	else
//		cout << "CY";
//}

////9095번 문제
//int main() {
//	int dp[12] = { 1, 2, 4 }, num;
//	cin >> num;
//	for (int i = 3; i < 11; i++)
//		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
//	for (int i = 0; i < num; i++) {
//		int input;
//		cin >> input;
//		cout << dp[input - 1] << endl;
//	}
//}

////4019번 문제
//int dp[10001], list[10001];
//int main() {
//	int num;
//	cin >> num;
//	for (int i = 1; i <= num; i++)
//		cin >> list[i];
//	if (num == 0)
//		cout << 0;
//	else if (num == 1)
//		cout << list[1];
//	else if (num == 2)
//		cout << list[1] + list[2];
//	else {
//		dp[1] = list[1];
//		dp[2] = list[1] + list[2];
//		dp[3] = max(list[3] + dp[1], list[2] + list[3]);
//		for (int i = 4; i <= num; i++)
//		{
//			dp[i] = max(dp[i - 1], max(dp[i - 3] + list[i - 1] + list[i], dp[i - 2] + list[i]));
//		}
//		cout << dp[num];
//	}
//}

////9461번 문제
//int main() {
//	long long int num, dp[101] = { 0 };
//	cin >> num;
//	dp[1] = 1; dp[2] = 1; dp[3] = 1; dp[4] = 2; dp[5] = 2;
//	for (int i = 6; i <= 100; i++) {
//		dp[i] = dp[i - 1] + dp[i - 5];
//	}
//	for (int i = 0; i < num; i++) {
//		long long int input;
//		cin >> input;
//		cout << dp[input] << endl;
//	}
//}

////1463번 문제
//int dp[10000001], list[10000001];
//int main() {
//	int num;
//	cin >> num;
//	for (int i = 1; i <= num; i++) {
//		list[i] = i;
//	}
//	dp[1] = 0;
//	dp[2] = 1;
//	for (int i = 3; i <= num; i++)
//	{
//		dp[i] = INF;
//	}
//	for (int i = 3; i <= num; i++) {
//		if (i % 3 == 0)
//			dp[i] = min(dp[i / 3] + 1, dp[i]);
//		if (i % 2 == 0)
//			dp[i] = min(dp[i / 2] + 1,dp[i]);
//		dp[i] = min(dp[i],dp[i - 1] + 1);
//		
//	}
//	cout << dp[num];
//}

////2579번 문제
//int main() {
//	int dp[301] = { 0 }, list[301] = { 0 }, num;
//	cin >> num;
//	for (int i = 1; i <= num; i++)
//		cin >> list[i];
//	dp[1] = list[1];
//	dp[2] = max(dp[1] + list[2], list[2]);
//	for (int i = 3; i <= num; i++) {
//		dp[i] = max(dp[i - 2] + list[i], dp[i - 3] + list[i - 1] + list[i]);
//	}
//	cout << dp[num];
//}

////1862번 문제
//int main() {
//    int num, list[51] = { 0 };
//    cin >> num;
//    for (int i = 0, save; i < num; i++) {
//        cin >> save;
//        list[save]++;
//    }
//    for (int i = 50; i >= 0; i--)
//        if (list[i] == i) {
//            cout << i;
//            return 0;
//        }
//    cout << -1;
//}

////1932번 문제
//int list[501][501];
//int main() {
//	int num;
//	cin >> num;
//	for (int i = 0; i < num; i++) {
//		for (int j = 0; j < i + 1; j++)
//			cin >> list[i][j];
//	}
//	for (int i = num - 1; i >= 1; i--)
//		for (int j = 0; j < i; j++)
//			list[i - 1][j] += max(list[i][j], list[i][j + 1]);
//	cout << list[0][0];
//}

////1912번 문제
//int list[100001], dp[100001];
//int main() {
//	int num, answer = -1001;
//	cin >> num;
//	for (int i = 0; i < num; i++)
//		cin >> list[i];
//	for (int i = 0; i < num; i++) {
//		dp[i] = max(list[i], list[i] + dp[i - 1]);
//		answer = max(answer, dp[i]);
//	}
//	cout << answer;
//}

//int dp[41] = { 0 };
//int re;
//int f(int num) {
//	if (num == 1)
//		return 0;
//	if (num == 2)
//		return 1;
//	re++;
//	if (dp[num] != 0)
//		return dp[num];
//	return	dp[num] = f(num - 1) + f(num - 2);
//}
//int main() {
//	int num;
//	cin >> num;
//	f(num);
//	cout << re;
//
//}

////24416번 문제
//int dp[41] = { 0 }, f1_repeat = 0, f2_repeat = 0;
//int f1(int num) {
//	if (num == 1)
//		return 0;
//	if (num == 2)
//		return 1;
//	f1_repeat++;
//	return f1(num - 1) + f1(num - 2);
//}
//void f2(int num) {
//	for (int i = 3; i <= num; i++) {
//		dp[i] = dp[i - 1] + dp[i - 2];
//		f2_repeat++;
//	}
//}
//int main() {
//	int num;
//	cin >> num;
//	f1(num);
//	dp[1] = 0;
//	dp[2] = 1;
//	f2(num);
//	cout << f1_repeat + 1 << " " << f2_repeat;
//}

////10870번 문제
//long long int f(long long int num) {
//	if (num == 1)
//		return 0;
//	if (num == 2)
//		return 1;
//	return f(num - 1) + f(num - 2);
//}
//int main() {
//	long long int num;
//	cin >> num;
//	cout << f(num + 1);
//}

////27433번 문제-2
//int main() {
//	long long int num, answer = 1;
//	cin >> num;
//	for (long long int i = 1; i <= num; i++)
//		answer *= i;
//	cout << answer;
//}

////1541번 문제
//int main() {
//    string input;
//    cin >> input;
//    int result = 0;
//    string num;
//    int minus = 0;
//    for (int i = 0; i <= input.size(); i++) {
//        if (input[i] == '-' || input[i] == '+' || i == input.size()) {
//            if (minus == 1) {
//                result -= stoi(num);
//                num = "";
//            }
//            else {
//                result += stoi(num);
//                num = "";
//            }
//        }
//        else
//            num += input[i];
//        if (input[i] == '-')
//            minus = true;
//    }
//    cout << result;
//}

////2485번 문제
//int tree[100001] = { 0 };
//int tree_distance[100001] = { 0 };
//int GCD(int num1, int num2) {
//	if (num2 == 0)
//		return num1;
//	else
//		return GCD(num2, num1 % num2);
//}
//int main()
//{
//	int num, count = 0;
//	cin >> num;
//	for (int i = 1; i <= num; i++)
//		cin >> tree[i];
//	for (int i = 1; i < num; i++)
//		tree_distance[i] = tree[i + 1] - tree[i];
//	int gcd_of_distance = tree[2] - tree[1];
//	for (int i = 1; i < num; i++)
//		gcd_of_distance = GCD(gcd_of_distance, tree_distance[i]);
//	for (int i = 1; i < num; i++)
//		count = count + (tree_distance[i] / gcd_of_distance) - 1;
//	cout << count;
//}

////11399번 문제
//int list[1001] = { 0 };
//int main() {
//	int num;
//	cin >> num;
//	for (int i = 0; i < num; i++)
//		cin >> list[i];
//	sort(list, list + num);
//	int answer = 0;
//	for (int i = 0; i < num; i++) {
//		int temp = 0;
//		for (int j = 0; j <= i; j++) {
//			temp += list[j];
//		}
//		answer += temp;
//	}
//	cout << answer;
//}

////1929번 문제
//int list[1000000];
//int main() {
//	int num1, num2;
//	cin >> num1 >> num2;
//	for (int i = 2; i <= num2; i++)
//	{
//		list[i] = i;
//	}
//	for (int i = 2; i <= num2; i++) {
//		if (list[i] != 0) {
//			for (int j = i + i; j <= num2; j += i)
//				list[j] = 0;
//		}
//	}
//	for (int i = num1; i <= num2; i++) {
//		if (list[i])
//			cout << i << endl;
//	}
//}

////18870번 문제
//typedef struct value {
//	int a, b, c;
//} VALUE;
//VALUE list[1000001];
//bool compare_1(VALUE a, VALUE b) {
//	return a.a < b.a;
//}
//bool compare_2(VALUE a, VALUE b) {
//	return a.b < b.b;
//}
//int main() {
//	int num;
//	cin >> num;
//	for (int i = 0; i < num; i++) {
//		cin >> list[i].a;
//		list[i].b = i + 1;
//	}
//	sort(list, list + num, compare_1);
//	for (int i = 0; i < num; i++) {
//		if (i != 0) {
//			if (list[i].a == list[i - 1].a) {
//				list[i].c = list[i - 1].c;
//			}
//			else {
//				list[i].c = list[i - 1].c + 1;
//			}
//		}
//		else
//			list[i].c = 0;
//	}
//	sort(list, list + num, compare_2);
//	for (int i = 0; i < num; i++) {
//		cout << list[i].c << " ";
//	}
//}

////11650번 문제
//typedef struct point {
//	int x;
//	int y;
//} POINT;
//POINT list[100001] = { 0 };
//bool compare(POINT a, POINT b) {
//	if (a.x < b.x)
//		return 1;
//	else if (a.x == b.x)
//	{
//		if (a.y < b.y)
//		{
//			return 1;
//		}
//	}
//	return 0;
//}
//int main() {
//	int num;
//	cin >> num;
//	for (int i = 0; i < num; i++)
//		cin >> list[i].x >> list[i].y;
//	sort(list, list + num, compare);
//	for (int i = 0; i < num; i++)
//		cout << list[i].x << " " << list[i].y << endl;
//}

////2839번 문제
//int main() {
//	int num, answer = 0;
//	cin >> num;
//	answer = num / 5;
//	for (int i = 0; i <= num; i += 3) {
//		for (int j = 0; j <= num; j += 5) {
//			if (i + j == num) {
//				cout << j / 5 + i / 3;
//				return 0;
//			}
//		}
//	}
//	cout << -1;
//}

////2139번 문제
//int main() {
//	int input1, input2, input3, month[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 };
//	while (true) {
//		cin >> input1 >> input2 >> input3;
//		if (input1 == 0 && input2 == 0 && input3 == 0)
//			return 0;
//		int checkyear = 0, answer = 0;
//		if (input3 % 4 == 0 && (input3 % 100 != 0) || input3 % 400 == 0)
//			checkyear = 1;
//		if (checkyear == 1 && input2 > 2)
//			++answer;
//		for (int i = 0; i < input2; ++i)
//			answer += month[i];
//		answer += input1;
//		cout << answer << endl;
//
//	}
//}

////1964번 문제
//int main() {
//	long long int input;
//	cin >> input;
//	long long int save = (1 + 4 * input + (3 * input * (input - 1)) / 2);
//	cout << save % 45678;
//}

////1075번 문제
//int main() {
//	int num1, num2, answer = 0;
//	cin >> num1;
//	cin >> num2;
//	num1 /= 100;
//	num1 *= 100;
//	while ((num1 + answer) % num2 != 0 && answer < 100)
//		answer++;
//	printf("%02d", answer);
//}

////4673번 문제
//int check[10001] = { 0 };
//int main() {
//	for (int i = 0; i < 10001; i++) {
//		int num = i;
//		int save = num;
//		while (save > 0) {
//			int temp = save % 10;
//			num += temp;
//			save /= 10;
//		}
//		check[num] = 1;
//	}
//	for (int i = 0; i < 10001; i++) {
//		if (check[i] == 0)
//			cout << i << endl;
//	}
//}

////13241번 문제
//int main() {
//	long long int num1, num2, save1, save2;
//	cin >> num1 >> num2;
//	long long int res = num1 * num2;
//	if (num1 < num2)
//	{
//		long long int t = num1;
//		num1 = num2;
//		num2 = t;
//	}
//	while (true) {
//		if (num2 == 0) {
//			break;
//		}
//		int t = num1%num2;
//		num1 = num2;
//		num2 = t;
//	}
//	cout << res / num1;
//}

////14425번 문제
//int main() {
//	string input1[10001];
//	string input2[10001];
//	int input1_num, input2_num, answer = 0;
//	cin >> input1_num >> input2_num;
//	for (int i = 0; i < input1_num; i++)
//		cin >> input1[i];
//	for (int i = 0; i < input2_num; i++)
//		cin >> input2[i];
//	sort(input1, input1 + input1_num);
//
//	for (int i = 0; i < input2_num; i++) {
//		int left = 0;
//		int right = input1_num - 1;
//		while (left <= right)
//		{
//			int mid = (left + right) / 2;
//			if (input2[i].compare(input1[mid])==0)
//			{
//				answer++;
//				break;
//			}
//			else if (input2[i].compare(input1[mid]) > 0)
//			{
//				left = mid + 1;
//			}
//			else {
//				right = mid - 1;
//			}
//		}
//	}
//	cout << answer;
//}

////10815번 문제
//int card[500001];
//int input[500001];
//int main() {
//	int card_num, input_num;
//	cin >> card_num;
//	for (int i = 0; i < card_num; i++) {
//		cin >> card[i];
//	}
//	cin >> input_num;
//	for (int i = 0; i < input_num; i++) {
//		cin >> input[i];
//	}
//	sort(card, card + card_num);
//	for (int i = 0; i < input_num; i++) {
//		int check = 0;
//		int left = 0;
//		int right = card_num - 1;
//		while(left<=right)
//		{
//			int mid = (left + right) / 2;
//			if (input[i] == card[mid])
//			{
//				check = 1;
//				break;
//			}
//			else if (input[i] > card[mid])
//			{
//				left = mid + 1;
//			}
//			else {
//				right = mid - 1;
//			}
//		}
//		if (check == 1)
//			cout << "1" << " ";
//		else
//			cout << "0" << " ";
//	}
//}

////1181번 문제
//string list[20001];
//bool compare(const string a, const string b) {
//	if (a.length() == b.length())
//		return a < b;
//	else {
//		return a.length() < b.length();
//	}
//}
//int main() {
//	int num;
//	cin >> num;
//	for (int i = 0; i < num; i++)
//		cin >> list[i];
//	sort(list, list + num, compare);
//	for (int i = 0; i < num; i++) {
//		if (list != 0 && list[i] == list[i - 1])
//			continue;
//		cout << list[i] << endl;
//	}
//}

////15894번 문제
//int main() {
//	unsigned long long int num;
//	cin >> num;
//	cout << num * 4;
//}

////9086번 문제
//int main() {
//	int num;
//	cin >> num;
//	for (int i = 0; i < num; i++) {
//		string input;
//		cin >> input;
//		cout << input[0] << input[input.length() - 1] << endl;
//	}
//}

////1152번 문제
//char list[1000001];
//int main() {
//	int answer = 0, status = 0;
//	scanf("%[^\n]s", list);
//	for (int i = 0; i < strlen(list); i++) {
//		if (list[i] != ' ' && status == 0) {
//			status = 1;
//			answer++;
//		}
//		if (list[i] == ' ')
//			status = 0;
//		
//	}
//	cout << answer;
//}

////1931번 문제
//typedef struct c {
//	int start;
//	int end;
//
//}CLASS;
//CLASS cs[100001];
//int com(const CLASS& a, const CLASS& b)
//{
//	if (a.end == b.end)
//	{
//		return a.start < b.start;
//	}
//	return a.end < b.end;
//}
//int main() {
//	int input;
//	cin >> input;
//	for (int i = 0; i < input; i++)
//		cin >> cs[i].start >> cs[i].end;
//	sort(cs, cs + input, com);
//	int std_end = cs[0].end;
//	int cnt = 1;
//	for (int i = 1; i < input; i++) {
//		if (std_end <= cs[i].start)
//		{
//			std_end = cs[i].end;
//			cnt++;
//		}
//	}
//	cout << cnt;
//}

////1389번 문제
//// 플로이드 와셜 알고리즘
//int V, E;
//int arr[101][101];  // 첫번째 배열은 출발,두번째 배열은 도착
//int dist[101][101];
//vector<int> v[101];
//void init()
//{
//	for (int i = 1; i <= V; i++)
//	{
//		for (int j = 1; j <= V; j++)
//		{
//			dist[i][j] = INF;
//		}
//	}
//}
//int main()
//{
//	cin >> V >> E;
//	init();
//	for (int i = 0; i < E; i++)
//	{
//		int node1, node2;
//		cin >> node1 >> node2;
//		dist[node1][node2] = 1;
//		dist[node2][node1] = 1;
//	}
//	for (int i = 1; i <= V; i++)
//	{
//		for (int j = 1; j <= V; j++)
//		{
//			for (int k = 1; k <= V; k++)
//			{
//				if (j == k) {
//					dist[j][k] = 0;
//				} else if(dist[j][k] > dist[j][i] + dist[i][k])
//				{
//					dist[j][k] = dist[j][i] + dist[i][k];
//				}
//			}
//		}
//	}
//
//	int min = INF;
//	int minvalue = 0;
//	for (int i = V; i >= 1; i--)
//	{
//		int temp = 0;
//		for (int j = 1; j <= V; j++)
//		{
//			temp += dist[i][j];
//		}
//		if (min >= temp) {
//			min = temp;
//			minvalue = i;
//		}
//	}
//	cout << minvalue << endl;
//}

////2559번 문제
//int list[100001];
//int main() {
//	int N, K, s, e, answer = 0, curr = 0;
//	cin >> N >> K;
//	for (int i = 0; i < N; i++)
//		cin >> list[i];
//	s = 0;
//	e = K - 1;
//	for (int i = s; i <= e; i++) {
//		answer += list[i];
//		curr += list[i];
//	}
//	while (e!= N - 1) {
//		curr -= list[s++];
//		curr += list[++e];
//		if (answer < curr)
//			answer = curr;
//	}
//	cout << answer << endl;
//}

//3215번 문제
//vector<pair<int, int>> list[200001];
//int N, M;
//int dist[200001];
//void DJ(int start, int end) {
//	priority_queue<pair<int, int>> pq;
//	pq.push({ 0, start });
//	dist[start] = 0;
//	while (!pq.empty()) {
//		int curr_weight = -pq.top().first;
//		int curr_node = pq.top().second;
//		pq.pop();
//		for (auto next : list[curr_node]) {
//			int next_weight = next.first;
//			int next_node = next.second;
//			if (dist[next_node] > dist[curr_node] + next_weight) {
//				dist[next_node] = dist[curr_node] + next_weight;
//				pq.push({ -(dist[next_node]), next_node });
//			}
//		}
//	}
//}
//int main() {
//	cin >> N >> M;
//	char node1, node2;
//	int weight;
//	for (int i = 0; i < M; i++) {
//		cin >> node1 >> node2 >> weight;
//		node1 -= 64;
//		node2 -= 64;
//		list[node1].push_back({ weight, node2 });
//		list[node2].push_back({ weight, node1 });
//	}
//	for (int i = 1; i <= N; i++) {
//		dist[i] = INF;
//	}
//	char temp1, temp2;
//	cin >> temp1 >> temp2;
//	DJ(temp1 - 64, temp2 - 64);
//	if (dist[temp2 - 64] == INF)
//		cout << -1 << endl;
//	else
//		cout << dist[temp2 - 64] << endl;
//}

//#define MAX 20001
//vector<pair<int, int> > list[MAX];
//int V, E, S;
//int dist[MAX];
//int visited[MAX];
//void input()
//{
//	int node1, node2, weight;
//	for (int i = 0; i < E; i++)
//	{
//		cin >> node1 >> node2 >> weight;
//		list[node1].push_back({ weight,node2 });
//	}
//}
//void dist_init()
//{
//	for (int i = 1; i <= V; i++)
//	{
//		dist[i] = INF;
//	}
//}
//void DJ(int start)
//{
//	priority_queue<pair<int, int> > pq;
//	pq.push({ 0,start });
//	dist[start] = 0;
//	visited[start] = 1;
//	while (!pq.empty())
//	{
//		int curr_weight = -pq.top().first;
//		int curr_node = pq.top().second;
//		pq.pop();
//		for (auto next : list[curr_node])
//		{
//			int next_weight = next.first;
//			int next_node = next.second;
//			if (visited[next_node])continue;
//			if (dist[next_node] > dist[curr_node] + next_weight)
//			{
//				dist[next_node] = dist[curr_node] + next_weight;
//				pq.push({ -(dist[next_node]), next_node });
//				visited[next_node] = 1;
//			}
//		}
//
//	}
//
//}
//int main() {
//	cin >> V >> E;
//	cin >> S;
//	dist_init();
//	input();
//	DJ(S);
//	for (int i=1;i<=V;i++)
//	{
//		if (dist[i] == INF)
//			cout << "INF" << endl;
//		else
//			cout << dist[i] << endl;
//	}
//}

////28125번 문제
//int main() {
//	int list[51][2] = { 0 };
// 	int N, K;
//	cin >> N >> K;
//	for (int i = 0; i < N; i++) {
//		cin >> list[i][0] >> list[i][1];
//	}
//	int min = 9999999;
//	for (int i = 0; i < N; i++) {
//		for (int j = i; j < N; j++) {
//			for (int k = j; k < N; k++) {
//				for (int z = 0; z < N; z++) {
//					if (z == i || z == j || z == k)
//						continue;
//					int distance = 0;
//					if (k == 1) {
//						distance = abs(list[i][0] + list[z][0]) + abs(list[i][1] + list[z][1]);
//					}
//					else if (k == 2) {
//						int distance1 = abs(list[i][0] + list[z][0]) + abs(list[i][1] + list[z][1]);
//						int distance2 = abs(list[j][0] + list[z][0]) + abs(list[j][1] + list[z][1]);
//						if (distance1 > distance2)
//							distance = distance2;
//						else
//							distance = distance1;
//					}
//					else if (k == 3) {
//						int distance1 = abs(list[i][0] + list[z][0]) + abs(list[i][1] + list[z][1]);
//						int distance2 = abs(list[j][0] + list[z][0]) + abs(list[j][1] + list[z][1]);
//						int distance3 = abs(list[k][0] + list[z][0]) + abs(list[k][1] + list[z][1]);
//						if (distance1 >= distance2 && distance1 >= distance3)
//							distance = distance1;
//						else if (distance2 >= distance1 && distance2 >= distance3)
//							distance = distance2;
//						else
//							distance = distance3;
//					}
//					if (min > distance)
//						min = distance;
//				}
//			}
//		}
//	}
//	cout << min << endl;
//}

////28124번 문제
//int main() {
//	int N, K, P, answer = 0;
//	cin >> N >> K >> P;
//	for (int i = 0; i < N; i++) {
//		int out = 0;
//		for (int j = 0; j < K; j++) {
//			int temp;
//			cin >> temp;
//			if (temp == 0)
//				out++;
//		}
//		if (out < P)
//			answer++;
//	}
//	cout << answer << endl;
//}

////17619번 문제
//int N, K;
//int table[100001];
//void init() {
//	for (int i = 1; i <= N; i++)
//		table[i] = i;
//}
//typedef struct NODE {
//	int x1;
//	int x2;
//	int number;
//} Node;
//int getParent(int node) {
//	if (node == table[node])
//		return node;
//	return table[node] = getParent(table[node]);
//}
//void Union(int node1, int node2) {
//	node1 = getParent(node1);
//	node2 = getParent(node2);
//	if (node1 > node2)
//		table[node1] = node2;
//	else
//		table[node2] = node1;
//}
//int compare(const Node a, Node b) {
//	return a.x1 < b.x1;
//}
//vector<Node> vec;
//int main() {
//	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//	cin >> N >> K;
//	for (int i = 1; i <= N; i++) {
//		int x1, x2, h;
//		cin >> x1 >> x2 >> h;
//		vec.push_back({ x1, x2, i });
//	}
//	init();
//	sort(vec.begin(), vec.end(), compare);
//	int s1, s2, no_Number;
//	s1 = vec[0].x1;
//	s2 = vec[0].x2;
//	no_Number = vec[0].number;
//	for (int i = 1; i < vec.size(); i++) {
//		if (s2 >= vec[i].x1) {
//			Union(no_Number, vec[i].number);
//			if (s2 < vec[i].x2) {
//				s2 = vec[i].x2;
//			}
//		}
//		else {
//			s1 = vec[i].x1;
//			s2 = vec[i].x2;
//			no_Number = vec[i].number;
//		}
//	}
//	for (int i = 1; i <= K; i++) {
//		int no1, no2;
//		cin >> no1 >> no2;
//		if (getParent(no1) == getParent(no2))
//			cout << 1 << endl;
//		else
//			cout << 0 << endl;
//	}
//}

//21758번 문제
//long long list[100001], sum[100001];
//int main()
//{
//	int num;
//	cin >> num;
//	for (int i = 1; i <= num; i++) {
//		cin >> list[i];
//		sum[i] = list[i] + sum[i - 1];
//	}
//	long long max = 0, temp;
//	for (int i = 2; i < num; i++) {
//		temp = sum[num] - list[1] - list[i] + sum[num] - sum[i];
//		if (temp > max)
//			max = temp;
//	}
//	for (int i = 2; i < num; i++) {
//		temp = sum[num] - list[num] - list[i] + sum[i - 1];
//		if (temp > max)
//			max = temp;
//	}
//	for (int i = 2; i < num; i++) {
//		temp = sum[i] - list[1] + sum[num] - sum[i - 1] - list[num];
//		if (temp > max)
//			max = temp;
//	}
//	cout << max;
//}

//25379번 문제
//int list[1000001] = { 0 };
//int main() {
//	int input;
//	cin >> input;
//	for (int i = 0; i < input; i++) {
//		cin >> list[i];
//		list[i] %= 2;
//	}
//	long long int count = 0, answer1 = 0, answer2 = 0;
//	for (int i = 0; i < input; i++) {
//		if (list[i] == 1) {
//			count++;
//		}
//		else
//			answer1 += count;
//	}
//	count = 0;
//	for (int i = input - 1; i >= 0; i--) {
//		if (list[i] == 1)
//			count++;
//		else
//			answer2 += count;
//	}
//	if (answer1 > answer2)
//		cout << answer2;
//	else
//		cout << answer1;
//}

////19941번 문제
//int main() {
//	int num1, num2;
//	cin >> num1 >> num2;
//	vector<char> list(num1);
//	for (int i = 0; i < num1; i++)
//		cin >> list[i];
//	int count = 0;
//	for (int i = 0; i < num1; i++) {
//		if (list[i] == 'P') {
//			for (int j = i - num2; j <= i + num2; j++) {
//				if (j < 0 || j > num1 - 1)
//					continue;
//				if (list[j] == 'H') {
//					count++;
//					list[j] = 'N';
//					break;
//				}
//			}
//		}
//	}
//	cout << count << '\n';
//}

//25379번 문제
//int list[1000001] = { 0 };
//int len;
//int swap(int *num1, int *num2) {
//	int temp = *num2;
//	*num2 = *num1;
//	*num1 = temp;
//}
//int main() {
//	cin >> len;
//	for (int i = 0; i < len; i++)
//		cin >> list[i];
//	
//}

//17610번 문제

//int n;
//int chu[13];
//int* weight;
//int s;
//
//void f(int idx, int curW)
//{
//	if (curW >= 0)
//		weight[curW] = 1;
//	if (idx >= n)return;
//
//	f(idx + 1, curW + chu[idx]);
//	f(idx + 1, curW);
//	f(idx + 1, curW - chu[idx]);
//
//}
//int main()
//{
//	int answer = 0;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> chu[i];
//		s += chu[i];
//	}
//	weight = (int*)malloc(sizeof(int) * (s+1));
//	for (int i = 0; i <= s; i++)
//		weight[i] = 0;
//	f(0, 0);
//	for (int i = 1; i <= s; i++)
//	{
//		if (weight[i] == 0)
//			answer++;
//	}
//	cout << answer;
//	return 0;
//}

////17608번 문제
//int list[100001] = { 0 };
//int main() {
//	int input, count = 0, max = 0;
//	cin >> input;
//	for (int i = 0; i < input; i++)
//		cin >> list[i];
//	max = input - 1;
//	for (int i = input - 1; i >= 0; i--) {
//		if (list[max] < list[i]) {
//			max = i;
//			count++;
//		}
//	}
//	cout << count + 1;
//}

////17618번 문제
//int input;
//int check(int num) {
//	int stack = 0, temp = num;
//	do {
//		stack += num % 10;
//		num /= 10;
//	} while (num != 0);
//	if (temp % stack == 0)
//		return 1;
//	else
//		return 0;
//}
//int main() {
//	int answer = 0;
//	cin >> input;
//	for (int i = 1; i <= input; i++) {
//		answer += check(i);
//	}
//	cout << answer;
//}

//17614번 문제
//int input;
//int check(int num) {
//	int count = 0;
//	do {
//		if (num % 10 == 3 || num % 10 == 6 || num % 10 == 9)
//			count++;
//		num /= 10;
//	} while (num != 0);
//	return count;
//}
//int main() {
//	int answer = 0;
//	cin >> input;
//	for (int i = 1; i <= input; i++) {
//		answer += check(i);
//	}
//	cout << answer;
//}

////5014번 문제
//int check[1000001] = { 0 };
//int main() {
//	int F, S, G, U, D;
//	cin >> F >> S >> G >> U >> D;
//	queue<int> q;
//	q.push(S);
//	check[S] = 1;
//	while (!q.empty()) {
//		int cur = q.front();
//		q.pop();
//		if (cur == G) {
//			cout << check[G] - 1;
//			return 0;
//		}
//		if (cur + U <= F && check[cur + U] == 0) {
//			check[cur + U] = check[cur] + 1;
//			q.push(cur + U);
//		}
//		if (cur - D >= 1 && check[cur - D] == 0) {
//			check[cur - D] = check[cur] + 1;
//			q.push(cur - D);
//		}
//	}
//	cout << "use the stairs";
//}