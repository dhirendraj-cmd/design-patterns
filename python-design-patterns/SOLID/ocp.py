from abc import ABC, abstractmethod


class Product:
    def __init__(self, name: str, price: float):
        self.name = name
        self.price = price


class ShoopingCart:
    def __init__(self) -> None:
        self.products: list[Product] = []

    def add_product(self, p: Product):
        self.products.append(p)

    def get_products(self) -> list[Product]:
        return self.products

    def calculate_price(self):
        total = 0
        for i in self.products:
            total+=i.price

        return total


class DBPersistance(ABC):
    def __init__(self, cart: ShoopingCart):
        self.cart = cart

    @abstractmethod
    def save(self, cart: ShoopingCart):
        pass



class SaveToSQL(DBPersistance):
    def save(self, cart:ShoopingCart):
        print("Saving to PostgresDB")


class SaveToMongo(DBPersistance):
    def save(self, cart:ShoopingCart):
        print("Saving to Mongo DB")



cart = ShoopingCart()
cart.add_product(Product("Bag", 250))
cart.add_product(Product("mpose", 128.50))

cart.get_products()

sql = SaveToSQL(cart=cart)
sql.save(cart=cart)

mongo = SaveToMongo(cart=cart)
mongo.save(cart=cart)