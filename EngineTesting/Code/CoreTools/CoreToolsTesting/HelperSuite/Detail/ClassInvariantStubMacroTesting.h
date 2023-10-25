///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 15:34)

#ifndef CORE_TOOLS_HELPER_SUITE_CLASS_INVARIANT_STUB_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_CLASS_INVARIANT_STUB_MACRO_TESTING_H

#include "CoreTools/Helper/UserMacro.h"

// ClassInvariantMacroTesting测试所需
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