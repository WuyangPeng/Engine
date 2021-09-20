// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.0.3 (2019/10/02 15:17)

#ifndef FREETYPE_LIB_EXAMPLE_DLL_H
#define FREETYPE_LIB_EXAMPLE_DLL_H

#include "System/Helper/ExportMacro.h"
#include "Macro/UserMacro.h"

#if defined(FREETYPE_LIB_EXAMPLE_NO_IMPORT) || defined(BUILDING_FREETYPE_LIB_EXAMPLE_STATIC)

  #define FREETYPE_LIB_EXAMPLE_DEFAULT_DECLARE
  #define FREETYPE_LIB_EXAMPLE_HIDDEN_DECLARE
  #define FREETYPE_LIB_EXAMPLE_VISIBLE

#else // !defined(FREETYPE_LIB_EXAMPLE_NO_IMPORT) && !defined(FREETYPE_LIB_EXAMPLE_STATIC)

   #if defined(FREETYPE_LIB_EXAMPLE_EXPORT)
 
        #define FREETYPE_LIB_EXAMPLE_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define FREETYPE_LIB_EXAMPLE_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

   #else // !defined(FREETYPE_LIB_EXAMPLE_EXPORT)

		#define FREETYPE_LIB_EXAMPLE_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define FREETYPE_LIB_EXAMPLE_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

   #endif // FREETYPE_LIB_EXAMPLE_EXPORT

   #define FREETYPE_LIB_EXAMPLE_VISIBLE TCRE_SYMBOL_VISIBLE

#endif // defined(FREETYPE_LIB_EXAMPLE_NO_IMPORT) || defined(FREETYPE_LIB_EXAMPLE_STATIC)

#endif // FREETYPE_LIB_EXAMPLE_DLL_H
