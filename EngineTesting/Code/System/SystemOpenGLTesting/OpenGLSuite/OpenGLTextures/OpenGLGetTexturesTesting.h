///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/16 23:31)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_GET_TEXTURES_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_GET_TEXTURES_TESTING_H

#include "OpenGLTexturesTestingBase.h"

namespace System
{
    class OpenGLGetTexturesTesting final : public OpenGLTexturesTestingBase
    {
    public:
        using ClassType = OpenGLGetTexturesTesting;
        using ParentType = OpenGLTexturesTestingBase;

    public:
        explicit OpenGLGetTexturesTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void OpenGLGetTextureTest();
        void OpenGLGetTexturesTest();

        void DoOpenGLGetTexturesTest(const TexturesType& textures);
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_GET_TEXTURES_TESTING_H