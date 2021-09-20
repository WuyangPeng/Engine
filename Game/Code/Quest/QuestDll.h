// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê”Œœ∑∞Ê±æ£∫0.0.0.1 (2019/10/05 22:01)

#ifndef QUEST_DLL_H
#define QUEST_DLL_H

#include "System/Helper/ExportMacro.h"
#include "Helper/UserMacro.h"

#if defined(BUILDING_QUEST_NO_IMPORT) || defined(BUILDING_QUEST_STATIC)

  #define QUEST_DEFAULT_DECLARE
  #define QUEST_HIDDEN_DECLARE 
  #define QUEST_VISIBLE

#else // !defined(BUILDING_QUEST_NO_IMPORT) && !defined(BUILDING_QUEST_STATIC)
 
   #if defined(BUILDING_QUEST_EXPORT)
 
        #define QUEST_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define QUEST_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

   #else // !defined(BUILDING_QUEST_EXPORT)

		#define QUEST_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define QUEST_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

   #endif // BUILDING_QUEST_EXPORT

   #define QUEST_VISIBLE TCRE_SYMBOL_VISIBLE

#endif // defined(BUILDING_QUEST_NO_IMPORT) || defined(BUILDING_QUEST_STATIC)
 
#endif // QUEST_DLL_H
