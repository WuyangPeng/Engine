/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/03/28 15:04)

#ifndef CORE_TOOLS_CONTRACT_FUNCTION_DESCRIBED_H
#define CORE_TOOLS_CONTRACT_FUNCTION_DESCRIBED_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace CoreTools
{
    /// FunctionDescribed�಻����
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
        /// ����ֱ�ӱȽ��ַ���ָ�룬������ʵ�ʵ�ֵ��
        return lhs.GetCurrentFunction() == rhs.GetCurrentFunction() && lhs.GetFileName() == rhs.GetFileName() && lhs.GetLine() == rhs.GetLine();
    }
}

#endif  // CORE_TOOLS_CONTRACT_FUNCTION_DESCRIBED_H
