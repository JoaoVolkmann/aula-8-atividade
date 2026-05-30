## 🚀 Guia de Uso do Projeto

Seu projeto Flutter está organizado e pronto para rodar!

### Estrutura do Projeto

```
me_ajuda_aqui/
├── lib/
│   └── main.dart              # Código principal do aplicativo
├── android/                   # Configurações Android
├── ios/                       # Configurações iOS
├── pubspec.yaml               # Dependências do projeto
├── README.md                  # Documentação
└── SETUP.md                   # Este arquivo
```

### ⚡ Primeiros Passos

1. **Instale as dependências:**
   ```bash
   flutter pub get
   ```

2. **Conecte um dispositivo ou emulador:**
   ```bash
   flutter devices
   ```

3. **Execute o aplicativo:**
   ```bash
   flutter run
   ```

### 📱 Funcionalidades Principais

#### Menu Principal
- **Botões de Navegação:** Acesse PIX, Benefícios e Contato
- **Botão de Microfone:** Ativa o reconhecimento de voz
- **Comandos de Voz Reconhecidos:**
  - "pix" → Vai para página PIX
  - "benef" → Vai para página Benefícios
  - "neto" ou "ligar" → Simula ligação para neto

#### Página PIX
- Guia passo a passo com feedback por voz
- 4 etapas: Apresentação → Abrir app bancário → Entrada de chave → Entrada de valor
- Validação de campos
- Botões para avançar e repetir instruções

#### Página Benefícios
- Opções de INSS, Assistencial e Pensão
- Feedback por voz ao selecionar

### ⚙️ Configurações e Permissões

#### Android
- ✅ `RECORD_AUDIO` - Para microfone
- ✅ `INTERNET` - Para carregar imagem da URL

#### iOS
- ✅ Microfone
- ✅ Reconhecimento de Fala

### 🔊 Customizações Disponíveis

No `lib/main.dart`, você pode ajustar:

```dart
// Velocidade de fala (0.4 = 40%)
await tts.setSpeechRate(0.4);

// Idioma
await tts.setLanguage("pt-BR");

// Tempo de escuta (em segundos)
await Future.delayed(Duration(seconds: 4));
```

### 🐛 Troubleshooting

**Erro com permissões no Android:**
- Execute: `flutter clean`
- Execute: `flutter run`

**Erro com imagem da URL:**
- Verifique sua conexão com internet
- A URL pode ter expirado, substitua por outra em `Image.network()`

**Reconhecimento de voz não funciona:**
- Verifique as permissões no dispositivo
- Certifique-se que o microfone está ativo
- Tente reiniciar o aplicativo

### 📦 Dependências Utilizadas

- **flutter_tts:** Síntese de texto em fala
- **speech_to_text:** Reconhecimento de fala

### 📝 Notas Importantes

1. O app é otimizado para **português brasileiro-BR)**
2. Todas as vozes são em português
3. A velocidade de fala é reduzida (0.4x) para melhor compreensão
4. O reconhecimento aguarda 4 segundos antes de parar

### 🎯 Próximos Passos

Para melhorar o app, você pode:
- Separar o código em múltiplos arquivos
- Criar um serviço de fala reusável
- Adicionar mais funcionalidades de negócio
- Implementar persistência de dados
- Adicionar autenticação

### 📞 Suporte

Para questões sobre as dependências:
- [flutter_tts](https://pub.dev/packages/flutter_tts)
- [speech_to_text](https://pub.dev/packages/speech_to_text)
