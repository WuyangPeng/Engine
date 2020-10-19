//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/15 9:51)

// 输出位置子类：文件类
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
        AppenderFile(const String& directory, const String& fileName, AppenderPrint appenderFlags, LogLevel logLevel,
                     int maxFileSize, bool backup, const String& extensionName);

        CLASS_INVARIANT_FINAL_DECLARE;

        [[nodiscard]] AppenderType GetAppenderType() const noexcept final;

        [[nodiscard]] const AppenderImplPtr Clone() const final;

        void Reload() final;

        [[nodiscard]] String GetDirectory() const final;
        [[nodiscard]] String GetExtensionName() const final;
        [[nodiscard]] int GetMaxFileSize() const noexcept final;
        [[nodiscard]] bool IsBackup() const noexcept final;

    private:
        [[nodiscard]] bool IsExceedMaxSize(PosType increaseSize);
        void BackupFile();

        void DoWrite(const LogMessage& message, const LogMessagePrefix& prefix, const LogMessagePostfix& postfix) final;

    private:
        using OStreamManagerPtr = std::shared_ptr<OFStreamManager>;

    private:
        [[nodiscard]] static String GetPrefixName(const String& directory, const String& fileName);
        [[nodiscard]] static String GetFullName(const String& prefixName, const String& extensionName);
        static void NewDirectory(const String& directory) noexcept;

        void Init(const String& directory);

    private:
        String m_Directory;
        String m_PrefixName;
        String m_ExtensionName;
        String m_FullName;
        int m_MaxFileSize;
        bool m_Backup;
        OStreamManagerPtr m_OStreamManager;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_APPENDER_FILE_H
