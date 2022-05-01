// Examen.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <mysql.h>
#include <iostream>
#include <string> 

using namespace std;
int q_estado;
int main()

{
	MYSQL* conectar;
	MYSQL_ROW fila;
	MYSQL_RES* resultado;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "root", "root", "prueba", 3307, NULL, 0);
	if (conectar) {
		
		string carnet, nombres, apellidos, direccion, genero, email, fecha;
		int telefono, id, opcion;

		cout << "MENU"<<endl;
		cout << "1. Insertar"<<endl;
		cout << "2. Actualizar" << endl;
		cout << "3. Eliminar" << endl;
		cout << "4. Listado" << endl;
		cin >> opcion;

		switch (opcion) {
		case 1: {
			system("cls");
			cout << "Ingrese carnet:";
			cin >> carnet;

			cout << "Ingrese nombres:";
			cin >> nombres;

			cout << "Ingrese apellidos:";
			cin >> apellidos;

			cout << "Ingrese direccion:";
			cin >> direccion;

			cout << "Ingrese genero:";
			cin >> genero;

			cout << "Ingrese email:";
			cin >> email;

			cout << "Ingrese telefono:";
			cin >> telefono;

			cout << "Ingrese fecha:";
			cin >> fecha;

			string insert = "insert into prueba.estudiantes(`carnet`,`nombres`, `apellidos`,`direccion`,`genero`, `email`,`fecha_nacimiento`,`telefono`) value ('" + carnet + "','" + nombres + "','" + apellidos + "','" + direccion + "',b'" + genero + "','" + email + "','" + fecha + "'," + to_string(telefono) + ")";
			cout << insert;
			const char* i = insert.c_str();
			q_estado = mysql_query(conectar, i);
			if (!q_estado) {
				cout << "Ingreso existoso";
			}
			else {
				cout << "Error al ingresar";
			}
			break;
		}
		case 2: {
			system("cls");
			cout << "Ingrese IdEstudiante:";
			cin >> id;

			cout << "Ingrese carnet:";
			cin >> carnet;

			cout << "Ingrese nombres:";
			cin >> nombres;

			cout << "Ingrese apellidos:";
			cin >> apellidos;

			cout << "Ingrese direccion:";
			cin >> direccion;

			cout << "Ingrese genero:";
			cin >> genero;

			cout << "Ingrese email:";
			cin >> email;

			cout << "Ingrese telefono:";
			cin >> telefono;

			cout << "Ingrese fecha:";
			cin >> fecha;

			string update = "update prueba.estudiantes  SET carnet = '" + carnet + "', nombres = '" + nombres + "', apellidos = '" + apellidos + "', direccion = '" + direccion + "', genero = b'" + genero + "', email = '" + email + "', telefono = " + to_string(telefono) + "  where idEstudiantes = " + to_string(id) + "  ";
			cout << update;
			const char* i = update.c_str();
			q_estado = mysql_query(conectar, i);
			if (!q_estado) {
				cout << "Actualizo existoso";
			}
			else {
				cout << "Error al ingresar";
			}
			break;
		}
		case 3: {
			system("cls");
			cout << "Ingrese Id estudiante:";
			cin >> id;

			string deleteSQL = "DELETE FROM prueba.estudiantes WHERE idEstudiantes = " + to_string(id) + "; ";
			cout << deleteSQL;
			const char* i = deleteSQL.c_str();
			q_estado = mysql_query(conectar, i);
			if (!q_estado) {
				cout << "Elimino existoso";
			}
			else {
				cout << "Error al ingresar";
			}
			break;
		}
		case 4: {
			system("cls");
			cout << "Ingrese Id estudiante:";
			cin >> id;

			string selectSQL = "Select * from prueba.estudiantes WHERE idEstudiantes = " + to_string(id) + "; ";

			const char* i = selectSQL.c_str();
			q_estado = mysql_query(conectar, i);
			if (!q_estado) {

				resultado = mysql_store_result(conectar);
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << fila[2] << "," << fila[3];
				}
			}
			else {
				cout << "Error al ingresar";
			}
			break;
		}
		}



	}
	else {
		cout << "2";
	}
}
