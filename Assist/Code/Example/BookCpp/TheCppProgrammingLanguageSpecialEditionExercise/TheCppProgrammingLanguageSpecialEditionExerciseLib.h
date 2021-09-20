///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.1 (2021/01/08 21:28)

#ifndef THE_CPP_PROGRAMMING_LANGUAGE_SPECIAL_EDITION_EXERCISE_LIB_H
#define THE_CPP_PROGRAMMING_LANGUAGE_SPECIAL_EDITION_EXERCISE_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_THE_CPP_PROGRAMMING_LANGUAGE_SPECIAL_EDITION_EXERCISE_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "TheCppProgrammingLanguageSpecialEditionExerciseD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "TheCppProgrammingLanguageSpecialEditionExercise.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_THE_CPP_PROGRAMMING_LANGUAGE_SPECIAL_EDITION_EXERCISE_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "TheCppProgrammingLanguageSpecialEditionExerciseStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "TheCppProgrammingLanguageSpecialEditionExerciseStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_THE_CPP_PROGRAMMING_LANGUAGE_SPECIAL_EDITION_EXERCISE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // THE_CPP_PROGRAMMING_LANGUAGE_SPECIAL_EDITION_EXERCISE_LIB_H
