///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/09 1:47)

#include "CoreTools/CoreToolsExport.h"

#include "FileBuffer.h"
#include "Detail/FileBufferImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CoreTools::FileBuffer::FileBuffer(size_t count)
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
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, FileBuffer, GetSize, size_t)

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
