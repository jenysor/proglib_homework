#ifndef PROGLIB_HOMEWORK_ROTATING_H
#define PROGLIB_HOMEWORK_ROTATING_H

#ifdef ROTATING_EXPORTS
#define ROTATING_API __declspec(dllexport)
#else
#define ROTATING_API __declspec(dllimport)
#endif

class ROTATING_API IRotating {};

class ROTATING_API Rotate : public IRotating{};

#endif //PROGLIB_HOMEWORK_ROTATING_H
