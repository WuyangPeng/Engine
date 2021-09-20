// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.1.0.1 (2020/04/05 17:51)

#ifndef BOOK_UML_DLL_H
#define BOOK_UML_DLL_H

#include "System/Helper/ExportMacro.h"
#include "Helper/UserMacro.h"

#if defined(BUILDING_BOOK_UML_NO_IMPORT) || defined(BUILDING_BOOK_UML_STATIC)

  #define BOOK_UML_DEFAULT_DECLARE
  #define BOOK_UML_HIDDEN_DECLARE 
  #define BOOK_UML_VISIBLE

#else // !defined(BUILDING_BOOK_UML_NO_IMPORT) && !defined(BUILDING_BOOK_UML_STATIC)
 
   #if defined(BUILDING_BOOK_UML_EXPORT)
 
        #define BOOK_UML_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define BOOK_UML_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

   #else // !defined(BUILDING_BOOK_UML_EXPORT)

		#define BOOK_UML_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define BOOK_UML_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

   #endif // BUILDING_BOOK_UML_EXPORT

   #define BOOK_UML_VISIBLE TCRE_SYMBOL_VISIBLE

#endif // defined(BUILDING_BOOK_UML_NO_IMPORT) || defined(BUILDING_BOOK_UML_STATIC)
 
#endif // BOOK_UML_DLL_H
