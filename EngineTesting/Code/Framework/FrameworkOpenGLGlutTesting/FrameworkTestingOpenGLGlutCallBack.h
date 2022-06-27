///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/24 15:20)

#ifndef FRAMEWORK_TESTING_FRAMEWORK_TESTING_WINDOW_MESSAGE_H
#define FRAMEWORK_TESTING_FRAMEWORK_TESTING_WINDOW_MESSAGE_H

#include "Framework/OpenGLGlutFrame/OpenGLGlutCallBackUnitTestSuite.h"

namespace Framework
{
    class FrameworkTestingOpenGLGlutCallBack : public OpenGLGlutCallBackUnitTestSuite
    {
    public:
        using ClassType = FrameworkTestingOpenGLGlutCallBack;
        using ParentType = OpenGLGlutCallBackUnitTestSuite;

    public:
        explicit FrameworkTestingOpenGLGlutCallBack(int64_t delta);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        NODISCARD virtual std::string GetSuiteName() const;

        void AddSuite() override;
        void AddOpenGLGlutFrameSuite();
    };

    using OpenGLGlutProcessFrameworkTesting = OpenGLGlutProcess<FrameworkTestingOpenGLGlutCallBack>;
}

#endif  // FRAMEWORK_TESTING_FRAMEWORK_TESTING_WINDOW_MESSAGE_H
