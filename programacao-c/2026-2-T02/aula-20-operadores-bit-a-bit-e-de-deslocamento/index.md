---
layout: default
title: "Aula 20 — Operadores bit-a-bit e de deslocamento"
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
  <span>Aula 20</span>
</nav>

<h1 class="page-title">Aula 20 — Operadores bit-a-bit e de deslocamento</h1>
<p class="page-subtitle">Nove sins e nãos num único número — e exercícios</p>

<div class="table-card">
  <div class="table-card-header">📄 Slides</div>
  <table>
    <tbody>
      <tr>
        <td><strong>Permissões de arquivos em UNIX como nove bits, um inteiro como fileira de bits em binário, octal e hexadecimal, os operadores <code>&amp;</code>, <code>|</code>, <code>^</code> e <code>~</code>, máscaras para ligar, desligar, inverter e testar bits, deslocamentos <code>&lt;&lt;</code> e <code>&gt;&gt;</code>, a ordem dos bytes na memória, um conjunto dentro de um <code>unsigned</code> e exercícios</strong></td>
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
        <td><strong>Notebook: os bits de um número, distância de Hamming, de letras para número, cores <code>0xRRGGBB</code>, trocar a ordem dos bytes, que dia todo mundo pode e duas pilhas de mesmo peso</strong></td>
        <td class="td-right"><a class="badge-pdf" href="https://colab.research.google.com/github/ayoshiaki/ufs-disciplinas/blob/main/programacao-c/2026-2-T02/aula-20-operadores-bit-a-bit-e-de-deslocamento/tutorial/tutorial.ipynb" target="_blank" rel="noopener">🚀 Abrir no Colab</a></td>
      </tr>
    </tbody>
  </table>
</div>

<div class="table-card">
  <div class="table-card-header">💻 Código da aula</div>
  <table>
    <tbody>
      <tr>
        <td><strong><code>permissoes.c</code>: lê um modo UNIX em octal e aplica ordens como <code>u+x</code> e <code>go-w</code>; <code>decimal.c</code>: o modo 754 escrito sem o zero na frente; <code>precedencia.c</code>: quem pode escrever? (<code>&amp;</code> contra <code>==</code>); <code>mascaras.c</code>: a máscara do bit <em>k</em>, para <em>k</em> de 28 a 32 (rode com <code>make mascaras-ubsan</code>); <code>bytes.c</code>: os quatro bytes de um <code>unsigned</code>, na ordem da memória; <code>conjunto.c</code>: um conjunto de 0 a 31 num <code>unsigned</code>; <code>crivo.c</code>: o crivo de Eratóstenes com um <code>char</code> e com um bit por número</strong></td>
        <td class="td-right"><a class="badge-pdf" href="https://github.com/ayoshiaki/ufs-disciplinas/tree/main/programacao-c/2026-2-T02/aula-20-operadores-bit-a-bit-e-de-deslocamento/codigo" target="_blank" rel="noopener">💻 Ver no GitHub</a></td>
      </tr>
    </tbody>
  </table>
</div>
