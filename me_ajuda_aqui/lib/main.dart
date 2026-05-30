import 'package:flutter/material.dart';
import 'package:flutter_tts/flutter_tts.dart';
import 'package:speech_to_text/speech_to_text.dart';

void main() {
  runApp(MyApp());
}

/* ===== VOZ ===== */
FlutterTts tts = FlutterTts();
Future falar(String texto) async {
  await tts.setLanguage("pt-BR");
  await tts.setSpeechRate(0.4);
  await tts.speak(texto);
}

/* ===== RECONHECIMENTO ===== */
SpeechToText speech = SpeechToText();

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      home: MenuPage(),
    );
  }
}

/* ================= MENU ================= */
class MenuPage extends StatefulWidget {
  @override
  _MenuPageState createState() => _MenuPageState();
}

class _MenuPageState extends State<MenuPage> {

  bool escutando = false;

  void ouvir() async {

    bool ok = await speech.initialize();

    if (!ok) {
      falar("Erro no microfone");
      return;
    }

    setState(() => escutando = true);

    falar("Pode falar");

    speech.listen(
      localeId: "pt_BR",
      onResult: (result) {

        String fala = result.recognizedWords.toLowerCase();

        if (fala.contains("pix")) {
          Navigator.push(context, MaterialPageRoute(builder: (_) => PixPage()));
        }
        else if (fala.contains("benef")) {
          Navigator.push(context, MaterialPageRoute(builder: (_) => BeneficiosPage()));
        }
        else if (fala.contains("neto") || fala.contains("ligar")) {
          falar("Ligando para seu neto");
          showDialog(
            context: context,
            builder: (_) => AlertDialog(
              content: Text("📞 Ligando para seu neto..."),
            ),
          );
        }
      },
    );

    await Future.delayed(Duration(seconds: 4));
    speech.stop();

    setState(() => escutando = false);
  }

  Widget botao(String texto, Widget? pagina) {
    return Padding(
      padding: EdgeInsets.all(10),
      child: ElevatedButton(
        style: ElevatedButton.styleFrom(minimumSize: Size(300, 60)),
        onPressed: () {
          if (pagina != null) {
            Navigator.push(context, MaterialPageRoute(builder: (_) => pagina));
          }
        },
        child: Text(texto, style: TextStyle(fontSize: 18)),
      ),
    );
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: Text("💛 Me Ajuda Aqui")),
      body: Column(
        mainAxisAlignment: MainAxisAlignment.center,
        children: [

          Image.network(
            "https://i.postimg.cc/6p3bh8cQ/e0525ad9-f973-434b-bced-12c5cd0e65f8.jpg",
            height: 120,
          ),

          botao("💰 Mandar PIX", PixPage()),
          botao("📄 Ver Benefícios", BeneficiosPage()),
          botao("📞 Falar com Neto", null),

          SizedBox(height: 20),

          ElevatedButton(
            onPressed: ouvir,
            style: ElevatedButton.styleFrom(
              backgroundColor: Colors.amber,
              minimumSize: Size(200, 60),
            ),
            child: Text(escutando ? "🎤 Escutando..." : "🎤 Falar"),
          ),
        ],
      ),
    );
  }
}

/* ================= PIX ================= */
class PixPage extends StatefulWidget {
  @override
  _PixPageState createState() => _PixPageState();
}

class _PixPageState extends State<PixPage> {

  int passo = 0;

  List<String> passos = [
    "Vamos enviar um PIX",
    "Abra o aplicativo do banco",
    "Digite a chave PIX",
    "Digite o valor"
  ];

  TextEditingController chave = TextEditingController();
  TextEditingController valor = TextEditingController();

  @override
  void initState() {
    super.initState();
    falar(passos[0]);
  }

  void proximo() {
    if (passo == 2 && chave.text.isEmpty) {
      falar("Digite a chave PIX");
      return;
    }

    if (passo == 3 && valor.text.isEmpty) {
      falar("Digite o valor");
      return;
    }

    setState(() => passo++);

    if (passo < passos.length) {
      falar(passos[passo]);
    } else {
      falar("Operação concluída");
      showDialog(
        context: context,
        builder: (_) => AlertDialog(
          content: Text("✅ Finalizado"),
        ),
      );
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: Text("PIX")),
      body: Column(
        children: [

          SizedBox(height: 20),
          Text(passos[passo]),

          if (passo == 2)
            TextField(controller: chave, decoration: InputDecoration(labelText: "Chave")),

          if (passo == 3)
            TextField(controller: valor, keyboardType: TextInputType.number),

          ElevatedButton(onPressed: proximo, child: Text("Próximo")),
          ElevatedButton(onPressed: () => falar(passos[passo]), child: Text("🔊 Repetir")),

        ],
      ),
    );
  }
}

/* ================= BENEFÍCIOS ================= */
class BeneficiosPage extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    falar("Escolha o benefício");

    return Scaffold(
      appBar: AppBar(title: Text("Benefícios")),
      body: Column(
        children: [

          ElevatedButton(onPressed: () => falar("Abrindo INSS"), child: Text("INSS")),
          ElevatedButton(onPressed: () => falar("Abrindo assistencial"), child: Text("Assistencial")),
          ElevatedButton(onPressed: () => falar("Abrindo pensão"), child: Text("Pensão")),

        ],
      ),
    );
  }
}
