/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/13 20:32)

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