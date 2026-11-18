# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Repository purpose

Material didático (slides Beamer + notebooks + páginas Jekyll) das disciplinas do DCOMP/UFS ministradas pelo Prof. André Yoshiaki Kashiwabara. Publicado via GitHub Pages em `https://ayoshiaki.github.io/ufs-disciplinas`.

## Architecture

Dois sistemas convivem no mesmo repositório:

1. **Slides LaTeX/Beamer** — cada aula é uma pasta `disciplina/turma/aula-NN-titulo/` contendo `slides.tex` (e opcionalmente `notebook.ipynb`, `codigo/`). Todos os `slides.tex` herdam do tema em `theme/` (submódulo git: `UFS_Beamer`). O Makefile resolve `TEXINPUTS` para apontar para `theme/` antes de chamar `pdflatex`, então `slides.tex` referencia o tema como se estivesse no diretório local.

2. **Site Jekyll** — `index.md` lista disciplinas a partir de `_data/disciplinas.yml`; cada `disciplina/index.md` lista turmas; cada `disciplina/turma/index.md` lista aulas; cada aula tem um `index.md` com frontmatter (`disciplina`, `turma`, `data`) que linka para `slides.pdf` gerado pelo Makefile. Layout único em `_layouts/default.html`. Build via GitHub Actions (`.github/workflows/`); `theme/`, `Makefile`, `TEMPLATE-aula/` ficam fora do site (ver `exclude:` em `_config.yml`).

**Importante**: os PDFs gerados (`slides.pdf`) são commitados — o GitHub Pages não compila LaTeX. Sempre rode `make` antes de commitar mudanças nos slides.

## Common commands

```bash
# Compilar todos os slides
make

# Compilar uma aula específica
make aula AULA=algoritmos/2025-1-A/aula-02-complexidade

# Limpar arquivos auxiliares (.aux .log .nav etc), mantendo PDFs
make clean

# Limpar tudo, inclusive PDFs
make clean-all

# Servir o site Jekyll localmente
bundle exec jekyll serve
```

Após clonar, inicialize o submódulo do tema: `git submodule update --init --recursive`.

## Criando uma nova aula

Copie `TEMPLATE-aula/` para `disciplina/turma/aula-NN-titulo/`, ajuste o frontmatter de `index.md` (campos `title`, `disciplina`, `turma`, `data`) e edite `slides.tex`. O Makefile descobre o novo `slides.tex` automaticamente via `find`.

## Bibliografia

Cada aula tem seu próprio `referencias.bib`, ao lado do `slides.tex`, que usa `\bibliography{referencias}`. Nunca use `\bibliography{../referencias}`: muitos slides usam `\nocite{*}`, e apontar para a bib da turma (que acumula as entradas de todas as aulas) imprime referências de outras aulas e faz o PDF crescer a cada recompilação. Ao instalar uma aula preparada fora do repositório (onde a bib costuma ficar em `../referencias.bib`, relativa a `slides/`), copie a bib para a pasta da aula e ajuste essa linha. Os `referencias.bib` no nível da turma não são usados pelos slides.
