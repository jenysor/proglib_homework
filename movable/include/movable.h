#ifndef PROGLIB_HOMEWORK_MOVABLE_H
#define PROGLIB_HOMEWORK_MOVABLE_H

#include <memory>
#include <ostream>

struct Coordinates
{
    double x;
    double y;

    bool operator==(const Coordinates& coords) const;
};

inline Coordinates operator+(const Coordinates& first, const Coordinates& second)
{
    return Coordinates({first.x + second.x, first.y + second.y});
}

inline std::ostream& operator<<(std::ostream& out, const Coordinates& coords)
{
    out << "(" << coords.x << ", " << coords.y << ")";
    return out;
}

class IMovable
{
public:
    virtual Coordinates getPosition() = 0;
    virtual Coordinates getVelocity() = 0;
    virtual void setPosition(const Coordinates& coords) = 0;

    virtual ~IMovable() = default;
};

class Move
{
public:
    Move() = default;

    static void move(std::shared_ptr<IMovable> object);
};

#endif // PROGLIB_HOMEWORK_MOVABLE_H
