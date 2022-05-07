// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.3.0.1 (2020/05/26 13:56)

#ifndef WIN_MAIN_ENTRY_POINT4_H
#define WIN_MAIN_ENTRY_POINT4_H

#include "Framework/MainFunctionHelper/WindowMainFunctionHelper.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuild.h"

namespace Framework
{
    using BaseType = WindowMainFunctionHelper<WindowsAPIFrameBuild, WindowProcessInterface>;

    class WinMainEntryPoint4 final : public BaseType
    {
    public:
        using ClassType = WinMainEntryPoint4;
        using ParentType = BaseType;

    public:
        WinMainEntryPoint4(WindowsHInstance instance, const char* commandLine, const WindowApplicationInformation& information, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_FINAL_DECLARE;
    };
}

#endif  // WIN_MAIN_ENTRY_POINT4_H
