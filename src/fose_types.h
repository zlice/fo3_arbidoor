// types from FOSE src, because visual studio cross compile is hell

struct FOSEInterface {
  uint32_t foseVersion;
  uint32_t runtimeVersion;
  uint32_t editorVersion;
  uint32_t isEditor;
  // unused data
  /*
  bool (*RegisterCommand)(CommandInfo * info); // returns true for success, false for failure
  void (*SetOpcodeBase)(uint32_t opcode);
  void * (*QueryInterface)(uint32_t id);

  // call during your Query or Load functions to get a PluginHandle uniquely identifying your plugin
  // invalid if called at any other time, so call it once and save the result
  PluginHandle (*GetPluginHandle)(void);

  // CommandReturnType enum defined in CommandTable.h
  // does the same as RegisterCommand but includes return type; *required* for commands returning arrays
  bool  (*RegisterTypedCommand)(CommandInfo * info, CommandReturnType retnType);
  // returns a full path the the game directory
  const char *(*GetRuntimeDirectory)();

  // Allows checking for nogore edition
  uint32_t  isNogore;
  */
};

struct PluginInfo {
  enum { kInfoVersion = 1 };

  uint32_t   infoVersion;
  const char *name;
  uint32_t   version;
};
