//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/13 10:35)

#include "CoreTools/CoreToolsExport.h"

#include "FileBufferImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CoreTools::FileBufferImpl::FileBufferImpl(size_t count)
    : m_Buffer(count)
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::FileBufferImpl::IsValid() const noexcept
{
    if (0u < m_Buffer.size())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

const char* CoreTools::FileBufferImpl::GetBufferBegin() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_Buffer.data();
}

size_t CoreTools::FileBufferImpl::GetSize() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_Buffer.size();
}

char* CoreTools::FileBufferImpl::GetBufferBegin() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return NON_CONST_MEMBER_CALL_CONST_MEMBER(char*, GetBufferBegin);
}

CoreTools::FileBufferImpl::BufferTypeConstIter CoreTools::FileBufferImpl::begin() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_Buffer.begin();
}

CoreTools::FileBufferImpl::BufferTypeIter CoreTools::FileBufferImpl::end() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return m_Buffer.begin();
}

CoreTools::FileBufferImpl::BufferTypeConstIter CoreTools::FileBufferImpl::end() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_Buffer.end();
}

CoreTools::FileBufferImpl::BufferTypeIter CoreTools::FileBufferImpl::begin() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return m_Buffer.end();
}

const char* CoreTools::FileBufferImpl::GetBuffer(int index) const  
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return &m_Buffer.at(index);
}

char* CoreTools::FileBufferImpl::GetBuffer(int index)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return NON_CONST_MEMBER_CALL_CONST_MEMBER_USE_PARAMETER(char*, GetBuffer, index);
}
