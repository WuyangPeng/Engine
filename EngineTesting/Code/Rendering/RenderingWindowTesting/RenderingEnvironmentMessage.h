///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.2 (2022/09/11 12:01)

#ifndef RENDERING_WINDOW_TESTING_RENDERING_ENVIRONMENT_MESSAGE_H
#define RENDERING_WINDOW_TESTING_RENDERING_ENVIRONMENT_MESSAGE_H

#include "Framework/WindowProcess/WindowMessageUnitTestSuiteDetail.h"

namespace RenderingWindowTesting
{
    class RenderingEnvironmentMessage : public Framework::WindowMessageUnitTestSuite
    {
    public:
        using ClassType = RenderingEnvironmentMessage;
        using ParentType = WindowMessageUnitTestSuite;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        RenderingEnvironmentMessage(int64_t delta, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void InitSuite() final;

        void AddRenderersSuite();
    };

    using RenderingWindowHandle = Framework::WindowProcessHandle<RenderingEnvironmentMessage>;
}

#endif  // RENDERING_WINDOW_TESTING_RENDERING_ENVIRONMENT_MESSAGE_H
