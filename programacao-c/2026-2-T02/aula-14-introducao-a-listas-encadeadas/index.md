---
layout: default
title: "Aula 14 — Listas encadeadas"
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
  <span>Aula 14</span>
</nav>

<h1 class="page-title">Aula 14 — Listas encadeadas</h1>
<p class="page-subtitle">Uma introdução: o nó, o encadeamento e o caminho até o <code>NULL</code></p>

<div class="table-card">
  <div class="table-card-header">📄 Slides</div>
  <table>
    <tbody>
      <tr>
        <td><strong>Por que não basta um vetor, o nó como <code>struct</code> que aponta para outro, montar e percorrer a lista, inserir no início, liberar sem perder o caminho e quando escolher vetor ou lista</strong></td>
        <td class="td-right"><a class="badge-pdf" href="slides.pdf">📄 PDF</a></td>
      </tr>
    </tbody>
  </table>
</div>

<div class="table-card">
  <div class="table-card-header">💻 Código da aula</div>
  <table>
    <tbody>
      <tr>
        <td><strong><code>lista.c</code>: inserir no início, imprimir, contar e liberar; <code>vetor_vs_lista.c</code>: inserir <em>n</em> valores no início de um vetor e de uma lista; <code>percorre.c</code>: somar <em>n</em> valores num vetor e numa lista; <code>libera_errada.c</code>: o <code>free</code> que vem antes da hora (rode com <code>make libera_errada-asan</code>)</strong></td>
        <td class="td-right"><a class="badge-pdf" href="https://github.com/ayoshiaki/ufs-disciplinas/tree/main/programacao-c/2026-2-T02/aula-14-introducao-a-listas-encadeadas/codigo" target="_blank" rel="noopener">💻 Ver no GitHub</a></td>
      </tr>
    </tbody>
  </table>
</div>
