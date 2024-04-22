/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/14 21:07)

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
    CORE_TOOLS_CLASS_IS_VALID_1;

    System::UnusedFunction(source);
}

void CoreTools::TestingNoObjectPtrImpl::Register(ObjectRegister& target) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    System::UnusedFunction(target);
}

void CoreTools::TestingNoObjectPtrImpl::Save(BufferTarget& target) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    System::UnusedFunction(target);
}

int CoreTools::TestingNoObjectPtrImpl::GetStreamingSize() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return 0;
}

void CoreTools::TestingNoObjectPtrImpl::Link(ObjectLink& source) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    System::UnusedFunction(source);
}
