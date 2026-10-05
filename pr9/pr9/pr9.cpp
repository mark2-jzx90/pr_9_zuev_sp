// pr9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;
const int MAX_SIZE = 100;

void applyDiscount10(double* data, int size);
void applyDiscount20(double* data, int size);
void addFixedMarkup(double* data, int size);
void roundToInteger(double* data, int size);


void applyProcessing(double* data, int size, void (*processor)(double*, int)) {
    if (processor != nullptr) {
        processor(data, size);
    }
    else {
        cout << "Ошибка\n";
    }
}

void printArray(const double* data, int size) {
    if (size == 0) {
        cout << "Массив пустой\n";
        return;
    }
    for (int i = 0; i < size; ++i) {
        cout << data[i] << " ";
    }
    cout << "\n";
}

void copyArray(const double* src, double* dest, int size) {
    for (int i = 0; i < size; ++i) {
        dest[i] = src[i];
    }
}

int main() {
    double current_data[MAX_SIZE] = { 0 };
    double backup_data[MAX_SIZE] = { 0 };
    int current_size = 0;

    void (*processors[])(double*, int) = {
        applyDiscount10,
        applyDiscount20,
        addFixedMarkup,
        roundToInteger
    };
    int main_choice = 0;
    do {
        cout << "1 - Ввести данные\n";
        cout << "2 - Показать данные\n";
        cout << "3 - Выбрать и выполнить обработку\n";
        cout << "4 - Восстановить исходные данные\n";
        cout << "5 - Выход\n";
        cout << "Выбери пункт меню вась: ";
        cin >> main_choice;

        switch (main_choice) {
        case 1: {
            cout << "Введи кол-во товаров (макс. " << MAX_SIZE << "): ";
            cin >> current_size;
            if (current_size < 1 || current_size > MAX_SIZE) {
                cout << "некорректный размер вась\n";
                current_size = 0;
                break;
            }
            cout << "Введи цены товаров:\n";
            for (int i = 0; i < current_size; ++i) {
                cin >> current_data[i];
            }
            copyArray(current_data, backup_data, current_size);
            cout << "Данные сохранены\n";
            break;
        }
        case 2: {
            cout << "текущие цены товаров: ";
            printArray(current_data, current_size);
            break;
        }
        case 3: {
            if (current_size == 0) {
                cout << "Сначала введи данные (Пункт 1)!\n";
                break;
            }
            cout << "1 - Применить скидку 10%\n";
            cout << "2 -  Применить скидку 20%\n";
            cout << "3 - Добавить фиксированную наценку\n";
            cout << "4 - Округлить цены до целого значения\n";
            cout << "Выбери номер операции вась (1-4): ";
            int op_choice;
            cin >> op_choice;

            if (op_choice >= 1 && op_choice <= 4) {
                cout << "Массив до обработки: ";
                printArray(current_data, current_size);
                void (*selected_processor)(double*, int) = processors[op_choice - 1];
                applyProcessing(current_data, current_size, selected_processor);
                cout << "массив после обрабтки: ";
                printArray(current_data, current_size);
            }
            else {
                cout << "неверный номер операции\n";
            }
            break;
        }
        case 4: {
            if (current_size == 0) {
                cout << "нет данных для восстановления\n";
            }
            else {
                copyArray(backup_data, current_data, current_size);
                cout << "иисходные данные восстановлены\n";
            }
            break;
        }
        case 5:
            cout << "Выход из проги\n";
            break;
        default:
            cout << "Неверный пункт меню\n";
            break;
        }
    } while (main_choice != 5);

    return 0;
}

//скидка 10%
void applyDiscount10(double* data, int size) {
    for (int i = 0; i < size; ++i) {
        data[i] = data[i] * 0.90;
    }
}

//скидка 20%
void applyDiscount20(double* data, int size) {
    for (int i = 0; i < size; ++i) {
        data[i] = data[i] * 0.80;
    }
}

//добавить фиксированную наценку
void addFixedMarkup(double* data, int size) {
    const double MARKUP = 50.0;
    for (int i = 0; i < size; ++i) {
        data[i] = data[i] + MARKUP;
    }
}

//округлить цены до целого знач
void roundToInteger(double* data, int size) {
    for (int i = 0; i < size; ++i) {
        data[i] = (int)(data[i] + 0.5);
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
