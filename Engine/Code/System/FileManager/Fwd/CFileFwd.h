// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 14:52)

#ifndef SYSTEM_FILE_MANAGE_C_FILE_FWD_H
#define SYSTEM_FILE_MANAGE_C_FILE_FWD_H  

#include "FileFlagsFwd.h"
#include "System/FileManager/Using/CFileUsing.h"

#include <fstream>

namespace System
{
	bool OpenCFile(FILE*& file, const CFileString& fileName, const CFileString& mode) noexcept;
	bool CloseCFile(FILE* file) noexcept;

	size_t ReadCFile(void* buffer, size_t size, size_t count, FILE* stream) noexcept;
	size_t WriteCFile(const void* buffer, size_t size, size_t count, FILE* stream) noexcept;

	bool GetFileLength(const CFileString& fileName, OffType* length) noexcept;

	bool SetvBuf(FILE* file, FileSetvBuf type, size_t size) noexcept;

	int GetCharacter(FILE* file) noexcept;
	bool UnGetCharacter(FILE* file, int character) noexcept;
	bool PutCharacter(FILE* file, int character) noexcept;
	bool PutString(FILE* file, const char* str) noexcept;
	std::string GetString(FILE* file, int count);
	bool IsEOF(FILE* file) noexcept;
	bool Flush(FILE* file) noexcept;
	bool Seek(FILE* file, long offset, FileSeek whence) noexcept;
	PosType GetPosition(FILE* file) noexcept;
	bool SetPosition(FILE* file, PosType position) noexcept;
	long Tell(FILE* file) noexcept;
	void Rewind(FILE* file) noexcept;
}

#endif // SYSTEM_FILE_MANAGE_C_FILE_FWD_H