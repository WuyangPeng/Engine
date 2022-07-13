///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/06/30 16:03)

#ifndef GAME_TEMPLATE_GENERATE_ENGINE_H
#define GAME_TEMPLATE_GENERATE_ENGINE_H

#include "CoreTools/EngineConfiguration/StringReplacing.h"

#include <string>

namespace GameTemplate
{
    class GenerateEngine
    {
    public:
        using ClassType = GenerateEngine;

    public:
        GenerateEngine(const std::string& configurationFileName, const std::string& parameterFileName);

        CLASS_INVARIANT_DECLARE;

    private:
        void Generate();

    private:
        std::string configurationFileName;
        CoreTools::StringReplacing parameter;
    };
}

#endif  // GAME_TEMPLATE_GENERATE_ENGINE_H