// ChaosCamp2023 => Task 2 => B.cpp : This file contains the 'main' function. Program execution image.ppm.
//
#include <iostream>
#include <fstream>
#include "Pixel.h"
#include "Circle.h"
#include "Color.h"
#include <assert.h>
#define crtTab "\t"  
#define crtNewLine "\n"

/// Output image resolution
static const int imageWidth = 1920;
static const int imageHeight = 1080;

static const int maxColorComponent = 255;

bool pixelInCircle(Pixel& pixel, Circle& circle) {
	assert(pixel.valid() && circle.radios() >= 0 && circle.radios() <= imageWidth);
	const int verticalDist = pixel.getX() - circle.getCenterX();
	const int horizontalDist = pixel.getY() - circle.getCenterY();
	const int distSquared = (verticalDist * verticalDist) + (horizontalDist * horizontalDist);

	return distSquared <= (circle.radios() * circle.radios());
}

int main() {

	std::ofstream ppmFileStream("output/circle.ppm", std::ios::out | std::ios::binary);
	ppmFileStream << "P3\n";
	ppmFileStream << imageWidth << " " << imageHeight << "\n";
	ppmFileStream << maxColorComponent << "\n";

	Pixel pixel;
	Circle circle(imageHeight / 2, imageWidth / 2, 200);

	Color colorBackground(135, 140, 135);
	Color colorCircle(0, 128, 0);

	//for fast tracing
	//std::string circleColor = colorCircle.RGB();
	//std::string backgroundColor = colorBackground.RGB();

	for (int rowIdx = 0; rowIdx < imageHeight; ++rowIdx) {
		for (int colIdx = 0; colIdx < imageWidth; ++colIdx) {
			pixel.setX(rowIdx);
			pixel.setY(colIdx);

			if (pixelInCircle(pixel, circle)) {
				ppmFileStream << colorCircle.RGB() << crtTab;
			}

			else {
				ppmFileStream << colorBackground.RGB() << crtTab;
			}
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
