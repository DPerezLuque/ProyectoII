#pragma once
/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, strings, and file streams
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <fstream>

//Screen dimension constants
//const int SCREEN_WIDTH = 640;
//const int SCREEN_HEIGHT = 480;

//The dimensions of the level
//const int LEVEL_WIDTH = 1536; // TAMAÑO EN X DEL TILE * COLUMNAS DEL TXT	10*24
//const int LEVEL_HEIGHT = 640; // TAMAÑO EN X DEL TILE * FILAS DEL TXT
							  
//The dimensions of the level
const int LEVEL_WIDTH = 2560; // TAMAÑO EN X DEL TILE * COLUMNAS DEL TXT	115*40
const int LEVEL_HEIGHT = 7360; // TAMAÑO EN X DEL TILE * FILAS DEL TXT

//Tile constants (INDIVIDUAL)
const int TILE_WIDTH = 64;
const int TILE_HEIGHT = 64;
const int TOTAL_TILES = 4600;       // FILAS * COLUMNAS DEL TXT
const int TOTAL_TILE_SPRITES = 51; //TIPOS DISTINTOS DE SPRITES
//DECLARACION DE TILES
const int TILE_TOPLEFT = 0;
const int TILE_TOPMIDDLE = 1;
const int TILE_TOPRIGHT = 2;
const int TILE_LEFT = 3;
const int TILE_RIGHT = 4;
const int TILE_DOWNLEFT = 5;
const int TILE_DOWNMIDDLE = 6;
const int TILE_DOWNRIGHT = 7;
const int TILE_LEFTMIDDLE = 8;
const int TILE_RIGHTMIDDLE = 9;
const int TILE_DOORIGHT = 10;
const int TILE_DOORLEFT = 11;
const int TILE_DOORTOP = 12;
const int TILE_LEFTDOWN = 13;
const int TILE_RIGHTDOWN = 14;
const int TILE_DOORDOWN = 15;
const int TILE_FRAGTOP = 16;
const int TILE_FRAGRIGHT = 17;
const int TILE_FRAGDOWN = 18;
const int TILE_FRAGLEFT = 19;
const int TILE_FLOORCRACKED0 = 20;
const int TILE_FLOORWSHADOW = 21;
const int TILE_BLOCKTOP = 22;
const int TILE_BLOCKRIGHT = 23;
const int TILE_BLOCKDOWN = 24;
const int TILE_BLOCKALTRIGHT = 25;
const int TILE_GIROTOPLEFT = 26;
const int TILE_GIROTOPRIGHT = 27;
const int TILE_FLOORCRACKED1 = 28;
const int TILE_FLOORCRACKED2 = 29;
const int TILE_BLOCKLEFT = 30;
const int TILE_BLOCKALTTOP = 31;
const int TILE_BLOCKALTLEFT = 32;
const int TILE_BLOCKALTDOWN = 33;
const int TILE_GIRODOWNLEFT = 34;
const int TILE_GIRODOWNRIGHT = 35;
const int TILE_FLOORCRACKED3 = 36;
const int TILE_FLOOR = 37;
const int TILE_CORNERFRAGTOPLEFT = 38;
const int TILE_CORNERFRAGTOPRIGHT = 39;
const int TILE_CORNERTOPLEFT = 40;
const int TILE_CORNERTOPRIGHT = 41;
const int TILE_GIROFRAGTOPLEFT = 42;
const int TILE_GIROFRAGTOPRIGHT = 43;
const int TILE_CORNERFRAGDOWNLEFT = 44;
const int TILE_CORNERFRAGDOWNRIGHT = 45;
const int TILE_CORNERDOWNLEFT = 46;
const int TILE_CORNERDOWNRIGHT = 47;
const int TILE_GIROFRAGDOWNLEFT = 48;
const int TILE_GIROFRAGDOWNRIGHT = 49;
const int TILE_BLACK = 50;

class Tilemap {
public:

	//Texture wrapper class
	class LTexture
	{
	public:
		//Initializes variables
		LTexture();

		//Deallocates memory
		~LTexture();

		//Loads image at specified path
		bool loadFromFile(SDL_Renderer* pRenderer, std::string path);

#ifdef _SDL_TTF_H
		//Creates image from font string
		bool loadFromRenderedText(std::string textureText, SDL_Color textColor);
#endif

		//Deallocates texture
		void free();

		//Set color modulation
		void setColor(Uint8 red, Uint8 green, Uint8 blue);

		//Set blending
		void setBlendMode(SDL_BlendMode blending);

		//Set alpha modulation
		void setAlpha(Uint8 alpha);

		//Renders texture at given point
		void render(SDL_Renderer* pRenderer, int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

		//Gets image dimensions
		int getWidth();
		int getHeight();

	private:
		//The actual hardware texture
		SDL_Texture* mTexture;

		//Image dimensions
		int mWidth;
		int mHeight;
	};

	//The tile
	class Tile
	{
	public:
		//Initializes position and type
		Tile(int x, int y, int tileType);

		//Shows the tile
		void render(SDL_Renderer* pRenderer, SDL_Rect& camera);

		//Get the tile type
		int getType();

		//Get the collision box
		//SDL_Rect getBox();

	private:
		//The attributes of the tile
		SDL_Rect mBox;

		//The tile type
		int mType;
	};

};
//Starts up SDL and creates window
//bool init();

//Loads media
//bool loadMedia(Tilemap::Tile* tiles[]);

//Frees media and shuts down SDL
//void close(Tilemap::Tile* tiles[]);

//Box collision detector
//bool checkCollision( SDL_Rect a, SDL_Rect b );

//Checks collision box against set of tiles
//bool touchesWall( SDL_Rect box, Tile* tiles[] );

//Sets tiles from tile map
bool setTiles(Tilemap::Tile *tiles[]);

//The window we'll be rendering to
//SDL_Window* pWindow = NULL;

//The window renderer
//SDL_Renderer* pRenderer = NULL;

//Scene textures
Tilemap::LTexture gTileTexture;
SDL_Rect gTileClips[TOTAL_TILE_SPRITES];

Tilemap::LTexture::LTexture()
{
	//Initialize
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

Tilemap::LTexture::~LTexture()
{
	//Deallocate
	free();
}

bool Tilemap::LTexture::loadFromFile(SDL_Renderer* pRenderer, std::string path)
{
	//Get rid of preexisting texture
	//free();

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Color key image
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(pRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		else
		{
			//Get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	//Return success
	mTexture = newTexture;
	return mTexture != NULL;
}

#ifdef _SDL_TTF_H
bool LTexture::loadFromRenderedText(std::string textureText, SDL_Color textColor)
{
	//Get rid of preexisting texture
	free();

	//Render text surface
	SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, textureText.c_str(), textColor);
	if (textSurface != NULL)
	{
		//Create texture from surface pixels
		mTexture = SDL_CreateTextureFromSurface(pRenderer, textSurface);
		if (mTexture == NULL)
		{
			printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
		}
		else
		{
			//Get image dimensions
			mWidth = textSurface->w;
			mHeight = textSurface->h;
		}

		//Get rid of old surface
		SDL_FreeSurface(textSurface);
	}
	else
	{
		printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
	}


	//Return success
	return mTexture != NULL;
}
#endif

void Tilemap::LTexture::free()
{
	//Free texture if it exists
	if (mTexture != NULL)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void Tilemap::LTexture::setColor(Uint8 red, Uint8 green, Uint8 blue)
{
	//Modulate texture rgb
	SDL_SetTextureColorMod(mTexture, red, green, blue);
}

void Tilemap::LTexture::setBlendMode(SDL_BlendMode blending)
{
	//Set blending function
	SDL_SetTextureBlendMode(mTexture, blending);
}

void Tilemap::LTexture::setAlpha(Uint8 alpha)
{
	//Modulate texture alpha
	SDL_SetTextureAlphaMod(mTexture, alpha);
}

void Tilemap::LTexture::render(SDL_Renderer* pRenderer, int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	//Set clip rendering dimensions
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopyEx(pRenderer, mTexture, clip, &renderQuad, angle, center, flip);
}

int Tilemap::LTexture::getWidth()
{
	return mWidth;
}

int Tilemap::LTexture::getHeight()
{
	return mHeight;
}

Tilemap::Tile::Tile(int x, int y, int tileType)
{
	//Get the offsets
	mBox.x = x;
	mBox.y = y;

	//Set the collision box
	mBox.w = TILE_WIDTH;
	mBox.h = TILE_HEIGHT;

	//Get the tile type
	mType = tileType;
}

void Tilemap::Tile::render(SDL_Renderer* pRenderer ,SDL_Rect& camera)
{
	gTileTexture.render(pRenderer, mBox.x - camera.x, mBox.y - camera.y, &gTileClips[mType]);
	//If the tile is on screen
	/* if( checkCollision( camera, mBox ) )
	{
	//Show the tile

	}*/
}

int Tilemap::Tile::getType()
{
	return mType;
}
/*
SDL_Rect Tilemap::Tile::getBox()
{
return mBox;
}
*/
/*
bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		pWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (pWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create renderer for window
			pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (pRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(pRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}
*/

/*
bool loadMedia(Tilemap::Tile* tiles[])
{
	//Loading success flag
	bool success = true;

	//Load dot texture
	/*if( !gDotTexture.loadFromFile( "39_tiling/dot.bmp" ) )
	{
	printf( "Failed to load dot texture!\n" );
	success = false;
	}
	
	//Load tile texture
	if (!gTileTexture.loadFromFile("39_tiling/sheet2.png"))
	{
		printf("Failed to load tile set texture!\n");
		success = false;
	}

	//Load tile map
	if (!setTiles(tiles))
	{
		printf("Failed to load tile set!\n");
		success = false;
	}

	return success;
}

void close(Tilemap::Tile* tiles[])
{
	//Deallocate tiles
	for (int i = 0; i < TOTAL_TILES; ++i)
	{
		if (tiles[i] == NULL)
		{
			delete tiles[i];
			tiles[i] = NULL;
		}
	}

	//Free loaded images
	//	gDotTexture.free();
	gTileTexture.free();

	//Destroy window	
	SDL_DestroyRenderer(pRenderer);
	SDL_DestroyWindow(pWindow);
	pWindow = NULL;
	pRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}
*/

bool setTiles(Tilemap::Tile* tiles[])
{
	//Success flag
	bool tilesLoaded = true;

	//The tile offsets
	int x = 0, y = 0;

	//Open the map
	std::ifstream map("..\\bmps\\lazy2.map");

	//If the map couldn't be loaded
	if (false) //map == NULL )
	{
		printf("Unable to load map file!\n");
		tilesLoaded = false;
	}
	else
	{
		//Initialize the tiles
		for (int i = 0; i < TOTAL_TILES; ++i)
		{
			//Determines what kind of tile will be made
			int tileType = -1;

			//Read tile from map file
			map >> tileType;

			//If the was a problem in reading the map
			if (map.fail())
			{
				//Stop loading map
				printf("Error loading map: Unexpected end of file!\n");
				tilesLoaded = false;
				break;
			}

			//If the number is a valid tile number
			if ((tileType >= 0) && (tileType < TOTAL_TILE_SPRITES))
			{
				tiles[i] = new Tilemap::Tile(x, y, tileType);
			}
			//If we don't recognize the tile type
			else
			{
				//Stop loading map
				printf("Error loading map: Invalid tile type at %d!\n", i);
				tilesLoaded = false;
				break;
			}

			//Move to next tile spot
			x += TILE_WIDTH;

			//If we've gone too far
			if (x >= LEVEL_WIDTH)
			{
				//Move back
				x = 0;

				//Move to the next row
				y += TILE_HEIGHT;
			}
		}

		//Clip the sprite sheet
		if (tilesLoaded)
		{
			gTileClips[TILE_FRAGTOP].x = 64;
			gTileClips[TILE_FRAGTOP].y = 192;
			gTileClips[TILE_FRAGTOP].w = TILE_WIDTH;
			gTileClips[TILE_FRAGTOP].h = TILE_HEIGHT;

			gTileClips[TILE_FRAGRIGHT].x = 128;
			gTileClips[TILE_FRAGRIGHT].y = 192;
			gTileClips[TILE_FRAGRIGHT].w = TILE_WIDTH;
			gTileClips[TILE_FRAGRIGHT].h = TILE_HEIGHT;

			gTileClips[TILE_FRAGDOWN].x = 192;
			gTileClips[TILE_FRAGDOWN].y = 192;
			gTileClips[TILE_FRAGDOWN].w = TILE_WIDTH;
			gTileClips[TILE_FRAGDOWN].h = TILE_HEIGHT;
			
			gTileClips[TILE_FRAGLEFT].x = 256;
			gTileClips[TILE_FRAGLEFT].y = 192;
			gTileClips[TILE_FRAGLEFT].w = TILE_WIDTH;
			gTileClips[TILE_FRAGLEFT].h = TILE_HEIGHT;

			gTileClips[TILE_FLOORCRACKED0].x = 0;
			gTileClips[TILE_FLOORCRACKED0].y = 256;
			gTileClips[TILE_FLOORCRACKED0].w = TILE_WIDTH;
			gTileClips[TILE_FLOORCRACKED0].h = TILE_HEIGHT;

			gTileClips[TILE_FLOORWSHADOW].x = 64;
			gTileClips[TILE_FLOORWSHADOW].y = 256;
			gTileClips[TILE_FLOORWSHADOW].w = TILE_WIDTH;
			gTileClips[TILE_FLOORWSHADOW].h = TILE_HEIGHT;

			gTileClips[TILE_FLOORCRACKED1].x = 0;
			gTileClips[TILE_FLOORCRACKED1].y = 320;
			gTileClips[TILE_FLOORCRACKED1].w = TILE_WIDTH;
			gTileClips[TILE_FLOORCRACKED1].h = TILE_HEIGHT;

			gTileClips[TILE_FLOORCRACKED2].x = 64;
			gTileClips[TILE_FLOORCRACKED2].y = 320;
			gTileClips[TILE_FLOORCRACKED2].w = TILE_WIDTH;
			gTileClips[TILE_FLOORCRACKED2].h = TILE_HEIGHT;

			gTileClips[TILE_FLOORCRACKED3].x = 0;
			gTileClips[TILE_FLOORCRACKED3].y = 384;
			gTileClips[TILE_FLOORCRACKED3].w = TILE_WIDTH;
			gTileClips[TILE_FLOORCRACKED3].h = TILE_HEIGHT;

			gTileClips[TILE_FLOOR].x = 64;
			gTileClips[TILE_FLOOR].y = 384;
			gTileClips[TILE_FLOOR].w = TILE_WIDTH;
			gTileClips[TILE_FLOOR].h = TILE_HEIGHT;

			gTileClips[TILE_CORNERFRAGTOPLEFT].x = 128;
			gTileClips[TILE_CORNERFRAGTOPLEFT].y = 384;
			gTileClips[TILE_CORNERFRAGTOPLEFT].w = TILE_WIDTH;
			gTileClips[TILE_CORNERFRAGTOPLEFT].h = TILE_HEIGHT;

			gTileClips[TILE_CORNERFRAGTOPRIGHT].x = 192;
			gTileClips[TILE_CORNERFRAGTOPRIGHT].y = 384;
			gTileClips[TILE_CORNERFRAGTOPRIGHT].w = TILE_WIDTH;
			gTileClips[TILE_CORNERFRAGTOPRIGHT].h = TILE_HEIGHT;

			gTileClips[TILE_GIROFRAGTOPLEFT].x = 320;
			gTileClips[TILE_GIROFRAGTOPLEFT].y = 384;
			gTileClips[TILE_GIROFRAGTOPLEFT].w = TILE_WIDTH;
			gTileClips[TILE_GIROFRAGTOPLEFT].h = TILE_HEIGHT;

			gTileClips[TILE_GIROFRAGTOPLEFT].x = 384;
			gTileClips[TILE_GIROFRAGTOPLEFT].y = 384;
			gTileClips[TILE_GIROFRAGTOPLEFT].w = TILE_WIDTH;
			gTileClips[TILE_GIROFRAGTOPLEFT].h = TILE_HEIGHT;

			gTileClips[TILE_GIROFRAGTOPLEFT].x = 384;
			gTileClips[TILE_GIROFRAGTOPLEFT].y = 384;
			gTileClips[TILE_GIROFRAGTOPLEFT].w = TILE_WIDTH;
			gTileClips[TILE_GIROFRAGTOPLEFT].h = TILE_HEIGHT;

			gTileClips[TILE_BLACK].x = 0;
			gTileClips[TILE_BLACK].y = 448;
			gTileClips[TILE_BLACK].w = TILE_WIDTH;
			gTileClips[TILE_BLACK].h = TILE_HEIGHT;

			gTileClips[TILE_CORNERFRAGDOWNRIGHT].x = 192;
			gTileClips[TILE_CORNERFRAGDOWNRIGHT].y = 448;
			gTileClips[TILE_CORNERFRAGDOWNRIGHT].w = TILE_WIDTH;
			gTileClips[TILE_CORNERFRAGDOWNRIGHT].h = TILE_HEIGHT;

			gTileClips[TILE_GIROFRAGDOWNLEFT].x = 320;
			gTileClips[TILE_GIROFRAGDOWNLEFT].y = 448;
			gTileClips[TILE_GIROFRAGDOWNLEFT].w = TILE_WIDTH;
			gTileClips[TILE_GIROFRAGDOWNLEFT].h = TILE_HEIGHT;

			gTileClips[TILE_GIROFRAGDOWNRIGHT].x = 384;
			gTileClips[TILE_GIROFRAGDOWNRIGHT].y = 448;
			gTileClips[TILE_GIROFRAGDOWNRIGHT].w = TILE_WIDTH;
			gTileClips[TILE_GIROFRAGDOWNRIGHT].h = TILE_HEIGHT;

			






			
			/*
			gTileClips[TILE_TOPLEFT].x = 0;
			gTileClips[TILE_TOPLEFT].y = 0;
			gTileClips[TILE_TOPLEFT].w = TILE_WIDTH;
			gTileClips[TILE_TOPLEFT].h = TILE_HEIGHT;

			gTileClips[TILE_TOPMIDDLE].x = 64;
			gTileClips[TILE_TOPMIDDLE].y = 0;
			gTileClips[TILE_TOPMIDDLE].w = TILE_WIDTH;
			gTileClips[TILE_TOPMIDDLE].h = TILE_HEIGHT;

			gTileClips[TILE_TOPRIGHT].x = 128;
			gTileClips[TILE_TOPRIGHT].y = 0;
			gTileClips[TILE_TOPRIGHT].w = TILE_WIDTH;
			gTileClips[TILE_TOPRIGHT].h = TILE_HEIGHT;

			gTileClips[TILE_LEFT].x = 0;
			gTileClips[TILE_LEFT].y = 32;
			gTileClips[TILE_LEFT].w = TILE_WIDTH;
			gTileClips[TILE_LEFT].h = TILE_HEIGHT;

			gTileClips[TILE_CENTER].x = 32;
			gTileClips[TILE_CENTER].y = 32;
			gTileClips[TILE_CENTER].w = TILE_WIDTH;
			gTileClips[TILE_CENTER].h = TILE_HEIGHT;

			gTileClips[TILE_RIGHT].x = 64;
			gTileClips[TILE_RIGHT].y = 32;
			gTileClips[TILE_RIGHT].w = TILE_WIDTH;
			gTileClips[TILE_RIGHT].h = TILE_HEIGHT;

			gTileClips[TILE_DOWNLEFT].x = 0;
			gTileClips[TILE_DOWNLEFT].y = 64;
			gTileClips[TILE_DOWNLEFT].w = TILE_WIDTH;
			gTileClips[TILE_DOWNLEFT].h = TILE_HEIGHT;

			gTileClips[TILE_DOWN].x = 32;
			gTileClips[TILE_DOWN].y = 64;
			gTileClips[TILE_DOWN].w = TILE_WIDTH;
			gTileClips[TILE_DOWN].h = TILE_HEIGHT;

			gTileClips[TILE_DOWNRIGHT].x = 64;
			gTileClips[TILE_DOWNRIGHT].y = 64;
			gTileClips[TILE_DOWNRIGHT].w = TILE_WIDTH;
			gTileClips[TILE_DOWNRIGHT].h = TILE_HEIGHT;
			/*
			gTileClips[ TILE_RED ].x = 0;
			gTileClips[ TILE_RED ].y = 0;
			gTileClips[ TILE_RED ].w = TILE_WIDTH;
			gTileClips[ TILE_RED ].h = TILE_HEIGHT;

			gTileClips[ TILE_GREEN ].x = 0;
			gTileClips[ TILE_GREEN ].y = 80;
			gTileClips[ TILE_GREEN ].w = TILE_WIDTH;
			gTileClips[ TILE_GREEN ].h = TILE_HEIGHT;

			gTileClips[ TILE_BLUE ].x = 0;
			gTileClips[ TILE_BLUE ].y = 160;
			gTileClips[ TILE_BLUE ].w = TILE_WIDTH;
			gTileClips[ TILE_BLUE ].h = TILE_HEIGHT;

			gTileClips[ TILE_TOPLEFT ].x = 80;
			gTileClips[ TILE_TOPLEFT ].y = 0;
			gTileClips[ TILE_TOPLEFT ].w = TILE_WIDTH;
			gTileClips[ TILE_TOPLEFT ].h = TILE_HEIGHT;

			gTileClips[ TILE_LEFT ].x = 80;
			gTileClips[ TILE_LEFT ].y = 80;
			gTileClips[ TILE_LEFT ].w = TILE_WIDTH;
			gTileClips[ TILE_LEFT ].h = TILE_HEIGHT;

			gTileClips[ TILE_BOTTOMLEFT ].x = 80;
			gTileClips[ TILE_BOTTOMLEFT ].y = 160;
			gTileClips[ TILE_BOTTOMLEFT ].w = TILE_WIDTH;
			gTileClips[ TILE_BOTTOMLEFT ].h = TILE_HEIGHT;

			gTileClips[ TILE_TOP ].x = 160;
			gTileClips[ TILE_TOP ].y = 0;
			gTileClips[ TILE_TOP ].w = TILE_WIDTH;
			gTileClips[ TILE_TOP ].h = TILE_HEIGHT;

			gTileClips[ TILE_CENTER ].x = 160;
			gTileClips[ TILE_CENTER ].y = 80;
			gTileClips[ TILE_CENTER ].w = TILE_WIDTH;
			gTileClips[ TILE_CENTER ].h = TILE_HEIGHT;

			gTileClips[ TILE_BOTTOM ].x = 160;
			gTileClips[ TILE_BOTTOM ].y = 160;
			gTileClips[ TILE_BOTTOM ].w = TILE_WIDTH;
			gTileClips[ TILE_BOTTOM ].h = TILE_HEIGHT;

			gTileClips[ TILE_TOPRIGHT ].x = 240;
			gTileClips[ TILE_TOPRIGHT ].y = 0;
			gTileClips[ TILE_TOPRIGHT ].w = TILE_WIDTH;
			gTileClips[ TILE_TOPRIGHT ].h = TILE_HEIGHT;

			gTileClips[ TILE_RIGHT ].x = 240;
			gTileClips[ TILE_RIGHT ].y = 80;
			gTileClips[ TILE_RIGHT ].w = TILE_WIDTH;
			gTileClips[ TILE_RIGHT ].h = TILE_HEIGHT;

			gTileClips[ TILE_BOTTOMRIGHT ].x = 240;
			gTileClips[ TILE_BOTTOMRIGHT ].y = 160;
			gTileClips[ TILE_BOTTOMRIGHT ].w = TILE_WIDTH;
			gTileClips[ TILE_BOTTOMRIGHT ].h = TILE_HEIGHT;
			/*
			gTileClips[TILE_BLANK1].x = 320;
			gTileClips[TILE_BLANK1].y = 0;
			gTileClips[TILE_BLANK1].w = TILE_WIDTH;
			gTileClips[TILE_BLANK1].h = TILE_HEIGHT;

			gTileClips[TILE_BLANK2].x = 320;
			gTileClips[TILE_BLANK2].y = 80;
			gTileClips[TILE_BLANK2].w = TILE_WIDTH;
			gTileClips[TILE_BLANK2].h = TILE_HEIGHT;

			gTileClips[TILE_BLANK3].x = 320;
			gTileClips[TILE_BLANK3].y = 160;
			gTileClips[TILE_BLANK3].w = TILE_WIDTH;
			gTileClips[TILE_BLANK3].h = TILE_HEIGHT;
			*/
		}
	}

	//Close the file
	map.close();

	//If the map was loaded fine
	return tilesLoaded;
}
/*
bool touchesWall( SDL_Rect box, Tile* tiles[] )
{
//Go through the tiles
for( int i = 0; i < TOTAL_TILES; ++i )
{
//If the tile is a wall type tile
if( ( tiles[ i ]->getType() >= TILE_CENTER ) && ( tiles[ i ]->getType() <= TILE_TOPLEFT ) )
{
//If the collision box touches the wall tile
if( checkCollision( box, tiles[ i ]->getBox() ) )
{
return true;
}
}
}

//If no wall tiles were touched
return false;
}
*/
/*int main(int argc, char* args[])
{
	//Start up SDL and create window
	//***
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//The level tiles
		Tilemap::Tile* tileSet[TOTAL_TILES];

		//Load media
		if (!loadMedia(tileSet))
		{
			printf("Failed to load media!\n");
		}
		else
		{
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//Level camera
			SDL_Rect camera = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };

			//While application is running
			while (!quit)
			{
				//Handle events on queue
				while (SDL_PollEvent(&e) != 0)
				{
					//User requests quit
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}

				}

				//Clear screen
				SDL_SetRenderDrawColor(pRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(pRenderer);

				//Render level
				for (int i = 0; i < TOTAL_TILES; ++i)
				{
					tileSet[i]->render(camera);
				}

				//Update screen
				SDL_RenderPresent(pRenderer);
			}
		}

		//Free resources and close SDL
		close(tileSet);
	}

	return 0;
}*/