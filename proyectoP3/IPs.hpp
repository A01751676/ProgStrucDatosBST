#ifndef IPS
#define IPS

#include <string>
using namespace std;

class IP{
    private:
        string ip;
        int numAccesos;

    public:

        void setIP(int ip){this->ip = ip;}
        string getIP(){return this->ip;}

        void setNumAccesos(int numAccesos){this->numAccesos = numAccesos;}
        int getNumAccesos(){return this->numAccesos;}

        IP(){
            this->ip = "";
            this->numAccesos = 0;
        }

        IP(string ip, int numAccesos){
            this->ip = ip;
            this->numAccesos = numAccesos;
        }
};
#endif