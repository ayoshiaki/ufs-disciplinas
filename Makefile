# ============================================================
#  Makefile — Compilação dos slides UFS Beamer
#
#  Uso:
#    make                  → compila todos os slides.tex
#    make AULA=algoritmos/2025-1-A/aula-01-introducao
#                          → compila apenas uma aula
#    make clean            → remove arquivos auxiliares
#    make clean-all        → remove auxiliares + PDFs
# ============================================================

# Raiz do repositório (onde está este Makefile)
ROOT := $(shell pwd)

# Pasta do tema UFS (git submodule)
THEME := $(ROOT)/theme

# TEXINPUTS aponta para o tema + pasta atual
export TEXINPUTS := .:$(THEME)/:

# Encontra todos os slides.tex no repositório
TEX_FILES := $(shell find . -name "slides.tex" \
               -not -path "./theme/*" \
               -not -path "./TEMPLATE-aula/*" \
               -not -path "./.git/*")

PDF_FILES := $(TEX_FILES:.tex=.pdf)

# ────────────────────────────────────────────────────────────
.PHONY: all clean clean-all help

## Compila todos os slides do repositório
all: $(PDF_FILES)

## Compila uma aula específica: make aula AULA=disciplina/turma/pasta
aula:
	@if [ -z "$(AULA)" ]; then \
	  echo "Uso: make aula AULA=algoritmos/2025-1-A/aula-01-introducao"; \
	  exit 1; \
	fi
	$(MAKE) $(AULA)/slides.pdf

# Regra genérica: compila qualquer slides.tex → slides.pdf
%.pdf: %.tex
	@echo "──────────────────────────────────────"
	@echo "Compilando: $<"
	@echo "──────────────────────────────────────"
	@dir=$$(dirname $<); \
	cd $$dir && \
	export TEXINPUTS=".:$(THEME)/:" && \
	export BIBINPUTS=".:$(THEME)/:" && \
	pdflatex -interaction=nonstopmode -halt-on-error slides.tex && \
	if grep -q '\\bibdata' slides.aux 2>/dev/null; then \
	  bibtex slides && \
	  pdflatex -interaction=nonstopmode -halt-on-error slides.tex; \
	fi && \
	pdflatex -interaction=nonstopmode slides.tex
	@echo "✔ $@ gerado com sucesso."

## Remove arquivos auxiliares LaTeX (mantém PDFs)
clean:
	find . \( -name "*.aux" -o -name "*.log" -o -name "*.nav" \
	          -o -name "*.out" -o -name "*.snm" -o -name "*.toc" \
	          -o -name "*.vrb" -o -name "*.fls" -o -name "*.fdb_latexmk" \
	          -o -name "*.synctex.gz" \) \
	       -not -path "./.git/*" -not -path "./theme/*" \
	       -delete
	@echo "✔ Arquivos auxiliares removidos."

## Remove auxiliares + PDFs gerados (mantém PDFs já commitados)
clean-all: clean
	find . -name "slides.pdf" \
	       -not -path "./.git/*" -not -path "./theme/*" \
	       -delete
	@echo "✔ PDFs removidos."

## Mostra esta ajuda
help:
	@grep -E '^##' Makefile | sed 's/## /  /'
