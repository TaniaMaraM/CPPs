# Ex06 - Defense Guide (Harl Filter)

## Guia de Defesa - Ex06

### 1. O que é o Switch Statement?

**Avaliador:** "Explica o switch."

**Tu:**
> "O switch é uma alternativa ao `if/else` para comparar uma variável com múltiplos valores. É mais eficiente porque o compilador pode optimizar usando jump tables."

```cpp
switch (valor) {
    case 0:
        // executa se valor == 0
        break;
    case 1:
        // executa se valor == 1
        break;
    default:
        // executa se nenhum case corresponder
}
```

---

### 2. O que é Fall-through?

**Avaliador:** "Porque não tens break em todos os cases?"

**Tu:**
> "Isso chama-se **fall-through**. Quando não há `break`, o código **continua para o próximo case**. É intencional neste exercício porque queremos mostrar **todos os níveis a partir do escolhido**."

**Exemplo visual:**
```cpp
switch (lvl) {   // lvl = 2 (WARNING)
    case 0:
        debug();     // ← salta (lvl != 0)
    case 1:
        info();      // ← salta (lvl != 1)
    case 2:
        warning();   // ← ENTRA AQUI (lvl == 2)
                     // sem break! Cai para baixo ↓
    case 3:
        error();     // ← EXECUTA também!
        break;       // PARA
}
// Output: WARNING + ERROR
```

---

### 3. Porque converter string para int?

**Avaliador:** "Porque usas `getLevel()` para converter?"

**Tu:**
> "Porque o **switch em C++ só funciona com valores inteiros** (int, char, enum). Não posso fazer `switch(string)`. Então converto a string para um índice numérico primeiro."

```cpp
int getLevel(std::string level) {
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    //                        0        1        2         3
    
    for (int i = 0; i < 4; i++) {
        if (levels[i] == level)
            return i;  // retorna índice: 0, 1, 2 ou 3
    }
    return -1;  // não encontrado → vai para default
}
```

---

### 4. O que acontece com input inválido?

**Avaliador:** "E se passar um nível que não existe?"

**Tu:**
> "`getLevel()` retorna -1, que não corresponde a nenhum case (0-3), então cai no **default** e imprime a mensagem de erro."

```bash
./harlFilter "INVALID"
# lvl = -1
# switch(-1): nenhum case → default
# Output: "[ Probably complaining about insignificant problems ]"
```

---

### 5. Fluxo Completo

**Avaliador:** "Explica o fluxo com WARNING."

**Tu:**
```
./harlFilter "WARNING"
        ↓
main(): argv[1] = "WARNING"
        ↓
harl.filter("WARNING")
        ↓
getLevel("WARNING") → retorna 2
        ↓
switch(2):
  case 0: salta
  case 1: salta
  case 2: warning() ← ENTRA!
          ↓ (fall-through)
  case 3: error()
          break ← PARA
        ↓
Output:
[ WARNING ]
I think I deserve to have some extra bacon for free.

[ ERROR ]
This is unacceptable! I want to speak to the manager now.
```

---

### 6. Diferença entre Ex05 e Ex06

**Avaliador:** "Qual a diferença entre os dois exercícios?"

**Tu:**

| Ex05 | Ex06 |
|------|------|
| Pointers to member functions | Switch statement |
| Mostra **UM** nível | Mostra **esse nível e acima** |
| `complain("DEBUG")` → só DEBUG | `filter("DEBUG")` → DEBUG + INFO + WARNING + ERROR |
| Sem fall-through | **Com** fall-through |

---

### 7. Teste Rápido na Eval

```bash
./harlFilter "DEBUG"    # Mostra tudo
./harlFilter "INFO"     # INFO + WARNING + ERROR
./harlFilter "WARNING"  # WARNING + ERROR
./harlFilter "ERROR"    # Só ERROR
./harlFilter "abc"      # Mensagem de erro
./harlFilter            # Usage error (argc != 2)
```

---

## Resumo para Memorizar

1. **Switch:** alternativa a if/else para comparar com múltiplos valores
2. **Fall-through:** sem break → continua para próximo case
3. **getLevel():** converte string → int (switch não aceita strings)
4. **default:** executado quando nenhum case corresponde

---

## Output Esperado

```bash
$ ./harlFilter "WARNING"
[ WARNING ]
I think I deserve to have some extra bacon for free.

[ ERROR ]
This is unacceptable! I want to speak to the manager now.
```

```bash
$ ./harlFilter "DEBUG"
[ DEBUG ]
I love having extra bacon for my burger. I really do!

[ INFO ]
I cannot believe adding extra bacon costs more money.

[ WARNING ]
I think I deserve to have some extra bacon for free.

[ ERROR ]
This is unacceptable! I want to speak to the manager now.
```

```bash
$ ./harlFilter "INVALID"
[ Probably complaining about insignificant problems ]
```
