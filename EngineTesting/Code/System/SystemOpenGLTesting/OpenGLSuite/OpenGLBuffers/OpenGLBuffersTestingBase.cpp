///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/17 12:13)

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
                   BindBuffer::PixePackBuffer,
                   BindBuffer::ShaderStorageBuffer,
                   BindBuffer::UniformBuffer,
                   BindBuffer::CopyReadBuffer,
                   BindBuffer::CopyWriteBuffer,
                   BindBuffer::AtomicCounterBuffer,
                   BindBuffer::TransformFeedbackBuffer },
      subDataBindBuffers{ BindBuffer::ArrayBuffer,
                          BindBuffer::ElementArrayBuffer,
                          BindBuffer::PixelUnpackBuffer,
                          BindBuffer::PixePackBuffer,
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
    shuffle(subDataBindBuffers.begin(), subDataBindBuffers.end(), randomEngine);
}

void System::OpenGLBuffersTestingBase::SetBindBufferTest(BindBuffer type, OpenGLUInt buffer) noexcept
{
    SetGLBindBuffer(type, buffer);
}

void System::OpenGLBuffersTestingBase::SetGLDeleteBufferTest(OpenGLUInt buffer) noexcept
{
    SetGLDeleteBuffers(buffer);
}

void System::OpenGLBuffersTestingBase::SetGLDeleteBuffersTest(const BufferType& buffers) noexcept
{
    SetGLDeleteBuffers(bufferSize, buffers.data());
}

void System::OpenGLBuffersTestingBase::SetGLDeleteFramebufferTest(OpenGLUInt buffer) noexcept
{
    SetGLDeleteFramebuffers(buffer);
}

void System::OpenGLBuffersTestingBase::SetGLDeleteFramebuffersTest(const BufferType& buffers) noexcept
{
    SetGLDeleteFramebuffers(bufferSize, buffers.data());
}

void System::OpenGLBuffersTestingBase::SetGLDeleteVertexArrayTest(OpenGLUInt buffer) noexcept
{
    SetGLDeleteVertexArrays(buffer);
}

void System::OpenGLBuffersTestingBase::SetGLDeleteVertexArraysTest(const BufferType& buffers) noexcept
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

System::BindBuffer System::OpenGLBuffersTestingBase::GetSubDataBindBuffer(size_t index) const
{
    return subDataBindBuffers.at(index % subDataBindBuffers.size());
}

size_t System::OpenGLBuffersTestingBase::GetSubDataBindBufferSize() const
{
    return std::min(boost::numeric_cast<size_t>(bufferSize), subDataBindBuffers.size());
}
