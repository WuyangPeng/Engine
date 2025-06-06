/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "OutputCSVTestingContainer.h"

#include "Input1Container.h"
#include "Input2Container.h"
#include "Input3Container.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"

using namespace std::literals;

OutputCSVTesting::OutputCSVTestingContainer::OutputCSVTestingContainer(const String& directory)
    : input1Container{},
      input2Container{},
      input3Container{}
{
    Parsing(directory);
    Verify();

    USER_SELF_CLASS_IS_VALID_1;
}

void OutputCSVTesting::OutputCSVTestingContainer::Parsing(const String& directory)
{
    for (const std::filesystem::path path{ directory };
         const auto& inputPath : std::filesystem::directory_iterator(path))
    {
        Parsing(inputPath);
    }
}

void OutputCSVTesting::OutputCSVTestingContainer::Parsing(const std::filesystem::directory_entry& inputPath)
{
    const auto fileName = CoreTools::StringConversion::FileSystemConversionStandard(inputPath.path().native());

    if (fileName.find(SYSTEM_TEXT(".csv"s)) != (fileName.size() - 4))
    {
        return;
    }

    const CoreTools::CSVContent csvContent{ fileName };

    const auto csvClassName = csvContent.GetCSVClassName();

    if (csvClassName == SYSTEM_TEXT("Input1"s))
    {
        input1Container = std::make_shared<Input1Container>(csvContent);
    }
    else if (csvClassName == SYSTEM_TEXT("Input2"s))
    {
        input2Container = std::make_shared<Input2Container>(csvContent);
    }
    else if (csvClassName == SYSTEM_TEXT("Input3"s))
    {
        input3Container = std::make_shared<Input3Container>(csvContent);
    }
}

void OutputCSVTesting::OutputCSVTestingContainer::Verify() const
{
    if (input1Container == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("input1表不存在。"s))
    }

    if (input2Container == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("input2表不存在。"s))
    }

    if (input3Container == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("input3表不存在。"s))
    }

    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("OutputCSVTesting结束载入……"));
}

#ifdef OPEN_CLASS_INVARIANT

bool OutputCSVTesting::OutputCSVTestingContainer::IsValid() const noexcept
{
    if (input1Container != nullptr &&
        input2Container != nullptr &&
        input3Container != nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

OutputCSVTesting::OutputCSVTestingContainer::ConstInput1ContainerSharedPtr OutputCSVTesting::OutputCSVTestingContainer::GetInput1Container() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return input1Container;
}

OutputCSVTesting::OutputCSVTestingContainer::ConstInput2ContainerSharedPtr OutputCSVTesting::OutputCSVTestingContainer::GetInput2Container() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return input2Container;
}

OutputCSVTesting::OutputCSVTestingContainer::ConstInput3ContainerSharedPtr OutputCSVTesting::OutputCSVTestingContainer::GetInput3Container() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return input3Container;
}

