#pragma once
#include "SDL.h"

class HUD
{
public:

	virtual ~HUD(){}

	virtual void draw() const = 0;

	virtual void update(SDL_Rect Camera, int contador) = 0;

};

