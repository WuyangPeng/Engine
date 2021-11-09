///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.5 (2021/10/20 21:21)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER4_TERM19_H
#define EFFECTIVE_MODERN_CPP_CHAPTER4_TERM19_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <vector>

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter4
        {
            namespace Terms19
            {
                namespace Example0
                {
                    class Widget
                    {
                    };

                    void MakeLogEntry(MAYBE_UNUSED Widget* pw) noexcept;
                }

                namespace Example1
                {
                    class Widget
                    {
                        // ...
                        void Process();
                        // ...
                    };
                }

                namespace Example2
                {
                    class Widget : public std::enable_shared_from_this<Widget>
                    {
                        // ...
                        void Process();
                        // ...
                    };
                }

                namespace Example3
                {
                    class Widget : public std::enable_shared_from_this<Widget>
                    {
                    public:
                        // 将实参完美转发给private构造函数的工厂函数
                        template <typename... Ts>
                        static std::shared_ptr<Widget> Create(Ts&&... params);

                        // ...
                        void Process();  // 同前
                        // ...

                    private:
                        // ...
                        // 构造函数
                    };
                }
            }
        }
    }
}
#endif  // EFFECTIVE_MODERN_CPP_CHAPTER4_TERM18_H
