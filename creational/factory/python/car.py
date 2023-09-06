from fiat import Fiat
from mercedes import Mercedes
from jeep import Jeep
from nullcar import Nullcar

def getcar(carname:str):
  if carname == 'Fiat':
    return Fiat()
  elif carname == 'Mercedes':
    return Mercedes()
  elif carname == 'Jeep':
    return Jeep()
  else:
    return NullCar(carname)

if __name__ == "__main__":
    for carname in 'Fiat', 'Mercedes', 'Jeep':
        car = getcar(carname)
        car.start()
        car.stop()
