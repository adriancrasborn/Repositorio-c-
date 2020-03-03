#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

struct Nodo{
int dato;
Nodo *der;
Nodo *izq;	
Nodo *padre;
};
void menu();
Nodo *crearNodo(int,Nodo *);
void insertarNodo(Nodo *&,int,Nodo*);
void mostrarArbol(Nodo *,int);
bool busqueda(Nodo *,int);
void preOrden(Nodo *);
Nodo *arbol=NULL;
void inOrden(Nodo *);
void postOrden(Nodo *);
void eliminar(Nodo *, int);
void eliminarNodo(Nodo *);
Nodo *minimo(Nodo *);
void reemplazar(Nodo *,Nodo *);
void destruirNodo(Nodo *);
int main(){
	menu();
	
	getch();
	return 0;
}
void menu(){
	int dato,opcion,contador=0;
	
	do{
		cout<<"\t.:Menu:."<<endl;
		cout<<"1. Insertar un nuevo nodo"<<endl;
		cout<<"2. Mostrar el arbol completo"<<endl;
		cout<<"3. Buscar un elemento en el arbol"<<endl;
		cout<<"4. Recorrer el arbol en pre orden"<<endl;
		cout<<"5. Recorrer el arbol en in orden"<<endl;
		cout<<"6. Recorrer el arbol en post orden"<<endl;
		cout<<"7. Eliminar un nodo del arbol"<<endl;
		cout<<"8. salir"<<endl;
		cout<<"Opcion:";
		cin>>opcion;
		
		switch(opcion){
			case 1: cout<<"\nDigite un numero:";
			        cin>>dato;
			        insertarNodo(arbol,dato,NULL);
			        cout<<"\n";
			        system("pause");
			        break;
			case 2: cout<<"\nMostrando el arbol completo\n\n";
			        mostrarArbol(arbol,contador);
					cout<<"\n";
					system("pause");
					break;
			case 3: cout<<"\nDigite el elemento a buscar";
			        cin>>dato;
					if(busqueda(arbol,dato) == true){
						cout<<"El elemento "<<dato<<" Ha sido encontrado en el arbol"<<endl;
					}		        
					else{
						cout<<"Elemento no encontrado";
					}
					cout<<"\n";
					system("pause");
					break;
			case 4:	cout<<"\nRecorrido en Preorden:";
			        preOrden(arbol);
			        cout<<"\n\n";
			        system("pause");
			        break;
			case 5: cout<<"\nRecorriedo en Inorden";
			        inOrden(arbol);
			        cout<<"\n\n";
			        system("pause");
			        break;   
			case 6: cout<<"\nRecorriedo en postorden";
			        postOrden(arbol);
			        cout<<"\n\n";
			        system("pause");
			        break;
			case 7: cout<<"\nDigite el numero a eliminar:";
			        cin>>dato;
					eliminar(arbol,dato);
					cout<<"\n";
					system("pause");
					break;		  		   
		}
		system("cls");
	}while(opcion !=8);
	
}
// funcion para insertar elemenentos en el arbol
Nodo *crearNodo(int n,Nodo *padre){
	Nodo *nuevo_nodo = new Nodo();
	
	nuevo_nodo->dato = n;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;
	nuevo_nodo->padre = padre;
	return nuevo_nodo;
}
// funcion elem,entos para insertar elementos en el arbol

void insertarNodo(Nodo *&arbol,int n,Nodo *padre){
	if(arbol==NULL){ // si el arbol esta vacio
 	   	Nodo *nuevo_nodo = crearNodo (n,padre);
 	   	arbol = nuevo_nodo;
	}
	else{ // si el arbol tiene un nodo o mas nodos
		int valorRaiz = arbol->dato;
		if(n < valorRaiz){
			insertarNodo(arbol->izq,n,arbol);
		}
		else{
				insertarNodo(arbol->der,n,arbol);
		}
	}
}
void mostrarArbol(Nodo *arbol,int cont){
	if(arbol == NULL){
		return;
	}
	else{
		mostrarArbol(arbol->der,cont+1);
		for(int i=0;i<cont;i++){
			cout<<"   ";
		}
		cout<<arbol->dato<<endl;
		mostrarArbol(arbol->izq,cont+1);
	}
	
}

bool busqueda(Nodo *arbol,int n){
	
	if(arbol==NULL){
		return false;
	}
	else if(arbol ->dato == n){
			return true;
		}
	else if(n < arbol->dato){
			return busqueda(arbol ->izq,n);
		}
	else{
			return busqueda(arbol->der,n);
		}
	
}

void preOrden(Nodo *arbol){
 if(arbol == NULL){
 	return;
 }	
 else{
 	cout<<arbol->dato<<" - ";
 	preOrden(arbol->izq);
 	preOrden(arbol ->der);
 }


}

void inOrden(Nodo *arbol){
 if(arbol == NULL){
 	return;
  }	
 else{
 	inOrden(arbol->izq);
 	cout<<arbol->dato<<" - ";
 	inOrden(arbol ->der);
  }	
}


void postOrden(Nodo *arbol){
 if(arbol == NULL){
 	return;
  }	
 else{
 	postOrden(arbol->izq);
 	postOrden(arbol ->der);
 	cout<<arbol->dato<<" - ";
  }	
}

void eliminar(Nodo *arbol, int n){
	if(arbol == NULL){
		return;
	}
	
	else if (n < arbol->dato){
      eliminar(arbol->izq,n);
	  		
	}
	else if(n > arbol->dato){
	  eliminar(arbol->der,n);
	}
	else{
		eliminarNodo(arbol);
	}
}
Nodo *minimo(Nodo * arbol){
	if(arbol == NULL){
		return NULL;
	}
	if(arbol->izq){
		return minimo(arbol->izq);
	}
	else{
		return arbol;
	}
}

void reemplazar(Nodo *Arbol,Nodo *nuevoNodo){
	if(arbol->padre){
		//arbol padre hay que asignarle su nuevo hijo
		if(arbol->dato == arbol->padre->izq->dato){
			arbol->padre->izq= nuevoNodo;
		}
		else if(arbol->dato == arbol->padre->der->dato){
			arbol->padre->der = nuevoNodo;
		}
	}
	if(nuevoNodo){
		//procedemos a asigarle su nuevo padre
		nuevoNodo->padre= arbol->padre;
	}
	
}

void destruirNodo(Nodo *nodo){
	nodo->izq = NULL;
	nodo->der = NULL;
	delete nodo;
}
void eliminarNodo(Nodo *nodoEliminar){
	if(nodoEliminar->izq && nodoEliminar->der){
		Nodo *menor = minimo(nodoEliminar->der);
		nodoEliminar->dato = menor->dato;
		eliminarNodo(menor);
	}
	else if(nodoEliminar -> izq){
		reemplazar(nodoEliminar,nodoEliminar->izq);
		destruirNodo(nodoEliminar);
	}
	else if(nodoEliminar->der){
		reemplazar(nodoEliminar,nodoEliminar->der);
		destruirNodo(nodoEliminar);
	}
	else{
		reemplazar(nodoEliminar,NULL);
		destruirNodo(nodoEliminar);
	}
}
