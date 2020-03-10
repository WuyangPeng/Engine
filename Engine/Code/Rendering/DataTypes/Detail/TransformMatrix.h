// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/17 14:03)

#ifndef RENDERING_DATA_TYPES_TRANSFORM_MATRIX_H
#define RENDERING_DATA_TYPES_TRANSFORM_MATRIX_H

#include "Rendering/RenderingDll.h"

#include "Mathematics/Algebra/Matrix.h"
#include "Mathematics/Algebra/APoint.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE TransformMatrix
    {
    public:
        using ClassType = TransformMatrix;
        using Matrix = Mathematics::Matrix<float>;
        using APoint = Mathematics::APoint<float>;
        
    public:
        TransformMatrix ();
        
		CLASS_INVARIANT_DECLARE;
        
        void MakeIdentity ();    
        void MakeUnitScale (const Matrix& rotate);

        bool IsIdentity () const;  
        bool IsRotationOrScaleMatrix () const;  
        bool IsUniformScale () const;  
       
        void SetRotate (const Matrix& rotate,const APoint& scale);
        void SetMatrix (const Matrix& matrix);
        void SetTranslate (const APoint& translate);
        void SetScale (const Matrix& rotate,const APoint& scale);
        void SetUniformScale (const Matrix& rotate,float scale);

		const Matrix GetMatrix () const;
        
        int GetStreamingSize () const;

        static const TransformMatrix sm_Identity;         
        
    private:
        void Modification(const APoint& translate);
        void Modification(const Matrix& matrix);
        void Modification(const Matrix& rotate,const APoint& scale);
        
    private:      
        Matrix m_Matrix;

        bool m_IsIdentity;
        bool m_IsRotationOrScaleMatrix;
        bool m_IsUniformScale;
    };     
}

#endif // RENDERING_DATA_TYPES_TRANSFORM_MATRIX_H
