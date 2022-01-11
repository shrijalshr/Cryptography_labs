#include <iostream>
#include <string>

int main()
{
	std::string message;
	char ch;
	int i, key;

	std::cout << "Enter a message to encrypt: ";
	getline( std::cin, message );

	std::cout << "Enter Key: ";
	std::cin >> key;

	for(i=0;message[i]!='\0';++i) {
		ch=message[i];
		if(ch>='a' && ch<='z') {
			ch=ch+key;
			if(ch>'z') {
				ch=ch-'z'+'a'-1;
			}
			message[i]=ch;
		}
		else if(ch>='A' && ch<='Z') {
			ch=ch+key;
			if(ch>'Z') {
				ch=ch-'Z'+'A'-1;
			}
			message[i]=ch;
		}
	}
	std::cout << "Encrypted msg: " << message;

	return 0;
}
