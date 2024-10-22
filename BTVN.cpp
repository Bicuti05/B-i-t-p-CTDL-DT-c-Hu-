#include <iostream>
using namespace std;

//Tim so nam co so dan giong nhau
void findsamePopulation(int a[], int m) {
	int dem = 0;
	int mang[100];
	int tanso[100];

	mang[0] = a[0];
	tanso[0] = 1;

	for (int i = 1; i < m; i++) {
		bool found = false;
		for (int j = 0; j <= dem; j++) {
			if (a[i] == mang[j]) {
				tanso[j] += 1;
				found = true;
				break;
			}
		}
		if (!found) {
			dem += 1;
			mang[dem] = a[i];
			tanso[dem] = 1;
		}
	}
	//Phan nay de in ra so luong dan so theo thu tu tang dan ve so dan

	/*for (int i = 0; i < dem + 1; i++) {
		for (int j = i + 1; j < dem + 1; j++) {
			if (mang[i] > mang[j]) {
				int mid = mang[i];
				mang[i] = mang[j];
				mang[j] = mid;

				int t_g = tanso[i];
				tanso[i] = tanso[j];
				tanso[j] = t_g;
			}
		}
	}*/
	for (int i = 0; i <= dem; i++) {
		cout << "So nam co " << mang[i] << " nguoi la: " << tanso[i] << " nam\n";
	}
}

//In ra so dan lon nhat trong danh sach
int findmax(int a[], int m) {
	int max = a[0];

	for (int i = 0; i < m; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}

	return max;
}

//In ra so dan nho nhat trong danh sach
int findmin(int a[], int m) {
	int min = a[0];

	for (int i = 0; i < m; i++) {
		if (a[i] < min){
			min = a[i];
		}
	}

	return min;
}

//Tim nhung nam co so dan tuong ung
void findYear(int songuoi, int a[], int b[], int m) {
	for (int i = 0; i < m; i++) {
		if (a[i] == songuoi) {
			cout << b[i] << " ";
		}
	}
}

int main() {
	int n;
	cout << "Nhap tong so nam: ";
	cin >> n;
	
	int year[150], people[150];
	for (int i = 0; i < n; i++) {
		cout << "Nhap nam: ";
		cin >> year[i];
		cout << "So nguoi trong nam " << year[i] << " la: ";
		cin >> people[i];
	}
	
	cout << "Danh sach so dan theo nam: \n";
	for (int i = 0; i < n; i++) {
		cout << year[i] << '\t' << people[i] << '\n';
	}
	/*
	int n = 51;
	int year[150];
	for (int i = 0; i < n; i++) {
		year[i] = i + 1920;
	}
	int people[] = { 19, 77, 40, 90, 2, 25, 54, 17, 79, 6, 44, 24, 14, 4, 95, 47, 66, 48, 23, 98, 15, 86, 25, 50, 9, 29, 64, 3, 67, 4, 90, 81, 74, 34, 98, 13, 87, 96, 56, 90, 49, 85, 94, 66, 19, 95, 47, 42, 65, 87, 11 };*/

	findsamePopulation(people, n);
	int maxPeople = findmax(people, n);
	int minPeople = findmin(people, n);

	cout << "Cac nam co so nguoi sinh ra lon nhat la: ";
	findYear(maxPeople, people, year, n);

	cout << "\nCac nam co so nguoi sinh ra nho nhat la: ";
	findYear(minPeople, people, year, n);

	return 0;
}