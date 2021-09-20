// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/12 14:02)

#ifndef OFFLINE_SERVER_CORE_DLL_H
#define OFFLINE_SERVER_CORE_DLL_H

#include "System/Helper/ExportMacro.h"
#include "Macro/UserMacro.h"

#if defined(BUILDING_OFFLINE_SERVER_CORE_NO_IMPORT)  || defined(BUILDING_OFFLINE_SERVER_CORE_STATIC)

  #define OFFLINE_SERVER_CORE_DEFAULT_DECLARE
  #define OFFLINE_SERVER_CORE_HIDDEN_DECLARE 
  #define OFFLINE_SERVER_CORE_VISIBLE

#else // !defined(BUILDING_OFFLINE_SERVER_CORE_NO_IMPORT) && !defined(BUILDING_OFFLINE_SERVER_CORE_STATIC)
 
   #if defined(BUILDING_OFFLINE_SERVER_CORE_EXPORT)
 
        #define OFFLINE_SERVER_CORE_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define OFFLINE_SERVER_CORE_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

   #else // !defined(BUILDING_OFFLINE_SERVER_CORE_EXPORT)

		#define OFFLINE_SERVER_CORE_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define OFFLINE_SERVER_CORE_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

   #endif // BUILDING_OFFLINE_SERVER_CORE_EXPORT

   #define OFFLINE_SERVER_CORE_VISIBLE TCRE_SYMBOL_VISIBLE

#endif // defined(BUILDING_OFFLINE_SERVER_CORE_NO_IMPORT) || defined(BUILDING_OFFLINE_SERVER_CORE_STATIC)
 
#endif // OFFLINE_SERVER_CORE_DLL_H
