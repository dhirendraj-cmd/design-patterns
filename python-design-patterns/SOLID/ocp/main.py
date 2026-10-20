from ocp.product import Product
from ocp.cart import ShoopingCart
from ocp.dbpersistance import SaveToMongo, SaveToSQL


cart = ShoopingCart()
cart.add_product(Product("Bag", 250))
cart.add_product(Product("mpose", 128.50))

cart.get_products()

sql = SaveToSQL(cart=cart)
sql.save(cart=cart)

mongo = SaveToMongo(cart=cart)
mongo.save(cart=cart)
