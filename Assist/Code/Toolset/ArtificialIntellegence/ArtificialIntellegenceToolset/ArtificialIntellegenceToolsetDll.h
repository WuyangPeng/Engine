// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.2.0 (2020/01/08 21:28)

#ifndef ARTIFICIAL_INTELLEGENCE_TOOLSET_DLL_DLL_H
#define ARTIFICIAL_INTELLEGENCE_TOOLSET_DLL_DLL_H

#include "System/Helper/ExportMacro.h"
#include "ArtificialIntellegence/Helper/UserMacro.h"

#if defined(BUILDING_ARTIFICIAL_INTELLEGENCE_TOOLSET_NO_IMPORT) || defined(BUILDING_ARTIFICIAL_INTELLEGENCE_STATIC)

  #define ARTIFICIAL_INTELLEGENCE_TOOLSET_DEFAULT_DECLARE
  #define ARTIFICIAL_INTELLEGENCE_TOOLSET_HIDDEN_DECLARE
  #define ARTIFICIAL_INTELLEGENCE_TOOLSET_VISIBLE

#else // !defined(BUILDING_ARTIFICIAL_INTELLEGENCE_TOOLSET_NO_IMPORT) && !defined(BUILDING_ARTIFICIAL_INTELLEGENCE_STATIC)

   #if defined(BUILDING_ARTIFICIAL_INTELLEGENCE_TOOLSET_EXPORT)
 
        #define ARTIFICIAL_INTELLEGENCE_TOOLSET_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define ARTIFICIAL_INTELLEGENCE_TOOLSET_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

   #else // !defined(BUILDING_ARTIFICIAL_INTELLEGENCE_TOOLSET_EXPORT)

		#define ARTIFICIAL_INTELLEGENCE_TOOLSET_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define ARTIFICIAL_INTELLEGENCE_TOOLSET_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

   #endif // BUILDING_ARTIFICIAL_INTELLEGENCE_TOOLSET_EXPORT

   #define ARTIFICIAL_INTELLEGENCE_TOOLSET_VISIBLE TCRE_SYMBOL_VISIBLE

#endif // defined(BUILDING_ARTIFICIAL_INTELLEGENCE_TOOLSET_NO_IMPORT) || defined(BUILDING_ARTIFICIAL_INTELLEGENCE_STATIC)

#endif // ARTIFICIAL_INTELLEGENCE_TOOLSET_DLL_DLL_H
