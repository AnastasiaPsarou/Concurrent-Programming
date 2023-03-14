Nikos Lymperopoulos 2812
Anastasia Psarou 2860

work_signal: I metavliti vrisketai mesa sto struct kathe nimatos kai einai 0 oso to ekastote nima den exei douleia kai vrisketai stin anamoni. Afou i main tou anathesei douleia tote i idia allazei tin timi tis metavlitis tou ekastote nimatos se 1, simainontas sto nima oti tou exei anatethei enas arithmos kai to 3ipnaei. Ystera i main paei sto epomeno nima. Stin periptwsi pou se kapoio nima den anatethei pote kapoio noumero apo tin main den dimiourgeitai problima. Afto simvainei dioti to nima tha koimatai stin arxiki mysem_down pou kanei ston simatoforo tou mexri i main na pei se ola ta nimata na termatisoun mesw tou terminate_signal kai na ta 3ipnisei.


main:
    Arxika anoigetai to arxeio "input.txt" kai oi arithmoi pou vriskontai se auto apothikeuontai se enan dinamika desmeumeno pinaka, ton array.
    Sti sinexeia dimiourgeitai o pinakas_thread opou kathe keli einai typou thread_T kai periexei ena thread kai kapoia simata ta opoia arxikopoiountai.
    Dimiourgountai tosa nimata osa dinei o xristis.
    Oso den exoun elegxtei oloi oi arithmoi tou array i main synexizei na dinei douleies sta diathesima nimata.
    Afou i main vrei ena nima pou einai diathesimo tou dinei enan arithmo na tsekarei an einai prime, tou allazei to work_signal tou se 1 kai to 3ipnaei mesw tis mysem_up wste na 3ekinisei tin douleia.
    An to nima sto opoio i main prospathei na dwsei douleia den einai diathesimo, tote paei sto amesws epomeno. An kai afto den einai diathesimo paei sto diko tou epomeno mexris wtou na vrei ena diathesimo nima. An i main eleg3ei ola ta nimata, diladi an ftasei sto nima apo to opoio 3ekinise, kai kanena den einai diathesimo tote mplokarei mesw tou simatoforou tis main_semid, mexri na tin 3ipnisei ena nima afou ginei diathesimo.
    
    Afou i main anathesei kai ton teleftaio arithmo tou pinaka array se ena nima tote metatrepei tin global metavliti terminate_signal se 1, to opoio koitane ola ta nimata gia na doun an i main exei simanei termatismo olwn twn nimatwn. Episis i main kanei mysem_up se olous tous simatoforous nimatwn etsi wste osa exoun idi mplokarei epeidi den exoun douleia na termatisoun amesws kai opoia nimata douleuoyn na termatisoun amesws afou teleiwsoun tin douleia tous. Gia afto kai stin sinthiki tou kwdika termatismou elegxoume tin timi tis metavlitis work_signal tou nimatos, giati mporei i main na tou exei anathesei enan arithmo kai meta tautoxrona na exei pei sta elefthera nimata na termatisoun, prin afto prolavei na teleiwsei tin douleia tou.
     
    H main perimenei mexri ola ta nimata na termatisoun. Kathe nima xrisimopoiei tin metavliti total_threads tin opoia ston kwdika termatismou meiwnei kata 1. Otan i timi tis ftasei sto 0 tote to ekastote nima 3erei oti einai to teleftaio kai oti mporei na 3ipnisei tin main. Afou kathe nima thelei na epe3ergastei kai na eleg3ei tin timi tis metavlitis total_threads, tote ekei exoume krisimo tmima kai gia afto xrisimopoioume ton simatoforo mtx2 gia na egguithoume apokleismo. Etsi mono 1 nima tha 3ipnisei tin main, to teleftaio. Ara den iparxei periptwsi ena nima na leitourgei enw i main termatizei.
    Afou i main 3ipnisei kanei free ton pinaka ton arithmwn input kai ton pinaka twn threads pinakas_thread.
    Episis katastrefei olous tous simatoforous tou programmatos kai termatizei.

prime_function:
    Otan thelei na dei an exei douleia kanei mysem_down ston ekastote simatoforo. An mplokarei tote i main den tou exei anathesei kamia douleia kai perimenei ekei mexri i main na ton 3ipnisei.
    To percentage kathe stoxeiou tou pinakas_thread periexei to poso twn arithmwn pou exei epe3ergastei to antistoixo thread.
    Parallila, ginetai kai elegxos an o arithmos pou exei dothei sto nima gia elegxo (given_num) einai prime i oxi.
    Meta mesa se ena kommati kwdika sto opoio egguatai apokleismos logw tis xrisis tou simatoforou mtx kathe nima afou teleiwsei tin douleia tou elegxei an i main exei mplokarei kai an nai tote kalei tin mysem_up gia ton main_semid. 
    Telos, to work_signal tou ginetai 0, pou simainei oti leei stin main oti teleiose ti douleia tou kai einai diathesimo.
   
check_availability:
    I main xrisimopoiei tin metavliti check kai mesa apo aftin elegxei kathe fora ta nimata ena ena mexri na vrei ena diathesimo kai na tou anathesei ena noumero. Arxika i check exei timi 0, alla apo ekei kai pera kathe fora pou i main anathetei sto nima pinakas_thread[check] enan arithmo tote tin au3anei kata 1. 
    An to nima sto opoio i main thelei na dwsei douleia den einai diathesimo tote paei sto epomeno mexris wtou na vrei ena diathesimo i na epistrepsei se afto apo to opoio 3ekinise. O elegxos diathesimotitas ginetai mesw tis metavlitis work_signal kathe nimatos. Afou gia kathe nima an work_signal == 0 tote den exoun douleia ara einai diathesima. Ara i main den xreiazetai na skeftetai poio nima einai diathesimo kathws i sinartisi check_availability exei alla3ei tin global metavliti sti thesi enos diathesimou thread kai exei epistrepsei 1, h exei epistrepsei 0 an ftasei sto nima apo to opoio 3ekinise kai ara i main apla mplokarei.
    
check_plus:
    Proxwraei tin metavliti check kathe fora kata 1 kai an i metavliti exei ftasei sto telous tou pinakas_thread tote tin 3anavazei stin arxi me timi 0.
    
isPrime:
    Elegxei an enas arithmos einai prwtos.

find_thread_index:
    Kathe thread pou kalei afti tin sinartisi vriskei mesw tou apotelesmatos pou epistrefei poio stoixeio tou pinakas_thread einai to idio. Etsi an thelei na dei an tou exei anatethei douleia kai i timi pou epistrafike einai thread_index tote apla leei pinakas_thread[thread_index].work_signal.
    
Ta kirio provlima tis askisis einai o sigxronismos meta3i main kai nimatwn. Kathws i leitourgia anathesis kai genika i epe3ergasia twn arithmwn ginetai meta3i main kai enos nimatos den iparxoun themata sigxronismou meta3i nimatwn. Gia na sigxronistei i main kanei xrisi tis sinartisis check_availability poy anaferame pio panw. Efoson iparxei kapoio diathesimo nima tote apla tou anathetei ton epomeno arithmo, allazei tin metavliti work_signal aftou tou nimatos se 1 gia na 3erei i idia meta oti to nima afto doulevei kai na min tou 3anadwsei kapoion arithmo kai to 3ipnaei mesw tou simatoforou tou. Ean i main den vrei kapoio diathesimo nima mplokarei kai to prwto nima pou tha teleiwsei tin douleia tou afou mplokarei tha dei oti i main koimatai ara tha tin 3ipnisei.
Stin seira 1 ergasiwn i metavliti work_signal xrisimeve kai stin main alla kai sta nimata. Pleon i metavliti afti endiaferei mono tin main afou ta nimata eite exoun mplokarei logw tou simatoforou tous eite epe3ergazontai ena noumero.
    
