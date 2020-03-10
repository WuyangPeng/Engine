// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/09 19:16)

#ifndef NETWORK_DLL_H
#define NETWORK_DLL_H

#include "Network/Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"
 
#if defined(BUILDING_NETWORK_NO_IMPORT) || defined(BUILDING_NETWORK_STATIC)

  #define NETWORK_DEFAULT_DECLARE
  #define NETWORK_HIDDEN_DECLARE 
  #define NETWORK_VISIBLE

#else // !defined(BUILDING_NETWORK_NO_IMPORT) && !defined(BUILDING_NETWORK_STATIC)
 
   #if defined(BUILDING_NETWORK_EXPORT)
 
        #define NETWORK_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define NETWORK_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

   #else // !defined(BUILDING_NETWORK_EXPORT)

		#define NETWORK_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define NETWORK_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

   #endif // BUILDING_NETWORK_EXPORT

   #define SYSTEM_VISIBLE TCRE_SYMBOL_VISIBLE

#endif // defined(BUILDING_NETWORK_NO_IMPORT) || defined(BUILDING_NETWORK_STATIC)

#endif // NETWORK_DLL_H
 