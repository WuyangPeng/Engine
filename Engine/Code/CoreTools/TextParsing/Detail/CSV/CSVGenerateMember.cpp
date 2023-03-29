///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/09 17:45)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateMember.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Detail/BaseMemberParsing.h"
#include "CoreTools/TextParsing/Detail/ChildMemberParsing.h"
#include "CoreTools/TextParsing/Detail/ContainerMemberParsing.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::CSVGenerateMember::CSVGenerateMember(CSVHead csvHead, String suffix) noexcept
    : csvHead{ std::move(csvHead) }, suffix{ std::move(suffix) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CSVGenerateMember)

System::String CoreTools::CSVGenerateMember::GenerateBaseMember()
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const BaseMemberParsing baseMemberParsing{};

    return baseMemberParsing.GenerateBaseMember();
}

System::String CoreTools::CSVGenerateMember::GenerateChildMember() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const ChildMemberParsing childMemberParsing{ csvHead };

    return childMemberParsing.GenerateChildMember();
}

System::String CoreTools::CSVGenerateMember::GenerateContainerMember() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto containerMemberParsing = ContainerMemberParsing::Create(csvHead);

    return containerMemberParsing->GenerateMember();
}