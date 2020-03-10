// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 14:55)

#include "System/SystemExport.h"

#include "CFile.h" 
#include "System/EnumOperator/EnumCastDetail.h"

#ifdef SYSTEM_PLATFORM_WIN32
	#include <tchar.h>
#endif // SYSTEM_PLATFORM_WIN32

#include <vector> 

using std::string;
using std::vector;
using namespace std::literals;

bool System
	::OpenCFile(FILE*& file, const CFileString& fileName, const CFileString& mode) noexcept
{
#if defined(TCRE_USE_GCC)
	m_File = ::fopen(fileName.c_str(), mode.c_str());
	if (m_File != nullptr)
		return true;
	else
		return false;
#else // !TCRE_USE_GCC
	if (::_tfopen_s(&file, fileName.c_str(), mode.c_str()) == 0)
		return true;
	else
		return false;
#endif // TCRE_USE_GCC
}

bool System
	::CloseCFile(FILE* file) noexcept
{
	if (::fclose(file) == 0)
		return true;
	else
		return false;
}

size_t System
	::ReadCFile(void* buffer, size_t size, size_t count, FILE* stream) noexcept
{
	return fread(buffer, size, count, stream);
}

size_t System
	::WriteCFile(const void* buffer, size_t size, size_t count, FILE* stream) noexcept
{
	return fwrite(buffer, size, count, stream);
}

bool System
	::GetFileLength(const CFileString& fileName, OffType* length) noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX)

	struct stat statistics {};
	if (stat(fileName.c_str(), &statistics) == 0)
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

#else // !SYSTEM_PLATFORM_LINUX

	struct _stat statistics {};
	if (::_tstat(fileName.c_str(), &statistics) == 0)
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

#endif // SYSTEM_PLATFORM_LINUX
}

bool System
	::SetvBuf(FILE* file, FileSetvBuf type, size_t size) noexcept
{
	if (::setvbuf(file, nullptr, EnumCastUnderlying(type), size) == 0)
		return true;
	else
		return false;
}

int System
	::GetCharacter(FILE* file) noexcept
{
	return ::getc(file);
}

bool System
	::UnGetCharacter(FILE* file, int character) noexcept
{
	if (::ungetc(character, file) == character)
		return true;
	else
		return false;
}

bool System
	::PutCharacter(FILE* file, int character) noexcept
{
	if (::putc(character, file) == character)
		return true;
	else
		return false;
}

bool System
	::PutString(FILE* file, const char* str) noexcept
{
	if (::fputs(str, file) != g_CFileError)
		return true;
	else
		return false;
}

string System
	::GetString(FILE* file, int count)
{
	vector<char> str(count);

	if (::fgets(str.data(), count, file) != nullptr)
	{
		return string{ str.data() };
	}
	else
	{
		return ""s;
	}
}

bool System
	::IsEOF(FILE* file) noexcept
{
	if (::feof(file) != 0)
		return true;
	else
		return false;
}

bool System
	::Flush(FILE* file) noexcept
{
	if (::fflush(file) == 0)
		return true;
	else
		return false;
}

bool System
	::Seek(FILE* file, long offset, FileSeek whence) noexcept
{
	if (::fseek(file, offset, EnumCastUnderlying(whence)) == 0)
		return true;
	else
		return false;
}

System::PosType System
	::GetPosition(FILE* file) noexcept
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

bool System
	::SetPosition(FILE* file, PosType position) noexcept
{
	if (::fsetpos(file, &position) == 0)
		return true;
	else
		return false;
}

long System
	::Tell(FILE* file) noexcept
{
	return ::ftell(file);
}

void System
	::Rewind(FILE* file) noexcept
{
	::rewind(file);
}
