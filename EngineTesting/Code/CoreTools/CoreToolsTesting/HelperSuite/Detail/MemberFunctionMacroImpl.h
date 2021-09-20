///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.1 (2021/08/16 21:23)

#ifndef CORE_TOOLS_HELPER_SUITE_MEMBER_FUNCTION_MACRO_IMPL_H
#define CORE_TOOLS_HELPER_SUITE_MEMBER_FUNCTION_MACRO_IMPL_H

#include "CoreTools/Helper/UserMacro.h"

#include <string>

namespace CoreTools
{
    class MemberFunctionMacroImpl final
    {
    public:
        using ClassType = MemberFunctionMacroImpl;

    public:
        MemberFunctionMacroImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::string ConstMemberFunction() const;
        NODISCARD std::string ConstMemberFunction(const std::string& character) const;
        NODISCARD std::string ConstMemberFunction(int value) const;
        NODISCARD std::string ConstMemberFunction(const std::string* character) const;

        void NonConstCopyMemberFunction();
        void NonConstCopyMemberFunction(const std::string& character);
        void NonConstCopyMemberFunction(int value);
        void NonConstCopyMemberFunction(const std::string* character);

    private:
        std::string m_Character;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_MEMBER_FUNCTION_MACRO_IMPL_H