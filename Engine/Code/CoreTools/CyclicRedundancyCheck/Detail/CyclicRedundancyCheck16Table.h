/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 15:09)

#ifndef CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_CYCLIC_REDUNDANCY_CHECK_16_TABLE_H
#define CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_CYCLIC_REDUNDANCY_CHECK_16_TABLE_H

#include "CoreTools/CoreToolsDll.h"

#include <array>

namespace CoreTools
{
    ///  0x0000, 0xCC01, 0xD801, 0x1400,
    ///  0xF001, 0x3C00, 0x2800, 0xE401,
    ///  0xA001, 0x6C00, 0x7800, 0xB401,
    ///  0x5000, 0x9C01, 0x8801, 0x4400
    class CORE_TOOLS_HIDDEN_DECLARE CyclicRedundancyCheck16Table final
    {
    public:
        using ClassType = CyclicRedundancyCheck16Table;

    public:
        CyclicRedundancyCheck16Table() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD uint16_t Get16Table(int index) const;

    private:
        static constexpr auto tableSize = 16;
        using TableType = std::array<uint16_t, tableSize>;

    private:
        TableType table;
    };
}

#endif  // CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_CYCLIC_REDUNDANCY_CHECK_16_TABLE_H
