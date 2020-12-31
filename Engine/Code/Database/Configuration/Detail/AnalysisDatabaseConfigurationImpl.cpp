//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 20:27)

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
    : m_Container{}, m_FileName{ fileName }, m_MainTree{}
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
    read_json(m_FileName, m_MainTree);
}

// private
void Database::AnalysisDatabaseConfigurationImpl::AnalysisMain()
{
    for (const auto& ptree : m_MainTree)
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
    auto wrappers = basicTree.get(SYSTEM_TEXT("Wrappers"s), SYSTEM_TEXT(""s));

    const auto wrappersStrategy = GetWrappersStrategy(wrappers);

    auto ip = CoreTools::StringConversion::StandardConversionMultiByte(basicTree.get(SYSTEM_TEXT("IP"s), SYSTEM_TEXT(""s)));
    auto port = basicTree.get(SYSTEM_TEXT("Port"s), 0);
    auto hostName = CoreTools::StringConversion::StandardConversionMultiByte(basicTree.get(SYSTEM_TEXT("HostName"s), SYSTEM_TEXT(""s)));
    auto userName = CoreTools::StringConversion::StandardConversionMultiByte(basicTree.get(SYSTEM_TEXT("UserName"s), SYSTEM_TEXT(""s)));
    auto password = CoreTools::StringConversion::StandardConversionMultiByte(basicTree.get(SYSTEM_TEXT("Password"s), SYSTEM_TEXT(""s)));

    auto pooling = basicTree.get(SYSTEM_TEXT("Pooling"s), false);
    auto poolMaxSize = basicTree.get(SYSTEM_TEXT("PoolMaxSize"s), 0);
    auto poolQueueTimeout = basicTree.get(SYSTEM_TEXT("PoolQueueTimeout"s), 0);
    auto poolMaxIdleTime = basicTree.get(SYSTEM_TEXT("PoolMaxIdleTime"s), 0);

    auto useFlagsOption = (0 < basicTree.get(SYSTEM_TEXT("UseFlagsOption"s), 0u));
    auto useStringOptions = (0 < basicTree.get(SYSTEM_TEXT("UseStringOption"s), 0u));
    auto useBooleanOptions = (0 < basicTree.get(SYSTEM_TEXT("UseBooleanOption"s), 0u));
    auto useIntOptions = (0 < basicTree.get(SYSTEM_TEXT("UseIntOption"s), 0u));
    auto useSSLOptions = (0 < basicTree.get(SYSTEM_TEXT("UseSSLOption"s), 0u));
    auto useDBMapping = (0 < basicTree.get(SYSTEM_TEXT("UseDBMapping"s), 0u));

    auto flagsOption = GetFlagsOption(basicTree, useFlagsOption);
    auto stringOptions = GetStringOptions(basicTree, useStringOptions);
    auto booleanOptions = GetBooleanOptions(basicTree, useBooleanOptions);
    auto intOptions = GetIntOptions(basicTree, useIntOptions);
    auto sslOptions = GetSSLOptions(basicTree, useSSLOptions);
    auto dbMapping = GetDBMapping(basicTree, useDBMapping);

    dbMapping.insert({ 0, hostName });

    ConfigurationStrategy configurationStrategy{ wrappersStrategy, ip, port, hostName, userName, password, pooling, poolMaxSize,
                                                 poolQueueTimeout, poolMaxIdleTime, flagsOption, stringOptions, booleanOptions, intOptions, sslOptions, dbMapping };

    m_Container.insert({ name, configurationStrategy });
}

// private
Database::ConfigurationStrategy::FlagsOption Database::AnalysisDatabaseConfigurationImpl::GetFlagsOption(const BasicTree& basicTree, bool useFlagsOption)
{
    vector<string> result;

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

    const auto iter = m_Container.find(name);

    if (iter != m_Container.cend())
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

    THROW_EXCEPTION(SYSTEM_TEXT("数据库包装器类型不存在。"s));
}

Database::AnalysisDatabaseConfigurationImpl::ContainerConstIter Database::AnalysisDatabaseConfigurationImpl::begin() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return m_Container.begin();
}

Database::AnalysisDatabaseConfigurationImpl::ContainerConstIter Database::AnalysisDatabaseConfigurationImpl::end() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return m_Container.end();
}

int Database::AnalysisDatabaseConfigurationImpl::GetSize() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(m_Container.size());
}

Database::ConfigurationStrategy::StringOption Database::AnalysisDatabaseConfigurationImpl::GetStringOptions(const BasicTree& basicTree, bool useStringOption)
{
    Database::ConfigurationStrategy::StringOption result{};

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
    Database::ConfigurationStrategy::BooleanOption result{};

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
    Database::ConfigurationStrategy::IntOption result{};

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
    Database::ConfigurationStrategy::SSLOption result{};

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
    Database::ConfigurationStrategy::DBMapping result{};

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
