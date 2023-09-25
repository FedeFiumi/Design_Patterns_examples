from .abs_factory import AbsFactory
from cars.null_car import NullCar

class NullFactory(AbsFactory):

    def create_auto(self):
        self.null_car = null_car = NullCar('Unknown_car')
        null_car.name = 'Unknown_car'
        return null_car
