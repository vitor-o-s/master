# Gerência de Dados para Big Data

Disciplina ofetada em 2024.1 de forma remota pela PPGCC (UFSC). Curso ministrado pelo professor Ronaldo S. Mello

Nota Final = (Prova * 0,3) + (Artigo * 0,3) + (Seminário * 0,3) + (Atividades de aula * 0,1)

Modelo do LaTex para o artigo: [SBC Conferences Template](https://pt.overleaf.com/latex/templates/sbc-conferences-template/blbxwjwzdngr)

## Cronograma

* [X] 12/03 Plano de Ensino da disciplina; modelagem de dados
* [X] 19/03 Introdução à Big Data
* [X] 26/03 BDs nas nuvens; BDs NoSQL
* [ ] 02/04 BDs NoSQL
* [ ] 09/04 BDs NoSQL
* [ ] 16/04 BDs NoSQL
* [ ] 23/04 BDs NewSQL e BDs em memória
* [ ] 30/04 BDs NewSQL e BDs em memória
* [ ] 07/05 Persistência poliglota de dados
* [ ] 14/05 Infraestrutura para processamento de Big Data
* [ ] 21/05 Infraestrutura para processamento de Big Data
* [ ] 28/05 Desafio na gerência de Big Data
* [ ] 04/06 Desafio na gerência de Big Data
* [ ] 11/06 Prova (individual, peso: 3)
* [ ] 18/06 Seminários (grupo, peso:3)
* [ ] 25/06 Seminários (grupo, peso:3)
* [ ] 02/07 Seminários (grupo, peso:3)
* [ ] 09/07 Entrega do artigo  (grupo, peso:3)

## Tipos de Especializações 

* (t,c): total, compartilhada
* (t,d): total, disjunta
* (p,c): parcial, compartilhada
* (p,d): parcial, disjunta

disjunta - é uma ou outra especialização
total - é obrigatório ser algum dos casos
## Atividade 1 (12/02)

O enunciado do exercício se encontra na página 16 do material [Aula 1 - Revisão Modelagem Conceitual.pdf](https://github.com/vitor-o-s/master/blob/main/data_management_big_data_ufsc/Aula%201%20-%20Revisa%CC%83o%20Modelagem%20Conceitual.pdf). Realizar a modelagem E-R de uma clínica de saúde.

Minha proposta de solução: ![Minha solução](https://github.com/vitor-o-s/master/blob/main/data_management_big_data_ufsc/Exercicio1ModelagemERClinicaSaude.png)

Proposta de solução do professor: ![Solução proposta pelo professor](https://github.com/vitor-o-s/master/blob/main/data_management_big_data_ufsc/SolucaoPropostaModelagemERClinicaSaude.png)

## Atividade 2 (19/02)

Levantar definições e desafios dos seguintes V's:

* Viscosidade: There is a time discrepancy between the actual event and what is being described.(Lag of Event). [The 17 V’s of Big Data written by Vishnuka Mahendran](https://medium.com/@vishnuka2019/the-17-vs-of-big-data-c1f2f969847f) - Quanto tempo aquela informação demora pra ser utilizada.
* Volatilidade: The volatility, sometimes referred to as another “V” of big data, is the rate of change and lifetime of the data. An example of highly volatile data includes social media, where sentiments and trending topics change quickly and often. [10 Vs in Big data written by Tejaswi Battula](https://www.linkedin.com/pulse/big-data-tejaswi-battula/) - A taxa de mudança dos dados.

## Atividade 3 (26/03)

* Ler o capítulo 13 do livro NoSQL Distilled
* Ler o texto: https://martinfowler.com/articles/nosql-intro-original.pdf
* Responder as seguintes perguntas:
  * 1) O que é persistência poliglota? - We use the term polyglot persistence to define this hybrid approach to persistence (pg 179 do livro). 
  * 2) Qual(is) a(s) vantagem(ns) de utilizar persistência poliglota? - Melhor performance em consultas e divisão das operações de escrita (pg 179 do livro). Encapsulamento dos dados em um serviço ao inves do uso direto da base de dados (pg do livro 181). Expansão das funcionalidades das bases (ex. uso de Redis como cache de um sistema como o BQ) (pg do livro 182).
  * 3) Qual(is) a(s) dificuldade(s) em utilizar persistência poliglota? - Múltiplas licenças, perfil de DBAs variado visto que cada ferramenta exige um aprofundamento em si, segurança que no mundo NoSQL pode ser algo ainda não muito bem resolvido e integração com muitas ferramentas que pode gerar uma dificuldade na orquestração (pg 184 do livro). 
