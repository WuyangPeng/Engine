///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.8.0.11 (2022/07/18 10:44)

#ifndef SCENE_OBJECT_DLL_H
#define SCENE_OBJECT_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_SCENE_OBJECT_NO_IMPORT) || defined(BUILDING_SCENE_OBJECT_STATIC)

    #define SCENE_OBJECT_DEFAULT_DECLARE
    #define SCENE_OBJECT_HIDDEN_DECLARE
    #define SCENE_OBJECT_VISIBLE

#else  // !defined(BUILDING_SCENE_OBJECT_NO_IMPORT) && !defined(BUILDING_SCENE_OBJECT_STATIC)

    #if defined(BUILDING_SCENE_OBJECT_EXPORT)

        #define SCENE_OBJECT_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define SCENE_OBJECT_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_SCENE_OBJECT_EXPORT)

        #define SCENE_OBJECT_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define SCENE_OBJECT_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_SCENE_OBJECT_EXPORT

    #define SCENE_OBJECT_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_SCENE_OBJECT_NO_IMPORT) || defined(BUILDING_SCENE_OBJECT_STATIC)

#endif  // SCENE_OBJECT_DLL_H
