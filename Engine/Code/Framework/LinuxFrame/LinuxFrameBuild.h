/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:17)

#ifndef FRAMEWORK_LINUX_LINUX_FRAME_BUILD_H
#define FRAMEWORK_LINUX_LINUX_FRAME_BUILD_H

namespace Framework
{
    template <typename LinuxProcess>
    class LinuxFrameBuild
    {
    public:
        using ClassType = LinuxFrameBuild<LinuxProcess>;

    public:
        LinuxFrameBuild() noexcept;
        virtual ~LinuxFrameBuild() noexcept = default;
        LinuxFrameBuild(const LinuxFrameBuild& rhs) noexcept = default;
        LinuxFrameBuild& operator=(const LinuxFrameBuild& rhs) noexcept = default;
        LinuxFrameBuild(LinuxFrameBuild&& rhs) noexcept = default;
        LinuxFrameBuild& operator=(LinuxFrameBuild&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        void EnterMessageLoop() noexcept;
    };
}

#endif  // FRAMEWORK_LINUX_LINUX_FRAME_BUILD_H
