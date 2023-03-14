Anastasia Psarou 2860
Nikos Lymperopoulos 2812
2h erg 3h ask

To struct car_t apoteleitai apo ena thread, enan char pou einai to xroma to autokinhtou kai tous xronous anamonis tou aytokinhtou gia na ftasei stin gefira kai gia na tin diasxisei.

Arxika diabazoume apo to arxeio "input3.txt" to xroma tou kathe aftokinitou kai tous xronous kai dhmiourgoume nimata aytokinhta me ayta ta xaraktiristika. 
To kathe nima kanei sleep oso xrono diabase apo to arxeio. Autos o xronos dilwnei posi wra thelei to kathe aytokinhto na ftasei stin arxi tis gefyras xwris na mpei se aytin.

Kathe aftokinito xrisimopoiei kapoies metavlites kata tin ektelesi tou.
1) cars_in : Ta sinexomena aftokinita pou exoun mpei stin gefira apo tin pleura twn aftokinitwn pou xrisimopoioun tin gefira.
2) cars_out : Ta sinexomena aftokinita pou exoun vgei apo tin gefira apo tin pleura twn aftokinitwn pou xrisimopoioun tin gefira.
3) cars_allowed_bridge : O megistos arithmos aftokinitwn pou mporoun na vriskontai panw stin gefira tautoxrona.
4) maximum_cars_row : O megistos arithmos sinexomenwn aftokinitwn pou mporoun na perasoun apo mia plevra prin ginei anagkastiki allagi proteraiotitas stin alli.
5) blue_cars : To plithos twn mple aftokinitwn pou den exoun vgei akoma apo tin gefira.
6) red_cars : To plithos twn kokkinwn aftokinitwn pou den exoun vgei akoma apo tin gefira.

To prwto nima pou mpainei stin sinartisi bridge analoga me to xrwma tou kathorizei poia pleura tha 3ekinisei prwti. Ayto ginetai me ti bohtheia mias metavlitis, tis first pou einai arxika 1. To proto nima pou mpainei se afto to kommati kwdika kanei down ton semid tou xrwmatos pou tha paei deutero. Stin synexeia, allazei tin timi tis metavlitis first wste na min mporei allo nima na mpei se afto to kommati kwdika.
Olo auto prostateuetai apo simatoforous ws krisimo tmima, wstw na eimaste sigouroi oti den tha mpoun se auto dio nimata "taytoxrona" kai ara den tha exoume pote dio i parapanw prwtous.

Stin synexeia, to kathe nima analoga me to xrwma tou perimenei ston ekastote simatoforo. Ta kokkina perimenoun ston row_semid_red kai ta mple row_semid_blue. 

Kathe fora pou ena aftokinito mpainei stin gefira prepei na eleg3ei merikes sinthikes gia na dei an prepei i oxi na 3ipnisei ton epomeno apo to xrwma tou.
An i gefira den exei gemisei, an apo tin pleura tou aftokinitou den exoun perasei ta megista epitrepomena aftokinita kai an iparxoun alla idiou xrwmatos aftokinita akoma kai an afta den exoun ftasei akoma stin gefira, tote kane up ton simatoforo tou ekastote xrwmatos.

Stin synexeia to kathe nima "koimatai" gia oso xrono xreiazetai gia na dianysei tin gefyra.

Afou to aftokinito "dianysei" tin gefira tote vgainei kai kanei merikous elegxous, enw ananewnei kai tis times diaforwn metavlitwn opws cars_out, blue_cars h red_cars.

An  den iparxoun alla aftokinita poy prokeitai na perasoun tin gefira ( an diladi to athroisma blue_cars + red_cars == 0 ) tote 3ipnaei tin main kai termatizei.
Alliws to aftokinito elegxei an den iparxoun alla aftokinita tou xrwmatos tou pou prokeitai na perasoun kai an nai tote 3ipnaei to prwto aftokinito pou perimenei tou antithetou xrwmatos kai arxikopoiei tis metavlites car_in kai cars_out se 0.
An kamia apo tis dio parapanw sinthikes den isxyei tote to aftokinito au3anei tin metavliti cars_out kata 1 kai elegxei an i gefyra itan gemati prin vgei kai an den exei ginei ypervasi tou max arithmou synexomenwn aytokinhtwn apo tin plevra tou. Se autin tin periptosi apla vazei stin gefyra ena aftokinhto tou idiou xrwmatos. 
An omws to aftokinhto pou mpainei einai to teleutaio tis pleuras tou, me vasi ton megisto arithmo sinexomenwn aftokinhton pou mporoun na perasoun apo kathe pleura ananewnei tis metavlites cars_in kai cars_out. Ystera elegxei an iparxoun alla aftokinita apo tin antitheti plevra. An iparxoun tote kanei up ton antitheto simatoforo, alliws kanei up ton simatoforo tou xrwmatos tou.


Olo ayto to kommati kwdika meta tin e3odo enos nimatos apo tin gefira einai krisimo tmima, dioti allazoume tin timi kapoiwn metavlitwn kai parallila elegxoume synthikes me basi tis times tous. 

Meta apo to telos tou krisimou tmimatos kathe struct pou periexei to ekastote nima apeleutheronetai apo ton eafto tou.

Ston kwdika yparxoun krisima tmimata, dioti epe3ergazomaste tis times cars_in kai cars_out se diaforetika shmeia. Auta einai i eisodos kai i e3odos. Yparxei sygxronismos meta3i olwn twn aftokinitwn pou mpainoun kai meta3i olwn twn aftokinitwn pou vgainoun apo tin gefyra. Afto dioti kathe aftokinhto thelei na dei3ei sto programma oti exei mpei stin gefyra au3anontas tin metavliti cars_in kata 1 kai oti exei vgei apo tin gefyra au3anontas tin metavliti cars_out kata 1.
O allos pithanos antagwnismos pou yparxei thewritika sto programma einai oti kapoio aftokihito enw vgainei prepei na arxikopoiisei tis metavlites cars_in kai cars_out. O logos omws pou e3aleifetai autos o antagwnismos einai giati mesw synthikwn e3asfalizoume oti mono to teleutaio aftokinhto mias sygkekrimenis fashs tha ektelesei aftes tis arxikopoiiseis. (px to teleutaio aftokinhto afou mia pleura ftasei ton megisto arithmo synexomenwn aftokinhtwn h to teleutaio aftokinhto enos xrwmatos)
Ara etsi eimaste sigouroi oti i arxikopoiisi autwn twn metavlitwn tha ginei meta tin epe3ergasia tous apo ta alla aftokinhta.
