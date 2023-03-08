#pragma once
class Circle {
public:
	Circle(int centerX, int centerY, int radioss) {
		this->centerX = centerX;
		this->centerY = centerY; 
		this->radioss = radioss;
	}
	int radios() {
		return radioss;
	}
	int getCenterX() {
		return centerX;
	}
	int getCenterY() {
		return centerY;
	}
	bool valid() {
		if (centerX < 0 || centerY < 0) {
			return false;
		}
		return true;
	}
private:
	int centerX,centerY;
	int radioss;
};