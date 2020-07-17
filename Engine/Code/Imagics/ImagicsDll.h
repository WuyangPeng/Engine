// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/30 11:15)

#ifndef IMAGICS_DLL_H
#define IMAGICS_DLL_H

#include "System/Helper/ExportMacro.h"
#include "Helper/UserMacro.h"
 
#if defined(BUILDING_IMAGICS_NO_IMPORT) || defined(BUILDING_IMAGICS_STATIC)

  #define IMAGICS_DEFAULT_DECLARE
  #define IMAGICS_HIDDEN_DECLARE 
  #define IMAGICS_VISIBLE

#else // !defined(BUILDING_IMAGICS_NO_IMPORT) && !defined(BUILDING_IMAGICS_STATIC)
 
#if defined(BUILDING_IMAGICS_EXPORT)
 
        #define IMAGICS_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define IMAGICS_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

   #else // !defined(BUILDING_IMAGICS_EXPORT)

		#define IMAGICS_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define IMAGICS_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

   #endif // BUILDING_IMAGICS_EXPORT

   #define IMAGICS_VISIBLE TCRE_SYMBOL_VISIBLE

#endif // defined(BUILDING_IMAGICS_NO_IMPORT) || defined(BUILDING_IMAGICS_STATIC)

#endif // IMAGICS_DLL_H