import 'package:flutter/material.dart';
import 'package:pianonotas/NotaCarta.dart';

void main() {
  runApp(NotasPiano());
}

class NotasPiano extends StatelessWidget{

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Notas de piano',
      home: NotaCarta(),
    );

  }

}



