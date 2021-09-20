// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê”Œœ∑∞Ê±æ£∫0.0.0.1 (2019/10/05 22:53)

#ifndef TEAM_DLL_H
#define TEAM_DLL_H

#include "System/Helper/ExportMacro.h"
#include "Helper/UserMacro.h"

#if defined(BUILDING_TEAM_NO_IMPORT) || defined(BUILDING_TEAM_STATIC)

  #define TEAM_DEFAULT_DECLARE
  #define TEAM_HIDDEN_DECLARE 
  #define TEAM_VISIBLE

#else // !defined(BUILDING_TEAM_NO_IMPORT) && !defined(BUILDING_TEAM_STATIC)
 
   #if defined(BUILDING_TEAM_EXPORT)
 
        #define TEAM_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define TEAM_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

   #else // !defined(BUILDING_TEAM_EXPORT)

		#define TEAM_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define TEAM_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

   #endif // BUILDING_TEAM_EXPORT

   #define TEAM_VISIBLE TCRE_SYMBOL_VISIBLE

#endif // defined(BUILDING_TEAM_NO_IMPORT) || defined(BUILDING_TEAM_STATIC)
 
#endif // TEAM_DLL_H
