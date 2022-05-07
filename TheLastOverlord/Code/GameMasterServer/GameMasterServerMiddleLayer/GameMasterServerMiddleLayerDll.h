// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���İ����汾��0.0.0.1 (2019/10/13 15:52)

#ifndef GAME_MASTER_SERVER_MIDDLE_LAYER_DLL_H
#define GAME_MASTER_SERVER_MIDDLE_LAYER_DLL_H

#include "System/Helper/ExportMacro.h"
#include "Macro/UserMacro.h"

#if defined(BUILDING_GAME_MASTER_SERVER_MIDDLE_LAYER_NO_IMPORT)  || defined(BUILDING_GAME_MASTER_SERVER_MIDDLE_LAYER_STATIC)

  #define GAME_MASTER_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE
  #define GAME_MASTER_SERVER_MIDDLE_LAYER_HIDDEN_DECLARE 
  #define GAME_MASTER_SERVER_MIDDLE_LAYER_VISIBLE

#else // !defined(BUILDING_GAME_MASTER_SERVER_MIDDLE_LAYER_NO_IMPORT) && !defined(BUILDING_GAME_MASTER_SERVER_MIDDLE_LAYER_STATIC)
 
   #if defined(BUILDING_GAME_MASTER_SERVER_MIDDLE_LAYER_EXPORT)
 
        #define GAME_MASTER_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define GAME_MASTER_SERVER_MIDDLE_LAYER_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

   #else // !defined(BUILDING_GAME_MASTER_SERVER_MIDDLE_LAYER_EXPORT)

		#define GAME_MASTER_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define GAME_MASTER_SERVER_MIDDLE_LAYER_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

   #endif // BUILDING_GAME_MASTER_SERVER_MIDDLE_LAYER_EXPORT

   #define GAME_MASTER_SERVER_MIDDLE_LAYER_VISIBLE TCRE_SYMBOL_VISIBLE

#endif // defined(BUILDING_GAME_MASTER_SERVER_MIDDLE_LAYER_NO_IMPORT) || defined(BUILDING_GAME_MASTER_SERVER_MIDDLE_LAYER_STATIC)
 
#endif // GAME_MASTER_SERVER_MIDDLE_LAYER_DLL_H