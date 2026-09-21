# Relatório sobre a análise do uso de IA para a solução de problemas

# Implementação Avaliação 01 - Parte 02

# Questão 01 - Feita pela Claude.ia

  A IA utilizou variáveis do tipo int, ao invés de unsigned char, gastando 3 bytes a mais de memória; Dessa forma, o programa também aceita entradas negativas e não informa que a entrada ideal para M seria no intervalo [0,7].

Para limpar o LSB das componentes RGB, ela utiliza a variável da componente e faz uma operação & ~1 (não 1); Assim, ela gera o mesmo resultado de quando, no meu código, eu faço (variavel_cor & 254). Em que assim eu já apresento o LSB em 0.

Como o meu, o código continua rodando caso o usuário faça entradas de M > 7. No entanto, no meu código ainda exibo uma mensagem de instrução. Por essa falta de delimitação de limite no meu código, ocorre um overflow silencioso que gera um resultado diferente do esperado, quando o usuário entra com um valor maior que 255.

# Conclusão: Dessa forma, se eu fosse refazer essa questão:
1 - Permaneceria com o tipo unsigend char. 
2 - Adicionar uma estrutura condicional (if/else ou do-while) para validar se 0 <= RGB <= 255 e 0 <= M <= 7 antes de processar os bits.
3 - Manteria o uso das variáveis de armazenamento do bits, para manter o código limpo e legível. 

# Questão 02 - Feita pela Claude.ia 



