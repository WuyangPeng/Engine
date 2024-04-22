/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/03 00:13)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerate.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Detail/CSV/CSVGenerateFactory.h"
#include "CoreTools/TextParsing/Detail/CSV/CSVGenerateImpl.h"

CoreTools::CSVGenerate::CSVGenerate(const CSVHead& csvHead, const CodeMappingAnalysis& codeMappingAnalysis, CSVGenerateType csvGenerateType)
    : impl{ ImplCreateUseFactory::Default, csvHead, codeMappingAnalysis, csvGenerateType }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::CSVGenerate::CSVGenerate(const CSVContent& csvContent, const CodeMappingAnalysis& codeMappingAnalysis, CSVGenerateType csvGenerateType)
    : impl{ ImplCreateUseFactory::Default, csvContent, codeMappingAnalysis, csvGenerateType }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CSVGenerate)

void CoreTools::CSVGenerate::GenerateFile(const String& codeDirectory, const String& directory) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GenerateFile(codeDirectory, directory);
}
