#include <EEPROM.h>

int nadrr;
void writeString(char add, String data);
String read_String(char add);
void setup() {

  String data = "jesuisun_vr41_mdfd7@2uif1flkdhsgshglqhdmlkjhgqlkjfdjesuislongmaisfdspofydsouqyfds";
  String data2 = "foobarpute";
  Serial.begin(9600);
  //writeString(0, data);
  delay(100);
  nadrr = data.length() + 2;
  Serial.println(data.length());
  //writeString(nadrr, data2);
  delay(10);
}

void loop() {
  String recivedData;
  recivedData = read_String(0);
  Serial.print("1    ");
  Serial.println(recivedData);

  delay(10);
  Serial.print("2   ");
  recivedData = read_String(nadrr);
  Serial.println(recivedData);
  delay(10);

}

void writeString(char add, String data)
{
  int _size = data.length();
  int i;
  for (i = 0; i < _size; i++)
  {
    EEPROM.write(add + i, data[i]);
  }
  EEPROM.write(add + _size, '\0'); //Add termination null character for String Data
}


String read_String(char add)
{
  int i;
  char data[100]; //Max 100 Bytes
  int len = 0;
  unsigned char k;
  k = EEPROM.read(add);
  while (k != '\0' && len < 500) //Read until null character
  {
    k = EEPROM.read(add + len);
    data[len] = k;
    len++;
  }
  data[len] = '\0';
  return String(data);
}
