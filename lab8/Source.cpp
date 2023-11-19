#include <iostream>
#include <Windows.h>
    

    class Triad {
    protected:
        int a, b, c;

    public:
        Triad(int a, int b, int c) : a(a), b(b), c(c) {}

        virtual void display() {
            std::cout << "Triad: " << a << ", " << b << ", " << c << std::endl;
        }

        virtual bool isEqual(Triad* other) {
            return (a == other->a && b == other->b && c == other->c);
        }
    };

    class Date : public Triad {
    public:
        Date(int year, int month, int day) : Triad(year, month, day) {}

        void display() override {
            std::cout << "Date: " << a << " " << b << " " << c << std::endl;
        }

        bool isEqual(Triad* other) override {
            Date* date = dynamic_cast<Date*>(other);
            if (date) {
                return (a == date->a && b == date->b && c == date->c);
            }
            return false;
        }
    };

    Triad* getObjectFromUser() {
        int a, b, c;
        std::cout << "Ведіть дату у форматі 2023, 11, 19 через пробіл: ";
        std::cin >> a >> b >> c;
        return new Triad(a, b, c);
    }

    int main() {
        SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
        Triad* triad1 = getObjectFromUser();
        Triad* triad2 = new Date(2023, 11, 19);

        triad1->display();
        triad2->display();

        if (triad1->isEqual(triad2)) {
            std::cout << "Сьогоднішня дата." << std::endl;
        }
        else {
            std::cout << "Дата не співпадає." << std::endl;
        }

        delete triad1;
        delete triad2;

        return 0;
    }
