---
layout: default
title: "Projeto — Projeto Paint"
disciplina: programacao-a
turma: 2026-1-T05
---

<nav class="breadcrumb">
  <a href="{{ '/' | relative_url }}">Disciplinas</a>
  <span class="breadcrumb-sep">›</span>
  <a href="{{ 'programacao-a' | relative_url }}">COMP0496 — Programação A</a>
  <span class="breadcrumb-sep">›</span>
  <a href="{{ 'programacao-a/2026-1-T05' | relative_url }}">Turma 5 · 2026/1</a>
  <span class="breadcrumb-sep">›</span>
  <span>Projeto</span>
</nav>

<h1 class="page-title">Projeto — Projeto Paint</h1>
<p class="page-subtitle">Um programa estilo <em>paint</em> em Python com Tkinter, evoluindo de imperativo para OO/MVC ao longo de 7 entregas</p>

{% assign colab = 'https://colab.research.google.com/github/ayoshiaki/ufs-disciplinas/blob/main/programacao-a/2026-1-T05/projeto' %}
{% assign github = 'https://github.com/ayoshiaki/ufs-disciplinas/blob/main/programacao-a/2026-1-T05/projeto' %}

<div class="table-card">
  <div class="table-card-header">📋 Enunciado</div>
  <table>
    <tbody>
      <tr>
        <td><strong>Descrição do projeto — entregas, datas e tags Git</strong></td>
        <td class="td-right"><a class="badge-colab" href="{{ colab }}/descricao.ipynb">▶ Abrir no Colab</a></td>
      </tr>
    </tbody>
  </table>
</div>

<div class="table-card">
  <div class="table-card-header">💻 Código de referência</div>
  <table>
    <tbody>
      <tr>
        <td><strong>01-linha.py</strong> — uma única linha por vez</td>
        <td class="td-right"><a class="badge-code" href="{{ github }}/01-linha.py">🗂 Ver código</a></td>
      </tr>
      <tr>
        <td><strong>02-linhas.py</strong> — várias linhas acumuladas</td>
        <td class="td-right"><a class="badge-code" href="{{ github }}/02-linhas.py">🗂 Ver código</a></td>
      </tr>
      <tr>
        <td><strong>03-linhasERabiscos.py</strong> — base entregue aos alunos</td>
        <td class="td-right"><a class="badge-code" href="{{ github }}/03-linhasERabiscos.py">🗂 Ver código</a></td>
      </tr>
    </tbody>
  </table>
</div>

<div class="prose" markdown="1">

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

## Mapa dos arquivos

| Arquivo | Descrição |
| --- | --- |
| `descricao.ipynb` | Enunciado completo do projeto (entregas, datas). |
| `01-linha.py` | Referência imperativa: uma única linha por vez. |
| `02-linhas.py` | Referência imperativa: várias linhas acumuladas. |
| `03-linhasERabiscos.py` | **Base entregue aos alunos** — linhas e rabiscos, imperativo. |

</div>
