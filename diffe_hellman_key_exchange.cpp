#include <iostream>
#include <math.h>

// Power function to return value of a ^ b mod P
long long int power(long long int a, long long int b, long long int P)
{
	if (b == 1)
		return a;

	else
		return (((long long int)pow(a, b)) % P);
}

// Driver program
int main()
{
	long long int P, G, x, a, y, b, ka, kb;

	// Both the persons will be agreed upon the
	// public keys G and P
	P = 23; // A prime number P is taken
	std::cout << "The value of P: " << P << std::endl;

	G = 9; // A primitive root for P, G is taken
	std::cout << "The value of G: " << G << std::endl;

	// Alice will choose the private key a
	a = 4; // a is the chosen private key
	std::cout << "The private key a for Alice : " << a << std::endl;
	x = power(G, a, P); // gets the generated key

	// Bob will choose the private key b
	b = 3; // b is the chosen private key
	std::cout << "The private key b for Bob : " << b << std::endl;
	y = power(G, b, P); // gets the generated key

	// Generating the secret key after the exchange
	// of keys
	ka = power(y, a, P); // Secret key for Alice
	kb = power(x, b, P); // Secret key for Bob

	std::cout << "Secret key for the Alice is : " << ka << std::endl;
	std::cout << "Secret Key for the Bob is : " << kb << std::endl;

	return 0;
}
