Approach:
1. Detect the type of the input string
2. Parse it into the detected type
3. Convert to the other three types
4. Display with proper formatting


Parsing do input é o caminho! Mas precisas de ser mais específico nos padrões:

Char: 'c' → tem aspas simples ao redor
Int: 42, -42 → apenas dígitos (e sinal opcional)
Float: 42.0f, -4.2f → tem ponto decimal E termina com f
Double: 42.0, -4.2 → tem ponto decimal mas SEM f

Ordem de verificação importa:
1. É char? → verifica se tem aspas: 'x'
2. É float especial? → verifica se é "nanf", "+inff", "-inff"
3. É double especial? → verifica se é "nan", "+inf", "-inf"
4. Tem 'f' no final? → é float
5. Tem '.'? → é double
6. Só dígitos? → é int

2. Pseudo-literais: nan, inf - O que são?
Estes são valores especiais de ponto flutuante (float/double) definidos pelo padrão IEEE 754. Deixa-me explicar:

nan = "Not a Number"
É o resultado de operações matemáticas inválidas:
double result = 0.0 / 0.0;  // nan
double result = sqrt(-1);    // nan

Analogia: Imagina que perguntas "quanto é zero dividido por zero?" — a matemática não tem resposta. É nan.

inf = "Infinity" (infinito)
É o resultado quando um número é demasiado grande:
double result = 1.0 / 0.0;   // +inf
double result = -1.0 / 0.0;  // -inf
double result = 1e308 * 10;  // +inf (overflow)

Analogia: É como dividir uma pizza por zero pessoas — quantas fatias cada um recebe? Infinitas!

Versões float vs double:
Float: nanf, +inff, -inff (com f no final)
Double: nan, +inf, -inf (sem f)


EX01:

O QUE É uintptr_t?
É um tipo de inteiro grande o suficiente para guardar um ponteiro:

Data* ptr = &myData;           // ponteiro (8 bytes em 64-bit)
uintptr_t num = (uintptr_t)ptr; // converte para inteiro
Data* back = (Data*)num;        // converte de volta

Este exercício é muito simples — só precisas de fazer type casting!
Data.hpp          → struct com dados
Serializer.hpp    → classe com serialize/deserialize
Serializer.cpp    → implementação (quase vazia!)
main.cpp          → testa

CONCEITO CHAVE: reinterpret_cast
Este é o cast mais poderoso do C++:
O que faz: Reinterpreta os bits de value como NewType (sem conversão).

Analogia: É como pegar numa caixa e dizer "agora isto é um número" sem mudar o conteúdo.
Ponteiro:  0x7fff5fbff8ac  (endereço de memória)
             ↓ reinterpret_cast
Número:    140734799814828  (mesmos bits, tipo diferente)
             ↓ reinterpret_cast
Ponteiro:  0x7fff5fbff8ac  (de volta!)

1. Crias Data original
   original.name = "Tania"
   &original = 0x7fff5fbff8ac

2. Serialize
   uintptr_t num = serialize(&original)
   num = 140734799814828

3. Deserialize
   Data* ptr = deserialize(140734799814828)
   ptr = 0x7fff5fbff8ac

4. Verificar
   ptr == &original? → YES ✅

   Conceito: Serialização de Ponteiros
Na vida real, serialização é usada para:

Guardar objectos em ficheiros

Objecto em memória → Bytes → Ficheiro
Enviar objectos pela rede

Objecto → Bytes → TCP/IP → Bytes → Objecto
Passar entre processos


Processo A → Número → Processo B

Pergunta: "O que faz reinterpret_cast?"
Resposta curta:

"Reinterpreta os bits de um valor como outro tipo, sem fazer conversão. É como dizer ao compilador: 'confia em mim, trata estes bits como este outro tipo'."

Pergunta: "Por que usaste reinterpret_cast aqui?"
Resposta:

"Porque preciso de converter um ponteiro (Data*) para um inteiro (uintptr_t). Outros casts não permitem isto:

static_cast não funciona (tipos incompatíveis)
dynamic_cast é para polimorfismo
const_cast é para const/volatile
reinterpret_cast é o único que permite reinterpretar o endereço de memória (ponteiro) como um número inteiro."

Pergunta: "É seguro usar reinterpret_cast?"
Resposta:

"Geralmente é perigoso porque não há verificações. MAS no nosso caso é seguro porque:

uintptr_t é garantido para guardar ponteiros (definido no standard)
Fazemos a conversão de volta para o mesmo tipo (Data*)
Não perdemos informação no processo
É como guardar um endereço numa etiqueta e depois usar a etiqueta para voltar ao mesmo endereço."

MEMÓRIA:
┌─────────────────────────────────┐
│ Endereço: 0x7fff5fbff8ac        │
│ ┌─────────────────┐             │
│ │ Data            │             │
│ │  value: 42      │             │
│ └─────────────────┘             │
└─────────────────────────────────┘
        ↑
        │ Data* ptr = &myData
        │
        
SERIALIZE (reinterpret_cast<uintptr_t>):
        │
        ↓
   140734799814828  (número que representa o endereço)
        │
        │ uintptr_t num
        │
        
DESERIALIZE (reinterpret_cast<Data*>):
        │
        ↓
┌─────────────────────────────────┐
│ Endereço: 0x7fff5fbff8ac        │  ← MESMO ENDEREÇO!
│ ┌─────────────────┐             │
│ │ Data            │             │
│ │  value: 42      │             │  ← MESMOS DADOS!
│ └─────────────────┘             │
└─────────────────────────────────┘

ex02:
1. dynamic_cast - Type Identification
Como descobrir o tipo real de um objecto polimórfico SEM typeid()?

Resposta: Usa dynamic_cast!