---
layout: default
title: "Material Didático"
---

{% assign disciplinas_ativas = "" | split: "" %}
{% for d in site.data.disciplinas %}
  {% assign ativas = d.turmas | where_exp: "t", "t.arquivada != true" %}
  {% if ativas.size > 0 %}
    {% assign disciplinas_ativas = disciplinas_ativas | push: d %}
  {% endif %}
{% endfor %}

<h1 class="page-title">Material Didático</h1>
<p class="page-subtitle">Departamento de Computação · {{ disciplinas_ativas | size }} disciplinas</p>

<div class="cards-grid">
{% for d in disciplinas_ativas %}
  {% assign ativas = d.turmas | where_exp: "t", "t.arquivada != true" %}
  <a href="{{ d.slug | relative_url }}" class="card" style="text-decoration:none; color:inherit;">
    <div class="card-icon">{{ d.icone }}</div>
    <div class="card-title">{{ d.nome }}</div>
    <div class="card-meta">
      {% for t in ativas %}{{ t.semestre }} · {{ t.label }}{% unless forloop.last %} &nbsp;·&nbsp; {% endunless %}{% endfor %}
    </div>
    <span class="card-link">Ver aulas →</span>
  </a>
{% endfor %}
</div>

<p style="margin-top:2.5rem;"><a href="{{ 'arquivo' | relative_url }}">📦 Turmas anteriores →</a></p>
