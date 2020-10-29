//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 20:25)

#ifndef DATABASE_CONFIGURATION_CONFIGURATION_STRATEGY_IMPL_H
#define DATABASE_CONFIGURATION_CONFIGURATION_STRATEGY_IMPL_H

#include "Database/DatabaseDll.h"

#include "Database/Configuration/Flags/ConfigurationStrategyFlags.h"

#include <map>
#include <string>
#include <vector>

namespace Database
{
    class DATABASE_HIDDEN_DECLARE ConfigurationStrategyImpl final
    {
    public:
        using ClassType = ConfigurationStrategyImpl;
        using FlagsOption = std::vector<std::string>;
        using StringOption = std::map<std::string, std::string>;
        using BooleanOption = std::map<std::string, bool>;
        using IntOption = std::map<std::string, int>;
        using SSLOption = std::map<std::string, std::string>;
        using DBMapping = std::map<int, std::string>;

    public:
        ConfigurationStrategyImpl(WrappersStrategy wrappersStrategy, const std::string& ip, int port,
                                  const std::string& hostName, const std::string& userName, const std::string& password);
        ConfigurationStrategyImpl(WrappersStrategy wrappersStrategy, const std::string& ip, int port,
                                  const std::string& hostName, const std::string& userName, const std::string& password,
                                  bool pooling, int poolMaxSize, int poolQueueTimeout, int poolMaxIdleTime,
                                  const FlagsOption& flagsOption, const StringOption& stringOption, const BooleanOption& booleanOption,
                                  const IntOption& intOption, const SSLOption& sslOption, const DBMapping& dbMapping);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] WrappersStrategy GetWrappersStrategy() const noexcept;

        [[nodiscard]] std::string GetIP() const;
        [[nodiscard]] int GetPort() const noexcept;
        [[nodiscard]] std::string GetDBHostName() const;
        [[nodiscard]] std::string GetDBUserName() const;
        [[nodiscard]] std::string GetDBPassword() const;

        [[nodiscard]] FlagsOption GetFlagsOption() const;
        [[nodiscard]] StringOption GetStringOptions() const;
        [[nodiscard]] BooleanOption GetBooleanOptions() const;
        [[nodiscard]] IntOption GetIntOptions() const;
        [[nodiscard]] SSLOption GetSSLOptions() const;
        [[nodiscard]] DBMapping GetDBMapping() const;
        [[nodiscard]] bool IsUseSSL() const noexcept;
        [[nodiscard]] std::string GetDBName(int dbIndex) const;

        [[nodiscard]] bool GetPooling() const noexcept;
        [[nodiscard]] int GetPoolMaxSize() const noexcept;
        [[nodiscard]] int GetPoolQueueTimeout() const noexcept;
        [[nodiscard]] int GetPoolMaxIdleTime() const noexcept;

    private:
        WrappersStrategy m_WrappersStrategyFlag;
        std::string m_IP;
        int m_Port;
        std::string m_HostName;
        std::string m_UserName;
        std::string m_Password;
        bool m_Pooling;
        int m_PoolMaxSize;
        int m_PoolQueueTimeout;
        int m_PoolMaxIdleTime;

        FlagsOption m_FlagsOptions;
        StringOption m_StringOptions;
        BooleanOption m_BooleanOptions;
        IntOption m_IntOptions;
        SSLOption m_SSLOptions;
        DBMapping m_DBMapping;
    };
}

#endif  // DATABASE_CONFIGURATION_CONFIGURATION_STRATEGY_IMPL_H
