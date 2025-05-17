#include"elements.h"
using namespace std;
class SignUpUI{
public:
	string getID();
	string getPassword();
	string getPhone();
	void ShowOutput(string id,string password,string phone);
};
class SignUp{
private:
	SignUpUI ui;
	IDList *idlist;
public:
	SignUp(IDList *idlist);
	void job();
};
class LogInUI{
public:
	string getID();
	string getPassword();
	void showOutput(string id,string password);
};
class LogIn{
private:
	LogInUI ui;
	IDList *idlist;
public:
	LogIn(IDList *idlist);
	string setCurrentSessionID();
	bool isAdmin();
	bool isValidAccount();
};

class LogOutUI{
public:
	void getInput();
	void ShowOutput(string id);
};
class LogOut{
private:
	LogOutUI ui;
public:
	bool isLogOutSuccessful(string id);
};
class RentBicycleUI{
public:
	string getBikeID();
	void ShowOutput(string bikeID,string productName);
};
class RentBicycle{
private:
	RentBicycleUI ui;
	RentalStatusList *rentalList;
	BicycleList *bikeList;
public:
	void job(string userID,RentalStatusList *rL,BicycleList *bL);
};
class ShowRentalInfoUI{
public:
	void getInput();
	void ShowOutput(string id,string productName);
};
class ShowRentalInfo{
private:
	ShowRentalInfoUI ui;
	RentalStatusList *list;
public:
	ShowRentalInfo(RentalStatusList *list);
	void job(string userID);
};
class AddBicycleUI{
public:
	string getID();
	string getProductName();
	void ShowOutput(string id,string productName);
};
class AddBicycle{
private:
	AddBicycleUI ui;
	BicycleList *list;
public:
	AddBicycle(BicycleList *list);
	void job();
};

