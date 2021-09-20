// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.0.3 (2019/10/01 11:14)

#ifndef PERL_LIB_EXAMPLE_DLL_H
#define PERL_LIB_EXAMPLE_DLL_H

#include "System/Helper/ExportMacro.h"
#include "Macro/UserMacro.h"

#if defined(PERL_LIB_EXAMPLE_NO_IMPORT) || defined(BUILDING_PERL_LIB_EXAMPLE_STATIC)

  #define PERL_LIB_EXAMPLE_DEFAULT_DECLARE
  #define PERL_LIB_EXAMPLE_HIDDEN_DECLARE
  #define PERL_LIB_EXAMPLE_VISIBLE

#else // !defined(PERL_LIB_EXAMPLE_NO_IMPORT) && !defined(BUILDING_PERL_LIB_EXAMPLE_STATIC)

   #if defined(PERL_LIB_EXAMPLE_EXPORT)
 
        #define PERL_LIB_EXAMPLE_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define PERL_LIB_EXAMPLE_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

   #else // !defined(PERL_LIB_EXAMPLE_EXPORT)

		#define PERL_LIB_EXAMPLE_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define PERL_LIB_EXAMPLE_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

   #endif // PERL_LIB_EXAMPLE_EXPORT

   #define PERL_LIB_EXAMPLE_VISIBLE TCRE_SYMBOL_VISIBLE

#endif // defined(PERL_LIB_EXAMPLE_NO_IMPORT) || defined(BUILDING_PERL_LIB_EXAMPLE_STATIC)

#endif // PERL_LIB_EXAMPLE_DLL_H
