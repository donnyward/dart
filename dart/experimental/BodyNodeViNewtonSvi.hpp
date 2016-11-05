/*
 * Copyright (c) 2016, Graphics Lab, Georgia Tech Research Corporation
 * Copyright (c) 2016, Humanoid Lab, Georgia Tech Research Corporation
 * Copyright (c) 2016, Personal Robotics Lab, Carnegie Mellon University
 * All rights reserved.
 *
 * This file is provided under the following "BSD-style" License:
 *   Redistribution and use in source and binary forms, with or
 *   without modification, are permitted provided that the following
 *   conditions are met:
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
 *   CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 *   INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 *   MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *   DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 *   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
 *   USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 *   AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *   LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *   ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *   POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef DART_DYNAMICS_BODYNODEVINEWTONSVI_HPP_
#define DART_DYNAMICS_BODYNODEVINEWTONSVI_HPP_

#include <Eigen/Dense>

#include "dart/common/AspectWithVersion.hpp"
#include "dart/dynamics/Skeleton.hpp"

namespace dart {
namespace dynamics {

class JointViNewtonSvi;

namespace detail {

struct BodyNodeViNewtonSviState
{
  using GradientMatrix = Eigen::Matrix<double, 6, Eigen::Dynamic>;

  EIGEN_MAKE_ALIGNED_OPERATOR_NEW

  /// Constructor
  BodyNodeViNewtonSviState();

  /// Destructor
  virtual ~BodyNodeViNewtonSviState() = default;

  /// The prediction of the transform for the next discrete time (k+1)
  Eigen::Isometry3d mNextWorldTransform{Eigen::Isometry3d::Identity()};

  /// The relative transform of the next transform relative to the current
  /// transform.
  Eigen::Isometry3d mWorldTransformDisplacement{Eigen::Isometry3d::Identity()};

  /// Discrete spatial velocity for the duration of (k-1, k).
  Eigen::Vector6d mPreAverageSpatialVelocity{Eigen::Vector6d::Zero()};

  /// Discrete spatial velocity for the duration of (k, k+1).
  Eigen::Vector6d mPostAverageSpatialVelocity{Eigen::Vector6d::Zero()};

  /// Discrete spatial momentum for the duration of (k-1, k).
  Eigen::Vector6d mPrevMomentum{Eigen::Vector6d::Zero()};

  /// Discrete spatial momentum for the duration of (k, k+1).
  Eigen::Vector6d mPostMomentum{Eigen::Vector6d::Zero()};

  /// Spatial impulse transmitted from the parent BodyNode.
  Eigen::Vector6d mParentImpulse{Eigen::Vector6d::Zero()};
};

} // namespace detail

//==============================================================================
class BodyNodeViNewtonSvi final
    : public common::AspectWithState<BodyNodeViNewtonSvi,
                                     detail::BodyNodeViNewtonSviState,
                                     BodyNode>
{
public:
  friend class SkeletonViNewtonSvi;

  using Base = common::AspectWithState<BodyNodeViNewtonSvi,
                                       detail::BodyNodeViNewtonSviState,
                                       BodyNode>;

  using GradientMatrix = Eigen::Matrix<double, 6, Eigen::Dynamic>;

  EIGEN_MAKE_ALIGNED_OPERATOR_NEW

  BodyNodeViNewtonSvi(const StateData& state = StateData());

  BodyNodeViNewtonSvi(const BodyNodeViNewtonSvi&) = delete;

  JointViNewtonSvi* getJointVi();
  const JointViNewtonSvi* getJointVi() const;

  void initialize(double timeStep);

protected:
  void setComposite(common::Composite* newComposite) override;

  void updateNextTransform();
  void updateNextVelocity(double timeStep);

  void evaluateDel(const Eigen::Vector3d& gravity, double timeStep);

  /// \{ \name Derivative

  void updateNextTransformDeriv();
  void updateNextVelocityDeriv(double timeStep);

  /// \}
};

} // namespace dynamics
} // namespace dart

#endif // DART_DYNAMICS_BODYNODEVINEWTONSVI_HPP_