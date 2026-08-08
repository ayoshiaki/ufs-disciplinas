# Turmas Arquivadas Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Separar turmas em andamento (home) de turmas encerradas (nova página `/arquivo`), controlado por um flag `arquivada: true` em `_data/disciplinas.yml`.

**Architecture:** Site Jekyll estático. Todo o filtro é feito em Liquid a partir de `site.data.disciplinas`; nenhuma turma muda de URL. As páginas de disciplina deixam de ter cartas hardcoded e passam a ler o YAML. Spec: `docs/superpowers/specs/2026-08-08-turmas-arquivadas-design.md`.

**Tech Stack:** Jekyll (disponível como `jekyll` direto no PATH — **não** há Gemfile; use `jekyll build`, não `bundle exec`), Liquid, kramdown.

## Global Constraints

- Não tocar em Makefile, PDFs, `theme/`, `.github/workflows/`.
- URLs existentes preservadas (ex.: `/algoritmos/2026-1-T04` continua funcionando).
- Ausência do campo `arquivada` = turma atual; só `arquivada: true` arquiva.
- Verificação = `jekyll build` + inspeção de `_site/` (não há suíte de testes; o "teste" de cada task é buildar e conferir o HTML gerado com grep).
- Classes CSS disponíveis em `assets/css/main.css`: `cards-grid`, `card`, `card-icon`, `card-title`, `card-meta`, `card-link`, `breadcrumb`, `breadcrumb-sep`, `page-title`, `page-subtitle`. Não inventar classes novas.
- `baseurl` é `/ufs-disciplinas`; sempre gerar links com o filtro `relative_url`, como o código existente já faz.

---

### Task 1: Página `/arquivo` + exclusão de `docs/` do site

**Files:**
- Create: `arquivo/index.md`
- Modify: `_config.yml` (bloco `exclude:`)

**Interfaces:**
- Consumes: `site.data.disciplinas` (campos `nome`, `slug`, `icone`, `turmas[].id/semestre/label/arquivada`)
- Produces: página `/arquivo/` no site; nada consumido por outras tasks.

- [ ] **Step 1: Adicionar `docs/` ao exclude do Jekyll**

Em `_config.yml`, no bloco `exclude:`, adicionar uma linha logo após `- TEMPLATE-aula/`:

```yaml
  - docs/
```

- [ ] **Step 2: Criar `arquivo/index.md`**

```markdown
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
```

- [ ] **Step 3: Buildar e verificar**

Run: `jekyll build && cat _site/arquivo/index.html | grep -c "Nenhuma turma arquivada"`
Expected: build sem erro; grep imprime `1` (não há turmas arquivadas ainda).

Run: `ls _site/docs 2>&1`
Expected: `No such file or directory` (docs/ excluído do site).

- [ ] **Step 4: Commit**

```bash
git add arquivo/index.md _config.yml
git commit -m "Adiciona página /arquivo para turmas encerradas"
```

---

### Task 2: Home filtra turmas arquivadas e linka o arquivo

**Files:**
- Modify: `index.md` (arquivo inteiro — conteúdo completo abaixo)

**Interfaces:**
- Consumes: `site.data.disciplinas`; página `/arquivo/` da Task 1 (alvo do link).
- Produces: nada consumido por outras tasks.

- [ ] **Step 1: Substituir o conteúdo de `index.md`**

Conteúdo completo do arquivo:

```markdown
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
```

- [ ] **Step 2: Buildar e verificar**

Run: `jekyll build && grep -c "Turmas anteriores" _site/index.html && grep -c "2026/1" _site/index.html`
Expected: build sem erro; primeiro grep ≥ 1 (link para o arquivo); segundo grep = 2 (as duas turmas atuais seguem na home).

- [ ] **Step 3: Commit**

```bash
git add index.md
git commit -m "Home lista apenas turmas atuais e linka o arquivo"
```

---

### Task 3: Páginas de disciplina geradas a partir do YAML

**Files:**
- Modify: `algoritmos/index.md` (arquivo inteiro)
- Modify: `programacao-a/index.md` (arquivo inteiro)

**Interfaces:**
- Consumes: `site.data.disciplinas` (localiza a disciplina por `slug`).
- Produces: nada consumido por outras tasks.

- [ ] **Step 1: Substituir o conteúdo de `algoritmos/index.md`**

Conteúdo completo (nota: o frontmatter `title` fica hardcoded porque Liquid não roda no frontmatter):

```markdown
---
layout: default
title: "COMP0497 — Algoritmos e Estruturas de Dados 1"
---

{% assign d = site.data.disciplinas | where: "slug", "algoritmos" | first %}
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
```

- [ ] **Step 2: Substituir o conteúdo de `programacao-a/index.md`**

Mesmo conteúdo da Step 1, trocando **apenas**: o `title` do frontmatter para `"COMP0496 — Programação A"` e o slug na primeira linha Liquid para `where: "slug", "programacao-a"`.

- [ ] **Step 3: Buildar e verificar**

Run: `jekyll build && grep -c "2026-1-T04" _site/algoritmos/index.html && grep -c "2026-1-T05" _site/programacao-a/index.html`
Expected: build sem erro; ambos os greps ≥ 1 (cartas geradas do YAML apontando para as turmas).

- [ ] **Step 4: Commit**

```bash
git add algoritmos/index.md programacao-a/index.md
git commit -m "Gera cartas de turma das disciplinas a partir do YAML"
```

---

### Task 4: Verificação ponta-a-ponta do arquivamento

**Files:**
- Modify (temporário, revertido ao fim): `_data/disciplinas.yml`

**Interfaces:**
- Consumes: tudo das Tasks 1–3.
- Produces: confirmação do critério de sucesso do spec; nenhuma mudança permanente.

- [ ] **Step 1: Arquivar temporariamente a turma de Algoritmos**

Em `_data/disciplinas.yml`, na turma `2026-1-T04`, adicionar a linha:

```yaml
      arquivada: true
```

- [ ] **Step 2: Buildar e verificar o comportamento de arquivada**

Run: `jekyll build && grep -c "COMP0497" _site/index.html; grep -c "2026-1-T04" _site/arquivo/index.html; grep -c "COMP0497" _site/arquivo/index.html; test -f _site/algoritmos/2026-1-T04/index.html && echo URL_OK`
Expected: primeiro grep = 0 (disciplina sem turma ativa some da home); segundo e terceiro ≥ 1 (turma e disciplina aparecem no arquivo); `URL_OK` (página da turma continua existindo).

- [ ] **Step 3: Verificar página de disciplina vazia**

Run: `grep -c "Nenhuma turma neste semestre" _site/algoritmos/index.html`
Expected: `1`.

- [ ] **Step 4: Reverter o flag temporário**

Remover a linha `arquivada: true` adicionada na Step 1.

Run: `git diff --stat _data/disciplinas.yml`
Expected: sem saída (arquivo idêntico ao commitado).

- [ ] **Step 5: Rebuildar no estado final e conferir**

Run: `jekyll build && grep -c "COMP0497" _site/index.html && grep -c "Nenhuma turma arquivada" _site/arquivo/index.html`
Expected: ambos = 1 (home de volta ao normal; arquivo vazio com mensagem).

- [ ] **Step 6: Commit final (apenas o plano, se ainda não commitado)**

```bash
git status --short
```

Expected: árvore limpa (Tasks 1–3 já commitaram tudo; a mudança da Step 1 foi revertida). Se o plano (`docs/superpowers/plans/`) aparecer como não commitado, commitá-lo:

```bash
git add docs/superpowers/plans/2026-08-08-turmas-arquivadas.md
git commit -m "Adiciona plano de implementação de turmas arquivadas"
```
