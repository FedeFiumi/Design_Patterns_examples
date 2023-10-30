import abc

class AbsAuto(abc.ABC):
    @abc.abstractclassmethod
    def start(self):
        pass

    def stop(self):
        pass
