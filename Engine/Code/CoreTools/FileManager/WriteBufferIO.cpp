///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/09 1:49)

#include "CoreTools/CoreToolsExport.h"

#include "WriteBufferIO.h"
#include "Detail/WriteBufferIOImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CoreTools::WriteBufferIO::WriteBufferIO(int bufferSize)
    : impl{ bufferSize }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, WriteBufferIO)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, WriteBufferIO, GetBytesTotal, int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, WriteBufferIO, GetBytesProcessed, int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, WriteBufferIO, GetFileBuffer, CoreTools::ConstFileBufferSharedPtr);

void CoreTools::WriteBufferIO::IncrementBytesProcessed(int bytesNumber)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->IncrementBytesProcessed(bytesNumber);
}

void CoreTools::WriteBufferIO::Write(size_t itemSize, const void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->Write(itemSize, data);
}

void CoreTools::WriteBufferIO::Write(size_t itemSize, size_t itemsNumber, const void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->Write(itemSize, itemsNumber, data);
}
