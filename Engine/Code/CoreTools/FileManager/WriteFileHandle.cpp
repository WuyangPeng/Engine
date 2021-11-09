///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.3 (2021/09/03 15:05)

#include "CoreTools/CoreToolsExport.h"

#include "WriteFileHandle.h"
#include "Detail/WriteFileHandleImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CoreTools::WriteFileHandle::WriteFileHandle(const String& fileName, FileHandleCreationDisposition creation)
    : impl{ fileName, creation }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, WriteFileHandle)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, WriteFileHandle, GetFileByteSize, int)

void CoreTools::WriteFileHandle::Write(size_t itemSize, const void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->Write(itemSize, data);
}

void CoreTools::WriteFileHandle::Write(size_t itemSize, size_t itemsNumber, const void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->Write(itemSize, itemsNumber, data);
}
