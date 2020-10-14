//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/14 14:55)

#include "CoreTools/CoreToolsExport.h"

#include "WriteBufferIO.h"
#include "Detail/WriteBufferIOImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

CoreTools::WriteBufferIO::WriteBufferIO(int bufferSize)
    : m_Impl{ make_shared<ImplType>(bufferSize) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, WriteBufferIO)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, WriteBufferIO, GetBytesTotal, int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, WriteBufferIO, GetBytesProcessed, int);

void CoreTools::WriteBufferIO::IncrementBytesProcessed(int bytesNumber) noexcept(g_Assert < 2 || g_CoreToolsAssert < 2)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->IncrementBytesProcessed(bytesNumber);
}

void CoreTools::WriteBufferIO::Write(size_t itemSize, const void* data)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->Write(itemSize, data);
}

void CoreTools::WriteBufferIO::Write(size_t itemSize, size_t itemsNumber, const void* data)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->Write(itemSize, itemsNumber, data);
}
