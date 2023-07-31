///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 10:20)

#include "Toolset/System/SystemToolset/SystemToolsetExport.h"

#include "ConnectParameter.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "System/Network/Flags/SocketPrototypesFlags.h"
#include "System/Network/SocketPrototypes.h"
#include "System/Windows/Engineering.h"
#include "Toolset/System/SystemToolset/Helper/SystemToolsetClassInvariantMacro.h"

SystemToolset::ConnectParameter::ConnectParameter(const std::string& jsonRoute, const std::string& portName)
    : port{ 30000 }, address{}, connectTime{ 20 }
{
    Init(jsonRoute, portName);

    SYSTEM_TOOLSET_SELF_CLASS_IS_VALID_9;
}

void SystemToolset::ConnectParameter::Init(const std::string& jsonRoute, const std::string& portName)
{
    using TreeType = boost::property_tree::basic_ptree<std::string, std::string>;

    TreeType mainTree{};
    read_json(jsonRoute, mainTree);

    port = mainTree.get<int>(portName, port) + System::GetEngineeringOffsetValue();
    address = mainTree.get<std::string>("Address", System::defaultRouteAddress);
    connectTime = mainTree.get<int>("ConnectTime", connectTime);
}

CLASS_INVARIANT_STUB_DEFINE(SystemToolset, ConnectParameter)

System::WinSockInternetAddress SystemToolset::ConnectParameter::GetWinSockInternetAddress() const
{
    SYSTEM_TOOLSET_CLASS_IS_VALID_CONST_9;

    WinSockInternetAddress internetAddress{};

    internetAddress.sin_family = EnumCastUnderlying<uint16_t>(System::AddressFamilies::Internet);
    internetAddress.sin_port = System::GetHostToNetShort(boost::numeric_cast<uint16_t>(port));
    internetAddress.sin_addr.s_addr = System::GetInternetAddress(address.c_str());

    return internetAddress;
}

int SystemToolset::ConnectParameter::GetConnectTime() const noexcept
{
    SYSTEM_TOOLSET_CLASS_IS_VALID_CONST_9;

    return connectTime;
}
