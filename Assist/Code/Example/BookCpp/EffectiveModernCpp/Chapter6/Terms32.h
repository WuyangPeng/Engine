///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.7 (2021/11/29 21:29)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER6_TERM32_H
#define EFFECTIVE_MODERN_CPP_CHAPTER6_TERM32_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter6
        {
            namespace Terms32
            {
                namespace Example0
                {
                    class Widget  // 一些有用的型别
                    {
                    public:
                        // ...

                        bool IsValidated() const noexcept;
                        bool IsProcessed() const noexcept;
                        bool IsArchived() const noexcept;

                    private:
                        // ...
                    };

                    class IsValAndArch  // 表示“已校验并已归档”
                    {
                    public:
                        using DataType = std::unique_ptr<Widget>;

                        explicit IsValAndArch(DataType&& ptr) noexcept;

                        bool operator()() const noexcept;

                    private:
                        DataType pw;
                    };
                }
            }
        }
    }
}
#endif  // EFFECTIVE_MODERN_CPP_CHAPTER6_TERM32_H
