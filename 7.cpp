#include <iostream>

int main() {
	short x1,x2,y1,y2;
	std::cin>>x1>>y1>>x1>>y1>>x2>>y2;
    abs(x1-x2) != abs(y1-y2) ? std::cout<<"YES" : std::cout<<"NO";
	return 0;
}