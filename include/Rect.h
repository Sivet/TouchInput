/*!
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 *
 * \copyright   Copyright 2021 RSP Systems A/S. All rights reserved.
 * \license     Mozilla Public License 2.0
 * \author      Simon Glashoff
 * \author      Steffen Brummer
 */
#ifndef RECT_H
#define RECT_H

#include "Point.h"

namespace rsp::graphics
{

class Rect
{
  public:
    Rect(int aLeft, int aTop, int aWidth, int aHeight);
    Rect(const Point &aLeftTop, const Point &aRightBottom);
    Rect(const Point &aLeftTop, int aWidth, int aHeight);
    Rect(const Rect &aRect);
    int GetTop() const;
    void SetTop(int aTopValue);
    int GetBottom() const;
    void SetBottom(int aBotValue);
    int GetLeft() const;
    void SetLeft(int aLeftValue);
    int GetRight() const;
    void SetRight(int aRightValue);
    const Point &GetTopLeft() const
    {
        return mLeftTop;
    }
    const Point &GetBottomRight() const
    {
        return mRightBottom;
    }
    int GetWidth() const;
    void SetWidth(int aWidth);
    int GetHeight() const;
    void SetHeight(int aHeight);
    bool IsHit(const Point &aPoint) const;

    bool VerifyDimensions() const;

  protected:
    Point mLeftTop;
    Point mRightBottom;
};

} // namespace rsp::graphics
#endif // RECT_H
