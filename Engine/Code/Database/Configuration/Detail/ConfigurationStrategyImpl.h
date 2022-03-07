///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/25 11:02)

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
        ConfigurationStrategyImpl(WrappersStrategy wrappersStrategy,
                                  const std::string& ip,
                                  int port,
                                  const std::string& hostName,
                                  const std::string& userName,
                                  const std::string& password);
        ConfigurationStrategyImpl(WrappersStrategy wrappersStrategy,
                                  const std::string& ip,
                                  int port,
                                  const std::string& hostName,
                                  const std::string& userName,
                                  const std::string& password,
                                  bool pooling,
                                  int poolMaxSize,
                                  int poolQueueTimeout,
                                  int poolMaxIdleTime,
                                  const FlagsOption& flagsOption,
                                  const StringOption& stringOption,
                                  const BooleanOption& booleanOption,
                                  const IntOption& intOption,
                                  const SSLOption& sslOption,
                                  const DBMapping& dbMapping);

        CLASS_INVARIANT_DECLARE;

        NODISCARD WrappersStrategy GetWrappersStrategy() const noexcept;

        NODISCARD std::string GetIP() const;
        NODISCARD int GetPort() const noexcept;
        NODISCARD std::string GetDBHostName() const;
        NODISCARD std::string GetDBUserName() const;
        NODISCARD std::string GetDBPassword() const;

        NODISCARD FlagsOption GetFlagsOption() const;
        NODISCARD StringOption GetStringOptions() const;
        NODISCARD BooleanOption GetBooleanOptions() const;
        NODISCARD IntOption GetIntOptions() const;
        NODISCARD SSLOption GetSSLOptions() const;
        NODISCARD DBMapping GetDBMapping() const;
        NODISCARD bool IsUseSSL() const noexcept;
        NODISCARD std::string GetDBName(int dbIndex) const;

        NODISCARD bool GetPooling() const noexcept;
        NODISCARD int GetPoolMaxSize() const noexcept;
        NODISCARD int GetPoolQueueTimeout() const noexcept;
        NODISCARD int GetPoolMaxIdleTime() const noexcept;

    private:
        WrappersStrategy wrappersStrategyFlag;
        std::string ip;
        int port;
        std::string hostName;
        std::string userName;
        std::string password;
        bool pooling;
        int poolMaxSize;
        int poolQueueTimeout;
        int poolMaxIdleTime;

        FlagsOption flagsOptions;
        StringOption stringOptions;
        BooleanOption booleanOptions;
        IntOption intOptions;
        SSLOption sslOptions;
        DBMapping dbMapping;
    };
}

#endif  // DATABASE_CONFIGURATION_CONFIGURATION_STRATEGY_IMPL_H
