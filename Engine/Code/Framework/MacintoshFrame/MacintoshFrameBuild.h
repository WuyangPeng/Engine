/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 15:16)

#ifndef FRAMEWORK_MACINTOSH_MACINTOSH_FRAME_BUILD_H
#define FRAMEWORK_MACINTOSH_MACINTOSH_FRAME_BUILD_H

#include "Rendering/RenderingDll.h"

namespace Framework
{
    template <typename MacintoshProcess>
    class MacintoshFrameBuild
    {
    public:
        using ClassType = MacintoshFrameBuild<MacintoshProcess>;

    public:
        MacintoshFrameBuild() noexcept;
        virtual ~MacintoshFrameBuild() noexcept = default;
        MacintoshFrameBuild(const MacintoshFrameBuild& rhs) noexcept = default;
        MacintoshFrameBuild& operator=(const MacintoshFrameBuild& rhs) noexcept = default;
        MacintoshFrameBuild(MacintoshFrameBuild&& rhs) noexcept = default;
        MacintoshFrameBuild& operator=(MacintoshFrameBuild&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        void EnterMessageLoop() noexcept;
    };
}

#endif  // FRAMEWORK_MACINTOSH_MACINTOSH_FRAME_BUILD_H
