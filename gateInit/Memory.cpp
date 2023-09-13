#include "Memory.h"

String Memory::ReadDataSD(){
  pinMode(pinCS, OUTPUT);
  File dataFile;

  if(SD.begin()){
    Serial.println("SD card ready to use. will read SD.");
  }else{
    Serial.println("SD card failed... Can't read SD.");
    return;
  }

  // Create (or open) a file on the SD card for writing
  dataFile = SD.open("data.txt");
  String result = "";

  // If the file opened successfully, read and print its contents
  if (dataFile) {
    while (dataFile.available()) {
      char data = dataFile.read();
      result += data;
    }

    // Close the file when you're done with it
    dataFile.close();
  } else {
    Serial.println("Error opening data.txt");
  }

  return result;
}

void Memory::WriteDataSD(int number) {
  // Set the CS pin as an output
  pinMode(pinCS, OUTPUT);

  // Initialize SD card
  if (SD.begin(pinCS)) {
    Serial.println("SD card ready to use. will write to SD.");
  } else {
    Serial.println("SD card failed... cant wrtie to SD.");
    return;
  }

  //del
  if (SD.remove("data.txt")) {
    Serial.println("Deleted existing data.txt file.");
  }

  // Create (or open) a file on the SD card for writing
  File dataFile = SD.open("data.txt", FILE_WRITE);

  // If the file opened successfully, write the passed number to it
  if (dataFile) {

    dataFile.println(number);
    
    // Close the file when you're done with it
    dataFile.close();
  } else {
    Serial.println("Error opening data.txt");
  }
}