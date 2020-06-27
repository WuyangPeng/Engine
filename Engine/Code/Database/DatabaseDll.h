// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/16 10:16)

#ifndef DATABASE_DLL_H
#define DATABASE_DLL_H

#include "System/Helper/ExportMacro.h"
#include "Database/Helper/UserMacro.h"
 
#if defined(BUILDING_DATABASE_NO_IMPORT) || defined(BUILDING_DATABASE_STATIC)

  #define DATABASE_DEFAULT_DECLARE
  #define DATABASE_HIDDEN_DECLARE 
  #define DATABASE_VISIBLE

#else // !defined(BUILDING_DATABASE_NO_IMPORT) && !defined(BUILDING_DATABASE_STATIC)
 
   #if defined(BUILDING_DATABASE_EXPORT)
 
        #define DATABASE_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define DATABASE_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

   #else // !defined(BUILDING_DATABASE_EXPORT)

		#define DATABASE_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define DATABASE_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

   #endif // BUILDING_DATABASE_EXPORT

   #define DATABASE_VISIBLE TCRE_SYMBOL_VISIBLE

#endif // defined(BUILDING_DATABASE_NO_IMPORT) || defined(BUILDING_DATABASE_STATIC)

#endif // DATABASE_DLL_H