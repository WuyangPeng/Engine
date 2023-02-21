///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.2 (2023/02/16 20:57)

#include "TestingNoObjectPtrImpl.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"

CoreTools::TestingNoObjectPtrImpl::TestingNoObjectPtrImpl() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, TestingNoObjectPtrImpl);

void CoreTools::TestingNoObjectPtrImpl::Load(BufferSource& source) noexcept
{
    System::UnusedFunction(source);
}

void CoreTools::TestingNoObjectPtrImpl::Register(ObjectRegister& target) const noexcept
{
    System::UnusedFunction(target);
}

void CoreTools::TestingNoObjectPtrImpl::Save(BufferTarget& target) const noexcept
{
    System::UnusedFunction(target);
}

int CoreTools::TestingNoObjectPtrImpl::GetStreamingSize() const noexcept
{
    return 0;
}

void CoreTools::TestingNoObjectPtrImpl::Link(ObjectLink& source) noexcept
{
    System::UnusedFunction(source);
}
