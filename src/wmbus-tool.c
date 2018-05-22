#include "apputils.h"

int main(int argc, char *argv[])
{

    // Initialize working structs and vars

    uint16_t InfoFlag = SHOWALLDETAILS;
    uint8_t  ReturnValue;
    uint16_t Port = 0;
    char     DevicePath[_MAX_PATH] = "";
    uint16_t Mode = RADIOT2;
    int      logging = 0;
    uint16_t wMBUSStick = iM871AIdentifier;
    char     comDeviceName[100] = "/dev/ttyUSB0";
    int      hStick;
    char     CommandlineDatPath[_MAX_PATH];
    int      retval;

    setupConsole();

    ecwMBUSMeter tabMeters[MAXMETER];
    memset(tabMeters, 0, MAXMETER*sizeof(ecwMBUSMeter));
    memset(CommandlineDatPath, 0, _MAX_PATH*sizeof(char));

    // Initialize and open serial port
    hStick = wMBus_OpenDevice(comDeviceName, wMBUSStick);
    printf("Opened device %s: %d\n", comDeviceName, hStick);

    if(hStick <= 0) {
        printf("Could not find iM871A device at %s. Exiting.\n", comDeviceName);
        wMBus_CloseDevice(hStick, wMBUSStick);
        exit(1);
    }

    // Check Stick type (assuming iM871A, AMBER not yet supported here)
    if((APIOK == (retval = wMBus_GetStickId(hStick, wMBUSStick, &ReturnValue, InfoFlag))) && 
            (iM871AIdentifier == ReturnValue)) 
    {
        printf("IMST iM871A Stick found\n");
    } else {
        printf("Could not open device %s (%02x, %d).\n", comDeviceName, ReturnValue, APIOK);
        wMBus_CloseDevice(hStick, wMBUSStick);
    }
    printf("wMBus_getStickId returned %d\n", retval);

    // Get Stick's Radio Mode
    if(APIOK == wMBus_GetRadioMode(hStick, wMBUSStick, &ReturnValue, InfoFlag)) {
        if(InfoFlag > SILENTMODE) {
            printf("wM-BUS %s Mode\n", (ReturnValue == RADIOT2) ? "T2" : "S2");
        }
        if (ReturnValue != Mode)
           wMBus_SwitchMode(hStick, wMBUSStick, (uint8_t) Mode, InfoFlag);
    } else {
        wMBus_CloseDevice(hStick, wMBUSStick);
        ErrorAndExit("wM-Bus Stick not found\n");
    }

    // initialize wM-Bus Stick
    wMBus_InitDevice(hStick, wMBUSStick, InfoFlag);

    /* UpdateMetersonStick(hStick, wMBUSStick, Meters, ecpiwwMeter, InfoFlag); */

    // Test number of slots for AES key table


    // store AES keys on Stick
    //wMBus_AddMeter(handle, stick, iX, &ecpiwwMeter[iX], infoflag);
    
//    unsigned char Filter[sizeof(CMD_SET_AES_KEY_REQ_Arr)];
//    memset(Filter,0,sizeof(CMD_SET_AES_KEY_REQ_Arr));
//    IMST_WriteAESKey(hStick,0,&Filter[3],(uint8_t*) MeterAddr[dwMeter].key);

    // poll and print data, quit when "q" pressed

    // Deinitialize wM-Bus stick

    // Close serial port

    
    wMBus_CloseDevice(hStick, wMBUSStick);

    printf("Goodbye.\n");
    
    return 0;
}
