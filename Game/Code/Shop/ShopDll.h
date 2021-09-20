// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê”Œœ∑∞Ê±æ£∫0.0.0.1 (2019/10/05 21:00)

#ifndef SHOP_DLL_H
#define SHOP_DLL_H

#include "System/Helper/ExportMacro.h"
#include "Helper/UserMacro.h"

#if defined(BUILDING_SHOP_NO_IMPORT) || defined(BUILDING_SHOP_STATIC)

  #define SHOP_DEFAULT_DECLARE
  #define SHOP_HIDDEN_DECLARE 
  #define SHOP_VISIBLE

#else // !defined(BUILDING_SHOP_NO_IMPORT) && !defined(BUILDING_SHOP_STATIC)
 
   #if defined(BUILDING_SHOP_EXPORT)
 
        #define SHOP_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define SHOP_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

   #else // !defined(BUILDING_SHOP_EXPORT)

		#define SHOP_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define SHOP_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

   #endif // BUILDING_SHOP_EXPORT

   #define SHOP_VISIBLE TCRE_SYMBOL_VISIBLE

#endif // defined(BUILDING_SHOP_NO_IMPORT) || defined(BUILDING_SHOP_STATIC)
 
#endif // SHOP_DLL_H
