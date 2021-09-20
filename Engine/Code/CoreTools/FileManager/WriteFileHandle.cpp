//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/14 14:56)

#include "CoreTools/CoreToolsExport.h"

#include "WriteFileHandle.h"
#include "Detail/WriteFileHandleImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

CoreTools::WriteFileHandle::WriteFileHandle(const String& fileName, FileHandleCreationDisposition creation)
    : impl{  fileName, creation  }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, WriteFileHandle)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, WriteFileHandle, GetFileByteSize, int)

void CoreTools::WriteFileHandle::Write(size_t itemSize, const void* data)
{
    

    return impl->Write(itemSize, data);
}

void CoreTools::WriteFileHandle::Write(size_t itemSize, size_t itemsNumber, const void* data)
{
    

    return impl->Write(itemSize, itemsNumber, data);
}
