/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 17:21)

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
        NODISCARD String GetFirstParameter(const String& key) const;

    private:
        using Container = std::map<String, Parameter>;

    private:
        Container container;
    };
}

#endif  // NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_PARAMETER_IMPL_H
