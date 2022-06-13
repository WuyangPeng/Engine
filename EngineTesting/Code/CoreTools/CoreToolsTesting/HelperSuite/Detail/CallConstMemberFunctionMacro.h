///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 11:13)

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
        NODISCARD const std::string& ConstMemberFunction(MAYBE_UNUSED const std::string& character) const noexcept;
        NODISCARD const std::string& operator[](MAYBE_UNUSED int index) const noexcept;
        NODISCARD const std::string* operator[](MAYBE_UNUSED const std::string& character) const noexcept;

        NODISCARD std::string& NonConstCopyMemberFunction() noexcept;
        NODISCARD std::string& NonConstCopyMemberFunction(const std::string& character) noexcept;
        NODISCARD std::string& operator[](int index) noexcept;
        NODISCARD std::string* operator[](const std::string& character) noexcept;

    private:
        std::string macro;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_CALL_CONST_MEMBER_FUNCTION_MACRO_H