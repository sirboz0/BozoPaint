
#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <algorithm>


#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#include "PaintDrop.h"
#include "PaintDropsManager.h"

void log(std::string message);

void readyPaint();
void paintDrops();
void undoLastStructure();
void clearCanvas();

void drawSelectionMenu();

int currentColorNumber = 1;
float paintSize = 20.0f;

bool splashLogoVisible = true;
bool canPaint = true;
// add a thing that you can pull up and down to change paint brush size

int main()
{

	InitWindow(1600, 1200, "Bozo paint");

	
	
	
	
	Texture2D backGroundImage = LoadTexture("path to selected saved image");

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(GRAY);

		if (splashLogoVisible) {
			DrawText("BOZO PAINT", 500, 200, 100.0f, ORANGE);// draw splash if not pressed paint
		}

		currentColorNumber = std::clamp(currentColorNumber, 1, 7);// clamp color number 1 to 3, use switch statement to set all color depends

		
		paintDrops();// paints all structures.
		readyPaint();// checks if user left mouse button is down if so then paint depending on the colormode.
		undoLastStructure();

		drawSelectionMenu();
		
		

		DrawTextureEx(backGroundImage, {0, 0}, 0.0f, 100.0f, WHITE);// draw saved background image(the loaded save image).
		

		EndDrawing();
	}
	CloseWindow();

}

void readyPaint()
{
	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && canPaint) {
		Vector2 mousePos = GetMousePosition();
		splashLogoVisible = false;// hide splash logo if user starts painting.

		switch (currentColorNumber) {// switch statement to check currentStructureNumber and set newer drawn structures color based on currentStructureNumber number.
		case 1: {
			PaintDrop paintDropNew({ mousePos.x, mousePos.y }, BLACK, paintSize);
			PaintDropsManager::PaintDrops.push_back(paintDropNew);
			break;
		}
		case 2: {
			PaintDrop paintDropNew({ mousePos.x, mousePos.y }, RED, paintSize);// if current struct number is 2 then new structures will be red
			PaintDropsManager::PaintDrops.push_back(paintDropNew);
			break;
		}
		case 3: {
			PaintDrop paintDropNew({ mousePos.x, mousePos.y }, BLUE, paintSize);// if current struct number is 2 then new structures will be red
			PaintDropsManager::PaintDrops.push_back(paintDropNew);
			break;
		}
		case 4: {
			PaintDrop paintDropNew({ mousePos.x, mousePos.y }, YELLOW, paintSize);// if current struct number is 2 then new structures will be red
			PaintDropsManager::PaintDrops.push_back(paintDropNew);
			break;
		}
		case 5: {
			PaintDrop paintDropNew({ mousePos.x, mousePos.y }, GREEN, paintSize);// if current struct number is 2 then new structures will be red
			PaintDropsManager::PaintDrops.push_back(paintDropNew);
			break;
		}
		case 6: {
			PaintDrop paintDropNew({ mousePos.x, mousePos.y }, PINK, paintSize);// if current struct number is 2 then new structures will be red
			PaintDropsManager::PaintDrops.push_back(paintDropNew);
			break;
		}
		case 7: {
			PaintDrop paintDropNew({ mousePos.x, mousePos.y }, WHITE, paintSize);// if current struct number is 2 then new structures will be red
			PaintDropsManager::PaintDrops.push_back(paintDropNew);
			break;
		}
		}
	}
}

void paintDrops()// dras every structure(every paint circle)
{
	for (auto& newPaintDrop : PaintDropsManager::PaintDrops) {// loop over all of the structures and call draw function.
		newPaintDrop.draw();
	}
}

void undoLastStructure() {
	if (IsKeyDown(KEY_Z) && !PaintDropsManager::PaintDrops.empty()) {// if pressing z and the structures is not empty then delete last paint circle.
		
		PaintDropsManager::PaintDrops.pop_back();// deletes the latest paint
	}
}



void clearCanvas()
{
	PaintDropsManager::PaintDrops.clear();
}

void log(std::string message) {
	if (message.empty()) return;// if the message is empty then return (dont log the message cause its unnecesary).
	
	std::cout << message;
}

void drawSelectionMenu() {// draws the menu that lets you change painting settings and image like color and load image and clear paint etc.
	// draw selection menu ui

	if (GuiPanel(Rectangle{ 380, 10, 800, 100 }, "")) {
		
	}

	if (GuiButton(Rectangle { 1450, 25, 75, 75}, "CLEAR")) {
		clearCanvas();
	}

	if (GuiButton(Rectangle{ 50, 25, 75, 75 }, "SAVE")) {
		TakeScreenshot("NewBozoPainting.png");
	}
	if (GuiButton(Rectangle{ 150, 25, 75, 75 }, "LOAD")) {
		// open files and then set the background image to the selected image file
	}

	if (GuiButton(Rectangle{ 400, 25, 75, 75 }, "BLACK")) {
		currentColorNumber = 1;
	}
	if (GuiButton(Rectangle{ 500, 25, 75, 75 }, "RED")) {
		currentColorNumber = 2;
	}
	if (GuiButton(Rectangle{ 600, 25, 75, 75 }, "BLUE")) {
		currentColorNumber = 3;
	}
	if (GuiButton(Rectangle{ 700, 25, 75, 75 }, "YELLOW")) {
		currentColorNumber = 4;
	}
	if (GuiButton(Rectangle{ 800, 25, 75, 75 }, "GREEN")) {
		currentColorNumber = 5;
	}
	if (GuiButton(Rectangle{ 900, 25, 75, 75 }, "PINK")) {
		currentColorNumber = 6;
	}
	if (GuiButton(Rectangle{ 900, 25, 75, 75 }, "WHITE")) {
		currentColorNumber = 7;
	}

	if (GuiSlider(Rectangle{ 200, 1100, 1100, 25 }, "SMALL", "BIG", &paintSize, 1.0f, 100.0f)) {
		canPaint = false;
	}
	else {
		canPaint = true;// if finished moving slider then can paint is true
	}
	
	
	

}