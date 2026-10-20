from SOLID.ocp.cart import ShoopingCart
from abc import ABC, abstractmethod


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




