<<<<<<< HEAD
//-------------------BTVN so 1-------------------
Khai bao mang so nguyen 2 chieu kich thuoc R va C:

int** mt;
mt = new int* [R];
int* temp = new int[R * C];
for (i = 0; i < R; ++i) {
	mt[i] = temp;
	temp += C;
}
//Khoi tao ma tran voi R hang va C cot
float** M = new float* [R];
for (i = 0; i < R; i++)
	M[i] = new float[C];
//Dung M[i][j] cho cac phan tu cua ma tran
//Giai phong
for (i = 0; i < R; i++)
	//Giai phong cac hang
	delete[]M[i];
	delete[]M;
	----------------SO SANH----------------
mt = new int* [R] //la mot mang gom R con tro -> luu dia chi cua tung hang 
int* temp = new int[R * C]: //Tao mot mang co kich thuoc R * C, luu lai moi phan tu cua ma tran
for (i = 0; i < R; ++i) {
	mt[i] = temp;
	temp += C;
}: //Gan R con tro mt[i] toi cac phan tu tuong ung trong mang "temp"
< Su thay doi >
mt[i] tro toi temp
temp tang C -> mt[i] tro toi phan tu dau tien cua hang tiep theo
Ket qua: mt[i] tro toi 1 phan cua mang "temp" 
         Su dung mt[i][j] co the tro toi 1 phan tu cu the cua mang "temp"
	-> Khong cap phat bo nho rieng cho tung hang
	-> Con tro mt[i][j] tro toi dia chi cu the cua tung phan tu trong mang "temp"
	-> Gay ton dung luong bo nho hon
	-> Su dung "temp" la mang 1 chieu de mo phong ma tran 2 chieu
	------------
float** M = new float* [R] //Tao mot mang con tro gom R con tro
for (i = 0; i < R; i++)
	M[i] = new float[C]; //con tro M[i] tro toi mang 1 chieu co C phan tu
Ket qua: 
->Cap phat bo nho rieng cho tung hang cua ma tran
->De truy cap toi M[i][j] hon
//-------------------BTVN so 2-------------------
Bai 1 :
#include<iostream>
using namespace std;
void insertionSort(int arr[], int N) { //Chen
		for (int i = 1; i < N; i++) {
			int key = arr[i];
			int j = i - 1;
			while (j >= 0 && arr[j] > key) {
				arr[j + 1] = arr[j];
				j = j - 1;
			}
			arr[j + 1] = key;
		}
}
int main(void) {
	int n;
	cin >> n;
	int mang[n];
	for (int k = 0; k < n; k++) {
		cin >> mang[k];
	}
	insertionSort(mang, n);
	cout << "Mang da sap xep la: ";
	for (int k = 0; k < n; k++) {
		cout << mang[k] << " ";
	}
	return 0;
}
Bai 2 :

#include<iostream>
using namespace std;
int Nil(int a) {
	int re = 0;
	if (a < 4) {
		re = -1;
	}
	else {
		int ar[1000];
		int m = 0;
		while (a % 2 == 0) {
			ar[m] = 2;
			a /= 2;
			m += 1;
		}
		for (int i = 3; i * i <= a; i += 2) {
			while (a % i == 0) {
				ar[m] = i;
				a /= i;
				m += 1;
			}
		}
		if (a > 2) {
			ar[m] = a;
			m += 1;
		}
		if (m == 2) {
			re = 0;
		}
		else {
			re = -2;
		}
	}
	return re;
}
void checkBlum(int arr[], int l, int b) {
	int count = 0;
	for (int i = 0; i < l; i++) {
		for (int j = i + 1; j < l; j++) {
			int sum = arr[i] + arr[j];
			if (sum < b) {
				if (Nil(arr[i]) == 0 && Nil(arr[j]) == 0) {
					if (Nil(sum) == 0) {
						cout << "(" << arr[i] << ", " << arr[j] << ") ";
						count += 1;
					}
				}
			}
		}
	}
	if (count == 0) {
		cout << "Khong co cap so thoa man";
	}
}

int main() {
	int N, M;
	cin >> N >> M;
	int mang[1000];
	int bien = 0;
	cout << "Day cac so Blum nho hon " << N << " la: " << endl;
	for (int k = 4; k < N; k++) {
		if (Nil(k) == 0) {
			mang[bien] = k;
			bien += 1;
		}
	}
	for (int k = 0; k < bien; k++) {
		cout << mang[k] << " ";
	}
	cout << "\nCac cap so Blum co tong la 1 so Blum nho hon " << N << " la: " << endl;
	checkBlum(mang, bien, N);
	int j;
	if (Nil(M) == 0) {
		for (j = 0; j < bien; j++) {
			if (mang[j] == M) {
				cout << "\nSo Blum M co ton tai trong day" << endl;
				break;
			}
		}
		if (j == bien) {
			cout << "\nKhong ton tai so Blum M trong day" << endl;
		}
	}
	else {
		cout << "\nSo M nhap vao khong phai 1 so Blum";
	}
	return 0;
}
