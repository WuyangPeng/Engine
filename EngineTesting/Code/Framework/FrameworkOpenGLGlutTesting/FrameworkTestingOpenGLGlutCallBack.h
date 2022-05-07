// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.1.0.2 (2020/04/29 11:27)

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
        virtual std::string GetSuiteName() const;

        void AddSuite() override;
        void AddOpenGLGlutFrameSuite();
    };

    using OpenGLGlutProcessFrameworkTesting = OpenGLGlutProcess<FrameworkTestingOpenGLGlutCallBack>;
}

#endif  // FRAMEWORK_TESTING_FRAMEWORK_TESTING_WINDOW_MESSAGE_H
