#pragma once

#include "raylib.h"

class PaintDrop
{
public:
	Vector2 position;
	float size;
	Rectangle rect;

	Color color;

    PaintDrop(Vector2 position, Color color, float size);
	void draw();
};

