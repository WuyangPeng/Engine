// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/15 11:58)

#ifndef CORE_TOOLS_DLL_H
#define CORE_TOOLS_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_CORE_TOOLS_NO_IMPORT) || defined(BUILDING_CORE_TOOLS_STATIC)

  #define CORE_TOOLS_DEFAULT_DECLARE
  #define CORE_TOOLS_HIDDEN_DECLARE
  #define CORE_TOOLS_VISIBLE

#else // !defined(BUILDING_CORE_TOOLS_NO_IMPORT) && !defined(BUILDING_CORE_TOOLS_STATIC)

   #if defined(BUILDING_CORE_TOOLS_EXPORT)
 
        #define CORE_TOOLS_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define CORE_TOOLS_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

   #else // !defined(BUILDING_CORE_TOOLS_EXPORT)

		#define CORE_TOOLS_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define CORE_TOOLS_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

   #endif // BUILDING_CORE_TOOLS_EXPORT

   #define CORE_TOOLS_VISIBLE TCRE_SYMBOL_VISIBLE

#endif // defined(BUILDING_CORE_TOOLS_NO_IMPORT) || defined(BUILDING_CORE_TOOLS_STATIC)

#endif // CORE_TOOLS_DLL_H