/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/14 12:13)

#ifndef CORE_TOOLS_HELPER_SUITE_TEST_HASH_H
#define CORE_TOOLS_HELPER_SUITE_TEST_HASH_H

#include "CoreTools/CoreToolsTesting/HelperSuite/HelperSuiteFwd.h"
#include "CoreTools/Helper/UserMacro.h"

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