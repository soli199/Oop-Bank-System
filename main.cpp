#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsBankClient.h"
#include "clsLoginScreen.h"
#include "clsMainScreen.h"
#include <iomanip>
#include <iostream>

int main() {
  
  while (true)

  {
    if(!clsLoginScreen::ShowLoginScreen())
break;
  }
}