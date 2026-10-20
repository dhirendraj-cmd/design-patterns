#include <iostream>
#include <vector>

using namespace std;


class Product{
    public:
        string name;
        double price;

        Product(string name, double price){
            this->name=name;
            this->price=price;
        }

};


class ShoppingCart{
    public:
        // store products
        vector<Product*> products;

        void addProduct(Product* p) { 
            products.push_back(p);
        }

        const vector<Product*>& getProducts(){
            return products;
        }


        // calculate price
        double calculatePrice(){
            double total = 0;
            for(auto x: products){
                total+=x->price;
            }

            return total;
        }

};



// abstract class
class DBPersistence{
    private:
        ShoppingCart* cart;

    public:
        virtual void save(ShoppingCart* cart) = 0;

};


class SaveToSQLDB: public DBPersistence{
    public:
        void save(ShoppingCart* cart) override{
            cout << "Saving to PostgresDB... \n";
        }
};

class SaveToDynamoDB: public DBPersistence{
    public:
        void save(ShoppingCart* cart) override{
            cout << "Saving to Dynamo DB... \n";
        }
};

class SaveToFile: public DBPersistence{
    public:
        void save(ShoppingCart* cart) override{
            cout << "Saving data to file ... \n";
        }
};

int main(){
    ShoppingCart* cart = new ShoppingCart();
    cart->addProduct(new Product("Suitcase", 2312));
    cart->addProduct(new Product("Trolley", 12000));

    DBPersistence* sqldb = new SaveToSQLDB();
    sqldb->save(cart);

    DBPersistence* dydb = new SaveToDynamoDB();
    dydb->save(cart);

    DBPersistence* file = new SaveToFile();
    file->save(cart);

    return 0;
}
