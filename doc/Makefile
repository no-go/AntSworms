OUTFILE = simulate_bug_algorithm

all:
	pandoc Content.md -o meta/content.tex
	latex -shell-escape _template.tex
	dvips _template
	ps2pdf _template.ps $(OUTFILE).pdf

clean:
	rm -rf meta/content.tex
	rm -rf *.aux
	rm -rf *.log
	rm -rf *.nav
	rm -rf *.toc
	rm -rf *.snm
	rm -rf *.pyg
	rm -rf *.out
	rm -rf *.vrb
	rm -rf *.ps
	rm -rf *.dvi

