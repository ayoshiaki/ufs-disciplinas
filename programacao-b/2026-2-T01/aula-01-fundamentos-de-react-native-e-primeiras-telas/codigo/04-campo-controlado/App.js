// Campo controlado: o estado manda no que aparece dentro do TextInput.
import { useState } from 'react';
import { View, Text, TextInput, StyleSheet } from 'react-native';

export default function App() {
  const [nome, setNome] = useState('');

  return (
    <View style={estilos.tela}>
      <Text style={estilos.rotulo}>Seu nome</Text>

      <TextInput
        style={estilos.campo}
        placeholder="digite aqui"
        value={nome}              // o que aparece vem do estado
        onChangeText={setNome}    // cada tecla devolve o texto novo ao estado
      />

      <Text style={estilos.saida}>
        {nome.length === 0 ? 'Ainda não digitou nada.' : `Olá, ${nome}!`}
      </Text>
      <Text style={estilos.contador}>{nome.length}/30 caracteres</Text>
    </View>
  );
}

const estilos = StyleSheet.create({
  tela: { flex: 1, justifyContent: 'center', paddingHorizontal: 32, backgroundColor: '#fff' },
  rotulo: { fontSize: 14, color: '#5b6b7f', marginBottom: 6 },
  campo: {
    height: 48, paddingHorizontal: 12, fontSize: 16,
    borderWidth: 1, borderColor: '#c9d2dd', borderRadius: 8,
  },
  saida: { fontSize: 22, fontWeight: 'bold', marginTop: 24, color: '#12263f' },
  contador: { fontSize: 12, color: '#8896a6', marginTop: 4 },
});
