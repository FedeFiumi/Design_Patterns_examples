from .abs_factory import AbsFactory
from cars.fiat import Fiat

class FiatFactory(AbsFactory):

    def create_auto(self):
        self.fiat = fiat = Fiat()
        fiat.name = 'Fiat'
        return fiat
