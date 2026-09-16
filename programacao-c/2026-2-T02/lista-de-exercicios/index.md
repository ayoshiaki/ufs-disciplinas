---
layout: default
title: "Lista de Exercícios — Fundamentos, Ponteiros e Memória Dinâmica"
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
  <span>Lista de Exercícios</span>
</nav>

<h1 class="page-title">Lista de Exercícios — Fundamentos, Ponteiros e Memória Dinâmica</h1>
<p class="page-subtitle">20 exercícios sobre todo o conteúdo trabalhado até aqui: dos tipos e TADs à alocação dinâmica de vetores e matrizes</p>

<div class="table-card">
  <div class="table-card-header">📄 Lista</div>
  <table>
    <tbody>
      <tr>
        <td><strong>Lista completa — 20 exercícios em seis partes, com rastreios, depuração de código e implementação</strong></td>
        <td class="td-right"><a class="badge-pdf" href="lista-de-exercicios.pdf">📄 PDF</a></td>
      </tr>
    </tbody>
  </table>
</div>

<div class="table-card">
  <div class="table-card-header">🧭 Partes e conteúdo</div>
  <table>
    <tbody>
      <tr>
        <td><strong>Parte I — Fundamentos, tipos e abstração</strong><br>rastreio de laços, divisão inteira, conversões e limites dos tipos, tipo × estrutura de dados × TAD, funções sobre vetores</td>
        <td class="td-right">Ex. 1–4</td>
      </tr>
      <tr>
        <td><strong>Parte II — Registros, enumerações e apelidos de tipo</strong><br>mapa de bytes e reordenação de <code>struct</code>, registros em funções, <code>enum</code> em <code>switch</code>, armadilhas do <code>typedef</code></td>
        <td class="td-right">Ex. 5–8</td>
      </tr>
      <tr>
        <td><strong>Parte III — Ponteiros</strong><br>rastreio com <code>&amp;</code>, <code>*</code> e aritmética, o <code>troca</code> que não troca, percorrer sem colchetes, ponteiro para ponteiro</td>
        <td class="td-right">Ex. 9–12</td>
      </tr>
      <tr>
        <td><strong>Parte IV — Vetores, strings e passagem por referência</strong><br>o vetor que encolhe na função, strings sem <code>&lt;string.h&gt;</code>, devolver mais de um resultado, erros que compilam sem reclamar</td>
        <td class="td-right">Ex. 13–16</td>
      </tr>
      <tr>
        <td><strong>Parte V — Alocação dinâmica de memória</strong><br>caça às falhas clássicas e um vetor que cresce sozinho com <code>realloc</code></td>
        <td class="td-right">Ex. 17–18</td>
      </tr>
      <tr>
        <td><strong>Parte VI — Vetores e matrizes dinâmicos</strong><br>matriz como vetor de ponteiros (<code>double **</code>) e a mesma matriz em um bloco único</td>
        <td class="td-right">Ex. 19–20</td>
      </tr>
    </tbody>
  </table>
</div>

<div class="prose" markdown="1">

## Como usar

A lista cobre o conteúdo das aulas de fundamentos de C, tipos e TADs, `struct`,
`enum`/`typedef`, ponteiros, vetores e strings, alocação dinâmica de memória e
vetores e matrizes dinâmicos.

Nos exercícios de rastreio, **escreva a saída no papel antes de compilar** — a diferença
entre o que você previu e o que o programa imprime é justamente o que a lista quer
mostrar. Nos exercícios de implementação, compile com avisos ligados:

```bash
gcc -std=c11 -Wall -Wextra -g exercicio.c -o exercicio
```

O gabarito será disponibilizado depois.

</div>
