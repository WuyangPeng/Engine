///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/05 11:12)

#ifndef WINDOW_MESSAGE_LOOP1_H
#define WINDOW_MESSAGE_LOOP1_H

#include "Framework/MainFunctionHelper/WindowMainFunctionHelper.h"
#include "Framework/WindowProcess/WindowProcess.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuild.h"

namespace Framework
{
    using BaseType = WindowMainFunctionHelper<WindowsAPIFrameBuild, WindowProcessInterface>;

    class WindowMessageLoop1 final : public BaseType
    {
    public:
        using ClassType = WindowMessageLoop1;
        using ParentType = BaseType;

    public:
        WindowMessageLoop1(WindowsHInstance instance, const char* commandLine, const WindowApplicationInformation& information, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_FINAL_DECLARE;

    protected:
        NODISCARD int EnterMessageLoop() final;

    private:
        static void DisplayFunction(WindowsHWnd hwnd, int64_t timeDelta) noexcept;

        void EnterOldMessageLoop(const String& className);
        void EnterNewMessageLoop(const String& className);
    };
}

#endif  // WINDOW_MESSAGE_LOOP1_H