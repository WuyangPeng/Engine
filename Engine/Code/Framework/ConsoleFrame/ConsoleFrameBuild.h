/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 15:19)

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
