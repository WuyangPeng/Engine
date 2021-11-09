
#ifndef CORE_TOOLS_FILE_MANAGER_IFSTREAM_MANAGER_H
#define CORE_TOOLS_FILE_MANAGER_IFSTREAM_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

namespace CoreTools
{
    // ����һ������ļ������������޸ĺͱ���浵�ļ�ʱ������ʱ�浵��
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

#endif  // CORE_TOOLS_FILE_MANAGER_IFSTREAM_MANAGER_H
