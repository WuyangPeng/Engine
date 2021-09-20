// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.0.3 (2019/10/01 20:12)

#ifndef DIRECTX_LIB_EXAMPLE_DLL_H
#define DIRECTX_LIB_EXAMPLE_DLL_H

#include "System/Helper/ExportMacro.h"
#include "Macro/UserMacro.h"

#if defined(DIRECTX_LIB_EXAMPLE_NO_IMPORT) || defined(BUILDING_DIRECTX_LIB_EXAMPLE_STATIC)

  #define DIRECTX_LIB_EXAMPLE_DEFAULT_DECLARE
  #define DIRECTX_LIB_EXAMPLE_HIDDEN_DECLARE
  #define DIRECTX_LIB_EXAMPLE_VISIBLE

#else // !defined(DIRECTX_LIB_EXAMPLE_NO_IMPORT) && !defined(DIRECTX_LIB_EXAMPLE_STATIC)

   #if defined(DIRECTX_LIB_EXAMPLE_EXPORT)
 
        #define DIRECTX_LIB_EXAMPLE_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define DIRECTX_LIB_EXAMPLE_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

   #else // !defined(DIRECTX_LIB_EXAMPLE_EXPORT)

		#define DIRECTX_LIB_EXAMPLE_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define DIRECTX_LIB_EXAMPLE_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

   #endif // DIRECTX_LIB_EXAMPLE_EXPORT

   #define DIRECTX_LIB_EXAMPLE_VISIBLE TCRE_SYMBOL_VISIBLE

#endif // defined(DIRECTX_LIB_EXAMPLE_NO_IMPORT) || defined(DIRECTX_LIB_EXAMPLE_STATIC)

#endif // DIRECTX_LIB_EXAMPLE_DLL_H