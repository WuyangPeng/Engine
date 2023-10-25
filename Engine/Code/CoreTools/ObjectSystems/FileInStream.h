///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/20 15:25)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_FILE_IN_STREAM_H
#define CORE_TOOLS_OBJECT_SYSTEMS_FILE_IN_STREAM_H

#include "CoreTools/CoreToolsDll.h"

#include "InTopLevel.h"
#include "System/Helper/UnicodeUsing.h"

#include <string>

/// �Ӵ����ļ��ж�ȡ���󡣰汾�ַ������ȱ���ȡ���������version��Ƚϣ�
/// ��������ַ����������ô�������󱻶�ȡ��
namespace CoreTools
{
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
