// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.3.0.2 (2020/06/04 13:00)

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
        WindowMessageLoop1(WindowsHInstance instance, const char* commandLine, const WindowApplicationInformation& information,
                           const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_FINAL_DECLARE;

    protected:
        int EnterMessageLoop() final;

    private:
        static void DisplayFunction(WindowsHWnd hwnd, int64_t timeDelta) noexcept;

        void EnterOldMessageLoop(const String& className);
        void EnterNewMessageLoop(const String& className);
    };
}

#endif  // WINDOW_MESSAGE_LOOP1_H