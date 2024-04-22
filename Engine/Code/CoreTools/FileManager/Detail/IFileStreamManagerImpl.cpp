/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/01 10:39)

#include "CoreTools/CoreToolsExport.h"

#include "IFileStreamManagerImpl.h"
#include "IFileStreamSeekManager.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Helper/PragmaWarning/Format.h"
#include "System/Helper/PragmaWarning/PosixTime.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <fstream>
#include <sstream>

using namespace std::literals;

CoreTools::IFileStreamManagerImpl::IFileStreamManagerImpl(const String& fileName)
    : iStream{ fileName }, fileName{ fileName }
{
    ASSERT_FAIL_THROW_EXCEPTION(iStream, SYSTEM_TEXT("打开文件"s) + fileName + SYSTEM_TEXT("失败！"s))

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::IFileStreamManagerImpl::IsValid() const noexcept
{
    try
    {
        return !fileName.empty() && iStream;
    }
    catch (...)
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

System::String CoreTools::IFileStreamManagerImpl::BackupFile() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    auto backupName = GetBackupName();
    System::OFileStream os{ backupName, System::OFileStream::app };

    if (os)
    {
        CopyContentToStream(&os);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("备份文件失败！"s))
    }

    return backupName;
}

System::String CoreTools::IFileStreamManagerImpl::GetBackupName() const
{
    String newName{ fileName };

    const auto dot = SYSTEM_TEXT("."s);

    const auto nowTime = boost::posix_time::second_clock::local_time();

    boost::basic_format basicFormat{ SYSTEM_TEXT("(%1%)."s) };
    basicFormat % boost::posix_time::to_iso_string_type<System::TChar>(nowTime);

    boost::replace_last(newName, dot, basicFormat.str());

    return newName;
}

void CoreTools::IFileStreamManagerImpl::CopyContentToStream(OStream* stream) const
{
    CORE_TOOLS_ASSERTION_0(stream != nullptr, "指针无效");

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26492)

    const auto thisImpl = const_cast<IFileStreamManagerImpl*>(this);

#include SYSTEM_WARNING_POP

    IFileStreamSeekManager manager{ thisImpl->iStream };

    const auto loc = iStream.getloc();

    stream->imbue(loc);

    *stream << iStream.rdbuf();
}

System::String CoreTools::IFileStreamManagerImpl::GetFileContent() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    System::OStringStream os{};

    if (os)
    {
        CopyContentToStream(&os);

        return os.str();
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("获取文件内容失败！"s))
    }
}

void CoreTools::IFileStreamManagerImpl::SetSimplifiedChinese()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

#if !defined(TCRE_USE_GCC)

    static const std::locale chs{ "chs" };

    iStream.imbue(chs);

#endif  // !defined(TCRE_USE_GCC)
}

System::IFileStream& CoreTools::IFileStreamManagerImpl::GetFileStream() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return iStream;
}

CoreTools::IFileStreamManagerImpl::FileContent CoreTools::IFileStreamManagerImpl::GetFileContent(System::StringView separate) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    FileContent fileContent{};

    split(fileContent, GetFileContent(), boost::is_any_of(separate), boost::token_compress_on);

    return fileContent;
}
