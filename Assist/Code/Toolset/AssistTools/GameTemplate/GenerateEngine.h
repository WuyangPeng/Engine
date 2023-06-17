///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/13 10:32)

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