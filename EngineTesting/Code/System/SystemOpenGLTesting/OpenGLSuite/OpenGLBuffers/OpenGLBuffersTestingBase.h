///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/17 12:13)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_BUFFERS_TESTING_BASE_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_BUFFERS_TESTING_BASE_H

#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"
#include "System/OpenGL/Using/OpenGLUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>

namespace System
{
    class OpenGLBuffersTestingBase : public CoreTools::UnitTest
    {
    public:
        using ClassType = OpenGLBuffersTestingBase;
        using ParentType = UnitTest;

    public:
        explicit OpenGLBuffersTestingBase(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        static constexpr auto bufferSize = 12;
        static constexpr auto bufferDataSize = 256;
        using BufferType = std::array<OpenGLUInt, bufferSize>;
        using BufferDataType = std::array<char, bufferDataSize>;
        using BufferSubDataType = std::array<char, bufferDataSize / 2>;
        using BindBufferContainer = std::vector<BindBuffer>;
        using BindBufferContainerConstIter = BindBufferContainer::const_iterator;

    protected:
        void RandomShuffle();
        void SetBindBufferTest(BindBuffer type, OpenGLUInt buffer) noexcept;
        void SetGLDeleteBufferTest(OpenGLUInt buffer) noexcept;
        void SetGLDeleteBuffersTest(const BufferType& buffers) noexcept;
        void SetGLDeleteFramebufferTest(OpenGLUInt buffer) noexcept;
        void SetGLDeleteFramebuffersTest(const BufferType& buffers) noexcept;
        void SetGLDeleteVertexArrayTest(OpenGLUInt buffer) noexcept;
        void SetGLDeleteVertexArraysTest(const BufferType& buffers) noexcept;
        NODISCARD BindBufferContainerConstIter begin() const noexcept;
        NODISCARD BindBufferContainerConstIter end() const noexcept;
        NODISCARD BindBuffer GetSubDataBindBuffer(size_t index) const;
        NODISCARD size_t GetSubDataBindBufferSize() const;

    private:
        BindBufferContainer bindBuffers;
        BindBufferContainer subDataBindBuffers;
        std::default_random_engine randomEngine;
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_BUFFERS_TESTING_BASE_H