///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.2 (2023/02/12 21:09)

#ifndef CORE_TOOLS_HELPER_SUITE_MEMBER_FUNCTION_MACRO_H
#define CORE_TOOLS_HELPER_SUITE_MEMBER_FUNCTION_MACRO_H

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/CoreToolsTesting/HelperSuite/HelperSuiteFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

#include <string>

namespace CoreTools
{
    class MemberFunctionMacro final
    {
    public:
        NON_COPY_TYPE_DECLARE(MemberFunctionMacro);

    public:
        NODISCARD static MemberFunctionMacro Create();

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
        explicit MemberFunctionMacro(DisableNotThrow disableNotThrow);

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_MEMBER_FUNCTION_MACRO_H