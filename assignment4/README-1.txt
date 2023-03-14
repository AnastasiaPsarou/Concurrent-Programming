Anastasia Psarou 2860
Nikos Lymperopoulos 2812
2h erg 1h ask

mysem_create: dimiourgei kathe fora enan simatoforo, afou to pedio nsems tis semget to orizoume ws 1, kai orizei tin timi tou se initial_value, i opoia metavliti einai orisma tis synartisis. H arxikopoisi ginetai me ti bohteia tis synartisis semctl. Ta pedia tou struct sembuf op arxikopoiountai. Sto sem_num dinoume tin timi 0 efoson kathe omada simatoforwn periexei enan mono shmatoforo. To sem_flag arxikopoieitai me SEM_UNDO, giati theloume na ginei anairesi tis pra3is otan termatistei i diergasia. 

mysem_down: dinei sto sem_op tin timi -1 kai meta kalei tin synartisi semop mesw tis opoias kanei tin timi tou simatoforou isi me 0 an itan 1 alliws an i timi tou simatoforou itan 0 to nima mplokarei mexri i timi tou simatoforou na ginei 1. Auto symbainei giati an |sem_op| > semval i synartisi semop mplokarei kai 3emplokarei otan ginei |sem_op| <= semval.

mysem_up: an i timi tou shmatoforou einai idi 1 tote exoume xameni klisi tis up kai i synartisi epistrefei 0. An oxi, diladi i timi tou simatoforou einai 0 tote tin au3anoume se 1 kai epistrefei 1.

mysem_destroy: h synartisi ayti katastrafei enan sinatoforo. Auto epitigxanetai me ti bohtheia tis synartisis semctl kai ti xrisi tou simatos IPC_RMID.

Kaname mia dokimi aytis tis bibliothikis me ti bohtheia tou parakatw programmatos.

H main paragei 2 simatoforous(oi opoioi arxikopoiountai me 0) kai 2 nimata kai orizei tin timi mias global int metavlitis tis number se 0. To proto nima paei stin synartisi foo1 opou kai kanei tin timi tis metablitis number = 5 kai meta = 10 kai ektiponei tin kathe timi. Otan teleiosei auto to nima kanei up ton shmatoforo opou mplokarei to deutero nima molis paei stin synartisi foo2. Stin synexeia h foo2 kanei tin timi tis metavlitis number = 15 to ektyponei kai meta = 20 kai to ektiponei. 

H main afou dimiourgisei auta ta nimata kanei mia sem_down ston idi 0 arxikopoiimeno shmatoforo semid_main. Opote i main mplokarei kai perimenei tin foo2 na ftasei sto telos tis kai na kanei mysem_up wste na 3emplokarei. 

Sto telos tou programmatos diagrafontai i simatoforoi.
