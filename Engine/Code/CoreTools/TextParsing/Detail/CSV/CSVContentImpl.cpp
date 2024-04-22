/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/03 09:27)

#include "CoreTools/CoreToolsExport.h"

#include "CSVContentImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Base/SpanIteratorDetail.h"
#include "CoreTools/FileManager/IFileStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/TextParsing/Detail/FileNameParsing.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

#include <vector>

CoreTools::CSVContentImpl::CSVContentImpl(const String& fileName)
    : fileName{ fileName }, fileContent{}
{
    Parsing();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

void CoreTools::CSVContentImpl::Parsing()
{
    const IFileStreamManager streamManager{ fileName };

    fileContent = streamManager.GetFileContent(TextParsing::gNewline);

    if (fileContent.size() < fileHeaderSize)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("csv文件头不合法。\n"s))
    }
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::CSVContentImpl::IsValid() const noexcept
{
    return fileHeaderSize <= fileContent.size();
}

#endif  // OPEN_CLASS_INVARIANT

CoreTools::CSVHead CoreTools::CSVContentImpl::GetCSVHead() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    SpanIterator spanIterator{ fileContent.cbegin(), fileContent.cend() };

    spanIterator += System::EnumCastUnderlying(CSVType::VariableName);

    const FileContent content{ spanIterator.GetBegin(), spanIterator.GetCurrent() };

    return CSVHead{ fileName, content };
}

int CoreTools::CSVContentImpl::GetCount() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(fileContent.size() - fileHeaderSize);
}

System::String CoreTools::CSVContentImpl::GetContent(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return fileContent.at(index + fileHeaderSize);
}

System::String CoreTools::CSVContentImpl::GetCSVClassName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    const FileNameParsing fileNameParsing{ fileName };

    return fileNameParsing.GetCSVClassName();
}
