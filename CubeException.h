#ifndef CUBEEXCEPTION_H
#define CUBEEXCEPTION_H

#include <exception>
using std::exception;
#include <string>

class CubeException : public exception
{
private:
    std::string msg;
    CubeException();
public:
    CubeException(const char* const what);
    CubeException(const std::string& what);
    virtual const char* what() const throw();
    virtual ~CubeException() throw();
};

#endif // CUBEEXCEPTIONS_H
