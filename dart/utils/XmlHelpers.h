/*
 * Copyright (c) 2013-2015, Georgia Tech Research Corporation
 * All rights reserved.
 *
 * Author(s): Jeongseok Lee <jslee02@gmail.com>
 *
 * Georgia Tech Graphics Lab and Humanoid Robotics Lab
 *
 * Directed by Prof. C. Karen Liu and Prof. Mike Stilman
 * <karenliu@cc.gatech.edu> <mstilman@cc.gatech.edu>
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

#ifndef DART_UTILS_XMLHELPERS_H_
#define DART_UTILS_XMLHELPERS_H_

#include <string>
#include <Eigen/Dense>
// TinyXML-2 Library
// http://www.grinninglizard.com/tinyxml2/index.html
#include <tinyxml2.h>

#include "dart/common/ResourceRetriever.h"
#include "dart/math/MathTypes.h"

namespace dart {
namespace utils {

std::string toString(bool _v);
std::string toString(int _v);
std::string toString(unsigned int _v);
std::string toString(float _v);
std::string toString(double _v);
std::string toString(char _v);
std::string toString(const Eigen::Vector2d& _v);
std::string toString(const Eigen::Vector3d& _v);
std::string toString(const Eigen::Vector3i& _v);
std::string toString(const Eigen::Vector6d& _v);
std::string toString(const Eigen::VectorXd& _v);
std::string toString(const Eigen::Isometry3d& _v);

bool              toBool      (const std::string& _str);
int               toInt       (const std::string& _str);
unsigned int      toUInt      (const std::string& _str);
float             toFloat     (const std::string& _str);
double            toDouble    (const std::string& _str);
char              toChar      (const std::string& _str);
Eigen::Vector2d   toVector2d  (const std::string& _str);
Eigen::Vector3d   toVector3d  (const std::string& _str);
Eigen::Vector3i   toVector3i  (const std::string& _str);
Eigen::Vector6d   toVector6d  (const std::string& _str);
Eigen::VectorXd   toVectorXd  (const std::string& _str);
// TODO: The definition of _str is not clear for transform (see: #250)
Eigen::Isometry3d toIsometry3d(const std::string& _str);
Eigen::Isometry3d toIsometry3dWithExtrinsicRotation(const std::string& _str);

std::string       getValueString    (const tinyxml2::XMLElement* _parentElement, const std::string& _name);
bool              getValueBool      (const tinyxml2::XMLElement* _parentElement, const std::string& _name);
int               getValueInt       (const tinyxml2::XMLElement* _parentElement, const std::string& _name);
unsigned int      getValueUInt      (const tinyxml2::XMLElement* _parentElement, const std::string& _name);
float             getValueFloat     (const tinyxml2::XMLElement* _parentElement, const std::string& _name);
double            getValueDouble    (const tinyxml2::XMLElement* _parentElement, const std::string& _name);
char              getValueChar      (const tinyxml2::XMLElement* _parentElement, const std::string& _name);
Eigen::Vector2d   getValueVector2d  (const tinyxml2::XMLElement* _parentElement, const std::string& _name);
Eigen::Vector3d   getValueVector3d  (const tinyxml2::XMLElement* _parentElement, const std::string& _name);
Eigen::Vector3i   getValueVector3i  (const tinyxml2::XMLElement* _parentElement, const std::string& _name);
Eigen::Vector6d   getValueVector6d  (const tinyxml2::XMLElement* _parentElement, const std::string& _name);
Eigen::VectorXd   getValueVectorXd  (const tinyxml2::XMLElement* _parentElement, const std::string& _name);
Eigen::Isometry3d getValueIsometry3d(const tinyxml2::XMLElement* _parentElement, const std::string& _name);
Eigen::Isometry3d getValueIsometry3dWithExtrinsicRotation(const tinyxml2::XMLElement* _parentElement, const std::string& _name);

void openXMLFile(tinyxml2::XMLDocument& doc, const common::Uri& uri,
                 const common::ResourceRetrieverPtr& retriever = nullptr);
bool hasElement(tinyxml2::XMLElement* _parentElement, const std::string& _name);
tinyxml2::XMLElement* getElement(tinyxml2::XMLElement* _parentElement, const std::string& _name);
bool hasAttribute(tinyxml2::XMLElement* element, const char* const name);

// Please use getAttributeString() instead.
DEPRECATED(6.0)
std::string getAttribute(tinyxml2::XMLElement* element, const char* const name);

// Please use getAttributeDouble() instead.
DEPRECATED(6.0)
void getAttribute(tinyxml2::XMLElement* element, const char* const name, double* d);

std::string     getAttributeString  (const tinyxml2::XMLElement* element, const std::string& attributeName);
bool            getAttributeBool    (const tinyxml2::XMLElement* element, const std::string& attributeName);
int             getAttributeInt     (const tinyxml2::XMLElement* element, const std::string& attributeName);
unsigned int    getAttributeUInt    (const tinyxml2::XMLElement* element, const std::string& attributeName);
float           getAttributeFloat   (const tinyxml2::XMLElement* element, const std::string& attributeName);
double          getAttributeDouble  (const tinyxml2::XMLElement* element, const std::string& attributeName);
char            getAttributeChar    (const tinyxml2::XMLElement* element, const std::string& attributeName);
Eigen::Vector2d getAttributeVector2d(const tinyxml2::XMLElement* element, const std::string& attributeName);
Eigen::Vector3d getAttributeVector3d(const tinyxml2::XMLElement* element, const std::string& attributeName);
Eigen::Vector6d getAttributeVector6d(const tinyxml2::XMLElement* element, const std::string& attributeName);
Eigen::VectorXd getAttributeVectorXd(const tinyxml2::XMLElement* element, const std::string& attributeName);

/// TemplatedElementEnumerator is a convenience class to help visiting all the
/// child elements of given parent element. This class is templated to cover
/// const and non-const tinyxml2::XMLElement types.
template <typename ElementType>
class TemplatedElementEnumerator
{
protected:

  using ElementPtr = typename std::add_pointer<ElementType>::type;
  using ElementRef = typename std::add_lvalue_reference<ElementType>::type;

public:

  /// Constructor that takes parent element and
  TemplatedElementEnumerator(ElementPtr parentElement,
                             const std::string& childElementName)
    : mParentElement(parentElement),
      mChildElementName(childElementName),
      mCurrentElement(nullptr)
  {
  }

  /// Destructor
  ~TemplatedElementEnumerator() {}

  /// Set the current element to the next sibling element or to the first child
  /// element of given parent element if it exists; returns success
  bool next()
  {
    if (!mParentElement)
      return false;

    if (mCurrentElement)
    {
      mCurrentElement
          = mCurrentElement->NextSiblingElement(mChildElementName.c_str());
    }
    else
    {
      mCurrentElement
          = mParentElement->FirstChildElement(mChildElementName.c_str());
    }

    if (!valid())
      mParentElement = nullptr;

    return valid();
  }

  /// Get the current element
  ElementPtr get() const { return mCurrentElement; }

  /// Dereference operator
  ElementPtr operator->() const { return mCurrentElement; }

  /// Dereference operator
  ElementRef operator*() const { return *mCurrentElement; }

  /// Equality operator
  bool operator==(const TemplatedElementEnumerator<ElementType>& rhs) const
  {
    // If they point at the same node, then the names must match
    return (this->mParentElement == rhs.mParentElement)
           && (this->mCurrentElement == rhs.mCurrentElement)
           && (this->mCurrentElement != nullptr
              || (this->mChildElementName == rhs.mChildElementName));
  }

  /// Assignment operator
  TemplatedElementEnumerator<ElementType>& operator=(
      const TemplatedElementEnumerator<ElementType>& rhs)
  {
    this->mParentElement    = rhs.mParentElement;
    this->mChildElementName = rhs.mChildElementName;
    this->mCurrentElement   = rhs.mCurrentElement;

    return *this;
  }

private:

  /// Returns true if the current element is valid (not a nullptr)
  bool valid() const
  {
    return mCurrentElement != nullptr;
  }

private:

  /// Parent element
  ElementPtr mParentElement;

  /// Child element name
  std::string mChildElementName;

  /// Currently visiting child element
  ElementPtr mCurrentElement;

};

// ElementEnumerator is for iterating elements for
using ElementEnumerator
    = TemplatedElementEnumerator<tinyxml2::XMLElement>;
using ConstElementEnumerator
    = TemplatedElementEnumerator<const tinyxml2::XMLElement>;

} // namespace utils
} // namespace dart

#endif // #ifndef DART_UTILS_XMLHELPERS_H_
