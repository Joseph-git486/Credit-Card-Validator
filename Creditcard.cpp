#include <iostream>
#include <algorithm>

std::string remove_space(std::string card);
int get_digit(int n);
int sum_even(std::string card);
int sum_odd(std::string card);

int main(){
    std::string card;
    std::cout<<"Enter card number: ";
    std::getline(std::cin,card);
    card.erase(std::remove(card.begin(),card.end(),' '),card.end());
    int sum = sum_even(card) + sum_odd(card);
    if(sum%10 == 0){
        std::cout<<"The card is valid";
    }
    else{
        std::cout<<"The card is not valid";
    }

}

int get_digit(int n){
    return n/10 + n%10;
}

int sum_odd(std::string card){
    int n;
    n = card.length()-1;
    int sum = 0;
    for(int i=n;i>=0;i-=2){
        sum += get_digit(card[i]-'0');
    }
    return sum;
}

int sum_even(std::string card){
    int n;
    n = card.length()-2;
    int sum = 0;
    for(int j=n;j>=0;j-=2){
        sum += get_digit(2*(card[j]-'0'));
    }
    return sum;
}