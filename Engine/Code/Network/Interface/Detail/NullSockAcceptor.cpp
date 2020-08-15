// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 11:12)

#include "Network/NetworkExport.h"

#include "NullSockAcceptor.h"
#include "System/Helper/UnusedMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;
using std::string;
using std::to_string;

#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26418)

Network::NullSockAcceptor ::NullSockAcceptor() noexcept
    : ParentType{}
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, NullSockAcceptor)

bool Network::NullSockAcceptor ::Accept(const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    SYSTEM_UNUSED_ARG(sockStream);
    SYSTEM_UNUSED_ARG(sockAddress);

    return false;
}

void Network::NullSockAcceptor ::AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    SYSTEM_UNUSED_ARG(eventInterface);
    SYSTEM_UNUSED_ARG(sockStream);
}

bool Network::NullSockAcceptor ::EnableNonBlock() noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    return false;
}

void Network::NullSockAcceptor ::AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    SYSTEM_UNUSED_ARG(eventInterface);
    SYSTEM_UNUSED_ARG(sockStream);
    SYSTEM_UNUSED_ARG(sockAddress);
}

bool Network::NullSockAcceptor ::Accept(const SockStreamSharedPtr& sockStream) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    SYSTEM_UNUSED_ARG(sockStream);

    return false;
}

const std::string Network::NullSockAcceptor ::GetAddress() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return std::string{};
}

int Network::NullSockAcceptor ::GetPort() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return 0;
}
#include STSTEM_WARNING_POP