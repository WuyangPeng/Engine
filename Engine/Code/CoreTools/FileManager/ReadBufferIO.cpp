//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/14 14:40)

#include "CoreTools/CoreToolsExport.h"

#include "ReadBufferIO.h"
#include "Detail/ReadBufferIOImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

CoreTools::ReadBufferIO::ReadBufferIO(const ConstFileBufferSharedPtr& fileBuffer)
    : impl{ fileBuffer }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ReadBufferIO)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, ReadBufferIO, GetText, int, std::string);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, ReadBufferIO, GetBytesTotal, int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, ReadBufferIO, GetBytesProcessed, int);

void CoreTools::ReadBufferIO::IncrementBytesProcessed(int bytesNumber) noexcept(g_Assert < 2 || g_CoreToolsAssert < 2)
{
    return impl->IncrementBytesProcessed(bytesNumber);
}

void CoreTools::ReadBufferIO::Read(size_t itemSize, void* data)
{
    return impl->Read(itemSize, data);
}

void CoreTools::ReadBufferIO::Read(size_t itemSize, size_t itemsNumber, void* data)
{
    return impl->Read(itemSize, itemsNumber, data);
}
