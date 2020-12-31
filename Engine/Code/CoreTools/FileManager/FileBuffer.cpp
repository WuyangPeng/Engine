//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/14 14:25)

#include "CoreTools/CoreToolsExport.h"

#include "FileBuffer.h"
#include "Detail/FileBufferImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

COPY_CONSTRUCTION_DEFINE(CoreTools, FileBuffer);

CoreTools::FileBuffer::FileBuffer(size_t count)
    : m_Impl{ make_shared<ImplType>(count) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, FileBuffer)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, FileBuffer, GetBuffer, int, const char*)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, FileBuffer, GetBuffer, int, char*)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, FileBuffer, GetBufferBegin, char*)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, FileBuffer, GetBufferBegin, const char*)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, FileBuffer, GetSize, size_t)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, FileBuffer, begin, CoreTools::FileBuffer::BufferTypeIter)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, FileBuffer, begin, CoreTools::FileBuffer::BufferTypeConstIter)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, FileBuffer, end, CoreTools::FileBuffer::BufferTypeIter)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, FileBuffer, end, CoreTools::FileBuffer::BufferTypeConstIter)