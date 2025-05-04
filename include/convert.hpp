#pragma once

#include <string>
#include <vector>

#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/variant/array.hpp>

using namespace godot;

namespace Convert
{

auto get_key_values(Array values, const String &key) -> Array
{
    std::vector<std::string> urls;

    for (auto i = 0; i < values.size(); i += 1)
    {
        if (values[i].get_type() == Variant::DICTIONARY)
        {
            Dictionary variant = values[i];

            Array keys = variant.keys();

            if (keys.has(key))
            {
                String url = variant[key];

                urls.push_back(url.utf8().get_data());
            }
        }
    }

    Array godot_urls;

    for (auto const &url : urls)
    {
        godot_urls.append(url.c_str());
    }

    return godot_urls;
}

} // namespace Convert
