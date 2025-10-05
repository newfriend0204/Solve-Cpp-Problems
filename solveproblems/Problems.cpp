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

////1038 b
//int N;
//vector<unsigned long long> results;
//void dfs(unsigned long long num, int degit) {
//	results.push_back(num);
//	for (int i = 0; i < degit; i++) {
//		dfs(num * 10 + i, i);
//	}
//}
//int main() {
//	cin >> N;
//
//	for (int i = 0; i <= 9; i++)
//		dfs(i, i);
//
//	sort(results.begin(), results.end());
//	if (N >= results.size()) {
//		cout << -1;
//		return 0;
//	}
//	cout << results[N];
//	return 0;
//}

////2589 b
//int col, row;
//int dx[] = { 0, 0, -1, 1 }, dy[] = { 1, -1, 0, 0 };
//vector<vector<char>> list(51, vector<char>(51));
//int bfs(int sy, int sx) {
//	vector<vector<int>> visited(51, vector<int>(51, 0));
//	queue<pair<int, int>> q;
//	int best = -1;
//	visited[sy][sx] = 1;
//	q.push({ sy, sx });
//
//	while (!q.empty()) {
//		int y = q.front().first;
//		int x = q.front().second;
//		q.pop();
//
//		for (int i = 0; i < 4; i++) {
//			int ny = y + dy[i];
//			int nx = x + dx[i];
//
//			if (ny < 0 || nx < 0 || ny >= col || nx >= row)
//				continue;
//
//			if (visited[ny][nx] != 0 || list[ny][nx] == 'W')
//				continue;
//
//			visited[ny][nx] = visited[y][x] + 1;
//			best = max(best, visited[y][x]);
//			q.push({ ny, nx });
//		}
//	}
//
//	return best;
//}
//int main() {
//	cin >> col >> row;
//	for (int i = 0; i < col; i++) {
//		for (int j = 0; j < row; j++)
//			cin >> list[i][j];
//	}
//
//	int best = -1;
//	for (int i = 0; i < col; i++) {
//		for (int j = 0; j < row; j++) {
//			if (list[i][j] == 'L')
//				best = max(best, bfs(i, j));
//		}
//	}
//
//	cout << best;
//}

////1759 b
//int L, C;
//vector<char> vowel = { 'a', 'e', 'i', 'o', 'u' };
//vector<char> list;
//void dfs(int idx, string text) {
//	if (text.length() == L) {
//		int isV = 0, isNotV = 0;
//		for (auto a : text) {
//			if (find(vowel.begin(), vowel.end(), a) != vowel.end())
//				isV++;
//			else
//				isNotV++;
//		}
//		if (isV >= 1 && isNotV >= 2)
//			cout << text << "\n";
//		return;
//	}
//
//	for (int i = idx; i < C; i++) {
//		dfs(i + 1, text + list[i]);
//	}
//}
//int main() {
//	cin >> L >> C;
//	for (int i = 0; i < C; i++) {
//		char a;
//		cin >> a;
//		list.push_back(a);
//	}
//
//	sort(list.begin(), list.end());
//	dfs(0, "");
//}

////15686 b
//int N, M;
//vector<int> save;
//int best = 99999999, count = 0;
//vector<pair<int, int>> house;
//vector<pair<int, int>> chicken;
//int AllDist(vector<int> save) {
//	int sum = 0;
//	for (auto [hy, hx] : house) {
//		int a = 99999999;
//		for (int i = 0; i < (int)save.size(); i++) {
//			auto [cy, cx] = chicken[save[i]];
//			int dist = abs(hy - cy) + abs(hx - cx);
//			a = min(a, dist);
//		}
//		sum += a;
//		if (sum >= best)
//			break;
//	}
//	return sum;
//}
//void dfs(int idx, int cnt) {
//	if (cnt == M) {
//		best = min(best, AllDist(save));
//		return;
//	}
//
//	if (idx == (int)chicken.size())
//		return;
//
//	if (cnt + (int)chicken.size() - idx < M)
//		return;
//
//	save.push_back(idx);
//	dfs(idx + 1, cnt + 1);
//	save.pop_back();
//
//	dfs(idx + 1, cnt);
//}
//int main() {
//	cin >> N >> M;
//	for (int i = 0; i < N; i++) {				 
//		for (int j = 0; j < N; j++) {
//			int num;
//			cin >> num;
//			if (num == 1)
//				house.push_back({ i, j });
//			else if (num == 2)
//				chicken.push_back({ i, j });
//		}
//	}
//
//	dfs(0, 0);
//	cout << best;
//}

////2475 b
//int main() {
//	int a, b, c, d, e;
//	cin >> a >> b >> c >> d >> e;
//	cout << (a*a + b*b + c*c + d*d + e*e) % 10;
//}

////15964 b
//int main() {
//	long long a, b;
//	cin >> a >> b;
//	cout << (a + b) * (a - b);
//}

////9086 b
//int main() {
//	int num;
//	cin >> num;
//	for (int i = 0; i < num; i++) {
//		string s;
//		cin >> s;
//		cout << s.front() << s.back() << "\n";
//	}
//}

////11718 b
//int main() {
//	string s;
//	while (getline(cin, s)) {
//		cout << s << "\n";
//	}
//}

////27866 b
//int main() {
//	string s;
//	int num;
//	cin >> s >> num;
//	cout << s[num - 1];
//}

////2754 b
//int main() {
//    string grade;
//    cin >> grade;
//
//    double ans = 0.0;
//
//    if (grade == "A+") 
//       ans = 4.3;
//    else if (grade == "A0")
//        ans = 4.0;
//    else if (grade == "A-")
//        ans = 3.7;
//    else if (grade == "B+")
//        ans = 3.3;
//    else if (grade == "B0")
//        ans = 3.0;
//    else if (grade == "B-")
//        ans = 2.7;
//    else if (grade == "C+")
//        ans = 2.3;
//    else if (grade == "C0")
//        ans = 2.0;
//    else if (grade == "C-")
//        ans = 1.7;
//    else if (grade == "D+")
//        ans = 1.3;
//    else if (grade == "D0")
//        ans = 1.0;
//    else if (grade == "D-")
//        ans = 0.7;
//    else
//        ans = 0.0;
//
//    printf("%.1f", ans);
//    return 0;
//}

////2744 b
//#include<cctype>
//int main() {
//    string s;
//    cin >> s;
//    for (char& c : s) {
//        if (islower(c))
//            c = toupper(c);
//        else
//            c = tolower(c);
//    }
//    cout << s << "\n";
//    return 0;
//}

////2743 b
//int main() {
//    string s;
//    cin >> s;
//    cout << s.size() << '\n';
//    return 0;
//}

////11654 b
//int main() {
//    char c;
//    cin >> c;
//    cout << (int)c << '\n';
//    return 0;
//}

////2738 b
//int main() {
//	int n, m;
//	cin >> n >> m;
//	vector<vector<int>> list1(n, vector<int>(m));
//	vector<vector<int>> list2(n, vector<int>(m));
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cin >> list1[i][j];
//		}
//	}
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cin >> list2[i][j];
//		}
//	}
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cout << list1[i][j] + list2[i][j] << " ";
//		}
//		cout << "\n";
//	}
//}

////5597 b
//int main() {
//	vector<int> list(31);
//	vector<int> ans;
//	for (int i = 1; i <= 28; i++) {
//		int num;
//		cin >> num;
//		list[num] = 1;
//	}
//	for (int i = 1; i <= 30; i++) {
//		if (list[i] != 1)
//			ans.push_back(i);
//	}
//	cout << ans[0] << "\n" << ans[1];
//	return 0;
//}

////10807 b
//int main() {
//	int num;
//	cin >> num;
//	vector<int> list(num);
//	for (int i = 0; i < num; i++)
//		cin >> list[i];
//	int find, ans = 0;
//	cin >> find;
//	for (int i = 0; i < num; i++) {
//		if (list[i] == find)
//			ans++;
//	}
//	cout << ans;
//	return 0;
//}

////10871 b
//int main() {
//	int a, b;
//	cin >> a >> b;
//	vector<int> list(a);
//	for (int i = 0; i < a; i++)
//		cin >> list[i];
//	for (int i = 0; i < a; i++) {
//		if (list[i] < b)
//			cout << list[i] << " ";
//	}
//	return 0;
//}

////15552 b
//int main() {
//	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//	int num;
//	cin >> num;
//	for (int i = 0; i < num; i++) {
//		int a, b;
//		cin >> a >> b;
//		cout << a + b << "\n";
//	}
//	return 0;
//}

////10951 b
//int main() {
//	int a, b;
//	while (cin >> a >> b) {
//		cout << a + b << "\n";
//	}
//}

////2438 b
//int main() {
//	int num;
//	cin >> num;
//	for (int i = 1; i <= num; i++) {
//		for (int j = 0; j < i; j++)
//			cout << "*";
//		cout << "\n";
//	}
//}

////2739 b
//int main() {
//	int num;
//	cin >> num;
//	for (int i = 1; i <= 9; i++) {
//		printf("%d * %d = %d\n", num, i, num * i);
//	}
//}

////10952 b
//int main() {
//	while (1) {
//		int a, b;
//		cin >> a >> b;
//		if (a == 0 && b == 0)
//			return 0;
//		cout << a + b << "\n";
//	}
//}

////10950 b
//int main() {
//	int tc;
//	cin >> tc;
//	for (int i = 0; i < tc; i++) {
//		int a, b;
//		cin >> a >> b;
//		cout << a + b << "\n";
//	}
//}

////10872 b
//int main() {
//	long long num, ans = 1;
//	cin >> num;
//	for (int i = 0; i < num; i++)
//		ans *= i + 1;
//	cout << ans;
//	return 0;
//}

////2741 b
//int main() {
//	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//	int num;
//	cin >> num;
//	for (int i = 0; i < num; i++)
//		cout << i + 1 << "\n";
//	return 0;
//}

////2420 b
//int main() {
//	long long a, b;
//	cin >> a >> b;
//	cout << abs(a - b);
//	return 0;
//}

////2753 b
//int main() {
//	int num;
//	cin >> num;
//	if (num % 4 == 0 && num % 100 != 0)
//		cout << 1;
//	else if (num % 400 == 0)
//		cout << 1;
//	else
//		cout << 0;
//	return 0;
//}

////14681 b
//int main() {
//	int a, b;
//	cin >> a >> b;
//	if (a > 0 && b > 0)
//		cout << 1;
//	if (a < 0 && b > 0)
//		cout << 2;
//	if (a < 0 && b < 0)
//		cout << 3;
//	if (a > 0 && b < 0)
//		cout << 4;
//}

////9498 b
//int main() {
//    int num;
//    cin >> num;
//    if (num >= 90)
//        cout << "A";
//    else if (num >= 80 && num < 90)
//        cout << "B";
//    else if (num >= 70 && num < 80)
//        cout << "C";
//    else if (num >= 60 && num < 70)
//        cout << "D";
//    else
//        cout << "F";
//    return 0;
//}

////1330 b
//int main() {
//	int a, b;
//	cin >> a >> b;
//	if (a > b)
//		cout << ">";
//	else if (a < b)
//		cout << "<";
//	else
//		cout << "==";
//	return 0;
//}

////11382 b
//int main() {
//	long long a, b, c;
//	cin >> a >> b >> c;
//	cout << a + b + c;
//	return 0;
//}

////10869 b
//int main() {
//	int a, b;
//	cin >> a >> b;
//	cout << a + b << endl;
//	cout << a - b << endl;
//	cout << a * b << endl;
//	cout << a / b << endl;
//	cout << a % b << endl;
//	return 0;
//}

////1008 b
//int main() {
//	double a, b;
//	cin >> a >> b;
//	cout.precision(12);
//	cout << a / b;
//	return 0;
//}

////10998 b
//int main() {
//	int a, b;
//	cin >> a >> b;
//	cout << a * b;
//	return 0;
//}

////1001 b
//int main() {
//	int a, b;
//	cin >> a >> b;
//	cout << a - b;
//	return 0;
//}

////1000 b
//int main() {
//	int a, b;
//	cin >> a >> b;
//	cout << a + b;
//	return 0;
//}

////25083 b
//int main() {
//    cout << "         ,r'\"7\n";
//    cout << "r`-_   ,'  ,/\n";
//    cout << " \\. \". L_r'\n";
//    cout << "   `~\\/\n";
//    cout << "      |\n";
//    cout << "      |";
//    return 0;
//}

////10171 b
//int main() {
//    cout << "|\\_/|\n"
//        "|q p|   /}\n"
//        "( 0 )\"\"\"\\\n"
//        "|\"^\"`    |\n"
//        "||_/=\\\\__|";
//    return 0;
//}

////7287 b
//int main() {
//	cout << 2 << "\n" << "new_friend";
//	return 0;
//}

////10699 b
//#include <ctime>
//int main() {
//    time_t t = time(NULL);
//    struct tm now;
//    localtime_r(&t, &now);
//
//    printf("%04d-%02d-%02d",
//        now.tm_year + 1900,
//        now.tm_mon + 1,
//        now.tm_mday);
//    return 0;
//}

////2557 b
//int main() {
//    cout << "Hello World!";
//    return 0;
//}