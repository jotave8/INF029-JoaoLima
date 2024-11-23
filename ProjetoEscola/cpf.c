#include "cpf.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int validarCPF(const char *cpf) {
  if (strlen(cpf) != 11)
    return 0;
  for (int i = 0; i < 11; i++) {
    if (!isdigit(cpf[i]))
      return 0;
  }
  int iguais = 1;
  for (int i = 1; i < 11 && iguais; i++) {
    if (cpf[i] != cpf[0])
      iguais = 0;
  }
  if (iguais)
    return 0;
  int soma = 0;
  for (int i = 0; i < 9; i++) {
    soma += (cpf[i] - '0') * (10 - i);
  }
  int digito1 = (soma * 10) % 11;
  if (digito1 == 10)
    digito1 = 0;

  soma = 0;
  for (int i = 0; i < 10; i++) {
    soma += (cpf[i] - '0') * (11 - i);
  }
  int digito2 = (soma * 10) % 11;
  if (digito2 == 10)
    digito2 = 0;
  return (digito1 == (cpf[9] - '0') && digito2 == (cpf[10] - '0'));
}
