#pragma once
//#ifndef ERROR_H
//#define ERROR_H
#include <string>
using namespace std;

class Error { // Clase raíz:
protected:
	string m;
public:
	Error(string const& am) : m(am) {};
	virtual ~Error() {}; // noexcept
	const string & mensaje() const { return m; }; // noexcept
};


class ErrorTextura : public Error {
public:
	ErrorTextura(string const& am) : Error(am) {};
};


/*
class MusicaFalla : public Error {
public:
	MusicaFalla(string const& am) : Error(am) {};
};
*/

//#endif