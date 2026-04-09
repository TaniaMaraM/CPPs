# CPP05 — Explicação Didáctica Completa

## Contexto geral

O CPP05 ensina **excepções em C++** (`try`, `throw`, `catch`) e como combiná-las com **classes**, **herança** e **polimorfismo**. O cenário inventado é uma burocracia: há **Bureaucrats** (funcionários) e **Forms** (formulários). Funcionários assinam e executam formulários, mas só se tiverem nível suficiente — caso contrário, lançam uma excepção.

---

## EX00 — `Bureaucrat`: a base de tudo

### Bloco 1 — O ficheiro de cabeçalho (`Bureaucrat.hpp`)

```cpp
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

class Bureaucrat
{
    private:
        const std::string _name;
        int               _grade;
    public:
        class GradeTooHighException : public std::exception { ... };
        class GradeTooLowException  : public std::exception { ... };
        // getters, incrementGrade, decrementGrade
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);
```

**O que está a acontecer:**
Define a "planta" da classe `Bureaucrat`. Cada burocrata tem um nome (imutável — `const`) e um nível (`_grade`) entre 1 (melhor) e 150 (pior). Dentro da classe existem **duas classes de excepção** aninhadas que herdam de `std::exception`, tornando-as "lançáveis" com `throw`.

**Em linguagem humana:**
> "Aqui eu defino o que é um burocrata — o seu nome, o seu nível, e os dois tipos de erro possíveis se o nível for inválido."

| Termo | Explicação simples |
|---|---|
| `class` | Um molde para criar objectos |
| `private` | Atributos que só a própria classe pode tocar |
| `const std::string _name` | Uma variável de texto que **nunca pode mudar** após ser criada |
| `std::exception` | A classe-mãe de todos os erros em C++ |
| classe dentro de classe | Uma classe aninhada — existe dentro do espaço da outra |

**Erro comum de iniciante:**
Esquecer o `#ifndef / #define / #endif` — sem isso o ficheiro seria incluído duas vezes e daria erros de duplicação.

---

### Bloco 2 — Construtores e validação (`Bureaucrat.cpp`)

```cpp
Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    _grade = grade;
}
```

**O que está a acontecer:**
Quando alguém cria `Bureaucrat("Tania", 0)`, o construtor verifica se o nível é válido. Se não for, **lança uma excepção** em vez de criar o objecto.

**Em linguagem humana:**
> "Aqui eu recebo o nome e o nível. Se o nível for impossível, grito um erro — não crio o funcionário."

**Conceitos:**
- **`throw`** — lançar uma excepção, como atirar um alarme
- **Initializer list** (`: _name(name)`) — forma obrigatória de inicializar atributos `const` antes do corpo do construtor

**Porquê `throw` e não `return`?**
O construtor não tem valor de retorno. A única forma de sinalizar erro num construtor é lançar uma excepção.

---

### Bloco 3 — `incrementGrade` / `decrementGrade`

```cpp
void Bureaucrat::incrementGrade()
{
    if (_grade - 1 < 1)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade()
{
    if (_grade + 1 > 150)
        throw GradeTooLowException();
    _grade++;
}
```

**O que está a acontecer:**
- Incrementar o nível = subir de posto = **diminuir** o número (grade 5 → grade 4)
- Decrementar = descer de posto = **aumentar** o número

**Em linguagem humana:**
> "Verifico se posso promover ou rebaixar o funcionário. Se já estiver no limite, lanço um erro."

**Erro comum de iniciante:**
Confundir "incrementar o grade" com "aumentar o número". Na burocracia deste exercício, **nível 1 é o melhor**, então incrementar = reduzir o número.

---

### Bloco 4 — `operator<<` (impressão)

```cpp
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return out;
}
```

**O que está a acontecer:**
Sobrecarga do operador `<<` para que `std::cout << tania` imprima algo legível.

**Em linguagem humana:**
> "Aqui eu ensino o C++ como imprimir um burocrata — em vez de não imprimir nada, imprime o nome e o nível."

**Conceito:** sobrecarga de operador (*operator overloading*) — redefinir o comportamento de um símbolo (`<<`) para um tipo personalizado.

---

### Bloco 5 — `main.cpp` do ex00

```cpp
try
{
    Bureaucrat tania("tania", 50);
    std::cout << tania << std::endl;
}
catch (std::exception &e)
{
    std::cout << "Exception: " << e.what() << std::endl;
}
```

**O que está a acontecer:**
Cada teste está envolvido em `try/catch`. Se algo lançar uma excepção dentro do `try`, o `catch` apanha-a e imprime a mensagem de erro.

**Em linguagem humana:**
> "Aqui eu tento fazer algo arriscado. Se der errado, em vez de o programa rebentar, apanho o erro e mostro uma mensagem bonita."

| Palavra | Significado simples |
|---|---|
| `try` | "Tenta fazer isto..." |
| `throw` | "...deu errado, lança este erro!" |
| `catch` | "Se algum erro aparecer, faz isto" |
| `e.what()` | A mensagem de texto do erro |

---

## EX01 — `Form`: o primeiro formulário

Um burocrata pode tentar **assinar** um formulário, mas só se o seu nível for suficientemente alto.

### Bloco — `beSigned`

```cpp
void Form::beSigned(Bureaucrat const &b)
{
    if (b.getGrade() > _gradeSign)
        throw GradeTooLowException();
    _signed = true;
}
```

**O que está a acontecer:**
O formulário verifica se o burocrata tem nível suficiente. Número menor = nível mais alto. Se `b.getGrade()` (ex: 100) for **maior** que `_gradeSign` (ex: 50), o burocrata é demasiado inferior — lança excepção.

**Em linguagem humana:**
> "O formulário verifica se o funcionário tem autoridade suficiente para o assinar. Se não tiver, recusa."

**Conceito:** **encapsulamento** — o formulário protege os seus próprios dados e só permite mudanças válidas.

---

## EX02 — `AForm`: classe abstracta + formas concretas

### O que mudou em relação ao ex01?

`Form` tornou-se `AForm` (**Abstract Form**). Não se pode criar um `AForm` directamente — é apenas um molde. O exercício obriga a criar três formulários concretos.

### Bloco — A função virtual pura

```cpp
virtual void execute(Bureaucrat const &executor) const = 0;
```

**O que está a acontecer:**
`= 0` significa "função virtual pura" — **esta função não tem implementação aqui**. Cada classe filha OBRIGATORIAMENTE tem de a implementar.

**Em linguagem humana:**
> "Estou a dizer: 'todo o formulário tem de saber executar-se, mas não sei como — cada tipo de formulário decidirá por si próprio.'"

**Conceito:** **polimorfismo** — o mesmo método (`execute`) comporta-se de forma diferente consoante o tipo de objecto.

---

### Bloco — `checkExecution` (helper protegido)

```cpp
void AForm::checkExecution(Bureaucrat const &executor) const
{
    if (!_signed)
        throw NotSignedException();
    if (executor.getGrade() > _gradeExecute)
        throw GradeTooLowException();
}
```

**O que está a acontecer:**
Antes de qualquer formulário executar a sua acção, chama esta função para validar dois requisitos: está assinado? O executor tem nível suficiente?

**Em linguagem humana:**
> "Verificação dupla antes de agir: 'o papel foi assinado?' e 'esta pessoa tem autoridade suficiente?'"

**Conceito:** `protected` — visível pelas classes filhas mas não pelo mundo exterior. Nível de acesso intermédio entre `private` e `public`.

---

### Bloco — `ShrubberyCreationForm::execute`

```cpp
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    checkExecution(executor);

    std::ofstream file((_target + "_shrubbery").c_str());
    file << "       *       \n"
         << "      ***      \n"
         << "     *****     \n"
         << "    *******    \n"
         << "   *********   \n"
         << "      ***      \n"
         << "      ***      \n";
    file.close();
}
```

**O que está a acontecer:**
Valida, depois **cria um ficheiro** no disco com árvores ASCII.

**Conceito:** `std::ofstream` — variável para escrever em ficheiros (output file stream).

---

### Bloco — `RobotomyRequestForm::execute`

```cpp
void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    checkExecution(executor);
    std::cout << "BZZZZZZZT DRRRRRR VRRRMMM *drilling noises*" << std::endl;
    if (std::rand() % 2 == 0)
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << _target << " robotomy failed." << std::endl;
}
```

**O que está a acontecer:**
50% de hipótese de sucesso. `rand() % 2` dá 0 ou 1 — como lançar uma moeda ao ar.

**Conceito:** **aleatoriedade** com `rand()` — números pseudo-aleatórios.

---

## EX03 — `Intern`: o padrão Factory

### Bloco — `typedef` (ponteiro para função)

```cpp
typedef AForm *(*Creator)(const std::string &);
```

**O que está a acontecer:**
Cria um alias de tipo chamado `Creator`. Representa "ponteiro para uma função que recebe uma `string` e devolve um `AForm*`".

**Em linguagem humana:**
> "Estou a dar um nome curto a um tipo complicado, para poder guardar funções numa tabela."

---

### Bloco — `struct Entry` e a tabela

```cpp
struct Entry {
    std::string name;
    Creator     creator;
};

Entry table[] = {
    {"shrubbery creation",  createShrubbery},
    {"robotomy request",    createRobotomy},
    {"presidential pardon", createPardon}
};
```

**O que está a acontecer:**
Um array de fichas. Cada ficha associa um nome de formulário a uma função criadora.

**Em linguagem humana:**
> "Aqui está a minha lista de formulários conhecidos. Cada linha diz: 'se o nome for X, chama a função Y.'"

| `name` | `creator` |
|---|---|
| `"shrubbery creation"` | `createShrubbery` |
| `"robotomy request"` | `createRobotomy` |
| `"presidential pardon"` | `createPardon` |

**Porquê tabela e não `if/else`?**
Com `if/else` é preciso acrescentar um bloco novo para cada formulário. Com a tabela, basta adicionar uma linha. É o **padrão Factory com tabela de dispatch**.

---

### Bloco — O loop de pesquisa

```cpp
for (int i = 0; i < 3; i++)
{
    if (table[i].name == formName)
    {
        std::cout << "Intern creates " << formName << std::endl;
        return table[i].creator(target);
    }
}

std::cout << "Intern: unknown form name '" << formName << "'" << std::endl;
return NULL;
```

**O que está a acontecer:**
Percorre a tabela, compara o nome. Se encontrar, chama a função criadora e devolve o objecto. Se não encontrar, devolve `NULL`.

**Em linguagem humana:**
> "Percorro a lista. Para cada ficha, pergunto: 'este nome bate certo?' Se sim, chamo a função da ficha e devolvo o formulário criado."

**Fluxo visual:**
```
makeForm("robotomy request", "Alice")
        │
        ▼
i=0: "shrubbery creation" == "robotomy request"? NÃO
i=1: "robotomy request"   == "robotomy request"? SIM ✓
        │
        ▼
chama createRobotomy("Alice")
        │
        ▼
devolve new RobotomyRequestForm("Alice")
```

**Erro comum de iniciante:** não verificar se o valor devolvido é `NULL` antes de o usar — chamando `form->execute(...)` com `NULL` causa segfault.

---

## Resumo geral do CPP05

| Exercício | O que acrescenta | Conceito-chave |
|---|---|---|
| **ex00** | Burocrata com nível, validação | `throw`, `try/catch`, excepções personalizadas |
| **ex01** | Formulário que pode ser assinado | Interacção entre classes, `beSigned` |
| **ex02** | Classe abstracta + 3 formulários concretos | `virtual`, herança, polimorfismo |
| **ex03** | Estagiário que cria formulários | Padrão Factory, ponteiros para funções |

**A história completa em voz alta:**
> "No CPP05 criei um sistema burocrático. Tenho funcionários com um nível numérico. Se tentarmos criar um funcionário com nível inválido, o programa lança uma excepção em vez de rebentar silenciosamente. Criei formulários que precisam de ser assinados e executados por funcionários com nível suficiente. A classe `AForm` é abstracta — tem um método `execute` sem implementação que cada formulário concreto implementa à sua maneira. Por fim, o `Intern` usa um padrão Factory com uma tabela de ponteiros para funções para criar qualquer formulário dado o seu nome, sem uma cadeia de `if/else`."
