/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/01 10:50)

#include "CoreTools/CoreToolsExport.h"

#include "FileBuffer.h"
#include "Detail/FileBufferImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools, FileBuffer)

CoreTools::FileBuffer::FileBuffer(int count)
    : impl{ count }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, FileBuffer)

const char* CoreTools::FileBuffer::GetConstBuffer(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return GetBuffer(index);
}

const char* CoreTools::FileBuffer::GetBuffer(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetBuffer(index);
}

char* CoreTools::FileBuffer::GetBuffer(int index)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->GetBuffer(index);
}

const char* CoreTools::FileBuffer::GetBufferBegin() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetBufferBegin();
}

char* CoreTools::FileBuffer::GetBufferBegin()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->GetBufferBegin();
}

int CoreTools::FileBuffer::GetSize() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetSize();
}

CoreTools::FileBuffer::BufferTypeConstIter CoreTools::FileBuffer::begin() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->begin();
}

CoreTools::FileBuffer::BufferTypeConstIter CoreTools::FileBuffer::end() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->end();
}

CoreTools::FileBuffer::BufferTypeIter CoreTools::FileBuffer::begin()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->begin();
}

CoreTools::FileBuffer::BufferTypeIter CoreTools::FileBuffer::end()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->end();
}

const char* CoreTools::FileBuffer::GetConstBufferBegin() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return GetBufferBegin();
}

void CoreTools::FileBuffer::CopyBuffer(const BufferTypeConstIter& begin, const BufferTypeConstIter& end)
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    impl->CopyBuffer(begin, end);
}
