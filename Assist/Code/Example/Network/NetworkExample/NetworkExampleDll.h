// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.2.2 (2020/01/23 23:18)

#ifndef NETWORK_EXAMPLE_DLL_DLL_H
#define NETWORK_EXAMPLE_DLL_DLL_H

#include "System/Helper/ExportMacro.h"
#include "Helper/UserMacro.h"

#if defined(BUILDING_NETWORK_EXAMPLE_NO_IMPORT) || defined(BUILDING_NETWORK_EXAMPLE_STATIC)

  #define NETWORK_EXAMPLE_DEFAULT_DECLARE
  #define NETWORK_EXAMPLE_HIDDEN_DECLARE
  #define NETWORK_EXAMPLE_VISIBLE

#else // !defined(BUILDING_NETWORK_EXAMPLE_NO_IMPORT) && !defined(BUILDING_NETWORK_EXAMPLE_STATIC)

   #if defined(BUILDING_NETWORK_EXAMPLE_EXPORT)
 
        #define NETWORK_EXAMPLE_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define NETWORK_EXAMPLE_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

   #else // !defined(BUILDING_NETWORK_EXAMPLE_EXPORT)

		#define NETWORK_EXAMPLE_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define NETWORK_EXAMPLE_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

   #endif // BUILDING_NETWORK_EXAMPLE_EXPORT

   #define NETWORK_EXAMPLE_VISIBLE TCRE_SYMBOL_VISIBLE

#endif // defined(BUILDING_NETWORK_EXAMPLE_NO_IMPORT) || defined(BUILDING_NETWORK_EXAMPLE_STATIC)

#endif // NETWORK_EXAMPLE_DLL_DLL_H
