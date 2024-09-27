#ifndef LISTA_H
#define LISTA_H

template <class T>
class Lista{
	private:
		struct Nodo{
			T dato;
			struct Nodo *sig;
		};
		
		int dim;
		struct Nodo *inicio;
		struct Nodo *crearNodo(T);

	public:
		Lista();

		~Lista();

		void InsertarPrimero(T);
		void InsertarUltimo(T);
		void InsertarDatoPosicion(T, int);


		void ImprimirLista();
		bool EstaVacia();
		int LongitudLista();

		void VaciarLista();
		void SuprimirDato(T);
		void SuprimirDatosTodos(T);
		T SuprimirDatoPosicion(int pos);
		
		T DevolverDatoPosicion(int pos);
		bool ExisteDato(T);
		
		
};

#endif