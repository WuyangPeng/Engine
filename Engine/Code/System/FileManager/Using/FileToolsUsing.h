///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/28 17:13)

#ifndef SYSTEM_FILE_MANAGER_FILE_TOOLS_USING_H
#define SYSTEM_FILE_MANAGER_FILE_TOOLS_USING_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using GetFileExInfoLevels = GET_FILEEX_INFO_LEVELS;
    using ByHandleFileInformation = BY_HANDLE_FILE_INFORMATION;
    using ByHandleFileInformationPtr = LPBY_HANDLE_FILE_INFORMATION;
    using FileSegmentElement = FILE_SEGMENT_ELEMENT;
    using FileSegmentElementPtr = PFILE_SEGMENT_ELEMENT;
    using FileInfoByHandleClass = FILE_INFO_BY_HANDLE_CLASS;
    using FileInfoByHandleClassPtr = PFILE_INFO_BY_HANDLE_CLASS;
    using FilePriorityHint = PRIORITY_HINT;

    using FileAttributeData = WIN32_FILE_ATTRIBUTE_DATA;
    using FileAttributeDataPtr = LPWIN32_FILE_ATTRIBUTE_DATA;
    using FileBasicInfoType = FILE_BASIC_INFO;
    using FileBasicInfoTypePtr = PFILE_BASIC_INFO;
    using FileRenameInfoType = FILE_RENAME_INFO;
    using FileRenameInfoTypePtr = PFILE_RENAME_INFO;
    using FileDispositionInfoType = FILE_DISPOSITION_INFO;
    using FileDispositionInfoTypePtr = PFILE_DISPOSITION_INFO;
    using FileAllocationInfoType = FILE_ALLOCATION_INFO;
    using FileAllocationInfoTypePtr = PFILE_ALLOCATION_INFO;
    using FileEndOfFileInfoType = FILE_END_OF_FILE_INFO;
    using FileEndOfFileInfoTypePtr = PFILE_END_OF_FILE_INFO;
    using FileIoPriorityHintInfoType = FILE_IO_PRIORITY_HINT_INFO;
    using FileIoPriorityHintInfoTypePtr = PFILE_IO_PRIORITY_HINT_INFO;

#else  // !SYSTEM_PLATFORM_WIN32

    enum GetFileExInfoLevels
    {
        GetFileExInfoStandard,
        GetFileExMaxInfoLevel
    };

    struct ByHandleFileInformation
    {
        uint32_t dwFileAttributes;
        FileTime ftCreationTime;
        FileTime ftLastAccessTime;
        FileTime ftLastWriteTime;
        uint32_t dwVolumeSerialNumber;
        uint32_t nFileSizeHigh;
        uint32_t nFileSizeLow;
        uint32_t nNumberOfLinks;
        uint32_t nFileIndexHigh;
        uint32_t nFileIndexLow;
    };
    using ByHandleFileInformationPtr = ByHandleFileInformation*;

    union FileSegmentElement
    {
        void* Buffer;
        uint64_t Alignment;
    };
    using FileSegmentElementPtr = FileSegmentElement*;

    enum FileInfoByHandleClass
    {
        FileBasicInfo,
        FileStandardInfo,
        FileNameInfo,
        FileRenameInfo,
        FileDispositionInfo,
        FileAllocationInfo,
        FileEndOfFileInfo,
        FileStreamInfo,
        FileCompressionInfo,
        FileAttributeTagInfo,
        FileIdBothDirectoryInfo,
        FileIdBothDirectoryRestartInfo,
        FileIoPriorityHintInfo,
        FileRemoteProtocolInfo,
        FileFullDirectoryInfo,
        FileFullDirectoryRestartInfo,
        MaximumFileInfoByHandleClass
    };
    using FileInfoByHandleClassPtr = FileInfoByHandleClass*;

    struct FileAttributeData
    {
        uint32_t dwFileAttributes;
        FileTime ftCreationTime;
        FileTime ftLastAccessTime;
        FileTime ftLastWriteTime;
        uint32_t nFileSizeHigh;
        uint32_t nFileSizeLow;
    };
    using FileAttributeDataPtr = FileAttributeData*;

    struct FileBasicInfoType
    {
        WindowsLargeInteger CreationTime;
        WindowsLargeInteger LastAccessTime;
        WindowsLargeInteger LastWriteTime;
        WindowsLargeInteger ChangeTime;
        uint32_t FileAttributes;
    };
    using FileBasicInfoTypePtr = FileBasicInfoType*;

    struct FileRenameInfoType
    {
        int ReplaceIfExists;
        WindowsHandle RootDirectory;
        uint32_t FileNameLength;
        SYSTEM_TEXT FileName[1];
    };
    using FileRenameInfoTypePtr = FileRenameInfoType*;

    struct FileDispositionInfoType
    {
        int DeleteFile;
    };
    using FileDispositionInfoTypePtr = FileDispositionInfoType*;

    struct FileAllocationInfoType
    {
        WindowsLargeInteger AllocationSize;
    };
    using FileAllocationInfoTypePtr = FileAllocationInfoType*;

    struct FileEndOfFileInfoType
    {
        WindowsLargeInteger EndOfFile;
    };
    using FileEndOfFileInfoTypePtr = FileEndOfFileInfoType*;

    enum FilePriorityHint
    {
        IoPriorityHintVeryLow = 0,
        IoPriorityHintLow,
        IoPriorityHintNormal,
        MaximumIoPriorityHintType
    };

    struct FileIoPriorityHintInfoType
    {
        FilePriorityHint PriorityHint;
    };
    using FileIoPriorityHintInfoTypePtr = FileIoPriorityHintInfoType*;

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_FILE_MANAGER_FILE_TOOLS_USING_H