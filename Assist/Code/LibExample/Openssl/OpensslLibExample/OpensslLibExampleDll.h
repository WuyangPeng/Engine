// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.0.3 (2019/10/01 0:05)

#ifndef OPENSSL_LIB_EXAMPLE_DLL_H
#define OPENSSL_LIB_EXAMPLE_DLL_H

#include "System/Helper/ExportMacro.h"
#include "Macro/UserMacro.h"

#if defined(OPENSSL_LIB_EXAMPLE_NO_IMPORT) || defined(BUILDING_OPENSSL_LIB_EXAMPLE_STATIC)

  #define OPENSSL_LIB_EXAMPLE_DEFAULT_DECLARE
  #define OPENSSL_LIB_EXAMPLE_HIDDEN_DECLARE
  #define OPENSSL_LIB_EXAMPLE_VISIBLE

#else // !defined(OPENSSL_LIB_EXAMPLE_NO_IMPORT) && !defined(OPENSSL_LIB_EXAMPLE_STATIC)

   #if defined(OPENSSL_LIB_EXAMPLE_EXPORT)
 
        #define OPENSSL_LIB_EXAMPLE_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define OPENSSL_LIB_EXAMPLE_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

   #else // !defined(OPENSSL_LIB_EXAMPLE_EXPORT)

		#define OPENSSL_LIB_EXAMPLE_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define OPENSSL_LIB_EXAMPLE_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

   #endif // OPENSSL_LIB_EXAMPLE_EXPORT

   #define OPENSSL_LIB_EXAMPLE_VISIBLE TCRE_SYMBOL_VISIBLE

#endif // defined(OPENSSL_LIB_EXAMPLE_NO_IMPORT) || defined(OPENSSL_LIB_EXAMPLE_STATIC)

#endif // OPENSSL_LIB_EXAMPLE_DLL_H
