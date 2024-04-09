# Create perfis
CREATE(Ronaldo:Perfil{nome:"Ronaldo", email:"r.mello@ufsc.br,", idade:55, cidade:"Porto Alegre", telefone:"999999999"});
CREATE(Luma:Perfil{nome:"Luma", email:"luma@gmail.com", idade:30, cidade:"Florianopolis", telefone:"888888888"});
CREATE(Karla:Perfil{nome:"Karla", email:"karla@gmail.com", idade:27, cidade:"Florianopolis", telefone:"777777777"});
CREATE(Lucas:Perfil{nome:"Lucas", email:"lucas@gmail.com", idade:35, cidade:"Lages", telefone:"666666666"});

# Create relações amizade
## Ronaldo e Luma
match (p1:Perfil),(p2:Perfil) WHERE p1.nome = "Ronaldo" AND p2.nome = "Luma" CREATE (p1)-[:amizade{timestamp:"4/4/2023 15:00"}]->(p2);
match (p1:Perfil),(p2:Perfil) WHERE p1.nome = "Ronaldo" AND p2.nome = "Luma" CREATE (p2)-[:amizade{timestamp:"4/4/2023 15:00"}]->(p1);
## Ronaldo e Karla
match (p1:Perfil),(p2:Perfil) WHERE p1.nome = "Ronaldo" AND p2.nome = "Karla" CREATE (p1)-[:amizade{timestamp:"3/4/2023 10:00"}]->(p2);
match (p1:Perfil),(p2:Perfil) WHERE p1.nome = "Ronaldo" AND p2.nome = "Karla" CREATE (p2)-[:amizade{timestamp:"3/4/2023 10:00"}]->(p1);
## Luma e Lucas
match (p1:Perfil),(p2:Perfil) WHERE p1.nome = "Lucas" AND p2.nome = "Luma" CREATE (p1)-[:amizade{timestamp:"2/4/2023 09:00"}]->(p2);
match (p1:Perfil),(p2:Perfil) WHERE p1.nome = "Lucas" AND p2.nome = "Luma" CREATE (p2)-[:amizade{timestamp:"2/4/2023 09:00"}]->(p1);
## Luma e Karla
match (p1:Perfil),(p2:Perfil) WHERE p1.nome = "Luma" AND p2.nome = "Karla" CREATE (p1)-[:amizade{timestamp:"1/4/2023 14:00"}]->(p2);
match (p1:Perfil),(p2:Perfil) WHERE p1.nome = "Luma" AND p2.nome = "Karla" CREATE (p2)-[:amizade{timestamp:"1/4/2023 14:00"}]->(p1);

## Create Posts
CREATE(p1:Post{id:100, texto:"Estressada!", timestamp:"1/4/2023 10:00"});
match (perfil:Perfil),(p:Post) WHERE perfil.nome = "Karla" AND p.id = 100 CREATE (perfil)-[:posse]->(p);
match (perfil:Perfil),(p:Post) WHERE perfil.nome = "Karla" AND p.id = 100 CREATE (p)-[:posse]->(perfil);

CREATE(p2:Post{id:101, texto:"Que dia lindo!", timestamp:"3/4/2023 14:30"}); 
match (perfil:Perfil),(p:Post) WHERE perfil.nome = "Karla" AND p.id = 101 CREATE (perfil)-[:posse]->(p);
match (perfil:Perfil),(p:Post) WHERE perfil.nome = "Karla" AND p.id = 101 CREATE (p)-[:posse]->(perfil);

CREATE(p3:Post{id:102, texto:"Novo mês iniciado!", timestamp:"1/4/2023 11:00"}); 
match (perfil:Perfil),(p:Post) WHERE perfil.nome = "Ronaldo" AND p.id = 102 CREATE (perfil)-[:posse]->(p);
match (perfil:Perfil),(p:Post) WHERE perfil.nome = "Ronaldo" AND p.id = 102 CREATE (p)-[:posse]->(perfil);

CREATE(p4:Post{id:103, texto:"Estou gripado!", timestamp:"4/4/2023 14:30"}); 
match (perfil:Perfil),(p:Post) WHERE perfil.nome = "Ronaldo" AND p.id = 103 CREATE (perfil)-[:posse]->(p);
match (perfil:Perfil),(p:Post) WHERE perfil.nome = "Ronaldo" AND p.id = 103 CREATE (p)-[:posse]->(perfil);

## Create Likes
match (perfil:Perfil),(p:Post) WHERE perfil.nome = "Lucas" AND p.id = 101 CREATE (perfil)-[:curtiu{timestamp:"4/4/2023 11:30"}]->(p);
match (perfil:Perfil),(p:Post) WHERE perfil.nome = "Lucas" AND p.id = 102 CREATE (perfil)-[:curtiu{timestamp:"4/4/2023 15:00"}]->(p);


## Create Comentários
match (perfil:Perfil),(p:Post) WHERE perfil.nome = "Karla" AND p.id = 103 CREATE (perfil)-[:comentario{texto:"melhoras!",timestamp:"4/4/2023 16:00"}]->(p);

## Exercícios 

### 1 Buscar todos os posts do BD
MATCH (p:Post) RETURN p;

### 2 Buscar os perfis de Florianopolis
MATCH (perfil:Perfil {cidade: "Florianopolis"}) RETURN perfil;

### 3 Buscar os nomes dos amigos de Karla
MATCH (Perfil{nome: "Karla"})-[:amizade]->(amigo) RETURN amigo.nome; -- Consulta direcional para evitar resultados duplicados

### 4 Buscar a idade da pessoa mais velha da rede social
MATCH (perfil:Perfil) RETURN max(perfil.idade); 

### 5 Buscar o número de amigos de Ronaldo
MATCH (Perfil {nome: "Ronaldo"})-[:amizade]->(amigo) RETURN COUNT(amigo) AS NumeroDeAmigos; - Consulta direcional para evitar resultados duplicados

### 6 Buscar os nomes das pessoas que comentaram ou deram like nos posts de Ronaldo
MATCH (Perfil {nome: "Ronaldo"})-[:posse]->(Post)<-[:comentario|:curtiu]-(pessoa:Perfil) RETURN DISTINCT pessoa.nome;

### 7 Remover os comentários feitos pela Karla
MATCH (Perfil {nome: "Karla"})-[r:comentario]->(Post) DELETE r;

### 8 Alterar a idade de Lucas para 37 e sua cidade para Florianopolis
MATCH (perfil:Perfil {nome: "Lucas"}) SET perfil.idade = 37, perfil.cidade = "Florianopolis"  RETURN perfil;
