//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/15 9:46)

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
        using AppenderManagerPtr = std::shared_ptr<AppenderManager>;

    public:
        explicit AnalysisAppenderManager(const std::string& fileName);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] AppenderManagerPtr GetAppenderManager() const noexcept;

    private:
        using String = System::String;
        using BasicTree = boost::property_tree::basic_ptree<String, String>;

    private:
        void Analysis();
        void AnalysisJson();
        void AnalysisLogger();
        void InsertLogger(LogLevel levelType, LogFilter filterType);
        void AnalysisAppender();
        bool AnalysisConsoleAppender();
        bool AnalysisFileAppender();
        bool AnalysisFileConfigurationAppender();
        bool InsertAppender(const BasicTree& fileTreeData);

    private:
        AppenderManagerPtr m_AppenderManager;
        std::string m_FileName;
        BasicTree m_MainTree;
        BasicTree m_AppenderTree;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_ANALYSIS_APPENDER_MANAGER_H
