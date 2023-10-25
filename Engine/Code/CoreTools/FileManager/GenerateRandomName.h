///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/22 13:39)

#ifndef CORE_TOOLS_FILE_MANAGER_GENERATE_RANDOM_NAME_H
#define CORE_TOOLS_FILE_MANAGER_GENERATE_RANDOM_NAME_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

// ����һ������ļ������������޸ĺͱ���浵�ļ�ʱ������ʱ�浵��
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
