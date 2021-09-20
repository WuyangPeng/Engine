// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.2.1 (2020/01/12 1:37)

#ifndef EXAMPLE_TOOLSET_DLL_DLL_H
#define EXAMPLE_TOOLSET_DLL_DLL_H

#include "System/Helper/ExportMacro.h"
#include "Macro/Macro.h" 

#if defined(BUILDING_EXAMPLE_TOOLSET_NO_IMPORT) || defined(BUILDING_EXAMPLE_STATIC)

  #define EXAMPLE_TOOLSET_DEFAULT_DECLARE
  #define EXAMPLE_TOOLSET_HIDDEN_DECLARE
  #define EXAMPLE_TOOLSET_VISIBLE

#else // !defined(BUILDING_EXAMPLE_TOOLSET_NO_IMPORT) && !defined(BUILDING_EXAMPLE_STATIC)

   #if defined(BUILDING_EXAMPLE_TOOLSET_EXPORT)
 
        #define EXAMPLE_TOOLSET_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define EXAMPLE_TOOLSET_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

   #else // !defined(BUILDING_EXAMPLE_TOOLSET_EXPORT)

		#define EXAMPLE_TOOLSET_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define EXAMPLE_TOOLSET_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

   #endif // BUILDING_EXAMPLE_TOOLSET_EXPORT

   #define EXAMPLE_TOOLSET_VISIBLE TCRE_SYMBOL_VISIBLE

#endif // defined(BUILDING_EXAMPLE_TOOLSET_NO_IMPORT) || defined(BUILDING_EXAMPLE_STATIC)

#endif // EXAMPLE_TOOLSET_DLL_DLL_H