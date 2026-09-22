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

Primeiro, iniciaremos com a correção do meu código: No meu laço for, eu inicializo a variável i = 2, depois de pegar os valores de x1 e x2. Dessa forma, logicamente a variável i deveria receber o valor 3. Da forma que estava, o usuário poderia entrar com 11 variáveis e "y" iniciaria com 1, mas o enunciado pede que ela inicie com 2. Outro ajuste necessário seria a mudança do tipo de variável de "suavizado" para float, no campo das variáveis, pois mantendo-o em unsigned char, o código não conseguiria retornar um sinal suavizado de maneira correta, apenas com valores arredondados; na linha de como calcular suavizado, eu alteraria para "suavizado = (float) (anterior + atual + proximo)/3.0;"

Assim, fazendo agora a análise no código gerado por IA, ela utilizou variáveis do tipo int e diouble, gastando uma quantidade desnecessária de memória. Ela também permitiu que o usuário entrasse com a quantidade de amostras que seriam suavizadas, e depois criou uma condicional que verificava se o numero de amostras permitiria a criação de janelas, o que permitiu o resultado correto dos cálculos. Por fim, o calculo das janelas e a impressão do resultado para o usuário se assemelham com o meu.

# Conclusão:
Apesar do gasto desnecessário de memoria quanto a decisão dos tipos da variáveis, o código da Claude passa no teste de mesa, entrega o que é solicitado no enunciado e o meu, não, por conta de alguns errinhos de falta de atenção.

Ainda assim, eu:
1 - Faria as alterações do início.
2 - Manteria o #define da variável N e, consequentemente, não faria a verificação de if/else.




