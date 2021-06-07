#include <stdio.h>
#include <stdlib.h>

typedef struct pilha
{
    int *dados;
    int ultimo;
    int tamanho;
    int _tamanhoMaximo;
} pilha;

pilha construir_Pilha(int tamanhoMaximo)
{
    pilha saida;

    saida.dados = (int *)malloc(tamanhoMaximo * sizeof(int));
    saida.ultimo = -1; // Não existe último quando este é inferior a 0
    saida.tamanho = 0;
    saida._tamanhoMaximo = tamanhoMaximo;

    for (int i = 0; i < saida.tamanho; i++)
    {
        saida.dados[i] = 0;
    }

    return saida;
}

int pop(pilha *p)
{
    if (p->tamanho > 0)
    {
        p->dados[p->ultimo] = 0;
        p->tamanho--;
        p->ultimo--;

        return 1;
    }
    else
    {
        return 0;
    }
}

int push(pilha *p, int entradaDeDados)
{
    if (p->tamanho + 1 <= p->_tamanhoMaximo)
    {
        p->tamanho++;
        p->ultimo++;
        p->dados[p->ultimo] = entradaDeDados;

        return 1;
    }
    else
    {
        return 0;
    }
}

void display(pilha *p)
{
    for (int i = 0; i < p->tamanho; i++)
    {
        printf("    %d: %d\n", i, p->dados[i]);
    }
}

void executarExemplo01()
{
    printf("Exemplo 01 (Conforme Exercício):\n\n");

    pilha p = construir_Pilha(10);

    pop(&p);

    push(&p, 5);
    push(&p, 6);
    push(&p, 7);

    display(&p);
}

void executarExemplo02()
{
    printf("Exemplo 02:\n\n");

    pilha p = construir_Pilha(10);

    push(&p, 5);
    push(&p, 6);
    push(&p, 7);

    printf("    -Chamadas de pop(): 0\n");
    display(&p);

    printf("    -Chamadas de pop(): 1\n");
    pop(&p);
    display(&p);

    printf("    -Chamadas de pop(): 2\n");
    pop(&p);
    display(&p);

    printf("    -Chamadas de pop(): 3\n");
    pop(&p);
    display(&p);

    printf("    -Chamadas de pop(): 4\n");
    pop(&p);
    display(&p);

    printf("\n    -Valores:\n");
    printf("    Tamanho: %d;    Ultimo: %d\n", p.tamanho, p.ultimo);

    printf("\n    -Construção de uma pilha completa:\n");
    push(&p, 1);
    push(&p, 2);
    push(&p, 3);
    push(&p, 4);
    push(&p, 5);
    push(&p, 6);
    push(&p, 7);
    push(&p, 8);
    push(&p, 9);
    push(&p, 10);

    display(&p);

    printf("\n");
}

int main(int argc, char const *argv[])
{
    executarExemplo01();
    printf("\nTecle enter para continuar...");
    while (getchar() != '\n')
        ;
    executarExemplo02();

    return 0;
}
