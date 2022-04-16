# **Výpočet determinantu**
**Vytvořil:**
<br>
Benjamin Rodr
<br>
# **Popis**

Tato semestrální práce je na téma výpočtu determiantu matice n x n. Pro výpočet determinantu se matice postupně upravuje pomocí GEM do tvaru kdy pod hlavní diagonálou jsou pouze nuly a během tohoto procesu násobí čísla na diagonále, čímž vznikne daný determinant.
<br>
<br>

**Implementace**
<br>
Jednovláknová implementace spočítá determinant již výše zmíněným způsobem. Vícevláknová (2,4,8,10) implementace při každém kroku GEM rozdělí matici na počet částí podle počtu vláken, tam každé vlákno upraví řádky podle současně používaného řádku na úpravu. Program bez zadání argumentu pro počet jader automaticky zvolí nejvyšší dostupnou pro zařízení uživatele pomocí thread::hardware_concurrency().
<br>
<br>

**Měření**
<br>
Měření proběhlo na kódu v commitu b24e6a8715d12dcda2ce07358cfb019cc79ea9be na 6 jádrovém Ryzen 4600H.
Měření probíhalo s maticemi o dimenzi 2000 a maticemi o dimenzi 5000. vždy se počítal determinant ze stejné matice.
Z měření vyšlo, že u těchto dimenzí je nejrychlejší implementace se 4 vlákny. Zároveň jakákoliv vícevláknová implementace byla rychlejší než základní jednovláknová. Nicméně osmivláknová a desetivláknová měly horší čas než čtyřvláknová. Domnívám se že to je způsobeno malými daty. Kdyby se pracovalo s dimenzí o velikosti desítek tisíc, výsledek by mohl být jiný. V tabulce je zapsána průměrná časová náročnost pro každou implementaci která je vypočítána ze 3 naměřených hodnot.

| Dimenze matice | Počet vláken | Průměrná časová náročnost [ms] |
| ------ | ------ | ------ |
| 5000 | 1 | 65 626 |
| 5000 | 2 | 59 919 |
| 5000 | 4 | 54 932 |
| 5000 | 8 | 58 579 |
| 5000 | 10 | 60 788 |

| Dimenze matice | Počet vláken | Průměrná časová náročnost [ms] |
| ------ | ------ | ------ |
| 2000 | 1 | 4 610 |
| 2000 | 2 | 3 922 |
| 2000 | 4 | 3 655 |
| 2000 | 8 | 4 128 |
| 2000 | 10 | 4 331 |
