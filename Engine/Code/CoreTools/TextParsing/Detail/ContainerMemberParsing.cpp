///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/09 09:39)

#include "CoreTools/CoreToolsExport.h"

#include "ContainerMemberParsing.h"
#include "DefaultContainerMemberParsing.h"
#include "MapContainerMemberParsing.h"
#include "UniqueContainerMemberParsing.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::ContainerMemberParsing::ContainerMemberParsingSharedPtr CoreTools::ContainerMemberParsing::Create(const CSVHead& csvHead)
{
    switch (const CSVFormatType csvFormatType = csvHead.GetCSVFormatType(); csvFormatType)
    {
        case CSVFormatType::TreeMap:
            FALLTHROUGH;
        case CSVFormatType::HashMap:
        {
            return std::make_unique<MapContainerMemberParsing>(csvHead);
        }
        case CSVFormatType::Unique:
        {
            return std::make_unique<UniqueContainerMemberParsing>(csvHead);
        }
        default:
        {
            return std::make_unique<DefaultContainerMemberParsing>(csvHead);
        }
    }
}

CoreTools::ContainerMemberParsing::ContainerMemberParsing(CSVHead csvHead) noexcept
    : ParentType{ 1 }, head{ std::move(csvHead) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ContainerMemberParsing)

CoreTools::CSVHead CoreTools::ContainerMemberParsing::GetCSVHead() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return head;
}

System::String CoreTools::ContainerMemberParsing::GetCSVClassName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return head.GetCSVClassName();
}
