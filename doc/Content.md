<!-- ABSTACT

From IEEE:

A conference article or paper should have the following elements:
 Metadata: title, keywords, abstract, professional affiliation(s), and cited references in
    the bibliography must be included, and written in the English Language.

 Abstract: a brief and objective summary that previews the rest of the paper it describes.
    It should be succinct yet provide enough information about the paper to facilitate a
    decision on whether the entire paper could be read with profit.

 Introduction: an introductory statement of the purpose of the paper, usually describing
    the hypothesis that will be tested and a summary of related previous work by others.

 Methods: the methods that are used to test the hypothesis should be given in sufficient
    detail that another researcher in the field could duplicate the testing.

 Results: the hypothesis should be tested and data representing the results of the testing
    presented.

 Conclusion: the data should be discussed and the results interpreted, and conclusions 
    given.

 # Introduction
 whats does others do, open questions, we are interested in..,
 we want to answer or focused on ... (Motivation)
 what is the problem?
 
 # Related Work
 intro about solutions and our special new solution/idea.
 iter through related work with focus on different solutions. Why are some aspects open?

 # Methodology
 
 # Results
 ## Definitions and Taxonomy
 ## Aspect 1
 ## Aspect 2
 ## Aspect 3

 # Discussion
 intro, offer explanation and reference to literature
 
 ## Conclusion
 ## Future Work
 new open questions? how can we find answers in the future?
 We can we use our solution in the future?

 # Acknowledgement
 !!! conference papers do not normally have an appendix !!!
 # Bibliography
-->

# Introduction

Primitive Algorithmen wie den Ant-Algorithmus sind bereits seit vielen Jahren
bekannt. Dieser nutzt einen Duftstoff, der in einer Region von jedem Teilnehmer
freigesetzt wird, um eine Art kollektiven Speicher zu verwirklichen. Ziel
ist es auf diese Art Spuren für andere Teilnehmer zu hinterlassen, welche
zu Futterquellen führen. Dieses Futter soll dann ins Nest getragen werden.
Je mehr Ameisen auf einer gelegten Spur laufen, desto stärker wird diese
Spur. Theoretische Modelle zeigen, dass sich dadurch sogar kürzere Wege
zurück ins Nest durchsetzen, da diese Wege von den Ameisen, die ihn gefunden
haben, häufiger frequentiert wird - die Duftspur wird so verstärkt.
In der Literatur finden sich viele Variationen und theoretische Modelle,
wie ein solcher Algorithmus, durch die Natur motiviert, nachgebildet werden
kann. Z.B. sind lokale Algorithmen (verteilte Algorithmen mit linearer Laufzeit,
die nicht von der Größe des Netzes abhängig sind), einem Schwarm-Algorithmus
wie dem Ant-Algorithmus sehr ähnlich, betrachten aber keine kontinuierliche
Veränderung der Daten Aufgrund von Bewegungen. Schaut man sich
in der Literatur die Ant-Algorithmen im Detail an, so wird der Erfolg
einer Ameisen-Kolonie bei gewählten Parametern, die das Legen der
Duftspuren und deren "Verwitterung" beeinflussen, kaum behandelt. Ebenso gibt
es beim Ant-Algorithmus einen Aspekt, der bei der ältesten Art, den Wanderameisen,
besondere Aufmerksamkeit verdient: "Ameisenmülen". In diesem Fall laufen
alle Ameisen im Kreis und sterben an Erschöpfung, da sie so keine weiteren
Futerquellen finden. Ein weiterer Punkt, der einen Erfolg eines zu primitiven
Ant-Algorithmus in Frage stellt, sind Ameisen-Straßen, die zu versiegten
Futterquellen führen. Wir konnten in unseren Simulationen beide "Fehlentwicklungen"
beobachten.

Man kann den Ant-Algorithmus durch Hinzunahme von GPS, Funktechnik und
einem großen Arbeitsspeicher zur modifizieren, um ein solches Fehlverhalten
zu erkennen oder zu verhindern, aber diese Modifikationen setzen
folgendes voraus:

- elektrische Energie
- Rechenleistung
- mindestens die Größe des Chips 
- bedenkenlose Anwendung von Funkwellen
- Speichermedium

Raketensteuerungen von Atombomben werden oft von pneumatischen (Staubsaugermotoren und Klappen
wie bei Zuse II) oder hydraulischen Systemen betrieben, damit sie bei einem
elektromagnitischen Impuls einer anderen Bombe noch weiter funktionieren.
In der Atmospähre eines anderen Planeten könnte eine Elektronik z.B. wegen der
starken statischen Ladung des Marsstaubs ähnliche Probleme verursachen.
Unter Wasser oder in einem sandigem Medium können GPS und Funkwellen kaum
bis gar nicht genutzt werden. Schaut man sich aktuelle Nanotechnologien
an, so werden chemische Botenstoffe zur Auslösung bestimmter Reaktionen,
interessanter, als mit Funktechnik Roboter in unserer Blutbahn kommunizieren
zu lassen. In der Natur werden bereits Hormone (und keine Funkwellen) als
Kommunikation eingesetzt. Sollte man chemische Propeller an Makromolekülen bilden oder
betreiben, die durch eine chemische Reaktion aufgrund einer bestimmten
Konzentration eines künstlichen Hormons an der Stelle des Moleküls, an dem
der Propeller sitzt, so sind logische Operationen oder gar Speichermedien
in einem Molekül begrenzt. Durch künstliche Methabolismen
eine turingvollständige Sprache bilden, die als Eingabe Konzentrationen
von bestimmten Molekülen akzeptiert und gleiches als Ausgabemedium zur
Steuerung einer molekularen Struktur erzeugt, mag heute noch nach Science
Fiction klingen - findet aber bereits in Laboren statt. (todo: hier fehlt
mir noch eine Referenz)







# Notes

We added a simple traffic jam control to each unit and measured a better food supply.


This demo file is
intended[@Tentschert2000] to serve as demo. I wish you the best[@li2014chaos] of success.
test test[@gonzalez2017smells] ...

Building robots in hardware to test a swarm algorithm is possible, but
expensive [hardware](https://en.wikipedia.org/wiki/Swarm_robotic_platforms)

A hardware specific simulation of a single device exists, too:
[BLE Ant client sim](https://infocenter.nordicsemi.com/index.jsp?topic=%2Fcom.nordic.infocenter.sdk52.v0.9.0%2Fant_examples_ant_fs.html)

Using VM with router/device firmware and a network layout should be
interessting: [Network sim](https://www.gns3.com/community)

## Ant algorithm

1.  clever

## Bee algorithm

1.  Ein kleiner teil der Bienen (Scouts) sucht global nach "gärten"
2.  Da Gärten, wo es viel "Futter" gibt ein großes Areal sind, kommen viele Scouts
    zum dance-floor zurück mit ähnlichen Koordinaten
3.  normale Bienen folgen nun den Scouts und verbreiten sich im Areal (Nahsuche)
4.  ein Teil fliegt als Scout weiter und sucht neue Gärten
5.  durch die Nahsuche werden schlechte Regionen von den Bienen ausgeschlossen
    und bessere Regionen "gespeichert"
6.  Biene, die bessere Region fand, wird neuer Scout und fliegt zum dance floor
7.  Biene, die in der Region keine Verbesserung nach einer Weile fand, sucht neue Gärten

<!--

\hfill J. Peters
\hfill \today

-->

# Related Work
intro about solutions and our special new solution/idea.
iter through related work with focus on different solutions. Why are some aspects open?

# Methods
Describe technique, structure and data collection of our solution.

# Results
intro about selected data, getting them and how we analyse them

## Definitions and Taxonomy

Parameters

- different food area size
- different distance between food area and home
- different count of food areas
- different direction random size
- different prefer pattern for dusty tiles
- different amount, how strong the way decisions effects on setting the new dust
- better to add or multiply dust on a tile
- loosing dust on tiles rate
- different hunger limits (?)
- different random seeds (?)

Effects

- development of collected food (%) in 1000 iterations
- used dust (sum) over 1000 iterations
- how many died (how long did they life)
- development of random-, jam- and dust-decisions (%) in a simulation
- distance after last 10 steps before dying (ant traps?)

## Aspect 1
Subsection text here.

## Aspect 2
Subsection text here.

## Discussion
intro, offer explanation and reference to literature


# Conclusion

...

**Future Work**: new open questions? how can we find answers in the future?
How can we use our solutions in the future?
