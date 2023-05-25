///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.9 (2023/05/22 16:25)

#ifndef DATABASE_CONFIGURATION_ANALYSIS_DATABASE_CONFIGURATION_IMPL_H
#define DATABASE_CONFIGURATION_ANALYSIS_DATABASE_CONFIGURATION_IMPL_H

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

        NODISCARD ConfigurationStrategy GetConfigurationStrategy(const String& name) const;
        NODISCARD ContainerConstIter begin() const noexcept;
        NODISCARD ContainerConstIter end() const noexcept;
        NODISCARD int GetSize() const;

    private:
        using BasicTree = boost::property_tree::basic_ptree<String, String>;

    private:
        void Analysis();
        void AnalysisJson();
        void AnalysisMain();
        void InsertStrategy(const String& name, const BasicTree& basicTree);
        NODISCARD static WrappersStrategy GetWrappersStrategy(const String& wrappers);

    private:
        NODISCARD ConfigurationStrategy::FlagsOption GetFlagsOption(const BasicTree& basicTree, bool useFlagsOption);
        NODISCARD ConfigurationStrategy::StringOption GetStringOptions(const BasicTree& basicTree, bool useStringOption);
        NODISCARD ConfigurationStrategy::BooleanOption GetBooleanOptions(const BasicTree& basicTree, bool useBooleanOption);
        NODISCARD ConfigurationStrategy::IntOption GetIntOptions(const BasicTree& basicTree, bool useIntOption);
        NODISCARD ConfigurationStrategy::SSLOption GetSSLOptions(const BasicTree& basicTree, bool useSSLOption);
        NODISCARD ConfigurationStrategy::DBMapping GetDBMapping(const BasicTree& basicTree, bool useDBMapping);

    private:
        Container container;
        std::string fileName;
        BasicTree mainTree;
    };
}

#endif  // DATABASE_CONFIGURATION_ANALYSIS_DATABASE_CONFIGURATION_IMPL_H
