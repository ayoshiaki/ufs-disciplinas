// Catálogo mínimo: View, Text, Image, TextInput, Pressable.
// Nada aqui guarda estado ainda --- o campo digita e o botão não reage.
import { View, Text, Image, TextInput, Pressable, StyleSheet } from 'react-native';

export default function App() {
  return (
    <View style={estilos.tela}>
      <Text style={estilos.titulo}>Catálogo de componentes</Text>

      {/* Image remota EXIGE width e height no estilo */}
      <Image
        style={estilos.foto}
        source={{ uri: 'https://picsum.photos/id/1005/200/200' }}
      />

      <TextInput style={estilos.campo} placeholder="Digite seu nome" />

      <Pressable
        style={estilos.botao}
        onPress={() => console.log('O botão foi tocado')}
      >
        <Text style={estilos.textoBotao}>Tocar aqui</Text>
      </Pressable>

      {/* Uma linha: flexDirection 'row' troca o eixo principal */}
      <View style={estilos.linha}>
        <View style={[estilos.quadrado, { backgroundColor: '#e63946' }]} />
        <View style={[estilos.quadrado, { backgroundColor: '#457b9d' }]} />
        <View style={[estilos.quadrado, { backgroundColor: '#2a9d8f' }]} />
      </View>
    </View>
  );
}

const estilos = StyleSheet.create({
  tela: { flex: 1, alignItems: 'center', paddingTop: 64, backgroundColor: '#fff' },
  titulo: { fontSize: 22, fontWeight: 'bold', marginBottom: 16 },
  foto: { width: 120, height: 120, borderRadius: 60 },
  campo: {
    width: 240, height: 44, marginTop: 20, paddingHorizontal: 12,
    borderWidth: 1, borderColor: '#c9d2dd', borderRadius: 8,
  },
  botao: {
    marginTop: 16, paddingVertical: 12, paddingHorizontal: 24,
    backgroundColor: '#12263f', borderRadius: 8,
  },
  textoBotao: { color: '#fff', fontWeight: 'bold' },
  linha: { flexDirection: 'row', gap: 12, marginTop: 24 },
  quadrado: { width: 56, height: 56, borderRadius: 8 },
});
