//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/13 20:25)

#ifndef CORE_TOOLS_FILE_MANAGER_DELETE_FILE_TOOLS_H
#define CORE_TOOLS_FILE_MANAGER_DELETE_FILE_TOOLS_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <boost/noncopyable.hpp>
#include <string>

CORE_TOOLS_EXPORT_SHARED_PTR(DeleteFileToolsImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE DeleteFileTools final : private boost::noncopyable
    {
    public:
        NON_COPY_CLASSES_TYPE_DECLARE(DeleteFileTools);
        using String = System::String;

    public:
        explicit DeleteFileTools(const String& fileName);

        CLASS_INVARIANT_DECLARE;

    private:
        IMPL_TYPE_DECLARE(DeleteFileTools);
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_DELETE_FILE_TOOLS_H