//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/26 19:03)

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
        [[nodiscard]] bool IsParameterExist(const String& key, const String& parameter) const;
        [[nodiscard]] const Parameter GetParameter(const String& key) const;

    private:
        using Container = std::map<String, Parameter>;

    private:
        Container m_Container;
    };
}

#endif  // NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_PARAMETER_IMPL_H
