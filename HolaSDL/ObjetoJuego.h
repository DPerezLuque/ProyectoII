#pragma once

class ObjetoJuego
{
public:

	virtual ~ObjetoJuego() {}

	virtual void draw() const = 0;

	virtual void update() = 0;

	virtual bool onClick() = 0;
};

