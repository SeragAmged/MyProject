// import 'dart:io';

// void main() async {
//   final socket = await Socket.connect('192.168.1.10', 80);

//   print('Connected to ESP32');

//   bool on = true;
//   void handleSocketData(List<int> data) {
//     if (data[0] == 51) {
//     socket.write(on?1:0);
//       on = !on;
//     } else {
//       print(String.fromCharCodes(data));
//     }
//   }

//   void handleSocketError(dynamic error) {
//     print('Error: $error');
//     socket.destroy();
//   }

//   void handleSocketClosed() {
//     print('Socket closed');
//     socket.destroy();
//   }

//   socket.listen(
//     handleSocketData,
//     onDone: handleSocketClosed,
//     onError: handleSocketError,

//   );

//   await Future.delayed(Duration(days: 365));
// }

import 'dart:io';

void main() async {
  final String esp32Ip = '192.168.1.7';
  final int esp32Port = 80;

  try {
    final socket = await Socket.connect(esp32Ip, esp32Port);
    print('Connected to ESP32');

    // Send 123 as a test immediately after connecting
    socket.write(3);
    // print('Sent: 123');

    // void handleSocketData(List<int> data) {
    //   print('Received data: ${String.fromCharCodes(data)}');
    //   // Additional logic can be added here if needed
    // }

    // void handleSocketError(dynamic error) {
    //   print('Error: $error');
    //   socket.destroy();
    // }

    // void handleSocketClosed() {
    //   print('Socket closed');
    //   socket.destroy();
    // }

    // socket.listen(
    //   handleSocketData,
    //   onDone: handleSocketClosed,
    //   onError: handleSocketError,
    // );

    // Keep the client running
    await Future.delayed(Duration(days: 365));
  } catch (e) {
    print('Unable to connect to ESP32: $e');
  }
}
