#pragma once
class HUD
{
public:

	virtual ~HUD(){}

	virtual void draw() const = 0;

	virtual void update() = 0;



};

