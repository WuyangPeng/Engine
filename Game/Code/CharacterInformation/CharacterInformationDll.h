// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������Ϸ�汾��0.0.0.1 (2019/10/04 21:30)

#ifndef CHARACTER_INFORMATION_DLL_H
#define CHARACTER_INFORMATION_DLL_H

#include "System/Helper/ExportMacro.h"
#include "Helper/UserMacro.h"

#if defined(BUILDING_CHARACTER_INFORMATION_NO_IMPORT) || defined(BUILDING_CHARACTER_INFORMATION_STATIC)

  #define CHARACTER_INFORMATION_DEFAULT_DECLARE
  #define CHARACTER_INFORMATION_HIDDEN_DECLARE 
  #define CHARACTER_INFORMATION_VISIBLE

#else // !defined(BUILDING_CHARACTER_INFORMATION_NO_IMPORT) && !defined(BUILDING_CHARACTER_INFORMATION_STATIC)
 
   #if defined(BUILDING_CHARACTER_INFORMATION_EXPORT)
 
        #define CHARACTER_INFORMATION_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define CHARACTER_INFORMATION_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

   #else // !defined(BUILDING_CHARACTER_INFORMATION_EXPORT)

		#define CHARACTER_INFORMATION_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define CHARACTER_INFORMATION_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

   #endif // BUILDING_CHARACTER_INFORMATION_EXPORT

   #define CHARACTER_INFORMATION_VISIBLE TCRE_SYMBOL_VISIBLE

#endif // defined(BUILDING_CHARACTER_INFORMATION_NO_IMPORT) || defined(BUILDING_CHARACTER_INFORMATION_STATIC)
 
#endif // CHARACTER_INFORMATION_DLL_H
