---
layout: default
title: "Aula 10 — Padrões de codificação"
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
  <span>Aula 10</span>
</nav>

<h1 class="page-title">Aula 10 — Padrões de codificação</h1>
<p class="page-subtitle">E a prática de modularizar seguindo um padrão: o módulo <code>ranking</code> que funciona, mas ninguém consegue manter</p>

<div class="table-card">
  <div class="table-card-header">📄 Slides</div>
  <table>
    <tbody>
      <tr>
        <td><strong>Padrões de codificação: nomes, números mágicos, estado global, <code>static</code> e <code>const</code>, o <code>.h</code> como contrato e as ferramentas que cobram o padrão (<code>-Wall -Wextra</code>, <code>clang-format</code>)</strong></td>
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
        <td><strong>Notebook: do <code>ranking.c</code> fora do padrão ao módulo refatorado — o que o <code>nm</code> mostra vazando, o estouro de <code>R[50]</code> com 60 alunos e a saída idêntica byte por byte</strong></td>
        <td class="td-right"><a class="badge-pdf" href="https://colab.research.google.com/github/ayoshiaki/ufs-disciplinas/blob/main/programacao-c/2026-2-T02/aula-10-padroes-de-codificacao-e-pratica-de-modularizacao/tutorial/tutorial.ipynb" target="_blank" rel="noopener">🚀 Abrir no Colab</a></td>
      </tr>
    </tbody>
  </table>
</div>

<div class="table-card">
  <div class="table-card-header">💻 Código da aula</div>
  <table>
    <tbody>
      <tr>
        <td><strong>O projeto <code>notas</code> com o módulo <code>ranking</code> antes (<code>antes/</code>) e depois (<code>depois/</code>) de aplicar o padrão</strong></td>
        <td class="td-right"><a class="badge-pdf" href="https://github.com/ayoshiaki/ufs-disciplinas/tree/main/programacao-c/2026-2-T02/aula-10-padroes-de-codificacao-e-pratica-de-modularizacao/codigo" target="_blank" rel="noopener">💻 Ver no GitHub</a></td>
      </tr>
    </tbody>
  </table>
</div>
