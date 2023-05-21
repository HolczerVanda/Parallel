# Parallel

## Beadandó feladat:

### Az összefésülő rendezés implementálása rekurzív módon.

#### Implementációk:

1. A szálak száma, a rekurzív hívási mélység, valamint a tömb mérete parancssori argumentumként szabható meg
2. Szekvenciális rekurzív változat
3. Párhuzamosítás a 'pthread' függvénykönyvtár használatával
4. Párhuzamosítás az 'OpenMP' API-val, sectionok használatával
5. Párhuzamosítás C#-ban a 'Parallel' osztály használatával

#### Mérések:

1. Futási idők összehasonlítása ugyanazon, illetve véletlenszerűen generált tömb bemenetekre
2. Futási idők összehasonlítása a rekurzív mélység változtatásának függvényében, szekvenciális és párhuzamos esetben
3. Adott tömbméret esetén az átlagos és a maximális futási idők összehasonlítása, szekvenciális és párhuzamos esetben
4. A kapott eredmények összesítése Excel táblázatban
