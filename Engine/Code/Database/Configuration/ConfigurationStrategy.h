///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/14 15:55)

#ifndef DATABASE_CONFIGURATION_CONFIGURATION_STRATEGY_H
#define DATABASE_CONFIGURATION_CONFIGURATION_STRATEGY_H

#include "Database/DatabaseDll.h"

#include "Flags/ConfigurationStrategyFlags.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <map>
#include <string>
#include <vector>

DATABASE_PERFORMANCE_UNSHARED_EXPORT_IMPL(ConfigurationStrategyImpl);

namespace Database
{
    class DATABASE_DEFAULT_DECLARE ConfigurationStrategy final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(ConfigurationStrategy);

        using FlagsOption = std::vector<std::string>;
        using StringOption = std::map<std::string, std::string>;
        using BooleanOption = std::map<std::string, bool>;
        using IntOption = std::map<std::string, int>;
        using SSLOption = std::map<std::string, std::string>;
        using DBMapping = std::map<int, std::string>;

    public:
        ConfigurationStrategy(WrappersStrategy wrappersStrategy,
                              const std::string& ip,
                              int port,
                              const std::string& hostName,
                              const std::string& userName,
                              const std::string& password);
        ConfigurationStrategy(WrappersStrategy wrappersStrategy,
                              const std::string& ip,
                              int port,
                              const std::string& hostName,
                              const std::string& userName,
                              const std::string& password,
                              bool pooling,
                              int poolMaxSize,
                              int poolQueueTimeout,
                              int poolMaxIdleTime,
                              int threadCount,
                              const FlagsOption& flagsOption,
                              const StringOption& stringOption,
                              const BooleanOption& booleanOption,
                              const IntOption& intOption,
                              const SSLOption& sslOption,
                              const DBMapping& dbMapping);

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
        PackageType impl;
    };
}

#endif  // DATABASE_CONFIGURATION_CONFIGURATION_STRATEGY_H
