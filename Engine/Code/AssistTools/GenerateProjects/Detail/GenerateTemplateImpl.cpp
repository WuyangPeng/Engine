///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2022/04/29 11:06)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateImpl.h"
#include "System/FileManager/FileTools.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Helper/PragmaWarning/Disable4996.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/FileManager/OFStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <vector>

using std::vector;
using namespace std::literals;

const System::String AssistTools::GenerateTemplateImpl::forwardSlash{ SYSTEM_TEXT("/") };

AssistTools::GenerateTemplateImpl::GenerateTemplateImpl(const System::String& templateFileName, const System::String& extension)
    : fileContent{ ReadFile(templateFileName) }, extension{ extension }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool AssistTools::GenerateTemplateImpl::IsValid() const noexcept
{
    if (!fileContent.empty())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

void AssistTools::GenerateTemplateImpl::Generate(const System::String& resourceDirectory, const System::String& newProjectName, const VariableType& newVariable) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_1;

    const System::String percent{ SYSTEM_TEXT("%"s) };

    NewDirectory(resourceDirectory);

    CoreTools::OFStreamManager manager{ resourceDirectory + forwardSlash + newProjectName + extension, false };

    auto copyFileContent = fileContent;

    for (const auto& value : newVariable)
    {
        boost::replace_all(copyFileContent, percent + value.first + percent, value.second);
    }

    manager << copyFileContent;
}

// static
// private
System::String AssistTools::GenerateTemplateImpl::ReadFile(const System::String& templateFileName)
{
    CoreTools::IFStreamManager manager{ templateFileName };

    auto fileContent = manager.GetFileContent();

    if (fileContent.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("读取的工程解决方案模板不合法。"s));
    }

    return fileContent;
}

void AssistTools::GenerateTemplateImpl::NewDirectory(const System::String& directory) const
{
    vector<System::String> splitDirectory{};

    boost::split(splitDirectory, directory, boost::is_any_of(forwardSlash));

    System::String createDiectory{};
    for (const auto& value : splitDirectory)
    {
        createDiectory += value;

        MAYBE_UNUSED const auto result = System::CreateFileDirectory(createDiectory, nullptr);

        createDiectory += forwardSlash;
    }
}

System::String AssistTools::GenerateTemplateImpl::GetTesting()
{
    return SYSTEM_TEXT("Testing"s);
}
