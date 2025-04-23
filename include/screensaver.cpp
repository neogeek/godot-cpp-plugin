#include "screensaver.hpp"

#include <algorithm>

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void Screensaver::_bind_methods() {}

void Screensaver::_ready()
{
    screen_size = get_viewport_rect().size;
    sprite_size = get_rect().size;
}

void Screensaver::_process(double delta)
{
    auto min_x = -(screen_size.x / 2) + (sprite_size.x / 2);
    auto min_y = -(screen_size.y / 2) + (sprite_size.y / 2);

    auto max_x = (screen_size.x / 2) - (sprite_size.x / 2);
    auto max_y = (screen_size.y / 2) - (sprite_size.y / 2);

    auto position = get_position();

    position.x += speed * x_direction * delta;
    position.y += speed * y_direction * delta;

    if (position.x > max_x || position.x < min_x)
    {
        x_direction = -x_direction;
    }

    if (position.y > max_y || position.y < min_y)
    {
        y_direction = -y_direction;
    }

    position.x = std::clamp(position.x, min_x, max_x);
    position.y = std::clamp(position.y, min_y, max_y);

    set_position(position);
}
