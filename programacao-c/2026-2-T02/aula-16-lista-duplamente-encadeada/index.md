---
layout: default
title: "Aula 16 — Lista duplamente encadeada"
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
  <span>Aula 16</span>
</nav>

<h1 class="page-title">Aula 16 — Lista duplamente encadeada</h1>
<p class="page-subtitle">Um nó que sabe quem vem antes — e exercícios</p>

<div class="table-card">
  <div class="table-card-header">📄 Slides</div>
  <table>
    <tbody>
      <tr>
        <td><strong>O nó com duas setas e a regra que ninguém confere por você, os quatro ponteiros de uma inserção, remover dado o nó sem esquecer <code>ini</code> e <code>fim</code>, o nó sentinela que acaba com os casos especiais, quanto custa cada operação e exercícios</strong></td>
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
        <td><strong>Notebook: conferir se a lista está consistente, inserir nos extremos sem percorrer, remover todas as ocorrências, inverter a lista e o desafio de um editor de linha com cursor</strong></td>
        <td class="td-right"><a class="badge-pdf" href="https://colab.research.google.com/github/ayoshiaki/ufs-disciplinas/blob/main/programacao-c/2026-2-T02/aula-16-lista-duplamente-encadeada/tutorial/tutorial.ipynb" target="_blank" rel="noopener">🚀 Abrir no Colab</a></td>
      </tr>
    </tbody>
  </table>
</div>

<div class="table-card">
  <div class="table-card-header">💻 Código da aula</div>
  <table>
    <tbody>
      <tr>
        <td><strong><code>dupla.c</code>: lista dupla em ordem crescente com inserção e remoção; <code>insere_errada.c</code>: a inserção que esquece o <code>ant</code> do seguinte; <code>remove_errada.c</code>: a remoção que esquece o <code>fim</code> (rode com <code>make remove_errada-asan</code>); <code>sentinela.c</code>: lista dupla circular com nó cabeça, sem nenhum <code>if</code>; <code>remove_fim.c</code>: remover sempre o último, na lista simples e na dupla</strong></td>
        <td class="td-right"><a class="badge-pdf" href="https://github.com/ayoshiaki/ufs-disciplinas/tree/main/programacao-c/2026-2-T02/aula-16-lista-duplamente-encadeada/codigo" target="_blank" rel="noopener">💻 Ver no GitHub</a></td>
      </tr>
    </tbody>
  </table>
</div>
