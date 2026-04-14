#define  _CRT_SECURE_NO_WARNINGS 1
//洛谷经典题 吃苹果
//#include <iostream>
//using namespace std;
//int main()
//{
//	int m, t, s,left;
//	cin >> m >> t >> s;
//	if (s <= m * t)
//	{
//		int ate = (s + t - 1) / t;
//		left = m - ate;
//	}
//	else
//	{
//		left = 0;
//	}
//	cout << left << endl;
//
//	return 0;
//}
//洛谷经典题 数的性质
//初见
//#include <iostream>
//using namespace std;
//int n1(int x)
//{
//	if (x % 2 == 0)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//int n2(int x)
//{
//	if (x > 4 && x <= 12)
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
//	int A = 0, UIM = 0, B = 0, Z = 0;
//	int x = 0;
//	cin >> x;
//	if (n1(x) && n2(x))
//	{
//		A = 1;
//	}
//	if (n1(x) || n2(x))
//	{
//		UIM = 1;
//
//	}
//	if (n1(x) + n2(x) == 1)
//	{
//		B = 1;
//	}
//	if (n1(x) + n2(x) == 0)
//	{
//		Z = 1;
//	}
//	cout << A << " " << UIM << " " << B << " " << Z << endl;
//	return 0;
//}
//优化
//#include <iostream>
//using namespace std;
//
//int main()
//{
//    int x;
//    cin >> x;
//
//    // 直接将性质判断化为 0 或 1 的布尔变量
//    bool p1 = (x % 2 == 0);          // 性质1：是偶数
//    bool p2 = (x > 4 && x <= 12);    // 性质2：大于4且不大于12
//
//    // 小A：都满足 (逻辑与)
//    int A = p1 && p2;
//
//    // Uim：至少满足一个 (逻辑或)
//    int UIM = p1 || p2;
//
//    // 八尾勇：刚好满足一个 (加起来等于1)
//    int B = (p1 + p2 == 1);
//
//    // 正妹：都不满足 (加起来等于0)
//    int Z = (p1 + p2 == 0);
//
//    cout << A << " " << UIM << " " << B << " " << Z << endl;
//
//    return 0;
//}
//极限
//#include <iostream>
//using namespace std;
//
//int main()
//{
//    int x;
//    cin >> x;
//
//    // 直接在 cout 中完成所有的逻辑计算和输出
//    cout << ((x % 2 == 0) && (x > 4 && x <= 12)) << " "    // 小A
//        << ((x % 2 == 0) || (x > 4 && x <= 12)) << " "    // Uim
//        << ((x % 2 == 0) + (x > 4 && x <= 12) == 1) << " "  // 八尾勇
//        << ((x % 2 == 0) + (x > 4 && x <= 12) == 0) << endl; // 正妹
//
//    return 0;
//}
//#include <iostream>
//using namespace std;
//
//int main() {
//    int a, b, c;
//    cin >> a >> b >> c;
//
//    // 确保a <= b
//    if (a > b) swap(a, b);
//    // 确保a <= c
//    if (a > c) swap(a, c);
//    // 确保b <= c
//    if (b > c) swap(b, c);
//
//    cout << a << " " << b << " " << c << endl;
//    return 0;
//}
// 洛谷经典题 不高兴的津津
//#include <iostream>
//using namespace std;
//
//int main() {
//    int a, b;
//    int max_time = 8; // 设定初始擂主战力为 8
//    int bad_day = 0;  // 记录新擂主是星期几，默认是 0
//
//    // i 代表星期几，从 1 循环到 7
//    for (int i = 1; i <= 7; i++) {
//        cin >> a >> b;
//        int sum = a + b; // 计算今天的总时间
//
//        // 如果今天的时间大于现有的最大时间，挑战成功！
//        if (sum > max_time) {
//            max_time = sum; // 更新擂主战力
//            bad_day = i;    // 记录下今天是星期几
//        }
//    }
//
//    // 循环结束后，留在擂台上的就是答案
//    cout << bad_day << endl;
//
//    return 0;
//}
//洛谷经典题 买铅笔
//初见
//#include <iostream>
//using namespace std;
//int main()
//{
//	int n, sum1, price1, sum2, price2, sum3, price3, total1, total2, total3, total;
//	cin >> n >> sum1 >> price1 >> sum2 >> price2 >> sum3 >> price3;
//	for (int i = 0; i * sum1 < n; i++)
//	{
//		total1 = (i + 1) * price1;
//	}
//	for (int j = 0; j * sum2 < n; j++)
//	{
//		total2 = (j + 1) * price2;
//	}
//	for (int k = 0; k * sum3 < n; k++)
//	{
//		total3 = (k + 1) * price3;
//	}
//	int min = (total1 < total2) ? total1 : total2;
//	total = (min < total3) ? min : total3;
//	cout << total;
//
//	return 0;
//}
//优化：
//#include <iostream>
//#include <algorithm> // 引入算法库，使用 min 函数
//using namespace std;
//
//int main() {
//    int n;
//    cin >> n;
//
//    // 设一个极大的初始擂主战力（因为我们要找最小值，所以初始值要足够大）
//    // 2147483647 是 int 能存的最大正数
//    int min_cost = 2147483647;
//
//    // 一共有 3 种铅笔，直接循环 3 次
//    for (int i = 0; i < 3; i++) {
//        int sum, price;
//        cin >> sum >> price; // 边读入
//
//        // 瞬间计算当前种类铅笔的盒数和总价
//        int packages = n / sum;
//        if (n % sum != 0) {
//            packages++;
//        }
//        int total = packages * price;
//
//        // 打擂台：把当前的总价和历史最低价进行 PK，保留更小的那个
//        min_cost = min(min_cost, total);
//    }
//
//    // 循环结束，直接输出活到最后的最低价
//    cout << min_cost << endl;
//
//    return 0;
//}
//#include <iostream>
//#include <iomanip>
//using namespace std;
//int main()
//{
//	int a;
//	float sum;
//	cin >> a;
//	if (a <= 150)
//	{
//		sum = 0.4463 * a;
//	}
//	else
//	{
//		if (a > 150 && a <= 400)
//		{
//			sum = 0.4463 * 150 + (a - 150) * 0.4663;
//		}
//		else
//		{
//			sum = 0.4463 * 150 + 250 * 0.4663 + (a - 400) * 0.5663;
//		}
//	}
//
//	cout << fixed << setprecision(1) << sum << endl;
//	return 0;
//}
//小鱼的航程
//初见
//#include <iostream>
//using namespace std;
//int main()
//{
//	int x, n, sum,final;
//	cin >> x >> n;
//	sum = n * 250;
//	if (x + n  > 6)
//	{
//		if ((x + n - 1 ) % 7 == 6)
//		{
//			final = sum - 250 - ((n + x - 1) / 7)*500;
//		}
//		else
//		{
//			final = sum - ((n + x - 1) / 7)*500;
//		}
//	}
//	else
//	{
//		final = sum;
//	}
//	cout << final << endl;
//	return 0;
//}
//很遗憾，这个会漏掉休息日的情况
//改进：
//#include <iostream>
//using namespace std;
//
//int main() {
//	int x, n;
//	long long total = 0; // 习惯性开 long long，防止总距离超过 int 的上限
//	cin >> x >> n;
//
//	for (int i = 0; i < n; i++) {
//		if (x != 6 && x != 7) {
//			total += 250; // 工作日，增加距离
//		}
//
//		x++; // 日子往后推一天
//
//		if (x == 8) {
//			x = 1; // 如果到了星期八，强制把它拨回星期一
//		}
//	}
//
//	cout << total << endl;
//	return 0;
//}
//#include <iostream>
//using namespace std;
//int main()
//{
//	int arr[10] = { 0 };
//	for (int i = 0; i < 10; i++)
//	{
//		cin >> arr[i];
//	}
//	int n;
//	int count = 0;
//	cin >> n;
//	for (int j = 0; j < 10; j++)
//	{
//		if (arr[j] <= n + 30)
//		{
//			count++;
//		}
//	}
//	cout << count << endl;
//
//	return 0;
//}
//洛谷经典题 ABC
//初见
//#include <iostream>
//#include <algorithm>
//#include <string.h>
//using namespace std;
//int main()
//{
//	int a, b, c;
//	char arr[4] = {'A','B','C','\0'};
//	cin >> a >> b >> c;
//	int Min, Max, Mid;
//	Min = min({a,b,c});
//	Max = max({ a,b,c });
//	Mid = a + b + c - Min - Max;
//	for (int i = 0; i < 3; i++)
//	{
//		cin >> arr[i];
//	}
//	char str1[4] = { 'A','B','C','\0'};
//	char str2[4] = { 'A','C','B','\0'};
//	char str3[4] = { 'B','A','C' ,'\0'};
//	char str4[4] = { 'B','C','A','\0'};
//	char str5[4] = { 'C','B','A' ,'\0'};
//	char str6[4]= { 'C','A','B' ,'\0'};
//	if (strcmp(arr, str1) == 0)
//	{
//		cout << Min <<" "<< Mid <<" "<< Max << endl;
//	}
//	if (strcmp(arr, str2) == 0)
//	{
//		cout << Min <<" "<< Max <<" "<< Mid << endl;
//	}
//	if (strcmp(arr, str3) == 0)
//	{
//		cout << Mid <<" "<< Min <<" "<< Max << endl;
//	}
//	if (strcmp(arr, str4) == 0)
//	{
//		cout << Mid <<" "<< Max <<" "<< Min << endl;
//	}
//	if (strcmp(arr, str5) == 0)
//	{
//		cout << Max <<" " << Mid << " " << Min << endl;
//	}
//	if (strcmp(arr, str6) == 0)
//	{
//		cout << Max <<" "<< Min <<" "<< Mid << endl;
//	}
//
//	return 0;
//}
//进阶
//#include <iostream>
//#include <algorithm> // 包含 sort
//#include <string>    // 包含现代 C++ 字符串库
//using namespace std;
//
//int main() {
//    int num[3];
//    // 1. 直接读入三个数到数组中
//    cin >> num[0] >> num[1] >> num[2];
//
//    // 2. 将数组从小到大排序
//    // 排序后：num[0]是最小(A), num[1]是中间(B), num[2]是最大(C)
//    sort(num, num + 3);
//
//    string s;
//    // 3. 瞬间读入包含 3 个字母的字符串 (比如 "BCA")
//    cin >> s;
//
//    // 4. 利用 ASCII 码魔法，直接映射输出
//    for (int i = 0; i < 3; i++) {
//        // s[i] 取出当前字母
//        // 减去 'A' 得到 0, 1 或 2，直接作为 num 数组的下标
//        cout << num[s[i] - 'A'] << " ";
//    }
//    cout << endl;
//
//    return 0;
//}
#include <iostream>
#include <string>
using namespace std;

int main() {
    string isbn;
    cin >> isbn; // 瞬间将形如 "0-670-82162-4" 的 13 个字符吸入

    int sum = 0;
    int multiplier = 1; // 乘数，从 1 递增到 9

    // 1. 遍历前 11 个字符（下标 0 到 10），刚好包含前 9 个数字
    for (int i = 0; i <= 10; i++) {
        if (isbn[i] != '-') { // 遇到数字才处理，精准绕过 '-'
            // isbn[i] - '0' 是把字符转成真数字
            sum += (isbn[i] - '0') * multiplier;
            multiplier++; // 乘数用完一次就加 1
        }
    }

    // 2. 计算识别码
    int remainder = sum % 11;
    char expected_char; // 期望的正确识别码字符

    if (remainder == 10) {
        expected_char = 'X'; // 特判 10 的情况
    }
    else {
        expected_char = remainder + '0'; // 数字转字符魔法
    }

    // 3. 校验与输出
    // 整个字符串长度固定是 13，最后一个字符的下标是 12
    if (isbn[12] == expected_char) {
        cout << "Right" << endl;
    }
    else {
        isbn[12] = expected_char; // 霸气地直接在原字符串上修改错误
        cout << isbn << endl;     // 连同分隔符一起原样输出
    }

    return 0;
}