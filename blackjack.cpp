#include <bits/stdc++.h>
#define ask(v,V) cout << v;cin >> V;
#define check(V) for(auto i : V){cout << i << " ";}cout << endl;
using namespace std;

class const_var{
    public:
        vector <char> POKER {'A', 'A', 'A', 'A', 'K', 'K', 'K', 'K', 'Q', 'Q', 'Q', 'Q', 'J', 'J', 'J', 'J', 'T', 'T', 'T', 'T', '9', '9', '9', '9', '8', '8', '8', '8', '7', '7', '7', '7', '6', '6', '6', '6', '5', '5', '5', '5', '4', '4', '4', '4', '3', '3', '3', '3', '2', '2', '2', '2'};
        map<char,int> POKER_value {{'A',11},{'K',10},{'Q',10},{'J',10},{'T',10},{'9',9},{'8',8},{'7',7},{'6',6},{'5',5},{'4',4},{'3',3},{'2',2}};
        vector <int> bot_total_value;


        int count_total(vector <char> cards){
            int total=0;
            for(auto card : cards){
                total+=POKER_value[card];
            }
            return total;
        }

        char give_card(){
            srand(time(0));
            int idx = rand()%POKER.size();
            char crd = POKER[idx];
            POKER.erase(POKER.begin()+idx);
            return crd;
        }

        void bot(){
            vector <char> cards;
            while(count_total(cards)<=15){
                cards.push_back(give_card());
            }
            bot_total_value.push_back(count_total(cards));
        }
};

int main(){

    const_var const_var;

    vector <char> player_cards;

    int bot_num;
    ask("Enter Bot Number > ",bot_num);

    while(bot_num--){
        const_var.bot();
    }

    player_cards.push_back(const_var.give_card());
    player_cards.push_back(const_var.give_card());

    for(auto i : player_cards){
        if(i != 'T'){
            cout << '[' << i << ']';
        }else{
            cout << '[' << "10" << ']';
        }
    }

    while(true){
        char giv;cout << '\n';ask("Do you want to add card? [Y/n]: ",giv);
        if(giv!='Y'&&giv!='y'){break;}
        player_cards.push_back(const_var.give_card());
        for(auto i : player_cards){
            if(i != 'T'){
                cout << '[' << i << ']';
            }else{
                cout << '[' << "10" << ']';
            }
        }
    }

    int min = *min_element(const_var.bot_total_value.begin(),const_var.bot_total_value.end());
    int max = *max_element(const_var.bot_total_value.begin(),const_var.bot_total_value.end());
    int player_num = const_var.count_total(player_cards);

    if(min>21||max>21){
        if(player_num <=21){
            cout << "You Win! (" << player_num<<')' << endl;
            for(auto i : const_var.bot_total_value){
                if(i <= 21)cout << "BOT: "<<i<< " (Win!)"<<endl;
                else cout << "BOT: "<<i<< " (Lose!)"<<endl;
            }
        }else {
            cout << "You Lose! (" << player_num<<')' << endl;
            for(auto i : const_var.bot_total_value){
                if(i <= 21)cout << "BOT: "<<i<< " (Win!)"<<endl;
                else cout << "BOT: "<<i<< " (Lose!)"<<endl;
            }
        }
    }else{
        if(player_num>21)cout << "You Lose! (" << player_num<<')' << endl;
        else if(max <= player_num)cout << "You Win! (" << player_num<<')' << endl;
        else cout << "You Lose! (" << player_num<<')' << endl;
        for(auto i : const_var.bot_total_value){
                if(i <= 21&&i>=player_num)cout << "BOT: "<<i<< " (Win!)"<<endl;
                else if(i<=21&&player_num>21)cout << "BOT: "<<i<< " (Win!)"<<endl;
                else cout << "BOT: "<<i<< " (Lose!)"<<endl;
        }
    }
    
}