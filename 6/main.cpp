#include <iostream>

using namespace std;

class Transport {
private:
	unsigned speed; // km/h
	unsigned money_per_hour;
public:
	Transport() {
		this->speed = 1;
		this->money_per_hour = 1;
	}
	Transport(unsigned speed, unsigned money_per_hour) {
		this->speed = speed;
		this->money_per_hour = money_per_hour;
	}

	double time(double distance) {
		return distance / speed;
	}
	double cost(double distance) {
		return time(distance) * money_per_hour;
	}

	~Transport() {}
	friend class Car;
	friend class Bicycle;
	friend class Wagon;
};

class Car : public Transport {
public:
	Car() {
		this->speed = 60;
		this->money_per_hour = 1000;
	}
	~Car() {}
};

class Bicycle : public Transport {
public:
	Bicycle() {
		this->speed = 10;
		this->money_per_hour = 500;
	}
	~Bicycle() {}
};

class Wagon : public Transport {
public:
	Wagon() {
		this->speed = 12;
		this->money_per_hour = 1500;
	}
	~Wagon() {}
};

int main(void) {
	Car c;
	Bicycle b;
	Wagon w;
	double distance;
	cout << "Distance (km): ";
	cin >> distance;

	cout << "\nCar:\ntime: " << c.time(distance) << "\ncost: " << c.cost(distance) << "\n";
	cout << "\nBicycle:\ntime: " << b.time(distance) << "\ncost: " << b.cost(distance) << "\n";
	cout << "\nWagon:\ntime: " << w.time(distance) << "\ncost: " << w.cost(distance) << "\n";
	return 0;
}