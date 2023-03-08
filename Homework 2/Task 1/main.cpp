// ChaosCamp2023 => Task 2 => B.cpp : This file contains the 'main' function. Program execution image.ppm.
//
#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>
#define crtTab "\t"  
#define crtNewLine "\n"

/// Output image resolution
static const int imageWidth = 1920;
static const int imageHeight = 1080;

static const int maxColorComponent = 255;

std::string randColor(int rectIndex) {
	std::string R,G,B;
	if (rectIndex & 1) {
		R = std::to_string(rand() % maxColorComponent);
	}
	else {
		R = "0";
	}
	if (rectIndex & 2) {
		G = std::to_string(rand() % maxColorComponent);
	}
	else {
		G = "0";
	}
	if (rectIndex & 4) {
		B = std::to_string(rand() % maxColorComponent);
	}
	else {
		B = "0";
	}
	return R + " " + G + " " + B;
}

int main() {

	std::ofstream ppmFileStream("output/rectangles.ppm", std::ios::out | std::ios::binary);
	ppmFileStream << "P3\n";
	ppmFileStream << imageWidth << " " << imageHeight << "\n";
	ppmFileStream << maxColorComponent << "\n";

	int heightRect = 160;
	int widthRect = 320;
	int widthRectCount = 100;

	for (int rowIdx = 0; rowIdx < imageHeight; ++rowIdx) {
		for (int colIdx = 0; colIdx < imageWidth; ++colIdx) {
			int rectX = rowIdx / heightRect;
			int rectY = colIdx / widthRect; 
			int rectIndex = (rectX * widthRectCount) + rectY;
			ppmFileStream << randColor(rectIndex) << crtTab;
		}
		ppmFileStream << crtNewLine;
	}

	ppmFileStream.close();
	return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or bug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
