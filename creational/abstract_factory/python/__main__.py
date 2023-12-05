from factories.ford_factory import FordFactory
from factories.mercedes_factory import MercedesFactory
from factories.toyota_factory import ToyotaFactory

print("----ABSTRACT FACTORY EXAMPLE")
print()

for factory in [FordFactory, MercedesFactory, ToyotaFactory]:
    print("Factory " + str(factory))
    car = factory.create_low_range()
    car.start()
    car.stop()
    car = factory.create_mid_range()
    car.start()
    car.stop()
    car = factory.create_high_range()
    car.start()
    car.stop()
    print()
