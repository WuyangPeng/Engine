///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.1 (2021/08/14 23:41)

#ifndef CORE_TOOLS_HELPER_SUITE_INITIALIZE_TERMINATOR_H
#define CORE_TOOLS_HELPER_SUITE_INITIALIZE_TERMINATOR_H

#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/InitializeTerminatorMacro.h"
#include "CoreTools/Helper/UserMacro.h"

namespace CoreTools
{
    class InitializeTerminator final
    {
    public:
        using ClassType = InitializeTerminator;

    public:
        CLASS_INVARIANT_DECLARE;

        CORE_TOOLS_INITIALIZE_TERMINATE_DECLARE(true);

        NODISCARD static bool IsRegister() noexcept;

    private:
        static bool isRegister;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(InitializeTerminator);
#include STSTEM_WARNING_POP
}

#endif  // CORE_TOOLS_HELPER_SUITE_INITIALIZE_TERMINATOR_H
