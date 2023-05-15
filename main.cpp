 
#include <iostream>
#include <cmath>

using namespace std;

class Calculator {
protected:
    double numbers [100];
    int count;
    double input;
    double input1, input2;

public:
    Calculator() : count (0){}
    virtual void addNumber(double number) = 0;
    virtual double getResult() = 0;
    virtual void clear() {
        count=0;
    }
};

class BasicCalculator : public Calculator {
public:
    void addNumber(double number) {
        numbers[count] = number;
        count++;
    }

    double getResult() {
        double result = 0;
        for (double number : numbers) {
            result += number;
        }
        clear();
        return result;
    }

    double jumlah() {
        while (true){
                cout << "Masukkan angka (masukkan 'x' untuk berhenti): ";
                while (cin >> input) {
                        addNumber(input);
                        cout << "Masukkan angka (masukkan 'x' untuk berhenti) : ";
                }
                if (cin.fail()) {
                    string stopSignal;
                    cin.clear();
                    cin >> stopSignal;
                        if (stopSignal == "x") {
                            break;
                        }
                }
        }
        cout << "Hasil penjumlahan: " << getResult() << endl;
    }

    double subtract() {
        double result = numbers[0];
        for (int i = 1; i < count ; i++) {
            result -= numbers[i];
        }
        clear();
        return result;
    }

    double kurang() {
        while (true){
                cout << "Masukkan angka (masukkan 'x' untuk berhenti): ";
                while (cin >> input) {
                        addNumber(input);
                        cout << "Masukkan angka (masukkan 'x' untuk berhenti) : ";
                }
                if (cin.fail()) {
                    string stopSignal;
                    cin.clear();
                    cin >> stopSignal;
                        if (stopSignal == "x") {
                            break;
                        }
                }
        }
        cout << "Hasil penjumlahan: " << subtract() << endl;
    }

    double multiply() {
        double result = 1;
        for (int i = 0; i < count; i++){
            result *= numbers[i];
        }
        clear();
        return result;
    }

    double kali() {
        while (true){
                cout << "Masukkan angka (masukkan 'x' untuk berhenti): ";
                while (cin >> input) {
                        addNumber(input);
                        cout << "Masukkan angka (masukkan 'x' untuk berhenti) : ";
                }
                if (cin.fail()) {
                    string stopSignal;
                    cin.clear();
                    cin >> stopSignal;
                        if (stopSignal == "x") {
                            break;
                        }
                }
        }
        cout << "Hasil penjumlahan: " << multiply() << endl;
    }

    double divide() {
        double result = numbers[0];
        for (int i = 1; i < count; i++) {
            if (numbers[i] != 0) {
                result /= numbers[i];
            } else {
                cout << "Error: Pembagian oleh nol tidak valid." << endl;
                return 0;
            }
        }
        clear();
        return result;
    }

    double bagi() {
        while (true){
                cout << "Masukkan angka (masukkan 'x' untuk berhenti): ";
                while (cin >> input) {
                        addNumber(input);
                        cout << "Masukkan angka (masukkan 'x' untuk berhenti) : ";
                }
                if (cin.fail()) {
                    string stopSignal;
                    cin.clear();
                    cin >> stopSignal;
                        if (stopSignal == "x") {
                            break;
                        }
                }
        }
        cout << "Hasil penjumlahan: " << divide() << endl;
    }
};

class Trigonometry {
public:
    static double sine(double angle) {
        return sin(angle);
    }

    static double cosine(double angle) {
        return cos(angle);
    }

    static double tangent(double angle) {
        return tan(angle);
    }
};

class ScientificCalculator : public Calculator {
public:
    void addNumber(double number) {
        numbers[count] = number;
        count++;
    }

    double getResult() {
        clear();
        return numbers[0];
    }

    double squareRoot() {
        clear();
        return sqrt(numbers[0]);
    }

    double akarKuadrat() {
        cout << "Masukkan angka: ";
        cin >> input1;
        addNumber(input1);
        cout << "Hasil akar kuadrat: " << squareRoot() << endl;
    }

    double exponentiation() {
        clear();
        return pow(numbers[0], numbers[1]);
    }

    double pangkat() {
        cout << "Masukkan angka: ";
        cin >> input1;
        cout << "Masukkan angka: ";
        cin >> input2;
        addNumber(input1);
        addNumber(input2);
        cout << "Hasil pemangkatan: " << exponentiation () << endl;
    }

    double factorial() {
        int n = static_cast<int>(numbers[0]);
        int result = 1;
        for (int i = 2; i <= n; i++) {
            result *= i;
        }
        clear();
        return result;
    }

    double faktorial() {
        cout << "Masukkan angka: ";
        cin >> input1;
        addNumber(input1);
        cout << "Hasil faktorial: " << factorial() << endl;
    }

    double sine() {
        clear();
        return Trigonometry::sine(numbers[0]);
    }

    double sin() {
        cout << "Masukkan angka: ";
        cin >> input1;
        addNumber(input1);
        cout << "Hasil sinus: " << sine() << endl;
    }

    double cosine() {
        clear();
        return Trigonometry::cosine(numbers[0]);
    }

    double cos() {
        cout << "Masukkan angka: ";
        cin >> input1;
        addNumber(input1);
        cout << "Hasil cosinus: " << cosine() << endl;
    }

    double tangent() {
        clear();
        return Trigonometry::tangent(numbers[0]);
    }

    double tan() {
        cout << "Masukkan angka: ";
        cin >> input1;
        addNumber(input1);
        cout << "Hasil tangent: " << tangent() << endl;
    }
};

int main() {
    BasicCalculator basicCalc;
    ScientificCalculator scientificCalc;
    string kalkulator;
    string operasi1;
    string operasi2;

    cout << "===== Kalkulator Sederhana ======" << endl;

    while (true) {
        cout << " " << endl;
        cout << "Menu Utama" << endl;
        cout << "1. Kalkulator Dasar\n2. Kalkulator Saintifik\n3. Keluar" << endl;
        cout << "Pilih kalkulator : ";
        cin >> kalkulator;

        if (kalkulator[0] == 49) {
            cout << endl;
            cout << "Menu Kalkulator Dasar" << endl;
            cout << "1. Penjumlahan\n2. Pengurangan\n3. Perkalian\n4. Pembagian" << endl;
            cout << "Pilih operasi : ";
            cin >> operasi1;

            if (operasi1[0] == 49) {
                basicCalc.jumlah();
            } else if (operasi1[0] == 50) {
                basicCalc.kurang();
            } else if (operasi1[0] == 51) {
                basicCalc.kali();
            } else if (operasi1[0] == 52) {
                basicCalc.bagi();
            } else {
                cout << "Operasi tidak valid." << endl;
            }

        } else if (kalkulator[0] == 50) {
            cout <<  endl;
            cout << "Menu Kalkulator Saintifik" << endl;
            cout << "1. Akar Kuadrat\n2. Pangkat\n3. Faktorial\n4. Sin\n5. Cos\n6. Tan" << endl;
            cout << "Pilih operasi : ";
            cin >> operasi2;

            if (operasi2[0] == 49) {
                scientificCalc.akarKuadrat();
            } else if (operasi2[0] == 50) {
                scientificCalc.pangkat();
            } else if (operasi2[0] == 51) {
                scientificCalc.faktorial();
            } else if (operasi2[0] == 52) {
                scientificCalc.sin();
            } else if (operasi2[0] == 53) {
                scientificCalc.cos();
            } else if (operasi2[0] == 54) {
                scientificCalc.tan();
            } else {
                cout << "Operasi tidak valid." << endl;
            }
        } else if (kalkulator[0] == 51) {
            cout << "Terima kasih telah menggunakan kalkulator." << endl;
            break;
        } else {
            cout << "Kalkulator tidak valid." << endl;
        }
    }

    return 0;
}
