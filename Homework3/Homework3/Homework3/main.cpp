#include <iostream>
using namespace std;

void psum1(float a[], float p[], long n) {
	long i;
	p[0] = a[0];
	for (i = 1; i < n; i++)
		p[i] = p[i - 1] + a[i];
}

void psum2(float a[], float p[], long n) {
	long i;
	p[0] = a[0];
	for (i = 1; i < n - 1; i += 2) {
		float mid_val = p[i - 1] + a[i];
		p[i] = mid_val;
		p[i + 1] = mid_val + a[i + 1];
	}
	/* For even n, finish remaining element */
	if (i < n)
		p[i] = p[i - 1] + a[i];
}

void psum1a(float a[], float p[], long n) {
	long i;
	/* last_val holds p[i-1]; val holds p [i] */
	float last_val, val;
	last_val = p[0] = a[0];
	for (i = 1; i < n; i++) {
		val = last_val + a[i];
		p[i] = val;
		last_val = val;
	}
}

void psum3(float a[], float p[], long n) {
	long i;
	float mid_val, temp1, temp2, temp3;
	p[0] = a[0];
	for (i = 1; i < n - 3; i += 4) {
		mid_val = p[i - 1] + a[i];
		temp1 = mid_val + a[i + 1];
		temp2 = temp1 + a[i + 2];
		temp3 = temp2 + a[i + 3];

		p[i] = mid_val;
		p[i + 1] = temp1;
		p[i + 2] = temp2;
		p[i + 3] = temp3;
		mid_val = p[i + 3];
	/*	p[i] = mid_val;
		p[i + 1] = mid_val + a[i + 1];
		p[i + 2] = mid_val + a[i + 1] + a[i + 2];
		mid_val = p[i + 2];*/
	}
	/* finish remaining elements */
	for (; i < n; i++) {
		mid_val += a[i];
		p[i] = mid_val;
	}
}

int main() {
	float a[5] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
	float p[5];
	psum1(a, p, 5);
	for (int i = 0; i < 5; i++)
		cout << p[i] << endl;
	cout << endl;
	psum2(a, p, 5);
	for (int i = 0; i < 5; i++)
		cout << p[i] << endl;
	cout << endl;
	psum3(a, p, 5);
	for (int i = 0; i < 5; i++)
		cout << p[i] << endl;
}