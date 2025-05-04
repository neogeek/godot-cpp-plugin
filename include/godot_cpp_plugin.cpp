#include "godot_cpp_plugin.hpp"

#include "convert.hpp"
#include "mathf.hpp"

void godot_cpp_plugin::_bind_methods()
{
    ClassDB::bind_static_method("godot_cpp_plugin",
                                D_METHOD("lerp", "a", "b", "t"),
                                &godot_cpp_plugin::lerp);

    ClassDB::bind_static_method("godot_cpp_plugin",
                                D_METHOD("inverse_lerp", "a", "b", "v"),
                                &godot_cpp_plugin::inverse_lerp);

    ClassDB::bind_static_method("godot_cpp_plugin", D_METHOD("sum", "values"),
                                &godot_cpp_plugin::sum);

    ClassDB::bind_static_method("godot_cpp_plugin",
                                D_METHOD("get_key_values", "values", "key"),
                                &godot_cpp_plugin::get_key_values);
}

float godot_cpp_plugin::lerp(float a, float b, float t)
{
    return Mathf::lerp(a, b, t);
}

float godot_cpp_plugin::inverse_lerp(float a, float b, float v)
{
    return Mathf::inverse_lerp(a, b, v);
}

int godot_cpp_plugin::sum(const Array &values) { return Mathf::sum(values); }

Array godot_cpp_plugin::get_key_values(const Array &values, const String &key)
{
    return Convert::get_key_values(values, key);
}
