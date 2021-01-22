#ifndef menu_h
#define menu_h

bool otaProgramming = false;

void executeMenu() {

marcaMenu:
  switch (displayMainMenu()) {
    case 3:  break;
    case 2: marca1: switch (displayModeMain())
      {
            case 2: if(displayWifiMode() == 0){goto marca1;} break;
            case 1: if(displayProtocolMode() == 0){goto marca1;} break;
            case 0: goto marcaMenu; break;
      }break;
    case 1:marca2:
      switch (displayConfigurationMenu())
      {
        case 3:otaProgramming = true; displayOtaProgramming(0); break;
          
        case 2: marca3:
          switch (displayWifiConfig())
          {
            case 3: if (displayWifiName() == 0) {goto marca3;} break;
            case 2: if (displayWifiPassword() == 0) {goto marca3;} break;
            case 1: if (displayLocalIp() == 0) {goto marca3; } break;
            case 0: goto marca2; break;
          }break;
         
        case 1:marca4:
          switch (displayConfigurationProtocol())
          {
            case 2: if (displayWebsocketConfig() == 0){ goto marca4; } break;
            case 1: if (displaySerialConfig() == 0){ ESP.restart(); } break;
            case 0: goto marca2; break;
          }break;
        case 0: goto marcaMenu;
          break;
      }
      break;
  }
}

#endif
