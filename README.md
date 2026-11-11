# LEO PIANO-
Elaboramos  un piano usando arduino, controlado por un sistema MIDI, para esto utilizaremos un arduino y un sensor de tacto, cada sensor representará una tecla músical, al presionarlo, el sintetizador al que está conectado, emitirá el sonido correspondiente a esa nota. 

El piano permite que los usuarios interactúen de forma intuitiva, tocando diferentes notas en un teclado.La respuesta instantánea al toque genera un aprendizaje activo y el desarrollo de habilidades musicales. El piano hecho con Arduino permite generar diversas tonalidades y melodías. Utiliza un sensor que se conecta a la placa Arduino, donde las frecuencias son controladas a través de un código específico, brindando una experiencia musical única.
Funcionamiento del piano MIDI

El piano utiliza sensores táctiles TTP223B conectados a un Arduino Leonardo. Al tocar un sensor, el Arduino envía una señal MIDI al computador que activa una nota musical en un sintetizador web.

Al mismo tiempo, esa señal MIDI es recibida por Hydra, donde cada nota puede controlar y modificar elementos visuales en tiempo real, como formas, colores, movimientos y efectos.

De esta manera, cada toque produce una respuesta audiovisual: el piano genera sonido y, simultáneamente, interactúa con los visuales de Hydra mediante MIDI.


## Materiales utilizados

| Cantidad | Material | Descripción |
|:---:|---|---|
| 23 | Jumpers macho-hembra | Cables de conexión |
| 5 | Jumpers macho-macho | Cables de conexión |
| 8 | Sensores TTP223B | Sensores táctiles digitales |
| 1 | Protoboard | Placa para conexiones |
| 1 | LED | Diodo emisor de luz |
| 1 | Resistencia | Control de corriente |
| 1 | Arduino Leonardo | Placa microcontroladora |

### Montaje del circuito
https://github.com/DaniPP22/Piano-Arduino-/blob/main/images/images/WhatsApp%20Image%202026-11-09%20at%209.43.51%20AM.jpeg




### SINTETIZADOR ONLINE
https://www.websynths.com/microtonal/


### Codigo Midi-Hydra

navigator.requestMIDIAccess()
    .then(onMIDISuccess, onMIDIFailure);

function onMIDISuccess(midiAccess) {
    console.log(midiAccess);
    var inputs = midiAccess.inputs;
    var outputs = midiAccess.outputs;
    for (var input of midiAccess.inputs.values()){
        input.onmidimessage = getMIDIMessage;
    }
}

function onMIDIFailure() {
    console.log('Could not access your MIDI devices.');
}

//create an array to hold our cc values and init to a normalized value
var cc=Array(128).fill(0.5)

getMIDIMessage = function(midiMessage) {
    var arr = midiMessage.data    
    var index = arr[1]
    //console.log('Midi received on cc#' + index + ' value:' + arr[2])    // uncomment to monitor incoming Midi
    var val = (arr[2]+1)/128.0  // normalize CC values to 0.0 - 1.0
    cc[index]=val
}
