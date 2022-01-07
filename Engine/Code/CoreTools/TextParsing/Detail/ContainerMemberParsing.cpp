///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 21:56)

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
    const CSVFormatType csvFormatType = csvHead.GetCSVFormatType();

    switch (csvFormatType)
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

CoreTools::ContainerMemberParsing::ContainerMemberParsing(const CSVHead& csvHead) noexcept
    : ParentType{ 1 }, m_CSVHead{ csvHead }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ContainerMemberParsing)

CoreTools::CSVHead CoreTools::ContainerMemberParsing::GetCSVHead() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_CSVHead;
}

System::String CoreTools::ContainerMemberParsing::GetCSVClassName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_CSVHead.GetCSVClassName();
}
