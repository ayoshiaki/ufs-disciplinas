---
layout: default
title: "Aula 13 — Recursividade e memória"
disciplina: programacao-c
turma: 2026-2-T02
---

<nav class="breadcrumb">
  <a href="{{ '/' | relative_url }}">Disciplinas</a>
  <span class="breadcrumb-sep">›</span>
  <a href="{{ 'programacao-c' | relative_url }}">COMP0512 — Programação C</a>
  <span class="breadcrumb-sep">›</span>
  <a href="{{ 'programacao-c/2026-2-T02' | relative_url }}">Turma 2 · 2026/2</a>
  <span class="breadcrumb-sep">›</span>
  <span>Aula 13</span>
</nav>

<h1 class="page-title">Aula 13 — Recursividade e memória</h1>
<p class="page-subtitle">O que a recursão gasta, onde, e como não estourar</p>

<div class="table-card">
  <div class="table-card-header">📄 Slides</div>
  <table>
    <tbody>
      <tr>
        <td><strong>Até onde a pilha aguenta, o que pesa em cada registro, recursão de cauda, uma tabela no heap para todas as chamadas e <code>malloc</code> em cada chamada: quem libera, e quando</strong></td>
        <td class="td-right"><a class="badge-pdf" href="slides.pdf">📄 PDF</a></td>
      </tr>
    </tbody>
  </table>
</div>

<div class="table-card">
  <div class="table-card-header">📓 Tutorial</div>
  <table>
    <tbody>
      <tr>
        <td><strong>Notebook: medir o limite da pilha, ver a recursão de cauda com <code>-O2</code>, comparar Fibonacci ingênuo e com tabela, e acompanhar o pico de heap com e sem <code>free</code></strong></td>
        <td class="td-right"><a class="badge-pdf" href="https://colab.research.google.com/github/ayoshiaki/ufs-disciplinas/blob/main/programacao-c/2026-2-T02/aula-13-recursividade-e-efeitos-na-alocacao-de-memoria/tutorial/tutorial.ipynb" target="_blank" rel="noopener">🚀 Abrir no Colab</a></td>
      </tr>
    </tbody>
  </table>
</div>

<div class="table-card">
  <div class="table-card-header">💻 Código da aula</div>
  <table>
    <tbody>
      <tr>
        <td><strong><code>memoria.c</code>: soma recursiva, soma com parcial na ida e Fibonacci com tabela no heap; <code>gorda.c</code>: um vetor local em cada nível; <code>invertida.c</code>: <code>malloc</code> em cada chamada, com contagem do pico de heap</strong></td>
        <td class="td-right"><a class="badge-pdf" href="https://github.com/ayoshiaki/ufs-disciplinas/tree/main/programacao-c/2026-2-T02/aula-13-recursividade-e-efeitos-na-alocacao-de-memoria/codigo" target="_blank" rel="noopener">💻 Ver no GitHub</a></td>
      </tr>
    </tbody>
  </table>
</div>
