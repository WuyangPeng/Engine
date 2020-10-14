//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/10 13:05)

#ifndef CORE_TOOLS_CONTRACT_FUNCTION_DESCRIBED_H
#define CORE_TOOLS_CONTRACT_FUNCTION_DESCRIBED_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE FunctionDescribed final
    {
    public:
        using ClassType = FunctionDescribed;

    public:
        FunctionDescribed(const char* currentFunction, const char* fileName, int line) noexcept;

        [[nodiscard]] const char* GetCurrentFunction() const noexcept;
        [[nodiscard]] const char* GetFileName() const noexcept;
        [[nodiscard]] int GetLine() const noexcept;

    private:
        const char* m_CurrentFunction;
        const char* m_FileName;
        int m_Line;
    };
}

#endif  // CORE_TOOLS_CONTRACT_FUNCTION_DESCRIBED_H
