#ifndef PROGLIB_HOMEWORK_MOVABLE_H
#define PROGLIB_HOMEWORK_MOVABLE_H

#ifdef MOVABLE_EXPORTS
#define MOVABLE_API __declspec(dllexport)
#else
#define MOVABLE_API __declspec(dllimport)
#endif

class MOVABLE_API IMovable {};

class MOVABLE_API Move : public IMovable{};

#endif //PROGLIB_HOMEWORK_MOVABLE_H
