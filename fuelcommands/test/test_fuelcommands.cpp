#include "fuelcommands.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

class MockUObject : public IUObject {
public:
	MOCK_METHOD(void, setProperty, (const std::string&, const std::string&), (override));
	MOCK_METHOD(std::string, getProperty, (const std::string&), (const override));
	MOCK_METHOD(bool, hasProperty, (const std::string&), (const override));
	MOCK_METHOD(void, removeProperty, (const std::string&), (override));
};

TEST(CheckFuelCommand, CheckFuelCommand_Execute_EnoughFuel)
{
	double fuel{7.0};
	double velocity{4.5};

	auto object = std::make_shared<MockUObject>();

	CheckFuelCommand command(object);

	EXPECT_CALL(*object, hasProperty("velocity")).WillOnce(testing::Invoke([]() {
		return true;
	}));

	EXPECT_CALL(*object, getProperty("velocity")).WillOnce(testing::Invoke([velocity]() {
		return std::to_string(velocity);
	}));

	EXPECT_CALL(*object, hasProperty("fuel")).WillOnce(testing::Invoke([]() {
		return true;
	}));

	EXPECT_CALL(*object, getProperty("fuel")).WillOnce(testing::Invoke([fuel]() {
		return std::to_string(fuel);
	}));

	ASSERT_NO_THROW(command.execute());
}

TEST(CheckFuelCommand, CheckFuelCommand_Execute_NotEnoughFuel)
{
	double fuel{4.5};
	double velocity{7.0};

	auto object = std::make_shared<MockUObject>();

	CheckFuelCommand command(object);

	EXPECT_CALL(*object, hasProperty("velocity")).WillOnce(testing::Invoke([]() {
		return true;
	}));

	EXPECT_CALL(*object, getProperty("velocity")).WillOnce(testing::Invoke([velocity]() {
		return std::to_string(velocity);
	}));

	EXPECT_CALL(*object, hasProperty("fuel")).WillOnce(testing::Invoke([]() {
		return true;
	}));

	EXPECT_CALL(*object, getProperty("fuel")).WillOnce(testing::Invoke([fuel]() {
		return std::to_string(fuel);
	}));

	ASSERT_THROW(command.execute(), CommandException);
}

TEST(BurnFuelCommand, BurnFuelCommand_Execute_Success)
{
	double fuel{7.0};
	double velocity{4.5};
	double remain = fuel - velocity;

	auto object = std::make_shared<MockUObject>();

	BurnFuelCommand command(object);

	EXPECT_CALL(*object, hasProperty("velocity")).WillOnce(testing::Invoke([]() {
		return true;
	}));

	EXPECT_CALL(*object, getProperty("velocity")).WillOnce(testing::Invoke([velocity]() {
		return std::to_string(velocity);
	}));

	EXPECT_CALL(*object, hasProperty("fuel")).WillOnce(testing::Invoke([]() {
		return true;
	}));

	EXPECT_CALL(*object, getProperty("fuel")).WillOnce(testing::Invoke([fuel]() {
		return std::to_string(fuel);
	}));

	EXPECT_CALL(*object, setProperty("fuel", std::to_string(remain)));

	ASSERT_NO_THROW(command.execute());
}