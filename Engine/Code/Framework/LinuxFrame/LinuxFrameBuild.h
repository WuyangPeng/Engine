///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/08 19:52)

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
