///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.0 (2021/02/20 0:13)

#include "Example/BookCpp/ExceptionalCpp/ExceptionalCppExport.h"

#include "ExceptionalCpp.h"

#ifndef BUILDING_EXCEPTIONAL_CPP_STATIC

    #include "DllLib.h"

#else  // BUILDING_EXCEPTIONAL_CPP_STATIC

namespace ExceptionalCpp
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_EXCEPTIONAL_CPP_STATIC
