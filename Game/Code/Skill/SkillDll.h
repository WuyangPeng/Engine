// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê”Œœ∑∞Ê±æ£∫0.0.0.1 (2019/10/05 21:38)

#ifndef SKILL_DLL_H
#define SKILL_DLL_H

#include "System/Helper/ExportMacro.h"
#include "Helper/UserMacro.h"

#if defined(BUILDING_SKILL_NO_IMPORT) || defined(BUILDING_SKILL_STATIC)

  #define SKILL_DEFAULT_DECLARE
  #define SKILL_HIDDEN_DECLARE 
  #define SKILL_VISIBLE

#else // !defined(BUILDING_SKILL_NO_IMPORT) && !defined(BUILDING_SKILL_STATIC)
 
   #if defined(BUILDING_SKILL_EXPORT)
 
        #define SKILL_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define SKILL_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

   #else // !defined(BUILDING_SKILL_EXPORT)

		#define SKILL_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define SKILL_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

   #endif // BUILDING_SKILL_EXPORT

   #define SKILL_VISIBLE TCRE_SYMBOL_VISIBLE

#endif // defined(BUILDING_SKILL_NO_IMPORT) || defined(BUILDING_SKILL_STATIC)
 
#endif // SKILL_DLL_H
