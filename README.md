# Regiao-critica-SO
<h1>Repositório para atividade pratica da disciplina de sistemas operacionais </h1>

<p>O programa simulado excuta a função de uma relação de produtor e consumidor, a geladeira tem capacidade para
  até 10 litros de leite, a cada intervalo de tempo o consumidor bebe 1  litro de leite e os observadores entao
  reabastecem a geladeira caso esteja abaixo da capacidade maxima.
</p>

<p>O problema consiste que em dado momento os observadores vão comprar leite demais e o a capacidade maxima é
  violada, isso se dá pela falta de sincronia entre as threads dos observadores
</p>
<p>O programa threadsSO.c implementa o problema sem a sincronização das threads e como esperado em dado momento
  ocorre a violação da capacidade maxima
<p>
  
  <p>O Programa threadsMonitoradas implementa um tentiva de sincronizar as threadas através do controle de acesso a região
    critica, no nosso caso a varievel global geladeira, o controle é feito usando as variavéis <b>ocupado</b> e <b>turno</b>.</p>
 <p>ocupado indica que uma thread já está acessando a região critica assim nenhuma outra pode acessar a região critica, turno indica
    qual é a thread com a vez para acesso da região critica é usada para evitar que outras threads liberem o acesso a região sem estarem em sua vez.</p>
<p>Com esse controle implementado o número de violações da capcidade diminuiram mas não foram corrigidos assim é nescessario refinar a técnica </p>
