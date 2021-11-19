#ifndef IPS
#define IPS

using namespace std;

class IP{
    private:
        int ip;
        int numAccesos;

    public:

        void setIP(int ip){this->ip = ip;}
        int getIP(){return this->ip;}

        void setNumAccesos(int numAccesos){this->numAccesos = numAccesos;}
        int getNumAccesos(){return this->numAccesos;}

        IP(){
            this->ip = 0;
            this->numAccesos = 0;
        }

        IP(int ip, int numAccesos){
            this->ip = ip;
            this->numAccesos = numAccesos;
        }
};
#endif