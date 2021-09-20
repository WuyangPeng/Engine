///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.2 (2021/03/27 22:01)

#ifndef STL_TUTORIAL_AND_REFERENCE_GUIDE_DLL_H
#define STL_TUTORIAL_AND_REFERENCE_GUIDE_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_STL_TUTORIAL_AND_REFERENCE_GUIDE_NO_IMPORT) || defined(BUILDING_STL_TUTORIAL_AND_REFERENCE_GUIDE_STATIC)

    #define STL_TUTORIAL_AND_REFERENCE_GUIDE_DEFAULT_DECLARE
    #define STL_TUTORIAL_AND_REFERENCE_GUIDE_HIDDEN_DECLARE
    #define STL_TUTORIAL_AND_REFERENCE_GUIDE_VISIBLE

#else  // !defined(BUILDING_STL_TUTORIAL_AND_REFERENCE_GUIDE_NO_IMPORT) && !defined(BUILDING_STL_TUTORIAL_AND_REFERENCE_GUIDE_STATIC)

    #if defined(BUILDING_STL_TUTORIAL_AND_REFERENCE_GUIDE_EXPORT)

        #define STL_TUTORIAL_AND_REFERENCE_GUIDE_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define STL_TUTORIAL_AND_REFERENCE_GUIDE_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_STL_TUTORIAL_AND_REFERENCE_GUIDE_EXPORT)

        #define STL_TUTORIAL_AND_REFERENCE_GUIDE_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define STL_TUTORIAL_AND_REFERENCE_GUIDE_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_STL_TUTORIAL_AND_REFERENCE_GUIDE_EXPORT

    #define STL_TUTORIAL_AND_REFERENCE_GUIDE_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_STL_TUTORIAL_AND_REFERENCE_GUIDE_NO_IMPORT) || defined(BUILDING_STL_TUTORIAL_AND_REFERENCE_GUIDE_STATIC)

#endif  // STL_TUTORIAL_AND_REFERENCE_GUIDE_DLL_H
