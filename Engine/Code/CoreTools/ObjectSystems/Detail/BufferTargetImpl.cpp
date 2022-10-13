///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/24 22:59)

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

void CoreTools::BufferTargetImpl::WriteUniqueID(const ConstObjectInterfaceSharedPtr& object)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const auto uniqueID = objectRegister->GetUniqueID(object);

    Write(CORE_TOOLS_STREAM_SIZE(uniqueID), &uniqueID);
}

CoreTools::ConstFileBufferSharedPtr CoreTools::BufferTargetImpl::GetFileBuffer() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return target.GetFileBuffer();
}
