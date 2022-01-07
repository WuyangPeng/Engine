///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/24 15:58)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_FILE_IN_STREAM_H
#define CORE_TOOLS_OBJECT_SYSTEMS_FILE_IN_STREAM_H

#include "CoreTools/CoreToolsDll.h"

#include "InTopLevel.h"
#include "System/Helper/UnicodeUsing.h"

#include <string>

namespace CoreTools
{
    // �Ӵ����ļ��ж�ȡ���󡣰汾�ַ������ȱ���ȡ���������version��Ƚϣ�
    // ��������ַ����������ô�������󱻶�ȡ��
    class CORE_TOOLS_DEFAULT_DECLARE FileInStream final
    {
    public:
        using ClassType = FileInStream;
        using String = System::String;

    public:
        explicit FileInStream(const String& fileName);

        CLASS_INVARIANT_DECLARE;

        NODISCARD InTopLevel GetInTopLevel() const noexcept;

    private:
        void Load(const String& fileName);

    private:
        InTopLevel inTopLevel;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_FILE_IN_STREAM_H
