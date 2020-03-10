// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/03 13:26)

#ifndef SCRIPT_DLL_H
#define SCRIPT_DLL_H

#include "System/Helper/ExportMacro.h"
#include "Script/Macro/UserMacro.h"
 
#if defined(BUILDING_SCRIPT_NO_IMPORT) || defined(BUILDING_SCRIPT_STATIC)

  #define SCRIPT_DEFAULT_DECLARE
  #define SCRIPT_HIDDEN_DECLARE 
  #define SCRIPT_VISIBLE

#else // !defined(BUILDING_SCRIPT_NO_IMPORT) && !defined(BUILDING_SCRIPT_STATIC)
 
   #if defined(BUILDING_SCRIPT_EXPORT)
 
        #define SCRIPT_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define SCRIPT_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

   #else // !defined(BUILDING_SCRIPT_EXPORT)

		#define SCRIPT_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define SCRIPT_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

   #endif // BUILDING_SCRIPT_EXPORT

   #define SCRIPT_VISIBLE TCRE_SYMBOL_VISIBLE

#endif // defined(BUILDING_SCRIPT_NO_IMPORT) || defined(BUILDING_SCRIPT_STATIC)

#endif // SCRIPT_DLL_H