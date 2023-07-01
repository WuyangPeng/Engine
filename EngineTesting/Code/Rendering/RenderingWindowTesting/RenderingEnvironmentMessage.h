///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/25 16:11)

#ifndef RENDERING_WINDOW_TESTING_RENDERING_ENVIRONMENT_MESSAGE_H
#define RENDERING_WINDOW_TESTING_RENDERING_ENVIRONMENT_MESSAGE_H

#include "Framework/WindowProcess/WindowMessageUnitTestSuiteDetail.h"

namespace RenderingWindowTesting
{
    class RenderingEnvironmentMessage final : public Framework::WindowMessageUnitTestSuite
    {
    public:
        using ClassType = RenderingEnvironmentMessage;
        using ParentType = WindowMessageUnitTestSuite;

        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        RenderingEnvironmentMessage(int64_t delta, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void InitSuite() override;

        void AddRendererEngineSuite();
    };

    using RenderingWindowHandle = Framework::WindowProcessHandle<RenderingEnvironmentMessage>;
}

#endif  // RENDERING_WINDOW_TESTING_RENDERING_ENVIRONMENT_MESSAGE_H
