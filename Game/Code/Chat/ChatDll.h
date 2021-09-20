// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê”Œœ∑∞Ê±æ£∫0.0.0.1 (2019/10/06 20:18)

#ifndef CHAT_DLL_H
#define CHAT_DLL_H

#include "System/Helper/ExportMacro.h"
#include "Helper/UserMacro.h"

#if defined(BUILDING_CHAT_NO_IMPORT) || defined(BUILDING_CHAT_STATIC)

  #define CHAT_DEFAULT_DECLARE
  #define CHAT_HIDDEN_DECLARE 
  #define CHAT_VISIBLE

#else // !defined(BUILDING_CHAT_NO_IMPORT) && !defined(BUILDING_CHAT_STATIC)
 
   #if defined(BUILDING_CHAT_EXPORT)
 
        #define CHAT_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define CHAT_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

   #else // !defined(BUILDING_CHAT_EXPORT)

		#define CHAT_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define CHAT_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

   #endif // BUILDING_CHAT_EXPORT

   #define CHAT_VISIBLE TCRE_SYMBOL_VISIBLE

#endif // defined(BUILDING_CHAT_NO_IMPORT) || defined(BUILDING_CHAT_STATIC)
 
#endif // CHAT_DLL_H
