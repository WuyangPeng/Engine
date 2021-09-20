// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/09/30 23:04)

#ifndef ACE_LIB_EXAMPLE_DLL_H
#define ACE_LIB_EXAMPLE_DLL_H

#include "System/Helper/ExportMacro.h"
#include "Macro/UserMacro.h"

#if defined(ACE_LIB_EXAMPLE_NO_IMPORT) || defined(BUILDING_ACE_LIB_EXAMPLE_STATIC)

  #define ACE_LIB_EXAMPLE_DEFAULT_DECLARE
  #define ACE_LIB_EXAMPLE_HIDDEN_DECLARE
  #define ACE_LIB_EXAMPLE_VISIBLE

#else // !defined(ACE_LIB_EXAMPLE_NO_IMPORT) && !defined(ACE_LIB_EXAMPLE_STATIC)

   #if defined(ACE_LIB_EXAMPLE_EXPORT)
 
        #define ACE_LIB_EXAMPLE_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define ACE_LIB_EXAMPLE_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

   #else // !defined(ACE_LIB_EXAMPLE_EXPORT)

		#define ACE_LIB_EXAMPLE_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define ACE_LIB_EXAMPLE_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

   #endif // ACE_LIB_EXAMPLE_EXPORT

   #define ACE_LIB_EXAMPLE_VISIBLE TCRE_SYMBOL_VISIBLE

#endif // defined(ACE_LIB_EXAMPLE_NO_IMPORT) || defined(ACE_LIB_EXAMPLE_STATIC)

#endif // ACE_LIB_EXAMPLE_DLL_H
