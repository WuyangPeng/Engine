///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.0 (2020/12/27 18:46)

#ifndef CPP_A_DIALOG_LIB_H
#define CPP_A_DIALOG_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_CPP_A_DIALOG_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "CppADialogD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CppADialog.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_CPP_A_DIALOG_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "CppADialogStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CppADialogStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_CPP_A_DIALOG_STATIC

#endif  // TCRE_USE_MSVC

#endif  // CPP_A_DIALOG_LIB_H
