/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 14:50)

#include "Framework/FrameworkExport.h"

#include "GenerateProjectName.h"
#include "ProjectNameImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"

#include <iomanip>
#include <sstream>

using namespace std::literals;

Framework::ProjectNameImpl::ProjectNameImpl(const String& fileName, const EnvironmentDirectory& environmentDirectory)
    : container{ GenerateProjectName::GenerateProjectNameContainer(fileName, environmentDirectory) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, ProjectNameImpl)

System::String Framework::ProjectNameImpl::GetSelectDescribe() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    auto index = 1;
    auto result = SYSTEM_TEXT("请选择要执行的工程：\n"s);

    for (const auto& element : container)
    {
        result += GetSelectDescribe(element, index);

        ++index;
    }

    return result;
}

System::String Framework::ProjectNameImpl::GetSelectDescribe(const String& element, int index) const
{
    const auto width = GetContainerPrintWidth();

    System::StringStream ss{};

    ss << std::setw(width) << std::setfill(SYSTEM_TEXT('0')) << index << SYSTEM_TEXT("：") << element << SYSTEM_TEXT('\n');

    return ss.str();
}

bool Framework::ProjectNameImpl::IsSelectValid(int select) const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return 0 <= select && select < boost::numeric_cast<int>(container.size());
}

System::String Framework::ProjectNameImpl::GetEngineeringName(int select) const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return container.at(select);
}

int Framework::ProjectNameImpl::GetContainerPrintWidth() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    const auto size = boost::numeric_cast<int>(container.size());

    return Mathematics::MathD::GetNumberDigits(size);
}
