// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.0 (2019/10/10 18:01)

#ifndef BACKGROUND_CLIENT_MIDDLE_LAYER_DLL_H
#define BACKGROUND_CLIENT_MIDDLE_LAYER_DLL_H

#include "System/Helper/ExportMacro.h"
#include "Macro/UserMacro.h"

#if defined(BUILDING_BACKGROUND_CLIENT_MIDDLE_LAYER_NO_IMPORT)  || defined(BUILDING_BACKGROUND_CLIENT_MIDDLE_LAYER_STATIC)

  #define BACKGROUND_CLIENT_MIDDLE_LAYER_DEFAULT_DECLARE
  #define BACKGROUND_CLIENT_MIDDLE_LAYER_HIDDEN_DECLARE 
  #define BACKGROUND_CLIENT_MIDDLE_LAYER_VISIBLE

#else // !defined(BUILDING_BACKGROUND_CLIENT_MIDDLE_LAYER_NO_IMPORT) && !defined(BUILDING_BACKGROUND_CLIENT_MIDDLE_LAYER_STATIC)
 
   #if defined(BUILDING_BACKGROUND_CLIENT_MIDDLE_LAYER_EXPORT)
 
        #define BACKGROUND_CLIENT_MIDDLE_LAYER_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define BACKGROUND_CLIENT_MIDDLE_LAYER_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

   #else // !defined(BUILDING_BACKGROUND_CLIENT_MIDDLE_LAYER_EXPORT)

		#define BACKGROUND_CLIENT_MIDDLE_LAYER_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define BACKGROUND_CLIENT_MIDDLE_LAYER_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

   #endif // BUILDING_BACKGROUND_CLIENT_MIDDLE_LAYER_EXPORT

   #define BACKGROUND_CLIENT_MIDDLE_LAYER_VISIBLE TCRE_SYMBOL_VISIBLE

#endif // defined(BUILDING_BACKGROUND_CLIENT_MIDDLE_LAYER_NO_IMPORT) || defined(BUILDING_BACKGROUND_CLIENT_MIDDLE_LAYER_STATIC)
 
#endif // BACKGROUND_CLIENT_MIDDLE_LAYER_DLL_H
