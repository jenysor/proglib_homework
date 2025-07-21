#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "movable.h"

class MockMovableObject : public IMovable
{
public:
    MOCK_METHOD(Coordinates, getPosition, (), (override));
    MOCK_METHOD(Coordinates, getSpeed, (), (override));
    MOCK_METHOD(void, setPosition, (const Coordinates& coords), (override));
};

TEST(TestMove, MovableObject_Move_Success)
{
    Coordinates startPosition{.x = 12.0, .y = 5.0};
    Coordinates speed{.x = -7.0, .y = 3.0};

    auto etalonPosition = startPosition + speed;

    auto object = std::make_shared<MockMovableObject>();

    EXPECT_CALL(*object, getPosition()).WillOnce(testing::Invoke([startPosition]() { return startPosition; }));
    EXPECT_CALL(*object, getSpeed()).WillOnce(testing::Invoke([speed]() { return speed; }));
    EXPECT_CALL(*object, setPosition(etalonPosition));

    ASSERT_NO_THROW(Move::move(object));
}

TEST(TestMove, MovableObject_Move_ErrorGetSpeed)
{
    Coordinates startPosition{.x = 12.0, .y = 5.0};
    Coordinates speed{.x = -7.0, .y = 3.0};

    auto object = std::make_shared<MockMovableObject>();

    EXPECT_CALL(*object, getPosition()).WillOnce(testing::Invoke([startPosition]() { return startPosition; }));
    EXPECT_CALL(*object, getSpeed())
        .WillOnce(testing::Invoke(
            [speed]()
            {
                throw std::invalid_argument("can't get speed");
                return speed;
            }));

    ASSERT_THROW(Move::move(object), std::invalid_argument);
}

TEST(TestMove, MovableObject_Move_ErrorGetPosition)
{
    Coordinates startPosition{.x = 12.0, .y = 5.0};

    auto object = std::make_shared<MockMovableObject>();

    EXPECT_CALL(*object, getPosition()).WillOnce(testing::Invoke([startPosition]()
    {
        throw std::invalid_argument("can't get position");
        return startPosition;
    }));

    ASSERT_THROW(Move::move(object), std::invalid_argument);
}
