//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 20:25)

#ifndef DATABASE_CONFIGURATION_ANALYSIS_DATABASE_CONFIGURATION_H
#define DATABASE_CONFIGURATION_ANALYSIS_DATABASE_CONFIGURATION_H

#include "Database/DatabaseDll.h"

#include "ConfigurationStrategy.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <map>
#include <string>

DATABASE_EXPORT_SHARED_PTR(AnalysisDatabaseConfigurationImpl);

namespace Database
{
    class DATABASE_DEFAULT_DECLARE AnalysisDatabaseConfiguration final
    {
    public:
        PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(AnalysisDatabaseConfiguration);
        using Container = std::map<System::String, ConfigurationStrategy>;
        using ContainerConstIter = Container::const_iterator;

    public:
        explicit AnalysisDatabaseConfiguration(const std::string& fileName);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] ConfigurationStrategy GetConfigurationStrategy(const System::String& name) const;
        [[nodiscard]] ContainerConstIter begin() const noexcept;
        [[nodiscard]] ContainerConstIter end() const noexcept;
        [[nodiscard]] int GetSize() const;

    private:
        IMPL_TYPE_DECLARE(AnalysisDatabaseConfiguration);
    };
}

#endif  // DATABASE_CONFIGURATION_ANALYSIS_DATABASE_CONFIGURATION_H
