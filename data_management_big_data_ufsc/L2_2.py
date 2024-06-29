import heapq
# https://docs.python.org/3/library/heapq.html
# A heap do python é implementada como min-heap e o índice é baseado em 0

def pedagio_por_vertice(vertice):
    # Exemplo de função que retorna um custo de pedágio diferente para cada vértice
    # Suponha que o custo do pedágio é baseado em algum atributo do vértice
    custos_de_pedagio = {
        1: 5, 2: 6, 3: 7, 4: 4, 5: 3,
        6: 5, 7: 7, 8: 2, 9: 8, 10: 6
    }
    return custos_de_pedagio.get(vertice, 0)  # Retorna 0 se o vértice não estiver definido

def dijkstra(G, origem, autonomia, preco, funcao_pedagio):
    
    D = {v: float('infinity') for v in G}
    A = {v: None for v in G}

    D[origem] = 0
    min_heap =  [(0, origem)]
    
    while min_heap:
        d_atual, v_atual = heapq.heappop(min_heap)
        
        for v_adjacente, distancia_u_ate_v in G[v_atual]:
            pedagio = funcao_pedagio(v_adjacente)
            nova_d = d_atual +  (((distancia_u_ate_v/autonomia)*preco) + pedagio)
            if nova_d < D[v_adjacente]:
                D[v_adjacente] = nova_d
                A[v_adjacente] = v_atual
                heapq.heappush(min_heap, (nova_d, v_adjacente))

    return  D, A # Retorna o vetor de distâncias e o de pais

def caminho_minimo(origem, destino, A):
    # Esta função reconstrói o caminho de 'destino' até 'origem' usando o dicionário de pais 'A'.
    caminho = []
    passo_atual = destino
    while passo_atual != origem:
        if passo_atual is None:
            return None  # Se não há caminho possível
        caminho.append(passo_atual)
        passo_atual = A[passo_atual]
    caminho.append(origem)
    caminho.reverse()  # Inverte a lista para mostrar o caminho da origem ao destino
    return caminho    
    

if __name__ == '__main__':
    # O grafo G é um dicionário cujo as chaves são os vértices do conjunto V,
    # Por sua vez cada vértice armazena uma lista que contém as tuplas de arestas
    # A tupla é formada pelo vértice de destino e o custo associado para atingir o mesmo
    # Dessa forma o vértice 1 se liga com o vértice  2 ao custo de 7 (sem unidade definida)
    G = {1: [(2, 7), (4, 9), (5, 10), (6, 8), (8, 9), (10, 8)], 
         2: [(1, 7), (3, 4), (4, 5), (9, 9), (10, 9)],
         3: [(2, 4), (4, 1), (5, 4)],
         4: [(1, 9), (2, 5), (3, 1), (5, 3)],
         5: [(1, 10), (3, 4), (4, 3), (6, 18)], 
         6: [(1, 8), (5, 18), (7, 9), (8, 9)], 
         7: [(6, 9), (8, 3), (9, 6)], 
         8: [(1, 9), (6, 9), (7, 3), (9, 4), (10, 2)], 
         9: [(2, 9), (7, 6), (8, 4), (10, 2)], 
         10: [(1, 8), (2, 9), (8, 2), (9, 2)]}
    for keys,values in G.items():
        print(keys, ':', values)
    # Para calcular o custo da viagem considere que:
    # A origem da viagem é na cidade 4
    # Autonomia de 12km por litro
    # Preço do combustível 5 reais o litro
    # Preço de pedágio fixo de 6 reais 
    # D = dijkstra(G, 4, 1, 1, 0)
    #print(D)
    origem = 4
    destino = 10
    autonomia = 1
    combustivel = 1
    D, A = dijkstra(G, origem, autonomia, combustivel, pedagio_por_vertice)
    print(D)
    print(A)
    caminho = caminho_minimo(origem, destino, A) # Agora, reconstruímos e retornamos o caminho de menor custo usando o dicionário de pais
    if caminho is None:
        print("Não há caminho disponível de {} para {}.".format(origem, destino))
    else:
        print("Caminho mais barato de {} para {} é: {}".format(origem, destino, caminho))
        print("O custo total da viagem é: R$ {:.2f}".format(D[destino]))

