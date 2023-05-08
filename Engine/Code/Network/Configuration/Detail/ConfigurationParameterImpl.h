///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.7 (2023/04/28 09:38)

#ifndef NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_PARAMETER_IMPL_H
#define NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_PARAMETER_IMPL_H

#include "Network/NetworkDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <map>
#include <set>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE ConfigurationParameterImpl final
    {
    public:
        using ClassType = ConfigurationParameterImpl;
        using String = System::String;
        using Parameter = std::set<String>;

    public:
        ConfigurationParameterImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        void AddParameter(const String& key, const String& parameter);
        NODISCARD bool IsParameterExist(const String& key, const String& parameter) const;
        NODISCARD Parameter GetParameter(const String& key) const;

    private:
        using Container = std::map<String, Parameter>;

    private:
        Container container;
    };
}

#endif  // NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_PARAMETER_IMPL_H
