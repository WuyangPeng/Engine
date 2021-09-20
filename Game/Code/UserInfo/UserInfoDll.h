// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê”Œœ∑∞Ê±æ£∫0.0.0.1 (2019/10/03 21:48)

#ifndef USER_INFO_DLL_H
#define USER_INFO_DLL_H

#include "System/Helper/ExportMacro.h"
#include "Helper/UserMacro.h"

#if defined(BUILDING_USER_INFO_NO_IMPORT) || defined(BUILDING_USER_INFO_STATIC)

  #define USER_INFO_DEFAULT_DECLARE
  #define USER_INFO_HIDDEN_DECLARE 
  #define USER_INFO_VISIBLE

#else // !defined(BUILDING_USER_INFO_NO_IMPORT) && !defined(BUILDING_USER_INFO_STATIC)
 
   #if defined(BUILDING_USER_INFO_EXPORT)
 
        #define USER_INFO_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define USER_INFO_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

   #else // !defined(BUILDING_USER_INFO_EXPORT)

		#define USER_INFO_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define USER_INFO_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

   #endif // BUILDING_USER_INFO_EXPORT

   #define USER_INFO_VISIBLE TCRE_SYMBOL_VISIBLE

#endif // defined(BUILDING_USER_INFO_NO_IMPORT) || defined(BUILDING_USER_INFO_STATIC)
 
#endif // USER_INFO_DLL_H
