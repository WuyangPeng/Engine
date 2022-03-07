///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/05 0:13)

#ifndef CORE_TOOLS_LOG_MANAGER_APPENDER_FILE_H
#define CORE_TOOLS_LOG_MANAGER_APPENDER_FILE_H

#include "CoreTools/CoreToolsDll.h"

#include "AppenderImpl.h"
#include "System/Helper/UnicodeUsing.h"
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
                     const String& extensionName);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD AppenderType GetAppenderType() const noexcept final;

        NODISCARD const AppenderImplSharedPtr Clone() const final;

        void Reload() final;

        NODISCARD String GetDirectory() const final;
        NODISCARD String GetExtensionName() const final;
        NODISCARD int GetMaxFileSize() const noexcept final;
        NODISCARD bool IsBackup() const noexcept final;

    private:
        using OStreamManagerPtr = std::shared_ptr<OFStreamManager>;

    private:
        NODISCARD bool IsExceedMaxSize(PosType increaseSize);
        void BackupFile();

        void DoWrite(const LogMessage& message, const LogMessagePrefix& prefix, const LogMessagePostfix& postfix) final;

        NODISCARD static String GetPrefixName(const String& directory, const String& fileName);
        NODISCARD static String GetFullName(const String& prefixName, const String& extensionName);
        static void NewDirectory(const String& directory) noexcept;

        void Init(const String& newDirectory);

    private:
        String directory;
        String prefixName;
        String extensionName;
        String fullName;
        int maxFileSize;
        bool backup;
        OStreamManagerPtr streamManager;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_APPENDER_FILE_H
