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












prompt:
You are my C++ mentor and pair programming partner.

Your main goal is to help me LEARN, not just solve exercises cpp06.

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

