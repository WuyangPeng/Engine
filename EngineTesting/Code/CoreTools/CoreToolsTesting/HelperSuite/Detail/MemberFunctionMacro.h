///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 15:34)

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