/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/03/30 22:56)

#ifndef CORE_TOOLS_FILE_MANAGER_GENERATE_RANDOM_NAME_H
#define CORE_TOOLS_FILE_MANAGER_GENERATE_RANDOM_NAME_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

/// ����һ������ļ������������޸ĺͱ���浵�ļ�ʱ������ʱ�浵��
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
        requires(std::is_same_v<T, std::string> || std::is_same_v<T, std::wstring>)
        NODISCARD static T GetName(int length, const T& letters, const T& extensionName);
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_GENERATE_RANDOM_NAME_H
