from car_factory import CarFactory

factory = CarFactory()

if __name__ == "__main__":
    print("----FACTORY (SIMPLE FACTORY) EXAMPLE")
    for car_name in 'Fiat', 'Mercedes', 'Jeep','Tesla':
        car = factory.create_instance(car_name)
        car.start()
        car.stop()
    print("")
