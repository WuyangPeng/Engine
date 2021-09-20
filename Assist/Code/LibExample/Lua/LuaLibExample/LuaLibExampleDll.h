// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/10/01 10:59)

#ifndef LUA_LIB_EXAMPLE_DLL_H
#define LUA_LIB_EXAMPLE_DLL_H

#include "System/Helper/ExportMacro.h"
#include "Macro/UserMacro.h"

#if defined(LUA_LIB_EXAMPLE_NO_IMPORT) || defined(BUILDING_LUA_LIB_EXAMPLE_STATIC)

  #define LUA_LIB_EXAMPLE_DEFAULT_DECLARE
  #define LUA_LIB_EXAMPLE_HIDDEN_DECLARE
  #define LUA_LIB_EXAMPLE_VISIBLE

#else // !defined(LUA_LIB_EXAMPLE_NO_IMPORT) && !defined(LUA_LIB_EXAMPLE_STATIC)

   #if defined(LUA_LIB_EXAMPLE_EXPORT)
 
        #define LUA_LIB_EXAMPLE_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define LUA_LIB_EXAMPLE_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

   #else // !defined(LUA_LIB_EXAMPLE_EXPORT)

		#define LUA_LIB_EXAMPLE_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define LUA_LIB_EXAMPLE_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

   #endif // LUA_LIB_EXAMPLE_EXPORT

   #define LUA_LIB_EXAMPLE_VISIBLE TCRE_SYMBOL_VISIBLE

#endif // defined(LUA_LIB_EXAMPLE_NO_IMPORT) || defined(LUA_LIB_EXAMPLE_STATIC)

#endif // LUA_LIB_EXAMPLE_DLL_H
