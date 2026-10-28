---
layout: default
title: "Aula 18 — Filas: conceito e implementação"
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
  <span>Aula 18</span>
</nav>

<h1 class="page-title">Aula 18 — Filas: conceito e implementação</h1>
<p class="page-subtitle">Entra-se por uma ponta e sai-se pela outra — e exercícios</p>

<div class="table-card">
  <div class="table-card-header">📄 Slides</div>
  <table>
    <tbody>
      <tr>
        <td><strong>O primeiro a entrar é o primeiro a sair, a fila num vetor com <code>ini</code> e <code>fim</code> que só andam para a direita, a fila circular em que o fim dá a volta, dobrar o vetor circular sem embaralhar, a fila numa lista que sai do primeiro nó e entra depois do último, quanto custa cada versão e exercícios</strong></td>
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
        <td><strong>Notebook: a roda da batata quente, um escalonador <em>round-robin</em>, a fila circular que avisa, crescer sem embaralhar, a mesma interface em vetor e em lista, a fila com duas pilhas e o caminho mais curto no labirinto</strong></td>
        <td class="td-right"><a class="badge-pdf" href="https://colab.research.google.com/github/ayoshiaki/ufs-disciplinas/blob/main/programacao-c/2026-2-T02/aula-18-filas-conceito-e-implementacao/tutorial/tutorial.ipynb" target="_blank" rel="noopener">🚀 Abrir no Colab</a></td>
      </tr>
    </tbody>
  </table>
</div>

<div class="table-card">
  <div class="table-card-header">💻 Código da aula</div>
  <table>
    <tbody>
      <tr>
        <td><strong><code>batata.c</code>: quem sobra na roda da batata quente?; <code>batata_circular.c</code>: a mesma roda com a fila circular; <code>dobra_errada.c</code>: a fila circular que dobra só com <code>realloc</code> (rode com <code>make dobra_errada-asan</code>); <code>esvazia.c</code>: a fila em lista que esquece de atualizar <code>fim</code> ao esvaziar (rode com <code>make esvazia-asan</code>); <code>fila.h</code>, <code>fila_vetor.c</code> e <code>fila_lista.c</code>: uma interface, duas implementações, usadas por <code>batata_tad.c</code>; <code>custo.c</code>: deslocar, dar a volta ou encadear — o tempo das três filas</strong></td>
        <td class="td-right"><a class="badge-pdf" href="https://github.com/ayoshiaki/ufs-disciplinas/tree/main/programacao-c/2026-2-T02/aula-18-filas-conceito-e-implementacao/codigo" target="_blank" rel="noopener">💻 Ver no GitHub</a></td>
      </tr>
    </tbody>
  </table>
</div>
