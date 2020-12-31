//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/22 14:52)

#include "CoreTools/CoreToolsExport.h"

#include "BufferTargetImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/ObjectSystems/ObjectRegister.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

CoreTools::BufferTargetImpl::BufferTargetImpl(int bufferSize, const ConstObjectRegisterSharedPtr& objectRegister)
    : m_Target{ bufferSize }, m_ObjectRegister{ objectRegister }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, BufferTargetImpl)

void CoreTools::BufferTargetImpl::Write(size_t itemSize, const void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    m_Target.Write(itemSize, data);
}

void CoreTools::BufferTargetImpl::Write(size_t itemSize, size_t itemsNumber, const void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    m_Target.Write(itemSize, itemsNumber, data);
}

int CoreTools::BufferTargetImpl::GetBytesWritten() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_Target.GetBytesProcessed();
}

void CoreTools::BufferTargetImpl::WriteUniqueID(const ConstObjectInterfaceSharedPtr& object)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const auto uniqueID = m_ObjectRegister->GetUniqueID(object);

    Write(CORE_TOOLS_STREAM_SIZE(uniqueID), &uniqueID);
}
