///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.0 (2023/01/14 15:58)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_PROGRAM_RESOURCE_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_PROGRAM_RESOURCE_TESTING_H

#include "OpenGLProgramResourceTestingBase.h"

namespace System
{
    class OpenGLProgramResourceTesting final : public OpenGLProgramResourceTestingBase
    {
    public:
        using ClassType = OpenGLProgramResourceTesting;
        using ParentType = OpenGLProgramResourceTestingBase;

    public:
        explicit OpenGLProgramResourceTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using PropertiesContainer = std::vector<OpenGLEnum>;
        using PropertiesResultType = std::vector<OpenGLInt>;
        using ResourceNameType = std::vector<OpenGLChar>;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ProgramResourceTest();

        void DoProgramResourceTest(OpenGLUInt programHandle);
        void ShaderTest(OpenGLUInt shaderHandle, OpenGLUInt programHandle);
        void ProgramPropertiesTest(OpenGLUInt programHandle);
        void DoProgramPropertiesTest(OpenGLUInt programHandle, int index);
        void ProgramResourceNameTest(OpenGLUInt programHandle, int numBytes, int index);

    private:
        PropertiesContainer properties;
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_PROGRAM_RESOURCE_TESTING_H