#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Data {
    int dia;
    int mes;
    int ano;
};

struct Funcionario {
    char nome[50];
    char cargo[50];
    float salario;
    struct Data dataAdmissao;
};

// Função para dar um aumento de salário a um funcionário
void darAumento(struct Funcionario *funcionario, float percentualAumento) {
    float aumento = (percentualAumento / 100) * funcionario->salario;
    funcionario->salario += aumento;
}

// Função para calcular quanto tempo um funcionário está na empresa em anos
int calcularTempoNaEmpresa(struct Funcionario *funcionario) {
    time_t now;
    struct tm dataAdmissao;
    time(&now);
    dataAdmissao = *localtime(&now);

    int anos = dataAdmissao.tm_year + 1900 - funcionario->dataAdmissao.ano;

    if (funcionario->dataAdmissao.mes > dataAdmissao.tm_mon + 1 ||
        (funcionario->dataAdmissao.mes == dataAdmissao.tm_mon + 1 &&
         funcionario->dataAdmissao.dia > dataAdmissao.tm_mday)) {
        anos--;
    }

    return anos;
}

int main() {
    struct Funcionario funcionario;
    struct Data dataAtual;

    printf("Digite o nome do funcionário: ");
    scanf("%s", funcionario.nome);

    printf("Digite o cargo do funcionário: ");
    scanf("%s", funcionario.cargo);

    printf("Digite o salário do funcionário: ");
    scanf("%f", &funcionario.salario);

    printf("Digite a data de admissão (DD MM AAAA): ");
    scanf("%d %d %d", &funcionario.dataAdmissao.dia, &funcionario.dataAdmissao.mes, &funcionario.dataAdmissao.ano);

    printf("\nDados do funcionário:\n");
    printf("Nome: %s\n", funcionario.nome);
    printf("Cargo: %s\n", funcionario.cargo);
    printf("Salário: R$%.2f\n", funcionario.salario);
    printf("Data de Admissão: %02d/%02d/%04d\n", funcionario.dataAdmissao.dia, funcionario.dataAdmissao.mes, funcionario.dataAdmissao.ano);

    float percentualAumento;
    printf("\nDigite o percentual de aumento de salário: ");
    scanf("%f", &percentualAumento);
    darAumento(&funcionario, percentualAumento);

    printf("\nSalário atualizado: R$%.2f\n", funcionario.salario);

    printf("\nTempo na empresa: %d anos\n", calcularTempoNaEmpresa(&funcionario));

    return 0;
}
