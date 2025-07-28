#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "rotating.h"

class MockRotatingObject : public IRotating
{
public:
    MOCK_METHOD(double, getRotation, (), (override));
    MOCK_METHOD(double, getAngularVelocity, (), (override));
    MOCK_METHOD(void, setRotation, (double rotation), (override));
};

TEST(TestRotate, RotatingObject_Rotate_Success)
{
    double startRotation{10};
    double angularVelocity{5};

    auto etalonRotation = startRotation + angularVelocity;

    auto object = std::make_shared<MockRotatingObject>();

    EXPECT_CALL(*object, getRotation()).WillOnce(testing::Invoke([startRotation]() { return startRotation; }));
    EXPECT_CALL(*object, getAngularVelocity()).WillOnce(testing::Invoke([angularVelocity]() { return angularVelocity; }));
    EXPECT_CALL(*object, setRotation(etalonRotation));

    ASSERT_NO_THROW(Rotate::rotate(object));
}

TEST(TestRotate, RotatingObject_OppositeRotate_Success)
{
    double startRotation{10};
    double angularVelocity{-5};

    auto etalonRotation = startRotation + angularVelocity;

    auto object = std::make_shared<MockRotatingObject>();

    EXPECT_CALL(*object, getRotation()).WillOnce(testing::Invoke([startRotation]() { return startRotation; }));
    EXPECT_CALL(*object, getAngularVelocity()).WillOnce(testing::Invoke([angularVelocity]() { return angularVelocity; }));
    EXPECT_CALL(*object, setRotation(etalonRotation));

    ASSERT_NO_THROW(Rotate::rotate(object));
}

TEST(TestRotate, RotatingObject_Rotate_ErrorGetAngularVelocity)
{
    double startRotation{10};
    double angularVelocity{-5};

    auto object = std::make_shared<MockRotatingObject>();

    EXPECT_CALL(*object, getRotation()).WillOnce(testing::Invoke([startRotation]() { return startRotation; }));
    EXPECT_CALL(*object, getAngularVelocity())
            .WillOnce(testing::Invoke(
                    [angularVelocity]()
                    {
                        throw std::invalid_argument("can't get angular velocity");
                        return angularVelocity;
                    }));

    ASSERT_THROW(Rotate::rotate(object), std::invalid_argument);
}

TEST(TestRotate, RotatingObject_Rotate_ErrorGetRotating)
{
    double startRotation{10};

    auto object = std::make_shared<MockRotatingObject>();

    EXPECT_CALL(*object, getRotation()).WillOnce(testing::Invoke([startRotation]()
                                                                 {
                                                                     throw std::invalid_argument("can't get rotating");
                                                                     return startRotation;
                                                                 }));

    ASSERT_THROW(Rotate::rotate(object), std::invalid_argument);
}