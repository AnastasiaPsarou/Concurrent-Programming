Nikos Lymperopoulos 2812
Anastasia Psarou 2860

To programma apoteleitai apo dio tipous nimatwn. To trenaki kai tous epivates.
Iparxoun 4 simatoforoi pou xrisimopoiountai gia na epitefxthei sigxronismos.
1) train_sem : aftos o simatoforos xrisimopoieitai apo to trenaki opote thelei na mplokarei. Diladi otan thelei na perimenei na epivivastoun oloi oi epivates i otan thelei na perimenei gia na apovivastoun.
2) line_sem  : aftos o simatoforos xrisimopoieitai apo ta atoma/nimata pou theloun na epivivastoun sto treno kai prepei na perimenoun se mia oura mexri na erthei i seira tous.
3) ride_sem  : aftos o simatoforos paizei ton rolo tis koursas. Oso oi epivates vriskontai mesa sto trenaki tote mexri afto na teleiwsei tin volta oloi tous mplokaroun mesw aftou tou simatoforou
4) main_sem  : aftos o simatoforos xrisimopoieitai apo tin main gia na mplokarei mexris wtou na teleiwsei to trenaki kai na exoun kanei oloi tin volta.

Episis ginetai xrisi kai merikwn global metavlitwn pou epitrepoun tin ulopoiisi diaforwn leitourgeiwn.
1) train_passengers : Plithos epivatwn pou vriskontai kapoia sigkekrimeni xroniki stigmi sto trenaki
2) past_passengers  : Plithos epivatwn pou exoun mpei sto trenaki
3) total_passengers : Sinolikoi epivates pou theloun na mpoun sto trenaki
4) max_passengers   : Max epivates pou xwrane sto trenaki

Arxika i main mpainei mesa sto arxeio input kai metraei tous arithmous poy iparxoun. Gia kathe noumero au3anei kata ena tin metabliti total_passengers. Otan teleiwsei afti i diadikasia i main kanei malloc ena pinaka opou ekei mesa tha vriskontai ta nimata alla kai oi xronoi anamonis tous. Kathe stoixeiou tou pinaka einai tipou struct pinakas kai periexei ena thread kai enan akeraio me onoma wait_time. Ara kathe stoixeio exei ton diko tou xrono anamonis.

Afou ginei i malloc tote i main arxikopoiei tous simatoforous kai istera pernaei ston pinaka olous tous xronous anamonis sto ekastote stoixeio. Dimiourgei to nima gia to trenaki kai istera dimiourgei ola ta nimata epivatwn. Se kathe epivati pernaei ws orisma tis sinartisis tou ton xrono anamonis tou. Afou ginei afto i main mplokarei ston simatoforo tis mexris wtou to trenaki na tin 3ipnisei kai telos katastrefei olous tous simatoforous kai apeleftherwnei ton dinamika desmevmeno pinaka.

train_function : Afti einai i sinartisi pou trexei to nima trenaki. Oles oi voltes ektelountai mesa se mia terastia while(1). Kathe fora to trenaki 3ekinaei kai afou paei stin arxi elegxei an ola ta atoma pou ithelan na epivivastoun epivivastikan. An afto isxyei tote apla xreiazetai na 3ipnisei tin main kai meta termatizei.
An iparxoun akoma atoma pou theloun na epivivastoun sto trenaki tote 3ipnaei ton prwto stin oura anamonis kai meta mplokarei mexris wtou o teleftaios pou tha epivivastei sto trenaki na to 3ipnisei. Ystera kanei kapoies ektipwseis simainontas tin volta kai afou teleiwsei 3ipnaei ton prwto pou vrisketai mesa sto trenaki kai mplokarei pali. Me tin idia logikh o teleftaios pou tha apovivastei apo to trenaki to 3ipnaei. Afou 3ipnisei simainei oti i volta exei teleiwsei kai 3anaepistrefei stin arxi gia na dei an iparxoun kai alla atoma pou perimenoun na epivivastoun i an prepei na termatisei.

line_function : Afti einai i sinartisi pou ektelei kathe nima epivatis. Kathe epivatis exei parei san orisma stin sinartisi tou ton xrono gia ton opoio prepei na perimenei prin paei stin oura gia na perimenei tin seira tou. Afou perimenei gia to dosmeno xroniko diastima tote paei kai perimenei stin oura. Afou 3ipnisei au3anei kata 1 tis metavlites train_passengers kai past_passengers kai istera kanei enan elegxo. An einai o teleftaios epivatis pou xwraei na mpei sto trenaki i an einai to teleftaio atomo pou thelei na mpei sto trenaki, diladi den iparxoun alla atoma stin oura, tote prepei na to 3ipnisei. Alliws prepei na 3ipnisei ton epomeno stin oura. Asxeta apo to poion 3ipnaei, afou to kanei to idio to nima paei kai mplokarei mesw tou simatoforou ride_sem, san na exei mpei mesa sto trenaki kai na perimenei na 3ekinisei i volta. Opws eipame afou teleiwsei i volta to trenaki 3ipnaei ton prwto epivati. Ara aftos me tin seira tou afou 3ipnisei kanei dio pragmata. Prwton meiwnei tin metavliti train_passengers kata 1. Defteron elegxei an einai to teleftaio atomo pou apovivazetai apo to trenaki, an diladi train_passengers == 0. An den einai o teleftaios tote 3ipnaei ton epomeno epivati pou einai mesa sto trenaki kai termatizei. An einai o teleftaios tote 3ipnaei to trenaki kai termatizei.

O logos pou mesa sto programma mas xrisimopoioume mono 4 simatoforous einai giati etsi opws einai grammeno den iparxei antagwnismos. O kathenas xeirizetai tis metavlites se sigkekrimenes stigmes pou gnwrizoume oti einai o monos pou to kanei afto, ara den xreiazetai kai na iparxei kapoios amivaios apokleismos.
Px stin arxi i main allazei tin timi toy total_passengers prin kan dimiourgisei ta nimata.
To trenaki elegxei tin timi twn metavlitwn past_passengers kai total_passengers otan vrisketai stin arxi tis koursas opou ola ta ipoloipa nimata eite einai mplokarismena eite exoun pethanei.
Episis kathe atomo kanei opoiadipote allagi stis metavlites prin 3ipnisei ton epomeno, etsi wste na einai sigouros oti den tha iparxei antagwnismos.

Enas allos tropos pou apofevgetai o antagwnismos einai oti ola ta nimata vriskontai sto idio simeio tis sinartisis line_function taftoxrona. Eite ola ta nimata vriskontai sto kommati tis epivivasis opou au3anoun tis metavlites train_passengers kai past_passengers, eite ola vriskontai sto kommati tis apovivasis opou meiwnoun tin metavliti train_passengers. Ara den xreiazetai na anisixoume gia sigxronismo meta3i tou prwtou kommatiou tis line_function kai tou defterou giati pote den tha iparxei antagwnismos meta3i tous.
