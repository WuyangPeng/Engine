// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/08 15:36)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_CALCULATE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_CALCULATE_H

#include "Mathematics/MathematicsDll.h"

#include "Bisect3Root.h"
#include "Bisect3Storage.h" 

namespace Mathematics
{
    template <typename Real>
    class Bisect3Node;

    template <typename Real>
    class  Bisect3;
    
    template <typename Real>
    class Bisect3Calculate
    {
    public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Bisect3Calculate<Real>;
        using Bisect3Storage = Bisect3Storage<Real>;
        using Bisect3Node = Bisect3Node<Real>;
        using Bisect3NodePtr = std::shared_ptr<Bisect3Node>;
        using Bisect3Root = Bisect3Root<Real>;
        using Bisect3RootPtr = std::shared_ptr<Bisect3Root>;
        using Bisect3 = Bisect3<Real>;
        
    public:
        Bisect3Calculate (const Bisect3& bisect,Real beginPointX, Real beginPointY,Real beginPointZ,
						  Real endPointX, Real endPointY, Real endPointZ);
        
		CLASS_INVARIANT_DECLARE;

       const Bisect3Root GetRoot() const;

    private:
        void Calculate(Real beginPointX, Real beginPointY,Real beginPointZ,
                       Real endPointX, Real endPointY,Real endPointZ);
        
        bool BisectRecurse (Bisect3Node* node);

		void BuildLeftLowerInside(Bisect3Node* node);
		void BuildRightLowerInside(Bisect3Node* node);
		void BuildLeftUpperInside(Bisect3Node* node);
		void BuildRightUpperInside(Bisect3Node* node);
		void BuildLeftLowerOutside(Bisect3Node* node);
		void BuildRightLowerOutside(Bisect3Node* node);
		void BuildLeftUpperOutside(Bisect3Node* node);
		void BuildRightUpperOutside(Bisect3Node* node);
    
    private:
        const Bisect3& m_Bisect3;
        int m_Level;
        Bisect3RootPtr m_Bisect3Root;
        
        // πÃ∂®¥Ê¥¢,“‘±‹√‚‘⁄µ›πÈ∂—’ªÀ∫ƒ°£
        Bisect3Storage m_Bisect3Storage;
        
        // Õº£¨”…µ›πÈ≥Ã–Ú¿¥ππΩ®°£
        Bisect3NodePtr m_Graph;
    };
    
    using Bisect3Calculatef = Bisect3Calculate<float>;
    using Bisect3Calculated = Bisect3Calculate<double>;
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_CALCULATE_H
