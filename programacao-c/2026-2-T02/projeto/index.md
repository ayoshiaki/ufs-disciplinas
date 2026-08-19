---
layout: default
title: "Projeto — Sistema de Contabilidade Pessoal por Partidas Dobradas"
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
  <span>Projeto</span>
</nav>

<h1 class="page-title">Projeto — Sistema de Contabilidade Pessoal por Partidas Dobradas</h1>
<p class="page-subtitle">Um sistema de terminal em C, construído em quatro fases ao longo do semestre: contas e lançamentos, histórico navegável, persistência em arquivo e relatórios</p>

<div class="table-card">
  <div class="table-card-header">📋 Enunciado</div>
  <table>
    <tbody>
      <tr>
        <td><strong>Enunciado completo — fases, regras de entrega e critérios de avaliação</strong></td>
        <td class="td-right"><a class="badge-pdf" href="enunciado.pdf">📄 PDF</a></td>
      </tr>
    </tbody>
  </table>
</div>

<div class="table-card">
  <div class="table-card-header">🗓 Fases e entregas</div>
  <table>
    <tbody>
      <tr>
        <td><strong>Repositório privado no GitHub</strong> — criar, adicionar <code>ayoshiaki</code> como colaborador e enviar o link pelo SIGAA</td>
        <td class="td-right">02/09/2026</td>
      </tr>
      <tr>
        <td><strong>Fase 1 — Fundações</strong> (tag <code>fase-1</code>): plano de contas, lançamentos com a regra de ouro e saldos</td>
        <td class="td-right">07/10/2026</td>
      </tr>
      <tr>
        <td><strong>Fase 2 — O razão vivo</strong> (tag <code>fase-2</code>): lançamentos retroativos, extrato navegável, desfazer/refazer, agendamentos, saldos hierárquicos e TADs opacos</td>
        <td class="td-right">18/11/2026</td>
      </tr>
      <tr>
        <td><strong>Fase 3 — Dados que sobrevivem</strong> (tag <code>fase-3</code>): arquivo binário versionado, importação de CSV e atributos em campo de bits</td>
        <td class="td-right">07/12/2026</td>
      </tr>
      <tr>
        <td><strong>Fase 4 — Relatórios</strong> (tag <code>final</code>): balancete, extrato por período e pelo menos dois relatórios criados pelo grupo</td>
        <td class="td-right">13/12/2026</td>
      </tr>
      <tr>
        <td><strong>Apresentação final</strong> — demonstração ao vivo, defesa das decisões de projeto e arguição individual</td>
        <td class="td-right">14/12/2026</td>
      </tr>
    </tbody>
  </table>
</div>

<div class="prose" markdown="1">

## Em resumo

Grupos de 2 a 4 integrantes desenvolvem, em C (padrão C11, apenas biblioteca padrão), um
programa de terminal que registra contas e lançamentos financeiros por partidas dobradas,
mantém os saldos consistentes, persiste os dados em disco e produz relatórios.

O enunciado **não diz qual estrutura de dados usar** em nenhuma fase: ele descreve
comportamentos e restrições. Analisar os requisitos, escolher a estrutura adequada e justificar a
escolha por escrito no `DECISOES.md` é parte central da avaliação.

Cada fase é entregue como uma *tag* de release no repositório privado do grupo. O peso do
projeto na média é `MF = (2·P1 + 2·P2 + PJ)/5`.

</div>
