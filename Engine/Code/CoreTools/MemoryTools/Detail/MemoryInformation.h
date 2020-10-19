//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.2 (2020/10/19 13:13)

#ifndef CORE_TOOLS_MEMORY_TOOLS_MEMORY_INFORMATION_H
#define CORE_TOOLS_MEMORY_TOOLS_MEMORY_INFORMATION_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Contract/FunctionDescribed.h"

#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE MemoryInformation final
    {
    public:
        using ClassType = MemoryInformation;

    public:
        MemoryInformation(size_t bytesNumber, int dimensionsNumber, const FunctionDescribed& functionDescribed);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] size_t GetBytesNumber() const noexcept;
        [[nodiscard]] int GetDimensionsNumber() const noexcept;
        [[nodiscard]] const FunctionDescribed& GetFunctionDescribed() const noexcept;
        [[nodiscard]] uint64_t GetUniqueID() const noexcept;

    private:
        size_t m_BytesNumber;
        int m_DimensionsNumber;
        FunctionDescribed m_FunctionDescribed;
        uint64_t m_UniqueID;
    };
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_MEMORY_INFORMATION_H
