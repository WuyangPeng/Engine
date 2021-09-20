// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê”Œœ∑∞Ê±æ£∫0.0.0.1 (2019/10/05 21:46)

#ifndef STATUSDLL_H
#define STATUSDLL_H

#include "System/Helper/ExportMacro.h"
#include "Helper/UserMacro.h"

#if defined(BUILDING_STATUSNO_IMPORT) || defined(BUILDING_STATUSSTATIC)

  #define STATUSDEFAULT_DECLARE
  #define STATUSHIDDEN_DECLARE 
  #define STATUSVISIBLE

#else // !defined(BUILDING_STATUSNO_IMPORT) && !defined(BUILDING_STATUSSTATIC)
 
   #if defined(BUILDING_STATUSEXPORT)
 
        #define STATUSDEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define STATUSHIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

   #else // !defined(BUILDING_STATUSEXPORT)

		#define STATUSDEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define STATUSHIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

   #endif // BUILDING_STATUSEXPORT

   #define STATUSVISIBLE TCRE_SYMBOL_VISIBLE

#endif // defined(BUILDING_STATUSNO_IMPORT) || defined(BUILDING_STATUSSTATIC)
 
#endif // STATUSDLL_H
