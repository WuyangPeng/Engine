///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.0 (2023/11/17 16:06)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_ENGINE_BASE_DETAIL_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_ENGINE_BASE_DETAIL_H

#include "GenerateDirectory.h"
#include "GenerateEngineBase.h"
#include "ModuleGenerate.h"

#include <type_traits>

namespace AssistTools
{
    template <typename T>
    requires(std::is_base_of_v<ModuleGenerate, T>)
    void GenerateEngineBase::ExecuteModuleGenerate(const GenerateDirectory& directory) const
    {
        T moduleGenerate{ gameParameterAnalysis, codeMappingAnalysis, directory };

        moduleGenerate.Generate();
    }
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_ENGINE_BASE_DETAIL_H
