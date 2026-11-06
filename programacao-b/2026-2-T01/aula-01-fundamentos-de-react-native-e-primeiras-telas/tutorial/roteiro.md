# Fundamentos de React Native — roteiro prático

**COMP0511 — Programação B · DCOMP/UFS**\
Prof. Dr. André Yoshiaki Kashiwabara — andreyoshiaki@dcomp.ufs.br

Este roteiro acompanha os slides. Tudo aqui roda no navegador e no seu celular:
não há nada para instalar no computador.

## Objetivos

Ao final desta aula você será capaz de:

- explicar por que o `<Text>` do React Native vira um componente nativo do Android ou do iOS;
- escrever arrow functions, desestruturar objetos e vetores e transformar listas com `map`;
- ler e escrever JSX, criar um componente e passar dados por props;
- montar uma tela com `View`, `Text`, `Image`, `TextInput` e `Pressable`, estilizada com `StyleSheet` e posicionada com Flexbox;
- usar `useState` para que a tela reaja ao toque e ao que o usuário digita.

## Antes de começar

1. No **celular**: instale o aplicativo **Expo Go** (Play Store ou App Store).
2. No **computador**: abra <https://snack.expo.dev> em uma aba nova.
3. Na barra da direita do Snack, escolha **My Device**. Vai aparecer um QR code.
4. Abra o Expo Go e leia o QR code. No iPhone, use a câmera do sistema.
5. Guarde a URL que o Snack gerou — é nela que o seu trabalho de hoje vai crescer.

> **Se a rede bloquear a conexão:** use o botão **Web** do próprio Snack. A tela
> roda no navegador. Você perde o celular de verdade, mas nenhum conceito da aula.

---

## 1. O JavaScript que a tela exige

### Arrow functions

Em JavaScript, funções são valores: dá para guardá-las em variáveis e passá-las
como argumento — que é exatamente o que um botão precisa receber.

```js
function dobro(x) {        // forma tradicional
  return x * 2;
}

const dobro = (x) => x * 2;   // a mesma coisa; sem chave, o return é implícito

const saudacao = (nome) => {  // com chave, volta o bloco e o return explícito
  const texto = 'Olá, ' + nome;
  return texto;
};
```

### Desestruturação

Desestruturação é uma atribuição em que o lado esquerdo imita o formato do dado: cada variável recebe o campo de mesmo nome (objeto) ou o valor na mesma posição (vetor).

```js
const aluno = { nome: 'Ada', curso: 'Programação B', nota: 9.5 };

const { nome, nota } = aluno;       // tira campos de dentro do objeto
const [a, b] = [10, 20];            // em vetores, por posição
```

A forma de vetor é a que o `useState` usa: `const [valor, setValor] = useState(0)`.

### `map`

```js
const habilidades = ['JavaScript', 'React Native', 'Flexbox'];

const tamanhos = habilidades.map((h) => h.length);   // [10, 12, 7]
```

**Antes de rodar, escreva a sua resposta:** quanto vale `resultado`?

```js
const notas = [7, 5, 9, 4];
const resultado = notas.map((n) => {
  n >= 6;
});
```

<details>
<summary>Confira depois de responder</summary>

`[undefined, undefined, undefined, undefined]`. A chave depois da seta abre um
bloco de comandos, e bloco de comandos exige `return`. Corrija de uma das duas formas:

```js
notas.map((n) => { return n >= 6; });
notas.map((n) => n >= 6);
```
</details>

### JSX, componente e props

```jsx
// componente = função com nome MAIÚSCULO que devolve JSX
function Saudacao({ nome, horario }) {          // props chegam como um objeto
  return <Text>Bom {horario}, {nome}!</Text>;
}

<Saudacao nome="Ada" horario="dia" />           // quem chama decide os valores
```

Quatro regras de JSX que sempre pegam:

1. chaves `{ }` entram em modo JavaScript;
2. só pode haver **um** elemento raiz;
3. toda tag fecha, inclusive as vazias: `<Image source={foto} />`;
4. estilo é objeto, não string: `style={{ fontSize: 20 }}`.

---

## 2. A primeira tela

Apague o conteúdo do `App.js` do Snack e cole o arquivo
[`codigo/01-ola-mundo/App.js`](../codigo/01-ola-mundo/App.js):

```jsx
import { View, Text, StyleSheet } from 'react-native';

export default function App() {
  return (
    <View style={estilos.tela}>
      <Text style={estilos.titulo}>Olá, COMP0511!</Text>
    </View>
  );
}

const estilos = StyleSheet.create({
  tela: { flex: 1, justifyContent: 'center', alignItems: 'center' },
  titulo: { fontSize: 28, fontWeight: 'bold' },
});
```

### Tarefa 1 — 5 minutos

1. Ponha o código acima para rodar no seu aparelho.
2. Troque o texto pelo seu próprio nome.
3. Mude `fontSize` para `48` e veja a tela recarregar sozinha.
4. **Apague a linha `flex: 1`.** Para onde o texto foi? Por quê?

> `justifyContent` distribui o conteúdo *no espaço que a caixa tem*. Sem `flex: 1`
> a `View` encolhe até caber no texto — e não sobra espaço para distribuir.

### Quando não funciona

| Sintoma | Causa provável |
|---|---|
| O QR code não conecta | Celular e computador em redes diferentes — use **Web** |
| Tela branca, sem erro | Faltou `export default` antes de `function App` |
| `Text strings must be rendered within a <Text>` | Texto solto dentro de uma `View` |
| A imagem não aparece | `Image` com `uri` exige `width` e `height` no estilo |

---

## 3. Componentes, estilo e Flexbox

| Componente | Equivale a | Para que serve |
|---|---|---|
| `View` | `<div>` | caixa: agrupa, posiciona, recebe cor e borda |
| `Text` | `<p>` | todo texto visível — nada de texto solto |
| `Image` | `<img>` | imagem local ou vinda de uma URL |
| `TextInput` | `<input>` | entrada de texto do usuário |
| `Pressable` | `<button>` | qualquer área que reage ao toque |

Rode [`codigo/02-componentes-e-estilo/App.js`](../codigo/02-componentes-e-estilo/App.js)
e experimente:

- troque `flexDirection: 'row'` do estilo `linha` para `'column'`;
- em `tela`, troque `alignItems: 'center'` por `'flex-start'` e depois `'flex-end'`;
- acrescente `justifyContent: 'space-between'` em `linha`.

As três propriedades que resolvem quase todo layout:

- **`flexDirection`** escolhe o eixo principal (`'column'` é o padrão no React Native);
- **`justifyContent`** distribui no eixo principal;
- **`alignItems`** alinha no eixo cruzado.

Diferenças em relação ao CSS da web: o padrão é `column` (e não `row`), `flex` é um
número só, não há unidades (`px`, `%`) e as propriedades usam `camelCase`
(`backgroundColor`, não `background-color`).

---

## 4. Telas que reagem: `useState`

**Antes de rodar, escreva a sua resposta:** você toca cinco vezes no botão.
O que a tela mostra?

```jsx
export default function App() {
  let contagem = 0;
  return (
    <View>
      <Text>{contagem}</Text>
      <Pressable onPress={() => { contagem = contagem + 1; }}>
        <Text>somar 1</Text>
      </Pressable>
    </View>
  );
}
```

<details>
<summary>Confira depois de responder</summary>

Zero, sempre zero. A variável muda na memória, mas ninguém pede para redesenhar
a tela; e se algo redesenhar, a função `App` roda de novo e `contagem` volta a `0`.
Falta um mecanismo que **lembre** o valor entre as renderizações e **avise** que a
tela mudou. Esse mecanismo é o `useState`.
</details>

```js
const [contagem, setContagem] = useState(0);
//     |            |                    +-- valor inicial (só na 1ª vez)
//     |            +----------- troca o valor E pede um novo desenho
//     +------------------------ valor atual, válido nesta renderização
```

Rode os dois exemplos e leia o código linha a linha:

- [`codigo/03-contador/App.js`](../codigo/03-contador/App.js) — contador;
- [`codigo/04-campo-controlado/App.js`](../codigo/04-campo-controlado/App.js) — campo controlado.

No campo controlado, o `TextInput` não guarda nada: `value={nome}` faz ele mostrar
o estado, e `onChangeText={setNome}` avisa quando o usuário pede uma mudança.

### Três armadilhas

```js
setContagem(contagem + 1);
console.log(contagem);          // 1. ainda o valor ANTIGO

setContagem((n) => n + 1);      // 2. quando o novo valor depende do antigo

lista.push('novo');             // 3. ERRADO: React não percebe a mudança
setLista([...lista, 'novo']);   //    CERTO: um vetor novo
```

---

## 5. Tarefa 2 — o cartão de perfil (atividade principal)

Trabalhe em duplas, no mesmo Snack, partindo de
[`codigo/cartao-perfil/esqueleto/App.js`](../codigo/cartao-perfil/esqueleto/App.js).
**Cada checkpoint tem que rodar no celular antes de você começar o próximo.**

### Checkpoint 1 — o cartão estático

- cabeçalho em linha: foto redonda de 72×72 à esquerda; ao lado, em coluna, o nome e o usuário;
- a bio abaixo;
- as habilidades como etiquetas, uma por item do vetor, geradas com `map`.

Dicas: `flexDirection: 'row'` + `alignItems: 'center'` no cabeçalho;
`borderRadius: 36` para uma foto de 72 de lado; cada elemento produzido por `map`
precisa de uma prop `key` única.

### Checkpoint 2 — o contador de curtidas

- um `Pressable` no rodapé do cartão mostrando `0 curtidas`;
- cada toque soma 1;
- o texto concorda em número: `1 curtida`, `2 curtidas`.

Use a forma funcional: `setCurtidas((n) => n + 1)`.

### Checkpoint 3 — a bio vira campo controlado

- crie um estado `bio` iniciado com `PERFIL.bio`;
- o `<Text>` da bio passa a mostrar o estado, não mais a constante;
- acrescente um `TextInput` com `value={bio}` e `onChangeText={setBio}`;
- mostre um contador `N/120` abaixo do campo.

Ao digitar, o texto do cartão muda junto — é o mesmo estado em dois lugares.

### Checkpoint 4 — Seguir / Seguindo

- estado booleano `seguindo`, começando em `false`;
- o botão mostra `Seguir` ou `Seguindo` e troca de cor
  (`style={[estilos.botaoSeguir, seguindo && estilos.botaoSeguindo]}`);
- o total de seguidores sobe 1 quando você está seguindo.

**Atenção ao último item:** o total de seguidores **não** é um estado novo.
Ele se calcula a partir de `seguindo`:

```js
const seguidores = seguindo ? PERFIL.seguidores + 1 : PERFIL.seguidores;
```

Estado duplicado é fonte de inconsistência: dois lugares para atualizar, um deles
esquecido.

---

## 6. Desafio para casa

Transforme o cartão de perfil em uma **lista de contatos**:

1. extraia um componente `Cartao` que receba `nome`, `usuario`, `foto` e
   `habilidades` por props;
2. monte um vetor com **quatro** pessoas e renderize os quatro cartões com `map`;
3. cada cartão mantém o **próprio** contador de curtidas — curtir um não pode
   afetar os outros;
4. acrescente um `TextInput` no topo que filtra os cartões pelo nome.

Pergunta que decide o item 3: onde deve morar o estado das curtidas — no `App`
ou dentro do `Cartao`?

Dica para o item 4: `lista.filter((p) => p.nome.toLowerCase().includes(busca.toLowerCase()))`.

---

## Referências

- Eisenman, B. *Learning React Native*. 2. ed. O'Reilly, 2017 — cap. 1 (panorama) e cap. 5 (estilo).
- Flanagan, D. *JavaScript: The Definitive Guide*. 7. ed. O'Reilly, 2020 — §3.10, §7.8.1, §8.1.3.
- Banks, A.; Porcello, E. *Learning React*. 2. ed. O'Reilly, 2020 — cap. 5 (JSX) e cap. 6 (estado).
- React Native Docs — <https://reactnative.dev/docs/getting-started>
- React Docs — <https://react.dev/learn>
- Expo Docs — <https://docs.expo.dev/>

A lista completa, com dados bibliográficos, está em [`../referencias.bib`](../referencias.bib).
