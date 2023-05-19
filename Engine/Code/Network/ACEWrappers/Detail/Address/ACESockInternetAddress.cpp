///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 14:00)

#include "Network/NetworkExport.h"

#include "ACESockInternetAddress.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Network/ACEWrappers/Detail/BaseMainManager/StringConversion.h"

#include <array>

#ifdef NETWORK_USE_ACE

Network::ACESockInternetAddress::ACESockInternetAddress(const std::string& hostName, int port)
    : aceInternetAddress{}
{
    if (aceInternetAddress.set(boost::numeric_cast<uint16_t>(port), hostName.c_str()) != 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("网络地址设置无效！"s))
    }

    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::ACESockInternetAddress::ACESockInternetAddress() noexcept
    : aceInternetAddress{}
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::ACESockInternetAddress::ACESockInternetAddress(int port)
    : aceInternetAddress{}
{
    if (aceInternetAddress.set(boost::numeric_cast<uint16_t>(port)) != 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("网络地址设置无效！"s))
    }

    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, ACESockInternetAddress)

const Network::ACEInternetAddressType& Network::ACESockInternetAddress::GetACEInternetAddress() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return aceInternetAddress;
}

Network::ACEInternetAddressType& Network::ACESockInternetAddress::GetACEInternetAddress()
{
    NETWORK_CLASS_IS_VALID_9;

    return ParentType::GetACEInternetAddress();
}

Network::ACESockInternetAddress::SockAddressSharedPtr Network::ACESockInternetAddress::Clone() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}

std::string Network::ACESockInternetAddress::GetAddress() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    constexpr auto bufferSize = 256;

    std::array<ACEChar, bufferSize> buffer{};

    if (aceInternetAddress.addr_to_string(buffer.data(), buffer.size()) == 0)
        return StringConversion::ACEStringConversionMultiByte(buffer.data());
    else
        return std::string{};
}

int Network::ACESockInternetAddress::GetPort() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return aceInternetAddress.get_port_number();
}

#endif  // NETWORK_USE_ACE