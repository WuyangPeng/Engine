///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 15:41)

#ifndef RENDERING_RENDERER_ENGINE_SUITE_WINDOWS_PARAMETER_TESTING_H
#define RENDERING_RENDERER_ENGINE_SUITE_WINDOWS_PARAMETER_TESTING_H

#include "System/Windows/WindowsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Rendering/DataTypes/Colour.h"
#include "Rendering/RendererEngine/RendererEngineFwd.h"

namespace Rendering
{
    class WindowsParameterTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WindowsParameterTesting;
        using ParentType = UnitTest;

        using String = System::String;
        using ColourType = Colour<float>;
        using WindowsBrushTypes = System::WindowsBrushTypes;

    public:
        explicit WindowsParameterTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;

        void MainTest();

        void AccessTest();

        void ExecuteTest(const WindowsParameter& windowsParameter);
        void SetClearColorTest(WindowsParameter& windowsParameter);
        void SetWindowParameterTest(WindowsParameter& windowsParameter);
        void SetWindowClassNameTest(WindowsParameter& windowsParameter);
        void SetWindowMenuNameTest(WindowsParameter& windowsParameter);
        void SetWindowPictorialParameterTest(WindowsParameter& windowsParameter);

    private:
        ColourType colour;
        std::string windowTitle;
        int windowX;
        int windowY;
        bool isAllowResize;
        String className;
        String menuName;
        int icon;
        bool isIconDefault;
        int cursor;
        bool isCursorDefault;
        WindowsBrushTypes background;
    };
}

#endif  // RENDERING_RENDERER_ENGINE_SUITE_WINDOWS_PARAMETER_TESTING_H