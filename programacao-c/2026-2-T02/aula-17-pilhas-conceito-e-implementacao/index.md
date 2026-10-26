---
layout: default
title: "Aula 17 — Pilhas: conceito e implementação"
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
  <span>Aula 17</span>
</nav>

<h1 class="page-title">Aula 17 — Pilhas: conceito e implementação</h1>
<p class="page-subtitle">Só se põe e se tira por uma das pontas — e exercícios</p>

<div class="table-card">
  <div class="table-card-header">📄 Slides</div>
  <table>
    <tbody>
      <tr>
        <td><strong>O último a entrar é o primeiro a sair, a pilha num vetor com o topo em <code>v[n-1]</code>, pilha vazia e pilha cheia — os dois erros que não avisam —, dobrar o vetor em vez de somar um, a pilha numa lista com o topo no primeiro nó, quanto custa cada versão e exercícios</strong></td>
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
        <td><strong>Notebook: o teste de balanceamento de <code>( [ { } ] )</code>, a pilha que avisa quando falha, o vetor que cresce com <code>realloc</code>, a mesma interface em vetor e em lista, conversão de base e a medição de vetor contra lista</strong></td>
        <td class="td-right"><a class="badge-pdf" href="https://colab.research.google.com/github/ayoshiaki/ufs-disciplinas/blob/main/programacao-c/2026-2-T02/aula-17-pilhas-conceito-e-implementacao/tutorial/tutorial.ipynb" target="_blank" rel="noopener">🚀 Abrir no Colab</a></td>
      </tr>
    </tbody>
  </table>
</div>

<div class="table-card">
  <div class="table-card-header">💻 Código da aula</div>
  <table>
    <tbody>
      <tr>
        <td><strong><code>balanco.c</code>: os parênteses, colchetes e chaves fecham na ordem certa?; <code>balanco_errada.c</code>: o mesmo teste sem conferir a pilha vazia (rode com <code>make balanco_errada-asan</code>); <code>transborda.c</code>: mais aberturas do que cabem no vetor; <code>pilha.h</code>, <code>pilha_vetor.c</code> e <code>pilha_lista.c</code>: uma interface, duas implementações, usadas por <code>balanco_tad.c</code>; <code>crescimento.c</code>: crescer de 1 em 1 contra dobrar; <code>vetor_vs_lista.c</code>: o tempo de empilhar e desempilhar nas duas versões</strong></td>
        <td class="td-right"><a class="badge-pdf" href="https://github.com/ayoshiaki/ufs-disciplinas/tree/main/programacao-c/2026-2-T02/aula-17-pilhas-conceito-e-implementacao/codigo" target="_blank" rel="noopener">💻 Ver no GitHub</a></td>
      </tr>
    </tbody>
  </table>
</div>
