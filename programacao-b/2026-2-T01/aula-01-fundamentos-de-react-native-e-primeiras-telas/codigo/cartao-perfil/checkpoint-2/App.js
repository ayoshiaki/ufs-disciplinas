// ============================================================
// Checkpoint 2 --- o cartão ganha estado: contador de curtidas
// Novidade em relação ao checkpoint 1: useState + Pressable.
// ============================================================
import { useState } from 'react';
import { View, Text, Image, Pressable, StyleSheet } from 'react-native';

const PERFIL = {
  nome: 'Ada Lovelace',
  usuario: '@ada',
  foto: 'https://picsum.photos/id/1027/200/200',
  bio: 'Estudante de Programação B. Gosto de algoritmos e de café.',
  habilidades: ['JavaScript', 'React Native', 'Flexbox', 'C'],
  seguidores: 128,
};

export default function App() {
  const [curtidas, setCurtidas] = useState(0);

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

        <Text style={estilos.bio}>{PERFIL.bio}</Text>

        <View style={estilos.etiquetas}>
          {PERFIL.habilidades.map((habilidade) => (
            <View key={habilidade} style={estilos.etiqueta}>
              <Text style={estilos.textoEtiqueta}>{habilidade}</Text>
            </View>
          ))}
        </View>

        <Pressable
          style={estilos.botaoCurtir}
          onPress={() => setCurtidas((n) => n + 1)}
        >
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
