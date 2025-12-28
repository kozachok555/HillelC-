#include <string>
#include <iostream>
#include <vector>
#include <memory>
class IDevice {
public:
	IDevice() = default;
	virtual void init() = 0;
	virtual void shutdown() = 0;
	virtual std::string name() const = 0;
	virtual ~IDevice() = default;
	IDevice(const IDevice&) = delete;
	IDevice& operator=(const IDevice&) = delete;
};
class Camera final : public IDevice {
	public:
	Camera(const std::string& name) : versionName(name) {};

	void init() override {
		std::cout << "Camera initialized" << std::endl;
	}
	void shutdown() override {
		std::cout << "Camera shutdown" << std::endl;
	}
	std::string name() const override {
		return versionName;
	}
	~Camera() override {
		std::cout << "Camera destructor called" << std::endl;
	}
private:
	std::string versionName;
};
class Microphone final : public IDevice {
public:
	Microphone(const std::string& name) : versionName(name) {};
	void init() override {
		std::cout << "Microphone initialized" << std::endl;
	}
	void shutdown() override {
		std::cout << "Microphone shutdown" << std::endl;
	}
	std::string name() const override {
		return versionName;
	}
	~Microphone() override {
		std::cout << "Microphone destructor called" << std::endl;
	}
private:
	std::string versionName;
};
class Storage final : public IDevice {
	public:
	Storage(const std::string& name) : versionName(name) {};
	void init() override {
		std::cout << "Storage initialized" << std::endl;
	}
	void shutdown() override {
		std::cout << "Storage shutdown" << std::endl;
	}
	std::string name() const override {
		return versionName;
	}
	~Storage() override {
		std::cout << "Storage destructor called" << std::endl;
	}
private:
	std::string versionName;
};
class BaseNV {
	public:
	BaseNV() = default;
	~BaseNV() = default;
	void foo() {
		std::cout << "BaseNV foo" << std::endl;
	}
	
};
class DerivedNV final : public BaseNV {
	public:
	DerivedNV() = default;
	~DerivedNV() = default;
	void foo() {
		std::cout << "DerivedNV foo" << std::endl;
	}
};
class BaseV {
	public:
	BaseV() = default;
	virtual ~BaseV() = default;
	virtual void foo() {
		std::cout << "BaseV foo" << std::endl;
	}
};
class DerivedV final : public BaseV {
	public:
	DerivedV() = default;
	~DerivedV() override = default;
	void foo() override {
		std::cout << "DerivedV foo" << std::endl;
	}
};

int main() {
	std::vector<std::unique_ptr<IDevice>> devices;
	devices.push_back(std::make_unique<Camera>("Camera v1.0"));
	devices.push_back(std::make_unique<Microphone>("Microphone v2.0"));
	devices.push_back(std::make_unique<Storage>("Storage v3.0"));
	for (const auto& device : devices) {
		device->init();
		std::cout << "Device Name: " << device->name() << std::endl;
		device->shutdown();
	}
	for (const auto& devicePtr : devices) {
		(*devicePtr).init();
		std::cout << "Device Name: " << (*devicePtr).name() << std::endl;
		(*devicePtr).shutdown();
	}
	IDevice* p = new Camera("delet4e example");
	delete p;
	DerivedNV dnv;
	dnv.foo();
	BaseNV* bnv = &dnv;
	bnv->foo();
	BaseV* bv = new DerivedV();
	bv->foo();
	delete bv;

	return 0;
}