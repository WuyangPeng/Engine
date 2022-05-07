///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.7 (2022/04/28 16:32)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_COPYRIGHT_DATA_IMPL_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_COPYRIGHT_DATA_IMPL_H

#include "AssistTools/AssistToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <string>

namespace AssistTools
{
    class ASSIST_TOOLS_HIDDEN_DECLARE CopyrightDataImpl
    {
    public:
        using ClassType = CopyrightDataImpl;

    public:
        CopyrightDataImpl(int endYear, const System::String& versions, const System::String& projectChineseName);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetEndYear() const noexcept;
        NODISCARD System::String GetVersions() const;
        NODISCARD System::String GetProjectChineseName() const;

    private:
        int endYear;
        System::String versions;
        System::String projectChineseName;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_COPYRIGHT_DATA_IMPL_H
