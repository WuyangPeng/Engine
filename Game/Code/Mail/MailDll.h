// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê”Œœ∑∞Ê±æ£∫0.0.0.1 (2019/10/05 23:03)

#ifndef MAIL_DLL_H
#define MAIL_DLL_H

#include "System/Helper/ExportMacro.h"
#include "Helper/UserMacro.h"

#if defined(BUILDING_MAIL_NO_IMPORT) || defined(BUILDING_MAIL_STATIC)

  #define MAIL_DEFAULT_DECLARE
  #define MAIL_HIDDEN_DECLARE 
  #define MAIL_VISIBLE

#else // !defined(BUILDING_MAIL_NO_IMPORT) && !defined(BUILDING_MAIL_STATIC)
 
   #if defined(BUILDING_MAIL_EXPORT)
 
        #define MAIL_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define MAIL_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

   #else // !defined(BUILDING_MAIL_EXPORT)

		#define MAIL_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define MAIL_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

   #endif // BUILDING_MAIL_EXPORT

   #define MAIL_VISIBLE TCRE_SYMBOL_VISIBLE

#endif // defined(BUILDING_MAIL_NO_IMPORT) || defined(BUILDING_MAIL_STATIC)
 
#endif // MAIL_DLL_H
