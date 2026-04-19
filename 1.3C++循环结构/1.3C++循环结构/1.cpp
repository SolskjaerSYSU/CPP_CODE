#define  _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//int main()
//{
//	int n, x,count;
//	count = 0;
//	cin >> n >> x;
//	for (int i = 1; i <= n; i++)
//	{
//		int temp = i;
//		while (temp)
//		{
//			if (temp % 10 == x)
//			{
//				count++;
//			}
//			temp /= 10;
//		}
//
//	}
//	cout << count <<endl;
//	return 0;
//}
//#include <iostream>
//using namespace std;
//
//int main() {
//    int k;
//    cin >> k;
//
//    double sum = 0;
//    int n = 0; // n 从 0 开始
//
//    // 只要累加和还没超过 k，就继续往后走
//    while (sum <= k) {
//        n++;              // 先往前走一步，n 变成 1, 2, 3...
//        sum += 1.0 / n;   // 把新这一步的分数直接累加上去
//    }
//
//    // 循环被打破的那一刻，说明刚刚加上 1/n 后 sum 大于 k 了，此时的 n 刚好就是答案！
//    cout << n << endl;
//
//    return 0;
//}
//洛谷经典题 金币
//初见
//#include <iostream>
//using namespace std;
//int main()
//{
//	int k, gold, sum, stage;
//	sum = 0;
//	gold = 0;
//	stage = 0;
//	cin >> k;
//	//1.判断在stage几
//	while (sum < k)
//	{
//		stage++;
//		sum = (stage + stage * stage) / 2;
//	}
//	//2.计算
//	for (int i = 1; i <= stage - 1; i++)
//	{
//		gold += i * i;
//	}
//	gold += (k - sum + stage) * stage;
//	cout << gold << endl;
//
//	return 0;
//}
//另一种可能：暴力模拟
//#include <iostream>
//using namespace std;
//
//int main() {
//    int k;
//    cin >> k;
//
//    int gold = 0;
//    int current_coin = 1; // 当前每天发多少金币
//    int days_in_this_stage = 0; // 这个阶段已经发了几天了
//
//    // 一天一天踏踏实实地过日子
//    for (int i = 1; i <= k; i++) {
//        gold += current_coin; // 今天领工资
//        days_in_this_stage++; // 这个阶段的日子多了一天
//
//        // 如果这个阶段熬出头了（发 1 金币的发了 1 天，发 2 金币的发了 2 天...）
//        if (days_in_this_stage == current_coin) {
//            current_coin++; // 阶段升级，明天的工资变高
//            days_in_this_stage = 0; // 新阶段的日子清零，重新开始熬
//        }
//    }
//
//    cout << gold << endl;
//    return 0;
//}
//#include <iostream>
//using namespace std;
//int main()
//{
//	int n, sum;
//	sum = 0;
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		sum += i;
//	}
//	cout << sum;
//
//	return 0;
//}
//洛谷经典题 质数口袋
//初见
//#include <iostream>
//using namespace std;
//int is_prime(int x)
//{
//	int factor = 0;
//	for (int i = 1; i <= x; i++)
//	{
//		if (x % i == 0)
//		{
//			factor++;
//		}
//	}
//	if (factor == 2)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//int main()
//{
//	int L;
//	cin >> L;
//	if (L == 1)
//	{
//		cout << 0 << endl;
//	}
//	else
//	{
//		int n = 0;
//		int sum = 0;
//		int a = 0;
//		int arr[100] = {0};
//		while (sum <= L)
//		{
//			n++;
//			sum += n;
//			if (is_prime(n))
//			{
//				arr[a] = n;
//				a++;
//			}
//		}
//		for (int i = 0; i <= a; i++)
//		{
//			cout << arr[i] << endl;
//		}
//		cout << a + 1 << endl;
//	}
//	
//	return 0;
//}
//#include <iostream>
//using namespace std;
//// 进化版的质数判断函数
//bool is_prime(int x) {
//    if (x < 2) return false; // 0 和 1 不是质数
//
//    // 技巧：i * i <= x 等价于 i <= sqrt(x)，避免了使用浮点数开方
//    for (int i = 2; i * i <= x; i++) {
//        if (x % i == 0) {
//            return false; // 只要找到一个因数，立马判定死刑，结束函数
//        }
//    }
//    return true; // 循环跑完都没找到因数，那它绝对是质数
//}
//
//int main() {
//    int L;
//    cin >> L;
//
//    int sum = 0;   // 口袋当前重量
//    int count = 0; // 装了几个质数
//
//    // 质数从 2 开始找，不需要上限，因为重量超标时会自动 break
//    for (int i = 2; ; i++) {
//        if (is_prime(i)) {
//            // 先在脑子里预演一下：如果把 i 装进去，会不会撑爆口袋？
//            if (sum + i > L) {
//                break; // 撑爆了，赶紧收手，跳出循环！
//            }
//
//            // 没撑爆，直接输出，不需要数组！
//            cout << i << endl;
//            sum += i;   // 增加口袋重量（你之前漏掉的最关键一步）
//            count++;    // 记录数量
//        }
//    }
//
//    // 最后输出总个数
//    cout << count << endl;
//
//    return 0;
//}
//洛谷经典题  回文质数
//初见
//#include <iostream>
//#include <string>
//using namespace std;
//// 进化版的质数判断函数
//bool is_prime(int x) {
//    if (x < 2) return false; // 0 和 1 不是质数
//
//    // 技巧：i * i <= x 等价于 i <= sqrt(x)，避免了使用浮点数开方
//    for (int i = 2; i * i <= x; i++) {
//        if (x % i == 0) {
//            return false; // 只要找到一个因数，立马判定死刑，结束函数
//        }
//    }
//    return true; // 循环跑完都没找到因数，那它绝对是质数
//}
//bool is_Palindrome(int x)
//{
//    string str = to_string(x);
//    int len = str.size();
//    for (int i = 0; i < len / 2; i++)
//    {
//        if (str[i] != str[len - i - 1])
//        {
//            return false;
//        }
//    }
//    return true;
//}
//int main()
//{
//    int a, b, n;
//    cin >> a >> b;
//    for (n = a; n <= b; n++)
//    {
//        if (is_prime(n) && is_Palindrome(n))//判断
//        {
//            cout << n << endl;
//        }
//    }
//
//    return 0;
//}
//优化：
//
//最佳：
//#include <iostream>
//using namespace std;
//
//// 还是那个高效的质数判断函数
//bool is_prime(int x) {
//    if (x < 2) return false;
//    for (int i = 2; i * i <= x; i++) {
//        if (x % i == 0) return false;
//    }
//    return true;
//}
//
//int main() {
//    int a, b;
//    cin >> a >> b;
//
//    int palindrome;
//
//    // 1. 拼装 1 位数回文数
//    for (int d1 = 5; d1 <= 9; d1 += 2) { // 首位必须是奇数才可能是质数（除了2，但题目范围通常较大，可以自己微调）
//        if (d1 >= a && d1 <= b && is_prime(d1)) cout << d1 << endl;
//    }
//
//    // 2. 拼装 2 位数回文数 (只有 11 是特例)
//    if (11 >= a && 11 <= b && is_prime(11)) cout << 11 << endl;
//
//    // 3. 拼装 3 位数回文数 (d1 d2 d1)
//    for (int d1 = 1; d1 <= 9; d1 += 2) { // 提示：最后一位是 d1，如果是偶数或者5，绝对不是质数，可以再优化
//        for (int d2 = 0; d2 <= 9; d2++) {
//            palindrome = 100 * d1 + 10 * d2 + d1;
//            if (palindrome >= a && palindrome <= b && is_prime(palindrome)) cout << palindrome << endl;
//        }
//    }
//
//    // （直接跳过 4 位数！）
//
//    // 4. 拼装 5 位数回文数 (d1 d2 d3 d2 d1)
//    for (int d1 = 1; d1 <= 9; d1 += 2) {
//        for (int d2 = 0; d2 <= 9; d2++) {
//            for (int d3 = 0; d3 <= 9; d3++) {
//                palindrome = 10000 * d1 + 1000 * d2 + 100 * d3 + 10 * d2 + d1;
//                if (palindrome >= a && palindrome <= b && is_prime(palindrome)) cout << palindrome << endl;
//            }
//        }
//    }
//
//    // （直接跳过 6 位数！）
//
//    // 5. 拼装 7 位数回文数 (d1 d2 d3 d4 d3 d2 d1)
//    for (int d1 = 1; d1 <= 9; d1 += 2) {
//        for (int d2 = 0; d2 <= 9; d2++) {
//            for (int d3 = 0; d3 <= 9; d3++) {
//                for (int d4 = 0; d4 <= 9; d4++) {
//                    palindrome = 1000000 * d1 + 100000 * d2 + 10000 * d3 + 1000 * d4 + 100 * d3 + 10 * d2 + d1;
//                    // 如果已经越界，直接结束整个程序，极速逃逸！
//                    if (palindrome > b) return 0;
//
//                    if (palindrome >= a && is_prime(palindrome)) cout << palindrome << endl;
//                }
//            }
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//using namespace std;
//int main()
//{
//	double mission;
//	double sum = 0.0;
//	double speed = 2.0;
//	int step = 0;
//	cin >> mission;
//	while (sum < mission)
//	{
//		step++;
//		sum += speed;
//		speed *= 0.98;
//	}
//
//	cout << step << endl;
//
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	int N;
//	cin >> N;
//	while (N % 10 == 0) //处理0
//	{
//		N /= 10;
//	}
//	string str = to_string(N);
//	int len = str.size();
//	if (N >= 0) //若为正数，则不需要处理负号
//	{
//			for (int i = 0; i < len; i++)
//			{
//				cout << str[len - 1 - i];
//			}
//		
//	}
//	else
//	{
//		cout << "-";
//		for (int i = 1; i < len; i++)
//		{
//			cout << str[len - i];
//		}
//	}
//
//	return 0;
//}
// //
// 初见：变长数组
//#include <iostream>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	int arr[n];
//	for (int i = 0; i < n; i++)
//	{
//		cin >>arr[i];
//	}
//	sort(arr, arr + n);
//	cout << arr[n - 1] - arr[0] << endl;
//
//	return 0;
//}
//优化：
//#include <iostream>
//#include <algorithm> // 为了使用内置的 max() 和 min() 函数
//
//using namespace std;
//
//int main()
//{
//    int n;
//    cin >> n;
//
//    // 初始化最大值为一个很小的数，最小值为一个很大的数
//    // 也可以初始化为题目数据范围的极值
//    int max_val = -1;
//    int min_val = 100000;
//
//    for (int i = 0; i < n; i++)
//    {
//        int num;
//        cin >> num; // 每次只读取当前数字
//
//        // 比较并更新当前的最大值和最小值
//        max_val = max(max_val, num);
//        min_val = min(min_val, num);
//    }
//
//    // 输出极差
//    cout << max_val - min_val << endl;
//
//    return 0;
//}
//#include <iostream>
//
//#include <algorithm>
//
//using namespace std;
//
//int main()
//
//{
//
//	int n;
//
//	cin >> n;
//
//	int arr[105];
//
//	for (int i = 0; i < n; i++)
//
//	{
//
//		cin >> arr[i];
//
//	}
//
//	sort(arr, arr + n);
//
//	cout << arr[n - 1] - arr[0] << endl;
//
//
//
//	return 0;
//
//}
//#include <iostream>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	int count = 1;
//	int max_count = 1;
//	int front = -1;
//
//	for (int i = 0; i < n; i++)
//	{
//		int num;
//		int temp = 1;
//		cin >> num;
//		if (num == front + 1)
//		{
//			count++;
//			temp = count;
//		}
//		else
//		{
//			count = 1;
//		}
//		max_count = max(max_count, temp);
//		front = num;
//	}
//	cout << max_count << endl;
//
//	return 0;
//}
//#include <iostream>
//#include <algorithm>
//using namespace std;
//bool is_prime(int x) {
//	    if (x < 2) return false; // 0 和 1 不是质数
//	
//	    // 技巧：i * i <= x 等价于 i <= sqrt(x)，避免了使用浮点数开方
//	    for (int i = 2; i * i <= x; i++) {
//	        if (x % i == 0) {
//	            return false; // 只要找到一个因数，立马判定死刑，结束函数
//	        }
//	    }
//	    return true; // 循环跑完都没找到因数，那它绝对是质数
//	}
//int is_mul_prime(int x)
//{
//	if (x < 6 && is_prime(x)) return 0;
//
//	for (int i = 2; i * i <= x; i++)
//	{
//		if (x % i == 0 && is_prime(i))
//		{
//			int temp1 = i;
//			int temp2 = x / temp1;
//			return temp2; // 只有找到因数了，才计算并返回
//		}
//	}
//	return 0;
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	cout << is_mul_prime(n) << endl;
//
//	return 0;
//}
//#include <iostream>
//#include <iomanip> // 必须引入这个头文件，才能使用 setw 和 setfill
//using namespace std;
//int main()
//{
//    int n;
//    cin >> n;
//    // ================= 任务一：打印正方形 =================
//    int count = 1; // 准备一个计数器，从 1 开始
//    for (int i = 0; i < n; i++) // 外层循环：控制一共打印 n 行
//    {
//        for (int j = 0; j < n; j++) // 内层循环：控制每一行打印 n 个数字
//        {
//            // 输出格式：设置宽度为 2，不足的地方用 '0' 填充，然后输出数字
//            cout << setfill('0') << setw(2) << count;
//            count++; // 每次打印完，数字加 1
//        }
//        cout << endl; // 这一行的 n 个数字打印完了，记得换行
//    }
//
//    // ================= 任务二：打印中间的空行 =================
//    cout << endl;
//
//    // ================= 任务三：打印靠右的直角三角形 =================
//    count = 1; // 计数器清零，重新从 1 开始
//
//    // 这里为了方便计算规律，我们让行号 i 从 1 开始，到 n 结束
//    for (int i = 1; i <= n; i++)
//    {
//        // 步骤 3.1：先打印前面的空格（把位置占住）
//        // 规律：第 i 行需要 n - i 个空位
//        for (int j = 0; j < n - i; j++)
//        {
//            cout << "  "; // 注意！这里是两个空格，因为一个数字占两个位置
//        }
//
//        // 步骤 3.2：再打印后面的数字
//        // 规律：第 i 行需要打印 i 个数字
//        for (int j = 0; j < i; j++)
//        {
//            cout << setfill('0') << setw(2) << count;
//            count++; // 每次打印完，数字加 1
//        }
//
//        cout << endl; // 这一行打印完了，换行
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <algorithm>
//#include <iomanip>
//using namespace std;
//int main()
//{
//	int n;
//	int sum1 = 0;
//	float sum = 0;
//	int max_n = 0;
//	int min_n = 0;
//	float ave = 0.0;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		int temp;
//		cin >> temp;
//		sum1 += temp;
//		max_n = max(max_n, temp);
//		min_n = min(min_n, temp);
//	}
//	sum = sum1 - max_n - min_n;
//	ave = sum / (n - 2);
//	cout << fixed << setprecision(2) << ave << endl;
//
//	return 0;
//}
//#include <iostream>
//using namespace std;
//int main()
//{
//	int n;
//	int x = 1;
//	int k = 1;
//	cin >> n;
//	if (n % 364 == 0)
//	{
//		int ave = n / 364;
//		if (ave <= 103)
//		{
//			k = 1;
//			x = ave - 3*k;
//		}
//		else //ave>104
//		{
//			//x在98 99 100 间循环
//			if (ave % 3 == 2)
//			{
//				x = 98;
//				k = (ave - x) / 3;
//			}
//			else if (ave % 3 == 0)
//			{
//				x = 99;
//				k = (ave - x) / 3;
//			}
//			else
//			{
//				x = 100;
//				k = (ave - x) / 3;
//			}
//		}
//	}
//	cout << x << endl;
//	cout << k << endl;
//
//	return 0;
//}
#include <iostream>
using namespace std;
int main()
{
	int arr[12];
	int left = 0;
	int sum = 0;
	int x = 0;
	int flag = 0;
	for (int i = 0; i < 12; i++) //存入预算
	{
		cin >> arr[i]; //arr[i]表示这个月的预算
	}
	for (int i = 0; i < 12; i++)
	{
		//1.先判断要不要存钱或要不要省吃俭用
		if (left + 300 < arr[i]&&flag!=1)
		{
			x = i + 1; //若需要省吃俭用，则存储下这个月的月份
			flag = 1; //静态变量，避免x内存被覆盖
		}
		while (left + 300 >= arr[i] + 100)
		{
			left -= 100;
			sum += 100;
		}
		//2.存完钱后
		left += 300; //先拿钱
		left -= arr[i]; //后花钱
	}
	if (flag == 1) //若有省吃俭用
	{
		cout << "-" << x << endl;
	}
	else
	{
		cout << sum * 1.2 + left << endl;
	}

	return 0;
}
