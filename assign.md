Zkus tuhle — je dost malá na ~3 hodiny práce, ale pořád zábavná a dobře procvičí C, práci s terminálem i logiku hry.

# „Signal Lost“ — terminálová survival hra

## Premisa

Jsi operátor poškozené vesmírné stanice. Každé kolo se zhoršují systémy a ty musíš rozhodovat, co opravíš dřív, než stanice exploduje nebo dojde kyslík.

Inspirace:

* FTL
* Papers Please (tlak rozhodnutí)
* old-school ASCII hry

---

# Herní mechaniky

Máš 4 systémy:

* Energie
* Kyslík
* Teplota
* Komunikace

Každý tah:

* všechny systémy trochu klesnou
* náhodná událost něco poškodí
* hráč zvolí jednu akci

Pokud některý systém spadne na 0 → konec hry.

Cíl:

* přežít 20 kol
* nebo obnovit komunikaci na 100 %

---

# Jak to může vypadat

```txt
========================
      SIGNAL LOST
========================

Kolo: 7

Energie:     54
Kyslik:      38
Teplota:     61
Komunikace:  22

Udalost:
> Zkrat v energeticke siti!

Co chces udelat?

1. Opravit energii
2. Stabilizovat kyslik
3. Opravit chlazeni
4. Posilit signal
5. Nic (risk)

>
```

---

# Náhodné události

Pole stringů:

```c
"Unik kysliku"
"Porucha reaktoru"
"Meteoricky naraz"
"Pozar v serverovne"
"Ruseni signalu"
```

Každá událost:

* poškodí konkrétní stat
* vypíše zprávu

---

# Co procvičíš

## Základy C

* `struct`
* `switch`
* `rand()`
* cykly
* funkce
* práce s textem

## Dobrá struktura programu

Např.:

```c
void print_status();
void random_event();
void player_action();
int game_over();
```

---

# Rozšíření (když zbude čas)

## ASCII UI

Bar ukazatele:

```txt
Kyslik: [######----]
```

---

## Inventory

Např.:

* repair kit
* battery
* oxygen tank

---

## Difficulty scaling

Každé kolo větší poškození.

---

## Více konců

* Exploze
* Udušení
* Úspěšný SOS signál
* Záchrana lodí

---

# Ideální scope na 3 hodiny

## 1. hodina

* game loop
* staty
* input

## 2. hodina

* random event systém
* opravy
* game over

## 3. hodina

* polish
* ASCII UI
* balancing

---

# Mini datová struktura

```c
typedef struct {
    int energy;
    int oxygen;
    int temperature;
    int communication;
    int turn;
} Station;
```

---

# Bonus challenge

Přidej:

* realtime timer
* ukládání skóre do souboru
* ANSI barvy v terminálu
* hidden ending

---

Pokud chceš, můžu ti ještě:

* navrhnout kompletní architekturu souborů,
* dát starter code,
* nebo vymyslet ještě jiný typ hry (roguelike, hacking simulator, dungeon crawler, tower defense apod.).
