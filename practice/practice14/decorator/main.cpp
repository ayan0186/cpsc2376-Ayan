#include <iostream>
#include <memory>

class Purchase {
public:
    virtual double getCost() const = 0;
    virtual ~Purchase() = default;
};

class SimplePurchase : public Purchase {
    double cost;
public:
    explicit SimplePurchase(double c):cost(c){}
    double getCost() const override { return cost; }
};

// ───────── decorators ─────────
class TaxDecorator : public Purchase {
    std::shared_ptr<Purchase> base;
public:
    explicit TaxDecorator(std::shared_ptr<Purchase> b):base(std::move(b)){}
    double getCost() const override { return base->getCost()*1.10; } // 10 % tax
};

class ShippingFeeDecorator : public Purchase {
    std::shared_ptr<Purchase> base;
    double fee;
public:
    ShippingFeeDecorator(std::shared_ptr<Purchase> b,double f=4.99)
        :base(std::move(b)),fee(f){}
    double getCost() const override { return base->getCost()+fee; }
};

class DiscountDecorator : public Purchase {
    std::shared_ptr<Purchase> base;
    double percent;          // 0.15 = 15 % off
public:
    DiscountDecorator(std::shared_ptr<Purchase> b,double p)
        :base(std::move(b)),percent(p){}
    double getCost() const override { return base->getCost()*(1.0-percent); }
};

int main(){
    std::cout<<"Base price: ";
    double price; std::cin>>price;
    std::shared_ptr<Purchase> p = std::make_shared<SimplePurchase>(price);

    char opt;
    do{
        std::cout<<"\nAdd decorator: t)-tax  s)-shipping  d)-discount  q)-quote\n> ";
        std::cin>>opt;
        if(opt=='t')      p = std::make_shared<TaxDecorator>(p);
        else if(opt=='s') p = std::make_shared<ShippingFeeDecorator>(p);
        else if(opt=='d'){
            double pct;
            std::cout<<"Percent off (e.g. 0.20 for 20%): ";
            std::cin>>pct;
            p = std::make_shared<DiscountDecorator>(p,pct);
        }
    }while(opt!='q');

    std::cout<<"Final cost = "<<p->getCost()<<'\n';
}
