---
layout: default
title: "COMP0498 — Algoritmos e Estruturas de Dados II"
---

{% assign d = site.data.disciplinas | where: "slug", "algoritmos-2" | first %}
{% assign ativas = d.turmas | where_exp: "t", "t.arquivada != true" %}

<nav class="breadcrumb">
  <a href="{{ '/' | relative_url }}">Disciplinas</a>
  <span class="breadcrumb-sep">›</span>
  <span>{{ d.nome }}</span>
</nav>

<h1 class="page-title">{{ d.nome }}</h1>
<p class="page-subtitle">Selecione uma turma</p>

<div class="cards-grid">
{% for t in ativas %}
  <a href="{{ d.slug | append: '/' | append: t.id | relative_url }}" class="card" style="text-decoration:none; color:inherit;">
    <div class="card-icon">📅</div>
    <div class="card-title">{{ t.label }}</div>
    <div class="card-meta">{{ t.semestre }} · Semestre atual</div>
    <span class="card-link">Ver aulas →</span>
  </a>
{% endfor %}
</div>

{% if ativas.size == 0 %}
<p>Nenhuma turma neste semestre. Veja as <a href="{{ 'arquivo' | relative_url }}">turmas anteriores</a>.</p>
{% endif %}
