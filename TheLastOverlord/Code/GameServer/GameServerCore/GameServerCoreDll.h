// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/11 16:58)

#ifndef GAME_SERVER_CORE_DLL_H
#define GAME_SERVER_CORE_DLL_H

#include "System/Helper/ExportMacro.h"
#include "Macro/UserMacro.h"

#if defined(BUILDING_GAME_SERVER_CORE_NO_IMPORT)  || defined(BUILDING_GAME_SERVER_CORE_STATIC)

  #define GAME_SERVER_CORE_DEFAULT_DECLARE
  #define GAME_SERVER_CORE_HIDDEN_DECLARE 
  #define GAME_SERVER_CORE_VISIBLE

#else // !defined(BUILDING_GAME_SERVER_CORE_NO_IMPORT) && !defined(BUILDING_GAME_SERVER_CORE_STATIC)
 
   #if defined(BUILDING_GAME_SERVER_CORE_EXPORT)
 
        #define GAME_SERVER_CORE_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define GAME_SERVER_CORE_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

   #else // !defined(BUILDING_GAME_SERVER_CORE_EXPORT)

		#define GAME_SERVER_CORE_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define GAME_SERVER_CORE_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

   #endif // BUILDING_GAME_SERVER_CORE_EXPORT

   #define GAME_SERVER_CORE_VISIBLE TCRE_SYMBOL_VISIBLE

#endif // defined(BUILDING_GAME_SERVER_CORE_NO_IMPORT) || defined(BUILDING_GAME_SERVER_CORE_STATIC)
 
#endif // GAME_SERVER_CORE_DLL_H