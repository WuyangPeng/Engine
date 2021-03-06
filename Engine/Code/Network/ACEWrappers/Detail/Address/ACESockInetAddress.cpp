//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 15:05)

#include "Network/NetworkExport.h"

#ifdef NETWORK_USE_ACE

    #include "ACESockInetAddress.h"
    #include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
    #include "CoreTools/Helper/ExceptionMacro.h"
    #include "Network/ACEWrappers/Detail/BaseMainManager/StringConversion.h"
    #include "System/Helper/PragmaWarning/NumericCast.h"

    #include <array>

using std::array;
using std::make_shared;
using std::string;
 
Network::ACESockInetAddress::ACESockInetAddress(const string& hostName, int port)
    : m_ACEInetAddress{}
{
    if (m_ACEInetAddress.set(boost::numeric_cast<uint16_t>(port), hostName.c_str()) != 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("网络地址设置无效！"s));
    }

    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::ACESockInetAddress::ACESockInetAddress() noexcept
    : m_ACEInetAddress{}
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::ACESockInetAddress::ACESockInetAddress(int port)
    : m_ACEInetAddress{}
{
    if (m_ACEInetAddress.set(boost::numeric_cast<uint16_t>(port)) != 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("网络地址设置无效！"s));
    }

    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, ACESockInetAddress)

const Network::ACEInetAddressType& Network::ACESockInetAddress::GetACEInetAddress() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return m_ACEInetAddress;
}

Network::ACEInetAddressType& Network::ACESockInetAddress::GetACEInetAddress()
{
    NETWORK_CLASS_IS_VALID_9;

    return ParentType::GetACEInetAddress();
}

const Network::ACESockInetAddress::SockAddressPtr Network::ACESockInetAddress::Clone() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return make_shared<ClassType>(*this);
}

const string Network::ACESockInetAddress::GetAddress() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    constexpr auto bufferSize = 256;

    array<ACEChar, bufferSize> buffer{};

    if (0 == m_ACEInetAddress.addr_to_string(buffer.data(), buffer.size()))
        return StringConversion::ACEStringConversionMultiByte(buffer.data());
    else
        return string{};
}

int Network::ACESockInetAddress::GetPort() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return m_ACEInetAddress.get_port_number();
}
    
#endif  // NETWORK_USE_ACE