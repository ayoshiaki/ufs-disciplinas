// ============================================================
// Checkpoint 3 --- a bio vira campo controlado
// Novidade: TextInput com value + onChangeText ligados ao estado.
// ============================================================
import { useState } from 'react';
import { View, Text, Image, TextInput, Pressable, StyleSheet } from 'react-native';

const PERFIL = {
  nome: 'Ada Lovelace',
  usuario: '@ada',
  foto: 'https://picsum.photos/id/1027/200/200',
  bio: 'Estudante de Programação B. Gosto de algoritmos e de café.',
  habilidades: ['JavaScript', 'React Native', 'Flexbox', 'C'],
  seguidores: 128,
};

const LIMITE_BIO = 120;

export default function App() {
  const [curtidas, setCurtidas] = useState(0);
  const [bio, setBio] = useState(PERFIL.bio);

  return (
    <View style={estilos.tela}>
      <View style={estilos.cartao}>

        <View style={estilos.cabecalho}>
          <Image style={estilos.foto} source={{ uri: PERFIL.foto }} />
          <View style={estilos.identidade}>
            <Text style={estilos.nome}>{PERFIL.nome}</Text>
            <Text style={estilos.usuario}>{PERFIL.usuario}</Text>
          </View>
        </View>

        {/* a bio exibida vem do estado, não mais da constante */}
        <Text style={estilos.bio}>{bio}</Text>

        <TextInput
          style={estilos.campoBio}
          value={bio}
          onChangeText={setBio}
          maxLength={LIMITE_BIO}
          multiline
          placeholder="escreva sua bio"
        />
        <Text style={estilos.contador}>{bio.length}/{LIMITE_BIO}</Text>

        <View style={estilos.etiquetas}>
          {PERFIL.habilidades.map((habilidade) => (
            <View key={habilidade} style={estilos.etiqueta}>
              <Text style={estilos.textoEtiqueta}>{habilidade}</Text>
            </View>
          ))}
        </View>

        <Pressable style={estilos.botaoCurtir} onPress={() => setCurtidas((n) => n + 1)}>
          <Text style={estilos.textoCurtir}>
            {curtidas === 1 ? '1 curtida' : `${curtidas} curtidas`}
          </Text>
        </Pressable>

      </View>
    </View>
  );
}

const estilos = StyleSheet.create({
  tela: { flex: 1, justifyContent: 'center', paddingHorizontal: 20, backgroundColor: '#eef1f6' },
  cartao: {
    backgroundColor: '#fff', borderRadius: 16, padding: 20,
    shadowColor: '#000', shadowOpacity: 0.12, shadowRadius: 12,
    shadowOffset: { width: 0, height: 4 }, elevation: 4,
  },
  cabecalho: { flexDirection: 'row', alignItems: 'center' },
  foto: { width: 72, height: 72, borderRadius: 36 },
  identidade: { marginLeft: 14 },
  nome: { fontSize: 20, fontWeight: 'bold', color: '#12263f' },
  usuario: { fontSize: 14, color: '#8896a6', marginTop: 2 },
  bio: { fontSize: 14, color: '#43536b', lineHeight: 20, marginTop: 14 },
  campoBio: {
    minHeight: 60, marginTop: 10, padding: 10, fontSize: 13,
    borderWidth: 1, borderColor: '#c9d2dd', borderRadius: 8,
    textAlignVertical: 'top',
  },
  contador: { fontSize: 11, color: '#8896a6', alignSelf: 'flex-end', marginTop: 4 },
  etiquetas: { flexDirection: 'row', flexWrap: 'wrap', gap: 8, marginTop: 14 },
  etiqueta: {
    backgroundColor: '#e7edf6', borderRadius: 999,
    paddingHorizontal: 10, paddingVertical: 5,
  },
  textoEtiqueta: { fontSize: 12, color: '#2c4a73', fontWeight: '600' },
  botaoCurtir: {
    marginTop: 18, paddingVertical: 12, borderRadius: 10,
    backgroundColor: '#e63946', alignItems: 'center',
  },
  textoCurtir: { color: '#fff', fontWeight: 'bold', fontSize: 15 },
});
