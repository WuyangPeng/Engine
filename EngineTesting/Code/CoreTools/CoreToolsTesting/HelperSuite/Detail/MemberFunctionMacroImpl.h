/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/14 21:00)

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
        NODISCARD std::string ConstMemberFunction(const std::string& aCharacter) const;
        NODISCARD std::string ConstMemberFunction(int value) const;
        NODISCARD std::string ConstMemberFunction(const std::string* aCharacter) const;

        void NonConstCopyMemberFunction();
        void NonConstCopyMemberFunction(const std::string& aCharacter);
        void NonConstCopyMemberFunction(int value);
        void NonConstCopyMemberFunction(const std::string* aCharacter);

    private:
        std::string character;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_MEMBER_FUNCTION_MACRO_IMPL_H