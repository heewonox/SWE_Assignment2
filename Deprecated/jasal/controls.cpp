#include<iostream>
#include"controls.h"
using namespace std;
string SignUpUI::getID(){
	string input;
	cin>>input;
	return input;
}
string SignUpUI::getPassword(){
	string input;
	cin>>input;
	return input;
}
string SignUpUI::getPhone(){
	string input;
	cin>>input;
	return input;
}
void SignUpUI::ShowOutput(string id,string password,string phone){
	cout<<"1.1. 회원가입"<<endl;
	cout<<"> "<<id<<" "<<password<<" "<<phone<<" "<<endl;
	return;
}
SignUp::SignUp(IDList *idlist){
	this->idlist=idlist;
}
void SignUp::job(){
	string id=ui.getID();
	string password=ui.getPassword();
	string phone=ui.getPhone();
	idlist->addNewAccount(id,password,phone);
	ui.ShowOutput(id,password,phone);
}
string LogInUI::getID(){
	string input;
	cin>>input;
	return input;
}
string LogInUI::getPassword(){
	string input;
	cin>>input;
	return input;
}
void LogInUI::showOutput(string id,string password){
	cout<<"2.1. 로그인"<<endl;
	cout<<"> "<<id<<" "<<password<<endl;
	return;
}
LogIn::LogIn(IDList *idlist){
	this->idlist=idlist;
}
string LogIn::setCurrentSessionID(){
	string id=ui.getID();
	string password=ui.getPassword();
	bool isAdmin=idlist->isAdmin(id,password);
	bool isValidAccount=idlist->isValidAccount(id,password);
	if(isAdmin){
		ui.showOutput(id,password);
		return id;
	}
	else if(isValidAccount){
		ui.showOutput(id,password);
		return id;
	}
	else{return "guest";}
}
void LogOutUI::getInput(){}
void LogOutUI::ShowOutput(string id){
	cout<<"2.2 로그아웃"<<endl;
	cout<<"> "<<id<<endl;
}
bool LogOut::isLogOutSuccessful(string id){
	ui.getInput();
	ui.ShowOutput(id);
	return true;
}
string AddBicycleUI::getID(){
	string id;
	cin>>id;
	return id;
}
string AddBicycleUI::getProductName(){
	string pm;
	cin>>pm;
	return pm;
}
void AddBicycleUI::ShowOutput(string id,string productName){
	cout<<"3.1. 자전거 등록"<<endl;
	cout<<"> "<<id<<" "<<productName<<endl;
}
AddBicycle::AddBicycle(BicycleList *list){
	this->list=list;
}
void AddBicycle::job(){
	string id=ui.getID();
	string productName=ui.getProductName();
	list->addNewBicycle(id,productName);
	ui.ShowOutput(id,productName);
}
string RentBicycleUI::getBikeID(){
	string id;
	cin>>id;
	return id;
}
void RentBicycleUI::ShowOutput(string bikeID,string productName){
	cout<<"4.1. 자전거 대여"<<endl;
	cout<<"> "<<bikeID<<" "<<productName<<endl;
	return;
}
void RentBicycle::job(string userID,RentalStatusList *rL,BicycleList *bL){
	string bikeID=ui.getBikeID();
	rentalList=rL;
	bikeList=bL;
	//first : get matching bike
	Bicycle* tmp=bikeList->fetchBicycleByID(bikeID);
	//second : make rental instance
	rentalList->addNewRentalStatus(userID,tmp);
	ui.ShowOutput(tmp->getID(),tmp->getProductName());
}
void ShowRentalInfoUI::getInput(){}
//fuck
//lets just leave it until better solution comes up
void ShowRentalInfoUI::ShowOutput(string id,string productName){
	cout<<"> "<<id<<" "<<productName<<endl;
}
ShowRentalInfo::ShowRentalInfo(RentalStatusList *list){
	this->list=list;
}
void ShowRentalInfo::job(string userID){
	for(int i=0;i<list->idx;i++){
		if(list->list[i]->getUserID()==userID){
			ui.ShowOutput(list->list[i]->getBicycle()->getID(),list->list[i]->getBicycle()->getProductName());
		}
	}
}