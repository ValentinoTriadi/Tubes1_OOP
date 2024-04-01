#include "people.hpp"
#include "GameException.hpp"
#include "product.hpp"
#include "toko.hpp"


People::People() : Keuangan(50), Weight(40), Type(0)
{

}

People::People(int weight, int Keuangan, int type, int n_penyimpanan, int m_penyimpanan) : Keuangan(Keuangan), Weight(weight), Type(type), storage(n_penyimpanan, m_penyimpanan)
{
}
People::~People() = default;

void People::cetakPenyimpanan()
{
    cout << storage << endl;
}

void People::makan()
{
    cout << "Pilih makanan dari penyimpanan" << endl;
    cetakPenyimpanan();

    cout << "Slot: ";
    string slot;
    cin >> slot;
    cout << endl;

    int row = slot[0] - 'A';
    int col = slot[1] - '0';

    Item* makanan = storage(row, col);
    if (makanan == nullptr) {
        throw FoodEmptyException();
    // TODO : else if (makanan->getType() != FOOD)
    }else{
        Product* product = dynamic_cast<Product*>(makanan);
        Weight += product->getAddedWeight();
        storage.deleteItem(row, col);
        cout << "Dengan lahapnya, kamu memakanan hidangan itu" << endl;
        cout << "Alhasil, berat badan kamu naik menjadi" << GetWeight() << endl;
    }

}

void People::membeli()
{
    cout << "Selamat datang di toko!!" << endl;
    cout << "Berikut merupakan hal yang dapat Anda Beli" << endl;

    // TODO : nampilin barang yang bisa dibeli dr toko

    cout << "Uang Anda : " << Keuangan.GetMoney() << endl;
    cout << "Slot penyimpanan tersedia:" << endl;

    cout << "Barang ingin dibeli : ";
    int buy;
    cin >> buy;
    cout << endl;
    cout << "Kuantitas : ";
    int quantity;
    cin >> quantity;
    cout << endl;


    if(storage.getCellKosong() < quantity){
        throw StorageFullException();
    // TODO : else if Keuangan.GetMoney < ...getPrice() * quantity)
    }else{
        cout << "Selamat Anda berhasil membeli " << quantity << " ";
        // TODO : cout << nama barang yang dibeli (pake .getName)

        // TODO : Keuangan.kurangUang(quantity * ...getPrice())
        cout << ". Uang Anda tersisa " << Keuangan.GetMoney() << " gulden" << endl;

        cout << "Pilih slot untuk menyimpan barang yang Anda beli!" << endl;
        cetakPenyimpanan();

        cout << "Petak Slot: ";
        string slot;
        for (int i = 0; i < quantity; i++) {
            cin >> slot;
            cout << endl;
            int row = slot[0] - 'A';
            int col = slot[1] - '0';
            // TODO : storage.setItem(row, col, ITEM YANG DIBELI);
        }
        cout << "Barang berhasil disimpan!" << endl;

    }


}

void People::menjual()
{
    // Perintah untuk menjual barang yang dimiliki pada penyimpanan ke toko. Petani dan peternak tidak dapat menjual bangunan. Dalam sekali menjual, dapat dijual lebih dari satu barang. Proses menjual barang akan menambah kuantitas barang tersebut di Toko, kecuali untuk tanaman dan hewan yang berjumlah tak hingga. Apabila penyimpanan kosong, maka menjual tidak dapat dilakukan. Uang penjual akan langsung bertambah sesuai dengan harga jual. Perhatikan bahwa contoh di bawah ini hanya merupakan contoh saja, silahkan dikembangkan menurut kreativitas selama masih memenuhi spesifikasi yang diberikan.
    cout << "Berikut merupakan penyimpanan Anda" << endl;
    cetakPenyimpanan();

    cout << "Kuantitas barang yang ingin dijual : ";
    int quantity;
    cin >> quantity;
    cout << endl;

    cout << "Silahkan pilih petak yang ingin Anda jual!" << endl;
    for(int i=0; i<quantity; i++){
        cout << "Petak ke-" << i+1 << " : ";
        string slot;
        cin >> slot;
        cout << endl;
        int row = slot[0] - 'A';
        int col = slot[1] - '0';
        Item* item = storage(row, col);
        storage.deleteItem(row, col);
        Toko.addItems(item);
    }
}

