#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "adapters.h"

class MockUObject : public IUObject {
public:
	MOCK_METHOD(void, setProperty, (const std::string&, const std::string&), (override));
	MOCK_METHOD(std::string, getProperty, (const std::string&), (const override));
	MOCK_METHOD(bool, hasProperty, (const std::string&), (const override));
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