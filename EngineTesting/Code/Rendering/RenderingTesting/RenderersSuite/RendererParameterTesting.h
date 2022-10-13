///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.2 (2022/09/06 9:44)

#ifndef RENDERING_RENDERERS_SUITE_RENDERER_PARAMETER_TESTING_H
#define RENDERING_RENDERERS_SUITE_RENDERER_PARAMETER_TESTING_H

#include "System/Windows/WindowsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Rendering/DataTypes/Colour.h"
#include "Rendering/Renderers/RenderersFwd.h"
#include "Rendering/Resources/ResourcesFwd.h"

namespace Rendering
{
    class RendererParameterTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = RendererParameterTesting;
        using ParentType = UnitTest;

        using String = System::String;
        using ColourType = Colour<float>;
        using WindowsBrushTypes = System::WindowsBrushTypes;

    public:
        explicit RendererParameterTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;

        void MainTest();

        void AccessTest();

        void ExecuteTest(const RendererParameter& rendererParameter);
        void ResizeTest(RendererParameter& rendererParameter);

    private:
        RendererTypes rendererType;
        int windowWidth;
        int windowHeight;
        DataFormatType colorFormat;
        DataFormatType depthStencilFormat;
        int multisamplesNumber;
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

#endif  // RENDERING_RENDERERS_SUITE_RENDERER_PARAMETER_TESTING_H