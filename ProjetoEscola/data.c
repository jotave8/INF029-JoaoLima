#include "data.h"
#include "defines.h"


int anoBissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}


int validarData(int dia, int mes, int ano) {
    if (ano < 1900 || ano > 2024) {
        return DATA_INVALIDA;
    }

    if (mes < 1 || mes > 12) {
        return DATA_INVALIDA;
    }

    int diasPorMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (mes == 2 && anoBissexto(ano)) {
        diasPorMes[1] = 29;
    }

    if (dia < 1 || dia > diasPorMes[mes - 1]) {
        return DATA_INVALIDA;
    }

    return DATA_VALIDA;
}