// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/08 15:30)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_CALCULATE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_CALCULATE_H

#include "Mathematics/MathematicsDll.h"

#include "Bisect2Storage.h" 

namespace Mathematics
{       
    template <typename Real>
    class Bisect2Calculate
    {
    public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Bisect2Calculate<Real>;
        using Bisect2Storage = Bisect2Storage<Real>;
        using Bisect2Node = Bisect2Node<Real>;
        using Bisect2NodePtr = std::shared_ptr<Bisect2Node>;
        using Bisect2Root = Bisect2Root<Real>;
        using Bisect2RootPtr = std::shared_ptr<Bisect2Root>;
        using Bisect2 = Bisect2<Real>;
        
    public:
        Bisect2Calculate (const Bisect2& bisect,Real beginPointX, Real beginPointY,Real endPointX, Real endPointY);
        
		CLASS_INVARIANT_DECLARE;
        
        const Bisect2Root GetRoot() const;

    private:
        void Calculate(Real beginPointX, Real beginPointY,Real endPointX, Real endPointY);
        
        bool BisectRecurse (Bisect2Node* node);

   private:
        const Bisect2& m_Bisect2;
        int m_Level;
        Bisect2RootPtr m_Bisect2Root;

        // �̶��洢,�Ա����ڵݹ��ջ��ġ�
        Bisect2Storage m_Bisect2Storage;
          
        // ͼ���ɵݹ������������
        Bisect2NodePtr m_Graph;
    };

    using Bisect2Calculatef = Bisect2Calculate<float>;
    using Bisect2Calculated = Bisect2Calculate<double>;
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_CALCULATE_H
