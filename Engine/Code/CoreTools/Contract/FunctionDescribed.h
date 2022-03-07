///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/10 18:31)

#ifndef CORE_TOOLS_CONTRACT_FUNCTION_DESCRIBED_H
#define CORE_TOOLS_CONTRACT_FUNCTION_DESCRIBED_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#ifndef FUNCTION_DESCRIBED_NO_EXPORT

    #define FUNCTION_DESCRIBED_DEFAULT_DECLARE CORE_TOOLS_DEFAULT_DECLARE

#else  // !FUNCTION_DESCRIBED_NO_EXPORT

    #if !defined(BUILDING_CORE_TOOLS_NO_IMPORT) && !defined(BUILDING_CORE_TOOLS_STATIC)
        #define FUNCTION_DESCRIBED_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
    #else  // defined(BUILDING_CORE_TOOLS_NO_IMPORT) || defined(BUILDING_CORE_TOOLS_STATIC)
        #define FUNCTION_DESCRIBED_DEFAULT_DECLARE
    #endif  // !defined(BUILDING_CORE_TOOLS_NO_IMPORT) && !defined(BUILDING_CORE_TOOLS_STATIC)

#endif  // FUNCTION_DESCRIBED_NO_EXPORT

namespace CoreTools
{
    class FUNCTION_DESCRIBED_DEFAULT_DECLARE FunctionDescribed final
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

    NODISCARD constexpr bool FUNCTION_DESCRIBED_DEFAULT_DECLARE operator==(const FunctionDescribed& lhs, const FunctionDescribed& rhs)
    {
        // ����ֱ�ӱȽ��ַ���ָ�룬������ʵ�ʵ�ֵ��
        return lhs.GetCurrentFunction() == rhs.GetCurrentFunction() && lhs.GetFileName() == rhs.GetFileName() && lhs.GetLine() == rhs.GetLine();
    }
}

#endif  // CORE_TOOLS_CONTRACT_FUNCTION_DESCRIBED_H
