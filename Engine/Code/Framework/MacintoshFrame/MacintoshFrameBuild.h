///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:41)

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
