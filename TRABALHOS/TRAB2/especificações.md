ALEST I - T2 - 2025
Verifica¸c˜ao de Autoriza¸c˜oes em uma Hierarquia
1 Descri¸c˜ao do problema
Vocˆe est´a ajudando no desenvolvimento de um software de auditoria para um
departamento p´ublico de um pa´ıs extremamente burocr´atico. O objetivo do
sistema ´e verificar se as ordens internas do departamento possuem todas as
autoriza¸c˜oes necess´arias, conforme as regras hier´arquicas da institui¸c˜ao.
Cada ordem ´e criada por um funcion´ario do departamento, e para ser con-
siderada v´alida, deve possuir autoriza¸c˜oes de acordo com um dos seguintes
crit´erios:
• A ordem deve ser autorizada por pelo menos trˆes pessoas que estejam
exatamente um n´ıvel acima na hierarquia do funcion´ario que a criou;
• Alternativamente pode ser autorizada por pelo menos uma pessoa que
esteja dois ou mais n´ıveis acima do funcion´ario solicitante.
A hierarquia do departamento ´e fixa e pode ser representada por uma ´arvore,
onde:
• Cada funcion´ario possui exatamente um superior (exceto o diretor geral,
que ´e a raiz da ´arvore);
• Um funcion´ario pode ter nenhum, um ou v´arios subordinados.
O que deve ser feito
Seu programa deve ser capaz de:
1. Ler um arquivo contendo as rela¸c˜oes hier´arquicas entre os funcion´arios e
construir uma ´arvore geral de hierarquia a partir desses dados. (Dica:
utilize a estrutura de ´arvore apresentada em aula, adaptando-a para tra-
balhar com nomes do tipo string.)
2. Implementar uma fun¸c˜ao que verifique se uma determinada ordem est´a
corretamente autorizada, de acordo com as regras descritas anteriormente.
1
Formato do arquivo de entrada
O arquivo de entrada cont´em a hierarquia no seguinte formato:
• A primeira linha cont´em um n´umero inteiro N , representando o n´umero
de rela¸c˜oes ”chefe-subordinado”existentes.
• As pr´oximas N linhas contˆem, cada uma, dois nomes entre aspas e sepa-
rados por um espa¸co: o primeiro ´e o nome do chefe, e o segundo ´e o nome
do subordinado. (Pode ter sobrenomes,)
Exemplo de arquivo de entrada:
6
"Jo~ao" "Maria"
"Jo~ao" "Carlos"
"Maria" "Ana"
"Maria" "Bruno"
"Carlos" "Paula"
"Carlos" "Rafael"
Fun¸c˜ao de verifica¸c˜ao
A fun¸c˜ao que verifica a validade de uma ordem deve receber, no m´ınimo, os
seguintes parˆametros (vocˆe pode incluir mais, se necess´ario):
• Nome do solicitante: uma string contendo o nome da pessoa que fez a
ordem. (Obs.: o nome pode n˜ao estar presente na ´arvore.)
• Lista de autorizantes: uma lista de strings com os nomes de todas as
pessoas que autorizaram a ordem.
A fun¸c˜ao deve ent˜ao retornar se a ordem ´e v´alida ou inv´alida, seguindo as
regras de autoriza¸c˜ao.
Exemplo de verifica¸c˜ao
Considere a hierarquia apresentada no exemplo anterior.
• Solicitante: "Ana"
• Autorizantes: ["Maria", "Carlos", "Jo~ao"]
Nesse caso:
• "Maria" e "Carlos" est˜ao um n´ıvel acima de "Ana" (sua chefe direta);
• "Jo~ao" est´a dois ou mais n´ıveis acima na hierarquia.
Portanto, a ordem seria considerada v´alida, pois h´a pelo menos um autori-
zante dois n´ıveis acima.
2
2 Relat´orio
No relat´orio, descreva:
• A estrutura de dados utilizada para representar a ´arvore;
• O algoritmo de leitura e constru¸c˜ao da hierarquia;
• A implementa¸c˜ao da fun¸c˜ao de verifica¸c˜ao de autoriza¸c˜oes e analise da
complexidade dela;
• Casos de teste utilizados e suas respectivas sa´ıdas.
• Conclus˜ao.
3 Sugest˜ao de estrutura do relat´orio
• Introdu¸c˜ao – 1 par´agrafo Apresente, de forma breve, o contexto do pro-
blema, seus objetivos e a importˆancia da verifica¸c˜ao hier´arquica das auto-
riza¸c˜oes.
• Estrutura de dados usada – 1 par´agrafo Descreva a estrutura de dados
utilizada (por exemplo, uma ´arvore gen´erica) e explique como ela repre-
senta a hierarquia entre os funcion´arios.
• C´odigo do algoritmo de leitura Inclua o trecho de c´odigo respons´avel
pela leitura do arquivo de entrada e pela constru¸c˜ao da ´arvore hier´arquica.
• Explica¸c˜ao da leitura – 1 ou 2 par´agrafos Explique como o algoritmo
realiza a leitura do arquivo, insere cada rela¸c˜ao na ´arvore e identifica o n´o
raiz (diretor-geral).
• C´odigo da fun¸c˜ao de verifica¸c˜ao Apresente o c´odigo respons´avel por
verificar se uma ordem est´a corretamente autorizada, conforme as regras
estabelecidas no enunciado.
• Explica¸c˜ao – 1 ou 2 par´agrafos Descreva a l´ogica utilizada para identificar
os n´ıveis hier´arquicos dos autorizantes em rela¸c˜ao ao solicitante e como o
programa determina se a ordem ´e v´alida ou inv´alida.
• Exemplo de entradas e sa´ıdas para teste Mostre exemplos de arqui-
vos de entrada e as respectivas sa´ıdas esperadas do programa, incluindo
casos v´alidos e inv´alidos.
• An´alise da complexidade – 1 par´agrafo Apresente a an´alise de com-
plexidade temporal da verifica¸c˜ao, no melhor e pior caso e em nota¸c˜ao
assint´otica (Big O).
• Conclus˜ao Finalize com um par´agrafo resumindo as principais dificulda-
des enfrentadas, as solu¸c˜oes adotadas e os aprendizados obtidos durante
a implementa¸c˜ao.
3