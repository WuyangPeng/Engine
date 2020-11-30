///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.4 (2020/11/26 14:32)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_GET_MINIMUM_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_GET_MINIMUM_H

#include "Mathematics/MathematicsDll.h"

#include "Minimize1.h"
#include "MinimizeNData.h"

namespace Mathematics
{
    template <typename Real, typename UserDataType>
    class MinimizeNGetMinimum final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = MinimizeNGetMinimum<Real, UserDataType>;
        using Math = Math<Real>;
        using Minimize1 = Minimize1<Real, ClassType>;
        using MinimizeNData = MinimizeNData<Real>;
        using Container = std::vector<Real>;
        using IndexContainer = std::vector<int>;
        using Function = Real (*)(const Container&, const UserDataType*);

    public:
        MinimizeNGetMinimum(int dimensions, const Container& initial, Function function,
                            const UserDataType* userData, const Container& begin, const Container& end);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] int GetDimensions() const noexcept;
        [[nodiscard]] Real CalculateLineArg(int index, Real value) const;
        [[nodiscard]] Real GetFunctionResult(const Container& lineArg) const noexcept;

        void FindEachDirection(int index, int maxLevel, int maxBracket);
        [[nodiscard]] Real EstimateUnitLengthConjugateDirection();
        void MinimizeConjugateDirection(Real length, int maxLevel, int maxBracket);

        [[nodiscard]] const MinimizeNData& GetMinimizeNData() const noexcept;

    private:
        struct DomainResult
        {
            Real m_BeginResult;
            Real m_EndResult;

            DomainResult(Real beginResult, Real endResult) noexcept;
        };

        // ���λ�õ�Ŀǰ�Ĺ�����m_TCurr[0..d-1]��
        // ��ǰ�������ķ�����m_DCurr[0..d-1]�����߱���Եѿ����˻������������ʵ�ֵĹ��̱��ü���
        // ���������m_TCurr + s * m_DCurr���ü����������[beginResult��endResult]��
        DomainResult ComputeDomain(const Container& begin, const Container& end);

        // Minimize1<Real>������ҪC���ĺ�����ִ������һά����
        // ������m_TCurr + s * m_DCurr����
        [[nodiscard]] static Real LineFunction(Real value, const MinimizeNGetMinimum* userData);

        Real GetDirectionCurrent(int index) const;
        void SetDirectionCurrent(int index) noexcept;

        [[nodiscard]] constexpr static int GetIndexSize(int dimensions)
        {
            return dimensions + 1;
        }

        [[nodiscard]] constexpr static int GetStorageSize(int dimensions)
        {
            return dimensions * GetIndexSize(dimensions);
        }

    private:
        int m_Dimensions;
        Container m_DirectionStorage;
        IndexContainer m_DirectionIndex;
        int m_DirectionConjugateIndex;
        int m_DirectionCurrentIndex;
        Container m_Save;

        Function m_Function;
        const UserDataType* m_UserData;
        MinimizeNData m_MinimizeNData;
        Container m_Begin;
        Container m_End;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_GET_MINIMUM_H
