---
layout: default
title: "Aula 09 — Modularização de programas"
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
  <span>Aula 09</span>
</nav>

<h1 class="page-title">Aula 09 — Modularização de programas</h1>
<p class="page-subtitle">Headers, múltiplos arquivos e bibliotecas: quebrar o <code>notas.c</code> em peças que compilam separado</p>

<div class="table-card">
  <div class="table-card-header">📄 Slides</div>
  <table>
    <tbody>
      <tr>
        <td><strong>Modularização de programas: interface e implementação, de <code>.c</code> a executável, <code>make</code>, bibliotecas e os erros que o compilador não pega</strong></td>
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
        <td><strong>Notebook: do <code>notas.c</code> monolítico aos módulos — guardas de inclusão, símbolos dentro do <code>.o</code>, os dois erros de ligação, <code>Makefile</code> com regras de padrão e empacotamento como biblioteca estática</strong></td>
        <td class="td-right"><a class="badge-pdf" href="https://colab.research.google.com/github/ayoshiaki/ufs-disciplinas/blob/main/programacao-c/2026-2-T02/aula-09-modularizacao-headers-multiplos-arquivos-e-bibliotecas/tutorial/tutorial.ipynb" target="_blank" rel="noopener">🚀 Abrir no Colab</a></td>
      </tr>
    </tbody>
  </table>
</div>

<div class="table-card">
  <div class="table-card-header">💻 Código da aula</div>
  <table>
    <tbody>
      <tr>
        <td><strong>Versão monolítica (<code>notas.c</code>) e versão modular (<code>matriz</code>, <code>estat</code>, <code>turma</code>, <code>main</code> e <code>Makefile</code>)</strong></td>
        <td class="td-right"><a class="badge-pdf" href="https://github.com/ayoshiaki/ufs-disciplinas/tree/main/programacao-c/2026-2-T02/aula-09-modularizacao-headers-multiplos-arquivos-e-bibliotecas/codigo" target="_blank" rel="noopener">💻 Ver no GitHub</a></td>
      </tr>
    </tbody>
  </table>
</div>
