/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/01 10:48)

#include "CoreTools/CoreToolsExport.h"

#include "CFileManagerHelper.h"
#include "Environment.h"
#include "Detail/CFileManagerImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <fstream>
#include <sstream>

using namespace std::literals;

CoreTools::FileBuffer CoreTools::CFileManagerHelper::LoadFromFile(const String& fileName, bool binaryFile)
{
    const auto mode = binaryFile ? SYSTEM_TEXT("rb"s) : SYSTEM_TEXT("rt"s);

    CFileManagerImpl manager{ fileName, mode };

    const auto bufferSize = boost::numeric_cast<int>(manager.GetFileLength());
    FileBuffer buffer{ bufferSize };

    if (const auto result = manager.ReadFromFile(sizeof(char), buffer.GetSize(), buffer.GetBufferBegin());
        bufferSize != boost::numeric_cast<int>(result))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("读取的文件大小不一致！"s))
    }

    return buffer;
}

std::string CoreTools::CFileManagerHelper::LoadFromFile(const std::string& fileName)
{
    if (const std::ifstream file{ fileName }; file)
    {
        std::stringstream ss{};

        ss << file.rdbuf();

        return ss.str();
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("文件不存在。"s))
    }
}

void CoreTools::CFileManagerHelper::SaveIntoFile(const String& fileName, bool binaryFile, int bufferSize, const char* buffer)
{
    /// 输入缓冲区必须存在。验证该缓冲区具有指定的字节数是不可能的。
    CORE_TOOLS_ASSERTION_0(buffer != nullptr, "传入的指针为空！");
    CORE_TOOLS_ASSERTION_2(0 < bufferSize, "传入的缓冲区大小小于或等于零！");

    const auto mode = binaryFile ? SYSTEM_TEXT("wb"s) : SYSTEM_TEXT("wt"s);

    CFileManagerImpl manager{ fileName, mode };

    if (const auto result = manager.WriteToFile(sizeof(char), bufferSize, buffer);
        bufferSize != boost::numeric_cast<int>(result))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("写入的文件大小不一致！"s))
    }
}

void CoreTools::CFileManagerHelper::AppendToFile(const String& fileName, bool binaryFile, int bufferSize, const char* buffer)
{
    /// 输入缓冲区必须存在。验证该缓冲区具有指定的字节数是不可能的。
    CORE_TOOLS_ASSERTION_0(buffer != nullptr, "传入的指针为空！");
    CORE_TOOLS_ASSERTION_2(0 < bufferSize, "传入的缓冲区大小小于或等于零！");

    const auto mode = binaryFile ? SYSTEM_TEXT("ab"s) : SYSTEM_TEXT("at"s);

    CFileManagerImpl manager{ fileName, mode };

    if (const auto result = manager.WriteToFile(sizeof(char), bufferSize, buffer);
        bufferSize != boost::numeric_cast<int>(result))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("写入的文件大小不一致！"s))
    }
}

CoreTools::FileBuffer CoreTools::CFileManagerHelper::LoadFromFileUseEnvironment(const Environment& environment, const String& fileName, bool binaryFile)
{
    const auto fullFileName = environment.GetPathReading(fileName);

    return LoadFromFile(fullFileName, binaryFile);
}
