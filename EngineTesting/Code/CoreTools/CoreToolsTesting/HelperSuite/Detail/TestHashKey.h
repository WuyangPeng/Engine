///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.2 (2023/02/19 12:54)

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
        explicit TestHashKey(const std::string& name);

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::size_t GetHashValue() const noexcept;
        NODISCARD bool operator==(const TestHashKey& rhs) const noexcept;

    private:
        std::string name;
        float buffer;
        int key;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_TEST_HASH_KEY_H