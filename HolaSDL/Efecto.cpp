#include "Efecto.h"

Efecto::Efecto(){
	pChunk = nullptr;
}
Efecto::Efecto(string nombArch)
{
	if (pChunk == nullptr){
		load(nombArch);
		Mix_Init(27);
		Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
		Mix_Volume(1, MIX_MAX_VOLUME);
	}
}

Efecto::~Efecto()
{
	//close();
}

void Efecto::play(){
	if (pChunk != nullptr){
		Mix_PlayChannel(-1, pChunk, 0);
	}
}
bool Efecto::load(string const& nombArch){
	close();
	pChunk = Mix_LoadWAV(nombArch.c_str()); // .wav, ogg, … 
	return pChunk != nullptr;
}
void Efecto::close(){
	Mix_FreeChunk(pChunk);
}

