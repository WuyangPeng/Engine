/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 17:30)

#include "Network/NetworkExport.h"

#include "AceSockInternetAddress.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Network/AceWrappers/Detail/BaseMainManager/StringConversion.h"

#include <array>

#ifdef NETWORK_USE_ACE

Network::AceSockInternetAddress::AceSockInternetAddress(const std::string& hostName, int port)
    : aceInternetAddress{}
{
    if (aceInternetAddress.set(boost::numeric_cast<uint16_t>(port), hostName.c_str()) != 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("网络地址设置无效！"s))
    }

    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::AceSockInternetAddress::AceSockInternetAddress() noexcept
    : aceInternetAddress{}
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::AceSockInternetAddress::AceSockInternetAddress(int port)
    : aceInternetAddress{}
{
    if (aceInternetAddress.set(boost::numeric_cast<uint16_t>(port)) != 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("网络地址设置无效！"s))
    }

    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, AceSockInternetAddress)

const Network::ACEInternetAddressType& Network::AceSockInternetAddress::GetACEInternetAddress() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return aceInternetAddress;
}

Network::ACEInternetAddressType& Network::AceSockInternetAddress::GetACEInternetAddress()
{
    NETWORK_CLASS_IS_VALID_9;

    return ParentType::GetACEInternetAddress();
}

Network::AceSockInternetAddress::SockAddressSharedPtr Network::AceSockInternetAddress::Clone() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}

std::string Network::AceSockInternetAddress::GetAddress() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    constexpr auto bufferSize = 256;

    std::array<ACEChar, bufferSize> buffer{};

    if (aceInternetAddress.addr_to_string(buffer.data(), buffer.size()) == 0)
        return StringConversion::ACEStringConversionMultiByte(buffer.data());
    else
        return std::string{};
}

int Network::AceSockInternetAddress::GetPort() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return aceInternetAddress.get_port_number();
}

#endif  // NETWORK_USE_ACE