///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.4 (2022/11/28 21:00)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_FORMAT_ERROR_MESSAGE_TESTING_BASE_H
#define SYSTEM_CHARACTER_STRING_SUITE_FORMAT_ERROR_MESSAGE_TESTING_BASE_H

#include "FormatMessageTestingBase.h"
#include "System/Helper/EnumCast.h"
#include "System/Windows/Flags/PlatformErrorFlags.h"
#include "System/Windows/WindowsFwd.h"

#include <set>

namespace System
{
    class FormatErrorMessageTestingBase : public FormatMessageTestingBase
    {
    public:
        using ClassType = FormatErrorMessageTestingBase;
        using ParentType = FormatMessageTestingBase;

    public:
        explicit FormatErrorMessageTestingBase(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        using WindowErrorContainer = std::set<WindowError>;
        using WindowErrorContainerConstIter = WindowErrorContainer::const_iterator;

        static constexpr auto bufferSize = 256u;

    protected:
        NODISCARD bool IsWindowErrorValid(WindowError windowError) const;
        NODISCARD WindowErrorContainerConstIter GetComWindowErrorBegin() const noexcept;
        NODISCARD WindowErrorContainerConstIter GetComWindowErrorEnd() const noexcept;
        NODISCARD bool IsExistInvalidWindowError() const noexcept;
        NODISCARD bool IsExistValidWindowError() const noexcept;
        NODISCARD DynamicLinkModule CreateKernel32Dll();
        void FreeKernel32Dll(DynamicLinkModule kernel32Dll);

    protected:
        NODISCARD static bool IsFormatWindowErrorSuccess(WindowError windowError);

    private:
        // Windows 7ϵͳĳЩ��������Ϣ�����ڡ�
        static constexpr auto windows7InvalidWindowError = WindowError::DeviceSupportInProgress;

        // Windows 10ϵͳ������δ�ĵ����Ĵ����롣
        static constexpr auto windows10ValidWindowError = UnderlyingCastEnum<WindowError>(44);

    private:
        WindowErrorContainer windowErrors;
        WindowErrorContainer comWindowErrors;
        bool isExistInvalidWindowError;
        bool isExistValidWindowError;
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_FORMAT_ERROR_MESSAGE_TESTING_BASE_H