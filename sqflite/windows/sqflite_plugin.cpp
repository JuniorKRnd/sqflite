#include "sqflite_plugin.h"


#include <flutter/method_channel.h>
// ref here https://engine.chinmaygarde.com/flutter__plugin__registrar_8h.html
#include <flutter/plugin_registrar_windows.h>

#include <flutter/standard_method_codec.h>
#include <windows.h>

#include <codecvt>
#include <memory>
#include <sstream>
#include <string>


using flutter::EncodableValue;

void SqflitePluginRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar) {
        // TODO ("Implement an instance class with a registrar method")
    }