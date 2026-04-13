Construtor — nunca pode ser virtual
O construtor cria o objecto do zero. Para chamar um método virtual o C++ precisa de uma vtable (tabela de funções virtuais) — mas a vtable só existe depois do objecto estar construído.

Ou seja: quando o construtor está a correr, o mecanismo de virtual ainda não existe. Não faz sentido, e o C++ nem permite:

virtual AForm();  // ❌ erro de compilação — proibido
Além disso, cada classe tem o seu próprio construtor com o seu próprio nome — AForm(), ShrubberyCreationForm() — nunca são chamados polimorficamente.

Destrutor — precisa de ser virtual quando há herança
Sem virtual no destrutor da base, acontece isto:

AForm *f = new ShrubberyCreationForm("garden");
delete f;
// qual destrutor é chamado?
SEM virtual ~AForm():               COM virtual ~AForm():
delete f → chama ~AForm()           delete f → vê o tipo real: ShrubberyCreationForm
         → ~ShrubberyCreationForm()          → chama ~ShrubberyCreationForm()
            NUNCA é chamado!                 → depois chama ~AForm()
            memory leak / UB                 correcto
O virtual no destrutor da base diz ao C++: "quando deletares via ponteiro de base, vai ver o tipo real e chama o destrutor correcto."

construtor → nunca virtual  (objecto ainda não existe)
destrutor  → virtual se há herança  (para não perder o destrutor da subclasse).

Orthodox Canonical Form — the four special functions every class must have in C++98:

class Foo
{
    public:
        Foo();                           // 1. Default constructor
        Foo(const Foo &other);           // 2. Copy constructor
        Foo &operator=(const Foo &other); // 3. Copy assignment operator
        ~Foo();                          // 4. Destructor
};
Why each one matters
1. Default constructor — lets you create an object without arguments:

Foo f;   // needs default ctor
2. Copy constructor — called when a new object is created from an existing one:

Foo b(a);       // copy ctor
Foo b = a;      // also copy ctor (initialisation, not assignment)
3. Copy assignment operator — called when assigning to an already existing object:

Foo b;
b = a;   // assignment operator (b already exists)
4. Destructor — called when the object goes out of scope or is deleted. Critical when you manage heap memory — without it, memory leaks.

Why C++98 requires you to define all four
If you don't define them, the compiler generates them automatically — but the auto-generated versions do shallow copies (copy pointers, not what they point to). That causes double-free bugs when two objects share the same heap memory.

By defining all four yourself, you control exactly what happens.

The subject exception
"exception classes do not have to be in OCF"
Your nested GradeTooHighException etc. — no need for copy ctor / assignment on those. Everything else must have all four.

Tema do módulo
O CPP05 introduz excepções em C++ (try, throw, catch) e junta isso a classes, herança e polimorfismo. O enredo é uma burocracia: Bureaucrats (níveis 1–150) e formulários que precisam de ser assinados e executados com nível suficiente — senão, lança-se uma excepção.

Ex00 — Bureaucrat
Classe base: nome + grade (1 = melhor, 150 = pior).
Validação no construtor: grade fora de [1,150] → throw GradeTooHighException() ou GradeTooLowException() (classes aninhadas que herdam de std::exception).
Incrementar / decrementar grade com os mesmos limites (cuidado: “subir” no cargo = diminuir o número do grade).
operator<< para imprimir o burocrata com std::cout.
No main, o código típico envolve testes em try { ... } catch (std::exception &e) { ... }.
Ideia central: erros não são “retornos” do construtor; usam-se excepções.

Ex01 — Form
Um formulário tem nome, se está assinado, e grades mínimos para assinar e para executar (conforme o subject).
beSigned(Bureaucrat): se o burocrata for demasiado “baixo” (número do grade maior que o exigido), lança excepção; caso contrário marca como assinado.
Ideia central: regras de negócio dentro da classe; encapsulamento + excepções.

Ex02 — AForm + três formulários concretos
Form passa a AForm (classe abstracta): por exemplo virtual void execute(...) const = 0;.
Não se instancia AForm directamente; existem ShrubberyCreationForm, RobotomyRequestForm, PresidentialPardonForm, cada um com o seu execute.
Habitualmente há um checkExecution (assinado? executor com grade suficiente?) antes da acção real.
Shrubbery: escreve ficheiro com árvores ASCII. Robotomy: aleatoriedade (ex.: rand()). Presidential: mensagem de perdão.
Ideia central: ligação ao CPP04 ex02 (abstract class + override) + excepções.

Ex03 — Intern (factory)
O Intern não “é” um formulário; fabrica formulários a partir de um nome de string (ex.: "shrubbery creation").
Padrão típico: tabela nome → função que cria AForm* (typedef de ponteiro para função, struct com name + creator, etc.).
Polimorfismo: devolves AForm* mas o objecto real é Shrubbery, Robotomy ou Presidential.
Ideia central: factory simples + o mesmo polimorfismo de AForm*.

Mapa mental rápido
Exercício	Foco principal
00
Excepções + Bureaucrat + grade
01
Form + assinatura + validação
02
AForm abstracto + execute em cada tipo + ficheiro / aleatoriedade
03
Intern + criar o form certo pelo nome
Frase para a eval (inglês)
"CPP05 is about C++ exceptions — try, throw, catch — combined with classes. We have bureaucrats with grades and forms that must be signed and executed at the right grade, or we throw. In ex02 we use an abstract base form with concrete execute implementations. In ex03 we add an intern that builds the right form type from a string — a simple factory pattern."

Se quiseres, no próximo passo podemos focar só ex03 (o teu intern.cpp) linha a linha.











prompt:
You are my C++ mentor and pair programming partner.

Your main goal is to help me LEARN, not just solve exercises cpp07.

Core workflow:

1. First, help me fully understand the problem before writing any code.
2. Explain the relevant concepts in a simple and clear way (assume I am a beginner).
3. Discuss possible approaches to solve the problem.
4. Present at least TWO possible solutions:

   * One simple and beginner-friendly
   * One more idiomatic, clean, or optimized (modern C++ when relevant)
5. Only AFTER that, we implement the solution together step by step.

STRICT RULES:

* DO NOT write or modify full code immediately.
* DO NOT rewrite my files on your own.
* DO NOT jump directly to the final solution.
* Always ask or wait before implementing changes.
* Only provide full code if I explicitly ask for it.

When I share code:

* First, analyze my reasoning and logic.
* Point out mistakes, edge cases, and improvements.
* Guide me with hints instead of giving the answer immediately.
* If I get stuck, progressively reveal more detailed help.

Teaching style:

* Explain concepts before using them.
* Use simple language and practical examples.
* Break problems into small, understandable steps.
* Reinforce good practices (naming, structure, readability, memory management).

Mindset:

* Act like a senior developer mentoring a junior.
* Be patient, supportive, and clear.
* Prioritize understanding over speed.

Important:

* Never assume I understand advanced C++ concepts unless you have explained them first.
* I prefer to type and build the code myself to reinforce learning.

