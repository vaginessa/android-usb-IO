#define VENDOR_ID               0x16C0
#define PRODUCT_ID              0x0480
#define RAWHID_USAGE_PAGE       0xFFAB  // recommended: 0xFF00 to 0xFFFF
#define RAWHID_USAGE            0x0200  // recommended: 0x0100 to 0xFFFF

#define RAWHID_TX_SIZE          64      // transmit packet size
#define RAWHID_TX_INTERVAL      2       // max # of ms between transmit packets
#define RAWHID_RX_SIZE          64      // receive packet size
#define RAWHID_RX_INTERVAL      8       // max # of ms between receive packets


byte rxBuffer[64];
byte txBuffer[64];
void setup() {
  pinMode(13, OUTPUT);
}


void loop() {
  int n = RawHID.recv(rxBuffer, 0);  //Receive data immediately if available
  if (n>0) {
    //Data was received from host.
    //Updated LED state
    if(rxBuffer[0] > 0) {
      digitalWrite(13, HIGH);
    } else {
      digitalWrite(13, LOW);
    }
    //Do something else with the data later
  }
}
