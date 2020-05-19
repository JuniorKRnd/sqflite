#include "sqflite_plugin.h"


#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>                   // ref here https://engine.chinmaygarde.com/flutter__plugin__registrar_8h.html
#include <flutter/standard_method_codec.h>
#include <windows.h>

#include <codecvt>
#include <memory>
#include <sstream>
#include <string>

namespace {


    using flutter::EncodableList;
    using flutter::EncodableMap;
    using flutter::EncodableValue;

    const char kChannelName[] = "com.tekartik.sqflite";
    const char kInMemoryPath[] = ":memory:";

    // methods currently upstream SQFLite implemented
    const char kMethodGetPlatformVersion[] = "getPlatformVersion";
    const char kMethodGetDatabasePath[] = "getDatabasePath";
    const char kMethodDebugMode[] = "debugMode";

    class SqflitePlugin : public flutter::Plugin {
    public:
        static void RegisterWithRegistrar(flutter::PluginRegistrarWindows* registrar);

        // Creates a plugin that communicates on the given channel.
        SqflitePlugin(flutter::PluginRegistrarWindows* registrar);

        virtual ~SqflitePlugin();

    private:
        // Called when a method is called on the plugin channel;
        void HandleMethodCall(
            const flutter::MethodCall<flutter::EncodableValue>& method_call,
            std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result);

        // The registrar for this plugin, for accessing the window.
        flutter::PluginRegistrarWindows* registrar_;
    }

    // real static registrar
    void SqflitePlugin::RegisterWithRegistrar(
        flutter::PluginRegistrarWindows* registrar) {
        auto channel = std::make_unique<flutter::MethodChannel<EncodableValue>>(
                registrar->messenger(), kChannelName,
                &flutter::StandardMethodCodec::GetInstance());

        auto plugin = std::make_unique<SqflitePlugin>(registrar);

        channel->SetMethodCallHandler(
            [plugin_pointer = plugin.get()](const auto &call, auto result) {
                plugin_pointer->HandleMethodCall(call, std::move(result));
                });
        
        registrar->AddPlugin(std::move(plugin));
    }

    SqflitePlugin::~SqflitePlugin(flutter::PluginRegistrarWindows *registrar)
    : registrar_(registrar) {}

    
    // virtual deconstructor ref: https://www.geeksforgeeks.org/pure-virtual-destructor-c/
    SqflitePlugin::~SqflitePlugin() {};


    // TODO: implement HandleMethodCall
    void SqflitePlugin::HandleMethodCall(
        const flutter::MethodCall<flutter::EncodableValue> &method_call,
        std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result) {
        
        }
    
} // namespace



void SqflitePluginRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar) {
        // TODO ("Implement an instance class with a registrar method")
    }