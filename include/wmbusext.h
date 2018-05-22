#ifndef WMBUSEXT_H
#define WMBUSEXT_H

#define SILENTMODE     0
#define SHOWDETAILS    1
#define SHOWALLDETAILS 2

#define ALLOW_READ_AES_KEY  1

#define _MAX_PATH 275

//Modes
#define RADIOT2     4
#define RADIOS2     2

#define AES_KEYLENGHT_IN_BYTES     16
#define iM871AIdentifier           0x33
#define iAMB8465Identifier         0x27
#define iAMB8665Identifier         0x53

//Returns
#define APIERROR   (-1)
#define APIOK      0

//METERS
#define METER_ELECTRICITY          0x02
#define METER_GAS                  0x03
#define METER_WATER                0x07

#define PACKET_WAS_ENCRYPTED       0x01
#define PACKET_WAS_NOT_ENCRYPTED   0x02
#define PACKET_IS_ENCRYPTED        0x04
#define PACKET_DECRYPTIONERROR     0x08

#pragma pack(push,1)
typedef struct _WMBUS_METER {
    uint16_t  manufacturerID;
    uint32_t  ident;
    uint8_t   version;
    uint8_t   type;
    uint8_t   key[AES_KEYLENGHT_IN_BYTES];
} ecwMBUSMeter, *pecwMBUSMeter;
#pragma pack(pop)

#define RFDATA_ENCRYPTED 0x01
#define RFDATA_NOT_ENCRYPTED 0x02

typedef struct _RF_DATA {
    uint32_t time;      // UNIX epoch time
    uint32_t value;     // OCR value in integer
    int8_t   exp;       // OCR value exponent
    uint8_t  accNo;     // RF packet access number, should be ascending and wraps
    int8_t   rssiDBm;   // rssi in dbm
    uint8_t  pktInfo;   // EC packet info
    uint8_t  utcnt_pic;   // Unique transmission counter (OCR picture count)
    uint8_t  utcnt_tx;    // Unique transmission counter (tx count)
    uint8_t  status;      // wMbus Status
    uint16_t configWord;  // wMbus ConfigWord
    uint32_t mbusID;      // MBus ID (8 BCD)
    bool valDuringErrState; // valDuringErrState: True when OCR could not be done, e.g. when SA is de-mounted, and ocr is repeated by last valid value (See "Value during error state" in M-Bus spec, coded in DIF[5:4])
} ecMBUSData, *psecMBUSData;





//wMBus handling
int           wMBus_OpenDevice(   char* device, uint16_t stick);
int           wMBus_CloseDevice(  int handle, uint16_t stick);
int           wMBus_GetStickId(   int handle, uint16_t stick, uint8_t* ID, uint16_t infoflag);

unsigned long wMBus_InitDevice(   int handle, uint16_t stick, uint16_t infoflag);

unsigned long wMBus_SwitchMode(   int handle, uint16_t stick, uint8_t Mode, uint16_t infoflag);
unsigned long wMBus_GetRadioMode( int handle, uint16_t stick, uint8_t* Mode, uint16_t infoflag);
unsigned long wMBus_AddMeter(     int handle, uint16_t stick, uint8_t slot, 
                                  pecwMBUSMeter NewMeter, uint16_t infoflag);
int           wMBus_RemoveMeter(  int Index);
unsigned long wMBus_GetData4Meter(int Index, psecMBUSData data);

unsigned long wMBus_GetMeterList();
unsigned long wMBus_GetMeterDataList();

bool          wMBus_AddAESKey(    int handle, uint16_t stick, uint8_t slot, uint8_t *key);
bool          wMBus_WriteAESKey(  uint32_t ident, uint8_t *key);
bool          wMBus_ReadAESKey(   uint32_t ident, uint8_t *key);

#endif
