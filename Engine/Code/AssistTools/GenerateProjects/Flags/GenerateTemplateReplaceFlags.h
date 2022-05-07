///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/04/28 16:32)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_REPLACE_FLAGS_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_REPLACE_FLAGS_H

#include "System/Helper/ConfigMacro.h"

namespace AssistTools
{
    enum class GenerateTemplateReplace
    {
        EndYear,
        ProjectChineseName,
        Versions,
        Date,
        Hour,
        Minute,
        ProjectCapital,
        SolutionName,
        ProjectName,
        ManagerCapital,
        ManagerName,
        ManagerChineseName,
        InterfaceName,
    };

}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_REPLACE_FLAGS_H