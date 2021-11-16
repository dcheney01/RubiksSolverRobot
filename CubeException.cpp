#include "cubeexception.h"

/**
* Ctor from const char.
* @param what The message.
*/
CubeException::CubeException(const char* const what)
{
    this->msg = what;
}

/**
* Ctor from string.
* @param what The message.
*/
CubeException::CubeException(const std::string& what)
{
    this->msg = what;
}

/**
* Get the exception message.
*/
const char* CubeException::what() const throw()
{
    return this->msg.c_str();
}

//Destructor does not do anything
CubeException::~CubeException() throw() {}
