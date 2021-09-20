// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.1.0.3 (2020/04/27 23:59)

#ifndef BOOK_CODE_DLL_H
#define BOOK_CODE_DLL_H

#include "System/Helper/ExportMacro.h"
#include "Helper/UserMacro.h"

#if defined(BUILDING_BOOK_CODE_NO_IMPORT) || defined(BUILDING_BOOK_CODE_STATIC)

  #define BOOK_CODE_DEFAULT_DECLARE
  #define BOOK_CODE_HIDDEN_DECLARE 
  #define BOOK_CODE_VISIBLE

#else // !defined(BUILDING_BOOK_CODE_NO_IMPORT) && !defined(BUILDING_BOOK_CODE_STATIC)
 
   #if defined(BUILDING_BOOK_CODE_EXPORT)
 
        #define BOOK_CODE_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define BOOK_CODE_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

   #else // !defined(BUILDING_BOOK_CODE_EXPORT)

		#define BOOK_CODE_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define BOOK_CODE_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

   #endif // BUILDING_BOOK_CODE_EXPORT

   #define BOOK_CODE_VISIBLE TCRE_SYMBOL_VISIBLE

#endif // defined(BUILDING_BOOK_CODE_NO_IMPORT) || defined(BUILDING_BOOK_CODE_STATIC)
 
#endif // BOOK_CODE_DLL_H
