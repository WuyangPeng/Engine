// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 15:23)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_IMPL_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_IMPL_H

#include "AssistTools/AssistToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <string> 
#include <map>

namespace AssistTools
{
	class ASSIST_TOOLS_HIDDEN_DECLARE GenerateTemplateImpl
	{
	public:
		using ClassType = GenerateTemplateImpl ;
		using VariableType = std::map<System::String, System::String> ;

	public:
		GenerateTemplateImpl(const System::String& templateFileName, const System::String& extension);
		virtual ~GenerateTemplateImpl() noexcept = default;
		GenerateTemplateImpl(const GenerateTemplateImpl& rhs) = default;
		GenerateTemplateImpl& operator=(const GenerateTemplateImpl& rhs) = default;
		GenerateTemplateImpl(GenerateTemplateImpl&& rhs) noexcept = default;
		GenerateTemplateImpl& operator=(GenerateTemplateImpl&& rhs) noexcept = default;

		CLASS_INVARIANT_VIRTUAL_DECLARE;		

	protected:
		static const System::String GetTesting();

		void Generate (const System::String& resourceDirectory, const System::String& newProjectName, 
			            const VariableType& newVariable) const;

	private:
		using VariableValueType = VariableType::value_type ;

	private:
		static const System::String ReadFile(const System::String& templateFileName);		

		void NewDirectory(const System::String& directory) const;

	private:
		static const System::String sm_ForwardSlash;

		System::String m_FileContent; 
		System::String m_Extension;
	};
}

#endif // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_IMPL_H
