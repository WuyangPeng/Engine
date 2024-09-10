/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.0 (2024/08/09 17:32)

#include "CoreTools/CoreToolsExport.h"

#include "JsonAnalysisManager.h"
#include "Detail/JsonAnalysisManagerImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

SINGLETON_GET_PTR_DEFINE(CoreTools, JsonAnalysisManager);

CoreTools::JsonAnalysisManager::JsonAnalysisManagerUniquePtr CoreTools::JsonAnalysisManager::jsonAnalysisManager{};

void CoreTools::JsonAnalysisManager::Create()
{
    jsonAnalysisManager = std::make_unique<JsonAnalysisManager>(JsonAnalysisManagerCreate::Init);
}

void CoreTools::JsonAnalysisManager::Destroy() noexcept
{
    jsonAnalysisManager.reset();
}

CoreTools::JsonAnalysisManager::JsonAnalysisManager(JsonAnalysisManagerCreate jsonAnalysisManagerCreate)
    : impl{ ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(jsonAnalysisManagerCreate);

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, JsonAnalysisManager)

CoreTools::JsonAnalysisManager::FactoryFunction CoreTools::JsonAnalysisManager::Find(const std::string& name) const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->Find(name);
}

void CoreTools::JsonAnalysisManager::Insert(const std::string& name, FactoryFunction function)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    return impl->Insert(name, function);
}

void CoreTools::JsonAnalysisManager::Remove(const std::string& name)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    return impl->Remove(name);
}

CoreTools::JsonAnalysisManager::JsonBaseSharedPtr CoreTools::JsonAnalysisManager::Create(const std::string& fileName, const std::string& rttiName) const
{
    JsonBase::BasicTree mainTree{};
    read_json(fileName, mainTree);

    SINGLETON_MUTEX_ENTER_MEMBER;

    if (const auto factoryFunction = Find(rttiName);
        factoryFunction != nullptr)
    {
        return factoryFunction(mainTree);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("找不到工厂函数。"))
    }
}