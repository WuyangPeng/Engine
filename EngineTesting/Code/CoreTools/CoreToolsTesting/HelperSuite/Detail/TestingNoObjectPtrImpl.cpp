///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.1 (2021/08/19 15:10)

#include "TestingNoObjectPtrImpl.h"
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

void CoreTools::TestingNoObjectPtrImpl::Load(MAYBE_UNUSED const BufferSourceSharedPtr& source) noexcept
{
}

void CoreTools::TestingNoObjectPtrImpl::Register(MAYBE_UNUSED const CoreTools::ObjectRegisterSharedPtr& target) const noexcept
{
}

void CoreTools::TestingNoObjectPtrImpl::Save(MAYBE_UNUSED const CoreTools::BufferTargetSharedPtr& target) const noexcept
{
}

int CoreTools::TestingNoObjectPtrImpl::GetStreamingSize() const noexcept
{
    return 0;
}

void CoreTools::TestingNoObjectPtrImpl::Link(MAYBE_UNUSED const CoreTools::ObjectLinkSharedPtr source) noexcept
{
}
