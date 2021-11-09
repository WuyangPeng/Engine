///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.5 (2021/10/18 22:30)

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
                    virtual ~Investment() noexcept = default;  // �ر�����������

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
                    // ����std::unique_ptrָ�浽����ָ��ʵ�δ����Ķ���
                    template <typename... Ts>
                    std::unique_ptr<Investment> MakeInvestment(MAYBE_UNUSED Ts&&... params) noexcept
                    {
                        return std::unique_ptr<Investment>{};
                    }
                }

                void MakeLogEntry(MAYBE_UNUSED Investment* pInvestment) noexcept;

                namespace Example1
                {
                    // һ����Ϊ�Զ�����������lambda���ʽ
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
                    std::unique_ptr<Investment, decltype(delInvmt)>  // �Ľ��ķ����ͱ�
                        MakeInvestment(Ts&&... params)
                    {
                        std::unique_ptr<Investment, decltype(delInvmt)> pInv(nullptr, delInvmt);

                        if (IsStock() /* Ӧ����һ��Stock�ͱ�Ķ��� */)
                        {
                            pInv.reset(new Stock(std::forward<Ts>(params)...));
                        }
                        else if (IsBond() /* Ӧ����һ��Bond�ͱ�Ķ��� */)
                        {
                            pInv.reset(new Bond(std::forward<Ts>(params)...));
                        }
                        else if (IsRealEstate() /* Ӧ����һ��RealEstate�ͱ�Ķ��� */)
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

                        // �����Զ���������λ��MakeInvestment�ڲ���
                        auto delInvmt = [](Investment* pInvestment) noexcept {
                            MakeLogEntry(pInvestment);

#include STSTEM_WARNING_POP

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26401)
#include SYSTEM_WARNING_DISABLE(26409)

                            delete pInvestment;

#include STSTEM_WARNING_POP
                        };

                        std::unique_ptr<Investment, decltype(delInvmt)> pInv(nullptr, delInvmt);  // ͬǰ

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26409)

                        if (IsStock())  // ͬǰ
                        {
                            pInv.reset(new Stock(std::forward<Ts>(params)...));
                        }
                        else if (IsBond())  // ͬǰ
                        {
                            pInv.reset(new Bond(std::forward<Ts>(params)...));
                        }
                        else if (IsRealEstate())  // ͬǰ
                        {
                            pInv.reset(new RealEstate(std::forward<Ts>(params)...));
                        }

#include STSTEM_WARNING_POP

                        return pInv;  // ͬǰ
                    }
                }

                namespace Example3
                {
                    // ʹ����״̬lambda���ʽ��Ϊ�Զ���������
                    auto delInvmt1 = [](Investment* pInvestment) noexcept {
                        MakeLogEntry(pInvestment);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26401)
#include SYSTEM_WARNING_DISABLE(26409)

                        delete pInvestment;

#include STSTEM_WARNING_POP
                    };

                    // ���سߴ���Investment*��ͬ
                    template <typename... Ts>
                    std::unique_ptr<Investment, decltype(delInvmt1)>
                        MakeInvestment(Ts&&... params)
                    {
                        return std::unique_ptr<Investment>{};
                    }
                }

                namespace Example4
                {
                    // ʹ�ú�����Ϊ�Զ���������
                    void DelInvmt2(Investment* pInvestment);

                    // ����ֵ�ߴ����Investment*�������ٺ���ָ��ĳߴ�
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
