/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:02)

#include "Framework/FrameworkExport.h"

#include "NetworkManagerImpl.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Framework::NetworkManagerImpl::NetworkManagerImpl() noexcept
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::NetworkManagerImpl::NetworkManagerImpl(NetworkManagerImpl&& rhs) noexcept
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;

    System::UnusedFunction(rhs);
}

Framework::NetworkManagerImpl& Framework::NetworkManagerImpl::operator=(NetworkManagerImpl&& rhs) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(rhs);

    return *this;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, NetworkManagerImpl)

void Framework::NetworkManagerImpl::ResetSendSocketManager(const std::string& fileName) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(fileName);
}
