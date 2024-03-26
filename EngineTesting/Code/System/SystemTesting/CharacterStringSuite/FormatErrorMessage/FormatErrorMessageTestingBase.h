/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 14:02)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_FORMAT_ERROR_MESSAGE_TESTING_BASE_H
#define SYSTEM_CHARACTER_STRING_SUITE_FORMAT_ERROR_MESSAGE_TESTING_BASE_H

#include "FormatMessageTestingBase.h"
#include "System/DynamicLink/Using/LoadLibraryUsing.h"
#include "System/Windows/Flags/PlatformErrorFlags.h"

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
        NODISCARD DynamicLinkModule CreateKernel32Dll();
        void FreeKernel32Dll(DynamicLinkModule kernel32Dll);

    protected:
        NODISCARD static bool IsFormatWindowErrorSuccess(WindowError windowError);

    private:
        WindowErrorContainer windowErrors;
        WindowErrorContainer comWindowErrors;
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_FORMAT_ERROR_MESSAGE_TESTING_BASE_H