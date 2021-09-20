// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.2.0 (2020/01/05 1:19) 

#ifndef NETWORK_TOOLSET_DLL_DLL_H
#define NETWORK_TOOLSET_DLL_DLL_H

#include "System/Helper/ExportMacro.h"
#include "Network/Helper/UserMacro.h"

#if defined(BUILDING_NETWORK_TOOLSET_NO_IMPORT) || defined(BUILDING_NETWORK_STATIC)

  #define NETWORK_TOOLSET_DEFAULT_DECLARE
  #define NETWORK_TOOLSET_HIDDEN_DECLARE
  #define NETWORK_TOOLSET_VISIBLE

#else // !defined(BUILDING_NETWORK_TOOLSET_NO_IMPORT) && !defined(BUILDING_NETWORK_STATIC)

   #if defined(BUILDING_NETWORK_TOOLSET_EXPORT)
 
        #define NETWORK_TOOLSET_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define NETWORK_TOOLSET_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

   #else // !defined(BUILDING_NETWORK_TOOLSET_EXPORT)

		#define NETWORK_TOOLSET_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define NETWORK_TOOLSET_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

   #endif // BUILDING_NETWORK_TOOLSET_EXPORT

   #define NETWORK_TOOLSET_VISIBLE TCRE_SYMBOL_VISIBLE

#endif // defined(BUILDING_NETWORK_TOOLSET_NO_IMPORT) || defined(BUILDING_NETWORK_STATIC)

#endif // NETWORK_TOOLSET_DLL_DLL_H
