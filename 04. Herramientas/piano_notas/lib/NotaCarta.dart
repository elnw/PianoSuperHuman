import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:flutter/painting.dart';
import 'dart:math';
import 'package:swipe_stack/swipe_stack.dart';

class NotaCarta extends StatefulWidget{
  final _notas = <String>['A','B','C','D','E','F','G'];
  final _cantidadGenerar = 5;


  Random _random = new Random();

  @override
  NotaCartaEstado createState() => NotaCartaEstado();

  String ObtenerNotaAleatoriamente(){
    return _notas[_random.nextInt(_notas.length)];
  }

}

class NotaCartaEstado extends State<NotaCarta>{
  List<SwiperItem> notasUsar = List<SwiperItem>();

  void llenarNotasUsar(){
    for(int i=0;i<widget._cantidadGenerar;i++){
      notasUsar.add(SwiperItem(
        builder: (SwiperPosition position, double progress){
            return Material(
              elevation: 4.0,
              borderRadius: BorderRadius.all(Radius.circular(6)),
              child: Container(
                child: Center(
                  child: Text(
                    widget.ObtenerNotaAleatoriamente(),
                    textAlign: TextAlign.center,
                    style: TextStyle(
                        fontSize: min(MediaQuery.of(context).size.width, MediaQuery.of(context).size.height) * 0.6,
                        fontWeight: FontWeight.bold
                    ),
                  ),
                )
              ),
            );
        }
      ));
    }
  }

  @override
  void initState() {
    super.initState();
    llenarNotasUsar();
  }

  @override
  Widget build(BuildContext context) {
    return Container(
      padding: EdgeInsets.symmetric(vertical: 16.0, horizontal: 16.0),
      width: MediaQuery.of(context).size.width*0.8,
      height: MediaQuery.of(context).size.height*0.8,
      decoration: BoxDecoration(
        borderRadius: BorderRadius.all(Radius.circular(10.0))
      ),
      child: SwipeStack(
        children: notasUsar,
        visibleCount: 4,
        translationInterval: 6,
        stackFrom: StackFrom.Left,
        scaleInterval: 0.1,
        onSwipe: (int index, SwiperPosition position){
          if(index == 2){
            setState(() {
              llenarNotasUsar();
            }

          );
          }
        },
      ),
    );

  }

}