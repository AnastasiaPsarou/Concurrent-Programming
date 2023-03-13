Nikos Lymperopoulos 2812
Anastasia Psarou 2860

work_signal: I metavliti vrisketai mesa sto struct kathe nimatos kai einai 0 oso to ekastote nima den exei douleia kai vrisketai stin anamoni. Afou i main tou anathesei douleia tote i idia allazei tin timi tis metavlitis tou ekastote nimatos se 1, simainontas sto nima oti tou exei anatethei enas arithmos kai oti prepei na 3ipnisei. Stin periptwsi pou se kapoio nima den anatethei pote kapoio noumero apo tin main den dimiourgeitai problima, dioti tha meinei kollimeno mesa stin energi anamoni mexri i main na pei se ola ta nimata na termatisoun mesw tou terminate_signal.


main:
    Arxika anoigetai to arxeio "input.txt" kai oi arithmoi pou vriskontai se auto apothikeuontai se enan dinamika desmeumeno pinaka, ton array.
    Sti sinexeia dimiourgeitai o pinakas_thread opou kathe keli einai typou thread_T kai periexei ena thread kai kapoia simata ta opoia arxikopoiountai.
    Dimiourgountai tosa nimata osa dinei o xristis.
    Oso den exoun elegxtei oloi oi arithmoi tou array i main synexizei na dinei douleies sta diathesima nimata.
    Afou i main vrei ena nima pou einai diathesimo tou dinei enan arithmo na tsekarei an einai prime kai tou allazei to work_signal tou se 1, wste na 3ekinisei tin douleia.
    Oso den yparxei diathesimo nima i main kanei energi anamoni me pthread_yield.
    Afou i main anathesei kai ton teleftaio arithmo tou pinaka array se ena nima tote metatrepei tin global metavliti terminate_signal se 1, to opoio koitane ola ta nimata gia na doun an i main exei simanei termatismo olwn twn nimatwn.
    Otan ena nima perimenei na tou anatethei i epomeni douleia prin kanei pthread_yield panta elegxei tin timi aftou tou simatos tou. An afto einai 1 simainei oti ola ta nimata exoun parei entoli apo tin main na pethanoun kai termatizoun. Afto epitrepei sta nimata pou akomi ergazontai otan i main steilei afto to sima na teleiwsoun prwta tin douleia tous kai otan mpoun stin anamoni na doun tin timi tou simatos kai tote na termatisoun.  
    H main perimenei mexri ola ta nimata na termatisoun. Meta kanei free ton pinaka ton arithmwn input kai ton pinaka twn threads pinakas_thread kai teleionei.
   
prime_function:
    Otan se ena nima dothei douleia 3ipnaei, vgainontas apo tin while loop.
    To percentage kathe stoxeiou tou pinakas_thread periexei to poso twn arithmwn pou exei epe3ergastei to antistoixo thread.
    Parallila, ginetai kai elegxos an o arithmos pou exei dothei sto nima gia elegxo (given_num) einai prime i oxi.
    Telos, to work_signal tou ginetai 0, pou simainei oti leei stin main oti teleiose ti douleia tou kai tha 3anampei se anamoni.
   
check_availability:
    3ekinaei i main apo to prwto thread kai psaxnei mexri na vrei ena diathesimo thread, diladi ena thread opou isxyei pinakas_thread[i].work_signal == 0. Afto leitourgei giati sto programma to work_signal enos thread einai 1 mono otan tou exei anatethei arithmos, alliws an perimenei einai 0.
    
check_all_available:
    Elegxei an ola ta nimata exoun teleiosei tin douleia tous. Diladi an oloi exoun work_signal = 0.
    
isPrime:
    Elegxei an enas arithmos einai prwtos.

find_thread_index:
    Kathe thread pou kalei afti tin sinartisi vriskei mesw tou apotelesmatos pou epistrefei poio stoixeio tou pinakas_thread einai to idio. Etsi an thelei na dei an tou exei anatethei douleia kai i timi pou epistrafike einai thread_index tote apla leei pinakas_thread[thread_index].work_signal.
    
Ta kirio provlima tis askisis einai o sigxronismos meta3i main kai nimatwn. Kathws i leitourgia anathesis kai genika i epe3ergasia twn arithmwn ginetai meta3i main kai enos nimatos den iparxoun themata sigxronismou meta3i nimatwn. Gia na sigxronistei i main kanei xrisi tis sinartisis check_availability poy anaferame pio panw. Efoson iparxei kapoio diathesimo nima tote apla tou anathetei ton epomeno arithmo kai allazei tin metavliti work_signal aftou tou nimatos se 1 gia na tou dei3ei oti prepei na 3ipnisei kai na doulepsei. Ean i main den vrei kapoio diathesimo nima kathws den xreiazetai na xrisimopoiei ton CPU mexri na teleiwsei, tote apla kanei pthread_yield(). Omoiws, ta nimata efoson doun oti den tous exei anatethei kapoia douleia, apla kanoun pthread_yield mesa stin energi anamoni tous.
    
