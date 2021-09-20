// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.0.3 (2019/10/01 1:54)

#ifndef MYSQL_LIB_EXAMPLE_DLL_H
#define MYSQL_LIB_EXAMPLE_DLL_H

#include "System/Helper/ExportMacro.h"
#include "Macro/UserMacro.h"

#if defined(MYSQL_LIB_EXAMPLE_NO_IMPORT) || defined(BUILDING_MYSQL_LIB_EXAMPLE_STATIC)

  #define MYSQL_LIB_EXAMPLE_DEFAULT_DECLARE
  #define MYSQL_LIB_EXAMPLE_HIDDEN_DECLARE
  #define MYSQL_LIB_EXAMPLE_VISIBLE

#else // !defined(MYSQL_LIB_EXAMPLE_NO_IMPORT) && !defined(MYSQL_LIB_EXAMPLE_STATIC)

   #if defined(MYSQL_LIB_EXAMPLE_EXPORT)
 
        #define MYSQL_LIB_EXAMPLE_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define MYSQL_LIB_EXAMPLE_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

   #else // !defined(MYSQL_LIB_EXAMPLE_EXPORT)

		#define MYSQL_LIB_EXAMPLE_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define MYSQL_LIB_EXAMPLE_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

   #endif // MYSQL_LIB_EXAMPLE_EXPORT

   #define MYSQL_LIB_EXAMPLE_VISIBLE TCRE_SYMBOL_VISIBLE

#endif // defined(MYSQL_LIB_EXAMPLE_NO_IMPORT) || defined(MYSQL_LIB_EXAMPLE_STATIC)

#endif // MYSQL_LIB_EXAMPLE_DLL_H