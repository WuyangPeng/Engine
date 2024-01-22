/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 09:57)

#include "CoreTools/CoreToolsExport.h"

#include "BufferTargetImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/ObjectSystems/ObjectRegister.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

CoreTools::BufferTargetImpl::BufferTargetImpl(int bufferSize, const ConstObjectRegisterSharedPtr& objectRegister)
    : target{ bufferSize }, objectRegister{ objectRegister }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, BufferTargetImpl)

void CoreTools::BufferTargetImpl::Write(size_t itemSize, const void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    target.Write(itemSize, data);
}

void CoreTools::BufferTargetImpl::Write(size_t itemSize, size_t itemsNumber, const void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    target.Write(itemSize, itemsNumber, data);
}

int CoreTools::BufferTargetImpl::GetBytesWritten() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return target.GetBytesProcessed();
}

void CoreTools::BufferTargetImpl::WriteUniqueId(const ConstObjectInterfaceSharedPtr& object)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const auto uniqueId = objectRegister->GetUniqueId(object);

    Write(GetStreamSize(uniqueId), &uniqueId);
}

CoreTools::ConstFileBufferSharedPtr CoreTools::BufferTargetImpl::GetFileBuffer() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return target.GetFileBuffer();
}
