///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.0 (2020/12/26 20:20)

#ifndef PROGRAMMING_PRINCIPLES_AND_PRACTICE_USING_CPP_DLL_H
#define PROGRAMMING_PRINCIPLES_AND_PRACTICE_USING_CPP_DLL_H

#include "Helper/UserMacro.h"
#include "System/Helper/ExportMacro.h"

#if defined(BUILDING_PROGRAMMING_PRINCIPLES_AND_PRACTICE_USING_CPP_NO_IMPORT) || defined(BUILDING_PROGRAMMING_PRINCIPLES_AND_PRACTICE_USING_CPP_STATIC)

    #define PROGRAMMING_PRINCIPLES_AND_PRACTICE_USING_CPP_DEFAULT_DECLARE
    #define PROGRAMMING_PRINCIPLES_AND_PRACTICE_USING_CPP_HIDDEN_DECLARE
    #define PROGRAMMING_PRINCIPLES_AND_PRACTICE_USING_CPP_VISIBLE

#else  // !defined(BUILDING_PROGRAMMING_PRINCIPLES_AND_PRACTICE_USING_CPP_NO_IMPORT) && !defined(BUILDING_PROGRAMMING_PRINCIPLES_AND_PRACTICE_USING_CPP_STATIC)

    #if defined(BUILDING_PROGRAMMING_PRINCIPLES_AND_PRACTICE_USING_CPP_EXPORT)

        #define PROGRAMMING_PRINCIPLES_AND_PRACTICE_USING_CPP_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define PROGRAMMING_PRINCIPLES_AND_PRACTICE_USING_CPP_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

    #else  // !defined(BUILDING_PROGRAMMING_PRINCIPLES_AND_PRACTICE_USING_CPP_EXPORT)

        #define PROGRAMMING_PRINCIPLES_AND_PRACTICE_USING_CPP_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define PROGRAMMING_PRINCIPLES_AND_PRACTICE_USING_CPP_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

    #endif  // BUILDING_PROGRAMMING_PRINCIPLES_AND_PRACTICE_USING_CPP_EXPORT

    #define PROGRAMMING_PRINCIPLES_AND_PRACTICE_USING_CPP_VISIBLE TCRE_SYMBOL_VISIBLE

#endif  // defined(BUILDING_PROGRAMMING_PRINCIPLES_AND_PRACTICE_USING_CPP_NO_IMPORT) || defined(BUILDING_PROGRAMMING_PRINCIPLES_AND_PRACTICE_USING_CPP_STATIC)

#endif  // PROGRAMMING_PRINCIPLES_AND_PRACTICE_USING_CPP_DLL_H
