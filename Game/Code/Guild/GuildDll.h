// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê”Œœ∑∞Ê±æ£∫0.0.0.1 (2019/10/05 23:12)

#ifndef GUILD_DLL_H
#define GUILD_DLL_H

#include "System/Helper/ExportMacro.h"
#include "Helper/UserMacro.h"

#if defined(BUILDING_GUILD_NO_IMPORT) || defined(BUILDING_GUILD_STATIC)

  #define GUILD_DEFAULT_DECLARE
  #define GUILD_HIDDEN_DECLARE 
  #define GUILD_VISIBLE

#else // !defined(BUILDING_GUILD_NO_IMPORT) && !defined(BUILDING_GUILD_STATIC)
 
   #if defined(BUILDING_GUILD_EXPORT)
 
        #define GUILD_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define GUILD_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

   #else // !defined(BUILDING_GUILD_EXPORT)

		#define GUILD_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define GUILD_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

   #endif // BUILDING_GUILD_EXPORT

   #define GUILD_VISIBLE TCRE_SYMBOL_VISIBLE

#endif // defined(BUILDING_GUILD_NO_IMPORT) || defined(BUILDING_GUILD_STATIC)
 
#endif // GUILD_DLL_H
