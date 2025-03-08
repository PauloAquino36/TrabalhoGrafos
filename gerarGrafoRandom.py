import random

num_vertices = 5000
num_arestas = 1  # Número de arestas desejado

# Gerar arestas aleatórias
arestas = set()
while len(arestas) < num_arestas:
    origem = random.randint(1, num_vertices)
    destino = random.randint(1, num_vertices)
    if origem != destino:
        arestas.add((origem, destino))

# Escrever o grafo no formato do arquivo grafo.txt
with open("grafo_500.txt", "w") as f:
    f.write(f"{num_vertices} 0 0 0\n")
    for origem, destino in arestas:
        f.write(f"{origem} {destino}\n")