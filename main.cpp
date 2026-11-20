#include <iostream>
using namespace std;

#define MAX 100 // Ukuran maksimal stack

class Stack {
private:
    int data[MAX];
    int top;

public:
    // Konstruktor: inisialisasi stack kosong
    Stack() {
        top = -1;
    }

    // Cek stack kosong
    bool isEmpty() {
        return (top == -1);
    }

    // Cek stack penuh
    bool isFull() {
        return (top == MAX - 1);
    }

    // Tambah data ke stack (push)
    void push(int nilai) {
        if (isFull()) {
            cout << "Stack Penuh! Tidak bisa menambah data\n";
            return;
        }
        top++;
        data[top] = nilai;
        cout << "Berhasil push: " << nilai << endl;
    }

    // Hapus data teratas stack (pop)
    void pop() {
        if (isEmpty()) {
            cout << "Stack Kosong! Tidak ada data untuk di‑pop\n";
            return;
        }
        cout << "Data yang dihapus (pop): " << data[top] << endl;
        top--;
    }

    // Lihat data teratas (peek)
    int peek() {
        if (isEmpty()) {
            cout << "Stack Kosong! Tidak ada data peek\n";
            return -9999; // Nilai penanda error
        }
        return data[top];
    }

    // Ukuran jumlah elemen stack
    int size() {
        return top + 1;
    }
};

// Fungsi main untuk uji coba
int main() {
    Stack s;
    int pilih, nilai;

    do {
        cout << "\n===== MENU STACK =====" << endl;
        cout << "1. Push (Tambah data)" << endl;
        cout << "2. Pop (Hapus data teratas)" << endl;
        cout << "3. Peek (Lihat data teratas)" << endl;
        cout << "4. Cek apakah kosong (isEmpty)" << endl;
        cout << "5. Ukuran Stack (size)" << endl;
        cout << "6. Keluar" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                cout << "Masukkan angka yang akan di‑push: ";
                cin >> nilai;
                s.push(nilai);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                if(!s.isEmpty()) cout << "Data teratas (peek): " << s.peek() << endl;
                break;
            case 4:
                if (s.isEmpty()) cout << "Status: Stack KOSONG\n";
                else cout << "Status: Stack TIDAK kosong\n";
                break;
            case 5:
                cout << "Jumlah data (size): " << s.size() << endl;
                break;
            case 6:
                cout << "Program selesai\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilih != 6);

    return 0;
}
