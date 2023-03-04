#include <iostream>
#include<math.h>


using namespace std;
void menu()
{
    cout << "Wybierz operacje: " << endl;
    cout << " 1 - dodawanie," << endl;
    cout << " 2 - odejmowanie," << endl;
    cout << " 3 - mnozenie," << endl;
    cout << " 4 - dzielenie," << endl;
    cout << " 5 - obliczanie pierwiastkow," << endl;
    cout << " 6 - obliczenie sredniej," << endl;
    cout << " 0 - wyjscie." << endl;
}
float dodawanie(float a, float b)
{
    return a + b;
}
float odejmowanie(float a, float b)
{
    return a - b;
}
float mnozenie(float a, float b)
{
    return a * b;
}
float dzielenie(float a, float b)
{
    return a / b;
}
double fdelta(double a, double b, double c)
{
    return b * b - 4 * a * c;
}
double fpierwiastek(double a, double b)
{
    return (-b) / (2 * a);
}
double fpierwiastek(double a, double b, double sdelta)
{
    return (-b - sdelta) / (2 * a);
}
float srednia(float suma, int i)
{
    return (suma / i);
}
int main()
{
    char c;
    float a, b;
    menu();
    do
    {
        cout << ">: ";
        cin >> c;
        if (c > '0' && c < '5')
        {
            cout << "Podaj pierwsza liczbe: ";
            cin >> a;
            cout << "Podaj druga liczbe: ";
            cin >> b;
            if (c == '1')
            {
                cout << "Wynik: " << dodawanie(a, b) << endl;
            }
            if (c == '2')
            {
                cout << "Wynik: " << odejmowanie(a, b) << endl;
            }
            if (c == '3')
            {
                cout << "Wynik: " << mnozenie(a, b) << endl;
            }
            if (c == '4')
            {
                cout << "Wynik: " << dzielenie(a, b) << endl;
            }
        }
        if (c == '5')
        {
            double a, b, c, delta, x1, x2;
            cout << "a = ";
            cin >> a;
            cout << "b = ";
            cin >> b;
            cout << "c = ";
            cin >> c;
            delta = fdelta(a, b, c);
            if (delta < 0)
            {
                cout << "Rownanie nie posiada pierwiastkow." << endl;
            }
            else
            {
                if (delta == 0)
                {
                    x1 = fpierwiastek(a, b);
                    cout << "Rownanie posiada jeden pierwiastek" << endl;
                    cout << "x = " << x1 << endl;
                }
                else
                {
                    x1 = fpierwiastek(a, b, sqrt(delta));
                    x2 = fpierwiastek(a, b, -sqrt(delta));
                    cout << "Rownanie posiada dwa pierwiastki" << endl;
                    cout << "x1 = " << x1 << endl;
                    cout << "x2 = " << x2 << endl;
                }
            }
            return 0;
        }
        if (c == '6')
        {

            float suma = 0;
            int x, i = 0;
            do
            {
                cout << "Podaj liczbe z przedzialu 1-6 lub aby zakonczyc liczenie sredniej kliknij 0 " << endl;
                cin >> x;
                if (x == 0)
                {
                    if (i == 0)
                    {
                        cout << "nie podales zadnej liczby, nie mozna policzyc sredniej" << endl;
                        break;
                    }
                    else
                    {
                        cout << "srednia = " << srednia(suma, i) << endl;
                        break;
                    }
                }
                if (x < 1 or x > 6)
                {
                    cout << "Podales liczbe z poza przedzialu" << endl;
                    continue;
                }
                else
                {
                    i++;
                    suma += x;
                    cout << "srednia = " << srednia(suma, i) << endl;

                }

            } while (x != '0');
            return 0;

        }


    } while (c != '0');
    return 0;
}