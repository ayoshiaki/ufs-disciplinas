# Design: separação de turmas atuais e arquivadas

**Data:** 2026-08-08

## Objetivo

Separar no site as turmas em andamento das turmas de semestres passados: a home
mostra apenas o que está sendo lecionado; uma página `/arquivo` reúne as turmas
encerradas.

## Dados

Em `_data/disciplinas.yml`, cada turma ganha um campo opcional `arquivada: true`.
Ausência do campo significa turma atual. Arquivar uma turma ao fim do semestre é
uma edição de uma linha no YAML — nenhum outro arquivo precisa mudar.

## Páginas

1. **Home (`index.md`)** — as cartas de disciplina listam apenas turmas não
   arquivadas. Disciplinas sem nenhuma turma ativa não aparecem na home. Ao fim
   da página, link "📦 Turmas anteriores →" para `/arquivo`. O contador de
   disciplinas no subtítulo reflete apenas as disciplinas exibidas.
2. **`arquivo/index.md` (nova)** — layout `default`, breadcrumb para a home.
   Lista as turmas com `arquivada: true`, agrupadas por disciplina, com cartas
   no mesmo estilo visual da home, linkando para as páginas de turma existentes
   (ex. `/algoritmos/2026-1-T04`). Disciplinas sem turma arquivada são omitidas.
3. **Páginas de disciplina (`algoritmos/index.md`, `programacao-a/index.md`)** —
   as cartas de turma, hoje hardcoded, passam a ser geradas via Liquid a partir
   de `site.data.disciplinas` (filtrando arquivadas), localizando a disciplina
   pelo `slug`.
4. **Páginas de turma e de aula** — intocadas; URLs preservadas.
5. **`_config.yml`** — adicionar `docs/` ao `exclude:` para que esta
   documentação interna não seja publicada no GitHub Pages.

## Fora de escopo

Makefile, PDFs, tema Beamer e workflow do GitHub Actions não mudam.

## Critério de sucesso

Com `arquivada: true` em uma turma: ela some da home e da página da disciplina,
aparece em `/arquivo`, e sua URL direta continua funcionando. Sem nenhuma turma
arquivada, `/arquivo` existe mas indica que não há turmas anteriores.
