using System;
using System.Collections.Generic;
using System.IO; // Necessário para ler/escrever arquivos
using System.Linq; // Necessário para usar LINQ

// === VARIÁVEIS E TIPOS ===
Console.WriteLine("==== VARIÁVEIS E TIPOS ====");
string nome = "Brenno";        // string (texto)
int idade = 18;               // int (inteiro)
double altura = 1.75;         // double (decimal)
bool ativo = true;            // bool (booleano - true ou false)

// === EXIBINDO VALORES ===
Console.WriteLine($"Olá, {nome}");
Console.WriteLine($"Idade: {idade}");
Console.WriteLine($"Altura: {altura}\n");

// === ENTRADA DO USUÁRIO ===
Console.WriteLine("==== ENTRADA DO USUÁRIO ====");
Console.Write("Qual sua comida favorita? ");
string comidaFavorita = Console.ReadLine();
Console.WriteLine($"Você gosta de {comidaFavorita}\n");

// === CONDICIONAIS ===
Console.WriteLine("==== CONDICIONAIS ====");
if (idade >= 18) {
    Console.WriteLine("Você é maior de idade.\n");
} else {
    Console.WriteLine("Você é menor de idade.\n");
}

// === LISTAS ===
Console.WriteLine("==== LISTAS ====");
List<string> frutas = new List<string> { "maçã", "banana", "uva" };
frutas.Add("laranja"); // adiciona item
Console.WriteLine($"Frutas disponíveis: {string.Join(", ", frutas)}\n");

// === LAÇO FOR ===
Console.WriteLine("==== LAÇO FOR ====");
Console.WriteLine("Listando frutas:");
foreach (string fruta in frutas) {
    Console.WriteLine($"- {fruta}");
}
Console.WriteLine();

// === LAÇO WHILE ===
Console.WriteLine("==== LAÇO WHILE ====");
int contador = 0;
while (contador < 3) {
    Console.WriteLine($"Contando: {contador}");
    contador++;
}
Console.WriteLine();

// === EXECUÇÃO DE FUNÇÃO ===
Console.WriteLine("==== FUNÇÃO ====");
Saudacao(nome);
Console.WriteLine();

// === DICIONÁRIOS ===
Console.WriteLine("==== DICIONÁRIOS ====");
Dictionary<string, object> pessoa = new Dictionary<string, object> {
    { "nome", nome },
    { "idade", idade },
    { "altura", altura }
};

Console.WriteLine($"Nome: {pessoa["nome"]}");
Console.WriteLine($"Altura: {pessoa["altura"]}\n");

// === SOMA DE TIPOS ===
Console.WriteLine("==== SOMA DE TIPOS ====");
Console.Write("Digite um número inteiro: ");
int n1 = int.Parse(Console.ReadLine());
Console.Write("Digite um número decimal: ");
double n2 = double.Parse(Console.ReadLine());
double soma = n1 + n2;
Console.WriteLine($"Soma dos números: {soma}\n");

// === OPERADORES ===
Console.WriteLine("==== OPERADORES ====");
Console.Write("Digite um número inteiro: ");
int a = int.Parse(Console.ReadLine());
Console.Write("Digite outro número inteiro: ");
int b = int.Parse(Console.ReadLine());

Console.WriteLine($"Soma: {a + b}");
Console.WriteLine($"Subtração: {a - b}");
Console.WriteLine($"Multiplicação: {a * b}");
// Divisão de inteiros em C# descarta os decimais. 
// Convertemos pelo menos um deles para double para ter a divisão exata.
Console.WriteLine($"Divisão: {(double)a / b}");
Console.WriteLine($"Módulo (resto da divisão): {a % b}");
Console.WriteLine();

// === TRATAMENTO DE ERROS ===
Console.WriteLine("==== TRATAMENTO DE ERROS ====");
try {
    Console.Write("Digite um número inteiro para testar erros: ");
    int numero = int.Parse(Console.ReadLine());
    Console.WriteLine($"Número digitado com sucesso: {numero}");
} catch (FormatException) {
    Console.WriteLine("Erro: Você não digitou um número inteiro válido!");
}
Console.WriteLine();

// === ORIENTAÇÃO A OBJETOS ===
Console.WriteLine("==== ORIENTAÇÃO A OBJETOS ====");
Cachorro meuCao = new Cachorro("Rex");
Console.WriteLine(meuCao.Latir());
Console.WriteLine();

// === ESCRITA E LEITURA DE ARQUIVOS ===
Console.WriteLine("==== ESCRITA E LEITURA DE ARQUIVOS ====");
// Escrita
string path = "estudo_csharp.txt";
File.WriteAllText(path, $"Arquivo de estudos criado com sucesso!\nNome do estudante: {nome}\n");

// Leitura
string conteudo = File.ReadAllText(path);
Console.WriteLine("Conteúdo lido do arquivo:");
Console.WriteLine(conteudo);

// === RECURSO ÚNICO (LINQ) ===
Console.WriteLine("==== RECURSO ÚNICO: LINQ (Language Integrated Query) ====");
List<int> numeros = new List<int> { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

// Usando LINQ para filtrar números pares maiores que 5
var resultadoLinq = numeros.Where(n => n % 2 == 0 && n > 5);

Console.WriteLine($"Números originais: {string.Join(", ", numeros)}");
Console.WriteLine($"Pares maiores que 5 (via LINQ): {string.Join(", ", resultadoLinq)}\n");

// === CONSTANTES E VALOR NULO (NULL) ===
Console.WriteLine("==== CONSTANTES E VALOR NULO ====");
// Em C#, usamos 'const' para constantes. O valor é definido na compilação e não muda.
const double PI = 3.14159;
Console.WriteLine($"Constante PI: {PI}");

// 'null' representa a ausência total de valor
string telefone = null;
if (telefone == null) {
    Console.WriteLine("Telefone não foi cadastrado (valor é null).\n");
}

// === SWITCH (MENU DE OPÇÕES) ===
Console.WriteLine("==== SWITCH (MENU DE OPÇÕES) ====");
Console.WriteLine("Menu: 1 - Falar com Atendente | 2 - Financeiro | 3 - Outros");
Console.Write("Escolha uma opção (1 a 3): ");
int opcao = int.Parse(Console.ReadLine());

// O 'switch' gerencia o menu de forma limpa e estruturada
switch (opcao) {
    case 1:
        Console.WriteLine("Direcionando para o Atendente...\n");
        break; // O 'break' impede que ele execute as opções de baixo
    case 2:
        Console.WriteLine("Direcionando para o Financeiro...\n");
        break;
    case 3:
        Console.WriteLine("Direcionando para Outros Assuntos...\n");
        break;
    default:
        // O 'default' é o caso executado se nenhuma opção acima for escolhida
        Console.WriteLine("Opção inválida!\n");
        break;
}


// === FUNÇÃO ===
// Métodos/funções em arquivos com instruções de nível superior (Top-Level Statements)
// devem ser definidos no final do arquivo.
void Saudacao(string pessoa) {
    Console.WriteLine($"Seja bem-vindo, {pessoa}");
}

// === CLASSES AUXILIARES ===
// Classes também devem ser definidas no final em arquivos com Top-Level Statements.
class Cachorro {
    public string Nome { get; set; }

    public Cachorro(string nome) {
        Nome = nome;
    }

    public string Latir() {
        return $"{Nome} diz: Au Au!";
    }
}
