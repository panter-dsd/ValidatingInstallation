/*
    Boost Software License - Version 1.0 - August 17th, 2003

    Permission is hereby granted, free of charge, to any person or organization
    obtaining a copy of the software and accompanying documentation covered by
    this license (the "Software") to use, reproduce, display, distribute,
    execute, and transmit the Software, and to prepare derivative works of the
    Software, and to permit third-parties to whom the Software is furnished to
    do so, all subject to the following:

    The copyright notices in the Software and this entire statement, including
    the above license grant, this restriction and the following disclaimer,
    must be included in all copies of the Software, in whole or in part, and
    all derivative works of the Software, unless such copies or derivative
    works are solely in the form of machine-executable object code generated by
    a source language processor.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
    SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
    FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
    ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
    DEALINGS IN THE SOFTWARE.
*/


#ifndef SERVICECHECKER_H
#define SERVICECHECKER_H

#include "abstractchecker.h"

class ServiceChecker : public AbstractChecker
{

public:
	ServiceChecker ();
	virtual ~ServiceChecker();

private:
	ServiceChecker (const ServiceChecker& other);
	ServiceChecker& operator= (const ServiceChecker& other);

	AbstractChecker* clone_p () const {
		return new ServiceChecker ();
	}
	virtual bool parse_p (int argc, char** argv);
	virtual int check_p (int argc, char** argv);
	
private:
	std::string host;
	int port;
	std::string connectionString;
	std::string connectionAnswer;
	std::string question;
	std::string answer;
};

#endif // SERVICECHECKER_H
