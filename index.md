---
layout: default
title: "Material Didático"
---

<h1 class="page-title">Material Didático</h1>
<p class="page-subtitle">Departamento de Computação · {{ site.data.disciplinas | size }} disciplinas</p>

<div class="cards-grid">
{% for d in site.data.disciplinas %}
  <a href="{{ d.slug | relative_url }}" class="card" style="text-decoration:none; color:inherit;">
    <div class="card-icon">{{ d.icone }}</div>
    <div class="card-title">{{ d.nome }}</div>
    <div class="card-meta">
      {% for t in d.turmas %}{{ t.semestre }} · {{ t.label }}{% unless forloop.last %} &nbsp;·&nbsp; {% endunless %}{% endfor %}
    </div>
    <span class="card-link">Ver aulas →</span>
  </a>
{% endfor %}
</div>
