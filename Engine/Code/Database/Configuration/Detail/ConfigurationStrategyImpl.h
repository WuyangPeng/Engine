/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 13:56)

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
                                  std::string ip,
                                  int port,
                                  std::string hostName,
                                  std::string userName,
                                  std::string password);
        ConfigurationStrategyImpl(WrappersStrategy wrappersStrategy,
                                  std::string ip,
                                  int port,
                                  std::string hostName,
                                  std::string userName,
                                  std::string password,
                                  bool pooling,
                                  int poolMaxSize,
                                  int poolQueueTimeout,
                                  int poolMaxIdleTime,
                                  int threadCount,
                                  FlagsOption flagsOption,
                                  StringOption stringOption,
                                  BooleanOption booleanOption,
                                  IntOption intOption,
                                  SSLOption sslOption,
                                  DBMapping dbMapping);

        CLASS_INVARIANT_DECLARE;

        NODISCARD WrappersStrategy GetWrappersStrategy() const noexcept;

        NODISCARD std::string GetIp() const;
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

        NODISCARD int GetThreadCount() const noexcept;

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
        int threadCount;

        FlagsOption flagsOptions;
        StringOption stringOptions;
        BooleanOption booleanOptions;
        IntOption intOptions;
        SSLOption sslOptions;
        DBMapping dbMapping;
    };
}

#endif  // DATABASE_CONFIGURATION_CONFIGURATION_STRATEGY_IMPL_H
