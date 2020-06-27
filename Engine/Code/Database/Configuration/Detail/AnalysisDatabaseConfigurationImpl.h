// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/16 10:52)

#ifndef DATABASE_DATABASE_CONFIGURATION_ANALYSIS_DATABASE_CONFIGURATION_IMPLL_H
#define DATABASE_DATABASE_CONFIGURATION_ANALYSIS_DATABASE_CONFIGURATION_IMPLL_H

#include "Database/DatabaseDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "Database/Configuration/ConfigurationStrategy.h"

#include <map>
#include <string>

namespace Database
{
	class DATABASE_HIDDEN_DECLARE AnalysisDatabaseConfigurationImpl
	{
	public:
		using ClassType = AnalysisDatabaseConfigurationImpl;
		using Container = std::map<System::String, ConfigurationStrategy>;
		using ContainerConstIter = Container::const_iterator;

	public:
		explicit AnalysisDatabaseConfigurationImpl(const std::string& fileName);

		CLASS_INVARIANT_DECLARE;

		ConfigurationStrategy GetConfigurationStrategy(const System::String& name) const;
		ContainerConstIter GetBegin() const;
		ContainerConstIter GetEnd() const;
		int GetSize() const;

	private:
		using BasicTree = boost::property_tree::basic_ptree<System::String, System::String>;

	private:
		void Analysis();
		void AnalysisJson();
		void AnalysisMain();
		void InsertStrategy(const System::String& name, const BasicTree& basicTree);
		static WrappersStrategy GetWrappersStrategy(const System::String& wrappers);

	private:
		ConfigurationStrategy::FlagsOption GetFlagsOption(const BasicTree& basicTree, bool useFlagsOption);
		ConfigurationStrategy::StringOption GetStringOptions(const BasicTree& basicTree, bool useStringOption);
		ConfigurationStrategy::BooleanOption GetBooleanOptions(const BasicTree& basicTree, bool useBooleanOption);
		ConfigurationStrategy::IntOption GetIntOptions(const BasicTree& basicTree, bool useIntOption);
		ConfigurationStrategy::SSLOption GetSSLOptions(const BasicTree& basicTree, bool useSSLOption);
		ConfigurationStrategy::DBMapping GetDBMapping(const BasicTree& basicTree, bool useDBMapping);

	private:
		Container m_Container;
		std::string m_FileName;
		BasicTree m_MainTree;
	};
}

#endif // DATABASE_DATABASE_CONFIGURATION_ANALYSIS_DATABASE_CONFIGURATION_IMPLL_H


