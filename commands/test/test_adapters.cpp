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

TEST(TestAngularVelocityAdapter, AngularVelocityAdapter_SetVelocity_Success)
{
	std::string property{"angularVelocity"};
	double value{11.4};

	auto object = std::make_shared<MockUObject>();

	EXPECT_CALL(*object, setProperty(property, std::to_string(value)));

	AngularVelocityAdapter adapter(object);

	ASSERT_NO_THROW(adapter.setAngularVelocity(11.4));
}

TEST(TestAngularVelocityAdapter, AngularVelocityAdapter_GetVelocity_Success)
{
	std::string property{"angularVelocity"};
	double value{11.4};

	auto object = std::make_shared<MockUObject>();

	EXPECT_CALL(*object, hasProperty(property)).WillOnce(testing::Invoke([value]() {
		return true;
	}));

	EXPECT_CALL(*object, getProperty(property)).WillOnce(testing::Invoke([value]() {
		return std::to_string(value);
	}));

	AngularVelocityAdapter adapter(object);

	ASSERT_NO_THROW(adapter.getAngularVelocity());
}

TEST(TestAngularVelocityAdapter, AngularVelocityAdapter_GetVelocity_ErrorGetVelocity)
{
	std::string property{"angularVelocity"};

	auto object = std::make_shared<MockUObject>();

	EXPECT_CALL(*object, hasProperty(property)).WillOnce(testing::Invoke([]() {
		return false;
	}));

	AngularVelocityAdapter adapter(object);

	ASSERT_THROW(adapter.getAngularVelocity(),std::invalid_argument);
}

TEST(TestAngularVelocityAdapter, AngularVelocityAdapter_RemoveVelocity_Success)
{
	std::string property{"angularVelocity"};

	auto object = std::make_shared<MockUObject>();

	EXPECT_CALL(*object, removeProperty(property));

	AngularVelocityAdapter adapter(object);

	ASSERT_NO_THROW(adapter.removeAngularVelocity());
}