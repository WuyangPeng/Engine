///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.0 (2021/02/20 0:13)

#include "Example/BookCpp/ExceptionalCppStyle/ExceptionalCppStyleExport.h"

#include "ExceptionalCppStyle.h"

#ifndef BUILDING_EXCEPTIONAL_CPP_STYLE_STATIC

    #include "DllLib.h"

#else  // BUILDING_EXCEPTIONAL_CPP_STYLE_STATIC

namespace ExceptionalCppStyle
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_EXCEPTIONAL_CPP_STYLE_STATIC
