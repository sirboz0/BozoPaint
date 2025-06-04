#include "PaintDrop.h"


PaintDrop::PaintDrop(Vector2 position, Color color, float size) {// constructor, callled when structure is created
	this->position = position;
	this->color = color;
	this->size = 50.0f;
	this->size = size;
	rect = {position.x, position.y, size, size};// last 2 args are the size x & y
	// add every new structure object to the array called "structures", then draw every structure in the array in the mainloop.
	
}

void PaintDrop::draw()
{
	DrawCircle(position.x, position.y, size, color);
}

