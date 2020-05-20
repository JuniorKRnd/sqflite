#include "sqflite_plugin.h"


#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>                   // ref here https://engine.chinmaygarde.com/flutter__plugin__registrar_8h.html
#include <flutter/standard_method_codec.h>
#include <windows.h>

#include <codecvt>
#include <memory>
#include <sstream>
#include <string>

// IMPORT PURE C SQLITE3 LIBRARY
#ifdef __cplusplus
extern "C"
{
#endif

// C header here
#include <sqlite3.h>

#ifdef __cplusplus
}
#endif


namespace {

    using flutter::EncodableList;
    using flutter::EncodableMap;
    using flutter::EncodableValue;

    static const char kChannelName[] = "com.tekartik.sqflite";
    static const char kInMemoryPath[] = ":memory:";

    // methods currently upstream SQFLite implemented
    static const char kMethodGetPlatformVersion[] = "getPlatformVersion";
    static const char kMethodGetDatabasePath[] = "getDatabasePath";
    static const char kMethodDebugMode[] = "debugMode";
    static const char kMethodDebug[] = "debug";
    static const char kMethodOptions[] = "options";

    static const char kMethodOpenDatabase[] = "openDatabase";
    static const char kMethodCloseDatabase[] =  "closeDatabase";
    static const char kMethodDeleteDatabase[] = "deleteDatabase";
    static const char kMethodExecute[] = "execute";
    static const char kMethodInsert[] = "insert";
    static const char kMethodUpdate[] = "update";
    static const char kMethodQuery[] = "query";
    static const char kMethodBatch[] = "batch";

    // For open]
    static const char kParamReadOnly[] = "readOnly";
    static const char kParamSingleInstance[] ="singleInstance";
    // Open result
    static const char kParamRecovered[] = "recovered";
    static const char kParamRecoveredInTranscation[] = "recoveredInTranscation";

    // For batch
    static const char kParamOperations[] = "operations";
    // For each batch operation
    static const char kParamPath[] = "path";
    static const char kParamId[] ="id";
    static const char kParamTable[]  = "table";
    static const char kParamValues[] = "values";
    
    static const char kSqliteErrorCode[] = "sqlite_error";
    static const char kErrorBadParam[] = "bad_param";      // internal only
    static const char kErrorOpenFailed[] = "open_failed";
    static const char kErrorDatabaseClosed[] = "database_closed";

    // Options
    static const char kParamQueryAsMapList[] = "queryAsMapList";

    // Debug
    static const char kParamDatabases[] = "databases";
    static const char kParamLogLevel[] = "loglevel";
    static const char kParamCmd[] = "cmd";
    static const char kParamCmdGet[] = "get";

    // Shared
    char SqfliteParamSql[] = "sql";
    char SqfliteParamSqlArguments[] = "arguments";
    char SqfliteParamInTransaction[] = "inTransaction";
    char SqfliteParamNoResult[] = "noResult";
    char SqfliteParamContinueOnError[] = "continueOnError";
    char SqfliteParamMethod[] = "method";
    

    // batch has either result or error
    const char SqfliteParamResult[] = "result";
    const char SqfliteParamError[] = "error";
    const char SqfliteParamErrorCode[] = "code";
    const char SqfliteParamErrorMessage[] = "message";
    const char SqfliteParamErrorData[] = "data";
    

    namespace SqfliteDatabase {
        // TODO ("Implement properties to hold database object and its transcation status")
    }

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
    };

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
    };

    SqflitePlugin::SqflitePlugin(flutter::PluginRegistrarWindows *registrar) 
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