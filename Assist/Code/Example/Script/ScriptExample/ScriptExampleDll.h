// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.2.2 (2020/01/24 19:29)

#ifndef SCRIPT_EXAMPLE_DLL_DLL_H
#define SCRIPT_EXAMPLE_DLL_DLL_H

#include "System/Helper/ExportMacro.h"
#include "Macro/UserMacro.h"

#if defined(BUILDING_SCRIPT_EXAMPLE_NO_IMPORT) || defined(BUILDING_SCRIPT_EXAMPLE_STATIC)

  #define SCRIPT_EXAMPLE_DEFAULT_DECLARE
  #define SCRIPT_EXAMPLE_HIDDEN_DECLARE
  #define SCRIPT_EXAMPLE_VISIBLE

#else // !defined(BUILDING_SCRIPT_EXAMPLE_NO_IMPORT) && !defined(BUILDING_SCRIPT_EXAMPLE_STATIC)

   #if defined(BUILDING_SCRIPT_EXAMPLE_EXPORT)
 
        #define SCRIPT_EXAMPLE_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define SCRIPT_EXAMPLE_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

   #else // !defined(BUILDING_SCRIPT_EXAMPLE_EXPORT)

		#define SCRIPT_EXAMPLE_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define SCRIPT_EXAMPLE_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

   #endif // BUILDING_SCRIPT_EXAMPLE_EXPORT

   #define SCRIPT_EXAMPLE_VISIBLE TCRE_SYMBOL_VISIBLE

#endif // defined(BUILDING_SCRIPT_EXAMPLE_NO_IMPORT) || defined(BUILDING_SCRIPT_EXAMPLE_STATIC)

#endif // SCRIPT_EXAMPLE_DLL_DLL_H
