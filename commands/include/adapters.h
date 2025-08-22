#ifndef PROGLIB_HOMEWORK_ADAPTERS_H
#define PROGLIB_HOMEWORK_ADAPTERS_H

#include "interfaces.h"
#include <memory>

class VelocityAdapter : public IVelocityChangeable {
public:
	explicit VelocityAdapter(std::shared_ptr<IUObject> obj);

	void setVelocity(double velocity) override;

	double getVelocity() const override;

	void removeVelocity() override;

private:
	std::shared_ptr<IUObject> object;
};

class AngularVelocityAdapter : public IAngularVelocityChangeable {
public:
	explicit AngularVelocityAdapter(std::shared_ptr<IUObject> obj);

	void setAngularVelocity(double angularVelocity) override;

	double getAngularVelocity() const override;

	void removeAngularVelocity() override;

private:
	std::shared_ptr<IUObject> object;
};

#endif // PROGLIB_HOMEWORK_ADAPTERS_H
