// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 16:20)

#ifndef PHYSICS_FLUID_FLUID2DB_H
#define PHYSICS_FLUID_FLUID2DB_H

#include "Physics/PhysicsDll.h"

#include "Mathematics/Algebra/Vector2D.h"

// This class is an implementation based on the ideas in "Real-Time Fluid
// Dynamics for Games", by Jos Stam (GDC 2003 Proceedings), but the code
// is faster in that it processes the source, diffusion, and advection
// terms all at the same time.  The only Gauss-Seidel iteration is in the
// Poisson solver.

namespace Physics
{
    template <typename Real>
    class PHYSICS_TEMPLATE_DEFAULT_DECLARE Fluid2Db
    {
    public:
        using Vector2D = Mathematics::Vector2D<Real>;

    public:
        // Construction and destruction.
        Fluid2Db(Real x0, Real y0, Real x1, Real y1, Real dt, Real denViscosity,
                 Real velViscosity, int imax, int jmax, int numGaussSeidelIterations, bool densityDirichlet);

        virtual ~Fluid2Db();
        Fluid2Db(const Fluid2Db&) = delete;
        Fluid2Db& operator=(const Fluid2Db&) = delete;
        Fluid2Db(Fluid2Db&&) = delete;
        Fluid2Db& operator=(Fluid2Db&&) = delete;
        // Member access.
        Real GetX0() const noexcept;
        Real GetY0() const noexcept;
        Real GetX1() const noexcept;
        Real GetY1() const noexcept;
        Real GetDt() const noexcept;
        Real GetDx() const noexcept;
        Real GetDy() const noexcept;
        Real GetTime() const noexcept;
        int GetIMax() const noexcept;
        int GetJMax() const noexcept;
        const Real* GetX() const noexcept;
        const Real* GetY() const noexcept;
        Real** GetDensity() const noexcept;
        Vector2D** GetVelocity() const noexcept;

        // Derived classes must provide initialization at time 0.
        virtual Real InitialDensity(Real x, Real y, int i, int j) = 0;

        virtual Vector2D InitialVelocity(Real x, Real y, int i, int j) = 0;

        // Derived classes must provide source terms.  The density has a
        // source-sink function.  The velocity has a force (impulse) function.
        virtual Real SourceDensity(Real t, Real x, Real y, int i, int j) = 0;

        virtual Vector2D SourceVelocity(Real t, Real x, Real y, int i, int j) = 0;

        void Initialize();
        void DoSimulationStep();

    protected:
        // Update the boundary values after the interior values have been
        // assigned.
        void DirichletBoundaryZero(Real** data) noexcept;
        void NeumannBoundaryZero(Real** data) noexcept;
        void UpdateDensityBoundary() noexcept;
        void UpdateVelocityBoundary();

        // Swap the buffer pointers.
        void SwapDensityBuffers() noexcept;
        void SwapVelocityBuffers() noexcept;

        // Constructor inputs.
        Real mX0, mY0, mX1, mY1;
        Real mDt;
        Real mDenViscosity, mVelViscosity;
        int mIMax, mJMax;
        int mNumGaussSeidelIterations;
        bool mDensityDirichlet;

        // Derived quantities;
        int mIMaxM1, mJMaxM1, mIMaxP1, mJMaxP1, mKMaxP1, mNumPixels;
        Real mDx, mDy;
        Real mDxDx, mDyDy;
        Real mHalfDivDx, mHalfDivDy;
        Real mDtDivDx, mDtDivDy, mDtDivDxDx, mDtDivDyDy;
        Real mEpsilon0, mEpsilonX, mEpsilonY;
        Real mDenLambdaX, mDenLambdaY;
        Real mVelLambdaX, mVelLambdaY;
        Real mDenGamma0, mDenGammaX, mDenGammaY;
        Real mVelGamma0, mVelGammaX, mVelGammaY;

        // Current simulation time.
        Real mTime;

        // Lattice cell centers.
        Real* mX;
        Real* mY;

        // State arrays.
        Real** mDensity0;
        Real** mDensity1;
        Vector2D** mVelocity0;
        Vector2D** mVelocity1;
        Real** mDivergence;
        Real** mPoisson;
    };
}

#endif  // PHYSICS_FLUID_FLUID2DB_H
