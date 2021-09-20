// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.2.1 (2020/01/18 20:49)

#ifndef MODEL_EDITOR_DLL_DLL_H
#define MODEL_EDITOR_DLL_DLL_H

#include "System/Helper/ExportMacro.h"
#include "Macro/UserMacro.h"

#if defined(BUILDING_MODEL_EDITOR_NO_IMPORT) || defined(BUILDING_MODEL_EDITOR_STATIC)

  #define MODEL_EDITOR_DEFAULT_DECLARE
  #define MODEL_EDITOR_HIDDEN_DECLARE
  #define MODEL_EDITOR_VISIBLE

#else // !defined(BUILDING_MODEL_EDITOR_NO_IMPORT) && !defined(BUILDING_MODEL_EDITOR_STATIC)

   #if defined(BUILDING_MODEL_EDITOR_EXPORT)
 
        #define MODEL_EDITOR_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define MODEL_EDITOR_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

   #else // !defined(BUILDING_MODEL_EDITOR_EXPORT)

		#define MODEL_EDITOR_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define MODEL_EDITOR_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

   #endif // BUILDING_MODEL_EDITOR_EXPORT

   #define MODEL_EDITOR_VISIBLE TCRE_SYMBOL_VISIBLE

#endif // defined(BUILDING_MODEL_EDITORNO_IMPORT) || defined(BUILDING_MODEL_EDITOR_STATIC)

#endif // MODEL_EDITOR_DLL_DLL_H
