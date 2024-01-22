/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 00:03)

#include "CoreTools/CoreToolsExport.h"

#include "FileBufferImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CoreTools::FileBufferImpl::FileBufferImpl(int count)
    : buffer(count)
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, FileBufferImpl)

const char* CoreTools::FileBufferImpl::GetBufferBegin() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return buffer.data();
}

char* CoreTools::FileBufferImpl::GetBufferBegin() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return NON_CONST_MEMBER_CALL_CONST_MEMBER(char*, GetBufferBegin);
}

int CoreTools::FileBufferImpl::GetSize() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(buffer.size());
}

CoreTools::FileBufferImpl::BufferTypeConstIter CoreTools::FileBufferImpl::begin() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return buffer.begin();
}

CoreTools::FileBufferImpl::BufferTypeIter CoreTools::FileBufferImpl::begin() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return buffer.begin();
}

CoreTools::FileBufferImpl::BufferTypeIter CoreTools::FileBufferImpl::end() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return buffer.end();
}

CoreTools::FileBufferImpl::BufferTypeConstIter CoreTools::FileBufferImpl::end() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return buffer.end();
}

const char* CoreTools::FileBufferImpl::GetBuffer(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return &buffer.at(index);
}

char* CoreTools::FileBufferImpl::GetBuffer(int index)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return NON_CONST_MEMBER_CALL_CONST_MEMBER_USE_PARAMETER(char*, GetBuffer, index);
}

void CoreTools::FileBufferImpl::CopyBuffer(const BufferTypeConstIter& begin, const BufferTypeConstIter& end)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto index = 0;
    for (auto iter = begin; iter != end; ++iter)
    {
        buffer.at(index) = *iter;
        ++index;
    }
}
