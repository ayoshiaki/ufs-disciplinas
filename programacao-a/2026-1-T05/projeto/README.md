# Projeto Paint — Programação A 2026-1

Projeto da disciplina **Programação A (2026-1)** — DCOMP/UFS. 

Este exercício foi desenvolvido por Dr. Giovanny Fernando Lucero Palma, e utilizado por docentes desta disciplina. 

Dr. André Yoshiaki Kashiwabara adaptou o exercício para a turma T05 de 2026/01. 


Um programa do tipo *paint* em Python com Tkinter, no estilo das aplicações
Google Drawings e LibreOffice Draw. O projeto parte de uma implementação
imperativa simples e evolui, ao longo de 7 entregas, para uma arquitetura
Orientada a Objetos com MVC e padrões de projeto.

O enunciado completo, com as entregas, datas e tags Git,
está em [`descricao.ipynb`](descricao.ipynb).

## Requisitos

- Python 3.10 ou superior.
- Tkinter (incluído na maioria das instalações de Python; no Linux pode exigir
  o pacote `python3-tk`).

Para conferir se o Tkinter está disponível:

```bash
python -m tkinter
```

## Como executar

Cada script abre uma janela própria. A partir da raiz do projeto:

```bash
python 01-linha.py            # desenha uma única linha (apaga a anterior)
python 02-linhas.py           # acumula várias linhas
python 03-linhasERabiscos.py  # linhas e rabiscos, com OptionMenu (base dos alunos)
```

A versão Orientada a Objetos parcial fica em `implementacoesParciais/OO/` e deve
ser executada de dentro da própria pasta (o `import figuras` é relativo a ela):

```bash
cd implementacoesParciais/OO
python linhasERabiscosFigs.py
```

## Mapa dos arquivos

| Arquivo | Descrição |
| --- | --- |
| `descricao.ipynb` | Enunciado completo do projeto (entregas, datas). |
| `01-linha.py` | Referência imperativa: uma única linha por vez. |
| `02-linhas.py` | Referência imperativa: várias linhas acumuladas. |
| `03-linhasERabiscos.py` | **Base entregue aos alunos** — linhas e rabiscos, imperativo. |
| `implementacoesParciais/OO/figuras.py` | Hierarquia `Figura` (Linha, Rabisco). |
| `implementacoesParciais/OO/linhasERabiscosFigs.py` | Versão OO parcial (gabarito docente — **não** disponibilizar). |

> **Nota docente:** o uso de variáveis globais e funções de módulo nas versões
> imperativas e na OO parcial é intencional — representa o estado "meio do
> caminho" que os alunos refatoram para OO/MVC ao longo das entregas.
