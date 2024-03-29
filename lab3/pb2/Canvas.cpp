#include "Canvas.h"

Canvas::Canvas(int width, int height)
{
	this->width = width;
	this->height = height;
	this->matrix = new char* [width];
	for (int i = 0; i < this->width; i++) {
		this->matrix[i] = new char[height];
	}
	for (int i = 0; i < this->width; i++) {
		for (int j = 0; j < this->height; j++) {
			this->matrix[i][j] = ' ';
		}
	}
}

Canvas::~Canvas()
{
	for (int i = 0; i < this->width; i++) delete this->matrix[i];
	delete this->matrix;
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	for (int i = std::max(x - ray, 0); i <= x + ray && i < width; i++) {
		for (int j = std::max(y - ray, 0); j <= y + ray && j < height; j++) {
			if ((i - x) * (i - x) + (j - y) * (j - y) >= ray * (ray - 1) && (i - x) * (i - x) + (j - y) * (j - y) <= ray * (ray + 1)) {
				this->matrix[i][j] = ch;
			}
		}
	}
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	for (int i = std::max(x - ray, 0); i <= x + ray && i < width; i++) {
		for (int j = std::max(y - ray, 0); j <= y + ray && j < height; j++) {
			if ( (i - x) * (i - x) + (j - y) * (j - y) <= ray * (ray + 1)) {
				this->matrix[i][j] = ch;
			}
		}
	}
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	if (top > 0 && top < this->height)
		for (int i = std::max(0, left); i <= right && i < this->width; i++) {
	
			this->matrix[i][top] = ch;
		}

	if (bottom > 0 && bottom < this->height)
		for (int i = std::max(0, left); i <= right && i < this->width; i++) {

			this->matrix[i][bottom] = ch;
		}

	if (right > 0 && right < this->width)
		for (int i = std::max(0, top); i <= bottom && i < this->height; i++) {

			this->matrix[right][i] = ch;
		}

	if (left > 0 && left < this->width)
		for (int i = std::max(0, top); i <= bottom && i < this->height; i++) {

			this->matrix[left][i] = ch;
		}
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = std::max(0, left); i <= right && i < this->width; i++) {
		for (int j = std::max(top, 0); j <= bottom && j < this->height; j++) {
			this->matrix[i][j] = ch;
		}
	}
}

void Canvas::SetPoint(int x, int y, char ch)
{
	if (x > 0 && x < this->width && y > 0 && y < this->height) {
		this->matrix[x][y] = ch;
	}
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int dx, dy, sx, sy, error, e2;
	dx = std::abs(x2 - x1);
	if (x1 < x2) sx = 1; else sx = -1;
	dy = -std::abs(y2 - y1);
	if (y1 < y2) sy = 1; else sy = -1;
	error = dx + dy;
	while (true) {
		matrix[x1][y1] = ch;
		if (x2 == x1 && y2 == y1) break;
		e2 = 2 * error;
		if (e2 >= dy) {
			if (x1 == x2) break;
			error = error + dy;
			x1 = x1 + sx;
		}
		if (e2 <= dx) {
			if (y1 == y2) break;
			error += dx;
			y1 += sy;

		}

	}

}

void Canvas::Print()
{
	for (int i = 0; i < this->height; i++) {
		for (int j = 0; j < this->width; j++) {
			std::cout << this->matrix[j][i];
		}
		std::cout << '\n';
	}
}

void Canvas::Clear()
{
	for (int i = 0; i < this->width; i++) {
		for (int j = 0; j < this->height; j++) {
			this->matrix[i][j] = ' ';
		}
	}
}
