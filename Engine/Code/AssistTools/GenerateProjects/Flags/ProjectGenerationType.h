/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 19:54)

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