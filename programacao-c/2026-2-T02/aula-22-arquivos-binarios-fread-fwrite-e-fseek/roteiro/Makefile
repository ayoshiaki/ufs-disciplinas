TEMA ?= ../../../../theme

roteiro.pdf: roteiro.tex referencias.bib codigo/*.c codigo/aluno.h saidas/*.txt
	TEXINPUTS=$(TEMA)//: latexmk -pdf -interaction=nonstopmode roteiro.tex

limpa:
	latexmk -C roteiro.tex

.PHONY: limpa
