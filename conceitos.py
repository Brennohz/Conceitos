# === VARIÁVEIS E TIPOS ===
print("==== VARIÁVEIS E TIPOS ====")
nome = "Brenno"           # string (texto)
idade = 18                # int (inteiro)
altura = 1.75             # float (decimal)
ativo = True              # booleano (True ou False)

# === EXIBINDO VALORES ===
print("Olá,", nome)
print("Idade:", idade)
print("Altura:", altura, "\n")

# === ENTRADA DO USUÁRIO ===
print("==== ENTRADA DO USUÁRIO ====")
comida_favorita = input("Qual sua comida favorita? ")
print("Você gosta de", comida_favorita, "\n")

# === CONDICIONAIS ===
print("==== CONDICIONAIS ====")
if idade >= 18:
    print("Você é maior de idade.\n")
else:
    print("Você é menor de idade.\n")

# === LISTAS ===
print("==== LISTAS ====")
frutas = ["maçã", "banana", "uva"]
frutas.append("laranja")  # adiciona item
print("Frutas disponíveis:", frutas, "\n")

# === LAÇO FOR ===
print("==== LAÇO FOR ====")
print("Listando frutas:")
for fruta in frutas:
    print("-", fruta)
print()

# === LAÇO WHILE ===
print("==== LAÇO WHILE ====")
contador = 0
while contador < 3:
    print("Contando:", contador)
    contador += 1
print()

# === FUNÇÃO ===
print("==== FUNÇÃO ====")
def saudacao(pessoa):
    print("Seja bem-vindo,", pessoa)

saudacao(nome)
print()

# === DICIONÁRIOS ===
print("==== DICIONÁRIOS ====")
pessoa = {
    "nome": nome,
    "idade": idade,
    "altura": altura
}

print("Nome:", pessoa["nome"])
print("Altura:", pessoa.get("altura"), "\n")

# === SOMA DE TIPOS ===
print("==== SOMA DE TIPOS ====")
n1 = int(input("Digite um número inteiro: "))
n2 = float(input("Digite um número decimal: "))
soma = n1 + n2
print("Soma dos números:", soma, "\n")

# === OPERADORES ===
print("==== OPERADORES ====")
a = int(input("Digite um número inteiro: "))
b = int(input("Digite outro número inteiro: "))

print("Soma:", a + b)
print("Subtração:", a - b)
print("Multiplicação:", a * b)
print("Divisão:", a / b)
print("Módulo (resto da divisão):", a % b)
print()

# === TRATAMENTO DE ERROS ===
print("==== TRATAMENTO DE ERROS ====")
try:
    numero = int(input("Digite um número inteiro para testar erros: "))
    print("Número digitado com sucesso:", numero)
except ValueError:
    print("Erro: Você não digitou um número inteiro válido!")
print()

# === ORIENTAÇÃO A OBJETOS (CLASSES) ===
print("==== ORIENTAÇÃO A OBJETOS ====")
class Cachorro:
    def __init__(self, nome_cao):
        self.nome_cao = nome_cao
        
    def latir(self):
        return f"{self.nome_cao} diz: Au Au!"

meu_cao = Cachorro("Rex")
print(meu_cao.latir())
print()

# === ESCRITA E LEITURA DE ARQUIVOS ===
print("==== ESCRITA E LEITURA DE ARQUIVOS ====")
# Escrita
with open("estudo_python.txt", "w", encoding="utf-8") as arquivo:
    arquivo.write("Arquivo de estudos criado com sucesso!\n")
    arquivo.write(f"Nome do estudante: {nome}\n")

# Leitura
with open("estudo_python.txt", "r", encoding="utf-8") as arquivo:
    conteudo = arquivo.read()
    print("Conteúdo lido do arquivo:")
    print(conteudo)
print()

# === RECURSO ÚNICO (LIST COMPREHENSION) ===
print("==== RECURSO ÚNICO: LIST COMPREHENSION ====")
numeros = [1, 2, 3, 4, 5]
quadrados = [x ** 2 for x in numeros]
print("Números originais:", numeros)
print("Quadrados gerados com List Comprehension:", quadrados)
print()

# === CONSTANTES E VALOR NULO (NONE) ===
print("==== CONSTANTES E VALOR NULO ====")
# Em Python, constantes são indicadas por convenção em letras MAIÚSCULAS.
# O interpretador não impede a alteração, mas avisa outros programadores para não mudarem.
PI = 3.14159
print("Constante PI (convenção):", PI)

# 'None' representa a ausência de valor (nulo)
telefone = None
if telefone is None:
    print("Telefone não foi cadastrado (valor é None).\n")

# === MATCH (MENU DE OPÇÕES) ===
print("==== MATCH (MENU DE OPÇÕES) ====")
print("Menu: 1 - Falar com Atendente | 2 - Financeiro | 3 - Outros")
opcao = int(input("Escolha uma opção (1 a 3): "))

# O 'match' (introduzido no Python 3.10) funciona como um menu de opções
match opcao:
    case 1:
        print("Direcionando para o Atendente...\n")
    case 2:
        print("Direcionando para o Financeiro...\n")
    case 3:
        print("Direcionando para Outros Assuntos...\n")
    case _:
        # O sublinhado (_) é o caso padrão, executado se nenhuma das opções acima for escolhida
        print("Opção inválida!\n")
