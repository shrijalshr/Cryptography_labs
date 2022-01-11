#include <iostream>
#include <string>

int main()
{
	int i, j, len, rails, count, code[100][1000];
	std::string str;
	std::cout << "Enter a Secret Message\n";
	std::cin >> str;
	len = str.length();
	std::cout << "Enter number of rails: ";
	std::cin >> rails;

	for (i = 0; i < rails; i++) {
		for (j = 0; j < len; j++)
			code[i][j] = 0;
	}
	count = 0;
	j = 0;

	while (j < len) {
		if (count % 2 == 0) {
			for (i = 0; i < rails; i++) {
				// strcpy(code[i][j],str[j]);
				code[i][j] = (int)str[j];
				j++;
			}
		}
		else {
			for (i = rails - 2; i > 0; i--) {
				code[i][j] = (int)str[j];
				j++;
			}
		}

		count++;
	}

	for (i = 0; i < rails; i++) {
		for (j = 0; j < len; j++) {
			if (code[i][j] != 0)
				std::cout << code[i][j];
		}
	}
	std::cout << std::endl;
}
