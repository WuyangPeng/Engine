// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê”Œœ∑∞Ê±æ£∫0.0.0.1 (2019/10/06 21:38)

#ifndef ACTIVITY_DLL_H
#define ACTIVITY_DLL_H

#include "System/Helper/ExportMacro.h"
#include "Helper/UserMacro.h"

#if defined(BUILDING_ACTIVITY_NO_IMPORT) || defined(BUILDING_ACTIVITY_STATIC)

  #define ACTIVITY_DEFAULT_DECLARE
  #define ACTIVITY_HIDDEN_DECLARE 
  #define ACTIVITY_VISIBLE

#else // !defined(BUILDING_ACTIVITY_NO_IMPORT) && !defined(BUILDING_ACTIVITY_STATIC)
 
   #if defined(BUILDING_ACTIVITY_EXPORT)
 
        #define ACTIVITY_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define ACTIVITY_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

   #else // !defined(BUILDING_ACTIVITY_EXPORT)

		#define ACTIVITY_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define ACTIVITY_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

   #endif // BUILDING_ACTIVITY_EXPORT

   #define ACTIVITY_VISIBLE TCRE_SYMBOL_VISIBLE

#endif // defined(BUILDING_ACTIVITY_NO_IMPORT) || defined(BUILDING_ACTIVITY_STATIC)
 
#endif // ACTIVITY_DLL_H
