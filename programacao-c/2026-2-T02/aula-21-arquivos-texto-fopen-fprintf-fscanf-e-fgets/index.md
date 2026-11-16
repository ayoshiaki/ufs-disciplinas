---
layout: default
title: "Aula 21 — Arquivos texto: fopen, fprintf, fscanf e fgets"
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
  <span>Aula 21</span>
</nav>

<h1 class="page-title">Aula 21 — Arquivos texto: <code>fopen</code>, <code>fprintf</code>, <code>fscanf</code> e <code>fgets</code></h1>
<p class="page-subtitle">As notas não morrem mais com o programa — e exercícios</p>

<div class="table-card">
  <div class="table-card-header">📄 Slides</div>
  <table>
    <tbody>
      <tr>
        <td><strong>Um arquivo texto como fileira de caracteres, fluxos e <code>FILE *</code>, os modos de <code>fopen</code>, <code>NULL</code>, <code>errno</code> e <code>perror</code>, o <em>buffer</em> e o <code>fclose</code>, <code>stdin</code>, <code>stdout</code> e <code>stderr</code>, <code>fscanf</code> e <code>fprintf</code>, por que não testar <code>feof</code>, <code>fgets</code> e o <code>'\n'</code> que vem junto, <code>fgets</code> + <code>sscanf</code>, <code>fgetc</code> e o <code>int c</code> — e exercícios</strong></td>
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
        <td><strong>Notebook: tabela de temperaturas, estatística de um arquivo de números, numerar as linhas, filtrar um CSV, arquivo de configuração, frequência das letras e intercalar duas listas de presença</strong></td>
        <td class="td-right"><a class="badge-pdf" href="https://colab.research.google.com/github/ayoshiaki/ufs-disciplinas/blob/main/programacao-c/2026-2-T02/aula-21-arquivos-texto-fopen-fprintf-fscanf-e-fgets/tutorial/tutorial.ipynb" target="_blank" rel="noopener">🚀 Abrir no Colab</a></td>
      </tr>
    </tbody>
  </table>
</div>

<div class="table-card">
  <div class="table-card-header">💻 Código da aula</div>
  <table>
    <tbody>
      <tr>
        <td><strong><code>boletim.c</code>: lê as notas de <code>turma.txt</code> e grava <code>boletim.txt</code>; <code>sem_teste.c</code>: o mesmo laço, sem testar o retorno de <code>fopen</code>; <code>diario.c</code>: grava uma anotação no diário de estudos — o que acontece na segunda execução?; <code>queda.c</code>: grava três linhas e cai antes do <code>fclose</code>; <code>fim.c</code>: o laço controlado por <code>feof</code>; <code>nomes.c</code>: tenta ler <code>turma.csv</code> com <code>fscanf</code> e <code>%s</code>; <code>linhas.c</code>: lê <code>turma.csv</code> linha a linha com um <em>buffer</em> pequeno; <code>boletim_csv.c</code>: <code>fgets</code> + <code>sscanf</code> para ler nomes com espaços; <code>conta.c</code>: conta linhas, palavras e bytes, como o <code>wc</code></strong></td>
        <td class="td-right"><a class="badge-pdf" href="https://github.com/ayoshiaki/ufs-disciplinas/tree/main/programacao-c/2026-2-T02/aula-21-arquivos-texto-fopen-fprintf-fscanf-e-fgets/codigo" target="_blank" rel="noopener">💻 Ver no GitHub</a></td>
      </tr>
    </tbody>
  </table>
</div>
