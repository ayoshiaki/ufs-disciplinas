---
layout: default
title: "Lista de Exercícios 2 — Recursividade, Listas, Pilhas e Filas"
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
  <span>Lista de Exercícios 2</span>
</nav>

<h1 class="page-title">Lista de Exercícios 2 — Recursividade, Listas, Pilhas e Filas</h1>
<p class="page-subtitle">20 exercícios sobre o conteúdo da segunda unidade: da pilha de execução às filas</p>

<div class="table-card">
  <div class="table-card-header">📄 Lista</div>
  <table>
    <tbody>
      <tr>
        <td><strong>Lista completa — 20 exercícios em seis partes, com rastreios, desenhos de memória, depuração de código e implementação</strong></td>
        <td class="td-right"><a class="badge-pdf" href="lista-de-exercicios-2.pdf">📄 PDF</a></td>
      </tr>
    </tbody>
  </table>
</div>

<div class="table-card">
  <div class="table-card-header">🧭 Partes e conteúdo</div>
  <table>
    <tbody>
      <tr>
        <td><strong>Parte I — Recursividade e pilha de execução</strong><br>o que acontece na ida e na volta, árvore de chamadas e o custo de recalcular, escrever funções recursivas</td>
        <td class="td-right">Ex. 1–3</td>
      </tr>
      <tr>
        <td><strong>Parte II — Recursividade e memória</strong><br>locais que se multiplicam pela profundidade, recursão de cauda, quem recebe o bloco é dono dele</td>
        <td class="td-right">Ex. 4–6</td>
      </tr>
      <tr>
        <td><strong>Parte III — Listas encadeadas simples</strong><br>seguir as setas, funções sobre uma lista, o <code>insere_fim</code> que não insere, ponteiro para a seta</td>
        <td class="td-right">Ex. 7–10</td>
      </tr>
      <tr>
        <td><strong>Parte IV — Listas duplamente encadeadas</strong><br>quatro setas para mover um nó, operações nos extremos e no meio, o nó sentinela</td>
        <td class="td-right">Ex. 11–13</td>
      </tr>
      <tr>
        <td><strong>Parte V — Pilhas</strong><br>seguir a pilha, pilha num vetor que dobra, pilha numa lista e o uso só pela interface</td>
        <td class="td-right">Ex. 14–16</td>
      </tr>
      <tr>
        <td><strong>Parte VI — Filas</strong><br>a fila circular dá a volta, fila numa lista com as duas pontas, resolver problemas com filas e pilhas, escolher a estrutura</td>
        <td class="td-right">Ex. 17–20</td>
      </tr>
    </tbody>
  </table>
</div>

<div class="prose" markdown="1">

## Como usar

A lista cobre o conteúdo das aulas de recursividade e pilha de execução, recursividade
e memória, listas encadeadas simples e duplas, pilhas e filas.

**A entrega é manuscrita**, em folhas avulsas com nome e matrícula em todas elas — as
instruções completas estão no início do PDF. Nos exercícios de rastreio, escreva a
saída no papel antes de conferir no computador; nos desenhos de memória, uma caixa por
nó ou variável, uma seta por ponteiro e `NULL` escrito explicitamente.

Para testar suas soluções antes de passá-las a limpo, compile com avisos ligados:

```bash
gcc -std=c11 -Wall -Wextra -g exercicio.c -o exercicio
```

</div>
