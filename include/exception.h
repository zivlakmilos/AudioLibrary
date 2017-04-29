#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

#include <exception>
#include <string>
#include <ostream>

class Exception : std::exception
{
public:
    Exception(const std::string &msg) : m_msg(msg) {};
    virtual ~Exception(void) {};

    virtual const char *what(void) const throw() override { return m_msg.c_str(); };

private:
    std::string m_msg;
};

inline std::ostream &operator<<(std::ostream &lhs, const Exception &rhs)
{
    lhs << rhs.what();
}

#endif // _EXCEPTION_H_
