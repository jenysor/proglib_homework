#ifndef PROGLIB_HOMEWORK_ADAPTERS_H
#define PROGLIB_HOMEWORK_ADAPTERS_H

#include "interfaces.h"
#include <memory>

class MovableAdapter : public IMovable {
public:
	explicit MovableAdapter(std::shared_ptr<IUObject> obj);

	double getPosition() override;

	double getVelocity() override;

	void setPosition(double position) override;

	~MovableAdapter() override = default;

private:
	std::shared_ptr<IUObject> object;
};

class VelocityAdapter : public IVelocityChangeable {
public:
	explicit VelocityAdapter(std::shared_ptr<IUObject> obj);

	void setVelocity(double velocity) override;

	double getVelocity() const override;

	void removeVelocity() override;

private:
	std::shared_ptr<IUObject> object;
};

class FuelAdapter : public IFuelAdapter {
public:
	explicit FuelAdapter(std::shared_ptr<IUObject> obj);

	double getFuel() override;

	void setFuel(double fuel) override;

	void removeFuel() override;

private:
	std::shared_ptr<IUObject> object;
};

#endif // PROGLIB_HOMEWORK_ADAPTERS_H
