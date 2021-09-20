///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.3 (2021/05/18 10:08)

#ifndef SYSTEM_FILE_MANAGE_C_FILE_H
#define SYSTEM_FILE_MANAGE_C_FILE_H

#include "System/SystemDll.h"

#include "Fwd/FileFlagsFwd.h"
#include "Using/CFileUsing.h"

#include <fstream>

namespace System
{
    // 通过FILE类型的文件操作

    NODISCARD bool SYSTEM_DEFAULT_DECLARE OpenCFile(FILE*& file, const CFileString& fileName, const CFileString& mode) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE CloseCFile(FILE* file) noexcept;

    NODISCARD size_t SYSTEM_DEFAULT_DECLARE ReadCFile(void* buffer, size_t size, size_t count, FILE* stream) noexcept;
    NODISCARD size_t SYSTEM_DEFAULT_DECLARE WriteCFile(const void* buffer, size_t size, size_t count, FILE* stream) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetFileLength(const CFileString& fileName, OffType* length) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetvBuf(FILE* file, FileSetvBuf type, size_t size) noexcept;

    NODISCARD int SYSTEM_DEFAULT_DECLARE GetCharacter(FILE* file) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE UnGetCharacter(FILE* file, int character) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE PutCharacter(FILE* file, int character) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE PutString(FILE* file, const char* str) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE IsEOF(FILE* file) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE Flush(FILE* file) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE Seek(FILE* file, long offset, FileSeek whence) noexcept;
    NODISCARD PosType SYSTEM_DEFAULT_DECLARE GetPosition(FILE* file) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetPosition(FILE* file, PosType position) noexcept;
    NODISCARD long SYSTEM_DEFAULT_DECLARE Tell(FILE* file) noexcept;
    void SYSTEM_DEFAULT_DECLARE Rewind(FILE* file) noexcept;

    NODISCARD std::string SYSTEM_DEFAULT_DECLARE GetString(FILE* file, int count);
}

#endif  // SYSTEM_FILE_MANAGE_C_FILE_H