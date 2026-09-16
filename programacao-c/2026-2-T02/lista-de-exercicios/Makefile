# Lista de exercícios — COMP0512 Programação C (2026/2 T02)
#
#   make            → gera lista-de-exercicios.pdf
#   make clean      → remove auxiliares
#
# O logotipo da UFS vem do submódulo theme/ na raiz do repositório,
# via TEXINPUTS (mesma convenção do Makefile dos slides).

THEME := ../../../theme
export TEXINPUTS := .:$(THEME)/:

all: lista-de-exercicios.pdf

%.pdf: %.tex preambulo.tex
	pdflatex -interaction=nonstopmode -halt-on-error $<
	pdflatex -interaction=nonstopmode -halt-on-error $<

clean:
	rm -f *.aux *.log *.out *.toc

distclean: clean
	rm -f lista-de-exercicios.pdf

.PHONY: all clean distclean
