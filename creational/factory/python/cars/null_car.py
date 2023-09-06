from .abs_car import AbsCar

class NullCar(AbsCar):
    def __init__(self, car_name):
        self._car_name = car_name

    def start(self):
        print('Undefined car named:' + self._car_name)

    def stop(self):
        pass
