//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 20:22)

#ifndef DATABASE_CONFIGURATION_ANALYSIS_DATABASE_CONFIGURATION_IMPLL_H
#define DATABASE_CONFIGURATION_ANALYSIS_DATABASE_CONFIGURATION_IMPLL_H

#include "Database/DatabaseDll.h"

#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "System/Helper/UnicodeUsing.h"
#include "Database/Configuration/ConfigurationStrategy.h"

#include <map>
#include <string>

namespace Database
{
    class DATABASE_HIDDEN_DECLARE AnalysisDatabaseConfigurationImpl final
    {
    public:
        using ClassType = AnalysisDatabaseConfigurationImpl;
        using Container = std::map<System::String, ConfigurationStrategy>;
        using ContainerConstIter = Container::const_iterator;
        using String = System::String;

    public:
        explicit AnalysisDatabaseConfigurationImpl(const std::string& fileName);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] ConfigurationStrategy GetConfigurationStrategy(const String& name) const;
        [[nodiscard]] ContainerConstIter begin() const noexcept;
        [[nodiscard]] ContainerConstIter end() const noexcept;
        [[nodiscard]] int GetSize() const;

    private:
        using BasicTree = boost::property_tree::basic_ptree<String, String>;

    private:
        void Analysis();
        void AnalysisJson();
        void AnalysisMain();
        void InsertStrategy(const String& name, const BasicTree& basicTree);
        [[nodiscard]] static WrappersStrategy GetWrappersStrategy(const String& wrappers);

    private:
        [[nodiscard]] ConfigurationStrategy::FlagsOption GetFlagsOption(const BasicTree& basicTree, bool useFlagsOption);
        [[nodiscard]] ConfigurationStrategy::StringOption GetStringOptions(const BasicTree& basicTree, bool useStringOption);
        [[nodiscard]] ConfigurationStrategy::BooleanOption GetBooleanOptions(const BasicTree& basicTree, bool useBooleanOption);
        [[nodiscard]] ConfigurationStrategy::IntOption GetIntOptions(const BasicTree& basicTree, bool useIntOption);
        [[nodiscard]] ConfigurationStrategy::SSLOption GetSSLOptions(const BasicTree& basicTree, bool useSSLOption);
        [[nodiscard]] ConfigurationStrategy::DBMapping GetDBMapping(const BasicTree& basicTree, bool useDBMapping);

    private:
        Container m_Container;
        std::string m_FileName;
        BasicTree m_MainTree;
    };
}

#endif  // DATABASE_CONFIGURATION_ANALYSIS_DATABASE_CONFIGURATION_IMPLL_H
