///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/25 11:15)

#ifndef DATABASE_CONFIGURATION_ANALYSIS_DATABASE_CONFIGURATION_H
#define DATABASE_CONFIGURATION_ANALYSIS_DATABASE_CONFIGURATION_H

#include "Database/DatabaseDll.h"

#include "ConfigurationStrategy.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <map>
#include <string>

DATABASE_PERFORMANCE_UNSHARED_EXPORT_IMPL(AnalysisDatabaseConfigurationImpl);

namespace Database
{
    class DATABASE_DEFAULT_DECLARE AnalysisDatabaseConfiguration final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(AnalysisDatabaseConfiguration);
        using Container = std::map<System::String, ConfigurationStrategy>;
        using ContainerConstIter = Container::const_iterator;

    public:
        explicit AnalysisDatabaseConfiguration(const std::string& fileName);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConfigurationStrategy GetConfigurationStrategy(const System::String& name) const;
        NODISCARD ContainerConstIter begin() const noexcept;
        NODISCARD ContainerConstIter end() const noexcept;
        NODISCARD int GetSize() const;

    private:
        PackageType impl;
    };
}

#endif  // DATABASE_CONFIGURATION_ANALYSIS_DATABASE_CONFIGURATION_H
