from factories import factory_loader

if __name__ == "__main__":
    print("----FACTORY (FULL FACTORY) EXAMPLE")
    for factory_name in 'fiat_factory', 'jeep_factory', 'mercedes_factory', 'tesla_factory':

        factory = factory_loader.load_factory(factory_name)
        car = factory.create_auto()

        car.start()
        car.stop()
    print("")
