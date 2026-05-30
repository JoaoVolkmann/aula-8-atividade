# 💛 Me Ajuda Aqui

Aplicativo Flutter assistente de voz para idosos, com funcionalidades de:
- 🎤 Reconhecimento de fala
- 🔊 Síntese de fala (text-to-speech)
- 💰 Sistema de PIX simplificado
- 📄 Informações de benefícios
- 📞 Contato com neto

## Funcionalidades

### Menu Principal
- Botões de navegação para PIX, Benefícios e Contato
- Botão de microfone para reconhecimento de voz
- Reconhece comandos como "pix", "benef", "neto", "ligar"

### PIX
- Guia passo a passo para envio de PIX
- Entrada de chave PIX
- Entrada de valor
- Feedback por voz em cada etapa

### Benefícios
- Opções de INSS, Assistencial e Pensão

## Instalação

1. Clone ou copie os arquivos do projeto
2. Na pasta do projeto, execute:
```bash
flutter pub get
```

3. Para rodar o aplicativo:
```bash
flutter run
```

## Permissões Necessárias

### Android (android/app/AndroidManifest.xml)
Adicione as permissões:
```xml
<uses-permission android:name="android.permission.RECORD_AUDIO" />
<uses-permission android:name="android.permission.INTERNET" />
```

### iOS (ios/Runner/Info.plist)
Adicione as configurações:
```xml
<key>NSMicrophoneUsageDescription</key>
<string>Este aplicativo precisa de permissão para usar o microfone</string>
<key>NSSpeechRecognitionUsageDescription</key>
<string>Este aplicativo precisa de permissão para reconhecimento de fala</string>
```

## Dependências

- **flutter_tts**: Para síntese de fala (text-to-speech)
- **speech_to_text**: Para reconhecimento de fala

## Notas de Uso

- O aplicativo fala em português brasileiro (pt-BR)
- Velocidade de fala configurada em 0.4x
- Reconhecimento de voz aguarda 4 segundos antes de parar de escutar
- A imagem na tela inicial vem de uma URL externa
