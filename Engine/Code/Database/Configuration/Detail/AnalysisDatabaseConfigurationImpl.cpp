///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/25 11:16)

#include "Database/DatabaseExport.h"

#include "AnalysisDatabaseConfigurationImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "CoreTools/CharacterString/CaseInsensitiveStringDetail.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using std::map;
using std::string;
using std::vector;
using namespace std::literals;

Database::AnalysisDatabaseConfigurationImpl::AnalysisDatabaseConfigurationImpl(const string& fileName)
    : container{}, fileName{ fileName }, mainTree{}
{
    Analysis();

    DATABASE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Database, AnalysisDatabaseConfigurationImpl)

// private
void Database::AnalysisDatabaseConfigurationImpl::Analysis()
{
    AnalysisJson();
    AnalysisMain();
}

// private
void Database::AnalysisDatabaseConfigurationImpl::AnalysisJson()
{
    read_json(fileName, mainTree);
}

// private
void Database::AnalysisDatabaseConfigurationImpl::AnalysisMain()
{
    for (const auto& ptree : mainTree)
    {
        try
        {
            InsertStrategy(ptree.first, ptree.second);
        }
        catch (const CoreTools::Error& error)
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, Database)
                << SYSTEM_TEXT("数据库策略")
                << ptree.first
                << SYSTEM_TEXT("配置值错误：")
                << error
                << LOG_SINGLETON_TRIGGER_ASSERT;
        }
    }
}

// private
void Database::AnalysisDatabaseConfigurationImpl::InsertStrategy(const String& name, const BasicTree& basicTree)
{
    const auto wrappers = basicTree.get(SYSTEM_TEXT("Wrappers"s), SYSTEM_TEXT(""s));

    const auto wrappersStrategy = GetWrappersStrategy(wrappers);

    const auto ip = CoreTools::StringConversion::StandardConversionMultiByte(basicTree.get(SYSTEM_TEXT("IP"s), SYSTEM_TEXT(""s)));
    const auto port = basicTree.get(SYSTEM_TEXT("Port"s), 0);
    const auto hostName = CoreTools::StringConversion::StandardConversionMultiByte(basicTree.get(SYSTEM_TEXT("HostName"s), SYSTEM_TEXT(""s)));
    const auto userName = CoreTools::StringConversion::StandardConversionMultiByte(basicTree.get(SYSTEM_TEXT("UserName"s), SYSTEM_TEXT(""s)));
    const auto password = CoreTools::StringConversion::StandardConversionMultiByte(basicTree.get(SYSTEM_TEXT("Password"s), SYSTEM_TEXT(""s)));

    const auto pooling = basicTree.get(SYSTEM_TEXT("Pooling"s), false);
    const auto poolMaxSize = basicTree.get(SYSTEM_TEXT("PoolMaxSize"s), 0);
    const auto poolQueueTimeout = basicTree.get(SYSTEM_TEXT("PoolQueueTimeout"s), 0);
    const auto poolMaxIdleTime = basicTree.get(SYSTEM_TEXT("PoolMaxIdleTime"s), 0);

    const auto useFlagsOption = (0 < basicTree.get(SYSTEM_TEXT("UseFlagsOption"s), 0u));
    const auto useStringOptions = (0 < basicTree.get(SYSTEM_TEXT("UseStringOption"s), 0u));
    const auto useBooleanOptions = (0 < basicTree.get(SYSTEM_TEXT("UseBooleanOption"s), 0u));
    const auto useIntOptions = (0 < basicTree.get(SYSTEM_TEXT("UseIntOption"s), 0u));
    const auto useSSLOptions = (0 < basicTree.get(SYSTEM_TEXT("UseSSLOption"s), 0u));
    const auto useDBMapping = (0 < basicTree.get(SYSTEM_TEXT("UseDBMapping"s), 0u));

    const auto flagsOption = GetFlagsOption(basicTree, useFlagsOption);
    const auto stringOptions = GetStringOptions(basicTree, useStringOptions);
    const auto booleanOptions = GetBooleanOptions(basicTree, useBooleanOptions);
    const auto intOptions = GetIntOptions(basicTree, useIntOptions);
    const auto sslOptions = GetSSLOptions(basicTree, useSSLOptions);
    auto dbMapping = GetDBMapping(basicTree, useDBMapping);

    dbMapping.insert({ 0, hostName });

    ConfigurationStrategy configurationStrategy{ wrappersStrategy,
                                                 ip,
                                                 port,
                                                 hostName,
                                                 userName,
                                                 password,
                                                 pooling,
                                                 poolMaxSize,
                                                 poolQueueTimeout,
                                                 poolMaxIdleTime,
                                                 flagsOption,
                                                 stringOptions,
                                                 booleanOptions,
                                                 intOptions,
                                                 sslOptions,
                                                 dbMapping };

    container.insert({ name, configurationStrategy });
}

// private
Database::ConfigurationStrategy::FlagsOption Database::AnalysisDatabaseConfigurationImpl::GetFlagsOption(const BasicTree& basicTree, bool useFlagsOption)
{
    ConfigurationStrategy::FlagsOption result{};

    if (useFlagsOption)
    {
        auto flagsOption = basicTree.get_child(SYSTEM_TEXT("FlagsOption"s));

        for (const auto& flags : flagsOption)
        {
            if (0 < flags.second.get_value<int>())
            {
                result.emplace_back(CoreTools::StringConversion::StandardConversionMultiByte(flags.first));
            }
        }
    }

    return result;
}

Database::ConfigurationStrategy Database::AnalysisDatabaseConfigurationImpl::GetConfigurationStrategy(const String& name) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    const auto iter = container.find(name);

    if (iter != container.cend())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("找不到指定名字的配置。"s));
    }
}

Database::WrappersStrategy Database::AnalysisDatabaseConfigurationImpl::GetWrappersStrategy(const String& wrappers)
{
    CoreTools::CaseInsensitiveTString caseInsensitiveTString{ wrappers.c_str() };

    if (caseInsensitiveTString == SYSTEM_TEXT("Mysql"))
    {
        return WrappersStrategy::Mysql;
    }
    else if (caseInsensitiveTString == SYSTEM_TEXT("MysqlConnector"))
    {
        return WrappersStrategy::MysqlConnector;
    }
    else if (caseInsensitiveTString == SYSTEM_TEXT("SQLite"))
    {
        return WrappersStrategy::SQLite;
    }
    else if (caseInsensitiveTString == SYSTEM_TEXT("SqlServer"))
    {
        return WrappersStrategy::SqlServer;
    }
    else if (caseInsensitiveTString == SYSTEM_TEXT("PostgreSQL"))
    {
        return WrappersStrategy::PostgreSQL;
    }
    else if (caseInsensitiveTString == SYSTEM_TEXT("Oracle"))
    {
        return WrappersStrategy::Oracle;
    }
    else if (caseInsensitiveTString == SYSTEM_TEXT("FlatFile"))
    {
        return WrappersStrategy::FlatFile;
    }
    else if (caseInsensitiveTString == SYSTEM_TEXT("MariaDB"))
    {
        return WrappersStrategy::MariaDB;
    }
    else if (caseInsensitiveTString == SYSTEM_TEXT("Mongo"))
    {
        return WrappersStrategy::Mongo;
    }
    else if (caseInsensitiveTString == SYSTEM_TEXT("Redis"))
    {
        return WrappersStrategy::Redis;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("数据库包装器类型不存在。"s));
}

Database::AnalysisDatabaseConfigurationImpl::ContainerConstIter Database::AnalysisDatabaseConfigurationImpl::begin() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return container.begin();
}

Database::AnalysisDatabaseConfigurationImpl::ContainerConstIter Database::AnalysisDatabaseConfigurationImpl::end() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return container.end();
}

int Database::AnalysisDatabaseConfigurationImpl::GetSize() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(container.size());
}

Database::ConfigurationStrategy::StringOption Database::AnalysisDatabaseConfigurationImpl::GetStringOptions(const BasicTree& basicTree, bool useStringOption)
{
    ConfigurationStrategy::StringOption result{};

    if (useStringOption)
    {
        auto stringOption = basicTree.get_child(SYSTEM_TEXT("StringOption"s));

        for (const auto& flags : stringOption)
        {
            result.insert({ CoreTools::StringConversion::StandardConversionMultiByte(flags.first),
                            CoreTools::StringConversion::StandardConversionMultiByte(flags.second.get_value<System::String>()) });
        }
    }

    return result;
}

Database::ConfigurationStrategy::BooleanOption Database::AnalysisDatabaseConfigurationImpl::GetBooleanOptions(const BasicTree& basicTree, bool useBooleanOption)
{
    ConfigurationStrategy::BooleanOption result{};

    if (useBooleanOption)
    {
        auto stringOption = basicTree.get_child(SYSTEM_TEXT("BooleanOption"s));

        for (const auto& flags : stringOption)
        {
            result.insert({ CoreTools::StringConversion::StandardConversionMultiByte(flags.first), flags.second.get_value<bool>() });
        }
    }

    return result;
}

Database::ConfigurationStrategy::IntOption Database::AnalysisDatabaseConfigurationImpl::GetIntOptions(const BasicTree& basicTree, bool useIntOption)
{
    ConfigurationStrategy::IntOption result{};

    if (useIntOption)
    {
        auto stringOption = basicTree.get_child(SYSTEM_TEXT("IntOption"s));

        for (const auto& flags : stringOption)
        {
            result.insert({ CoreTools::StringConversion::StandardConversionMultiByte(flags.first), flags.second.get_value<int>() });
        }
    }

    return result;
}

Database::ConfigurationStrategy::SSLOption Database::AnalysisDatabaseConfigurationImpl::GetSSLOptions(const BasicTree& basicTree, bool useSSLOption)
{
    ConfigurationStrategy::SSLOption result{};

    if (useSSLOption)
    {
        auto stringOption = basicTree.get_child(SYSTEM_TEXT("SSLOption"s));

        for (const auto& flags : stringOption)
        {
            result.insert({ CoreTools::StringConversion::StandardConversionMultiByte(flags.first),
                            CoreTools::StringConversion::StandardConversionMultiByte(flags.second.get_value<System::String>()) });
        }
    }

    return result;
}

Database::ConfigurationStrategy::DBMapping Database::AnalysisDatabaseConfigurationImpl::GetDBMapping(const BasicTree& basicTree, bool useDBMapping)
{
    ConfigurationStrategy::DBMapping result{};

    if (useDBMapping)
    {
        auto stringOption = basicTree.get_child(SYSTEM_TEXT("DBMapping"s));

        for (const auto& flags : stringOption)
        {
            result.insert({ flags.second.get_value<int>(), CoreTools::StringConversion::StandardConversionMultiByte(flags.first) });
        }
    }

    return result;
}
