///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/11 20:53)

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

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(InitializeTerminator);

#include SYSTEM_WARNING_POP
}

#endif  // CORE_TOOLS_HELPER_SUITE_INITIALIZE_TERMINATOR_H
