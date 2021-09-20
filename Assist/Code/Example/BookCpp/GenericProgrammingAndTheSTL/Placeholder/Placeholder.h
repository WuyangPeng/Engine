///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.0 (2021/02/27 12:45)

#ifndef GENERIC_PROGRAMMING_AND_THE_STL_PLACEHOLDER_PLACEHOLDER_H
#define GENERIC_PROGRAMMING_AND_THE_STL_PLACEHOLDER_PLACEHOLDER_H

#include "Example/BookCpp/GenericProgrammingAndTheSTL/GenericProgrammingAndTheSTLDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace GenericProgrammingAndTheSTL
{
    class GENERIC_PROGRAMMING_AND_THE_STL_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // GENERIC_PROGRAMMING_AND_THE_STL_PLACEHOLDER_PLACEHOLDER_H
