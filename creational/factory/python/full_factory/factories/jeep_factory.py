from .abs_factory import AbsFactory
from cars.jeep import Jeep

class JeepFactory(AbsFactory):

    def create_auto(self):
        self.fiat = jeep = Jeep()
        jeep.name = 'Jeep'
        return jeep
