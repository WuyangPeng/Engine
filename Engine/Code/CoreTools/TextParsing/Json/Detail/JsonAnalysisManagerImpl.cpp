﻿/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.0 (2024/08/09 17:37)

#include "CoreTools/CoreToolsExport.h"

#include "JsonAnalysisManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::JsonAnalysisManagerImpl::JsonAnalysisManagerImpl() noexcept
    : factories{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, JsonAnalysisManagerImpl)

CoreTools::JsonAnalysisManagerImpl::FactoryFunction CoreTools::JsonAnalysisManagerImpl::Find(const std::string& name) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (const auto iter = factories.find(name);
        iter != factories.cend())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("找不到指定的工厂函数！"s))
    }
}

void CoreTools::JsonAnalysisManagerImpl::Insert(const std::string& name, FactoryFunction function)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    factories.emplace(name, function);
}

void CoreTools::JsonAnalysisManagerImpl::Remove(const std::string& name) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    factories.erase(name);
}
