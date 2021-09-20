// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê”Œœ∑∞Ê±æ£∫0.0.0.1 (2019/10/06 21:12)

#ifndef INSTANCE_DLL_H
#define INSTANCE_DLL_H

#include "System/Helper/ExportMacro.h"
#include "Helper/UserMacro.h"

#if defined(BUILDING_INSTANCE_NO_IMPORT) || defined(BUILDING_INSTANCE_STATIC)

  #define INSTANCE_DEFAULT_DECLARE
  #define INSTANCE_HIDDEN_DECLARE 
  #define INSTANCE_VISIBLE

#else // !defined(BUILDING_INSTANCE_NO_IMPORT) && !defined(BUILDING_INSTANCE_STATIC)
 
   #if defined(BUILDING_INSTANCE_EXPORT)
 
        #define INSTANCE_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define INSTANCE_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

   #else // !defined(BUILDING_INSTANCE_EXPORT)

		#define INSTANCE_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define INSTANCE_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

   #endif // BUILDING_INSTANCE_EXPORT

   #define INSTANCE_VISIBLE TCRE_SYMBOL_VISIBLE

#endif // defined(BUILDING_INSTANCE_NO_IMPORT) || defined(BUILDING_INSTANCE_STATIC)
 
#endif // INSTANCE_DLL_H
