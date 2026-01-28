# Ex03 - Defense Guide

## Como Explicar na Eval (Guia Completo)

### 1. Diferença Reference vs Pointer

**Avaliador:** "Qual a diferença entre reference e pointer?"

**Tu:**
> "**Pointer** guarda um endereço e pode ser NULL. **Reference** é um alias (outro nome) para uma variável existente e nunca pode ser NULL. Syntaxe: pointer usa `*` e `->`, reference usa acesso directo como variável normal."

**Exemplo:**
```cpp
int x = 42;
int* ptr = &x;    // pointer: guarda endereço, pode mudar, pode ser NULL
int& ref = x;     // reference: É x, nunca muda, nunca NULL

*ptr = 10;        // acesso via dereference
ref = 10;         // acesso directo
```

---

### 2. Porque HumanA usa Reference?

**Avaliador:** "Porque HumanA tem `Weapon&` e não `Weapon*`?"

**Tu:**
> "Porque o subject diz que **HumanA sempre tem arma**. Como nunca pode estar sem arma (nunca NULL) e a arma nunca muda (é sempre a mesma), reference é perfeita: mais segura e sintaxe mais limpa."

**Código:**
```cpp
class HumanA {
    Weapon& weapon;  // ← reference: sempre válida, nunca muda
public:
    HumanA(std::string name, Weapon& weapon);  // recebe no constructor
};
```

---

### 3. Porque HumanB usa Pointer?

**Avaliador:** "Porque HumanB tem `Weapon*` e não `Weapon&`?"

**Tu:**
> "Porque o subject diz que **HumanB pode não ter arma**. Jim começa sem arma (NULL) e recebe depois via `setWeapon()`. Reference não pode ser NULL, então pointer é necessário."

**Código:**
```cpp
class HumanB {
    Weapon* weapon;  // ← pointer: pode ser NULL
public:
    HumanB(std::string name) : weapon(NULL) {}  // começa sem arma
    void setWeapon(Weapon& weapon);  // dá arma depois
};
```

---

### 4. Porque ambos vêem a mudança?

**Avaliador:** "Porque quando mudas `club.setType()`, Bob e Jim vêem a mudança?"

**Tu:**
> "Porque **ambos apontam/referem a MESMA arma** em memória. Não são cópias! Quando mudas a arma original, todos que apontam/referem para ela vêem a mudança."

**Visual:**
```
MEMÓRIA:
club (0x1000): "crude spiked club"  ← arma original
                ↑            ↑
          Bob.weapon    Jim.weapon
          (reference)   (pointer)
          
Depois de setType():
club (0x1000): "some other type of club"  ← mudou!
                ↑            ↑
          Bob.weapon    Jim.weapon
          (ambos vêem!)
```

---

### 5. Initialization List (importante!)

**Avaliador:** "Porque usaste initialization list no HumanA?"

**Tu:**
> "**References DEVEM ser inicializadas na initialization list**, não podem ser inicializadas no corpo do constructor. É obrigatório em C++."

**Código:**
```cpp
// ✅ CERTO
HumanA::HumanA(std::string name, Weapon& weapon) 
    : name(name), weapon(weapon) {  // ← initialization list
}

// ❌ ERRADO
HumanA::HumanA(std::string name, Weapon& weapon) {
    this->weapon = weapon;  // ← NÃO COMPILA! Reference já foi criada!
}
```

---

### 6. Porque `getType()` retorna `const std::string&`?

**Avaliador:** "O que significa `const std::string& getType() const`?"

**Tu:**
> "Retorna **reference para a string** (não copia, mais eficiente). O primeiro `const` significa que **não posso modificar a string retornada**. O segundo `const` significa que **o método não modifica o objecto Weapon**."

**Código:**
```cpp
const std::string& getType() const {
//     ↑                        ↑
//  não posso              não modifica
//  modificar              o Weapon
//  a string
    return type;
}
```

---

### 7. Acesso via Pointer vs Reference

**Avaliador:** "Qual a diferença entre `weapon.getType()` e `weapon->getType()`?"

**Tu:**

| HumanA (reference) | HumanB (pointer) |
|--------------------|------------------|
| `Weapon& weapon` | `Weapon* weapon` |
| `weapon.getType()` (acesso directo) | `weapon->getType()` (via pointer) |

```cpp
// HumanA
weapon.getType();  // reference: usa '.'

// HumanB
weapon->getType(); // pointer: usa '->'
// equivalente a: (*weapon).getType()
```

---

## Perguntas Difíceis (avançadas)

### Q1: "O que acontece se HumanB for destruído mas a arma ainda existir?"

**R:** Nada de errado! O pointer só guarda o endereço. A arma continua a existir (não é responsabilidade do HumanB apagá-la).

### Q2: "E se a arma for destruída mas HumanB ainda existir?"

**R:** **Dangling pointer!** `weapon` aponta para memória inválida. Precisarias verificar antes de usar ou usar smart pointers (C++11).

### Q3: "Podias usar reference em HumanB?"

**R:** Não! Reference nunca pode ser NULL. Como Jim pode começar sem arma, pointer é obrigatório.

---

## Checklist para Defesa

- ✅ Explicar diferença pointer/reference
- ✅ Justificar escolha em HumanA (reference)
- ✅ Justificar escolha em HumanB (pointer)
- ✅ Explicar initialization list
- ✅ Explicar `const` no getType()
- ✅ Mostrar que ambos vêem mudança (mesma arma)
- ✅ Explicar NULL em HumanB

---

## Output Esperado

```
Bob attacks with their crude spiked club
Bob attacks with their some other type of club
Jim attacks with their crude spiked club
Jim attacks with their some other type of club
```

**Crucial:** Ambos **vêem a mudança** quando `club.setType()` é chamado!
