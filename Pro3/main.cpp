#include <string>
#include <iostream>
#include <vector>
#include <memory>
class IDevice {
protected:
	IDevice() {
		if (isExists) {
			throw std::runtime_error("only 1 device can exist");
		};
		isExists = true;
	};
public:
	virtual void init() = 0;
	virtual void shutdown() = 0;
	virtual std::string name() const = 0;
	virtual ~IDevice() {
		isExists = false;
	};

	IDevice(const IDevice&) = delete;
	IDevice& operator=(const IDevice&) = delete;
private:
	static bool isExists;
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

bool IDevice::isExists = false;
int main() {
	try {
		std::unique_ptr<IDevice> device;
		device = std::make_unique<Camera>("Camera v1.0");
		device->init();
		device.reset();

		device = std::make_unique<Microphone>("Microphone v2.0");
		device->init();
		device->shutdown();
		device.reset();

	}
	catch (const std::exception& e) {
		std::cerr << e.what();
	}

	return 0;
}