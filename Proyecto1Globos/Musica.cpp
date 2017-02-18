#include "Musica.h"

Musica::Musica()
{
	
}
void Musica::load(){
	/*
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	pMusic = Mix_LoadMUS("..\\bmps\\Megalovania.mp3");		//Dirección del archivo de audio
	
	Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 4096);
	pMusic = Mix_LoadWAV(".. / bmps / Ghost.wav");	
	*/
}
void Musica::play(){

	/*Mix_VolumeChunk(pMusic, 100);
	Mix_AllocateChannels(2);
	Mix_PlayChannel(1, pMusic, -1);
	*/
}

Musica::~Musica()
{
}
