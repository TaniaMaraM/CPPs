The Problem They Solve
Templates resolvem principalmente repetição de código.
In C, if you want a swap for different types, you write multiple functions:

void swap_int(int *a, int *b)   { ... }
void swap_float(float *a, float *b) { ... }
This is repetitive and error-prone. Templates let you write it once.

A template is a compile-time instruction for the compiler to generate a type-specific function (or class) on demand — no runtime cost, no code duplication.

What are Templates?
Imagine you want to write a swap function. In C you'd have to write one for int, one for float, one for char*, etc. In C++ without templates you'd do the same thing.

Templates solve this: you write the function once, and the compiler generates the specific version for whatever type you actually use.

The Core Idea
Type is unknown → use a placeholder → compiler fills it in at compile time
That placeholder is called a type parameter, written as T by convention.

Syntax
template <typename T>
void swap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}
template <typename T> — tells the compiler "this is a template, T is a placeholder for a type"
T — used exactly like a real type inside the function
When you call swap(a, b) with two ints, the compiler generates swap<int> automatically
You can also write class instead of typename — they mean the same thing here:

template <class T>   // identical meaning
How the Compiler Uses Them
int x = 1, y = 2;
swap(x, y);          // compiler deduces T = int, generates swap<int>
std::string a = "hi", b = "bye";
swap(a, b);          // compiler deduces T = std::string, generates swap<std::string>
This deduction happens at compile time — no runtime cost.

Why in the Header?
The compiler needs to see the full template definition to generate code for each type. That's why the subject says:

"Templates must be defined in the header files."

If you put them in a .cpp, other translation units can't see the definition → linker errors.

What ex00 Asks
Three function templates in whatever.hpp:

Function	Behaviour
swap(a, b)
swaps the two values, returns nothing
min(a, b)
returns the smallest; if equal, returns the second
max(a, b)
returns the greatest; if equal, returns the second
The only constraint: both arguments must be the same type and support comparison operators (<, >, etc.).

What Actually Happens at Compile Time
Templates are not real functions. They are blueprints — instructions for the compiler to generate a real function when needed.

Your template source code
        |
        v
Compiler sees: swap(x, y) where x, y are int
        |
        v
Compiler GENERATES: void swap<int>(int &a, int &b) { ... }
        |
        v
That generated code is compiled and linked as normal

A Concrete Mental Model
Think of a template like a cookie cutter:

The cookie cutter = your template definition
The cookie = the real function the compiler generates
The dough type = the actual type (int, std::string, etc.)
You define the cutter once. Every time you use a different dough, you get a new cookie. You never touch the cutter again.

What T Actually Is
T is just a name — a placeholder. The compiler replaces every T with the real type when instantiating.

template <typename T>
void swap(T &a, T &b) {
    T tmp = a;   // becomes: int tmp = a;
    a = b;
    b = tmp;
}
When you call swap(x, y) with two ints, the compiler literally rewrites the function replacing every T with int. You could name it anything — T, Type, MyType — but T is the convention.

Type Deduction — How the Compiler Knows What T Is
You don't have to tell the compiler what T is:

int a = 1, b = 2;
swap(a, b);           // compiler deduces T = int automatically
std::string x = "hi", y = "bye";
swap(x, y);           // compiler deduces T = std::string automatically
The compiler looks at the arguments you pass and deduces T. This is called template argument deduction.

You can be explicit if needed: swap<int>(a, b) — but usually you don't need to.


You know how in C you'd write a separate swap function for int, float, char — all doing the same thing with different types?"

"Yes."

"Templates let you write it once, and the compiler generates the specific version for you. You use T as a placeholder for the type, and when you actually call the function with an int, the compiler swaps T for int and compiles that version. It's like a stencil — you define the shape once, the compiler paints it in whatever colour you need."

If they ask "but when does that happen?":

"At compile time — not runtime. So there's zero performance cost. The compiler just produces multiple versions of the function behind the scenes, one per type you use."

If they ask "why in the header?":

"Because the compiler needs to see the full definition to generate the code. If it's hidden in a .cpp file, the compiler can't reach it when it needs to instantiate the template."


Por que repetir template <typename T> em cada função?
Cada função é um template independente. O T do swap não tem nada a ver com o T do min — são placeholders separados que existem apenas dentro da sua própria função.

Se não repetisses, o compilador não saberia que min também é um template — pensaria que T é um tipo desconhecido e daria erro.

Precisas de library?
Para este ficheiro, não — os templates são pure C++ sem depender de nada.

EX01:

Por que size_t em vez de int?
int pode ser negativo. Um tamanho de array nunca pode ser negativo — não faz sentido um array com -3 elementos.

size_t é um tipo sem sinal (unsigned), definido exactamente para representar tamanhos e índices em memória. É o tipo que o sizeof retorna, e o tipo padrão para índices de arrays.

O problema
Imagina que tens um array e queres fazer algo em cada elemento — imprimir, duplicar, converter, etc.

Sem templates, terias de escrever uma função separada para cada tipo:

void iterInt(int *arr, int len, void (*func)(int))    { ... }
void iterStr(std::string *arr, int len, void (*func)(std::string)) { ... }
Repetitivo, e se amanhã precisares de float, escreves outra.

A solução: iter genérico
Com templates, escreves uma vez:

template <typename T, typename F>
void iter(T *array, size_t len, F func)
{
    for (size_t i = 0; i < len; i++)
        func(array[i]);
}
E funciona para qualquer tipo:

iter(intArray,    5, print)   →  percorre ints, chama print em cada um
iter(stringArray, 3, print)   →  percorre strings, chama print em cada uma
iter(floatArray,  4, upper)   →  percorre floats, chama upper em cada um
Em termos simples
iter é um "for each" genérico. Em vez de tu escreveres o loop sempre que queres fazer algo num array, delegas isso ao iter e só dizes o que fazer (a função).

É o mesmo conceito que std::for_each da STL — mas como estamos no módulo 07 e a STL ainda é proibida, implementas tu próprio.
