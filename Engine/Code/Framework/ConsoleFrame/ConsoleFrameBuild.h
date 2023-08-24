///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/08 19:52)

#ifndef FRAMEWORK_CONSOLE_CONSOLE_FRAME_BUILD_H
#define FRAMEWORK_CONSOLE_CONSOLE_FRAME_BUILD_H

#include "Framework/FrameworkDll.h"

namespace Framework
{
    template <typename ConsoleProcess>
    class ConsoleFrameBuild
    {
    public:
        using ClassType = ConsoleFrameBuild<ConsoleProcess>;

    public:
        ConsoleFrameBuild() noexcept;
        virtual ~ConsoleFrameBuild() noexcept = default;
        ConsoleFrameBuild(const ConsoleFrameBuild& rhs) noexcept = default;
        ConsoleFrameBuild& operator=(const ConsoleFrameBuild& rhs) noexcept = default;
        ConsoleFrameBuild(ConsoleFrameBuild&& rhs) noexcept = default;
        ConsoleFrameBuild& operator=(ConsoleFrameBuild&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        void EnterMessageLoop() noexcept;
    };
}

#endif  // FRAMEWORK_CONSOLE_CONSOLE_FRAME_BUILD_H
