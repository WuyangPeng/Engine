///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/31 10:27)

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
        explicit GenerateEngine(std::string configurationFileNam);

        CLASS_INVARIANT_DECLARE;

    private:
        using StringReplacing = CoreTools::StringReplacing;

    private:
        void Generate();

    private:
        std::string configurationFileName;
    };
}

#endif  // GAME_TESTING_TEMPLATE_GENERATE_ENGINE_H