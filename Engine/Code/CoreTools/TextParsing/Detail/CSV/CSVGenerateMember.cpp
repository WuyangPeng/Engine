///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 20:19)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateMember.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Detail/BaseMemberParsing.h"
#include "CoreTools/TextParsing/Detail/ChildMemberParsing.h"
#include "CoreTools/TextParsing/Detail/ContainerMemberParsing.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::CSVGenerateMember::CSVGenerateMember(const CSVHead& csvHead, const String& suffix)
    : csvHead{ csvHead }, suffix{ suffix }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CSVGenerateMember)

System::String CoreTools::CSVGenerateMember::GenerateBaseMember() const
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