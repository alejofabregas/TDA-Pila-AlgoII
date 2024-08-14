#include "pila.h"
#include "testing.h"
#include <stdlib.h>

#define CANT_ELEM_PRUEBA 10000

static void prueba_pila_vacia(void) {
    pila_t *pila = pila_crear();
    print_test("La pila esta vacia", pila_esta_vacia(pila));
    pila_destruir(pila);
}

void prueba_crear_destruir_pila() {
	pila_t *pila = pila_crear();
	print_test("Se creo la pila", pila != NULL);
	pila_destruir(pila);
	print_test("Se destruyo la pila", true);
}

void pruebas_apilar_desapilar() {
	pila_t *pila = pila_crear();
	int tam_elem = 13;
	int elem_prueba[13] = {0,1,2,3,4,5,6,7,8,9,10,11,12};
	bool apilar_ok = true;
	bool desapilar_ok = true;
	for (int i = 0; i < tam_elem; i++) {
		if (!pila_apilar(pila, &elem_prueba[i])) {apilar_ok = false;}
	}
	print_test("Apilar varios elementos", apilar_ok);
	print_test("Tope pila es el ultimo del vector", pila_ver_tope(pila) == &elem_prueba[tam_elem - 1]);
	for (int i = tam_elem - 1; i >= 0; i--) {
		if (pila_desapilar(pila) != &elem_prueba[i]) {desapilar_ok = false;}
	}
	print_test("Desapilar varios elementos", desapilar_ok);
	pila_destruir(pila);
}

void prueba_de_volumen() {
	pila_t *pila = pila_crear();
	int elem_prueba[CANT_ELEM_PRUEBA];
	bool apilar_ok = true;
	bool desapilar_ok = true;
	for (int i = 0; i < CANT_ELEM_PRUEBA; i++) {
		elem_prueba[i] = i;
		if (!pila_apilar(pila, &elem_prueba[i])) {apilar_ok = false;}
	}
	print_test("Apilar volumen de elementos", apilar_ok);
	for (int i = CANT_ELEM_PRUEBA - 1; i >= 0; i--) {
		if (pila_desapilar(pila) != &elem_prueba[i]) {desapilar_ok = false;}
	}
	print_test("Desapilar volumen de elementos", desapilar_ok);
	print_test("Pila vacia", pila_esta_vacia(pila));
	pila_destruir(pila);
}

void prueba_apilamiento_null() {
	pila_t *pila = pila_crear();
	void *puntero_null = NULL;
	print_test("Apilamiento del elemento NULL", pila_apilar(pila, puntero_null));
	print_test("Ver tope pila con NULL", pila_ver_tope(pila) == puntero_null);
	print_test("Apilamiento del elemento NULL 2", pila_apilar(pila, puntero_null));
	print_test("Ver tope pila con NULL 2", pila_ver_tope(pila) == puntero_null);
	pila_destruir(pila);
}

void prueba_desapilar_hasta_vacia() {
	pila_t *pila = pila_crear();
	int elem_prueba = 1;
	pila_apilar(pila, &elem_prueba);
	pila_desapilar(pila);
	print_test("Chequear si la pila desapilada esta vacia", pila_esta_vacia(pila));
	print_test("Ver tope de pila desapilada hasta vacia", pila_ver_tope(pila) == NULL);
	print_test("Desapilar la pila desapilada hasta vacia", pila_desapilar(pila) == NULL);
	pila_destruir(pila);
	
}

void pruebas_desapilar_ver_tope_recien_creada() {
	pila_t *pila = pila_crear();
	print_test("Desapilar pila recien creada", pila_desapilar(pila) == NULL);
	print_test("Ver tope de pila recien creada", pila_ver_tope(pila) == NULL);
	pila_destruir(pila);
}

void prueba_esta_vacia_recien_creada() {
	pila_t *pila = pila_crear();
	print_test("Una pila recien creada esta vacia", pila_esta_vacia(pila));
	pila_destruir(pila);
}

void pruebas_desapilar_ver_tope() {
	pila_t *pila = pila_crear();
	int tam_str = 13;
	char string_prueba[13] = "abcdefghijklm";
	for (int i = 0; i < tam_str; i++) {
		pila_apilar(pila, &string_prueba[i]);
	}
	for (int i = 0; i < tam_str; i++) {
		pila_desapilar(pila);
	}
	print_test("Desapilar pila apilada y desapilada hasta estar vacia", pila_desapilar(pila) == NULL);
	print_test("Ver tope de una pila apilada y desapilada hasta estar vacia", pila_ver_tope(pila) == NULL);
	pila_destruir(pila);
}


void pruebas_pila_estudiante() {
    prueba_pila_vacia();
    prueba_crear_destruir_pila();
    pruebas_apilar_desapilar();
    prueba_de_volumen();
    prueba_apilamiento_null();
    prueba_desapilar_hasta_vacia();
    pruebas_desapilar_ver_tope_recien_creada();
    prueba_esta_vacia_recien_creada();
    pruebas_desapilar_ver_tope();
}


/*
 * Función main() que llama a la función de pruebas.
 */

#ifndef CORRECTOR  // Para que no dé conflicto con el main() del corrector.

int main(void) {
    pruebas_pila_estudiante();
    return failure_count() > 0;  // Indica si falló alguna prueba.
}

#endif
