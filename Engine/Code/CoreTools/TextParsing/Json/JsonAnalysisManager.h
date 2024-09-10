/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.0 (2024/08/09 17:32)

#ifndef CORE_TOOLS_TEXT_PARSING_JSON_JSON_ANALYSIS_MANAGER_H
#define CORE_TOOLS_TEXT_PARSING_JSON_JSON_ANALYSIS_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "JsonBase.h"
#include "CoreTools/Base/Singleton.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"

CORE_TOOLS_EXPORT_UNIQUE_PTR(JsonAnalysisManager);
CORE_TOOLS_NON_COPY_EXPORT_IMPL(JsonAnalysisManagerImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE JsonAnalysisManager final : public Singleton<JsonAnalysisManager>
    {
    public:
        NON_COPY_TYPE_DECLARE(JsonAnalysisManager);
        using ParentType = Singleton<JsonAnalysisManager>;

        using FactoryFunction = JsonBase::FactoryFunction;
        using JsonBaseSharedPtr = JsonBase::JsonBaseSharedPtr;

    private:
        enum class JsonAnalysisManagerCreate
        {
            Init,
        };

    public:
        explicit JsonAnalysisManager(JsonAnalysisManagerCreate jsonAnalysisManagerCreate);

        static void Create();
        static void Destroy() noexcept;

        SINGLETON_GET_PTR_DECLARE(JsonAnalysisManager);

        CLASS_INVARIANT_DECLARE;

        NODISCARD FactoryFunction Find(const std::string& name) const;
        void Insert(const std::string& name, FactoryFunction function);
        void Remove(const std::string& name);

        NODISCARD JsonBaseSharedPtr Create(const std::string& fileName, const std::string& rttiName) const;

    private:
        using JsonAnalysisManagerUniquePtr = std::unique_ptr<JsonAnalysisManager>;

    private:
        static JsonAnalysisManagerUniquePtr jsonAnalysisManager;
        PackageType impl;
    };
}

#define JSON_ANALYSIS_MANAGER_SINGLETON CoreTools::JsonAnalysisManager::GetSingleton()

#endif  // CORE_TOOLS_TEXT_PARSING_JSON_JSON_ANALYSIS_MANAGER_H