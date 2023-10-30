from .abs_factories import AbsFactory
from autos.ford.fiesta import Fiesta
from autos.ford.kuga import Kuga
from autos.ford.mustang import Mustang


class FordFactory(AbsFactory):
    @staticmethod
    def create_low_range():
        return Fiesta()

    @staticmethod
    def create_mid_range():
        return Kuga()

    @staticmethod
    def create_high_range():
        return Mustang()
