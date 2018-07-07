OUTFILE = lightweight_ant_algorithm_with_ant_mill_protection

all:
#	sed -E "s/\[\@([^ ]+)\]/~\\cite\{\1\}/g" Content.md > _cites.md
	pandoc Readme.md -o meta/content.tex \
#		--biblio=meta/_bibi.bib \
#		--filter=pandoc-citeproc
	sed -i -E "s/\{\[\}\@([^ ]+)\{\]\}/~\\\\cite\{\1\}/g" meta/content.tex
	latex -shell-escape _template.tex
	bibtex _template
	latex -shell-escape _template.tex
	latex -shell-escape _template.tex
	dvips _template
	ps2pdf _template.ps $(OUTFILE).pdf

tex:
	latex -shell-escape _template.tex
	bibtex _template
	latex -shell-escape _template.tex
	latex -shell-escape _template.tex
	dvips _template
	ps2pdf _template.ps $(OUTFILE).pdf

clean:
	rm -rf _cites.md
	rm -rf meta/content.tex
	rm -rf *.aux
	rm -rf *.bbl
	rm -rf *.blg
	rm -rf *.log
	rm -rf *.nav
	rm -rf *.toc
	rm -rf *.snm
	rm -rf *.pyg
	rm -rf *.out
	rm -rf *.vrb
	rm -rf *.ps
	rm -rf *.dvi

