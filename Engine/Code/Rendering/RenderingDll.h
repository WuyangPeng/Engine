// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/17 10:54)

#ifndef RENDERING_DLL_H
#define RENDERING_DLL_H

#include "System/Helper/ExportMacro.h"
#include "Rendering/Macro/UserMacro.h"
 
#if defined(BUILDING_RENDERING_NO_IMPORT) || defined(BUILDING_RENDERING_STATIC)

  #define RENDERING_DEFAULT_DECLARE
  #define RENDERING_HIDDEN_DECLARE 
  #define RENDERING_VISIBLE

#else // !defined(BUILDING_RENDERING_NO_IMPORT) && !defined(BUILDING_RENDERING_STATIC)
 
   #if defined(BUILDING_RENDERING_EXPORT)
 
        #define RENDERING_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define RENDERING_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

   #else // !defined(BUILDING_RENDERING_EXPORT)

		#define RENDERING_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define RENDERING_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

   #endif // BUILDING_RENDERING_EXPORT

   #define RENDERING_VISIBLE TCRE_SYMBOL_VISIBLE

#endif // defined(BUILDING_RENDERING_NO_IMPORT) || defined(BUILDING_RENDERING_STATIC)

#endif // RENDERING_DLL_H