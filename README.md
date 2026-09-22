# Relatório — Análise do Uso de IA na Solução de Problemas

**Disciplina:** Laboratório de Programação — LP 2026.2
**Atividade:** Análise AP01
**Ferramenta de IA utilizada:** Claude.ai

---

## Sobre este relatório

Este documento apresenta a comparação entre as soluções desenvolvidas em sala de aula (14/09 e 18/09) e as soluções geradas pela IA para as quatro questões da avaliação. Para cada questão, são analisados os pontos fortes e fracos de cada abordagem, possíveis falhas e o aprendizado obtido com a comparação.

> Todos os códigos referenciados estão disponíveis neste repositório.

---

## Sumário

- [Questão 01](#questão-01)
- [Questão 02](#questão-02)
- [Questão 03](#questão-03)
- [Questão 04](#questão-04)
- [Considerações finais](#considerações-finais)

---

## Questão 01

**Resolvida também por:** Claude.ai

### Análise comparativa

| Aspecto | Minha solução | Solução da IA |
|---|---|---|
| Tipo de variável | `unsigned char` | `int` (gasta 3 bytes a mais de memória) |
| Validação de entrada | Não trata negativos nem restringe o intervalo de `M` | Aceita entradas negativas e não informa que `M` deve estar em `[0, 7]` |
| Limpeza do LSB | `variavel_cor & 254` | `variavel_cor & ~1` (resultado equivalente) |
| Validação de `M > 7` | Continua rodando, mas exibe mensagem de instrução | Continua rodando sem alerta |
| Overflow | Ocorre overflow silencioso quando o valor de entrada é maior que 255 (sem tratamento de limite) | Mesmo problema |

### O que eu aprendi / o que faria diferente

1. Manter o tipo `unsigned char`.
2. Adicionar uma estrutura condicional (`if/else` ou `do-while`) para validar `0 ≤ RGB ≤ 255` e `0 ≤ M ≤ 7` antes de processar os bits.
3. Manter o uso das variáveis de armazenamento dos bits, para preservar a legibilidade do código.

---

## Questão 02

**Resolvida também por:** Claude.ai

### Correções identificadas na minha solução

- No laço `for`, a variável `i` era inicializada com `i = 2`, mas deveria começar em `i = 3` — o enunciado pede que a suavização comece a partir do índice 2, então o índice de controle precisa iniciar em 3.
- No `#define`, o limite de entrada permitia até 10 variáveis, mas o esperado eram 11, o que gerava uma falha de limite.
- A variável `suavizado` estava como `unsigned char`; deveria ser `float`, pois com `unsigned char` o resultado ficava apenas arredondado, sem representar corretamente o sinal suavizado.
  - Correção proposta: `suavizado = (float)(anterior + atual + proximo) / 3.0f;`

### Análise da solução da IA

| Aspecto | Observação |
|---|---|
| Tipos de variável | Usou `int` e `double`, com gasto desnecessário de memória |
| Entrada de amostras | Permitiu que o usuário definisse a quantidade de amostras a suavizar |
| Validação | Criou uma condicional para verificar se o número de amostras permite formar janelas — o que garantiu o cálculo correto |
| Cálculo e saída | Semelhantes à minha implementação |

### Conclusão

Apesar do gasto desnecessário de memória na escolha dos tipos, o código da Claude passa no teste de mesa e atende ao que foi pedido no enunciado. O meu código, por conta de pequenos erros de atenção (inicialização do índice e limite do `#define`), não atendia completamente.

**O que eu faria diferente:**

1. Corrigir os erros de inicialização identificados acima.
2. Manter o `#define` da variável `N` e, consequentemente, não usar validação por `if/else`.

---

## Questão 03

**Resolvida também por:** Claude.ai

### Análise comparativa

| Aspecto | Minha solução | Solução da IA |
|---|---|---|
| Tipos de variável | `unsigned char` para a maioria das variáveis de processamento; `float` só na normalização de X — economiza memória e é adequado para processamento de imagens | `int` e `double` — gasto desnecessário de memória |
| Definição de Xmin/Xmax | `Xmin = 255` e `Xmax = 0` como valores iniciais, garantindo que sejam sobrescritos nas comparações seguintes; funciona bem com `unsigned char`, mas é inviável para tipos maiores | Iguala `Xmin` e `Xmax` ao primeiro pixel inserido — abordagem mais generalizada, funciona melhor para outros casos |
| Falha no teste de mesa | Quebra quando `Xmin == Xmax`, pois não há validação que impeça essa entrada | Mesmo problema: também quebra quando `Xmin == Xmax`, por falta da mesma validação |

### Correção proposta

```c
if (Xmin == Xmax) {
    printf("Não é possível normalizar o sinal, pois Xmin = a Xmax");
} else {
    printf("Insira o pixel a ser normalizado no intervalo [%hhu,%hhu]\n", Xmin, Xmax);
    scanf("%hhu", &X);

    Xnormalizado = (float)(X - Xmin) / (Xmax - Xmin);

    printf("O pixel %hhu normalizado é = %.2f\n", X, Xnormalizado);
}
```

### Conclusão

Ambas as soluções compartilham uma lógica semelhante e, por consequência, falham no mesmo cenário: `Xmin == Xmax`. A principal diferença de qualidade está no mecanismo de definição de `Xmin`/`Xmax` — a abordagem da IA (igualar ambos ao primeiro pixel inserido) é mais generalizada e funcional do que a minha (fixar os extremos do intervalo `unsigned char`).

**O que eu faria diferente:**

1. Manter o `#define N 5`, por questão de praticidade.
2. Manter as escolhas de tipos de variáveis, para economia de memória.
3. Adicionar a condicional para tratar o caso `Xmin == Xmax`, blindando o código.
4. Substituir minha comparação de min/max pela lógica da Claude, mais generalizada e funcional.

---

## Questão 04

**Resolvida também por:** Claude.ia

> A minha solução passa em todos os testes de mesa e é consideravelmente mais intuitiva e legível que a solução da IA.
> Nesse problema em específico, utilizamos o mesmo tipo de variável, int, e nossas diferenciações estão no desenrolar do código: A IA utiliza o laço while e a flag parar para sair do loop, com condicionais if-else que testam as entradas para sair (numero == -1), e a permissão de seguir ou não, com else-if vazios que são visualmente desorganizados.
> Enquanto no meu código, foi utilizado o do-while sem flag, minha condição de saída foi simples do { } while (numero != -1). Dentro do "do", utilizei apenas um if que, de modo que se o numero se encaixar nas condições, seria contabilizado pelo contador e passaria pela operação da soma.
> Assim, apesar do código da Claude estar mais parecido com o algoritmo da prova, o meu código é mais intuitivo e legível, de modo que eu manteria todo o meu algortimo e não faria alterações.

---

## Considerações finais

**O uso da Inteligência Artificial modificou sua compreensão sobre alguma das questões da prova? Se sim, explique brevemente.**

> A questão que mudou brevemente a minha compreensão da questão não é tanto da questão inteira, mas o modo de comparar maximos e minimos. A solução da questão 3 pela claude, apesar de falhar no teste de mesa como a minha, me levou a entender outra maneira de fazer comparações de modo mais inteligente e generalizado.
> Ademais, também nao posso deixar de notar que a IA, mais especificamnete a Claude, gasta mais memória na escolha dos tipos das variáveis porque ela busca criar soluções mais genralizadas. Sua lógica é mais geral, e como pudemos ver, também pode falhar. Dessa forma, cabe sempre ao aluno/dev analisar e testar os códigos de modo a garantir sua funcionalidade.

