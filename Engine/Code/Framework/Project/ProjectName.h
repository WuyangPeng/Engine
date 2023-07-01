///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.0 (2023/06/18 20:33)
///
///	��Ԫ���ԣ�Pass

#ifndef FRAMEWORK_PROJECT_PROJECT_NAME_H
#define FRAMEWORK_PROJECT_PROJECT_NAME_H

#include "Framework/FrameworkDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Framework/MainFunctionHelper/MainFunctionHelperFwd.h"

#include <vector>

FRAMEWORK_PERFORMANCE_UNSHARED_EXPORT_IMPL(ProjectNameImpl);

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE ProjectName final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(ProjectName);

        using String = System::String;

    public:
        ProjectName(const String& fileName, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetSelectDescribe() const;
        NODISCARD bool IsSelectValid(int select) const;
        NODISCARD String GetEngineeringName(int select) const;
        NODISCARD int GetContainerPrintWidth() const;

    private:
        PackageType impl;
    };
}

#endif  // FRAMEWORK_PROJECT_PROJECT_NAME_H