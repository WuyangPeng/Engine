///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.5 (2021/10/22 11:39)

#include "CoreTools/CoreToolsExport.h"

#include "CSVTotalGenerateFwdHeadFile.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using namespace std::literals;

CoreTools::CSVTotalGenerateFwdHeadFile::CSVTotalGenerateFwdHeadFile(const String& nameSpace, const CSVHeadContainer& csvHeadContainer)
    : ParentType{ nameSpace, csvHeadContainer }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CSVTotalGenerateFwdHeadFile)

System::String CoreTools::CSVTotalGenerateFwdHeadFile::GetFileSuffix() const
{
    return SYSTEM_TEXT("Fwd.h"s);
}

System::String CoreTools::CSVTotalGenerateFwdHeadFile::GetContent() const
{
    auto content = GenerateCopyright();

    content += GenerateNewLine();
    content += GenerateHeaderGuard();

    content += GenerateFwdHead();
    content += GenerateNameSpace();
    content += GenerateFwd();

    content += GenerateHeaderGuardEndif();

    return content;
}
