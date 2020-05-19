#ifndef PLUGINS_SQFLITE_WINDOWS_SQFLITE_PLUGIN_H_
#define PLUGINS_SQFLITE_WINDOWS_SQFLITE_PLUGIN_H_

// A plugin to allow sqlite ops in windows

#include <flutter_plugin_registrar.h>


#ifdef FLUTTER_PLUGIN_IMPL
#define FLUTTER_PLUGIN_EXPORT __declspec(dllexport)
#else
#define FLUTTER_PLUGIN_EXPORT __declspec(dllimport)
#endif


#if defined(__cplusplus)
extern "C" {
#endif


FLUTTER_PLUGIN_EXPORT void SqflitePluginRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar);


#if defined(__cplusplus)
}  // extern "C"
#endif

#endif      // end of PLUGINS_SQFLITE_WINDOWS_SQFLITE_PLUGIN_H_