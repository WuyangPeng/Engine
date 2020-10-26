//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/19 16:46)

#ifndef CORE_TOOLS_MEMORY_TOOLS_RANDOM_H
#define CORE_TOOLS_MEMORY_TOOLS_RANDOM_H

// 一个简单的伪随机数生成器。它至少产生32位随机数（大于rand()的15位）。
// 如果在构造中没有给出种子，状态被设置为一个固定值。这对于再现随机数流是很有用的。

#include "CoreTools/CoreToolsDll.h"

#include <array>

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE Random final
    {
    public:
        using ClassType = Random;

    public:
        Random() noexcept;
        explicit Random(uint32_t seed) noexcept;

        CLASS_INVARIANT_DECLARE;

        // 生成一个完整的32位的随机数。
        [[nodiscard]] uint32_t Generate() noexcept;

        // 生成一个正的32位随机数。
        [[nodiscard]] int GeneratePositive() noexcept;

    private:
        void GenerateSeeds() noexcept;

        // 返回一个新的数字由一个仅依赖于状态的简单生成器产生。
        [[nodiscard]] uint32_t GenerateSimple() noexcept;

    private:
        static constexpr auto sm_TableSize = 250;

        // 这个单一的种子被用于初始化一个简单的发生器。
        uint32_t m_State;

        int m_Index0;
        int m_Index1;
        std::array<uint32_t, sm_TableSize> m_Table;
    };
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_RANDOM_H
