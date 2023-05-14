#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Calculator {
protected:
    vector<double> numbers;

public:
    virtual void addNumber(double number) = 0;
    virtual double getResult() = 0;
    virtual void clear() {
        numbers.clear();
    }
};

class BasicCalculator : public Calculator {
public:
    void addNumber(double number) {
        numbers.push_back(number);
    }

    double getResult() {
        double result = 0;
        for (double number : numbers) {
            result += number;
        }
        return result;
    }

    double subtract() {
        double result = numbers[0];
        for (int i = 1; i < numbers.size(); i++) {
            result -= numbers[i];
        }
        return result;
    }

    double multiply() {
        double result = 1;
        for (double number : numbers) {
            result *= number;
        }
        return result;
    }

    double divide() {
        double result = numbers[0];
        for (int i = 1; i < numbers.size(); i++) {
            if (numbers[i] != 0) {
                result /= numbers[i];
            } else {
                cout << "Error: Pembagian oleh nol tidak valid." << endl;
                return 0;
            }
        }
        return result;
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
        numbers.push_back(number);
    }

    double getResult() {
        return numbers[0];
    }

    double squareRoot() {
        return sqrt(numbers[0]);
    }

    double exponentiation() {
        return pow(numbers[0], numbers[1]);
    }

    double factorial() {
        int n = static_cast<int>(numbers[0]);
        int result = 1;
        for (int i = 2; i <= n; i++) {
            result *= i;
        }
        return result;
    }

    double sine() {
        return Trigonometry::sine(numbers[0]);
    }

    double cosine() {
        return Trigonometry::cosine(numbers[0]);
    }

    double tangent() {
        return Trigonometry::tangent(numbers[0]);
    }
};

int main() {
    BasicCalculator basicCalc;
    ScientificCalculator scientificCalc;
    int kalkulator;
    int operasi1;
    int operasi2;
    double input1, input2, input;

    cout << "===== Calculadora sederhana ======" << endl;

    while (true) {
        cout << " " << endl;
        cout << "Menu Utama" << endl;
        cout << "1. Kalkulator Dasar\n2. Kalkulator Saintifik\n3. Keluar" << endl;
        cout << "Pilih kalkulator : ";
        cin >> kalkulator;

        if (kalkulator == 1) {
            cout << " " << endl;
            cout << "Menu Kalkulator Dasar" << endl;
            cout << "1. Penjumlahan\n2. Pengurangan\n3. Perkalian\n4. Pembagian" << endl;
            cout << "Pilih operasi : ";
            cin >> operasi1;

            if (operasi1 == 1) {
                while (operasi1 == 1)
        {
                    cout << "Masukkan angka (masukkan 'x' untuk berhenti): ";
                    while (cin >> input) {
                        basicCalc.addNumber(input);
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
                cout << "Hasil penjumlahan: " << basicCalc.getResult() << endl;
            } else if (operasi1 == 2) {
                while (operasi1 == 2) {
                    cout << "Masukkan angka (masukkan 'x' untuk berhenti): ";
                    while (cin >> input) {
                        basicCalc.addNumber(input);
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
                cout << "Hasil pengurangan: " << basicCalc.subtract() << endl;
            } else if (operasi1 == 3) {
                while (operasi1 == 3) {
                    cout << "Masukkan angka (masukkan 'x' untuk berhenti): ";
                    while (cin >> input) {
                        basicCalc.addNumber(input);
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
                cout << "Hasil perkalian: " << basicCalc.multiply() << endl;
            } else if (operasi1 == 4) {
                while (operasi1 == 3) {
                    cout << "Masukkan angka (masukkan 'x' untuk berhenti): ";
                    while (cin >> input) {
                        basicCalc.addNumber(input);
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
                cout << "Hasil pembagian: " << basicCalc.divide() << endl;
            } else {
                cout << "Operasi tidak valid." << endl;
            }
        } else if (kalkulator == 2) {
            cout << " " << endl;
            cout << "Menu Kalkulator Saintifik" << endl;
            cout << "1. Akar Kuadrat\n2. Pangkat\n3. Faktorial\n4. Sin\n5. Cos\n6. Tan" << endl;
            cout << "Pilih operasi : ";
            cin >> operasi2;

            if (operasi2 == 1) {
                cout << "Masukkan angka: ";
                cin >> input1;
                scientificCalc.addNumber(input1);
                cout << "Hasil akar kuadrat: " << scientificCalc.squareRoot() << endl;
            } else if (operasi2 == 2) {
                cout << "Masukkan angka: ";
                cin >> input1;
                cout << "Masukkan angka: ";
                cin >> input2;
                scientificCalc.addNumber(input1);
                scientificCalc.addNumber(input2);
                cout << "Hasil pemangkatan: " << scientificCalc.exponentiation () << endl;
                cout << "Hasil pemangkatan: " << scientificCalc.exponentiation() << endl;
            } else if (operasi2 == 3) {
                cout << "Masukkan angka: ";
                cin >> input1;
                scientificCalc.addNumber(input1);
                cout << "Hasil faktorial: " << scientificCalc.factorial() << endl;
            } else if (operasi2 == 4) {
                cout << "Masukkan angka: ";
                cin >> input1;
                scientificCalc.addNumber(input1);
                cout << "Hasil sine: " << scientificCalc.sine() << endl;
            } else if (operasi2 == 5) {
                cout << "Masukkan angka: ";
                cin >> input1;
                scientificCalc.addNumber(input1);
                cout << "Hasil cosine: " << scientificCalc.cosine() << endl;
            } else if (operasi2 == 6) {
                cout << "Masukkan angka: ";
                cin >> input1;
                scientificCalc.addNumber(input1);
                cout << "Hasil tangent: " << scientificCalc.tangent() << endl;
            } else {
                cout << "Operasi tidak valid." << endl;
            }
        } else if (kalkulator == 3) {
            cout << "Terima kasih telah menggunakan kalkulator." << endl;
            break;
        } else {
            cout << "Kalkulator tidak valid." << endl;
        }
    }

    return 0;
}
