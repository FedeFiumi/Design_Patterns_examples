from .abs_factory import AbsFactory
from cars.mercedes import Mercedes

class MercedesFactory(AbsFactory):

    def create_auto(self):
        self.mercedes = mercedes = Mercedes()
        mercedes.name = 'Mercedes'
        return mercedes
