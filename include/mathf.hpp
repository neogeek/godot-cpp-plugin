#pragma once

#include <algorithm>

namespace Mathf
{

auto lerp(float a, float b, float t) -> float { return ((1 - t) * a) + (b * t); }

auto inverse_lerp(float a, float b, float v) -> float
{
    return std::clamp((v - a) / (b - a), 0.0F, 1.0F);
}

} // namespace Mathf
