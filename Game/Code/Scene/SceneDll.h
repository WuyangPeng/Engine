// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê”Œœ∑∞Ê±æ£∫0.0.0.1 (2019/10/05 21:15)

#ifndef SCENE_DLL_H
#define SCENE_DLL_H

#include "System/Helper/ExportMacro.h"
#include "Helper/UserMacro.h"

#if defined(BUILDING_SCENE_NO_IMPORT) || defined(BUILDING_SCENE_STATIC)

  #define SCENE_DEFAULT_DECLARE
  #define SCENE_HIDDEN_DECLARE 
  #define SCENE_VISIBLE

#else // !defined(BUILDING_SCENE_NO_IMPORT) && !defined(BUILDING_SCENE_STATIC)
 
   #if defined(BUILDING_SCENE_EXPORT)
 
        #define SCENE_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define SCENE_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

   #else // !defined(BUILDING_SCENE_EXPORT)

		#define SCENE_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define SCENE_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

   #endif // BUILDING_SCENE_EXPORT

   #define SCENE_VISIBLE TCRE_SYMBOL_VISIBLE

#endif // defined(BUILDING_SCENE_NO_IMPORT) || defined(BUILDING_SCENE_STATIC)
 
#endif // SCENE_DLL_H
