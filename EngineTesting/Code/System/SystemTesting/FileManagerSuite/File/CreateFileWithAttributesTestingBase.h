///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/15 18:17)

#ifndef SYSTEM_FILE_MANAGER_SUITE_CREATE_FILE_WITH_ATTRIBUTES_TESTING_BASE_H
#define SYSTEM_FILE_MANAGER_SUITE_CREATE_FILE_WITH_ATTRIBUTES_TESTING_BASE_H

#include "System/SystemTesting/FileManagerSuite/FileTestingBase.h"
#include "System/FileManager/Fwd/FileFlagsFwd.h"

#include <random>
#include <vector>

namespace System
{
    class CreateFileWithAttributesTestingBase : public FileTestingBase
    {
    public:
        using ClassType = CreateFileWithAttributesTestingBase;
        using ParentType = FileTestingBase;

    public:
        explicit CreateFileWithAttributesTestingBase(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        void RandomFileHandleFlags();
        NODISCARD FileHandleDesiredAccess GetFileHandleDesiredAccess(size_t index) const;
        NODISCARD FileHandleDesiredAccess GetFileHandleDesiredAccess(size_t index, FileHandleCreationDisposition fileHandleCreationDisposition) const;
        NODISCARD FileHandleShareMode GetFileHandleShareMode(size_t index) const;
        NODISCARD FileHandleCreationDisposition GetFileHandleCreationDisposition(size_t index) const;
        NODISCARD FileHandleAttributes GetFileHandleAttributes(size_t index) const;
        NODISCARD FileHandleOther GetFileHandleOther(size_t index) const;
        NODISCARD FileHandleSecurity GetFileHandleSecurity(size_t index) const;
        NODISCARD size_t GetMaxSize() const noexcept;
        NODISCARD String GetCreateFileName(size_t index) const;

    private:
        using FileHandleDesiredAccessContainer = std::vector<FileHandleDesiredAccess>;
        using FileHandleShareModeContainer = std::vector<FileHandleShareMode>;
        using FileHandleCreationDispositionContainer = std::vector<FileHandleCreationDisposition>;
        using FileHandleAttributesContainer = std::vector<FileHandleAttributes>;
        using FileHandleOtherContainer = std::vector<FileHandleOther>;
        using FileHandleSecurityContainer = std::vector<FileHandleSecurity>;

    private:
        FileHandleDesiredAccessContainer fileHandleDesiredAccesses;
        FileHandleShareModeContainer fileHandleShareModes;
        FileHandleCreationDispositionContainer fileHandleCreationDispositions;
        FileHandleAttributesContainer fileHandleAttributeses;
        FileHandleOtherContainer fileHandleOthers;
        FileHandleSecurityContainer fileHandleSecurities;
        std::default_random_engine randomEngine;
        size_t maxSize;
        String extendName;
        String fileNamePrefix;
    };
}

#endif  // SYSTEM_FILE_MANAGER_SUITE_CREATE_FILE_WITH_ATTRIBUTES_TESTING_BASE_H