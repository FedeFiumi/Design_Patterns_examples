import abc

class AbsFactory(abc.ABC):
    @abc.abstractclassmethod
    def create_low_range(self):
        pass

    @abc.abstractclassmethod
    def create_mid_range(self):
        pass

    @abc.abstractclassmethod
    def create_high_range(self):
        pass
