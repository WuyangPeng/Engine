// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.0.3 (2019/10/02 9:37)

#ifndef OGRE_LIB_EXAMPLE_DLL_H
#define OGRE_LIB_EXAMPLE_DLL_H

#include "System/Helper/ExportMacro.h"
#include "Macro/UserMacro.h"

#if defined(OGRE_LIB_EXAMPLE_NO_IMPORT) || defined(BUILDING_OGRE_LIB_EXAMPLE_STATIC)

  #define OGRE_LIB_EXAMPLE_DEFAULT_DECLARE
  #define OGRE_LIB_EXAMPLE_HIDDEN_DECLARE
  #define OGRE_LIB_EXAMPLE_VISIBLE

#else // !defined(OGRE_LIB_EXAMPLE_NO_IMPORT) && !defined(OGRE_LIB_EXAMPLE_STATIC)

   #if defined(OGRE_LIB_EXAMPLE_EXPORT)
 
        #define OGRE_LIB_EXAMPLE_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define OGRE_LIB_EXAMPLE_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

   #else // !defined(OGRE_LIB_EXAMPLE_EXPORT)

		#define OGRE_LIB_EXAMPLE_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define OGRE_LIB_EXAMPLE_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

   #endif // OGRE_LIB_EXAMPLE_EXPORT

   #define OGRE_LIB_EXAMPLE_VISIBLE TCRE_SYMBOL_VISIBLE

#endif // defined(OGRE_LIB_EXAMPLE_NO_IMPORT) || defined(OGRE_LIB_EXAMPLE_STATIC)

#endif // OGRE_LIB_EXAMPLE_DLL_H
