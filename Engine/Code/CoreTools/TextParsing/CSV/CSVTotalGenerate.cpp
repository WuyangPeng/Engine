///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/26 13:56)

#include "CoreTools/CoreToolsExport.h"

#include "CSVTotalGenerate.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/TextParsing/Detail/CSV/CSVTotalGenerateFactory.h"
#include "CoreTools/TextParsing/Detail/CSV/CSVTotalGenerateImpl.h"

CoreTools::CSVTotalGenerate::CSVTotalGenerate(const String& nameSpace, const CSVHeadContainer& csvHeadContainer, const CodeMappingAnalysis& codeMappingAnalysis, CSVTotalGenerateType csvTotalGenerateType)
    : impl{ ImplCreateUseFactory::Default, nameSpace, csvHeadContainer, codeMappingAnalysis, csvTotalGenerateType }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CSVTotalGenerate)

void CoreTools::CSVTotalGenerate::GenerateFile(const String& codeDirectory, const String& directory) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GenerateFile(codeDirectory, directory);
}
