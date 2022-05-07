///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/06 13:57)

#ifndef FRAMEWORK_CONSOLE_CONSOLE_FRAME_BUILD_H
#define FRAMEWORK_CONSOLE_CONSOLE_FRAME_BUILD_H

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
