// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê”Œœ∑∞Ê±æ£∫0.0.0.1 (2019/10/05 21:54)

#ifndef RELATION_DLL_H
#define RELATION_DLL_H

#include "System/Helper/ExportMacro.h"
#include "Helper/UserMacro.h"

#if defined(BUILDING_RELATION_NO_IMPORT) || defined(BUILDING_RELATION_STATIC)

  #define RELATION_DEFAULT_DECLARE
  #define RELATION_HIDDEN_DECLARE 
  #define RELATION_VISIBLE

#else // !defined(BUILDING_RELATION_NO_IMPORT) && !defined(BUILDING_RELATION_STATIC)
 
   #if defined(BUILDING_RELATION_EXPORT)
 
        #define RELATION_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define RELATION_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

   #else // !defined(BUILDING_RELATION_EXPORT)

		#define RELATION_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define RELATION_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

   #endif // BUILDING_RELATION_EXPORT

   #define RELATION_VISIBLE TCRE_SYMBOL_VISIBLE

#endif // defined(BUILDING_RELATION_NO_IMPORT) || defined(BUILDING_RELATION_STATIC)
 
#endif // RELATION_DLL_H
