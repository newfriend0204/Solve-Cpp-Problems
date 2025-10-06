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

////15683 b
//int N, M, answer = 1000000000;
//vector<vector<int>> list;
//int dy[] = { 0, 1, 0, -1 }, dx[] = { 1, 0, -1, 0 };
//struct CCTV {
//	int type, y, x;
//};
//vector<vector<vector<int>>> dirs = {
//	{},
//	{{0},{1},{2},{3}},
//	{{0,2},{1,3}},
//	{{0,1},{1,2},{2,3},{3,0}},
//	{{0,1,2},{1,2,3},{2,3,0},{3,0,1}},
//	{{0,1,2,3}}
//};
//vector<CCTV> cctvs;
//void dfs(int idx, vector<vector<int>> maps) {
//    if (idx == cctvs.size()) {
//        int count = 0;
//        for (int i = 0; i < N; i++) {
//            for (int j = 0; j < M; j++) {
//                if (maps[i][j] == 0)
//                    count++;
//            }
//        }
//        answer = min(answer, count);
//        return;
//    }
//
//    int type = cctvs[idx].type;
//    int y = cctvs[idx].y;
//    int x = cctvs[idx].x;
//
//    for (int i = 0; i < dirs[type].size(); i++) {
//        vector<vector<int>> next = maps;
//        for (int k = 0; k < dirs[type][i].size(); k++) {
//            int d = dirs[type][i][k];
//            int ny = y;
//            int nx = x;
//
//            while (true) {
//                ny += dy[d];
//                nx += dx[d];
//
//                if (ny < 0 || ny >= N || nx < 0 || nx >= M)
//                    break;
//                if (next[ny][nx] == 6)
//                    break;
//                if (next[ny][nx] == 0)
//                    next[ny][nx] = 7;
//            }
//        }
//
//        dfs(idx + 1, next);
//    }
//}
//int main() {
//	cin >> N >> M;
//	list.resize(N, vector<int>(M));
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			cin >> list[i][j];
//			if (list[i][j] != 0 && list[i][j] != 6)
//				cctvs.push_back({ list[i][j], i, j });
//		}
//	}
//	dfs(0, list);
//	cout << answer;
//}

////10974 b
//int main() {
//	int N;
//	vector<int> list;
//	cin >> N;
//	list.resize(N);
//	for (int i = 0; i < N; i++)
//		list[i] = i + 1;
//
//	sort(list.begin(), list.end());
//	do {
//		for (int i = 0; i < list.size(); i++)
//			cout << list[i] << ' ';
//		cout << "\n";
//	} while (next_permutation(list.begin(), list.end()));
//}

////10819 b
//int N, answer = 0;
//vector<int> list;
//int check(vector<int> num) {
//	int sum = 0;
//	for (int i = 0; i < num.size() - 1; i++) {
//		sum += abs(num[i] - num[i + 1]);
//	}
//	return sum;
//}
//int main() {
//	cin >> N;
//	list.resize(N);
//	for (int i = 0; i < N; i++)
//		cin >> list[i];
//
//	sort(list.begin(), list.end());
//	do {
//		answer = max(answer, check(list));
//	} while (next_permutation(list.begin(), list.end()));
//
//	cout << answer;
//}

////2468 b
//int N, maxHeight = -1, answer = 0;
//int dy[] = { -1, 1, 0, 0 }, dx[] = { 0, 0, -1, 1 };
//vector<vector<int>> table;
//vector<vector<int>> visited(N, vector<int>(N, 0));
//void dfs(int y, int x, int idx) {
//	visited[y][x] = 1;
//	
//	for (int dir = 0; dir < 4; dir++) {
//		int ny = y + dy[dir];
//		int nx = x + dx[dir];
//
//		if (ny < 0 || ny >= N || nx < 0 || nx >= N)
//			continue;
//
//		if (table[ny][nx] > idx && visited[ny][nx] == 0)
//			dfs(ny, nx, idx);
//	}
//}
//void check(int idx) {
//	int count = 0;
//	visited.assign(N, vector<int>(N, 0));
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			if (visited[i][j] == 0 && table[i][j] > idx) {
//				dfs(i, j, idx);
//				count++;
//			}
//		}
//	}
//	answer = max(answer, count);
//}
//int main() {
//	cin >> N;
//	table.resize(N, vector<int>(N));
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cin >> table[i][j];
//			maxHeight = max(maxHeight, table[i][j]);
//		}
//	}
//	
//	for (int i = 0; i <= maxHeight; i++)
//		check(i);
//	cout << answer;
//}

////14889 b
//int N, answer = 1000000000;
//vector<vector<int>> table;
//void dfs(int idx, int sumStart, int sumLink, vector<int> start, vector<int> link) {
//    if (idx == N) {
//        int sum = 0;
//
//        for (int i = 0; i < (int)start.size(); i++) {
//            for (int j = i + 1; j < (int)start.size(); j++) {
//                int u = start[i], v = start[j];
//                sum += table[u][v] + table[v][u];
//            }
//        }
//
//        for (int i = 0; i < (int)link.size(); i++) {
//            for (int j = i + 1; j < (int)link.size(); j++) {
//                int u = link[i], v = link[j];
//                sum -= table[u][v] + table[v][u];
//            }
//        }
//
//        answer = min(answer, abs(sum));
//        return;
//    }
//
//	if (sumStart < N / 2) {
//		start.push_back(idx);
//		dfs(idx + 1, sumStart + 1, sumLink, start, link);
//        start.pop_back();
//	}
//	if (sumLink < N / 2) {
//		link.push_back(idx);
//		dfs(idx + 1, sumStart, sumLink + 1, start, link);
//        link.pop_back();
//	}
//}
//int main() {
//	cin >> N;
//	table.resize(N, vector<int>(N));
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++)
//			cin >> table[i][j];
//	}
//
//	dfs(0, 0, 0, {}, {});
//	cout << answer;
//}

////14888 b
//int N, minAnswer = 1000000001, maxAnswer = -1000000001;
//vector<int> list;
//vector<int> possible = { 0, 0, 0, 0 };
//void dfs(int idx, int sum, vector<int> possible) {
//	if (idx == N - 1) {
//		minAnswer = min(minAnswer, sum);
//		maxAnswer = max(maxAnswer, sum);
//		return;
//	}
//	
//	if (possible[0] > 0)
//		dfs(idx + 1, sum + list[idx + 1], { possible[0] - 1, possible[1], possible[2], possible[3] });
//	if (possible[1] > 0)
//		dfs(idx + 1, sum - list[idx + 1], { possible[0], possible[1] - 1, possible[2], possible[3] });
//	if (possible[2] > 0)
//		dfs(idx + 1, sum * list[idx + 1], { possible[0], possible[1], possible[2] - 1, possible[3] });
//	if (possible[3] > 0)
//		dfs(idx + 1, sum / list[idx + 1], { possible[0], possible[1], possible[2], possible[3] - 1 });
//}
//int main() {
//	cin >> N;
//	list.resize(N);
//	for (int i = 0; i < N; i++)
//		cin >> list[i];
//	for (int i = 0; i < 4; i++)
//		cin >> possible[i];
//
//	dfs(0, list[0], possible);
//	cout << maxAnswer << "\n" << minAnswer;
//}

////14501 b
//int N, answer = 0;
//vector<int> T, P;
//void dfs(int idx, int sum) {
//	if (idx >= N) {
//		answer = max(answer, sum);
//		return;
//	}
//
//	if (idx + T[idx] <= N)
//		dfs(idx + T[idx], sum + P[idx]);
//	dfs(idx + 1, sum);
//}
//int main() {
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		int a, b;
//		cin >> a >> b;
//		T.push_back(a);
//		P.push_back(b);
//	}
//
//	dfs(0, 0);
//	cout << answer;
//}

////1062 b
//int N, K, answer = 0;
//bool learned[26] = { false };
//vector<string> words;
//void dfs(int idx, int depth) {
//	if (depth == K - 5) {
//		int count = 0;
//		for (int i = 0; i < words.size(); i++) {
//			int pass = 1;
//			for (char c : words[i]) {
//				if (learned[c - 'a'] == false) {
//					pass = 0;
//					break;
//				}
//			}
//			if (pass == 1)
//				count++;
//		}
//		answer = max(answer, count);
//		return;
//	}
//
//	for (int i = idx; i < 26; i++) {
//		if (learned[i])
//			continue;
//		learned[i] = true;
//		dfs(i + 1, depth + 1);
//		learned[i] = false;
//	}
//}
//int main() {
//	cin >> N >> K;
//	if (K < 5) {
//		cout << 0;
//		return 0;
//	}
//	for (int i = 0; i < N; i++) {
//		string input;
//		cin >> input;
//		words.push_back(input.substr(4, input.length() - 8));
//	}
//	learned['a' - 'a'] = true;
//	learned['n' - 'a'] = true;
//	learned['t' - 'a'] = true;
//	learned['i' - 'a'] = true;
//	learned['c' - 'a'] = true;
//
//	dfs(0, 0);
//	cout << answer;
//}

////1107 b
//int N, M, answer = 0;
//vector<int> broken;
//int canPress(int num) {
//	if (num == 0) {
//		if (find(broken.begin(), broken.end(), 0) != broken.end())
//			return -1;
//		else
//			return 1;
//	}
//
//	int len = 0;
//	while (num > 0) {
//		int save = num % 10;
//		if (find(broken.begin(), broken.end(), save) != broken.end())
//			return -1;
//		len++;
//		num /= 10;
//	}
//	return len;
//}
//int main() {
//	cin >> N >> M;
//	for (int i = 0; i < M; i++) {
//		int a;
//		cin >> a;
//		broken.push_back(a);
//	}
//	answer = abs(N - 100);
//
//	for (int i = 0; i <= 1000000; i++) {
//		int len = canPress(i);
//		if (len != -1)
//			answer = min(answer, len + abs(i - N));
//	}
//
//	cout << answer;
//}

////14500 b
//vector<vector<pair<int, int>>> tetromino = {
//    {{0,0},{0,1},{0,2},{0,3}},
//
//    {{0,0},{1,0},{2,0},{3,0}},
//    {{0,0},{0,1},{1,0},{1,1}},
//
//    {{0,0},{1,0},{2,0},{2,1}},
//    {{0,0},{0,1},{1,1},{2,1}},
//    {{0,0},{0,1},{0,2},{1,0}},
//    {{0,2},{1,0},{1,1},{1,2}},
//
//    {{0,1},{1,1},{2,1},{2,0}},
//    {{0,0},{1,0},{2,0},{0,1}},
//    {{0,0},{0,1},{0,2},{1,2}},
//    {{0,0},{1,0},{1,1},{1,2}},
//
//    {{0,0},{0,1},{1,1},{1,2}},
//    {{0,1},{1,0},{1,1},{2,0}},
//
//    {{0,1},{0,2},{1,0},{1,1}},
//    {{0,0},{1,0},{1,1},{2,1}},
//
//    {{0,0},{0,1},{0,2},{1,1}},
//    {{0,1},{1,1},{2,1},{1,0}},
//    {{0,1},{1,0},{1,1},{1,2}},
//    {{0,0},{1,0},{2,0},{1,1}}
//};
//int main() {
//    int N, M, answer = 0;
//    cin >> N >> M;
//    vector<vector<int>> map(N, vector<int>(M));
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < M; j++) {
//            cin >> map[i][j];
//        }
//    }
//
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < M; j++) {
//            for (int k = 0; k < tetromino.size(); k++) {
//                int sum = 0, pass = 1;
//                for (int l = 0; l < 4; l++) {
//                    int ny = i + tetromino[k][l].first;
//                    int nx = j + tetromino[k][l].second;
//                    if (ny < 0 || nx < 0 || ny >= N || nx >= M) {
//                        pass = 0;
//                        break;
//                    }
//                    sum += map[ny][nx];
//                }
//                if (pass == 1)
//                    answer = max(answer, sum);
//            }
//        }
//    }
//
//    cout << answer;
//}

////14502 b
//int N, M, answer = 0;
//int dx[] = { 0, 0, -1, 1 }, dy[] = { 1, -1, 0, 0 };
//void bfs(vector<vector<int>> map) {
//	queue<pair<int, int>> q;
//	vector<vector<int>> visited(N, vector<int>(M, 0));
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			if (map[i][j] == 2) {
//				q.push({ i,j });
//				visited[i][j] = 1;
//			}
//		}
//	}
//
//	while (!q.empty()) {
//		auto [y, x] = q.front();
//		q.pop();
//		for (int d = 0; d < 4; d++) {
//			int ny = y + dy[d];
//			int nx = x + dx[d];
//			if (ny < 0 || nx < 0 || ny >= N || nx >= M)
//				continue;
//			if (visited[ny][nx])
//				continue;
//			if (map[ny][nx] == 1)
//				continue;
//
//			visited[ny][nx] = 1;
//			map[ny][nx] = 2;
//			q.push({ ny, nx });
//		}
//	}
//
//	int safe = 0;
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < M; j++)
//			if (map[i][j] == 0)
//				safe++;
//	answer = max(answer, safe);
//}
//void makeWall(int cnt, int startx, int starty, vector<vector<int>> map) {
//	if (cnt == 3) {
//		bfs(map);
//		return;
//	}
//
//	for (int i = starty; i < N; i++) {
//		for (int j = (i == starty ? startx : 0); j < M; j++) {
//			if (map[i][j] != 0)
//				continue;
//			map[i][j] = 1;
//
//			if (j + 1 < M)
//				makeWall(cnt + 1, j + 1, i, map);
//			else
//				makeWall(cnt + 1, 0, i + 1, map);
//			map[i][j] = 0;
//		}
//	}
//}
//int main() {
//	cin >> N >> M;
//	vector<vector<int>> lab(N, vector<int>(M));
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			cin >> lab[i][j];
//		}
//	}
//
//	makeWall(0, 0, 0, lab);
//	cout << answer;
//}

////9663 b
//int N, answer = 0;
//int col[15], diagUp[30], diagDown[30];
//void dfs(int row) {
//	if (row == N) {
//		answer++;
//		return;
//	}
//
//	for (int i = 0; i < N; i++) {
//		if (col[i] == 1 || diagUp[row + i] == 1 || diagDown[row - i + N - 1])
//			continue;
//
//		col[i] = 1;
//		diagUp[row + i] = 1;
//		diagDown[row - i + N - 1] = 1;
//
//		dfs(row + 1);
//
//		col[i] = 0;
//		diagUp[row + i] = 0;
//		diagDown[row - i + N - 1] = 0;
//	}
//}
//int main() {
//	cin >> N;
//	dfs(0);
//	cout << answer;
//}

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