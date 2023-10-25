///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/22 13:39)

#ifndef CORE_TOOLS_FILE_MANAGER_GENERATE_RANDOM_NAME_H
#define CORE_TOOLS_FILE_MANAGER_GENERATE_RANDOM_NAME_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

// 生成一个随机文件名，用于在修改和保存存档文件时生成临时存档。
namespace CoreTools
{

    class CORE_TOOLS_DEFAULT_DECLARE GenerateRandomName
    {
    public:
        using ClassType = GenerateRandomName;

        using String = System::String;

    public:
        NODISCARD static std::string GetName(int length, const std::string& extensionName = "tmp");
        NODISCARD static std::wstring GetName(int length, const std::wstring& extensionName = L"tmp");
        NODISCARD static String GetStandardName(int length, const String& extensionName = SYSTEM_TEXT("tmp"));

    private:
        template <typename T>
        NODISCARD static T GetName(int length, const T& letters, const T& extensionName);
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_GENERATE_RANDOM_NAME_H
