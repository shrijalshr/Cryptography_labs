#include <iostream>
#include <math.h>

// to find gcd
int gcd(int a, int h)
{
	int temp;
	while (1)
	{
		temp = a % h;
		if (temp == 0)
			return h;
		a = h;
		h = temp;
	}
}

int main()
{
	// 2 random prime numbers
	double p = 3;
	double q = 7;
	double n = p * q;
	double count;
	double totient = (p - 1) * (q - 1);

	// public key
	// e stands for encrypt
	double e = 2;

	// for checking co-prime which satisfies e>1
	while (e < totient)
	{
		count = gcd(e, totient);
		if (count == 1)
			break;
		else
			e++;
	}

	// private key
	// d stands for decrypt
	double d;

	// k can be any arbitrary value
	double k = 2;

	// choosing d such that it satisfies d*e = 1 + k * totient
	d = (1 + (k * totient)) / e;
	double msg = 12;
	double c = pow(msg, e);
	double m = pow(c, d);
	c = fmod(c, n);
	m = fmod(m, n);

	std::cout << "Message data = " << msg;
	std::cout << "\np = " << p;
	std::cout << "\nq = " << q;
	std::cout << "\nn = pq = " << n;
	std::cout << "\ntotient = " << totient;
	std::cout << "\ne = " << e;
	std::cout << "\nd = " << d;
	std::cout << "\nEncrypted data = " << c;
	std::cout << "\nOriginal Message Sent = " << m;

	return 0;
}
