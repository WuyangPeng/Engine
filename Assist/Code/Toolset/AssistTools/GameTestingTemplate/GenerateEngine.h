///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.12 (2023/06/13 10:35)

#ifndef GAME_TESTING_TEMPLATE_GENERATE_ENGINE_H
#define GAME_TESTING_TEMPLATE_GENERATE_ENGINE_H

#include "CoreTools/EngineConfiguration/StringReplacing.h"

#include <string>

namespace GameTestingTemplate
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

#endif  // GAME_TESTING_TEMPLATE_GENERATE_ENGINE_H