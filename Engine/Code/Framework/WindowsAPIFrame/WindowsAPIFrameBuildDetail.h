///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/13 14:00)

#ifndef FRAMEWORK_WINDOWS_API_FRAME_BUILD_DETAIL_H
#define FRAMEWORK_WINDOWS_API_FRAME_BUILD_DETAIL_H

#include "WindowsAPIFrameBuild.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Framework/Application/WindowApplicationInformation.h"

template <typename Process>
Framework::WindowsAPIFrameBuild<Process>::WindowsAPIFrameBuild(HInstance instance, const char* commandLine, const WindowApplicationInformation& information, const EnvironmentDirectory& environmentDirectory)
    : windowRegister{ environmentDirectory, instance, commandLine, information.GetWindowPictorial(), information.GetWindowName() },
      windowCreate{ WindowInstanceParameter{ instance, windowRegister.GetWindowClassName() },
                    WindowCreateParameter{ information.GetWindowTitle(), information.GetStyle() },
                    information.GetWindowSize() },
      windowMessageLoop{ windowRegister.GetFunction() }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

template <typename Process>
Framework::WindowsAPIFrameBuild<Process>::WindowsAPIFrameBuild(WindowsAPIFrameBuild&& rhs) noexcept
    : windowRegister{ std::move(rhs.windowRegister) },
      windowCreate{ std::move(rhs.windowCreate) },
      windowMessageLoop{ std::move(rhs.windowMessageLoop) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

template <typename Process>
Framework::WindowsAPIFrameBuild<Process>& Framework::WindowsAPIFrameBuild<Process>::operator=(WindowsAPIFrameBuild&& rhs) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    windowRegister = std::move(rhs.windowRegister);
    windowCreate = std::move(rhs.windowCreate);
    windowMessageLoop = std::move(rhs.windowMessageLoop);

    return *this;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Process>
bool Framework::WindowsAPIFrameBuild<Process>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Process>
System::WindowsHWnd Framework::WindowsAPIFrameBuild<Process>::GetHwnd() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return windowCreate.GetHwnd();
}

template <typename Process>
System::WindowsHInstance Framework::WindowsAPIFrameBuild<Process>::GetHInstance() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return windowRegister.GetHInstance();
}

template <typename Process>
int Framework::WindowsAPIFrameBuild<Process>::EnterMessageLoop()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (auto process = windowRegister.GetWindowProcess();
        process.Initialize())
    {
        // Ĭ��PreIdle()���������������Ӧ�ó���������ǵĴ����ڴ�����ʾ֮����¼�ѭ����ʼ֮ǰ��
        process.PreIdle();

        const auto result = windowMessageLoop.EnterMessageLoop(windowCreate.GetHwnd());

        process.Terminate();

        return boost::numeric_cast<int>(result);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("���̳�ʼ��ʧ�ܣ�"s));
    }
}

#endif  // FRAMEWORK_WINDOWS_API_FRAME_BUILD_DETAIL_H
