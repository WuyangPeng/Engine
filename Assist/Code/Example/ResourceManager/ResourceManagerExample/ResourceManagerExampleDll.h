// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.2.2 (2020/01/26 0:50)

#ifndef RESOURCE_MANAGER_EXAMPLE_DLL_DLL_H
#define RESOURCE_MANAGER_EXAMPLE_DLL_DLL_H

#include "System/Helper/ExportMacro.h"
#include "Macro/UserMacro.h"

#if defined(BUILDING_RESOURCE_MANAGER_EXAMPLE_NO_IMPORT) || defined(BUILDING_RESOURCE_MANAGER_EXAMPLE_STATIC)

  #define RESOURCE_MANAGER_EXAMPLE_DEFAULT_DECLARE
  #define RESOURCE_MANAGER_EXAMPLE_HIDDEN_DECLARE
  #define RESOURCE_MANAGER_EXAMPLE_VISIBLE

#else // !defined(BUILDING_RESOURCE_MANAGER_EXAMPLE_NO_IMPORT) && !defined(BUILDING_RESOURCE_MANAGER_EXAMPLE_STATIC)

   #if defined(BUILDING_RESOURCE_MANAGER_EXAMPLE_EXPORT)
 
        #define RESOURCE_MANAGER_EXAMPLE_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define RESOURCE_MANAGER_EXAMPLE_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

   #else // !defined(BUILDING_RESOURCE_MANAGER_EXAMPLE_EXPORT)

		#define RESOURCE_MANAGER_EXAMPLE_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define RESOURCE_MANAGER_EXAMPLE_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

   #endif // BUILDING_RESOURCE_MANAGER_EXAMPLE_EXPORT

   #define RESOURCE_MANAGER_EXAMPLE_VISIBLE TCRE_SYMBOL_VISIBLE

#endif // defined(BUILDING_RESOURCE_MANAGER_EXAMPLE_NO_IMPORT) || defined(BUILDING_RESOURCE_MANAGER_EXAMPLE_STATIC)

#endif // RESOURCE_MANAGER_EXAMPLE_DLL_DLL_H