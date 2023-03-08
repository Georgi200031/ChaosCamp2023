#pragma once
class Pixel {
public:
	bool valid() {
		if (x < 0 || y < 0) {
			return false;
		}
	    return true; 
	}
	void setX(int x) {
		this->x = x;
	}
	void setY(int y) {
		this->y = y;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}

private:
	int x, y;
};