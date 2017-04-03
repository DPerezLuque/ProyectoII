#include "Musica.h"

Musica::Musica(){
	pMusic = nullptr;	
}

Musica::Musica(string nombArch)
{	
	if (pMusic == nullptr) {
		load(nombArch);
		Mix_Init(27);
		Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
		Mix_VolumeMusic(80);
	}
}


Musica::~Musica()
{
	close();
}

bool Musica::load(string const& nombArch){
	close();
	pMusic = Mix_LoadMUS(nombArch.c_str());	

	bool culo = pMusic == nullptr;
	cout << culo;

	return pMusic != nullptr;

}

void Musica::pause(){
	Mix_PauseMusic();
}
void Musica::play(){
	Mix_PlayMusic(pMusic, -1);
	cout << "Playing music\n";
}

void Musica::close(){
	if (pMusic != nullptr){
		Mix_FreeMusic(pMusic);
		pMusic = nullptr;
	}
}