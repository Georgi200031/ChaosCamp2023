#pragma once
#include <string>
class Color {
public:
    Color(int R,int G,int B) {
		this->R = R;
		this->G = G;
		this->B = B; 
    }
    std::string RGB() {
	return std::to_string(R) + " " + std::to_string(G) + " " + std::to_string(B);
    }
private:
	int R, G, B;
};