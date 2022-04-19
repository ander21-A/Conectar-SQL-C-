// mysql_c.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <mysql.h>
#include <iostream>
using namespace std;
int q_estado;
int main()
{
    MYSQL* conectar;
    MYSQL_ROW fila;
    MYSQL_RES* resultado;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "as_tienda", "Tiend@123", "bd_tienda", 3306, NULL, 0);
    if (conectar) {
        //cout << "Conexion Exitosa...."<< endl;
        string marca;
        cout << "Ingrese Marca: ";
        cin >> marca;
        string insert = "Insert into marcas(marca) values('" + marca + "')";
        const char* i = insert.c_str();
        q_estado = mysql_query(conectar, i);
        if (!q_estado) {
            cout << "Ingreso Exitoso...." << endl;
        }
        else {
            cout << "Ingreso Fallido...." << endl;
        }

        string consulta = "select * from marcas";
        const char* c = consulta.c_str();
        q_estado = mysql_query(conectar, c);
        if (!q_estado) {
            resultado = mysql_store_result(conectar);
            while (fila = mysql_fetch_row(resultado)) {
                cout << fila[0] << "," << fila[1] << endl;
            }
        }
        else {
            cout << "Error al cunsultar...." << endl;
        }
    }
    else {
        cout << "Conexion Fallida...." << endl;
    }
    system("pause");
    return 0; 
}

