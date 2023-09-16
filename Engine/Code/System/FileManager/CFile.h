///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/28 17:14)

#ifndef SYSTEM_FILE_MANAGER_C_FILE_H
#define SYSTEM_FILE_MANAGER_C_FILE_H

#include "System/SystemDll.h"

#include "Fwd/FileFlagsFwd.h"
#include "Using/CFileUsing.h"

// 通过FILE类型的文件操作
namespace System
{
    NODISCARD bool SYSTEM_DEFAULT_DECLARE OpenCFile(FILE*& file, const CFileString& fileName, const CFileString& mode) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE CloseCFile(FILE* file) noexcept;

    NODISCARD size_t SYSTEM_DEFAULT_DECLARE ReadCFile(void* buffer, size_t size, size_t count, FILE* stream) noexcept;
    NODISCARD size_t SYSTEM_DEFAULT_DECLARE WriteCFile(const void* buffer, size_t size, size_t count, FILE* stream) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetFileLength(const CFileString& fileName, OffType* length) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetVBuffer(FILE* file, FileSetVBuffer type, size_t size) noexcept;

    NODISCARD int SYSTEM_DEFAULT_DECLARE GetCharacter(FILE* file) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE UnGetCharacter(FILE* file, int character) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE PutCharacter(FILE* file, int character) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE PutString(FILE* file, const char* str) noexcept;

    NODISCARD std::string SYSTEM_DEFAULT_DECLARE GetString(FILE* file, int count);

    NODISCARD bool SYSTEM_DEFAULT_DECLARE IsEof(FILE* file) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE Flush(FILE* file) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE Seek(FILE* file, long offset, FileSeek whence) noexcept;
    NODISCARD PosType SYSTEM_DEFAULT_DECLARE GetPosition(FILE* file) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetPosition(FILE* file, PosType position) noexcept;
    NODISCARD long SYSTEM_DEFAULT_DECLARE Tell(FILE* file) noexcept;
    void SYSTEM_DEFAULT_DECLARE Rewind(FILE* file) noexcept;
}

#endif  // SYSTEM_FILE_MANAGER_C_FILE_H