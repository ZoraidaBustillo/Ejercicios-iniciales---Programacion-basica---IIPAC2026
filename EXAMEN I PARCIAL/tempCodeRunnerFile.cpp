#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

const int NUM_PRODUCTOS = 12;
const double TASA_DOLAR = 26.42;
const double ISV = 0.15;

// ================= PRODUCTOS =================
string nombresProductos[NUM_PRODUCTOS] = {
    "Puma A55","Puma i13","Puma Mini","PumaBook 15",
    "PumaGamer X","PumaDesk","PumaTab","PumaPad Air",
    "PumaPrint","Audifonos BT","Mouse","Teclado"
};

string categoriasProductos[NUM_PRODUCTOS] = {
    "Celulares","Celulares","Celulares",
    "Laptops","Laptops","Laptops",
    "Tablets","Tablets","Tablets",
    "Accesorios","Accesorios","Accesorios"
};

double preciosProductos[NUM_PRODUCTOS] = {
    6800,19500,1800,18900,32500,14800,7900,16500,4500,650,350,1250
};

int inventarioProductos[NUM_PRODUCTOS] = {
    18,8,20,10,6,7,12,6,9,30,40,15
};

int puntosProductos[NUM_PRODUCTOS] = {
    120,250,60,220,350,180,140,230,90,25,15,45
};

// ================= VALIDACION =================
int validarEntero(string msg, int min, int max) {
    int x;
    while (true) {
        cout << msg;
        cin >> x;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Opcion invalida.\n";
            continue;
        }

        if (x >= min && x <= max) return x;

        cout << "Opcion invalida.\n";
    }
}

// ================= SI / NO =================
bool opcionSiNo(string msg) {
    int op;
    while (true) {
        cout << "\n" << msg << "\n";
        cout << "1. SI\n2. NO\nOpcion: ";
        cin >> op;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Opcion invalida.\n";
            continue;
        }

        if (op == 1) return true;
        if (op == 2) return false;

        cout << "Opcion invalida.\n";
    }
}

// ================= GENERO =================
char validarGenero() {
    int op;
    while (true) {
        cout << "\nGENERO\n1. Masculino\n2. Femenino\nOpcion: ";
        cin >> op;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Opcion invalida.\n";
            continue;
        }

        if (op == 1) return 'M';
        if (op == 2) return 'F';

        cout << "Opcion invalida.\n";
    }
}

// ================= MENU =================
void mostrarMenu() {
    cout << "\n================ PUMA TECH STORE ================\n";

    cout << left
         << setw(4) << "ID"
         << setw(25) << "PRODUCTO"
         << setw(15) << "CATEGORIA"
         << setw(10) << "PRECIO"
         << setw(8) << "STOCK" << "\n";

    cout << "------------------------------------------------------------\n";

    for (int i = 0; i < NUM_PRODUCTOS; i++) {
        cout << left
             << setw(4) << i + 1
             << setw(25) << nombresProductos[i]
             << setw(15) << categoriasProductos[i]
             << setw(10) << preciosProductos[i]
             << setw(8) << inventarioProductos[i] << "\n";
    }
}

// ================= FACTURA (ARREGLADA) =================
void factura(string nombre, int edad, char genero, int tipo,
             int cant[], double &total, double &usd,
             int &puntos, double &desc, double &isv) {

    double subtotal = 0;
    double descuento = 0;
    int puntosTotal = 0;

    cout << "\n==================== FACTURA ====================\n";
    cout << "Cliente: " << nombre << "\n";
    cout << "Edad: " << edad << "\n";
    cout << "Genero: " << (genero == 'M' ? "Masculino" : "Femenino") << "\n";

    cout << "\nDETALLE DE COMPRA:\n";
    cout << "-------------------------------------------------\n";

    for (int i = 0; i < NUM_PRODUCTOS; i++) {
        if (cant[i] > 0) {

            double sub = preciosProductos[i] * cant[i];
            double d = 0;

            // descuentos cliente
            if (tipo == 1 && categoriasProductos[i] == "Accesorios") d += 0.08;
            if (tipo == 2 && categoriasProductos[i] == "Laptops") d += 0.10;
            if (tipo == 3 && categoriasProductos[i] == "Tablets") d += 0.12;

            // genero
            if (genero == 'F' && categoriasProductos[i] == "Accesorios") d += 0.10;
            if (genero == 'M' && categoriasProductos[i] == "Laptops") d += 0.05;

            double descProd = sub * d;

            subtotal += sub;
            descuento += descProd;
            puntosTotal += puntosProductos[i] * cant[i];

            cout << left
                 << setw(25) << nombresProductos[i]
                 << "x" << cant[i] << "\n";
        }
    }

    double subtotalFinal = subtotal - descuento;
    isv = subtotalFinal * ISV;
    total = subtotalFinal + isv;
    usd = total / TASA_DOLAR;

    puntos = puntosTotal;
    desc = descuento;

    cout << "\n---------------- RESUMEN ----------------\n";
    cout << "Subtotal: Lps " << subtotal << "\n";
    cout << "Descuentos: Lps " << descuento << "\n";
    cout << "ISV (15%): Lps " << isv << "\n";
    cout << "TOTAL: Lps " << total << "\n";
    cout << "USD: $" << usd << "\n";
    cout << "Puntos: " << puntos << "\n";
}

// ================= MAIN =================
int main() {

    string nombre;
    int edad, tipo;
    char genero;

    cout << "===== BIENVENIDO A PUMA TECH STORE =====\n";

    do {
        int cant[NUM_PRODUCTOS] = {0};

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\nNombre cliente: ";
        getline(cin, nombre);

        edad = validarEntero("Edad: ", 1, 120);
        genero = validarGenero();

        cout << "\nTIPO CLIENTE\n";
        cout << "1. Estudiante\n2. Profesional\n3. Corporativo\n";
        tipo = validarEntero("Opcion: ", 1, 3);

        do {
            mostrarMenu();

            int cod = validarEntero("Seleccione producto (1-12): ", 1, 12) - 1;
            int cantidad = validarEntero("Cantidad: ", 1, inventarioProductos[cod]);

            cant[cod] += cantidad;
            inventarioProductos[cod] -= cantidad;

        } while (opcionSiNo("Desea agregar otro producto?"));

        double total, usd, desc, isv;
        int puntos;

        factura(nombre, edad, genero, tipo, cant, total, usd, puntos, desc, isv);

        int pago = validarEntero("\nPago:\n1. Efectivo\n2. Transferencia\nOpcion: ", 1, 2);

        if (pago == 1) {
            double dinero;

            cout << "Ingrese efectivo: Lps ";
            cin >> dinero;

            while (dinero < total) {
                cout << "Falta: Lps " << (total - dinero) << "\n";
                cout << "Ingrese efectivo: Lps ";
                cin >> dinero;
            }

            cout << "Cambio: Lps " << (dinero - total) << "\n";
        }
        else {
            string ref;
            cout << "Referencia transferencia: ";
            cin >> ref;
        }

    } while (opcionSiNo("Desea ingresar otro cliente?"));

    cout << "\nFIN DEL PROGRAMA\n";
}