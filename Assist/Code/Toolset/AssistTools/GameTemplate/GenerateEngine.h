///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��1.0.0.0 (2023/11/18 14:03)

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
        explicit GenerateEngine(std::string configurationFileName);

        CLASS_INVARIANT_DECLARE;

    private:
        using StringReplacing = CoreTools::StringReplacing;

    private:
        void Generate();

    private:
        std::string configurationFileName;
    };
}

#endif  // GAME_TEMPLATE_GENERATE_ENGINE_H