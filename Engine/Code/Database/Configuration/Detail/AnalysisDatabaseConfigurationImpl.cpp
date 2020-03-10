// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/03 09:44)

#include "Database/DatabaseExport.h" 

#include "AnalysisDatabaseConfigurationImpl.h" 
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h" 
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/CharacterString/CaseInsensitiveStringDetail.h" 

#include <boost/property_tree/json_parser.hpp>
#include <boost/numeric/conversion/cast.hpp>

using std::string; 
using std::vector;
using std::map;

Database::AnalysisDatabaseConfigurationImpl
	::AnalysisDatabaseConfigurationImpl( const string& fileName )
	:m_Container{}, m_FileName{ fileName }, m_MainTree{}
{
	Analysis();

	DATABASE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Database, AnalysisDatabaseConfigurationImpl)

// private
void Database::AnalysisDatabaseConfigurationImpl
	::Analysis()
{
	AnalysisJson(); 
	AnalysisMain();
}

// private
void Database::AnalysisDatabaseConfigurationImpl
	::AnalysisJson()
{
	read_json(m_FileName,m_MainTree);
}

// private
void Database::AnalysisDatabaseConfigurationImpl
	::AnalysisMain()
{
	for (const auto& ptree : m_MainTree)
	{
		try
		{		
			InsertStrategy(ptree.first, ptree.second);		
		}
		catch (CoreTools::Error& error)
		{
			LOG_SINGLETON_ENGINE_APPENDER(Warn, Database)
				<< SYSTEM_TEXT("数据库策略")
				<< ptree.first
				<< SYSTEM_TEXT("配置值错误：")
				<< error
				<< CoreTools::LogAppenderIOManageSign::TriggerAssert;
		}	
	}
}

// private
void Database::AnalysisDatabaseConfigurationImpl
	::InsertStrategy(const System::String& name, const BasicTree& basicTree)
{
	auto wrappers = basicTree.get(SYSTEM_TEXT("Wrappers"), System::String{});

	auto wrappersStrategy = GetWrappersStrategy(wrappers);

	auto ip = CoreTools::StringConversion::StandardConversionMultiByte(basicTree.get(SYSTEM_TEXT("IP"), System::String{}));
	auto port = basicTree.get(SYSTEM_TEXT("Port"), 0u); 
	auto hostName = CoreTools::StringConversion::StandardConversionMultiByte(basicTree.get(SYSTEM_TEXT("HostName"), System::String{}));
	auto userName = CoreTools::StringConversion::StandardConversionMultiByte(basicTree.get(SYSTEM_TEXT("UserName"), System::String{}));
	auto password = CoreTools::StringConversion::StandardConversionMultiByte(basicTree.get(SYSTEM_TEXT("Password"), System::String{}));	

	auto pooling = basicTree.get(SYSTEM_TEXT("Pooling"), false);
	auto poolMaxSize = basicTree.get(SYSTEM_TEXT("PoolMaxSize"), 0);
	auto poolQueueTimeout = basicTree.get(SYSTEM_TEXT("PoolQueueTimeout"),0 );
	auto poolMaxIdleTime = basicTree.get(SYSTEM_TEXT("PoolMaxIdleTime"), 0);

	auto useFlagsOption = (0 < basicTree.get(SYSTEM_TEXT("UseFlagsOption"), 0u));
	auto useStringOptions = (0 < basicTree.get(SYSTEM_TEXT("UseStringOption"), 0u));
	auto useBooleanOptions = (0 < basicTree.get(SYSTEM_TEXT("UseBooleanOption"), 0u));
	auto useIntOptions = (0 < basicTree.get(SYSTEM_TEXT("UseIntOption"), 0u));
	auto useSSLOptions = (0 < basicTree.get(SYSTEM_TEXT("UseSSLOption"), 0u));
	auto useDBMapping = (0 < basicTree.get(SYSTEM_TEXT("UseDBMapping"), 0u));
	
	auto flagsOption = GetFlagsOption(basicTree,useFlagsOption);
	auto stringOptions = GetStringOptions(basicTree, useStringOptions);
	auto booleanOptions = GetBooleanOptions(basicTree, useBooleanOptions);
	auto intOptions = GetIntOptions(basicTree, useIntOptions);
	auto sslOptions = GetSSLOptions(basicTree, useSSLOptions); 
	auto dbMapping = GetDBMapping(basicTree, useDBMapping);

	dbMapping.insert({ 0,hostName });

	ConfigurationStrategy configurationStrategy{ wrappersStrategy ,ip,port,hostName,userName,password,pooling,poolMaxSize,
		                                         poolQueueTimeout,poolMaxIdleTime,flagsOption,stringOptions,booleanOptions,intOptions,sslOptions,dbMapping };

	m_Container.insert({ name ,configurationStrategy });
}

// private
Database::ConfigurationStrategy::FlagsOption Database::AnalysisDatabaseConfigurationImpl
	::GetFlagsOption(const BasicTree& basicTree,bool useFlagsOption)
{
	vector<string> result;

	if (useFlagsOption)
	{
		auto flagsOption = basicTree.get_child(SYSTEM_TEXT("FlagsOption"));

		for (const auto& flags : flagsOption)
		{
			if (0 < flags.second.get_value<int>())
			{
				result.push_back(CoreTools::StringConversion::StandardConversionMultiByte(flags.first));
			}
		}
	}
	
	return result;
}

Database::ConfigurationStrategy Database::AnalysisDatabaseConfigurationImpl
	::GetConfigurationStrategy(const System::String& name) const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

	auto iter = m_Container.find(name);

	if (iter != m_Container.end())
	{
		return iter->second;
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("找不到指定名字的配置。"));
	}	 
}

Database::WrappersStrategy Database::AnalysisDatabaseConfigurationImpl
	::GetWrappersStrategy(const System::String& wrappers)
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

	THROW_EXCEPTION(SYSTEM_TEXT("数据库包装器类型不存在。"));
} 

Database::AnalysisDatabaseConfigurationImpl::ContainerConstIter Database::AnalysisDatabaseConfigurationImpl
	::GetBegin() const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

	return m_Container.begin();
}

Database::AnalysisDatabaseConfigurationImpl::ContainerConstIter Database::AnalysisDatabaseConfigurationImpl
	::GetEnd() const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

	return m_Container.end();
}

int Database::AnalysisDatabaseConfigurationImpl
	::GetSize() const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

	return boost::numeric_cast<int>(m_Container.size());
}

Database::ConfigurationStrategy::StringOption Database::AnalysisDatabaseConfigurationImpl
	::GetStringOptions(const BasicTree& basicTree, bool useStringOption)
{
	Database::ConfigurationStrategy::StringOption  result;

	if (useStringOption)
	{
		auto stringOption = basicTree.get_child(SYSTEM_TEXT("StringOption"));

		for (const auto& flags : stringOption)
		{	
			result.insert({ CoreTools::StringConversion::StandardConversionMultiByte(flags.first),
							CoreTools::StringConversion::StandardConversionMultiByte(flags.second.get_value<System::String>()) });			
		}
	}

	return result;
}

Database::ConfigurationStrategy::BooleanOption Database::AnalysisDatabaseConfigurationImpl
	::GetBooleanOptions(const BasicTree& basicTree, bool useBooleanOption)
{
	Database::ConfigurationStrategy::BooleanOption  result;

	if (useBooleanOption)
	{
		auto stringOption = basicTree.get_child(SYSTEM_TEXT("BooleanOption"));

		for (const auto& flags : stringOption)
		{
			result.insert({ CoreTools::StringConversion::StandardConversionMultiByte(flags.first),flags.second.get_value<bool>() });
		}
	}

	return result;
}

Database::ConfigurationStrategy::IntOption Database::AnalysisDatabaseConfigurationImpl
	::GetIntOptions(const BasicTree& basicTree, bool useIntOption)
{
	Database::ConfigurationStrategy::IntOption  result;

	if (useIntOption)
	{
		auto stringOption = basicTree.get_child(SYSTEM_TEXT("IntOption"));

		for (const auto& flags : stringOption)
		{
			result.insert({ CoreTools::StringConversion::StandardConversionMultiByte(flags.first),flags.second.get_value<int>() });
		}
	}

	return result;
}

Database::ConfigurationStrategy::SSLOption Database::AnalysisDatabaseConfigurationImpl
	::GetSSLOptions(const BasicTree& basicTree, bool useSSLOption)
{
	Database::ConfigurationStrategy::SSLOption  result;

	if (useSSLOption)
	{
		auto stringOption = basicTree.get_child(SYSTEM_TEXT("SSLOption"));

		for (const auto& flags : stringOption)
		{
			result.insert({ CoreTools::StringConversion::StandardConversionMultiByte(flags.first),
							CoreTools::StringConversion::StandardConversionMultiByte(flags.second.get_value<System::String>()) });
		}
	}

	return result;
}

Database::ConfigurationStrategy::DBMapping Database::AnalysisDatabaseConfigurationImpl
	::GetDBMapping(const BasicTree& basicTree, bool useDBMapping)
{
	Database::ConfigurationStrategy::DBMapping result;

	if (useDBMapping)
	{
		auto stringOption = basicTree.get_child(SYSTEM_TEXT("DBMapping"));

		for (const auto& flags : stringOption)
		{
			result.insert({ flags.second.get_value<int>(),CoreTools::StringConversion::StandardConversionMultiByte(flags.first)});
		}
	}

	return result;
}

