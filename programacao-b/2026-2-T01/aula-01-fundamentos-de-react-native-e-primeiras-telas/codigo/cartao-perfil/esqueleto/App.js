// ============================================================
// Cartão de perfil --- ponto de partida
// Cole em snack.expo.dev, leia o QR com o Expo Go e trabalhe aqui.
// Os TODO marcam o que é seu. Não apague os dados abaixo.
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

export default function App() {
  // CHECKPOINT 2 --- TODO: estado das curtidas, começando em 0
  // CHECKPOINT 3 --- TODO: estado da bio, começando em PERFIL.bio
  // CHECKPOINT 4 --- TODO: estado booleano "seguindo", começando em false

  return (
    <View style={estilos.tela}>
      <View style={estilos.cartao}>

        {/* CHECKPOINT 1 --- TODO: cabeçalho em linha:
            a foto (redonda, 72x72) à esquerda; ao lado, em coluna,
            o nome e o usuário. */}

        {/* CHECKPOINT 3 --- TODO: trocar o texto fixo pelo estado da bio,
            e acrescentar um TextInput controlado que a edita. */}
        <Text style={estilos.bio}>{PERFIL.bio}</Text>

        {/* CHECKPOINT 1 --- TODO: as habilidades, uma etiqueta por item,
            geradas com map. Cada elemento da lista precisa de key. */}

        {/* CHECKPOINT 2 --- TODO: botão de curtir mostrando o total.
            CHECKPOINT 4 --- TODO: botão Seguir / Seguindo ao lado. */}

      </View>
    </View>
  );
}

const estilos = StyleSheet.create({
  tela: { flex: 1, justifyContent: 'center', paddingHorizontal: 20, backgroundColor: '#eef1f6' },
  cartao: {
    backgroundColor: '#fff', borderRadius: 16, padding: 20,
    // sombra leve; não precisa entender agora
    shadowColor: '#000', shadowOpacity: 0.12, shadowRadius: 12,
    shadowOffset: { width: 0, height: 4 }, elevation: 4,
  },
  bio: { fontSize: 14, color: '#43536b', lineHeight: 20, marginTop: 14 },
  // TODO: crie aqui os estilos que os seus checkpoints pedirem.
});
