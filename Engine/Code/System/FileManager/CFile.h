// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.0 (2020/01/02 14:53)

#ifndef SYSTEM_FILE_MANAGE_C_FILE_H
#define SYSTEM_FILE_MANAGE_C_FILE_H

#include "System/SystemDll.h"

#include "Fwd/FileFlagsFwd.h"
#include "Using/CFileUsing.h" 

#include <fstream>

namespace System
{
	// 通过FILE类型的文件操作

	bool SYSTEM_DEFAULT_DECLARE OpenCFile(FILE*& file, const CFileString& fileName, const CFileString& mode) noexcept;
	bool SYSTEM_DEFAULT_DECLARE CloseCFile(FILE* file) noexcept;

	size_t SYSTEM_DEFAULT_DECLARE ReadCFile(void* buffer, size_t size, size_t count, FILE* stream) noexcept;
	size_t SYSTEM_DEFAULT_DECLARE WriteCFile(const void* buffer, size_t size, size_t count, FILE* stream) noexcept;

	bool SYSTEM_DEFAULT_DECLARE GetFileLength(const CFileString& fileName, OffType* length) noexcept;

	bool SYSTEM_DEFAULT_DECLARE SetvBuf(FILE* file, FileSetvBuf type, size_t size) noexcept;

	int SYSTEM_DEFAULT_DECLARE GetCharacter(FILE* file) noexcept;
	bool SYSTEM_DEFAULT_DECLARE UnGetCharacter(FILE* file, int character) noexcept;
	bool SYSTEM_DEFAULT_DECLARE PutCharacter(FILE* file, int character) noexcept;
	bool SYSTEM_DEFAULT_DECLARE PutString(FILE* file, const char* str) noexcept;

	bool SYSTEM_DEFAULT_DECLARE IsEOF(FILE* file) noexcept;
	bool SYSTEM_DEFAULT_DECLARE Flush(FILE* file) noexcept;
	bool SYSTEM_DEFAULT_DECLARE Seek(FILE* file, long offset, FileSeek whence) noexcept;
	PosType SYSTEM_DEFAULT_DECLARE GetPosition(FILE* file) noexcept;
	bool SYSTEM_DEFAULT_DECLARE SetPosition(FILE* file, PosType position) noexcept;
	long SYSTEM_DEFAULT_DECLARE Tell(FILE* file) noexcept;
	void SYSTEM_DEFAULT_DECLARE Rewind(FILE* file) noexcept;

	std::string SYSTEM_DEFAULT_DECLARE GetString(FILE* file, int count);
}

#endif // SYSTEM_FILE_MANAGE_C_FILE_H