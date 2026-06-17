/*
--FSCANF--
"%d/s/c/ld/f/lf/" -- int, string, char, long, float, double
"%99x" -- beri max 99 znakov + \0
"[...]" -- scanset -> beri dokler/kadar
"[abc]" -- beri SAMO zanke a, b in c
"[a-zA-z]" -- SAMO črke
"[^,]" -- vse RAZEN vejice --> '^' pomeni RAZEN
"[^\n]" -- vse RAZEN '\n'
"[^,\"]" -- vse RAZEN vejice in ' " '(narekovanja)
" " -- preskoci whitespace --> \n \t presledke
"%*d" -- preberi int ampak ga ZAVRZI (* pomeni zavrzi)
"%*[^,\n ]" -- pozri vse vejice, presledke in newline
" \"%99[^,\"]\"" -- preberi 99 znakov BREZ vejice, presledkov in narekovajev --> .."REKA",.. --> se shrani v pointerju kot REKA
" \"%99[^,\"]\" %*[,]" --> --||-- prebere in zavre se vejico na koncu 

fscanf vrne stevilo uspeno prebranih elementov/argumentov in ne znakov ali EOF ce je konec datoteke

--FREAD-- |--> BINARNE datotke
fread(pointer, velikost_elementa(sizeof(itd.) v bajtih), stevilo_elementov, datoteka)
fread vrne stevilo prebranih elementov k mora biti <= stevilo_elementov, ce je manj od 1 potem je ALI napaka ALI konec datoteke

--FSEEK-- |--> PREMIKANJE PO DATOTEKI
fseek(datoteka, OFFSET, argument) |--> argumenti: SEEK_SET -> na zacetek + OFFSET, SEEK_END -> na konec + OFFSET, 
SEEK_CUR -> trenuntna poz + OFFSET

ftell(datoteka) |--> vrne trenutno pozicijo v bajtih

--FGETS-- |--> prebere string z vkljucno z whitespaci iz datoteke
fgets(char* buff, int max_znakov, datoteka);
    -- prebere tudi \n na koncu vrstice to lahko odstranis z "line[strcspn(line, '\n')] == '\0'"
    -- strcspn(char* arr, char iskan) vrne prvi index kjer se prikaže iskan char v stringu
*/