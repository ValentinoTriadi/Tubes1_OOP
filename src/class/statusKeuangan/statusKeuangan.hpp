#ifndef STATUSKEUANGAN_HPP
#define STATUSKEUANGAN_HPP

class StatusKeuangan{
    private:
        int Money;
        int NonUang;
    public:
        StatusKeuangan();
        StatusKeuangan(int Money, int NonUang);
        ~StatusKeuangan();

        void hitungPajak();
        void tambahUang();
        void kurangUang();
};

#endif