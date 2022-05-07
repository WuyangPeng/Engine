///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/07 11:17)

#include "Framework/FrameworkExport.h"

#include "NetworkManagerImpl.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Network/Interface/SendSocketManager.h"

using std::const_pointer_cast;
using std::make_shared;
using std::move;
using std::string;

Framework::NetworkManagerImpl::NetworkManagerImpl() noexcept
    : sendSocketManager{}
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::NetworkManagerImpl::NetworkManagerImpl(NetworkManagerImpl&& rhs) noexcept
    : sendSocketManager{ move(rhs.sendSocketManager) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::NetworkManagerImpl& Framework::NetworkManagerImpl::operator=(NetworkManagerImpl&& rhs) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    sendSocketManager = move(rhs.sendSocketManager);

    return *this;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, NetworkManagerImpl)

void Framework::NetworkManagerImpl::ResetSendSocketManager(const string& fileName)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    sendSocketManager = make_shared<SendSocketManager>(fileName);
}

Framework::NetworkManagerImpl::SendSocketManagerSharedPtr Framework::NetworkManagerImpl::GetSendSocketManager() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26473)

    return const_pointer_cast<SendSocketManager>(static_cast<const ClassType*>(this)->GetSendSocketManager());

#include STSTEM_WARNING_POP
}

Framework::NetworkManagerImpl::ConstSendSocketManagerSharedPtr Framework::NetworkManagerImpl::GetSendSocketManager() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return sendSocketManager;
}

void Framework::NetworkManagerImpl::Send(const Network::SocketData& socketData, uint64_t socketID, const MessageInterfaceSharedPtr& message)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (sendSocketManager != nullptr)
    {
        sendSocketManager->Send(socketData, socketID, message);
    }
}
