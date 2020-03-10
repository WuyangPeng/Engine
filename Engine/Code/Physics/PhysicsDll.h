// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 14:45)

#ifndef PHYSICS_DLL_H
#define PHYSICS_DLL_H

#include "System/Helper/ExportMacro.h"
#include "Physics/Macro/UserMacro.h"
 
#if defined(BUILDING_PHYSICS_NO_IMPORT) || defined(BUILDING_PHYSICS_STATIC)

  #define PHYSICS_DEFAULT_DECLARE
  #define PHYSICS_HIDDEN_DECLARE 
  #define PHYSICS_VISIBLE

#else // !defined(BUILDING_PHYSICS_NO_IMPORT) && !defined(BUILDING_PHYSICS_STATIC)
 
   #if defined(BUILDING_PHYSICS_EXPORT)
 
        #define PHYSICS_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define PHYSICS_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

   #else // !defined(BUILDING_PHYSICS_EXPORT)

		#define PHYSICS_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define PHYSICS_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

   #endif // BUILDING_PHYSICS_EXPORT

   #define SYSTEM_VISIBLE TCRE_SYMBOL_VISIBLE

#endif // defined(BUILDING_PHYSICS_NO_IMPORT) || defined(BUILDING_PHYSICS_STATIC)

#endif // PHYSICS_DLL_H
 