/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/28 22:39)

#ifndef DATABASE_GENERATE_MIDDLE_LAYER_SYSTEM_SYSTEM_MANAGER_IMPL_H
#define DATABASE_GENERATE_MIDDLE_LAYER_SYSTEM_SYSTEM_MANAGER_IMPL_H

#include "DatabaseGenerate/DatabaseGenerateMiddleLayer/DatabaseGenerateMiddleLayerDll.h"

#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/AncientBooksContainer.h"
#include "DatabaseGenerate/DatabaseGenerateMiddleLayer/Helper/ExportMacro.h"
#include "Database/Configuration/AnalysisDatabaseConfiguration.h"

#include <mutex>
#include <thread>

namespace DatabaseGenerateMiddleLayer
{
    class DATABASE_GENERATE_MIDDLE_LAYER_HIDDEN_DECLARE SystemManagerImpl final
    {
    public:
        using ClassType = SystemManagerImpl;

        using AncientBooksContainer = AncientBooks::AncientBooksContainer;

    public:
        explicit SystemManagerImpl(const std::string& fileName);

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool Idle(const AncientBooksContainer& ancientBooksContainer);

        NODISCARD bool Initialize();
        NODISCARD bool Destroy() noexcept;

    private:
        using ThreadContainer = std::vector<std::jthread>;
        using ConfigurationStrategy = Database::ConfigurationStrategy;
        using AnalysisDatabaseConfiguration = Database::AnalysisDatabaseConfiguration;

    private:
        void SaveDatabase(const ConfigurationStrategy& configurationStrategy, const AncientBooksContainer& ancientBooksContainer);
        void CreateSaveDatabaseThread(const AncientBooksContainer& ancientBooksContainer);
        void CreateSaveDatabaseThread(const ConfigurationStrategy& configurationStrategy, const AncientBooksContainer& ancientBooksContainer);

    private:
        bool isSave;
        AnalysisDatabaseConfiguration analysisDatabaseConfiguration;
        ThreadContainer thread;
        std::mutex mutex;
        std::atomic_int finishCount;
    };
}

#endif  // DATABASE_GENERATE_MIDDLE_LAYER_SYSTEM_MANAGER_IMPL_H
