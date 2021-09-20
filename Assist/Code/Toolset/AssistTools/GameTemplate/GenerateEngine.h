// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.2.1 (2020/01/11 1:13)

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
		std::string m_ConfigurationFileName;
		CoreTools::StringReplacing m_Parameter;
	};
}

#endif // GAME_TEMPLATE_GENERATE_ENGINE_H