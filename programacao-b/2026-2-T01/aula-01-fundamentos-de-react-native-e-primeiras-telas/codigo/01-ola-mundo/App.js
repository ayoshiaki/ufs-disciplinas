// Olá mundo --- cole isto em snack.expo.dev e leia o QR code com o Expo Go.
import { View, Text, StyleSheet } from 'react-native';

export default function App() {
  return (
    <View style={estilos.tela}>
      <Text style={estilos.titulo}>Olá, COMP0511!</Text>
      <Text style={estilos.legenda}>Este texto está rodando no seu celular.</Text>
    </View>
  );
}

const estilos = StyleSheet.create({
  tela: {
    flex: 1,                   // ocupa toda a altura disponível
    justifyContent: 'center',  // centraliza no eixo principal (vertical)
    alignItems: 'center',      // centraliza no eixo cruzado (horizontal)
    backgroundColor: '#f2f4f8',
  },
  titulo: { fontSize: 28, fontWeight: 'bold', color: '#12263f' },
  legenda: { fontSize: 14, color: '#5b6b7f', marginTop: 8 },
});
