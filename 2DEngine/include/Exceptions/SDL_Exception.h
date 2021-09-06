#ifndef WITZ_ENGINE_EXCEPTION_H
#define WITZ_ENGINE_EXCEPTION_H

#include <exception>

namespace WitzEngine
{
	class SDL_Exception : public std::exception {
	public:
		SDL_Exception(const char* message) : message(message) {}

		virtual const char* what() const throw() {
			return message;
		}

		const char* message;
	};
}

#endif //WITZ_ENGINE_EXCEPTION_H