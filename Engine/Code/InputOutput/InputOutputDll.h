// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/16 14:40)

#ifndef INPUT_OUTPUT_DLL_H
#define INPUT_OUTPUT_DLL_H

#include "System/Helper/ExportMacro.h"
#include "Helper/UserMacro.h"

#if defined(BUILDING_INPUT_OUTPUT_NO_IMPORT) || defined(BUILDING_INPUT_OUTPUT_STATIC)

  #define INPUT_OUTPUT_DEFAULT_DECLARE
  #define INPUT_OUTPUT_HIDDEN_DECLARE
  #define INPUT_OUTPUT_VISIBLE

#else // !defined(BUILDING_INPUT_OUTPUT_NO_IMPORT) && !defined(BUILDING_INPUT_OUTPUT_STATIC)
 
   #if defined(BUILDING_INPUT_OUTPUT_EXPORT)
 
        #define INPUT_OUTPUT_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define INPUT_OUTPUT_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

   #else // !defined(BUILDING_INPUT_OUTPUT_EXPORT)

		#define INPUT_OUTPUT_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define INPUT_OUTPUT_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

   #endif // BUILDING_INPUT_OUTPUT_EXPORT

   #define INPUT_OUTPUT_VISIBLE TCRE_SYMBOL_VISIBLE

#endif // defined(BUILDING_INPUT_OUTPUT_NO_IMPORT) || defined(BUILDING_INPUT_OUTPUT_STATIC)

#endif // INPUT_OUTPUT_DLL_H