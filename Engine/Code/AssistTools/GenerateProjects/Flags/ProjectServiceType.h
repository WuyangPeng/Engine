///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.0 (2023/11/08 15:06)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_PROJECT_SERVICE_TYPE_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_PROJECT_SERVICE_TYPE_H

#include "AssistTools/AssistToolsDll.h"

namespace AssistTools
{
    enum class ProjectServiceType
    {
        Tools = 0,

        Client = 1,
        Server = 2,
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_PROJECT_SERVICE_TYPE_H