---
layout: default
title: "Aula 22 — Arquivos binários: fread, fwrite e fseek"
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
  <span>Aula 22</span>
</nav>

<h1 class="page-title">Aula 22 — Arquivos binários: <code>fread</code>, <code>fwrite</code> e <code>fseek</code></h1>
<p class="page-subtitle">Achar e alterar um aluno no meio do arquivo sem reescrever o resto — e exercícios</p>

<div class="table-card">
  <div class="table-card-header">📄 Slides</div>
  <table>
    <tbody>
      <tr>
        <td><strong>Texto ou bytes: o que se perde ao gravar um número como texto, <code>fwrite</code> e o modo <code>"wb"</code>, <code>sizeof</code>, preenchimento e ordem dos bytes de um registro, <code>fread</code> e o que ele devolve, por que gravar um ponteiro não grava o que ele aponta, direto ao registro <i>k</i> com <code>fseek</code> e <code>ftell</code>, alterar sem reescrever com <code>"r+b"</code> — e exercícios</strong></td>
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
        <td><strong>Notebook: quadrados em disco, copiar qualquer arquivo, comparar dois arquivos, contar registros sem ler, listar de trás para frente, um <code>xxd</code> simples e busca binária no disco</strong></td>
        <td class="td-right"><a class="badge-pdf" href="https://colab.research.google.com/github/ayoshiaki/ufs-disciplinas/blob/main/programacao-c/2026-2-T02/aula-22-arquivos-binarios-fread-fwrite-e-fseek/tutorial/tutorial.ipynb" target="_blank" rel="noopener">🚀 Abrir no Colab</a></td>
      </tr>
    </tbody>
  </table>
</div>

<div class="table-card">
  <div class="table-card-header">🧪 Roteiro prático</div>
  <table>
    <tbody>
      <tr>
        <td><strong>Roteiro de laboratório: ler <code>turma.csv</code> com <code>fgetc</code>, <code>fgets</code> + <code>sscanf</code> e <code>fscanf</code> (e a armadilha do <code>feof</code>); medir o registro, ler <code>turma.bin</code> com <code>fread</code> e ir direto ao registro <i>k</i> com <code>fseek</code>; o mesmo número como texto e como bytes — com tarefas, desafios e saídas esperadas</strong></td>
        <td class="td-right"><a class="badge-pdf" href="roteiro/roteiro.pdf">📄 PDF</a></td>
      </tr>
      <tr>
        <td><strong>Programas e dados do roteiro: <code>conta.c</code>, <code>media.c</code>, <code>pedacos.c</code>, <code>repete.c</code>, <code>tamanho.c</code>, <code>lista.c</code>, <code>lote.c</code>, <code>consulta.c</code>, <code>precisao.c</code>, <code>turma.csv</code>, <code>turma2.csv</code> e <code>turma.bin</code> (o mesmo que o <code>make</code> gera)</strong></td>
        <td class="td-right"><a class="badge-pdf" href="https://github.com/ayoshiaki/ufs-disciplinas/tree/main/programacao-c/2026-2-T02/aula-22-arquivos-binarios-fread-fwrite-e-fseek/roteiro/codigo" target="_blank" rel="noopener">💻 Ver no GitHub</a></td>
      </tr>
    </tbody>
  </table>
</div>

<div class="table-card">
  <div class="table-card-header">💻 Código da aula</div>
  <table>
    <tbody>
      <tr>
        <td><strong><code>aluno.h</code>: o registro gravado em <code>turma.bin</code>; <code>precisao.c</code>: o mesmo <code>double</code> gravado como texto e como bytes; <code>cadastro.c</code>: converte <code>turma.csv</code> em <code>turma.bin</code>; <code>lista.c</code>: lê <code>turma.bin</code> registro a registro e imprime o boletim; <code>ponteiro.c</code>: grava uma <code>struct</code> que tem um ponteiro dentro; <code>consulta.c</code>: vai direto ao registro <i>k</i> de <code>turma.bin</code>; <code>corrige.c</code>: troca uma nota dentro de <code>turma.bin</code> sem reescrever o resto; <code>corrige_rb.c</code>: o mesmo, aberto com <code>"rb"</code> e sem testar o <code>fwrite</code></strong></td>
        <td class="td-right"><a class="badge-pdf" href="https://github.com/ayoshiaki/ufs-disciplinas/tree/main/programacao-c/2026-2-T02/aula-22-arquivos-binarios-fread-fwrite-e-fseek/codigo" target="_blank" rel="noopener">💻 Ver no GitHub</a></td>
      </tr>
    </tbody>
  </table>
</div>
