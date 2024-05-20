escolas_rio = ("Porto da Pedra", "Beija-flor", "Salgueiro", "Grande Rio", "Unidos da Tijuca", "Imperatriz", "Mocidade", "Portela", "Vila Isabel", "Mangueira", "Paraíso do Tuiuti", "Viradouro")
lista_dicionarios = []
lista_escolas = []

continuar = True
while continuar:
    deletar = False
    nome_escola = input().split(': ')
    # devo deixar o 'nome_escola' no formato a ser adicionado no dicionario.
    if nome_escola == ['Fim']:
        continuar = False 
    else:
        
        nome_escola[1] = float(nome_escola[1])
        valor_procurado = nome_escola[0]
        if nome_escola[0] in escolas_rio: # verificando se a escola está na tupla das possíveis escolas do Rio
            if valor_procurado in lista_escolas: # verificando se a escola já foi chamada
                print(f"{nome_escola[0]} teve sua nota atualizada!")
                for dicionario in lista_dicionarios: # Esse for tem o intuito de remover o elemento que já estava na lista_dicionarios
                    if valor_procurado in dicionario.values():
                        lista_dicionarios.remove(dicionario)
            else:
                print(f'{nome_escola[0]} teve sua nota apurada!')    
            lista_dicionarios.append({'nome_escola' :nome_escola[0], 'nota': nome_escola[1]}) # adiciona os dicionarios em uma lista
            lista_escolas.append(nome_escola[0]) # adiciona o nome_escola para uma lista das escolas que já foram chamadas
        else:
            print('Epa, o que essa escola está fazendo aqui?!')

print("")
print("CLASSIFICAÇÃO DO CARNAVAL 2024:")
            
# criarei uma função para retornar os valores somente das notas dos dicionários.
def retornar_nota(n):
    return n['nota']
            
# após isso, devo fazer um 'for' para percorrer os elementos do dicionário,
# para que assim eu possa ordenar as escolas de samba.
lista_dicionarios.sort(key=retornar_nota, reverse=True)

# farei um 'for' para percorrer os elementos da lista:
for escola in range(len(lista_dicionarios)):
    elemento_lista = lista_dicionarios[escola]
    print(f"{escola + 1}. {elemento_lista.get('nome_escola')}: {elemento_lista.get('nota')}")
    
print("")  
print(f"É CAMPEÃ! A ESCOLA {lista_dicionarios[0].get('nome_escola')} É A GRANDE VENCEDORA DO CARNAVAL DE 2024, FAZENDO {lista_dicionarios[0].get('nota')} PONTOS!!")
print(f"Infelizmente, a escola {lista_dicionarios[-1].get('nome_escola')} não alcançou as expectativas, fazendo apenas {lista_dicionarios[-1].get('nota')} pontos, e foi rebaixada.")
    