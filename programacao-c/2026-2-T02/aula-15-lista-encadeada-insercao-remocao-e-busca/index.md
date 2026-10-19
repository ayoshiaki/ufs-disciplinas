---
layout: default
title: "Aula 15 — Lista encadeada: busca, inserção e remoção"
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
  <span>Aula 15</span>
</nav>

<h1 class="page-title">Aula 15 — Lista encadeada: busca, inserção e remoção</h1>
<p class="page-subtitle">Achar, pôr e tirar um nó em qualquer ponto da lista</p>

<div class="table-card">
  <div class="table-card-header">📄 Slides</div>
  <table>
    <tbody>
      <tr>
        <td><strong>Buscar um valor, inserir em qualquer posição de uma lista ordenada, remover sem esquecer o primeiro nó, ponteiro para ponteiro para eliminar o caso especial e quanto custa cada operação</strong></td>
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
        <td><strong>Notebook: busca que desiste cedo, inserir no fim sem percorrer, remover por posição, remover todas as ocorrências com ponteiro para ponteiro e o desafio de uma agenda sempre em ordem alfabética</strong></td>
        <td class="td-right"><a class="badge-pdf" href="https://colab.research.google.com/github/ayoshiaki/ufs-disciplinas/blob/main/programacao-c/2026-2-T02/aula-15-lista-encadeada-insercao-remocao-e-busca/tutorial/tutorial.ipynb" target="_blank" rel="noopener">🚀 Abrir no Colab</a></td>
      </tr>
    </tbody>
  </table>
</div>

<div class="table-card">
  <div class="table-card-header">💻 Código da aula</div>
  <table>
    <tbody>
      <tr>
        <td><strong><code>lista.c</code>: lista em ordem crescente com busca, inserção e remoção; <code>busca_errada.c</code>: a condição do laço na ordem trocada (rode também com <code>make busca_errada-O2</code>); <code>remove_errada.c</code>: a remoção sem o caso do primeiro nó (rode com <code>make remove_errada-asan</code>); <code>ponteiro_duplo.c</code>: inserção e remoção sem caso especial; <code>fim_vs_inicio.c</code>: inserir <em>n</em> valores no fim, percorrendo, e no início</strong></td>
        <td class="td-right"><a class="badge-pdf" href="https://github.com/ayoshiaki/ufs-disciplinas/tree/main/programacao-c/2026-2-T02/aula-15-lista-encadeada-insercao-remocao-e-busca/codigo" target="_blank" rel="noopener">💻 Ver no GitHub</a></td>
      </tr>
    </tbody>
  </table>
</div>
