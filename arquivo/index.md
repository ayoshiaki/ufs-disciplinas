---
layout: default
title: "Turmas anteriores"
---

<nav class="breadcrumb">
  <a href="{{ '/' | relative_url }}">Disciplinas</a>
  <span class="breadcrumb-sep">›</span>
  <span>Turmas anteriores</span>
</nav>

<h1 class="page-title">📦 Turmas anteriores</h1>
<p class="page-subtitle">Material de semestres já encerrados</p>

{% assign total_arquivadas = 0 %}
{% for d in site.data.disciplinas %}
  {% assign arquivadas = d.turmas | where_exp: "t", "t.arquivada == true" %}
  {% assign total_arquivadas = total_arquivadas | plus: arquivadas.size %}
  {% if arquivadas.size > 0 %}
    <h2 style="margin:2rem 0 1rem; font-size:1.15rem;">{{ d.icone }} {{ d.nome }}</h2>
    <div class="cards-grid">
    {% for t in arquivadas %}
      <a href="{{ d.slug | append: '/' | append: t.id | relative_url }}" class="card" style="text-decoration:none; color:inherit;">
        <div class="card-icon">📅</div>
        <div class="card-title">{{ t.label }}</div>
        <div class="card-meta">{{ t.semestre }}</div>
        <span class="card-link">Ver aulas →</span>
      </a>
    {% endfor %}
    </div>
  {% endif %}
{% endfor %}

{% if total_arquivadas == 0 %}
<p style="margin-top:1rem;">Nenhuma turma arquivada por enquanto.</p>
{% endif %}
