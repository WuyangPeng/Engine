/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:34)

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
        using BufferType = std::array<OpenGLUnsignedInt, bufferSize>;
        using BufferDataType = std::array<char, bufferDataSize>;
        using BufferSubDataType = std::array<char, bufferDataSize / 2>;
        using BindBufferContainer = std::vector<BindBuffer>;
        using BindBufferContainerConstIter = BindBufferContainer::const_iterator;
        using OpenGLFloatContainer = std::vector<OpenGLFloat>;

    protected:
        void RandomShuffle();
        void SetBindBufferTest(BindBuffer type, OpenGLUnsignedInt buffer) const noexcept;
        void DeleteBufferTest(OpenGLUnsignedInt buffer) const noexcept;
        void DeleteBuffersTest(const BufferType& buffers) const noexcept;
        void DeleteFrameBufferTest(OpenGLUnsignedInt buffer) const noexcept;
        void DeleteFrameBuffersTest(const BufferType& buffers) const noexcept;
        void DeleteVertexArrayTest(OpenGLUnsignedInt buffer) const noexcept;
        void DeleteVertexArraysTest(const BufferType& buffers) const noexcept;

        NODISCARD BindBufferContainerConstIter begin() const noexcept;
        NODISCARD BindBufferContainerConstIter end() const noexcept;
        NODISCARD BindBuffer GetSubDataBindBuffer(int index) const;
        NODISCARD int GetSubDataBindBufferSize() const;

    private:
        BindBufferContainer bindBuffers;
        BindBufferContainer subDataBindBuffers;
        std::default_random_engine randomEngine;
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_BUFFERS_TESTING_BASE_H