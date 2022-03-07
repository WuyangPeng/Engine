///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/06 0:09)

#ifndef CORE_TOOLS_LOG_MANAGER_ANALYSIS_APPENDER_MANAGER_H
#define CORE_TOOLS_LOG_MANAGER_ANALYSIS_APPENDER_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/LogManager/LogManagerFwd.h"

#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE AnalysisAppenderManager final
    {
    public:
        using ClassType = AnalysisAppenderManager;
        using AppenderManagerSharedPtr = std::shared_ptr<AppenderManager>;

    public:
        explicit AnalysisAppenderManager(const std::string& fileName);

        CLASS_INVARIANT_DECLARE;

        NODISCARD AppenderManagerSharedPtr GetAppenderManager() const noexcept;

    private:
        using String = System::String;
        using BasicTree = boost::property_tree::basic_ptree<String, String>;

    private:
        void Analysis();
        void AnalysisJson();
        void AnalysisLogger();
        void InsertLogger(LogLevel levelType, LogFilter filterType);
        void AnalysisAppender();
        NODISCARD bool AnalysisConsoleAppender();
        NODISCARD bool AnalysisFileAppender();
        NODISCARD bool AnalysisFileConfigurationAppender();
        NODISCARD bool InsertAppender(const BasicTree& fileTreeData);

    private:
        AppenderManagerSharedPtr appenderManager;
        std::string fileName;
        BasicTree mainTree;
        BasicTree appenderTree;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_ANALYSIS_APPENDER_MANAGER_H
