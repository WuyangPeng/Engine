﻿///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.0 (2023/11/08 09:45)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_PROJECT_GENERATION_TYPE_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_PROJECT_GENERATION_TYPE_H

#include "AssistTools/AssistToolsDll.h"

namespace AssistTools
{
    enum class ProjectGenerationType
    {
        Default = 0,
        Utf8 = 1,
        Sln = 2,
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_PROJECT_GENERATION_TYPE_H