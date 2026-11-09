# Lista de exercícios 2 — COMP0512 Programação C (2026/2 T02)
#
#   make            → gera lista-de-exercicios-2.pdf
#   make clean      → remove auxiliares
#
# O logotipo da UFS vem do tema em ufs-disciplinas/theme (caminho absoluto,
# para compilar fora do repositório do site).

THEME := $(HOME)/work/ufs-disciplinas/theme
export TEXINPUTS := .:$(THEME)/:

all: lista-de-exercicios-2.pdf

%.pdf: %.tex preambulo.tex
	pdflatex -interaction=nonstopmode -halt-on-error $<
	pdflatex -interaction=nonstopmode -halt-on-error $<

clean:
	rm -f *.aux *.log *.out *.toc

distclean: clean
	rm -f lista-de-exercicios-2.pdf

.PHONY: all clean distclean
