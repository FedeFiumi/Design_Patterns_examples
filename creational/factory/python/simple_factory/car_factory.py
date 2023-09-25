from inspect import getmembers, isclass, isabstract
import cars

class CarFactory():
    cars_dict = {} # Key = car model name, Value = class for the car

    def __init__(self):
        self.load_cars()

    def load_cars(self):
        classes = getmembers(cars, lambda m: isclass(m) and not isabstract(m))
        for name, _type in classes:
            if isclass(_type) and issubclass(_type, cars.AbsCar):
                self.cars_dict.update([[name, _type]])

    def create_instance(self, car_name):
        if car_name in self.cars_dict:
            return self.cars_dict[car_name]()
        else:
            return cars.NullCar(car_name)
