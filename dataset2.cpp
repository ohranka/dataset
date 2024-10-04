#include <iostream>
#include <fstream>
#include <windows.h>
#include <sstream>
#include<vector>
#include<algorithm>

std::string toString(int val)
{
    std::ostringstream oss;
    oss << val;
    return oss.str();
}


int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    std::ofstream out;
    out.open("dataset_anon.xls");
    std::ifstream data("dataset.txt");
    std::string fio,city_in,city_out,time_in,time_out,train_num,card,num_pas,sit,cap;
    int cash;
    std::vector<std::string> dats(50001);
    for (int i = 0; i <= 50000; i++) {
        data >> fio;
        data >> cap;
        fio = fio + cap;
        data >> cap;
        fio += cap;
        data >> num_pas;
        data >> city_out;
        data >> city_in;
        data >> time_out;
        data >> time_in;
        data >> train_num;
        data >> sit;
        data >> cash;
        data >> card;
        fio = 'М';
        cap = num_pas[0] ;
        num_pas = cap + num_pas[1];
        int a = time_out[9] - '0';
        a = a % 7 + 1;
        time_out = toString(a);
        time_in = toString(a);
        if (cash == 7084 || cash == 1728 || cash == 1883 || cash == 2466) {
            sit = "54";
        }
        if (cash == 5184 ||cash==7408||cash==9249 ) {
            sit = "19";
        }
        if (cash == 1787||cash ==1802||cash==2124||cash==3990||cash==2004) {
            sit = "36";
        }
        if (cash == 1132) {
            sit = "65";
        }
        cap = "";
        for (int k = 0; k<5; k ++) {
            cap = cap + card[k];
        }
        card = cap;
        if (cash > 5000) {
            cash = (9249 + 5184 + 7084) / 3;
        }
        if (cash <2000) {
            cash = (1787 + 1728 + 1883+1802+1132) / 5;
        }
        if (cash < 5000&&cash>2000) {
            cash = (2466 + 2124 + 2004) / 3;
        }
        dats[i] = fio + '\t' + num_pas + '\t' + city_out + '\t' + city_in + '\t' + time_out + '\t' + time_in + '\t' + train_num + '\t' + sit + '\t' + toString(cash) + '\t' + card;
    }
    std::sort(dats.begin(),dats.end(), std::greater < std::string >());
    int p = 1;
    int k_anon=100000;
    for (int i = 1; i <= 50000; i++) {
        p++;
        if (p == 6) {
            out << dats[i] << std::endl;
            out << dats[i-1] << std::endl;
            out << dats[i-2] << std::endl;
            out << dats[i-3] << std::endl;
            out << dats[i-4] << std::endl;
            out << dats[i-5] << std::endl;
            if (p < k_anon) {
                k_anon = p;
            }
        }
        if (p > 6) {
            out << dats[i] << std::endl;
            if (p < k_anon) {
                k_anon = p;
            }
        }
        if (dats[i] != dats[i - 1]) {
            p = 0;
        }
    }
    std::cout << "K_anon равен " << p;
}

