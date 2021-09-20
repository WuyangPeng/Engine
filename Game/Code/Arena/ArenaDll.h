// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê”Œœ∑∞Ê±æ£∫0.0.0.1 (2019/10/06 20:43)

#ifndef ARENA_DLL_H
#define ARENA_DLL_H

#include "System/Helper/ExportMacro.h"
#include "Helper/UserMacro.h"

#if defined(BUILDING_ARENA_NO_IMPORT) || defined(BUILDING_ARENA_STATIC)

  #define ARENA_DEFAULT_DECLARE
  #define ARENA_HIDDEN_DECLARE 
  #define ARENA_VISIBLE

#else // !defined(BUILDING_ARENA_NO_IMPORT) && !defined(BUILDING_ARENA_STATIC)
 
   #if defined(BUILDING_ARENA_EXPORT)
 
        #define ARENA_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define ARENA_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

   #else // !defined(BUILDING_ARENA_EXPORT)

		#define ARENA_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define ARENA_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

   #endif // BUILDING_ARENA_EXPORT

   #define ARENA_VISIBLE TCRE_SYMBOL_VISIBLE

#endif // defined(BUILDING_ARENA_NO_IMPORT) || defined(BUILDING_ARENA_STATIC)
 
#endif // ARENA_DLL_H
