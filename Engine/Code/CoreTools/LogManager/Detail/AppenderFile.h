///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/21 09:44)

#ifndef CORE_TOOLS_LOG_MANAGER_APPENDER_FILE_H
#define CORE_TOOLS_LOG_MANAGER_APPENDER_FILE_H

#include "CoreTools/CoreToolsDll.h"

#include "AppenderImpl.h"
#include "CoreTools/FileManager/FileManagerFwd.h"

#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE AppenderFile final : public AppenderImpl
    {
    public:
        using ClassType = AppenderFile;
        using ParentType = AppenderImpl;

    public:
        AppenderFile(const String& directory,
                     const String& fileName,
                     AppenderPrint appenderFlags,
                     LogLevel logLevel,
                     int maxFileSize,
                     bool backup,
                     String extensionName);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD AppenderType GetAppenderType() const noexcept override;

        NODISCARD const AppenderImplSharedPtr Clone() const override;

        NODISCARD String GetDirectory() const override;
        NODISCARD String GetExtensionName() const override;
        NODISCARD int GetMaxFileSize() const noexcept override;
        NODISCARD bool IsBackup() const noexcept override;

    private:
        using OStreamManagerPtr = std::shared_ptr<OFStreamManager>;

    private:
        NODISCARD bool IsExceedMaxSize(const OFStreamManager& stream, PosType increaseSize) const;
        void BackupFile(const String& fullName) const;

        void DoWrite(const LogMessage& message, const LogMessagePrefix& prefix, const LogMessagePostfix& postfix) const override;

        NODISCARD static String GetPrefixName(const String& directory, const String& fileName);
        NODISCARD static String GetFullName(const String& prefixName, const String& extensionName);
        static void NewDirectory(const String& directory) noexcept;

        void Init(const String& newDirectory);

    private:
        String directory;
        String prefixName;
        String extensionName;
        int maxFileSize;
        bool backup;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_APPENDER_FILE_H
