///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.2 (2023/02/06 15:30)

#ifndef CORE_TOOLS_HELPER_SUITE_CLASS_INVARIANT_STUB_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_CLASS_INVARIANT_STUB_MACRO_TESTING_H

#include "CoreTools/Helper/UserMacro.h"

// ClassInvariantMacroTesting��������
namespace CoreTools
{
    class ClassInvariantStubMacroTesting final
    {
    public:
        using ClassType = ClassInvariantStubMacroTesting;

        CLASS_INVARIANT_DECLARE;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_CLASS_INVARIANT_STUB_MACRO_TESTING_H