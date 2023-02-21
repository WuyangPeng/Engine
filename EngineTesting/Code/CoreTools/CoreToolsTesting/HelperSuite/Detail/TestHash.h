///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.2 (2023/02/19 12:54)

#ifndef CORE_TOOLS_HELPER_SUITE_TEST_HASH_H
#define CORE_TOOLS_HELPER_SUITE_TEST_HASH_H

#include "CoreTools/CoreToolsTesting/HelperSuite/HelperSuiteFwd.h"
#include "CoreTools/Helper/UserMacro.h"

#include <string>
#include <vector>

namespace CoreTools
{
    class TestHash
    {
    public:
        using ClassType = TestHash;

    public:
        CLASS_INVARIANT_DECLARE;

        NODISCARD size_t operator()(const TestHashKey& rhs) const noexcept;
    };

}

#endif  // CORE_TOOLS_HELPER_SUITE_TEST_HASH_H