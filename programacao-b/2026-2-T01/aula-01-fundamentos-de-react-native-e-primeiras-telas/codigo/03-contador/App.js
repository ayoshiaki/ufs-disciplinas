// Contador: o menor programa que mostra o estado mudando a tela.
import { useState } from 'react';
import { View, Text, Pressable, StyleSheet } from 'react-native';

export default function App() {
  // useState devolve um par: o valor atual e a função que o troca.
  const [contagem, setContagem] = useState(0);

  return (
    <View style={estilos.tela}>
      <Text style={estilos.numero}>{contagem}</Text>

      <View style={estilos.linha}>
        <Pressable style={estilos.botao} onPress={() => setContagem(contagem - 1)}>
          <Text style={estilos.textoBotao}>-1</Text>
        </Pressable>

        {/* Forma funcional: use quando o novo valor depende do anterior */}
        <Pressable style={estilos.botao} onPress={() => setContagem((n) => n + 1)}>
          <Text style={estilos.textoBotao}>+1</Text>
        </Pressable>
      </View>

      <Pressable onPress={() => setContagem(0)}>
        <Text style={estilos.zerar}>zerar</Text>
      </Pressable>
    </View>
  );
}

const estilos = StyleSheet.create({
  tela: { flex: 1, justifyContent: 'center', alignItems: 'center', backgroundColor: '#fff' },
  numero: { fontSize: 72, fontWeight: 'bold', color: '#12263f' },
  linha: { flexDirection: 'row', gap: 16, marginTop: 24 },
  botao: {
    width: 72, height: 56, borderRadius: 10, backgroundColor: '#12263f',
    justifyContent: 'center', alignItems: 'center',
  },
  textoBotao: { color: '#fff', fontSize: 20, fontWeight: 'bold' },
  zerar: { marginTop: 20, color: '#5b6b7f', textDecorationLine: 'underline' },
});
