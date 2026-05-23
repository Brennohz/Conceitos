#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream> // Necessário para ler/escrever arquivos

// ============================================================================
// O QUE É O "std::" ?
// ============================================================================
// Em C++, todas as ferramentas da biblioteca padrão (como cout, string, vector)
// vivem dentro de um "namespace" (espaço de nomes) chamado "std".
// 
// Para usá-los, a forma mais explícita e segura é usar o prefixo: std::cout, std::string.
// 
// A linha abaixo ("using namespace std;") é um atalho que diz ao compilador:
// "Se eu digitar cout ou string sem o prefixo, procure no namespace std."
// 
// DICA DE BOA PRÁTICA: Usar "using namespace std" é aceitável em arquivos de estudo e scripts
// pequenos, mas em projetos reais (principalmente em arquivos .h / header files)
// deve ser evitado para não poluir o namespace global e evitar conflitos de nomes.
// 
// Exemplo de como seria usar SEM o atalho:
// std::cout << "Olá Mundo" << std::endl;
// ============================================================================
using namespace std;

// === ORIENTAÇÃO A OBJETOS (CLASSES) ===
class Cachorro {
public:
    string nome_cao;

    // Construtor
    Cachorro(string n) {
        nome_cao = n;
    }

    // Método
    string latir() {
        return nome_cao + " diz: Au Au!";
    }
};

// === FUNÇÃO ===
// Em C++, a função precisa ser declarada ou definida antes de ser chamada.
void saudacao(string pessoa) {
    cout << "Seja bem-vindo, " << pessoa << endl;
}

int main() {
    // Configura o console para aceitar acentos no Windows
    setlocale(LC_ALL, "Portuguese");

    // === VARIÁVEIS E TIPOS ===
    cout << "==== VARIÁVEIS E TIPOS ====\n";
    string nome = "Brenno";        // texto
    int idade = 18;               // inteiro
    double altura = 1.75;         // decimal (ponto flutuante)
    bool ativo = true;            // booleano (true ou false)

    // === EXIBINDO VALORES ===
    cout << "Olá, " << nome << endl;
    cout << "Idade: " << idade << endl;
    cout << "Altura: " << altura << "\n\n";

    // === ENTRADA DO USUÁRIO ===
    cout << "==== ENTRADA DO USUÁRIO ====\n";
    string comida_favorita;
    cout << "Qual sua comida favorita? ";
    cin >> comida_favorita; // Lembrete: cin lê apenas até o primeiro espaço
    cout << "Você gosta de " << comida_favorita << "\n\n";

    // === CONDICIONAIS ===
    cout << "==== CONDICIONAIS ====\n";
    if (idade >= 18) {
        cout << "Você é maior de idade.\n\n";
    } else {
        cout << "Você é menor de idade.\n\n";
    }

    // === VETORES (LISTAS) ===
    cout << "==== VETORES (LISTAS) ====\n";
    vector<string> frutas = {"maçã", "banana", "uva"};
    frutas.push_back("laranja");  // adiciona item no final
    cout << "Frutas disponíveis: ";
    for (size_t i = 0; i < frutas.size(); i++) {
        cout << frutas[i] << (i < frutas.size() - 1 ? ", " : "");
    }
    cout << "\n\n";

    // === LAÇO FOR ===
    cout << "==== LAÇO FOR ====\n";
    cout << "Listando frutas:\n";
    for (string fruta : frutas) {
        cout << "- " << fruta << endl;
    }
    cout << "\n";

    // === LAÇO WHILE ===
    cout << "==== LAÇO WHILE ====\n";
    int contador = 0;
    while (contador < 3) {
        cout << "Contando: " << contador << endl;
        contador++;
    }
    cout << "\n";

    // === EXECUÇÃO DA FUNÇÃO ===
    cout << "==== FUNÇÃO ====\n";
    saudacao(nome);
    cout << "\n";

    // === MAPAS (DICIONÁRIOS) ===
    cout << "==== MAPAS (DICIONÁRIOS) ====\n";
    map<string, string> pessoa;
    pessoa["nome"] = nome;
    pessoa["idade"] = to_string(idade);
    pessoa["altura"] = to_string(altura);

    cout << "Nome: " << pessoa["nome"] << endl;
    cout << "Altura: " << pessoa["altura"] << "\n\n";

    // === SOMA DE TIPOS ===
    cout << "==== SOMA DE TIPOS ====\n";
    int n1;
    double n2;
    cout << "Digite um número inteiro: ";
    cin >> n1;
    cout << "Digite um número decimal: ";
    cin >> n2;
    double soma = n1 + n2; // conversão implícita de int para double
    cout << "Soma dos números: " << soma << "\n\n";

    // === OPERADORES ===
    cout << "==== OPERADORES ====\n";
    int a, b;
    cout << "Digite um número inteiro: ";
    cin >> a;
    cout << "Digite outro número inteiro: ";
    cin >> b;

    cout << "Soma: " << a + b << endl;
    cout << "Subtração: " << a - b << endl;
    cout << "Multiplicação: " << a * b << endl;
    // Divisão de inteiros em C++ descarta os decimais. 
    // É preciso converter pelo menos um deles para double/float para ter casas decimais.
    cout << "Divisão: " << (double)a / b << endl;
    cout << "Módulo (resto da divisão): " << a % b << endl;
    cout << "\n";

    // === TRATAMENTO DE ERROS ===
    cout << "==== TRATAMENTO DE ERROS ====\n";
    int numero;
    cout << "Digite um número inteiro para testar erros: ";
    // Em C++, o cin entra em estado de falha se o tipo digitado não coincidir.
    if (cin >> numero) {
        cout << "Número digitado com sucesso: " << numero << "\n\n";
    } else {
        cout << "Erro: Você não digitou um número inteiro válido!\n\n";
        cin.clear(); // Limpa o estado de erro do cin
        cin.ignore(10000, '\n'); // Descarta a entrada inválida que restou no buffer
    }

    // === ORIENTAÇÃO A OBJETOS ===
    cout << "==== ORIENTAÇÃO A OBJETOS ====\n";
    Cachorro meu_cao("Rex");
    cout << meu_cao.latir() << "\n\n";

    // === ESCRITA E LEITURA DE ARQUIVOS ===
    cout << "==== ESCRITA E LEITURA DE ARQUIVOS ====\n";
    // Escrita
    ofstream arquivo_escrever("estudo_cpp.txt");
    if (arquivo_escrever.is_open()) {
        arquivo_escrever << "Arquivo de estudos criado com sucesso!\n";
        arquivo_escrever << "Nome do estudante: " << nome << "\n";
        arquivo_escrever.close();
    }

    // Leitura
    ifstream arquivo_ler("estudo_cpp.txt");
    string linha;
    cout << "Conteúdo lido do arquivo:\n";
    if (arquivo_ler.is_open()) {
        while (getline(arquivo_ler, linha)) {
            cout << linha << endl;
        }
        arquivo_ler.close();
    }
    cout << "\n";

    // === RECURSO ÚNICO (PONTEIROS E REFERÊNCIAS) ===
    cout << "==== RECURSO ÚNICO: PONTEIROS E REFERÊNCIAS ====\n";
    int valor = 42;
    int* ponteiro = &valor; // Guarda o endereço de memória de 'valor'
    int& referencia = valor; // Cria um atalho/apelido para 'valor'

    cout << "Valor original: " << valor << endl;
    cout << "Endereço de memória (via Ponteiro): " << ponteiro << endl;
    cout << "Valor acessado através do Ponteiro: " << *ponteiro << endl;
    
    referencia = 99; // Alterar a referência altera o valor original
    cout << "Valor após alterar a referência: " << valor << "\n\n";

    // === CONSTANTES E VALOR NULO (NULLPTR) ===
    cout << "==== CONSTANTES E VALOR NULO ====\n";
    // Em C++, usamos a palavra-chave 'const' para declarar constantes.
    // O compilador impede qualquer tentativa de alterar este valor.
    const double PI = 3.14159;
    cout << "Constante PI: " << PI << endl;

    // 'nullptr' representa um ponteiro que não aponta para nenhum lugar (nulo/vazio)
    int* ponteiro_nulo = nullptr;
    if (ponteiro_nulo == nullptr) {
        cout << "O ponteiro está vazio (aponta para nullptr).\n\n";
    }

    // === SWITCH (MENU DE OPÇÕES) ===
    cout << "==== SWITCH (MENU DE OPÇÕES) ====\n";
    cout << "Menu: 1 - Falar com Atendente | 2 - Financeiro | 3 - Outros\n";
    int opcao;
    cout << "Escolha uma opção (1 a 3): ";
    cin >> opcao;

    // O 'switch' é a estrutura de controle ideal para menus em C++
    switch (opcao) {
        case 1:
            cout << "Direcionando para o Atendente...\n\n";
            break; // O 'break' impede que o código continue rodando as opções abaixo
        case 2:
            cout << "Direcionando para o Financeiro...\n\n";
            break;
        case 3:
            cout << "Direcionando para Outros Assuntos...\n\n";
            break;
        default:
            // O 'default' é executado se nenhuma das opções válidas for escolhida
            cout << "Opção inválida!\n\n";
            break;
    }

    return 0;
}
