///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.1 (2021/08/04 22:52)

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