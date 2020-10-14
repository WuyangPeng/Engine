//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/14 14:41)

#include "CoreTools/CoreToolsExport.h"

#include "ReadFileHandle.h"
#include "Detail/ReadFileHandleImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

CoreTools::ReadFileHandle::ReadFileHandle(const String& fileName)
    : m_Impl{ make_shared<ImplType>(fileName) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, ReadFileHandle)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, ReadFileHandle, GetFileByteSize, int);

void CoreTools::ReadFileHandle::Read(size_t itemSize, void* data)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->Read(itemSize, data);
}

void CoreTools::ReadFileHandle::Read(size_t itemSize, size_t itemsNumber, void* data)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->Read(itemSize, itemsNumber, data);
}
