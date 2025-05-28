// #include <iostream>
// using namespace std;
// // bit maskeing ka use karenge 
// // jo n hai uss size ka bits wala array lelo yani ki
// // 2 ki power n -1 tak 0 se 2^n-1 tak hota hai because 
// // 0 means sign of - 
// //1 means sign of +
// //array input numbers pe baari baari se bits run 0 to 2^n-1 and see where ever target
// int main() {
//     int n;
//     cin>>n;
//     int a[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin>>a[i];
//     }
//     // pehle ab loop laga 0 se 2^n-1 tak ka aur saare numbers ka binary representation le
//     // agar 0 hai to - 1 hai to +
//     for (int i = 0; i < ((1<<n)-1); i++)
//     {
//         int sum=0;
//         // binary representation of n bits
//         for (int j = 0; j <n ; j++)
//         {
//             if (i and (1<<j)){
//                 sum+=
//             }
            
            
//         }
        
//     }
    
    
//     return 0;
// }
#include <iostream>
using namespace std;

int main() {

	int n;
	int a[50];
	int target;
	cin >> n >> target;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	int ans = 0;

	for (int i = 0; i < (1 << n); ++i)
	{
		int no = i;
		int sum = 0;

		for (int i = 0; i < n; ++i)
		{
			if ((no & 1) == 0) {
				sum += a[i];
			}
			else {
				sum = sum - a[i];
			}

			no = no >> 1;
		}
		if (sum == target) {
			ans++;
		}
	}

	cout << ans << endl;




	
	return 0;
}