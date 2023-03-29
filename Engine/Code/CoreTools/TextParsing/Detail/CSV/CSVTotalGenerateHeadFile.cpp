///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/09 18:09)

#include "CoreTools/CoreToolsExport.h"

#include "CSVTotalGenerateHeadFile.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::CSVTotalGenerateHeadFile::CSVTotalGenerateHeadFile(const String& nameSpace, const CSVHeadContainer& csvHeadContainer)
    : ParentType{ nameSpace, csvHeadContainer }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CSVTotalGenerateHeadFile)

System::String CoreTools::CSVTotalGenerateHeadFile::GetFileSuffix() const
{
    return TextParsing::gHeadFileExtensionName.data();
}

System::String CoreTools::CSVTotalGenerateHeadFile::GetContent() const
{
    auto content = GenerateCopyright();

    content += GenerateNewLine();
    content += GenerateHeaderGuard();

    content += GenerateHead();

    content += GenerateHeaderGuardEndif();

    return content;
}
