/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.0 (2024/08/09 17:37)

#ifndef CORE_TOOLS_TEXT_PARSING_JSON_JSON_ANALYSIS_MANAGER_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_JSON_JSON_ANALYSIS_MANAGER_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/TextParsing/Json/JsonBase.h"

#include <map>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE JsonAnalysisManagerImpl
    {
    public:
        using ClassType = JsonAnalysisManagerImpl;

        using FactoryFunction = JsonBase::FactoryFunction;

    public:
        JsonAnalysisManagerImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD FactoryFunction Find(const std::string& name) const;
        void Insert(const std::string& name, FactoryFunction function);
        void Remove(const std::string& name) noexcept;

    private:
        using FactoryContainer = std::map<std::string, FactoryFunction>;

    private:
        FactoryContainer factories;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_JSON_JSON_ANALYSIS_MANAGER_IMPL_H