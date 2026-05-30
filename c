#include <stdio.h>

// função para calcular a média
float calcularMedia(float n1, float n2, float n3) {
    return (n1 + n2 + n3) / 3;
}

int main() {

    char nome[50];
    int idade;

    float nota1, nota2, nota3, media;

    int numeros[5];
    int soma = 0;
    int maior;

    // 1. ler nome
    printf("Digite seu nome: ");
    scanf("%s", nome);

    // 2. ler idade com validação
    do {
        printf("Digite sua idade: ");
        scanf("%d", &idade);

        if (idade < 0) {
            printf("Idade invalida. Digite novamente.\n");
        }

    } while (idade < 0);

    // 3. ler 3 notas
    printf("Digite a primeira nota: ");
    scanf("%f", &nota1);

    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);

    printf("Digite a terceira nota: ");
    scanf("%f", &nota3);

    // 4. calcular média usando função
    media = calcularMedia(nota1, nota2, nota3);

    printf("Media: %.2f\n", media);

    // 5. mostrar situação
    if (media >= 7) {
        printf("Situacao: Aprovado\n");
    } else if (media >= 5) {
        printf("Situacao: Recuperacao\n");
    } else {
        printf("Situacao: Reprovado\n");
    }

    // 6. pedir 5 números e guardar em vetor
    for (int i = 0; i < 5; i++) {
        printf("Digite um numero inteiro: ");
        scanf("%d", &numeros[i]);

        soma += numeros[i];

        if (i == 0 || numeros[i] > maior) {
            maior = numeros[i];
        }
    }

    printf("Soma dos numeros: %d\n", soma);
    printf("Maior numero: %d\n", maior);

    return 0;
}