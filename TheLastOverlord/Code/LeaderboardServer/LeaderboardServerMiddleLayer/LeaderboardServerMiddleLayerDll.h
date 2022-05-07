// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/12 15:34)

#ifndef LEADERBOARD_SERVER_MIDDLE_LAYER_DLL_H
#define LEADERBOARD_SERVER_MIDDLE_LAYER_DLL_H

#include "System/Helper/ExportMacro.h"
#include "Macro/UserMacro.h"

#if defined(BUILDING_LEADERBOARD_SERVER_MIDDLE_LAYER_NO_IMPORT)  || defined(BUILDING_LEADERBOARD_SERVER_MIDDLE_LAYER_STATIC)

  #define LEADERBOARD_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE
  #define LEADERBOARD_SERVER_MIDDLE_LAYER_HIDDEN_DECLARE 
  #define LEADERBOARD_SERVER_MIDDLE_LAYER_VISIBLE

#else // !defined(BUILDING_LEADERBOARD_SERVER_MIDDLE_LAYER_NO_IMPORT) && !defined(BUILDING_LEADERBOARD_SERVER_MIDDLE_LAYER_STATIC)
 
   #if defined(BUILDING_LEADERBOARD_SERVER_MIDDLE_LAYER_EXPORT)
 
        #define LEADERBOARD_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define LEADERBOARD_SERVER_MIDDLE_LAYER_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

   #else // !defined(BUILDING_LEADERBOARD_SERVER_MIDDLE_LAYER_EXPORT)

		#define LEADERBOARD_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define LEADERBOARD_SERVER_MIDDLE_LAYER_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

   #endif // BUILDING_LEADERBOARD_SERVER_MIDDLE_LAYER_EXPORT

   #define LEADERBOARD_SERVER_MIDDLE_LAYER_VISIBLE TCRE_SYMBOL_VISIBLE

#endif // defined(BUILDING_LEADERBOARD_SERVER_MIDDLE_LAYER_NO_IMPORT) || defined(BUILDING_LEADERBOARD_SERVER_MIDDLE_LAYER_STATIC)
 
#endif // LEADERBOARD_SERVER_MIDDLE_LAYER_DLL_H