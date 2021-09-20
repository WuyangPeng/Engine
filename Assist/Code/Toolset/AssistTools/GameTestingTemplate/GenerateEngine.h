// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.1 (2020/01/12 0:33)

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
		std::string m_ConfigurationFileName;
		CoreTools::StringReplacing m_Parameter;
	};
}

#endif // GAME_TESTING_TEMPLATE_GENERATE_ENGINE_H