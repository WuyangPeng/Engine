///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/23 15:40)

#include "CoreTools/CoreToolsExport.h"

#include "FileBuffer.h"
#include "Detail/FileBufferImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CoreTools::FileBuffer::FileBuffer(int count)
    : impl{ count }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, FileBuffer)

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools, FileBuffer)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, FileBuffer, GetBuffer, int, const char*)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, FileBuffer, GetBuffer, int, char*)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, FileBuffer, GetBufferBegin, char*)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, FileBuffer, GetBufferBegin, const char*)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, FileBuffer, GetSize, int)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, FileBuffer, begin, CoreTools::FileBuffer::BufferTypeIter)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, FileBuffer, begin, CoreTools::FileBuffer::BufferTypeConstIter)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, FileBuffer, end, CoreTools::FileBuffer::BufferTypeIter)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, FileBuffer, end, CoreTools::FileBuffer::BufferTypeConstIter)

const char* CoreTools::FileBuffer::GetConstBuffer(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return GetBuffer(index);
}

const char* CoreTools::FileBuffer::GetConstBufferBegin() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return GetBufferBegin();
}

void CoreTools::FileBuffer::CopyBuffer(BufferTypeConstIter begin, BufferTypeConstIter end)
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    impl->CopyBuffer(begin, end);
}
