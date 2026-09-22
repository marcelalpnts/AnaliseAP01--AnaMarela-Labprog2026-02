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

> Começando com o meu código: Utilizei unsigned char para a maioria das variáveis de processamento e utilizei float apenas para a normalização do X, o que economizou memória e é o tipo de dado ideal para processamento de imagens.
> Apesar disso, utilizei como validação de min e max, igualando o Xmin = 255, que é o valor máximo a ser registrado, e para o Xmax = 0, o menor valor possível. Assim, eu poderia garantir que os valores seguintes alterariam os iniciais quando houvesse a comparação; o que pode parecer bom quando trabalhamos com dados unsigned char, mas é inviável para tipos que utilizam mais bytes.
> No teste de mesa, meu código quebra apenas quando Xmin==Xmax. Como não criei nenhum critério que impossibilitasse esse tipo de entrada, o é permitido que o usuario quebre o programa.
> Dessa forma, se eu fosse refazer, criaria uma condicional if, de modo que:

> if (Xmin == Xmax) {printf("Não é possível normalizar o sinal, pois Xmin = a Xmax");}
    
    else {
        
        printf("Insira o pixel a ser normalizado no intervalo [%hhu,%hhu]\n", Xmin, Xmax);
    scanf("%hhu", &X);

    Xnormalizado = (float)(X - Xmin) / (Xmax-Xmin);

    printf("O pixel %hhu normalzado é = %.2f\n", X, Xnormalizado);
    }

> Agora partindo para a analise da IA, sua lógica está parecida com a minha, apesar do gasto desnecessário de memória utilizando os tipos int e double. Ela utiliza uma lógica bastante inteligente para delimitar o Xmax e Xmin, que é igualá-los ao primeiro pixel inserido, o que acaba sendo uma abordagem mais generalizada para outros casos e funciona melhor que o meu teste.
> Assim, com lógicas parecidas, temos erros semelhantes, no teste de mesa, o código da Claude também quebra quando Xmin == Xmáx, mostrando que também falta uma condicional para a validação dessas entradas.
> Sendo assim, depois dessa análise, eu continuaria mantendo meu #define N 5, por questões de praticidade, e as escolhas dos tipos de variáveis, para economia de memoria; ajustaria a falta da condicional para casos de Xmin == Xmax, para blindar mais meu código, e substituiria a minha comparação de min-max pela da Claude, que utilizou um mecanismo mais generalizado e funcional que o meu.

---

## Questão 04

**Resolvida também por:** Claude.ai

> 

---

## Considerações finais

**O uso da Inteligência Artificial modificou sua compreensão sobre alguma das questões da prova? Se sim, explique brevemente.**

> ⚠️ **Resposta a completar.**

