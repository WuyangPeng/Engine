///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 15:34)

#ifndef CORE_TOOLS_HELPER_SUITE_CALL_CONST_MEMBER_FUNCTION_MACRO_H
#define CORE_TOOLS_HELPER_SUITE_CALL_CONST_MEMBER_FUNCTION_MACRO_H

#include "CoreTools/Helper/UserMacro.h"

#include <string>

namespace CoreTools
{
    class CallConstMemberFunctionMacro final
    {
    public:
        using ClassType = CallConstMemberFunctionMacro;

    public:
        explicit CallConstMemberFunctionMacro(const std::string& macro);

        CLASS_INVARIANT_DECLARE;

        NODISCARD const std::string& ConstMemberFunction() const noexcept;
        NODISCARD const std::string& ConstMemberFunction(const std::string& character) const noexcept;
        NODISCARD const std::string& operator[](int index) const noexcept;
        NODISCARD const std::string* operator[](const std::string& character) const noexcept;

        NODISCARD std::string& NonConstCopyMemberFunction() noexcept;
        NODISCARD std::string& NonConstCopyMemberFunction(const std::string& character) noexcept;
        NODISCARD std::string& operator[](int index) noexcept;
        NODISCARD std::string* operator[](const std::string& character) noexcept;

    private:
        std::string macro;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_CALL_CONST_MEMBER_FUNCTION_MACRO_H