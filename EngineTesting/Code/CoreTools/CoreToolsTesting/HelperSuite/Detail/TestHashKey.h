///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/11 20:55)

#ifndef CORE_TOOLS_HELPER_SUITE_TEST_HASH_KEY_H
#define CORE_TOOLS_HELPER_SUITE_TEST_HASH_KEY_H

#include "CoreTools/Helper/UserMacro.h"

#include <string>
#include <vector>

namespace CoreTools
{
    class TestHashKey
    {
    public:
        using ClassType = TestHashKey;

    public:
        explicit TestHashKey(std::string name) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::size_t GetHashValue() const noexcept;
        NODISCARD bool operator==(const TestHashKey& rhs) const noexcept;

    private:
        std::string name;
        int64_t buffer;
        int key;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_TEST_HASH_KEY_H