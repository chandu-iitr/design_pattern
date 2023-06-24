#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// observer Class
class NotificationAlertObserver {
    public:
    virtual void update() = 0;
};

// Observerable class
class StocksObservable {
public:
    virtual void add(NotificationAlertObserver* observer) = 0;
    virtual void detach(NotificationAlertObserver* observer) = 0;
    virtual void notifySubscribers() = 0;
    virtual void setStockCount(int newStockAdded) = 0;
    virtual int getStockCount() = 0; 
};

// IPhone Stock Observable
class IphoneObservable : public StocksObservable {
    private:
    std::vector<NotificationAlertObserver*> observers;
    int stockCount = 0;
    
    public:
    void add(NotificationAlertObserver* observer) {
        observers.push_back(observer);
    }
    
    void detach(NotificationAlertObserver* observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }
    
    void notifySubscribers() {
        for (NotificationAlertObserver* observer : observers) {
            observer->update();
        }
    }

    void setStockCount(int newStockAdded) {
        if(stockCount ==0 ){
            notifySubscribers();
        }
        stockCount += newStockAdded;
    }

    int getStockCount() {
        return stockCount;
    }
};

// NotificationAlert Observer implementation for EmailAlert notification
class EmailAlertObserver : public NotificationAlertObserver {
    private:
    std::string emailId;
    StocksObservable* observable;

    public:
    EmailAlertObserver(std::string emailId, StocksObservable* observable) : emailId(emailId), observable(observable) {}

    void update() {
        sendMail(emailId);
    }

    void sendMail(std::string emailId){
        std::cout << "mail sent to: " + emailId << std::endl;
    }
};


// NotificationAlert Observer implementation for MobileAlert notification
class MobileAlertObserver : public NotificationAlertObserver {
    private:
    std::string userName;
    StocksObservable* observable;

    public:
    MobileAlertObserver(std::string userName, StocksObservable* observable) : userName(userName), observable(observable) {}

    void update() {
        sendMsgOnMobile(userName);
    }

    void sendMsgOnMobile(std::string userName){
        std::cout << "msg on mobile sent to: " + userName << std::endl;
    }
};

class Store {
    private:
    IphoneObservable iphoneObservable;
    EmailAlertObserver obs1;  // Assuming EmailAlertObserver is derived from NotificationAlertObserver
    EmailAlertObserver obs2;
    EmailAlertObserver obs3;
    MobileAlertObserver obs4;

    public:
    Store() : obs1("xyz@gmail.com", &iphoneObservable),
            obs2("nnn@gmail.com", &iphoneObservable),
            obs3("mmm@gmail.com", &iphoneObservable),
            obs4("cvcv", &iphoneObservable) {}

    void initialize() {
        iphoneObservable.add(&obs1);
        iphoneObservable.add(&obs2);
        iphoneObservable.add(&obs3);
        iphoneObservable.add(&obs4);

        iphoneObservable.setStockCount(10);
    }
};


int main(){
    Store store;
    store.initialize();
    return 0;
}