/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/28 15:04)

#ifndef CORE_TOOLS_CONTRACT_FUNCTION_DESCRIBED_H
#define CORE_TOOLS_CONTRACT_FUNCTION_DESCRIBED_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace CoreTools
{
    /// FunctionDescribed类不导出
    class FunctionDescribed final
    {
    public:
        using ClassType = FunctionDescribed;

    public:
        constexpr FunctionDescribed(const char* currentFunction, const char* fileName, int line) noexcept
            : currentFunction{ currentFunction }, fileName{ fileName }, line{ line }
        {
        }

        NODISCARD constexpr const char* GetCurrentFunction() const noexcept
        {
            return currentFunction;
        }

        NODISCARD constexpr const char* GetFileName() const noexcept
        {
            return fileName;
        }

        NODISCARD constexpr int GetLine() const noexcept
        {
            return line;
        }

    private:
        const char* currentFunction;
        const char* fileName;
        int line;
    };

    NODISCARD constexpr bool operator==(const FunctionDescribed& lhs, const FunctionDescribed& rhs)
    {
        /// 这里直接比较字符串指针，而不是实际的值。
        return lhs.GetCurrentFunction() == rhs.GetCurrentFunction() && lhs.GetFileName() == rhs.GetFileName() && lhs.GetLine() == rhs.GetLine();
    }
}

#endif  // CORE_TOOLS_CONTRACT_FUNCTION_DESCRIBED_H
