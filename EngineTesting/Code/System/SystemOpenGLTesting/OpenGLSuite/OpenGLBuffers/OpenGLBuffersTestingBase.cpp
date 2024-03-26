/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:43)

#include "OpenGLBuffersTestingBase.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/OpenGLBuffers.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLBuffersTestingBase::OpenGLBuffersTestingBase(const OStreamShared& stream)
    : ParentType{ stream },
      bindBuffers{ BindBuffer::ArrayBuffer,
                   BindBuffer::ElementArrayBuffer,
                   BindBuffer::PixelUnpackBuffer,
                   BindBuffer::PixelPackBuffer,
                   BindBuffer::ShaderStorageBuffer,
                   BindBuffer::UniformBuffer,
                   BindBuffer::CopyReadBuffer,
                   BindBuffer::CopyWriteBuffer,
                   BindBuffer::AtomicCounterBuffer,
                   BindBuffer::TransformFeedbackBuffer },
      subDataBindBuffers{ BindBuffer::ArrayBuffer,
                          BindBuffer::ElementArrayBuffer,
                          BindBuffer::PixelUnpackBuffer,
                          BindBuffer::PixelPackBuffer,
                          BindBuffer::CopyReadBuffer,
                          BindBuffer::CopyWriteBuffer,
                          BindBuffer::TransformFeedbackBuffer },
      randomEngine{ GetEngineRandomSeed() }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLBuffersTestingBase)

void System::OpenGLBuffersTestingBase::RandomShuffle()
{
    std::ranges::shuffle(subDataBindBuffers, randomEngine);
}

void System::OpenGLBuffersTestingBase::SetBindBufferTest(BindBuffer type, OpenGLUnsignedInt buffer) const noexcept
{
    SetGLBindBuffer(type, buffer);
}

void System::OpenGLBuffersTestingBase::DeleteBufferTest(OpenGLUnsignedInt buffer) const noexcept
{
    SetGLDeleteBuffers(buffer);
}

void System::OpenGLBuffersTestingBase::DeleteBuffersTest(const BufferType& buffers) const noexcept
{
    SetGLDeleteBuffers(bufferSize, buffers.data());
}

void System::OpenGLBuffersTestingBase::DeleteFrameBufferTest(OpenGLUnsignedInt buffer) const noexcept
{
    SetGLDeleteFrameBuffers(buffer);
}

void System::OpenGLBuffersTestingBase::DeleteFrameBuffersTest(const BufferType& buffers) const noexcept
{
    SetGLDeleteFrameBuffers(bufferSize, buffers.data());
}

void System::OpenGLBuffersTestingBase::DeleteVertexArrayTest(OpenGLUnsignedInt buffer) const noexcept
{
    SetGLDeleteVertexArrays(buffer);
}

void System::OpenGLBuffersTestingBase::DeleteVertexArraysTest(const BufferType& buffers) const noexcept
{
    SetGLDeleteVertexArrays(bufferSize, buffers.data());
}

System::OpenGLBuffersTestingBase::BindBufferContainerConstIter System::OpenGLBuffersTestingBase::begin() const noexcept
{
    return bindBuffers.cbegin();
}

System::OpenGLBuffersTestingBase::BindBufferContainerConstIter System::OpenGLBuffersTestingBase::end() const noexcept
{
    return bindBuffers.cend();
}

System::BindBuffer System::OpenGLBuffersTestingBase::GetSubDataBindBuffer(int index) const
{
    const auto correctIndex = index % subDataBindBuffers.size();

    return subDataBindBuffers.at(correctIndex);
}

int System::OpenGLBuffersTestingBase::GetSubDataBindBufferSize() const
{
    return std::min(bufferSize, boost::numeric_cast<int>(subDataBindBuffers.size()));
}
