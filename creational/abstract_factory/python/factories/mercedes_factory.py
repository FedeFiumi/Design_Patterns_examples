from .abs_factories import AbsFactory
from autos.mercedes.classa import ClassA
from autos.mercedes.glc import Glc
from autos.mercedes.amgcoupe import AmgCoupe


class MercedesFactory(AbsFactory):
    @staticmethod
    def create_low_range():
        return ClassA()

    @staticmethod
    def create_mid_range():
        return Glc()

    @staticmethod
    def create_high_range():
        return AmgCoupe()
