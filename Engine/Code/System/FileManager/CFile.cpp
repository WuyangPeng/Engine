/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 09:27)

#include "System/SystemExport.h"

#include "CFile.h"
#include "System/Helper/EnumCast.h"

#ifdef SYSTEM_PLATFORM_WIN32

    #include <tchar.h>

#endif  // SYSTEM_PLATFORM_WIN32

#include <vector>

bool System::OpenCFile(FILE*& file, const CFileString& fileName, const CFileString& mode) noexcept
{
#if defined(TCRE_USE_GCC)

    file = ::fopen(fileName.c_str(), mode.c_str());

    return file != nullptr;

#else  // !TCRE_USE_GCC

    return ::_tfopen_s(&file, fileName.c_str(), mode.c_str()) == 0;

#endif  // TCRE_USE_GCC
}

bool System::CloseCFile(FILE* file) noexcept
{
    return ::fclose(file) == 0;
}

size_t System::ReadCFile(void* buffer, size_t size, size_t count, FILE* stream) noexcept
{
    return fread(buffer, size, count, stream);
}

size_t System::WriteCFile(const void* buffer, size_t size, size_t count, FILE* stream) noexcept
{
    return fwrite(buffer, size, count, stream);
}

bool System::GetFileLength(const CFileString& fileName, OffType* length) noexcept
{
    struct STAT_STRUCT statistics
    {
    };

    if (::STAT_FUNCTION(fileName.c_str(), &statistics) == 0)
    {
        if (length != nullptr)
        {
            *length = statistics.st_size;
        }
        return true;
    }
    else
    {
        if (length != nullptr)
        {
            *length = 0;
        }
        return false;
    }
}

bool System::SetVBuffer(FILE* file, FileSetVBuffer type, size_t size) noexcept
{
    return ::setvbuf(file, nullptr, EnumCastUnderlying(type), size) == 0;
}

int System::GetCharacter(FILE* file) noexcept
{
    return ::getc(file);
}

bool System::UnGetCharacter(FILE* file, int character) noexcept
{
    return ::ungetc(character, file) == character;
}

bool System::PutCharacter(FILE* file, int character) noexcept
{
    return ::putc(character, file) == character;
}

bool System::PutString(FILE* file, const char* str) noexcept
{
    return ::fputs(str, file) != gCFileError;
}

std::string System::GetString(FILE* file, int count)
{
    CharContainer result(count);

    if (::fgets(result.data(), count, file) != nullptr)
    {
        return std::string{ result.data() };
    }
    else
    {
        return std::string{};
    }
}

bool System::IsEof(FILE* file) noexcept
{
    return ::feof(file) != 0;
}

bool System::Flush(FILE* file) noexcept
{
    return ::fflush(file) == 0;
}

bool System::Seek(FILE* file, long offset, FileSeek whence) noexcept
{
    return ::fseek(file, offset, EnumCastUnderlying(whence)) == 0;
}

System::PosType System::GetPosition(FILE* file) noexcept
{
    PosType position{ -1 };

    if (::fgetpos(file, &position) == 0)
    {
        return position;
    }
    else
    {
        return PosType{ -1 };
    }
}

bool System::SetPosition(FILE* file, PosType position) noexcept
{
    return ::fsetpos(file, &position) == 0;
}

long System::Tell(FILE* file) noexcept
{
    return ::ftell(file);
}