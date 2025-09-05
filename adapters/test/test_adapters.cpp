#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "adapters.h"

class MockUObject : public IUObject {
public:
	MOCK_METHOD(void, setProperty, (const std::string&, const std::string&), (override));
	MOCK_METHOD(std::string, getProperty, (const std::string&), (const override));
	MOCK_METHOD(bool, hasProperty, (const std::string&), (const override));
	MOCK_METHOD(void, removeProperty, (const std::string&), (override));
};

TEST(TestMovableAdapter, MovableAdapter_SetPosition_Success)
{
	std::string property{"position"};
	double value{11.4};

	auto object = std::make_shared<MockUObject>();

	EXPECT_CALL(*object, setProperty(property, std::to_string(value)));

	MovableAdapter adapter(object);

	ASSERT_NO_THROW(adapter.setPosition(11.4));
}

TEST(TestMovableAdapter, MovableAdapter_GetPosition_Success)
{
	std::string property{"position"};
	double value{11.4};

	auto object = std::make_shared<MockUObject>();

	EXPECT_CALL(*object, hasProperty(property)).WillOnce(testing::Invoke([value]() {
		return true;
	}));

	EXPECT_CALL(*object, getProperty(property)).WillOnce(testing::Invoke([value]() {
		return std::to_string(value);
	}));

	MovableAdapter adapter(object);

	ASSERT_NO_THROW(adapter.getPosition());
}

TEST(TestMovableAdapter, MovableAdapter_GetPosition_ErrorGetPosition)
{
	std::string property{"position"};

	auto object = std::make_shared<MockUObject>();

	EXPECT_CALL(*object, hasProperty(property)).WillOnce(testing::Invoke([]() {
		return false;
	}));

	MovableAdapter adapter(object);

	ASSERT_THROW(adapter.getPosition(),std::invalid_argument);
}

TEST(TestMovableAdapter, MovableAdapter_GetVelocity_Success)
{
	std::string property{"velocity"};
	double value{11.4};

	auto object = std::make_shared<MockUObject>();

	EXPECT_CALL(*object, hasProperty(property)).WillOnce(testing::Invoke([value]() {
		return true;
	}));

	EXPECT_CALL(*object, getProperty(property)).WillOnce(testing::Invoke([value]() {
		return std::to_string(value);
	}));

	MovableAdapter adapter(object);

	ASSERT_NO_THROW(adapter.getVelocity());
}

TEST(TestMovableAdapter, MovableAdapter_GetVelocity_ErrorGetVelocity)
{
	std::string property{"velocity"};

	auto object = std::make_shared<MockUObject>();

	EXPECT_CALL(*object, hasProperty(property)).WillOnce(testing::Invoke([]() {
		return false;
	}));

	MovableAdapter adapter(object);

	ASSERT_THROW(adapter.getVelocity(),std::invalid_argument);
}

TEST(TestVelocityAdapter, VelocityAdapter_SetVelocity_Success)
{
	std::string property{"velocity"};
	double value{11.4};

	auto object = std::make_shared<MockUObject>();

	EXPECT_CALL(*object, setProperty(property, std::to_string(value)));

	VelocityAdapter adapter(object);

	ASSERT_NO_THROW(adapter.setVelocity(11.4));
}

TEST(TestVelocityAdapter, VelocityAdapter_GetVelocity_Success)
{
	std::string property{"velocity"};
	double value{11.4};

	auto object = std::make_shared<MockUObject>();

	EXPECT_CALL(*object, hasProperty(property)).WillOnce(testing::Invoke([value]() {
		return true;
	}));

	EXPECT_CALL(*object, getProperty(property)).WillOnce(testing::Invoke([value]() {
		return std::to_string(value);
	}));

	VelocityAdapter adapter(object);

	ASSERT_NO_THROW(adapter.getVelocity());
}

TEST(TestVelocityAdapter, VelocityAdapter_GetVelocity_ErrorGetVelocity)
{
	std::string property{"velocity"};

	auto object = std::make_shared<MockUObject>();

	EXPECT_CALL(*object, hasProperty(property)).WillOnce(testing::Invoke([]() {
		return false;
	}));

	VelocityAdapter adapter(object);

	ASSERT_THROW(adapter.getVelocity(),std::invalid_argument);
}

TEST(TestVelocityAdapter, VelocityAdapter_RemoveVelocity_Success)
{
	std::string property{"velocity"};

	auto object = std::make_shared<MockUObject>();

	EXPECT_CALL(*object, removeProperty(property));

	VelocityAdapter adapter(object);

	ASSERT_NO_THROW(adapter.removeVelocity());
}

TEST(TestFuelAdapter, FuelAdapter_GetFuel_Success)
{
	std::string property{"fuel"};
	double value{11.4};

	auto object = std::make_shared<MockUObject>();

	EXPECT_CALL(*object, hasProperty(property)).WillOnce(testing::Invoke([]() {
		return true;
	}));

	EXPECT_CALL(*object, getProperty(property)).WillOnce(testing::Invoke([value]() {
		return std::to_string(value);
	}));

	FuelAdapter adapter(object);

	ASSERT_NO_THROW(adapter.getFuel());
}

TEST(TestFuelAdapter, FuelAdapter_GetFuel_ErrorGetFuel)
{
	std::string property{"fuel"};
	double value{11.4};

	auto object = std::make_shared<MockUObject>();

	EXPECT_CALL(*object, hasProperty(property)).WillOnce(testing::Invoke([]() {
		return false;
	}));

	FuelAdapter adapter(object);

	ASSERT_THROW(adapter.getFuel(),std::invalid_argument);
}

TEST(TestFuelAdapter, FuelAdapter_SetFuel_Success)
{
	std::string property{"fuel"};
	double value{11.4};

	auto object = std::make_shared<MockUObject>();

	EXPECT_CALL(*object, setProperty(property, std::to_string(value)));

	FuelAdapter adapter(object);

	ASSERT_NO_THROW(adapter.setFuel(value));
}

TEST(TestFuelAdapter, FuelAdapter_RemoveFuel_Success)
{
	std::string property{"fuel"};

	auto object = std::make_shared<MockUObject>();

	EXPECT_CALL(*object, removeProperty(property));

	FuelAdapter adapter(object);

	ASSERT_NO_THROW(adapter.removeFuel());
}

TEST(TestInstantVelocityAdapter, InstantVelocityAdapter_GetInstantVelocity_Success)
{
	std::string property{"instantVelocity"};
	double value{11.4};

	auto object = std::make_shared<MockUObject>();

	EXPECT_CALL(*object, hasProperty(property)).WillOnce(testing::Invoke([]() {
		return true;
	}));

	EXPECT_CALL(*object, getProperty(property)).WillOnce(testing::Invoke([value]() {
		return std::to_string(value);
	}));

	InstantVelocityAdapter adapter(object);

	ASSERT_NO_THROW(adapter.getInstantVelocity());
}

TEST(TestInstantVelocityAdapter, InstantVelocityAdapter_GetInstantVelocity_ErrorGetInstantVelocity)
{
	std::string property{"instantVelocity"};
	double value{11.4};

	auto object = std::make_shared<MockUObject>();

	EXPECT_CALL(*object, hasProperty(property)).WillOnce(testing::Invoke([]() {
		return false;
	}));

	InstantVelocityAdapter adapter(object);

	ASSERT_THROW(adapter.getInstantVelocity(),std::invalid_argument);
}

TEST(TestInstantVelocityAdapter, InstantVelocityAdapter_SetInstantVelocity_Success)
{
	std::string property{"instantVelocity"};
	double value{11.4};

	auto object = std::make_shared<MockUObject>();

	EXPECT_CALL(*object, setProperty(property, std::to_string(value)));

	InstantVelocityAdapter adapter(object);

	ASSERT_NO_THROW(adapter.setInstantVelocity(value));
}

TEST(TestInstantVelocityAdapter, InstantVelocityAdapter_RemoveInstantVelocity_Success)
{
	std::string property{"instantVelocity"};

	auto object = std::make_shared<MockUObject>();

	EXPECT_CALL(*object, removeProperty(property));

	InstantVelocityAdapter adapter(object);

	ASSERT_NO_THROW(adapter.removeInstantVelocity());
}