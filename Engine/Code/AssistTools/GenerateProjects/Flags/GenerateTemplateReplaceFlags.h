///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.7 (2022/04/28 16:32)

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