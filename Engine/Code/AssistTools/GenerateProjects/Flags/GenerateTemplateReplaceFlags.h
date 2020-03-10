// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 15:28)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_REPLACE_FLAGS_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_REPLACE_FLAGS_H

#include "System/Helper/ConfigMacro.h"

namespace AssistTools
{
	enum class GenerateTemplateReplace : uint32_t 
	{ 
		EndYear,
		ProjectChineseName,
		Versions,
		Date,
		Hour,
		Minute,
		ProjectCapital,
		SolutionName,
		ProjectName,
		ManagerCapital,
		ManagerName,
		ManagerChineseName,
		InterfaceName,
	};
	
} 	

#endif // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_REPLACE_FLAGS_H