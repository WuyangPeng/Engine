// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 15:31)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_TEMPLATE_VC100_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_TEMPLATE_VC100_H

#include "AssistTools/AssistToolsDll.h"

namespace AssistTools
{
	class ASSIST_TOOLS_DEFAULT_DECLARE TemplateVC100
	{
	public:
		static void GenerateDx9 (const char* projectName);
		static void GenerateWgl (const char* projectName);

	private:
		static void Generate (const char* projectName, const char* prefix, const char* projectLines[]);

		enum
		{
			NUM_PROJECT_LINES = 330,
			NUM_FILTER_LINES = 23
		};

		static const char* msDx9ProjectLines[NUM_PROJECT_LINES];
		static const char* msWglProjectLines[NUM_PROJECT_LINES];
		static const  char* msFilterLines[NUM_FILTER_LINES];
	};
}

#endif // ASSIST_TOOLS_GENERATE_PROJECTS_TEMPLATE_VC100_H
