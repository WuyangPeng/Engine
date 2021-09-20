//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/14 14:40)

#include "CoreTools/CoreToolsExport.h"

#include "ReadAndWriteFileHandle.h"
#include "Detail/ReadAndWriteFileHandleImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

CoreTools::ReadAndWriteFileHandle::ReadAndWriteFileHandle(const String& fileName)
    : impl{ fileName }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ReadAndWriteFileHandle)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, ReadAndWriteFileHandle, GetFileLength, uint64_t);

void CoreTools::ReadAndWriteFileHandle::Read(size_t itemSize, void* data)
{
    return impl->Read(itemSize, data);
}

void CoreTools::ReadAndWriteFileHandle::Read(size_t itemSize, size_t itemsNumber, void* data)
{
    return impl->Read(itemSize, itemsNumber, data);
}

void CoreTools::ReadAndWriteFileHandle::Write(size_t itemSize, const void* data)
{
    return impl->Write(itemSize, data);
}

void CoreTools::ReadAndWriteFileHandle::Write(size_t itemSize, size_t itemsNumber, const void* data)
{
    return impl->Write(itemSize, itemsNumber, data);
}
