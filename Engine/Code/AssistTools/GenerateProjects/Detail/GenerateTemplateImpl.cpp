// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/07/31 15:35)

#include "AssistTools/AssistToolsExport.h"

#include "System/Helper/PragmaWarning/Disable4996.h"
#include "GenerateTemplateImpl.h"
#include "System/FileManager/FileTools.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/FileManager/OFStreamManager.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
 
#include "System/Helper/PragmaWarning/Algorithm.h" 

#include <vector>

using std::vector;
using namespace std::literals;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
const System::String AssistTools::GenerateTemplateImpl
	::sm_ForwardSlash(SYSTEM_TEXT("/"));
 #include STSTEM_WARNING_POP
AssistTools::GenerateTemplateImpl
	::GenerateTemplateImpl(const System::String& templateFileName, const System::String& extension)
	:m_FileContent(ReadFile(templateFileName)), m_Extension(extension)
{
	ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

 

#ifdef OPEN_CLASS_INVARIANT
bool AssistTools::GenerateTemplateImpl
	::IsValid() const noexcept
{
	if (!m_FileContent.empty())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

void AssistTools::GenerateTemplateImpl
	::Generate (const System::String& resourceDirectory, const System::String& newProjectName,const VariableType& newVariable) const
{
	ASSIST_TOOLS_CLASS_IS_VALID_1;

	const System::String percent(SYSTEM_TEXT("%"));  

	NewDirectory(resourceDirectory);

	CoreTools::OFStreamManager manager(resourceDirectory + sm_ForwardSlash + newProjectName + m_Extension, false); 

	System::String fileContent = m_FileContent;

	for(const VariableValueType& value: newVariable)
	{	 
		boost::replace_all(fileContent, percent + value.first + percent, value.second);		 		
	} 

	manager << fileContent;
}

// static
// private
const System::String AssistTools::GenerateTemplateImpl
	::ReadFile(const System::String& templateFileName)
{
	CoreTools::IFStreamManager manager(templateFileName);

	System::String fileContent = manager.GetFileContent();

	if (fileContent.empty())
	{
		THROW_EXCEPTION(SYSTEM_TEXT("读取的工程解决方案模板不合法。"s));
	}

	return fileContent;
}

void AssistTools::GenerateTemplateImpl
	::NewDirectory(const System::String& directory) const
{
	vector<System::String> splitDirectory;

	boost::split(splitDirectory, directory, boost::is_any_of(sm_ForwardSlash));

	System::String createDiectory;
	for(const vector<System::String>::value_type& value:splitDirectory)
	{
		createDiectory += value;

		[[maybe_unused]] const auto result = System::CreateFileDirectory(createDiectory, nullptr);

		createDiectory += sm_ForwardSlash;
	}	
}

const System::String AssistTools::GenerateTemplateImpl
	::GetTesting()
{
	return SYSTEM_TEXT("Testing");
}

 