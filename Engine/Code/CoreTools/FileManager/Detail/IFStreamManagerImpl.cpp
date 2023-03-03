///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.3 (2023/03/02 10:45)

#include "CoreTools/CoreToolsExport.h"

#include "IFStreamManagerImpl.h"
#include "IFStreamSeekManager.h"
#include "System/Helper/PragmaWarning/Format.h"
#include "System/Helper/PragmaWarning/PosixTime.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <sstream>

using namespace std::literals;

CoreTools::IFStreamManagerImpl::IFStreamManagerImpl(const String& fileName)
    : iStream{ fileName }, fileName{ fileName }
{
    if (!iStream)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("���ļ�"s) + fileName + SYSTEM_TEXT("ʧ�ܣ�"s));
    }

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::IFStreamManagerImpl::IsValid() const noexcept
{
    try
    {
        if (!fileName.empty() && iStream)
            return true;
        else
            return false;
    }
    catch (...)
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

System::String CoreTools::IFStreamManagerImpl::BackupFile() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    auto newName = GetBackupName();
    System::OFileStream os{ newName, System::OFileStream::app };

    if (os)
    {
        CopyContentToStream(&os);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�����ļ�ʧ�ܣ�"s))
    }

    return newName;
}

System::String CoreTools::IFStreamManagerImpl::GetBackupName() const
{
    String newName{ fileName };

    const auto dot = SYSTEM_TEXT("."s);

    const auto nowTime = boost::posix_time::second_clock::local_time();

    boost::basic_format<System::TChar> basicFormat{ SYSTEM_TEXT("(%1%)."s) };
    basicFormat % boost::posix_time::to_iso_string_type<System::TChar>(nowTime);

    boost::replace_last(newName, dot, basicFormat.str());

    return newName;
}

void CoreTools::IFStreamManagerImpl::CopyContentToStream(OStream* stream) const
{
    CORE_TOOLS_ASSERTION_0(stream != nullptr, "ָ����Ч");

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26492)

    const auto thisImpl = const_cast<IFStreamManagerImpl*>(this);

#include STSTEM_WARNING_POP

    IFStreamSeekManager manager{ thisImpl->iStream };

    const auto loc = iStream.getloc();

    stream->imbue(loc);

    *stream << iStream.rdbuf();
}

System::String CoreTools::IFStreamManagerImpl::GetFileContent() const
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
        THROW_EXCEPTION(SYSTEM_TEXT("��ȡ�ļ�����ʧ�ܣ�"s));
    }
}

void CoreTools::IFStreamManagerImpl::SetSimplifiedChinese()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

#if !defined(TCRE_USE_GCC)

    const std::locale chs{ "chs" };

    iStream.imbue(chs);

#endif  // !defined(TCRE_USE_GCC)
}
