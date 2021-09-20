// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.3.0 (2020/03/24 21:31)

#ifndef BOOK_MODE_DLL_H
#define BOOK_MODE_DLL_H

#include "System/Helper/ExportMacro.h"
#include "Helper/UserMacro.h"

#if defined(BUILDING_BOOK_MODE_NO_IMPORT) || defined(BUILDING_BOOK_MODE_STATIC)

  #define BOOK_MODE_DEFAULT_DECLARE
  #define BOOK_MODE_HIDDEN_DECLARE 
  #define BOOK_MODE_VISIBLE

#else // !defined(BUILDING_BOOK_MODE_NO_IMPORT) && !defined(BUILDING_BOOK_MODE_STATIC)
 
   #if defined(BUILDING_BOOK_MODE_EXPORT)
 
        #define BOOK_MODE_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define BOOK_MODE_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

   #else // !defined(BUILDING_BOOK_MODE_EXPORT)

		#define BOOK_MODE_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define BOOK_MODE_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

   #endif // BUILDING_BOOK_MODE_EXPORT

   #define BOOK_MODE_VISIBLE TCRE_SYMBOL_VISIBLE

#endif // defined(BUILDING_BOOK_MODE_NO_IMPORT) || defined(BUILDING_BOOK_MODE_STATIC)
 
#endif // BOOK_MODE_DLL_H
