#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "movable.h"

class MockMovableObject : public IMovable
{
public:
    MOCK_METHOD(double, getPosition, (), (override));
    MOCK_METHOD(double, getVelocity, (), (override));
    MOCK_METHOD(void, setPosition, (double position), (override));
};

TEST(TestMove, MovableObject_Move_Success)
{
    double startPosition{12.0};
    double velocity{ 3.0};

    auto etalonPosition = startPosition + velocity;

    auto object = std::make_shared<MockMovableObject>();

    EXPECT_CALL(*object, getPosition()).WillOnce(testing::Invoke([startPosition]() { return startPosition; }));
    EXPECT_CALL(*object, getVelocity()).WillOnce(testing::Invoke([velocity]() { return velocity; }));
    EXPECT_CALL(*object, setPosition(etalonPosition));

    ASSERT_NO_THROW(Move::move(object));
}

TEST(TestMove, MovableObject_Move_ErrorGetVelocity)
{
    double startPosition{ 5.0};
    double velocity{-7.0};

    auto object = std::make_shared<MockMovableObject>();

    EXPECT_CALL(*object, getPosition()).WillOnce(testing::Invoke([startPosition]() { return startPosition; }));
    EXPECT_CALL(*object, getVelocity())
        .WillOnce(testing::Invoke(
            [velocity]()
            {
                throw std::invalid_argument("can't get velocity");
                return velocity;
            }));

    ASSERT_THROW(Move::move(object), std::invalid_argument);
}

TEST(TestMove, MovableObject_Move_ErrorGetPosition)
{
    double startPosition{12.0};

    auto object = std::make_shared<MockMovableObject>();

    EXPECT_CALL(*object, getPosition())
        .WillOnce(testing::Invoke(
            [startPosition]()
            {
                throw std::invalid_argument("can't get position");
                return startPosition;
            }));

    ASSERT_THROW(Move::move(object), std::invalid_argument);
}

TEST(TestMove, MovableObject_Move_ErrorSetPosition)
{
    double startPosition{ 5.0};
    double velocity{-7.0};

    auto etalonPosition = startPosition + velocity;

    auto object = std::make_shared<MockMovableObject>();

    EXPECT_CALL(*object, getPosition()).WillOnce(testing::Invoke([startPosition]() { return startPosition; }));
    EXPECT_CALL(*object, getVelocity()).WillOnce(testing::Invoke([velocity]() { return velocity; }));
    EXPECT_CALL(*object, setPosition(etalonPosition))
        .WillOnce(testing::Invoke([]() { throw std::runtime_error("can't set position"); }));

    ASSERT_THROW(Move::move(object), std::runtime_error);
}
