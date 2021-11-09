///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.5 (2021/10/18 22:30)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER4_TERM18_H
#define EFFECTIVE_MODERN_CPP_CHAPTER4_TERM18_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <memory>

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter4
        {
            namespace Terms18
            {
                class Investment
                {
                public:
                    // ...
                    virtual ~Investment() noexcept = default;  // 必备的设计组件！

                    // ...

                    Investment() noexcept = default;
                    Investment(const Investment& rhs) noexcept = default;
                    Investment& operator=(const Investment& rhs) noexcept = default;
                    Investment(Investment&& rhs) noexcept = default;
                    Investment& operator=(Investment&& rhs) noexcept = default;
                };

                class Stock : public Investment
                {
                    // ...
                public:
                    Stock(MAYBE_UNUSED int arguments) noexcept;
                };

                class Bond : public Investment
                {
                    // ...
                public:
                    Bond(MAYBE_UNUSED int arguments) noexcept;
                };

                class RealEstate : public Investment
                {
                    // ...
                public:
                    RealEstate(MAYBE_UNUSED int arguments) noexcept;
                };

                namespace Example0
                {
                    // 返回std::unique_ptr指涉到根据指定实参创建的对象。
                    template <typename... Ts>
                    std::unique_ptr<Investment> MakeInvestment(MAYBE_UNUSED Ts&&... params) noexcept
                    {
                        return std::unique_ptr<Investment>{};
                    }
                }

                void MakeLogEntry(MAYBE_UNUSED Investment* pInvestment) noexcept;

                namespace Example1
                {
                    // 一个作为自定义析构器的lambda表达式
                    auto delInvmt = [](Investment* pInvestment) noexcept {
                        MakeLogEntry(pInvestment);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26401)
#include SYSTEM_WARNING_DISABLE(26409)

                        delete pInvestment;

#include STSTEM_WARNING_POP
                    };

                    bool IsStock() noexcept;
                    bool IsBond() noexcept;
                    bool IsRealEstate() noexcept;

                    template <typename... Ts>
                    std::unique_ptr<Investment, decltype(delInvmt)>  // 改进的返回型别
                        MakeInvestment(Ts&&... params)
                    {
                        std::unique_ptr<Investment, decltype(delInvmt)> pInv(nullptr, delInvmt);

                        if (IsStock() /* 应创建一个Stock型别的对象 */)
                        {
                            pInv.reset(new Stock(std::forward<Ts>(params)...));
                        }
                        else if (IsBond() /* 应创建一个Bond型别的对象 */)
                        {
                            pInv.reset(new Bond(std::forward<Ts>(params)...));
                        }
                        else if (IsRealEstate() /* 应创建一个RealEstate型别的对象 */)
                        {
                            pInv.reset(new RealEstate(std::forward<Ts>(params)...));
                        }

                        return pInv;
                    }
                }

                bool IsStock() noexcept;
                bool IsBond() noexcept;
                bool IsRealEstate() noexcept;

                namespace Example2
                {
                    template <typename... Ts>
                    auto MakeInvestment(Ts&&... params)  // C++14
                    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)

                        // 现在自定义析构器位于MakeInvestment内部了
                        auto delInvmt = [](Investment* pInvestment) noexcept {
                            MakeLogEntry(pInvestment);

#include STSTEM_WARNING_POP

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26401)
#include SYSTEM_WARNING_DISABLE(26409)

                            delete pInvestment;

#include STSTEM_WARNING_POP
                        };

                        std::unique_ptr<Investment, decltype(delInvmt)> pInv(nullptr, delInvmt);  // 同前

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26409)

                        if (IsStock())  // 同前
                        {
                            pInv.reset(new Stock(std::forward<Ts>(params)...));
                        }
                        else if (IsBond())  // 同前
                        {
                            pInv.reset(new Bond(std::forward<Ts>(params)...));
                        }
                        else if (IsRealEstate())  // 同前
                        {
                            pInv.reset(new RealEstate(std::forward<Ts>(params)...));
                        }

#include STSTEM_WARNING_POP

                        return pInv;  // 同前
                    }
                }

                namespace Example3
                {
                    // 使用无状态lambda表达式作为自定义析构器
                    auto delInvmt1 = [](Investment* pInvestment) noexcept {
                        MakeLogEntry(pInvestment);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26401)
#include SYSTEM_WARNING_DISABLE(26409)

                        delete pInvestment;

#include STSTEM_WARNING_POP
                    };

                    // 返回尺寸与Investment*相同
                    template <typename... Ts>
                    std::unique_ptr<Investment, decltype(delInvmt1)>
                        MakeInvestment(Ts&&... params)
                    {
                        return std::unique_ptr<Investment>{};
                    }
                }

                namespace Example4
                {
                    // 使用函数作为自定义析构器
                    void DelInvmt2(Investment* pInvestment);

                    // 返回值尺寸等于Investment*加上至少函数指针的尺寸
                    template <typename... Ts>
                    std::unique_ptr<Investment, void (*)(Investment*)>
                        MakeInvestment(Ts&&... params)
                    {
                        return std::unique_ptr<Investment>{};
                    }
                }
            }
        }
    }
}
#endif  // EFFECTIVE_MODERN_CPP_CHAPTER4_TERM18_H
