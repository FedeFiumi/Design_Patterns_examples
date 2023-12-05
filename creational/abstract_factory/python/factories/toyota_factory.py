from .abs_factories import AbsFactory
from autos.toyota.aygo import Aygo
from autos.toyota.rav4 import Rav4
from autos.toyota.supra import Supra


class ToyotaFactory(AbsFactory):
    @staticmethod
    def create_low_range():
        return Aygo()

    @staticmethod
    def create_mid_range():
        return Rav4()

    @staticmethod
    def create_high_range():
        return Supra()
