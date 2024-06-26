/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/14 12:13)

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